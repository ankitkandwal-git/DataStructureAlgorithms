package BinarySearchTree.DeletionBST;
import java.util.*;

class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
};

public class Main{
    void inorder(Node root) {
        if (root != null) {
            inorder(root.left);
            System.out.print(root.data + " ");
            inorder(root.right);
        }
    }
    Node deleteNode(Node root, int key){
        if(root==null) return root;
        if(key<root.data){
            root.left = deleteNode(root.left,key);
            return root;
        }
        else if(key>root.data){
            root.right = deleteNode(root.right,key);
            return root;
        } 
        if(root.left==null){
            Node temp = root.right;
            return temp;
        }
        if(root.right==null){
            Node temp = root.left;
            return temp;
        }
        Node cur = root.right;
        while(cur.left!=null){
            cur = cur.left;
        }
        root.data = cur.data;
        root.right = deleteNode(root.right,cur.data);
        return root;
    }
    public static void main(String[] args) {
        Main tree = new Main();
        Node root = new Node(50);
        root.left = new Node(30);
        root.right = new Node(70);
        root.left.left = new Node(20);
        root.left.right = new Node(40);
        root.right.left = new Node(60);
        root.right.right = new Node(80);

        System.out.println("Inorder traversal of the given tree:");
        tree.inorder(root);

        System.out.println("\n\nDelete 20:");
        root = tree.deleteNode(root, 20);
        tree.inorder(root);

        System.out.println("\n\nDelete 30:");
        root = tree.deleteNode(root, 30);
        tree.inorder(root);

        System.out.println("\n\nDelete 50:");
        root = tree.deleteNode(root, 50);
        tree.inorder(root);
    }
}