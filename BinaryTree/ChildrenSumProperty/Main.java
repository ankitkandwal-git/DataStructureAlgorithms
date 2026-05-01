package BinaryTree.ChildrenSumProperty;
import java.util.*;

public class Main {
    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }

    static boolean childrenSumProperty(Node root) {
        if (root == null) return true;
        if (root.left == null && root.right == null) return true;
        int childSum = 0;
        if (root.left != null) childSum += root.left.data;
        if (root.right != null) childSum += root.right.data;
        if (root.data != childSum) return false;
        return childrenSumProperty(root.left) && childrenSumProperty(root.right);
    }

    public static void main(String[] args) {
        Node root = new Node(10);
        root.left = new Node(8);
        root.right = new Node(2);
        root.left.left = new Node(3);
        root.left.right = new Node(5);
        root.right.right = new Node(2);
        System.out.println(childrenSumProperty(root));
    }
}