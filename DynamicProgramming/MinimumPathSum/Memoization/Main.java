package DynamicProgramming.MinimumPathSum.Memoization;
import java.util.Scanner;

class Main{
    static int minimumPathSum(int[][]grid , int m , int n,int[][]dp){
        if(m<0 || n<0){
            return Integer.MAX_VALUE;
        }
        if(m==0 && n==0) return grid[0][0];
        if(dp[m][n] != -1) return dp[m][n];
        int right = minimumPathSum(grid, m-1, n, dp);
        int down = minimumPathSum(grid, m, n-1, dp);
        return dp[m][n] = Math.min(right,down) + grid[m][n];
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int[][] grid = new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            int[][] dp = new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    dp[i][j] = -1;
                }
            }
            System.out.println(minimumPathSum(grid, m-1, n-1, dp));
        }
    }
}