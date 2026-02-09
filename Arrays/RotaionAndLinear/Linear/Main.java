package Arrays.RotaionAndLinear.Linear;
import java.util.Scanner;

class Main{
    static int LinearSearch(int n,int target,int arr[]){
        for(int i=0;i<n;i++){
            if(arr[i]==target){
                return i;
            }
        }
        return -1;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int n = sc.nextInt();
            int target = sc.nextInt();
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int ans = LinearSearch(n,target,arr);
            if(ans==-1){
                System.out.println("Element not found");
            }
            else{
                System.out.println("Element found at index: "+ans);
            }
        }
    }
}