package Heaps.MaxHeapSort;

import java.util.*;

class Main{
    static boolean isMaxHeap(int arr[]){
        int n = arr.length;
        // Start from the last non-leaf node and go up to the root.
        for(int i = (n / 2) - 1; i >= 0; i--){
            int left = 2*i + 1;
            int right = 2*i + 2;
            if(left<n && arr[left]>arr[i]){
                return false;
            }
            if(right<n && arr[right]>arr[i]){
                return false;
            }
        }
        return true;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            if(isMaxHeap(arr)){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }
    }
}