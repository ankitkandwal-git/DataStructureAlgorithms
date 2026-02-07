package DynamicProgramming.UniquePath2.Memoization;
import java.util.Scanner;

class Main{
    static int uniquePath(int m , int n, int[][] grid, int[][]dp){
        if(m<0 || n<0) return 0;
        if(m==0 || n==0) return 1;
        if(grid[m][n] ==0) return 1;
        if(dp[m][n] != -1) return dp[m][n];
        int right = uniquePath(m, n-1, grid, dp);
        int down = uniquePath(m-1, n, grid, dp);
        return dp[m][n] = right + down;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of rows: ");
            int m = sc.nextInt();
            System.out.println("Enter the number of columns: ");
            int n = sc.nextInt();
            System.out.println("Enter the grid elements (0 for free cell, 1 for obstacle): ");
            int[][]grid = new int[m][n];
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
            System.out.println("Number of unique paths: " + uniquePath(m-1, n-1, grid, dp));
        }
    }
}