package BinaryTree.SymmentricBinaryTree;
import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;
class Main{
    static class Node{
        int data;
        Node left;
        Node right;

        public Node(int data)
        {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    };
    static boolean checkSymmetric(Node root1,Node root2){
        if(root1==null && root2==null) return true;
        if(root1==null || root2==null) return false;
        if(root1!= null && root2==null) return false;
        if(root1.data != root2.data) return false;
        return checkSymmetric(root1.left,root2.right) && checkSymmetric(root1.right,root2.left);
    }
    static boolean isSymmetric(Node root){
        if(root==null) return true;
        return checkSymmetric(root.left,root.right);
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of nodes in the tree:");
            int n = sc.nextInt();
            Node root = null;
            System.out.println("Enter values of node: ");
            Queue<Node> q = new LinkedList<>();
            for(int i=0;i<n;i++){
                int data = sc.nextInt();
                Node newNode = new Node(data);
                if(root==null){
                    root = newNode;
                    q.add(root);
                }
                else{
                    Node parent = q.peek();
                    if(parent.left==null){
                        parent.left = newNode;
                        q.add(parent.left);
                    }
                    else{
                        parent.right = newNode;
                        q.add(parent.right);
                        q.poll();
                    }
                }
            }
            if(isSymmetric(root)){
                System.out.println("The tree is symmetric.");
            }
            else{
                System.out.println("The tree is not symmetric.");
            }
        }
    }
}