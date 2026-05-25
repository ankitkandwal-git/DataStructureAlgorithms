package BinaryTree.MaximumLevelSum;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;

    Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
};

public class Main{
    static int maxLevelSum(Node root){
        if(root==null) return 0;
        Queue<Node>q = new LinkedList<>();
        q.add(root);
        int maxSum = Integer.MIN_VALUE;
        while(!q.isEmpty()){
            int size = q.size();
            int sum = 0;
            for(int i=0;i<size;i++){
                Node temp = q.poll();
                if(temp==null) continue;
                sum += temp.data;
                if(temp.left!=null) q.add(temp.left);
                if(temp.right!=null) q.add(temp.right);
            }
            maxSum = Math.max(maxSum,sum);
        }
        return maxSum;
    }

    static Node insert(Node root, int data){
        if(root==null) return new Node(data);
        if(data<=root.data) root.left = insert(root.left, data);
        else root.right = insert(root.right, data);
        return root;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of nodes in the binary tree:");
            int n = sc.nextInt();
            Node root = null;
            System.out.println("Enter the values of the nodes (use -1 for null):");
            for(int i=0;i<n;i++){
                int data = sc.nextInt();
                if(data==-1) continue;
                root = insert(root,data);
            }
            int result = maxLevelSum(root);
            System.out.println("The maximum level sum is: " + result);
        }
    }
}