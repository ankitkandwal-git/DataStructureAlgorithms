package BinarySearchTree.InsertBST;

import java.util.*;

class Node{
    public int data;
    public Node left;
    public Node right;
    public Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
};

public class Main{
    static void inorder(Node root){
        if(root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    static Node insert(Node root, int key){
        if(root==null) return new Node(key);
        Node cur = root;
        while(true){
            if(key<cur.data){
                if(cur.left==null){
                    cur.left = new Node(key);
                    break;
                }
                cur = cur.left;
            }
            else{
                if(cur.right==null){
                    cur.right = new Node(key);
                    break;
                }
                cur = cur.right;
            }
        }
        return root;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the number of nodes:");
            int n = sc.nextInt();
            Node root = null;
            System.out.println("Enter the values of nodes:");
            for(int i=0;i<n;i++){
                int key = sc.nextInt();
                root = insert(root, key);
            }
            System.out.println("Inorder Traversal of the BST:");
            inorder(root);
            
        }
    }
}
