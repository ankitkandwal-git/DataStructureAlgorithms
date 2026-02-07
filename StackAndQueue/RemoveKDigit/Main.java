package StackAndQueue.RemoveKDigit;

import java.util.Scanner;
import java.util.Stack;

public class Main{
    static String removeKDigits(String num , int k){
        int n = num.length();
        Stack<Character> stack = new Stack<>();
        for(int i=0;i<n;i++){
            while(!stack.empty() && k>0 && stack.peek()>num.charAt(i)){
                stack.pop();
                k--;
            }
            stack.push(num.charAt(i));
        }
        while(!stack.empty() && k>0){
            stack.pop();
            k--;
        }
        StringBuilder ans = new StringBuilder();
        while(!stack.isEmpty()){
            ans.append(stack.pop());
        }
        ans.reverse();
        // Remove leading zeros
        int idx = 0;
        while (idx < ans.length() && ans.charAt(idx) == '0') idx++;
        String finalAns = ans.substring(idx);
        if(finalAns.length() == 0){
            return "0";
        }
        return finalAns;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number string:");
        String num = sc.next();
        System.out.println("Enter the value of k:");
        int k = sc.nextInt();
        String result = removeKDigits(num, k);
        System.out.println(result);
        sc.close();
    }
}
