n = input("N: ")

D = diag(ones(1, n-1), 1) + diag(ones(1, n-1), -1) + diag(-2 * ones(1, n), 0) + diag(ones(1), n-1) + diag(ones(1), -n+1)
