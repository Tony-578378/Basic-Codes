# INSERTIONSORT
insertionSort_R <- function(x){
  n <- length(x)
  for (i in 2:n) {
    token <- x[i]
    j <- i-1
    while (j > 0 && x[j] > token) {
      x[j+1] <- x[j]
      j <- j-1
    }
    x[j+1] <- token
  }
  return(x)
}
my_vector = c(1,5,6,2,3,4)
sorted_vector = insertionSort_R(my_vector)
print(sorted_vector)
# MERGESORT
merge_R <- function(left, right){
  result <- c()
  while (length(left) > 0 && length(right) > 0) {
    if (left[1] < right[1]) {
      result <- c(result, left[1])
      left <- left[-1]
    }
    else {
      result <- c(result, right[1])
      right <- right[-1]
    }
  }
  if (length(left) > 0) {
    result <- c(result, left)
  }
  if (length(right) > 0) {
    result <- c(result, right)
  }
  return(result)
}
mergeSort_R <- function(x){
  n <- length(x)
  if (n <= 1) {
    return(x)
  }
  
  q <- floor(n/2) #Round down to the largest integer.
  
  left <- mergeSort_R(x[1:q])
  right <- mergeSort_R((x[(q+1):n]))#Divide until individual elements are reached.
  
  return(merge_R(left, right))
}
# Create a sample vector
unsorted_vec <- c(38, 27, 43, 3, 9, 82, 10)#Divide to [38,27,43] and [3,9,82,10] until individual ones. Merge to form [27,38],[43],[3,9],[10,82] until the whole.

# Run MergeSort
sorted_vec <- mergeSort_R(unsorted_vec)

print(paste("Unsorted:", paste(unsorted_vec, collapse = ", ")))
print(paste("Sorted:  ", paste(sorted_vec, collapse = ", ")))
