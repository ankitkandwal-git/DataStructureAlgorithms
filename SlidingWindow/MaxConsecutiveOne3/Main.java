package SlidingWindow.MaxConsecutiveOne3;
import java.util.*;
public class Main {
    static int longestOnes(int[] nums, int k) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int zeroCount = 0;

        while (right < nums.length) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }

            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the size of the array:");
            int n = sc.nextInt();
            int[] nums = new int[n];
            System.out.println("Enter the elements of the array (0s and 1s):");
            for (int i = 0; i < n; i++) {
                nums[i] = sc.nextInt();
            }
            System.out.println("Enter the value of k:");
            int k = sc.nextInt();
            int result = longestOnes(nums, k);
            System.out.println("The longest subarray of 1's after flipping at most " + k + " zeros is: " + result);
        }
    }
}
