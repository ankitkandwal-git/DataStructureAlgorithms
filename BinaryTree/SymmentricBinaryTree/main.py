class Node: 
    def __init__(self, value): 
        self.value = value 
        self.left = None 
        self.right = None
    
    def checkSymmetry(self,root1,root2): 
        if root1 is None and root2 is None: 
            return True 
        if root1 is None or root2 is None:
            return False
        if root1.value != root2.value:
            return False
        return self.checkSymmetry(root1.left,root2.right) and self.checkSymmetry(root1.right,root2.left)
    
    def isSymmetric(root):
        if root is None:
            return True
        return root.checkSymmetry(root.left,root.right)


n = int(input("Enter the number of nodes in the tree: "))
nodes = []
for i in range(n):
    value = int(input(f"Enter the value of node {i+1}: "))
    nodes.append(Node(value))
for i in range(n):
    left_index = int(input(f"Enter the index of the left child of node {i+1} (or -1 if no left child): "))
    right_index = int(input(f"Enter the index of the right child of node {i+1} (or -1 if no right child): "))
    if left_index != -1:
        nodes[i].left = nodes[left_index]
    if right_index != -1:
        nodes[i].right = nodes[right_index]
if Node.isSymmetric(nodes[0]):
    print("The binary tree is symmetric.")
else:
    print("The binary tree is not symmetric.")
    