package BinaryTree.RightViewOfBinaryTree;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
};

public class Main{
    public static ArrayList<Integer> rightView(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        if (root == null) return ans;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int size = q.size();
            int temp = 0;
            for (int i = 0; i < size; i++) {
                Node cur = q.poll();
                temp = cur.data;
                if (cur.left != null) q.add(cur.left);
                if (cur.right != null) q.add(cur.right);
            }
            ans.add(temp);
        }
        return ans;
    }

    public static Node insert(Node root, int data) {
        if (root == null) return new Node(data);
        if (data < root.data) root.left = insert(root.left, data);
        else root.right = insert(root.right, data);
        return root;
    }
    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the size of Tree: ");
            int n = sc.nextInt();
            Node root = null;
            for (int i = 0; i < n; i++) {
                int data = sc.nextInt();
                root = insert(root, data);
            }
            ArrayList<Integer> result = rightView(root);
            System.out.println("Right View of the Binary Tree: " + result);
        }
    }
}