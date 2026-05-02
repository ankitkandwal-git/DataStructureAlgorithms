package BinarySearchTree.SearchBST;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;

    public Node(int data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
};

public class Main {
    static Node BST(Node root,int key){
        if(root==null) return root;
        while(root != null){
            if(root.data == key) return root;
            else if(key<root.data) root = root.left;
            else root = root.right;
        }
        return root;
    }
    public static void main(String[]args){
        try(Scanner sc = new Scanner(System.in)){
            Node root = new Node(4);
            root.left = new Node(2);
            root.right = new Node(7);
            root.left.left = new Node(1);
            root.left.right = new Node(3);

            System.out.print("Enter the key to search: ");
            int key = sc.nextInt();
            Node result = BST(root,key);
            if(result != null) System.out.println("Key found: " + result.data);
            else System.out.println("Key not found in the BST.");
        }
    }
}
