package DynamicProgramming.FrogJump.Memoization;
import java.util.Scanner;

class Main{
    static int frogJump(int n , int[] height, int[]dp){
        if(n==0) return 0;
        if(n==1) return Math.abs(height[1]-height[0]);
        if(dp[n] != -1) return dp[n];
        int jumpOne = Math.abs(height[n]-height[n-1]) + frogJump(n-1,height,dp);
        int jumpTwo = Math.abs(height[n]-height[n-2]) + frogJump(n-2,height,dp);
        return dp[n] = Math.min(jumpOne,jumpTwo);
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the number of stairs: ");
            int n = sc.nextInt();
            System.out.print("Enter the heights of the stairs: ");
            int[] height = new int[n];
            for(int i=0; i<n; i++){
                height[i] = sc.nextInt();
            }
            int[] dp = new int[n];
            for(int i=0; i<n; i++){
                dp[i] = -1;
            }
            int result = frogJump(n-1, height, dp);
            System.out.println("The minimum energy required to reach the top is: " + result);
        }
    }
}