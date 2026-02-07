package DynamicProgramming.FibonnaciSeries.Tabulation;
import java.util.Scanner;
public class Main{
    static int fib(int n){
        int[] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the value of n: ");
            int n = sc.nextInt();
            System.out.println(fib(n));
        }
    }
}