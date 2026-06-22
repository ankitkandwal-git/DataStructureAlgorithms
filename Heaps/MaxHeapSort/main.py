def isHeap(arr):
    n = len(arr)
    for i in range(n//2+1):
        left = 2*i + 1
        right = 2*i + 2

        if left < n and arr[i] < arr[left]:
            return False

        if right < n and arr[i] < arr[right]:
            return False
    return True 

n = int(input("Enter the number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))

if isHeap(arr):
    print("The array is a max heap.")
else:
    print("The array is not a max heap.")