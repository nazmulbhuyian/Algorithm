// There are N
//  items numbered from 1 to N
// . The ith
//  item has a weight of wi
//  and a value of vi
// .

// You have to choose some items out of the N
//  items and carry them home in a knapsack. The capacity of the knapsack is W
//  which donate the maximum weight that can be carried inside the knapsack. In other words, W
//  means the total summation of all weights of items that can be carried in the knapsack.

// Print maximum possible sum of values of items that you can take home.

// Note: Solve this problem using recursion.

// Input
// First line contains two numbers N
//  and W
//  (1≤N≤20,1≤W≤100)
//  number of items and the capacity of the knapsack.

// Next N
//  lines will contain two numbers wi
//  and vi
//  (1≤wi≤50,1≤vi≤1000)
// Output
// Print maximum possible sum of values of items that you can take home.

// Examples
// inputCopy
// 3 8
// 3 30
// 4 50
// 5 60
// outputCopy
// 90
// inputCopy
// 6 15
// 6 5
// 5 6
// 6 4
// 6 6
// 3 5
// 7 2
// outputCopy
// 17


#include <bits/stdc++.h>
using namespace std;
int knapsack(int n, int s, int v[], int w[])
{
    // base case
    if (n == 0 || s == 0)
        return 0;
    if (w[n - 1] <= s)
    {
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        return max(op1, op2);
    }
    else
    {
        return knapsack(n - 1, s, v, w);
    }
}
int main()
{
    int n, s;
    cin >> n >> s;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cout << knapsack(n, s, v, w);
    return 0;
}