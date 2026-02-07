package DynamicProgramming.MaximumPathSum.Memoziation;
import java.util.Scanner;

class Main{
    static int maxPathSum(int i, int j, int[][] matrix, int n, int m, int[][] dp){
        if(i<0 || j<0 || i>=n || j>=m) return Integer.MIN_VALUE;
        if(i==n-1 && j==m-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = matrix[i][j] + maxPathSum(i+1, j, matrix, n, m, dp);
        int right = matrix[i][j] + maxPathSum(i, j+1, matrix, n, m, dp);

        return dp[i][j] = Math.max(down, right);
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] matrix = new int[n][m];
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    matrix[i][j] = sc.nextInt();
                }
            }
            int[][] dp = new int[n][m];
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    dp[i][j] = -1;
                }
            }
            int result = maxPathSum(0, 0, matrix, n, m, dp);
            System.out.println(result);
        }
    }
}