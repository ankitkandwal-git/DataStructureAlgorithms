import collections

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class BalancedBinaryTree:
    def _check_height(self, root): 
        if root is None:
            return 0
        left_height = self._check_height(root.left)
        if left_height == -1: return -1
        right_height = self._check_height(root.right)
        if right_height == -1: return -1
        diff = abs(left_height - right_height) 
        if diff > 1: 
            return -1 
        return max(left_height, right_height) + 1 
        
    def balanced_BT(self,root): 
        return self._check_height(root) != -1 

n = int(input("enter the number of nodes in the tree: "))
tree = BalancedBinaryTree()
print("enter the nodes in the tree (space-separated): ")
values = []
while len(values) < n:
    values.extend(map(int, input().split()))

root = None
if values:
    root = Node(values[0])
    queue = collections.deque([root])
    i = 1
    while queue and i < n:
        curr = queue.popleft()
        if i < n and values[i] != -1:
            curr.left = Node(values[i])
            queue.append(curr.left)
        i += 1
        if i < n and values[i] != -1:
            curr.right = Node(values[i])
            queue.append(curr.right)
        i += 1

if tree.balanced_BT(root):
    print("The tree is balanced.")
else:
    print("The tree is not balanced.")