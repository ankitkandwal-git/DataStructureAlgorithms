package DynamicProgramming.SamuraiAndFriend.Memoization;
import java.util.Scanner;
public class Main {
    static int samuraiAndFriend(int i, int j1 , int j2, int[][]grid , int[][][]dp){
        int m = grid.length;
        int n = grid[0].length;
        if(j1<0 || j2<0 || j1>=n || j2>=n) return Integer.MIN_VALUE;
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi;
        if(j1==j2) maxi = grid[i][j1];
        else maxi = grid[i][j1] + grid[i][j2];
        int x[] = new int[9];
        x[0] = samuraiAndFriend(i+1, j1, j2, grid, dp);
        x[1] = samuraiAndFriend(i+1, j1, j2-1, grid, dp);
        x[2] = samuraiAndFriend(i+1, j1, j2+1, grid, dp);
        x[3] = samuraiAndFriend(i+1, j1-1, j2, grid, dp);
        x[4] = samuraiAndFriend(i+1, j1-1, j2-1, grid, dp);
        x[5] = samuraiAndFriend(i+1, j1-1, j2+1, grid, dp);
        x[6] = samuraiAndFriend(i+1, j1+1, j2, grid, dp);
        x[7] = samuraiAndFriend(i+1, j1+1, j2-1, grid, dp);
        x[8] = samuraiAndFriend(i+1, j1+1, j2+1, grid, dp);
        int result = Integer.MIN_VALUE;
        for(int val:x){
            result = Math.max(result, val);
        }
        return dp[i][j1][j2] = maxi + result;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int[][]grid = new int[m][n];
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    grid[i][j] = sc.nextInt();
                }
            }
            int[][][]dp = new int[m][n][n];
            for(int i=0; i<m; i++){
                for(int j1=0; j1<n; j1++){
                    for(int j2=0; j2<n; j2++){
                        dp[i][j1][j2] = -1;
                    }
                }
            }
            System.out.println(samuraiAndFriend(0, 0, n-1, grid, dp));
        }
    }
}
