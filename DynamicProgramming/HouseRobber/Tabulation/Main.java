package DynamicProgramming.HouseRobber.Tabulation;
import java.util.Scanner;
public class Main {
    static int rob(int n , int[]arr){
        int[] dp = new int[n];
        dp[0] = arr[0];
        dp[1] = Math.max(arr[0], arr[1]);
        for(int i=2;i<n;i++){
            int pick = arr[i] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = Math.max(pick, notPick);
        }
        return dp[n-1];
    } 
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }   
            System.out.println(rob(n, arr));
        }
    }
}
