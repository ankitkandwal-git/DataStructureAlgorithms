package Arrays.RemoveDuplicate;
import java.util.Scanner;
public class Main {
    static int removeDuplicate(int arr[] , int n){
        int i = 0;
        for(int j=1;j<n;j++){
            if(arr[i] != arr[j]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
    }
    public static void main(String[] args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int result = removeDuplicate(arr, n);
            for(int i=0;i<result;i++){
                System.out.print(arr[i] + " ");
            }
        }
    }
}
