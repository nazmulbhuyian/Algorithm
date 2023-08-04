// Question: You are given an array of N positive integers. The next line will contain an integer K. You need to tell whether there exists more than one occurrence of K in that array or not. If there exists more than one occurrence of K print YES, Otherwise print NO.
// See the sample input-output for more clarification.
// The given array will be sorted in increasing order. And it is guaranteed that at least one occurrence of K will exist.	 You must solve this in O(logn) complexity.
// Marks: 20



// Sample Input
// Sample Output
// 7
// 1 3 4 6 6 9 17		
// 6
// YES
// 10
// 0 1 2 3 4 5 6 7 8 9
// 3
// NO


#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int target) {
    int cnt = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == target) {
            cnt++;
            if(arr[mid-1]==target){
                cnt++;
            }
            if(arr[mid+1]==target){
                cnt++;
            }
        }
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cin >> k;
    
    int result = binarySearch(arr, 0, n-1, k);
    if (result > 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}