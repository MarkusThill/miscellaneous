library(lhs)
library(ggplot2)
library(MASS)
library(dplyr)
library(pbapply)

runLHS <- function(whichN, repeats){
  lhsTimes <- data.frame()
  for(i in whichN){
    for(j in 1:repeats) {
      tStart <- proc.time()
      invisible(optimumLHS(n = i, k = 5, verbose = FALSE)) # nochmal für 10
      tt <- (proc.time()-tStart)
      lhsTimes<-rbind(lhsTimes,data.frame(user=tt[1],system=tt[2],elapsed=tt[3], n=i))
    }
  }
  return (lhsTimes)
}



res <- pblapply(X=rev(1:30)*10, FUN=runLHS, 10, cl=1)
res <- do.call(rbind, res)
#saveRDS(object=res, file="lhs.rds") # In case you want to save the results
# res <- readRDS(file="lhs.rds")
# stop("Stop here for the moment")

plotData <- res[which(res$elapsed>.01),]
p <- ggplot(plotData,aes(x=n,y=user)) +
  geom_point() + 
  ylab("computation time / s") + 
  theme(axis.text=element_text(size=12),
        axis.title=element_text(size=14,face="bold"))
plot(p)

# Apply log10 to the data
log_n = log10(plotData$n)
log_y = log10(plotData$user)
log_data <- data.frame(log_n, log_y)

#
# Since we repeated each run several times: Measure the variance for each point n
#
grouped <- group_by(cbind(data.frame(log_n=log_n), data.frame(log_y=log_y)), log_n)
stats <- summarise(grouped, mean=mean(log_y), var=var(log_y))

# Now assign the corresponding variance to each data-point again
mergedData <- merge(log_data, stats)

# Prepare the vectors and matrices for the weighted linear least squares estimator
W =  diag(1.0 /mergedData$var)
X = cbind(1,mergedData$log_n)
y = mergedData$log_y

# Estimate the Intercept and Slope using weighted linear least squares
theta = ginv(t(X) %*% W %*% X) %*% t(X) %*% W %*% y
cat("Slope m=", theta[2], ". Intercept b=", theta[1], sep="")

# Plot the estimated line
p <- ggplot(plotData,aes(x=n,y=user)) +
  geom_point() + 
  scale_y_log10() + 
  scale_x_log10() + 
  geom_abline(slope=theta[2], intercept = theta[1]) +
  theme_bw() + 
  ylab("computation time / s") + 
  theme(axis.text=element_text(size=12),
        axis.title=element_text(size=14,face="bold"))
plot(p)