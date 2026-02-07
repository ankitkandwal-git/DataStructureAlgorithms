package DynamicProgramming.SamuraiAndFriend.Tabulation;
import java.util.Scanner;   
public class Main {
    static int samuraiAndFriend(int i,int j1, int j2, int m , int n,int[][]grid){
        int[][][] dp = new int[m][n][n];
        for(int row=m-1;row>=0;row--){
            for(int col1=0;col1<n;col1++){
                for(int col2=0;col2<n;col2++){
                    if(row==m-1){
                        if(col1==col2){
                            dp[row][col1][col2] = grid[row][col1];
                        }else{
                            dp[row][col1][col2] = grid[row][col1] + grid[row][col2];
                        }
                    }
                    else{
                        int grid_value = 0;
                        if(col1==col2){
                            grid_value = grid[row][col1];
                        }
                        else{
                            grid_value = grid[row][col1] + grid[row][col2];
                        }
                        int[] x = new int[9];
                        for(int k=0;k<9;k++){
                            x[k] = Integer.MIN_VALUE;
                        }
                        if(col1-1>=0 && col2-1>=0){
                            x[0] = dp[row+1][col1-1][col2-1];
                        }
                        if(col1-1>=0){
                            x[1] = dp[row+1][col1-1][col2];
                        }
                        if(col1-1>=0 && col2+1<n){
                            x[2] = dp[row+1][col1-1][col2+1];
                        }
                        if(col2-1>=0){
                            x[3] = dp[row+1][col1][col2-1];
                        }
                        x[4] = dp[row+1][col1][col2];
                        if(col2+1<n){
                            x[5] = dp[row+1][col1][col2+1];
                        }
                        if(col1+1<n && col2-1>=0){
                            x[6] = dp[row+1][col1+1][col2-1];
                        }
                        if(col1+1<n){
                            x[7] = dp[row+1][col1+1][col2];
                        }
                        if(col1+1<n && col2+1<n){
                            x[8] = dp[row+1][col1+1][col2+1];
                        }
                        int max_next = Integer.MIN_VALUE;
                        for(int k=0;k<9;k++){
                            max_next = Math.max(max_next, x[k]);
                        }
                        dp[row][col1][col2] = grid_value + max_next;
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int grid[][] = new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            System.out.println(samuraiAndFriend(0,0,n-1,m,n,grid));
        }
    }
}
