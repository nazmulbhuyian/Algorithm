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
int dis[N];
bool vis[N];
vector<int> v[N];
vector<int> cmp;
void dfs(int s)
{
    vis[s] = true;
    cmp.push_back(s);
    for (int child : v[s])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            ans.push_back(i);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << " " << ans[i + 1] << endl;
    }
    return 0;
}