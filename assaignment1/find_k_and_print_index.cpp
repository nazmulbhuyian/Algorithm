// Question: Write a C++ program that takes N integer numbers that are sorted and distinct. The next line will contain an integer k. You need to tell whether K exists in that array or not. If it exists, print its index otherwise print “Not Found”. 	
// You must solve this in O(logn) complexity.
// Marks: 20



// Sample Input
// Sample Output
// 8
// -4 0 2 6 9 10 29 54
// 29
// 6
// 10
// 0 1 2 3 4 5 6 7 8 9
// -3
// Not Found



#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int target) {
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
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
    if (result != -1) {
        cout << result << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    return 0;
}
