package Arrays.CountSubarrayWithTargetSum;
import java.util.HashMap;
import java.util.Scanner;

class Main{
    static int countSubarrWithTargetSum(int[]arr,int target){
        HashMap<Integer,Integer>m = new HashMap<>();
        int count = 0;
        int sum = 0;
        for(int i=0;i<arr.length;i++){
            sum+=arr[i];
            if(sum==target){
                count++;
            }
            count += m.getOrDefault(sum-target,0);
            m.put(sum,m.getOrDefault(sum,0)+1); 
        }
        return count;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[]arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int target = sc.nextInt();
            System.out.println(countSubarrWithTargetSum(arr,target));
        }
    }
}