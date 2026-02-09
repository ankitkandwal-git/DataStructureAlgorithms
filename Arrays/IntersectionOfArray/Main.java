package Arrays.IntersectionOfArray;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Main{
    static List<Integer> intersectionOfArray(int m,int n,int a[],int b[]){
        List<Integer>ans = new ArrayList<>();
        int i=0,j=0;
        while(i<m && j<n){
            if(a[i]==b[j]){
                ans.add(a[i]);
                i++;
                j++;
            }else if(a[i]<b[j]){
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int a[] = new int[m];
            int b[] = new int[n];
            for(int i=0;i<m;i++){
                a[i] = sc.nextInt();
            }
            for(int i=0;i<n;i++){
                b[i] = sc.nextInt();
            }
            List<Integer>ans = intersectionOfArray(m,n,a,b);
            for(int i:ans){
                System.out.print(i+" ");
            }
        }
    }
}