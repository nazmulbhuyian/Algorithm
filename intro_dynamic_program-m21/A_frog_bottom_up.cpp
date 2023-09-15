// Problem Statement
// There are 
// N stones, numbered 
// 1,2,…,N. For each 
// i (
// 1≤i≤N), the height of Stone 
// i is 
// h 
// i
// ​
//  .

// There is a frog who is initially on Stone 
// 1. He will repeat the following action some number of times to reach Stone 
// N:

// If the frog is currently on Stone 
// i, jump to Stone 
// i+1 or Stone 
// i+2. Here, a cost of 
// ∣h 
// i
// ​
//  −h 
// j
// ​
//  ∣ is incurred, where 
// j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone 
// N.

// Constraints
// All values in input are integers.
// 2≤N≤10 
// 5
 
// 1≤h 
// i
// ​
//  ≤10 
// 4
 
// Input
// Input is given from Standard Input in the following format:

// N
// h 
// 1
// ​
  
// h 
// 2
// ​
  
// … 
// h 
// N
// ​
 
// Output
// Print the minimum possible total cost incurred.

// Sample Input 1
// Copy
// 4
// 10 30 40 20
// Sample Output 1
// Copy
// 30
// If we follow the path 
// 1 → 
// 2 → 
// 4, the total cost incurred would be 
// ∣10−30∣+∣30−20∣=30.

// Sample Input 2
// Copy
// 2
// 10 10
// Sample Output 2
// Copy
// 0
// If we follow the path 
// 1 → 
// 2, the total cost incurred would be 
// ∣10−10∣=0.

// Sample Input 3
// Copy
// 6
// 30 10 60 10 60 50
// Sample Output 3
// Copy
// 40
// If we follow the path 
// 1 → 
// 3 → 
// 5 → 
// 6, the total cost incurred would be 
// ∣30−60∣+∣60−60∣+∣60−50∣=40.



#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cost[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }
    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);
    for (int i = 3; i <= n; i++)
    {
        // int choice1 = dp[i - 2] + abs(cost[i] - cost[i - 2]);
        // int choice2 = dp[i - 1] + abs(cost[i] - cost[i - 1]);
        dp[i] = min(dp[i - 2] + abs(cost[i] - cost[i - 2]), dp[i - 1] + abs(cost[i] - cost[i - 1])); // dp state
    }
    cout << dp[n] << endl;
    return 0;
}