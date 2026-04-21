#include<bits/stdc++.h>
using namespace std;

class MergeTwoSortedArrays{
    public:
    void mergeArray(vector<int>& arr1, vector<int>& arr2){
        int m = arr1.size();
        int n = arr2.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            if(arr1[i] < arr2[j]){
                i++;
            } else {
                swap(arr1[i], arr2[j]);
                sort(arr2.begin(), arr2.end()); // Ensure arr2 remains sorted
                i++;
            }
        }
    }
};
int main(){
    int m, n;
    cout << "Enter the size of first array: ";
    cin >> m;
    cout << "Enter the size of second array: ";
    cin >> n;
    vector<int> arr1(m), arr2(n);
    cout << "Enter the elements of first array: ";
    for(int i = 0; i < m; i++){
        cin >> arr1[i];
    }
    cout << "Enter the elements of second array: ";
    for(int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    MergeTwoSortedArrays obj;
    obj.mergeArray(arr1, arr2);
    cout << "Merged array: ";
    for(int i = 0; i < m; i++){
        cout << arr1[i] << " ";
    }
    for(int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }
    return 0;
}