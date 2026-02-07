package DynamicProgramming.ClimbStairs;

import java.util.Scanner;

public class Main{
    static int climbStairs(int n, int[] dp){
        if(n==0 || n==1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = climbStairs(n-1, dp) + climbStairs(n-2, dp);
        return dp[n];
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter number of stairs: ");
            int n = sc.nextInt();
            int[] dp = new int[n+1];
            for(int i=0;i<=n;i++){
                dp[i] = -1;
            }
            System.out.println(climbStairs(n, dp));
        }
    }
}
