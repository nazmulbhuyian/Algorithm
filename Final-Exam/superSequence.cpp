// Problem Statement

// Mina and Rita were playing with their dolls. Both of them had given names to their dolls. Now, they want to create a nameplate to attach to their dog's collar. However, their father told them he can only provide money for one nameplate. So, they need to create a single nameplate that includes both of their doll's names while keeping it as short as possible due to the character limit.

// Can you help them choose a name that incorporates both of their doll's names and is as short as possible?

// Input Format

// First line will contain T, the number of test cases.
// Each line of the test case will contain two strings A and B which are the name of the dolls.
// Constraints

// 1 <= T <= 1000
// 1 <= |A|, |B| <= 1000; Here |A| and |B| means the length of A and B. The string will contain small English alphabets only and won't contain any spaces.
// Output Format

// Print the number of character in that name which can be printed on the name plate.
// Sample Input 0

// 2
// buzzi kuzzi
// tommy batomzy
// Sample Output 0

// 6
// 8



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int n = a.size();
        int m = b.size();
        int dp[n + 1][m + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int lcs_length = dp[n][m];
        int total_length = n + m - lcs_length;

        cout << total_length << endl;
    }

    return 0;
}
