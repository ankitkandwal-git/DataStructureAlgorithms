package Searching.LinearSearching;
import java.util.Scanner;

class Main{
    static int linearSearch(int n , int key, int arr[]){
        for(int i=0;i<n;i++){
            if(arr[i]==key){
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int key = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            System.out.println(linearSearch(n , key, arr));
         }
    }
}