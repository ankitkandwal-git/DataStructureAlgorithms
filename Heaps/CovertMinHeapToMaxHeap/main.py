class ConvertMinToMaxHeap:
    def __init__(self,arr):
        self.arr = arr
        self.n = len(arr)
    
    def heapify(self,i):
        l = 2*i+1
        r = 2*i+2
        maxi = i
        if l < self.n and self.arr[l] > self.arr[maxi]:
            maxi = l
        if r < self.n and self.arr[r] > self.arr[maxi]:
            maxi = r
        if maxi != i:
            self.arr[i], self.arr[maxi] = self.arr[maxi], self.arr[i]
            self.heapify(maxi)
    def convert(self):
        for i in range(self.n//2-1,-1,-1):
            self.heapify(i)
        return self.arr

n = int(input("Enter the number of elements in the heap: "))
arr = list(map(int, input("Enter the elements of the array: ").split()))

obj = ConvertMinToMaxHeap(arr)
print(obj.convert())