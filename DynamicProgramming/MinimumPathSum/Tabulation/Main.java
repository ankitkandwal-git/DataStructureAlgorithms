package DynamicProgramming.MinimumPathSum.Tabulation;
import java.util.Scanner;
public class Main {
    static int minPathSum(int[][] grid, int m , int n){
        int dp[][] = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) {
                    dp[i][j] = grid[i][j];
                }
                else {
                    int up = (i > 0) ? dp[i-1][j] : Integer.MAX_VALUE;
                    int left = (j > 0) ? dp[i][j-1] : Integer.MAX_VALUE;
                    dp[i][j] = grid[i][j] + Math.min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int grid[][] = new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            System.out.println(minPathSum(grid,m,n));
        }
    }
}
