package DynamicProgramming.Triangle.Memoization;
import java.util.Scanner;
public class Main {
    static int trianglePathSum(int[][] triangle,int[][]dp, int i, int j , int n){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int down = triangle[i][j] + trianglePathSum(triangle,dp,i+1,j,n);
        int diagonal = triangle[i][j] + trianglePathSum(triangle,dp,i+1,j+1,n);
        return dp[i][j] = Math.min(down,diagonal);
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[][] triangle = new int[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<=i;j++){
                    triangle[i][j] = sc.nextInt();
                }
            }
            int[][] dp = new int[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<=i;j++){
                    dp[i][j] = -1;
                }
            }
            System.out.println(trianglePathSum(triangle,dp,0,0,n));
        }
    }
}
