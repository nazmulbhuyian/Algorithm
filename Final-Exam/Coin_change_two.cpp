// Problem Statement

// Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants. But this time the fairy told him to choose the minimum possible number of marks he can.

// Can you tell what will be the minimum number of marks Zarif will need to fulfill his dream. If it is not possible then print -1.

// Input Format

// First line will contain T, the number of test cases.
// First line of each test case will contain N and M.
// Second line of each test case will contain a list A of N marks.
// Constraints

// 1 <= T <= 1000
// 1 <= N <= 1000
// 0 <= M <= 1000
// 1 <= A[i] <= 100; 0 <= i < N
// Output Format

// Output minimum number of marks needed if he can obtain perfect score of 1000, -1 otherwise.
// Sample Input 0

// 5
// 5 1000
// 1 2 3 4 5
// 5 999
// 2 3 4 5 6
// 2 900
// 30 40
// 3 904
// 2 6 5
// 2 904
// 2 5
// Sample Output 0

// 0
// -1
// 3
// 16
// 21



#include <bits/stdc++.h>
using namespace std;

int findMinimumMarks(int n, vector<int>& marks, int target) {
    vector<int> dp(target + 1, INT_MAX - 1);
    dp[0] = 0;

    for (int mark : marks) {
        for (int i = mark; i <= target; i++) {
            dp[i] = min(dp[i], 1 + dp[i - mark]);
        }
    }

    return (dp[target] == INT_MAX - 1) ? -1 : dp[target];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> marks(n);
        for (int i = 0; i < n; i++) {
            cin >> marks[i];
        }

        int target = 1000 - m;
        int minMarksNeeded = findMinimumMarks(n, marks, target);

        cout << minMarksNeeded << endl;
    }

    return 0;
}
