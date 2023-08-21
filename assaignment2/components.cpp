// Problem Statement

// You will be given an undirected graph as input. You need to tell the number nodes in each component in ascending order.

// Note: There will be no component with single node.

// Input Format

// First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 1000.
// Next E lines will contain A, B which means there is a edge between node A and B.
// Constraints

// 1 <= N, E <= 1000
// Output Format

// Output the number of nodes in each component in ascending order.
// Sample Input 0

// 9 7
// 0 1
// 1 2
// 0 2
// 2 3
// 4 5
// 5 7
// 8 9
// Sample Output 0

// 2 3 4 
// Explanation 0

// The components are shown for the sample test case:
// image

// Sample Input 1

// 5 3
// 999 1000
// 100 500
// 500 600
// Sample Output 1

// 2 3







#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> adjList[N];
bool visited[N];

int dfs(int node) {
    visited[node] = true;
    int size = 1;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            size += dfs(neighbor);
        }
    }

    return size;
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    vector<int> componentSizes;

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            int size = dfs(i);
            if (size > 1) {
                componentSizes.push_back(size);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int size : componentSizes) {
        cout << size << " ";
    }

    return 0;
}
