package Sorting.BubbleSort;

import java.util.Scanner;

class Main{
    static int bubbleSort(int arr[] , int n){
        int swapCount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    swapCount++;
                }
            }
        }
        return swapCount;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int swaps = bubbleSort(arr, n);
            System.out.println("Sorted Array:");
            for(int i=0;i<n;i++){
                System.out.print(arr[i] + " ");
            }
            System.out.println("\nNumber of swaps: " + swaps);
        }
    }
}