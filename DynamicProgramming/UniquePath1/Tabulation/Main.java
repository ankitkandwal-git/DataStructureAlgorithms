package DynamicProgramming.UniquePath1.Tabulation;

import java.util.Scanner;

public class Main {
    static int uniquePath(int m , int n){
        int[][] dp = new int[m][n];  
        for(int i=0;i<=m-1;i++){
            dp[i][0] = 1;
        } 
        for(int j=0;j<=n-1;j++){
            dp[0][j] = 1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            System.out.println(uniquePath(m,n));
        }
    }
}
