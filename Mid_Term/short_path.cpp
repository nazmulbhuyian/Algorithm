// Problem Statement

// You will be given N numbers of nodes, E numbers of edges in a graph. For each edge you will be given A, B and W which means there is a connection from A to B for which you need to give W cost. The value of nodes could be from 1 to N.

// You will be given a source node S. Then you will be given a test case T, for each test case you will be given a destination node D and a cost DW. You need to tell if you can go to the destination from source using DW cost.

// Input Format

// First line will contain N and E.
// Next E lines will contain A and B.
// Next line will contain source node S.
// Next line will contain T, the number of test cases.
// For each test case, you will get D and DW.
// Constraints

// 1 <= N <= 1000
// 1 <= E <= N*(N-1)
// 1 <= S <= N
// 1 <= T <= 1000
// 1 <= D <= N
// 0 <= DW <= 10^9
// Output Format

// Ouput "YES" or "NO" for each test case if it is possible to go from S to D in DW cost.
// Sample Input 0

// 5 7
// 1 2 10
// 1 3 2
// 3 2 1
// 2 4 7
// 3 4 2
// 4 5 5
// 2 5 2
// 1
// 5
// 1 0
// 2 5
// 3 1
// 4 4
// 5 6
// Sample Output 0

// YES
// YES
// NO
// YES
// YES

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<pair<int, int>> v[N];
// int dis[N];
// bool vis[N];
// void dijkstra(int s)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     pq.push({0, s});
//     dis[s] = 0;
//     while (!pq.empty())
//     {
//         pair<int, int> parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         if (vis[parentNode])
//         {
//             continue;
//         }
//         vis[parentNode] = true;
//         int parentCost = parent.first;
//         for (int i = 0; i < v[parentNode].size(); i++)
//         {
//             pair<int, int> child = v[parentNode][i];
//             int childNode = child.first;
//             int childCost = child.second;
//             if (parentCost + childCost < dis[childNode])
//             {
//                 dis[childNode] = parentCost + childCost;
//                 pq.push({dis[childNode], childNode});
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         v[a].push_back({b, w});
//         v[b].push_back({a, w});
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }

//     int source;
//     cin>>source;
//     dijkstra(source);

//     int testCase;
//     cin>>testCase;
//     while (testCase--)
//     {
//         int distan,distanCost;
//         cin>>distan>>distanCost;
//         int result = dis[distan];
//         if (result==distanCost)
//         {
//             cout<<"YES"<<endl;
//         }else cout<<"NO"<<endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
long long int d[N];
int n, m;

void bellman_ford(int s)
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;

    d[s] = 0;

    for (int i = 1; i < n; i++)
    {
        // all edges relaxation
        for (int u = 1; u <= n; u++)
        {
            for (pii vpair : g[u])
            {
                int v = vpair.first;
                int w = vpair.second;

                if (d[u] != INF && d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                }
            }
        }
    }
}

int main()
{

    cin >> n >> m;

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] = LONG_MAX;
    }

    int source;
    cin >> source;
    bellman_ford(source);

    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int distan, distanCost;
        cin >> distan >> distanCost;
        int result = d[distan];
        if (result <= distanCost)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<pair<int, int>> v[N];
// long long int dis[N];
// bool vis[N];
// void dijkstra(int s)
// {
//     priority_queue<pair< int,  int>, vector<pair< int,  int>>, greater<pair< int,  int>>> pq;

//     pq.push({0, s});
//     dis[s] = 0;
//     while (!pq.empty())
//     {
//         pair< int,  int> parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         if (vis[parentNode])
//         {
//             continue;
//         }
//         vis[parentNode] = true;
//          int parentCost = parent.first;
//         for (int i = 0; i < v[parentNode].size(); i++)
//         {
//             pair< int,  int> child = v[parentNode][i];
//              int childNode = child.first;
//              int childCost = child.second;
//             if (parentCost + childCost < dis[childNode])
//             {
//                 dis[childNode] = parentCost + childCost;
//                 pq.push({dis[childNode], childNode});
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         v[a].push_back({b, w});
//         // v[b].push_back({a, w});
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = LONG_MAX;
//     }

//     int source;
//     cin>>source;
//     dijkstra(source);

//     int testCase;
//     cin>>testCase;
//     while (testCase--)
//     {
//         int distan,distanCost;
//         cin>>distan>>distanCost;
//         int result = dis[distan];
//         if (result<=distanCost)
//         {
//             cout<<"YES"<<endl;
//         }else cout<<"NO"<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// vector<pair<int, int>> v[N];
// int dis[N];
// bool vis[N];
// void dijkstra(int s)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     pq.push({0, s});
//     dis[s] = 0;
//     while (!pq.empty())
//     {
//         pair<int, int> parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         if (vis[parentNode])
//         {
//             continue;
//         }
//         vis[parentNode] = true;
//         int parentCost = parent.first;
//         for (int i = 0; i < v[parentNode].size(); i++)
//         {
//             pair<int, int> child = v[parentNode][i];
//             int childNode = child.first;
//             int childCost = child.second;
//             if (parentCost + childCost < dis[childNode])
//             {
//                 dis[childNode] = parentCost + childCost;
//                 pq.push({dis[childNode], childNode});
//             }
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         v[a].push_back({b, w});
//         // v[b].push_back({a, w});
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         dis[i] = INT_MAX;
//     }

//     int source;
//     cin>>source;
//     dijkstra(source);

//     cout << dis[3] << endl;

//     // int testCase;
//     // cin>>testCase;
//     // while (testCase--)
//     // {
//     //     int distan,distanCost;
//     //     cin>>distan>>distanCost;
//     //     int result = dis[distan];
//     //     if (result==distanCost)
//     //     {
//     //         cout<<"YES"<<endl;
//     //     }else cout<<"NO"<<endl;
//     // }
//     return 0;
// }