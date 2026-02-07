package Arrays.SecondLargestElement;
import java.util.Scanner;
public class Main {
    static int secondLargestNumber(int n , int[] arr){
        int largest = Integer.MIN_VALUE;
        int secondLargest = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i]>secondLargest && arr[i]!= largest){
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int result = secondLargestNumber(n,arr);
            System.out.println(result);
        }
    }
}
