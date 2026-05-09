package SlidingWindow.MaxConsecutiveOne2.BruteForce;
import java.util.*;
public class Main {
    static int longestOnes(int[]nums){
        int n = nums.length;
        int maxLength = 0;
        for(int i=0;i<n;i++){
            int zeroCount = 0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    zeroCount++;
                }
                if(zeroCount>1){
                    break;
                }
                maxLength = Math.max(maxLength,j-i+1);
            }
        }
        return maxLength;
    }
    public static void main(String[] args) {
        int[] nums = {1,1,0,0,1};
        System.out.println(longestOnes(nums));
    }
}
