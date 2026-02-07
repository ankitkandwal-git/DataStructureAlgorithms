def fib(n,dp):
    if(n==0 or n==1):
        return n
    if(dp[n]!= -1):
        return dp[n]
    
    dp[n] = fib(n-1,dp) + fib(n-2,dp)
    return dp[n]

n = int(input("Enter the value of n: "))
result = fib(n,dp=[-1]*(n+1))
print(result)