###Skeleton R script for the UMMCI Take Home Assessment 24-25###

#Start by setting up your working directory
setwd("Please don't forget to mask this when submitting your assignment
      so you wouldn't be identifiable. Thank you!")

#Load the packages needed for the different tasks
library(haven)

#Load the dataset
Sesame <- read_dta("Sesame.dta")

#Attach the data for easier analysis
attach(Sesame)

#Call a couple of packages to make it easier to run descriptive statistics
library(psych)
library(sjmisc)

#Take a look at the whole dataset
describe(Sesame)

#Consider some descriptive statistics
frq(sex)
frq(age)
frq(site)
frq(viewcat)
frq(encour)
frq(regular)

#Look at the ability measures and consider the correlation between
#pre- and post-intervention measures
frq(prelet)
hist(prelet)

frq(postlet)
hist(postlet)

let <- cor.test(prelet, postlet)
let
#You might want to consider doing the above for all/most pre-post measures


###########################
#________Task 1____________
###########################
#Packages needed for this task
library(PerformanceAnalytics)
library(factoextra)
library(GPArotation)

#Below are some suggested code
#Feel free to deviate from this, these are merely suggestions/some help
#to get you going

#Use this if you want to analyse pre-treatment ability measures:
#pre <- Sesame[, c(9:14)]
#chart.Correlation(pre, histogram=TRUE, pch=19)
#pca <- prcomp(Sesame[, c(9:14)], center = TRUE, scale. = TRUE)
#efa <- fa(pre, nfactors = testmultiplealternatives, scores = "regression")

#Use this if you want to analyse post-treatment ability measures:
#post <- Sesame[, c(15:20)]
#chart.Correlation(post, histogram=TRUE, pch=19)
#pca <- prcomp(Sesame[, c(15:20)], center = TRUE, scale. = TRUE)
#efa <- fa(post, nfactors = testmultiplealternatives, scores = "regression")



###########################
#________Task 2____________
###########################
#Packages needed for this task
library(lavaan)
library(lavaanPlot)
library(semPlot)

#Below are some suggested code
#Feel free to deviate from this, these are merely suggestions/some help
#to get you going

#Structural equation model of interest:
#sem <-  'pretest =~ prebody + prelet + preform + prenumb + prerelat + preclasf
#         posttest =~ postbody + postlet + postform + postnumb + postrelat + postclasf
#         posttest ~ pretest + age + sex + viewcat + setting
#         pretest ~ age + sex + viewcat + setting
#         age~~sex
#         age~~viewcat
#         age~~setting
#         sex~~viewcat
#         sex~~setting
#         viewcat~~setting'


###########################
#________Task 3____________
#Multilevel Modelling
## 1) Consider ‘site’ as the cluster-level variable. First, estimate the intraclass 
## correlation coefficient for three variables of your choice (which could be either 
## from pre- or post-treatment). What do you find? How would you interpret the results?

## 2) Second, fit a fixed and random effects model to these three variables with 
## age, sex, viewing frequency (‘viewcat’) and the setting the programme was 
## watched (‘setting’) as explanatory variables. Compare the two models to each 
## other and interpret the findings. Which modelling approach would you choose 
## based on the data structure and model comparison? Why?

## 3) Using your preferred modelling approach, interpret the findings. What do you find?
###########################
#Packages needed for this task
library(clubSandwich)
library(texreg)

#Below are some suggested code
#Feel free to deviate from this, these are merely suggestions/some help
#to get you going

#1)
#I choose postlet, postnumb, and postrelat from post-treatment.
#We first fit an empty (no covariates) and random effects model using postlet as the response variable.
install.packages("nlme")
install.packages("performance")
library(nlme)
library(lme4)
library(performance)

postlet.rie <- lme(postlet ~ 1, random = ~ 1|site, na.action="na.omit", 
                   method="ML", data = Sesame)
VarCorr(postlet.rie)
postlet.rie_icc <- 36.56131/(36.56131 + 137.02105)
print(postlet.rie_icc)
icc(postlet.rie)#The ICC is 0.211.
#Now, use the full model with all exploratory variables.
postlet.fie <- lme(postlet ~ age + sex + viewcat + setting, random = ~ 1|site, 
                   na.action="na.omit", method="ML", data = Sesame)
VarCorr(postlet.fie)
postlet.fie_icc <- 23.71163/(23.71163 + 97.50453)
print(postlet.fie_icc)
icc(postlet.fie)#The ICC is 0.196.

#Next, we use postnumb as the response variable and fit an empty model.
postnumb.rie <- lme(postnumb ~ 1, random = ~ 1|site, na.action="na.omit", 
                    method="ML", data = Sesame)
VarCorr(postnumb.rie)
postnumb.rie_icc <- 21.71652/(21.71652 + 140.12655)
print(postnumb.rie_icc)
icc(postnumb.rie)#The ICC is 0.134.
#Then, use the full model.
postnumb.fie <- lme(postnumb ~ age + sex + viewcat + setting, random = ~ 1|site, 
                    na.action="na.omit", method="ML", data = Sesame)
VarCorr(postnumb.fie)
postnumb.fie_icc <- 13.68464/(13.68464 + 100.80408)
print(postnumb.fie_icc)
icc(postnumb.fie)#The ICC is 0.120.

#Finally, postrelat is used as the response variable and an empty model is fitted.
postrelat.rie <- lme(postrelat ~ 1, random = ~ 1|site, na.action="na.omit", 
                     method="ML", data = Sesame)
VarCorr(postrelat.rie)
postrelat.rie_icc <- 0.3109034/(0.3109034 + 8.6134689)
print(postrelat.rie_icc)
icc(postrelat.rie)#The ICC is 0.035.

#Then, fit a full model instead.
postrelat.fie <- lme(postrelat ~ age + sex + viewcat + setting, random = ~ 1|site, 
                     na.action="na.omit", method="ML", data = Sesame)
VarCorr(postrelat.fie)
postrelat.fie_icc <- 0.2220558/(0.2220558 + 7.1311649)
print(postrelat.fie_icc)
icc(postrelat.fie)#The ICC is 0.030.

#In conclusion, for postlet, the empty model has an intraclass correlation coefficient of 0.211 and the (adjusted) 
#full model has an ICC of 0.196, so 19.6-21.1% variation in the scores of posttest on letters is attributable to site-level
#differences (differences between clusters) and 78.9-80.4% is attributable to individual differences (differences within
#clusters). More than 5% of the variation is attributable to level-2, so multilevel modelling might be needed for the scores 
#of posttest on letters.
#For postnumb, the empty model has an ICC of 0.134 and the (adjusted) full model has an ICC of 0.120, so 12.0-13.4% variation 
#in the scores of posttest on numbers is attributable to differences between clusters and 86.6-88.0% is attributable to differences 
#within clusters. More than 5% of the variation is attributable to level-2, so multilevel modelling might also be needed for the scores 
#of posttest on numbers.
#For postrelat, the ICC for the empty model is 0.035 and the ICC for the full model is 0.030, so 3.0-3.5% variation in the scores
#of posttest on relational terms is attributable to differences between clusters and 96.5-97.0% is attributable to differences
#within clusters. Less than 5% of the variation is attributable to level-2, so multilevel modelling might not be needed for the scores 
#of posttest on relational terms.
#One thing consistent for all 3 variables is that, after having added the level-1 variables, the intraclass correlation coefficient
#slightly decreases, so more variation is attributable to differences within clusters. This indicates that the individual-level covariates
#have been able to account for the site-level differences. Also, after level-1 variables are added, both variations between and within clusters
#for all three variables decrease.

#For clustered-robust standard errors
#coef_test(nameofyourmodel, vcov = "CR1", 
#          cluster = school, test = "naive-t")


###########################
#________Task 4____________
###########################
#Packages needed for this task
library(Matching)

#Below are some suggested code
#Feel free to deviate from this, these are merely suggestions/some help
#to get you going

#You'll need to detach your database for this task:
#detach(Sesame)

#For distance-based matching (e.g. Mahalanobis), create your vector of covariates:
#X <- cbind(Sesame$cov1, Sesame$cov2, Sesame$cov3 etc. etc.)
#Then, carry out matching as usual:
#namethis <- Match(Tr = Sesame$regular, X = X, estimand = "ATT", M = testfortherightnumber,
#ties = TRUE, distance.tolerance = 1e-15, replace = TRUE, Weight = 1)
#balancename <- MatchBalance(regular ~ cov1 + cov2 + cov3 + etc. etc., 
#nboots = 0, ks = FALSE, match.out = namethis, data = Sesame)
#nametheestimation <- Match(Y = Sesame$yourchosenoutcome, Tr = Sesame$regular, X = X, estimand = "ATT",
#                    M = testfortherightnumber, ties = TRUE, distance.tolerance = 1e-15, replace = TRUE, Weight = 1,
#                    Var.calc = 5, BiasAdjust = TRUE)



#For PS matching, create your propensity score:
#nameyourmodel <- glm(regular ~ cov1 + cov2 + cov3 + etc. etc., family = binomial, data = Sesame)
#summary(nameyourmodel)
#Sesame$pscore <- nameyourmodel$fitted
#Then, carry out matching as usual:
#namethis <- Match(Tr = Sesame$regular, X = Sesame$pscore, estimand = "ATT", M = testfortherightnumber,
#ties = TRUE, distance.tolerance = 1e-15, replace = TRUE)
#balancename <- MatchBalance(regular ~ cov1 + cov2 + cov3 + etc. etc., 
#nboots = 0, ks = FALSE, match.out = namethis, data = Sesame)
#nametheestimation <- Match(Y = Sesame$yourchosenoutcome, Tr = Sesame$regular, X = Sesame$pscore,
#estimand = "ATT", M = testfortherightnumber, ties = TRUE, distance.tolerance = 1e-15,
#replace = TRUE, Var.calc = 5)
