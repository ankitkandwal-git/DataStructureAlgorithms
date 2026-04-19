package Arrays.MaxSubarrayProduct;
import java.util.Scanner;
import java.lang.Math;

class MaxSubarrayProduct{
    static int maxProduct(int []arr){
        int n = arr.length;
        double max_product = 1;
        double suffix = 1;
        double prefix = 1;
        for(int i=0;i<n;i++){
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
            prefix = prefix*arr[i];
            suffix = suffix*arr[n-1-i];
            max_product = Math.max(max_product,Math.max(prefix,suffix));
        }
        return (int)max_product;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the size of the array:");
            int n = sc.nextInt();
            int []arr = new int[n];
            System.out.println("Enter the elements of the array:");
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int result = maxProduct(arr);
            System.out.println("The maximum product of a subarray is: "+result);
        }
    }
}