package Arrays.IsArraySorted;
import java.util.Scanner;

class Main{
    static boolean isArraySorted(int arr[], int n){
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            if(isArraySorted(arr, n)){
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}