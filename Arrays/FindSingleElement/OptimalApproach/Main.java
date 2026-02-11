package Arrays.FindSingleElement.OptimalApproach;
import java.util.Scanner;

class Main{
    static int singleElement(int n,int arr[]){
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans ^ arr[i];
        }
        return ans;
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)){
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(singleElement(n,arr));
    }
  }
}