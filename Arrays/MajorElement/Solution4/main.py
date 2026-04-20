class MajorElement:
    def majElement(self,arr):
        n = len(arr)
        count = 1
        leader = arr[0]
        for i in range(n):
            if count == 0:
                leader = arr[i]
                count = 1
            elif leader == arr[i]:
                count +=1
            else :
                count-=1
        return leader 

n = int(input("Enter the size of arrays: "))
arr = list(map(int,input("Enter the array element: ").split()))
obj = MajorElement()
result = obj.majElement(arr)
print("The majority element is: ",result)