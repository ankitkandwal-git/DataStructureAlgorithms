package BinaryTree.DiameterOfBinaryTree;
import java.util.Scanner;
class DiameterOfBinaryTree{
    static class Node{
        int data;
        Node left,right;
        Node(int x){
            data = x;
            left = null;
            right = null;
        }
    };
    static int diameter(Node root,int[]result){
        if(root == null) return 0;
        int leftHeight = diameter(root.left,result);
        int rightHeight = diameter(root.right,result);
        result[0] = Math.max(result[0],leftHeight + rightHeight + 1);
        return Math.max(leftHeight,rightHeight) + 1;
    }
    public static void main(String[]args){
        Node root = null;
        try(Scanner sc = new Scanner(System.in)){
            System.out.print("Enter the size of BT: ");
            int n = sc.nextInt();
            for(int i=0;i<n;i++){
                int x;
                System.out.print("Enter the value of node: ");
                x = sc.nextInt();
                if(root==null) root = new Node(x);
                else {
                    Node temp = root;
                    while(true){
                        if(x < temp.data){
                            if(temp.left == null){
                                temp.left = new Node(x);
                                break;
                            }
                            else temp = temp.left;
                        }
                        else{
                            if(temp.right == null){
                                temp.right = new Node(x);
                                break;
                            }
                            else temp = temp.right;
                        }
                    }
                }
            }
        }
        int[] result = new int[1];
        diameter(root,result);
        System.out.println("Diameter of the binary tree is: " + result[0]);
    }
};
