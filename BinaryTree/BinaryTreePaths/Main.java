package BinaryTree.BinaryTreePaths;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
java.util.ArrayList;
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data=data;
        this.left=null;
        this.right=null;
    }
}
public class Main{
    static void paths(Node root,List<Integer> v,List<List<Integer>> ans){
        if(root==null) return;
        v.add(root.data);
        if(root.left==null && root.right==null){
            ans.add(new ArrayList<>(v));
        }
        paths(root.left,v,ans);
        paths(root.right,v,ans);
        v.remove(v.size()-1);
    }
    // Insert node in level order
    static Node insert(Node root, int data) {
        if (data == -1) return root; // skip nulls
        if (root == null) return new Node(data);
        java.util.Queue<Node> q = new java.util.LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node temp = q.poll();
            if (temp.left == null) {
                temp.left = new Node(data);
                break;
            } else q.add(temp.left);
            if (temp.right == null) {
                temp.right = new Node(data);
                break;
            } else q.add(temp.right);
        }
        return root;
    }
    public static List<List<Integer>>binaryPath(Node root){
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> v = new ArrayList<>();
        paths(root,v,ans);
        return ans;
    }
    public static void main(String []ans){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of nodes in the binary tree:");
            int n = sc.nextInt();
            Node root = null;
            System.out.println("Enter the values of the nodes (enter -1 for null):");
            for(int i=0;i<n;i++){
                int data = sc.nextInt();
                root = insert(root,data);
            }
            List<List<Integer>> result = binaryPath(root);
            System.out.println("All root-to-leaf paths:");
            for(List<Integer> path : result){
                System.out.println(path);
            }
        }
    }
}