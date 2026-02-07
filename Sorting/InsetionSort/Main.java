package Sorting.InsetionSort;
import java.util.Scanner;
public class Main {
    static void insertionSort(int arr[] , int n){
        int count = 0;
        for(int i=1;i<=n-1;i++){
            int j = i;
            while(j > 0 && arr[j-1] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                j--;
                count++;
            }
        }
        System.out.println("\nTotal iterations: " + count);
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            insertionSort(arr,n);
            for(int i=0;i<n;i++){
                System.out.print(arr[i] + " ");
            }
        }
    }
}
