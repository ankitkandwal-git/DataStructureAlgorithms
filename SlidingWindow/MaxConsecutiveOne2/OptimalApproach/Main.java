package SlidingWindow.MaxConsecutiveOne2.OptimalApproach;
import java.util.*;

public class Main{
    static int maxConsecutiveOnes(int[]nums){
        int left =0,right=0;
        int zeroCount = 0;
        int maxLength = 0;
        while(right<nums.length){
            if(nums[right]==0){
                zeroCount++;
            }
            while(zeroCount>1){
                if(nums[left]==0){
                    zeroCount--;
                }
                left++;
            }
            maxLength = Math.max(maxLength, right-left+1);
            right++;
        }
        return maxLength;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[]nums = new int[n];
            for(int i=0;i<n;i++){
                nums[i] = sc.nextInt();
            }
            int result = maxConsecutiveOnes(nums);
            System.out.println(result);
        }
    }
}