package BinaryTree.HeightOfTree;
import java.util.Scanner;
class HeightOfBinaryTree {
    public
    class Node{
        int data;
        Node left,right;
        Node(int x){
            data = x;
            left = null;
            right = null;
        }
    };
    static int heightofBT(Node root){
        if(root==null) return 0;
        int leftHeight = heightofBT(root.left);
        int rightHeight = heightofBT(root.right);
        return 1 + Math.max(leftHeight, rightHeight);
    }
    static Node insertIntoBST(Node root, int value){
        if(root == null){
            return new HeightOfBinaryTree().new Node(value);
        }
        if(value < root.data){
            root.left = insertIntoBST(root.left, value);
        } else if(value > root.data){
            root.right = insertIntoBST(root.right, value);
        }
        return root;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.println("Enter the number of nodes in the binary tree:");
            int n = sc.nextInt();
            Node root = null;
            System.out.println("Enter the values of the nodes:");
            for(int i=0; i<n; i++){
                int value = sc.nextInt();
                root = insertIntoBST(root, value);
            }
            int height = heightofBT(root);
            System.out.println("Height of the binary tree: " + height);
        }
    }
};
