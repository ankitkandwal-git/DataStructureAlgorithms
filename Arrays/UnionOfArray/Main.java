package Arrays.UnionOfArray;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    static List<Integer> unionOfArray(int arr1[] , int arr2[] , int m , int n){
        int i=0,j=0;
        int count = 0;
        List<Integer> ans = new ArrayList<>();
        while(i<m && j<n){
            if(arr1[i]<=arr2[j]){
                if(ans.isEmpty() || arr1[i]!= ans.get(ans.size()-1)){
                    ans.add(arr1[i]);
                }
                i++;
                count++;
            } else{
                if(ans.isEmpty() || arr2[j] != ans.get(ans.size()-1)){
                    ans.add(arr2[j]);
                }
                j++;
                count++;
            }
        }
        while(i<m){
            if(ans.isEmpty() || arr1[i]!= ans.get(ans.size()-1)){
                ans.add(arr1[i]);
            }
            i++;
            count++;
        }
        while(j<n){
            if(ans.isEmpty() || arr2[j] != ans.get(ans.size()-1)){
                ans.add(arr2[j]);
            }
            j++;
            count++;
        }
        return ans;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            int m = sc.nextInt();
            int n = sc.nextInt();
            int arr1[] = new int[m];
            int arr2[] = new int[n];
            for(int i=0;i<m;i++){
                arr1[i] = sc.nextInt();
            }
            for(int i=0;i<n;i++){
                arr2[i] = sc.nextInt();
            }
            List<Integer> ans = unionOfArray(arr1,arr2,m,n);
            for(int i=0;i<ans.size();i++){
                System.out.print(ans.get(i)+" ");
            }
        }
    }
}
