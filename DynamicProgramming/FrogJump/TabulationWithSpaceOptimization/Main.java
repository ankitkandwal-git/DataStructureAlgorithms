package DynamicProgramming.FrogJump.TabulationWithSpaceOptimization;
import java.util.Scanner;
public class Main {
    static int frogJump(int n , int[] height){
        int prev = 0;
        int prev2 = Math.abs(height[1]-height[0]);
        int current = 0;
        for(int i=2;i<n;i++){
            int jumpone = Math.abs(height[i]-height[i-1]) + prev2;
            int jumpTwo = Math.abs(height[i]-height[i-2]) + prev;
            current = Math.min(jumpone,jumpTwo);
            prev = prev2; 
            prev2 = current;
        }
        return current; 
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter number of stairs: ");
            int n = sc.nextInt();
            System.out.println("Enter heights of stairs: ");
            int[] height = new int[n];
            for(int i=0;i<n;i++){
                height[i] = sc.nextInt();
            }
            int result = frogJump(n,height);
            System.out.println("Minimum energy required to reach the top: " + result);
        }
    }
}
