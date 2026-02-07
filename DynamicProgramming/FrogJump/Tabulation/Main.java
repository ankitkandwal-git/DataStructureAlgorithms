package DynamicProgramming.FrogJump.Tabulation;
import java.util.Scanner;
public class Main {
    static int frogJump(int n , int[]height){
        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = Math.abs(height[1] - height[0]);
        for(int i=2;i<n;i++){
            int jump1 = Math.abs(height[i]-height[i-1]) + dp[i-1];
            int jump2 = Math.abs(height[i]-height[i-2]) + dp[i-2];
            dp[i] = Math.min(jump1, jump2);
        }
        return dp[n-1];
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter number of stairs: ");
            int n = sc.nextInt();
            System.out.print("Enter the height of stairs: ");
            int[] height = new int[n];
            for(int i = 0; i < n; i++) {
                height[i] = sc.nextInt();
            }
            int result = frogJump(n, height);
            System.out.println("Minimum energy required: " + result);
        }
    }
}
