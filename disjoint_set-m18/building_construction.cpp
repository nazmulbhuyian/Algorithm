// Byteland has n
//  cities, and m
//  roads between them. The goal is to construct new roads so that there is a route between any two cities.

// Your task is to find out the minimum number of roads required, and also determine which roads should be built.

// Input

// The first input line has two integers n
//  and m
// : the number of cities and roads. The cities are numbered 1,2,…,n
// .

// After that, there are m
//  lines describing the roads. Each line has two integers a
//  and b
// : there is a road between those cities.

// A road always connects two different cities, and there is at most one road between any two cities.

// Output

// First print an integer k
// : the number of required roads.

// Then, print k
//  lines that describe the new roads. You can print any valid solution.

// Constraints
// 1≤n≤105

// 1≤m≤2⋅105

// 1≤a,b≤n

// Example

// Input:
// 4 2
// 1 2
// 3 4

// Output:
// 1
// 2 3








#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int mx = 0;
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
            mx = max(mx, parentSize[leaderA]);
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx = max(mx, parentSize[leaderB]);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int cmp = n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
        {
            cmp--;
            dsu_union(a, b);
        }
        cout << cmp << " " << mx << endl;
    }
    return 0;
}