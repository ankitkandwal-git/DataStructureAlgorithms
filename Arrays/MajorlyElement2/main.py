class MajorlyElement2:
    def majorElement(self,nums):
        n = len(nums)
        l1 = float('-inf')
        l2 = float('-inf')
        m1 = 0
        m2 = 0
        c1 = 0
        c2 = 0
        ans = []
        for i in range(n):
            if nums[i] != l2 and m1==0:
                l1 = nums[i]
                m1 = 1
            elif nums[i] != l1 and m2==0:
                l2 = nums[i]
                m2 = 1
            elif nums[i] == l1:
                m1 += 1
            elif nums[i] == l2:
                m2 += 1
            else :
                m1 -= 1
                m2 -= 1 
            
            
        for i in range(n):
            if nums[i] == l1:
                c1 += 1
            elif nums[i] == l2:
                c2 += 1

        if c1 > n // 3:
            ans.append(l1)
        if c2 > n // 3:
            ans.append(l2)

        return ans 
    
    
n = int(input("Enter the number of elements in the array: "))
nums = list(map(int, input("Enter the elements of the array: ").split()))
obj = MajorlyElement2()
result = obj.majorElement(nums)
print("The majority elements are:", result)