There are n
//  cities and m
//  roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.

// For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.

// Input

// The first input line has two integers n
//  and m
// : the number of cities and roads. The cities are numbered 1,2,…,n
// .

// Then, there are m
//  lines describing the roads. Each line has three integers a
// , b
//  and c
// : there is a road between cities a
//  and b
// , and its reparation cost is c
// . All roads are two-way roads.

// Every road is between two different cities, and there is at most one road between two cities.

// Output

// Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".

// Constraints
// 1≤n≤105

// 1≤m≤2⋅105

// 1≤a,b≤n

// 1≤c≤109

// Example

// Input:
// 5 6
// 1 2 3
// 2 3 5
// 2 4 2
// 3 4 8
// 5 1 7
// 5 4 4

// Output:
// 14




#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}
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
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v.push_back(Edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    for (Edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;
        ans.push_back(val);
        dsu_union(a, b);
    }
    long long sum = 0;
    for (Edge val : ans)
    {
        sum += (long long)val.w;
    }
    if (ans.size() == n - 1)
    {
        cout << sum << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}