package Sorting.SelectionSort;
import java.util.Scanner;

class Main{
    static void SelectionSort(int arr[] , int n){
        for(int i=0;i<n-1;i++){
            int minIndex = i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[minIndex]){
                    minIndex = j;
                }
            }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
        }
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the number of elements: ");
            int n = sc.nextInt();
            int arr[] = new int[n];
            System.out.println("Enter the elements:");
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            SelectionSort(arr , n);
            System.out.println("Sorted array:");
            for(int i=0;i<n;i++){
                System.out.print(arr[i] + " ");
            }
        }
    }
}