def largest_element(arr,n):
    largest_num = float('-inf')
    for i in range(n):
        if arr[i]>largest_num:
            largest_num = arr[i]
    return largest_num

n = int(input())
arr = list(map(int,input().split()))
print(largest_element(arr,n))