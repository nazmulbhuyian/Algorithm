// Problem Statement

// You will be given an undirected graph as input. You will be given a query Q, for each query you will be given a source S and a destination D. You need to tell the minimum distance from source to destination for each query.

// Note: If there is no path in between the source and destination, print -1.

// Input Format

// First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 10^5.
// Next E lines will contain A, B which means there is a edge between node A and B.
// Next line will contain Q, the number of queries.
// For each query every line will contain S and D.
// Constraints

// 1 <= N, E <= 1000
// 1 <= Q <= 1000
// 0 <= S, D <= 10^5
// Output Format

// Output the minimum distance from source to destination for each query.
// Sample Input 0

// 6 7
// 0 1
// 0 2
// 1 2
// 0 3
// 4 2
// 3 5
// 4 3
// 6
// 0 5
// 1 5
// 2 5
// 2 3
// 1 4
// 0 0
// Sample Output 0

// 2
// 3
// 3
// 2
// 2
// 0
// Explanation 0

// In this test case, the graph is given below.
// image

// Sample Input 1

// 7 6
// 0 1
// 0 2
// 1 2
// 0 3
// 4 2
// 4 3
// 4
// 3 10
// 2 6
// 0 6
// 0 10
// Sample Output 1

// -1
// -1
// -1
// -1

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
int dist[N];

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int s, d;
        cin >> s >> d;

        for (int i = 0; i < n; i++)
        {
            dist[i] = -1;
        }

        dist[s] = 0;

        queue<int> q;
        q.push(s);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor : adjList[current])
            {
                if (dist[neighbor] == -1)
                {
                    dist[neighbor] = dist[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        cout << dist[d] << endl;
    }

    return 0;
}









#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
int dist[N];

// void bfs(int source, int n)
// {

//     queue<int> q;
//     q.push(source);
//     dist[source] = 0;

//     while (!q.empty())
//     {
//         int current = q.front();
//         q.pop();

//         for (int neighbor : adjList[current])
//         {
//             if (dist[neighbor] == INT_MAX)
//             {
//                 dist[neighbor] = dist[current] + 1;
//                 q.push(neighbor);
//             }
//         }
//     }
// }

void dfs(int node, int depth)
{
    dist[node] = depth;

    for (int neighbor : adjList[node])
    {
        if (dist[neighbor] == -1)
        {
            dfs(neighbor, depth + 1);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int s, d;
        cin >> s >> d;

        for (int i = 0; i < n; i++)
        {
            dist[i] = INT_MAX;
        }

        bool found = false;
        for (int i = 0; i < N; ++i)
        {
            auto it = find(adjList[i].begin(), adjList[i].end(), s);
            if (it != adjList[i].end())
            {
                found = true;
                break;
            }
        }

        if (found)
        {

            bool found2 = false;
            for (int i = 0; i < N; ++i)
            {
                auto it = find(adjList[i].begin(), adjList[i].end(), d);
                if (it != adjList[i].end())
                {
                    found2 = true;
                    break;
                }
            }

            if (found2)
            {
                // bfs(s, n);
                dfs(s, 0);
                cout << dist[d] << endl;
            }
            else
                cout << -1 << endl;
        }
        else
            cout << -1 << endl;

        // bfs(s, n);
        // if (dist[d] == INT_MAX)
        // {
        //     cout << -1 << endl;
        // }
        // else
        // {
        //     cout << dist[d] << endl;
        // }
    }

    return 0;
}
