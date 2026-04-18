package Arrays.MajorlyElement2;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
class MajorlyElement2{
    public
    List<Integer> majElement(int[]nums){
        int n = nums.length;
        int l1=Integer.MIN_VALUE,l2=Integer.MIN_VALUE;
        int m1=0,m2=0;
        int c1=0,c2=0;
        List<Integer>ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(nums[i] != l2 && m1==0){
                l1 = nums[i];
                m1 = 1;
            }
            else if(nums[i] != l1 && m2==0){
                l2 = nums[i];
                m2 = 1;
            }
            else if(nums[i] == l1){
                m1++;
            }
            else if(nums[i] == l2){
                m2++;
            }
            else{
                m1--;
                m2--;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] == l1){
                c1++;
            }
            else if(nums[i] == l2){
                c2++;
            }
        }
        if(c1 > n/3){
            ans.add(l1);
        }
        if(c2 > n/3){
            ans.add(l2);
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[]nums = new int[n];
        for(int i=0;i<n;i++){
            nums[i] = sc.nextInt();
        }
        MajorlyElement2 me = new MajorlyElement2();
        List<Integer>ans = me.majElement(nums);
        for(int i:ans){
            System.out.print(i+" ");
        }
    }
}