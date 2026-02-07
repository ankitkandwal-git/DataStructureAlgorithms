package DynamicProgramming.FibonnaciSeries.Memoization;

import java.util.Scanner; 

public class Main{
    static int fib(int n, int[] dp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = fib(n-1, dp) + fib(n-2, dp);
        return dp[n];
    } 

    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the value of n: ");
            int n = sc.nextInt();
            int[] dp = new int[n+1];
            for(int i=0;i<=n;i++){
                dp[i] = -1;
            }
            System.out.println(fib(n, dp));
        }
    }
}