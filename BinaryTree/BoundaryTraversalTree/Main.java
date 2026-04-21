
package BinaryTree.BoundaryTraversalTree;
import java.util.List;
import java.util.ArrayList;

class BoundaryTreeTraversal{
    static class Node{
        int data;
        Node left, right;
        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    static boolean isLeaf(Node node) {
        return (node.left == null && node.right == null);
    }
    static void leftBoundary(Node node, List<Integer> res) {
        Node cur = node.left;
        while (cur != null) {
            if (!isLeaf(cur)) res.add(cur.data);
            if (cur.left != null) cur = cur.left;
            else cur = cur.right;
        }
    }
    static void leaves(Node node, List<Integer> res) {
        if (node == null) return;
        if (isLeaf(node)) {
            res.add(node.data);
            return;
        }
        leaves(node.left, res);
        leaves(node.right, res);
    }
    static void rightBoundary(Node node, List<Integer> res) {
        Node cur = node.right;
        List<Integer> tmp = new ArrayList<>();
        while (cur != null) {
            if (!isLeaf(cur)) tmp.add(cur.data);
            if (cur.right != null) cur = cur.right;
            else cur = cur.left;
        }
        for (int i = tmp.size() - 1; i >= 0; --i) {
            res.add(tmp.get(i));
        }
    }
    static List<Integer> boundary(Node root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;
        if (!isLeaf(root)) res.add(root.data);
        leftBoundary(root, res);
        leaves(root, res);
        rightBoundary(root, res);
        return res;
    }
    public static void main(String[]args){
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);

        List<Integer> result = boundary(root);
        for (int val : result) {
            System.out.print(val + " ");
        }
    }
};