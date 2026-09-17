class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

def array_to_LL(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for value in arr[1:]:
        current.next = Node(value)
        current = current.next
    return head

def print_LL(head):
    current = head
    while current:
        print(current.data, end=" -> ")
        current = current.next
    print("None") 


def detect_cycle(head):
    slow = head 
    fast = head
    if head is None or head.next is None:
        return False
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False 

n = int(input("Enter the number of elements in the linked list: "))
arr = list(map(int, input("Enter the elements: ").split()))
head = array_to_LL(arr)
print_LL(head)
print("Cycle detected:" , detect_cycle(head))