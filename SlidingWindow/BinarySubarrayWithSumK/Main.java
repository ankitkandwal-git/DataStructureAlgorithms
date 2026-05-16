package SlidingWindow.BinarySubarrayWithSumK;
import java.util.*;

public class Main{
    static int f(int[]arr,int k){
        int i=0,j=0,sum=0,res=0;
        int n = arr.length;
        while(j<n){
            sum+=arr[j];
            while(sum>k){
                sum-=arr[i];
                i++;
            }
            res +=j-i+1;
            j++;
        }
        return res;
    }
    static int binarySubarrayWithSumK(int[]arr,int k){
        return f(arr,k)-f(arr,k-1);
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[]arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            System.out.println(binarySubarrayWithSumK(arr,k));
        }
    }
}