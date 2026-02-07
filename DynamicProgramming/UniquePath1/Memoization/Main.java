package DynamicProgramming.UniquePath1.Memoization;
import java.util.Scanner;
public class Main {
    static int uniquePath(int m ,int n, int[][]dp){
        if(m<0 || n<0){
            return 0;
        }
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int up = uniquePath(m-1,n,dp);
        int left = uniquePath(m,n-1,dp);
        return dp[m][n] = up + left;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int[][] dp = new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    dp[i][j] = -1;
                }
            }
            System.out.println(uniquePath(m-1,n-1,dp));
        }
    }
}
