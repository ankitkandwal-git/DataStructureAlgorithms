def help(arr):
    n = len(arr)
    maxi = 0;
    mini = float('inf')
    for i in range(0,26):
        if arr[i] != 0:
            mini = min(mini,arr[i])
            maxi = max(maxi,arr[i])
    return maxi - mini

def beauty(s):
    n = len(s)
    ans = 0
    for i in range(n):
        arr = [0]*26
        for j in range(i,n):
            arr[ord(s[j]) - ord('a')] += 1
            ans += help(arr)
    return ans

string = input("Enter the string: ")
print(beauty(string))