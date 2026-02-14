#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {nums[i], i};
    }
    sort(arr.begin(), arr.end());
    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i].second == i) {
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arr[j].second;
            cycle_size++;
        }
        if (cycle_size > 0) {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}