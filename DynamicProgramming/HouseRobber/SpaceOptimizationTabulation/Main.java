package DynamicProgramming.HouseRobber.SpaceOptimizationTabulation;
import java.util.Scanner;
public class Main {
    static int rob(int n , int[] arr){
        int prev2 = 0;
        int prev1 = arr[0];
        int current = 0;
        for(int i=1;i<n;i++){
            int rob = arr[i] + prev2;
            int notRob = 0 + prev1;
            current = Math.max(rob, notRob);
            prev2 = prev1;
            prev1 = current;
        
        }
        return prev1;
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the size of array");
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            System.out.println(rob(n, arr));
        }
    }
}
