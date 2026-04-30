class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
    def right_view(self,root):
        ans = []
        queue = []
        if root is None:
            return
        queue.append(root)
        while(queue):
            size = len(queue)
            temp = None
            for i in range(size):
                cur = queue.pop(0)
                temp = cur.data
                if cur.left:
                    queue.append(cur.left)
                if cur.right:
                    queue.append(cur.right)

            ans.append(temp)
        return ans

n = int(input("Enter the number of nodes: "))
root = None
for i in range(n):
    data = int(input("Enter the data for node {}: ".format(i+1)))
    if root is None:
        root = Node(data)
    else:
        current = root
        while True:
            if data < current.data:
                if current.left is None:
                    current.left = Node(data)
                    break
                else:
                    current = current.left
            else:
                if current.right is None:
                    current.right = Node(data)
                    break
                else:
                    current = current.right
print("Right view of the binary tree: ", root.right_view(root))
                
                