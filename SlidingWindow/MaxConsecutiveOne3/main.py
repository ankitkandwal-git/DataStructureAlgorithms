def longest_ones(nums,k):
    left = 0
    max_length = 0
    zero_count = 0

    for right in range(len(nums)):
        if nums[right] == 0:
            zero_count += 1

        while zero_count > k:
            if nums[left] == 0:
                zero_count -= 1
            left += 1

        max_length = max(max_length, right - left + 1)

    return max_length 

n = int(input("Enter the number of elements in the array: "))
nums = list(map(int, input("Enter the elements of the array (0s and 1s): ").split()))
k = int(input("Enter the value of k: "))
result = longest_ones(nums, k)
print("The longest subarray of 1's after flipping at most", k, "zeros is:", result)