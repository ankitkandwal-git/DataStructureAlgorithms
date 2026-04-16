package String.MinAdditionToMakeValidBrackets;
import java.util.Scanner;

class Solution{
    static int minAddToMakeValid(String s){
        int count=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='(') count++;
            else if(count==0) ans++;
            else count--;
        }
        ans+=count;
        return ans;
    }
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)) {
            String s = sc.nextLine();
            System.out.println(minAddToMakeValid(s));
        }
    }
}