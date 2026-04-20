package Arrays.MajorElement.Solution4;
import java.util.Scanner;


class MajorElement{
    static int majElement(int[]arr){
        int leader = arr[0];
        int major = 1;
        int n = arr.length;
        for(int i=1;i<n;i++){
            if(arr[i]==leader){
                major++;
            }
            else{
                major--;
            }
        }
       return leader;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the size of the array:");
            int n = sc.nextInt();
            System.out.print("Enter the elements of the array:");
            int[] arr = new int[n];
            for(int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            int result = majElement(arr);
            System.out.println("The major element is: " + result);
        }
    }
}