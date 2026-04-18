package String.LongestHappyPrefix;
import java.util.Scanner;
public class Main {
    static String longestPrefix(String s){
        int n = s.length();
        int[] lps = new int[n];
        int i=0,j=1;
        while(j<n){
            if(s.charAt(i)==s.charAt(i)){
                lps[j]=i+1;
                i++;
                j++;
            }
            else {
                if(i==0){
                    lps[j]=0;
                    j++;
                }
                else {
                    i=lps[i-1];
                }
            }
        }
        return s.substring(0,lps[n-1]);

    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            String s = sc.next();
            System.out.println(longestPrefix(s));
        }
    }
}
