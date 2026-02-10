package Arrays.ConsecutiueNumber.OptimalApproach;

import java.util.Scanner;

class Main{
    static int consecutiveNumber(int n , int arr[]){
        int max =0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                count++;
            }
            else if(count>max){
                max = count;
            }
            else{
                count = 0;
            }
        }
        return max;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            System.out.println(consecutiveNumber(n,arr));
        }
    }
}