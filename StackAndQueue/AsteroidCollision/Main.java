package StackAndQueue.AsteroidCollision;
import java.util.*;
public class Main {
    public static int[] asteroidCollision(int[] arr) {
        int n = arr.length;
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                stk.push(arr[i]);
            } else {
                while (!stk.isEmpty() && stk.peek() > 0 && stk.peek() + arr[i] < 0) {
                    stk.pop();
                }
                if (stk.isEmpty() || stk.peek() < 0) {
                    stk.push(arr[i]);
                } else if (stk.peek() + arr[i] == 0) {
                    stk.pop();
                }
            }
        }

        int[] ans = new int[stk.size()];
        int i = stk.size() - 1;
        while (!stk.isEmpty()) {
            ans[i] = stk.pop();
            i--;
        }

        return ans;
    }


    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in)) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] result = asteroidCollision(arr);

        for (int x : result) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
 }
}