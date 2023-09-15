// There are n
//  cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of m
//  roads.

// A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number of components and the size of the largest component.

// Input

// The first input line has two integers n
//  and m
// : the number of cities and roads. The cities are numbered 1,2,…,n
// .

// Then, there are m
//  lines describing the new roads. Each line has two integers a
//  and b
// : a new road is constructed between cities a
//  and b
// .

// You may assume that every road will be constructed between two different cities.

// Output

// Print m
//  lines: the required information after each day.

// Constraints
// 1≤n≤105

// 1≤m≤2⋅105

// 1≤a,b≤n

// Example

// Input:
// 5 3
// 1 2
// 1 3
// 4 5

// Output:
// 4 2
// 3 3
// 2 3





#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int parentLevel[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
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
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentLevel[leaderA] > parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if (parentLevel[leaderB] > parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }
    map<int, bool> mp;
    for (int i = 1; i <= n; i++)
    {
        int ldr = dsu_find(i);
        mp[ldr] = true;
    }
    vector<int> v;
    for (pair<int, bool> p : mp)
    {
        v.push_back(p.first);
    }
    cout << v.size() - 1 << endl;
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << v[i] << " " << v[i + 1] << endl;
    }
    return 0;
}