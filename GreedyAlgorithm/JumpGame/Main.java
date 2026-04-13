package GreedyAlgorithm.JumpGame;
import java.util.Scanner;
public class Main {
    static boolean jumpGame(int[] nums){
        int n = nums.length;
        int maxReach = 0;
        for(int i=0; i<n; i++){
            maxReach = Math.max(maxReach, i + nums[i]);
            if(maxReach >= n-1){
                return true;
            }
        } 
        return false;       
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[]nums = new int[n];
            for(int i=0; i<n; i++){
                nums[i] = sc.nextInt();
            }
            boolean result = jumpGame(nums);
            System.out.println(result);
        }
    }
}
