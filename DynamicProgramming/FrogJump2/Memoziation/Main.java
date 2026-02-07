package DynamicProgramming.FrogJump2.Memoziation;
import java.util.Arrays;
import java.util.Scanner;

class Main{
    static int frogJump(int n , int[] height, int[]dp, int k){

        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        int min_energy = Integer.MAX_VALUE;
        for(int i=1;i<=k;i++){
            if(n-i >= 0){
                int jump = Math.abs(height[n]-height[n-i]) + frogJump(n-i,height,dp,k);
                min_energy = Math.min(min_energy,jump);
            }
        }
        return dp[n] = min_energy;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter number of stairs: ");
            int n = sc.nextInt();
            System.out.print("Enter maximum jump length: ");
            int k = sc.nextInt();
            int[] height = new int[n];
            for(int i=0;i<n;i++){
                System.out.print("Enter height of stair ");
                height[i] = sc.nextInt();
            }
            int[] dp = new int[n];
            Arrays.fill(dp, -1);
            System.out.println("Minimum energy required to reach the top: " + frogJump(n-1, height, dp, k));
        }
    }
}