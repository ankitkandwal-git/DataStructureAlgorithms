package DynamicProgramming.HouseRobber.Memoization;
import java.util.Scanner;
public class Main {
    static int houseRob(int n , int[]arr,int[] dp){
        if(n==0) return arr[0];
        if(n==1) return Math.max(arr[0],arr[1]);
        if(dp[n]!= -1) return dp[n];
        int houseRob = arr[n] + houseRob(n-2,arr,dp);
        int notHouseRob = 0 + houseRob(n-1,arr,dp);
        return dp[n] = Math.max(houseRob,notHouseRob);
        
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of houses:");
            int n = sc.nextInt();
            int[] arr = new int[n];
            System.out.println("Enter the amount of money in each house:");
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int[] dp = new int[n];
            for(int i=0;i<n;i++){   
                dp[i] = -1;
            }
            int result = houseRob(n-1,arr,dp);
            System.out.println("Maximum amount that can be robbed: " + result);
        }
    }
}
