package String.BeautyOfAllSubString;
import java.util.Scanner;

class BeautyOfAllSubString{
    static int help(int[]arr){
        int mini = Integer.MAX_VALUE,
            maxi = Integer.MIN_VALUE;
        for(int i=0;i<26;i++){
            if(arr[i] != 0){
                mini = Math.min(mini,arr[i]);
                maxi = Math.max(maxi,arr[i]);
            }
        }
        return maxi-mini;
    }
    public static int beauty(String s){
        int ans=0;
        for(int i=0;i<s.length();i++){
            int[]arr = new int[26];
            for(int j=i;j<s.length();j++){
                arr[s.charAt(j)-'a']++;
                ans+=help(arr);
            }
        }
        return ans;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of test cases:");
            String s = sc.next();
            System.out.println(beauty(s));
        }
    }
};

