// Problem Statement

// Kamal lives in mazenda city. In his neighbourhood there are several houses too. Some of them are directly connected to Kamal's house, and some of them are indirectly connected. This time the roads are only one-way. If there are N houses and E roads in his area. Every house has a unique number from 0 to N-1. Can you tell how many houses Kamal can go directly or indirectly if Kamal's house if his house number is K?

// Note: You can go in the road only in one direction.

// Input Format

// First line will contain N and E, the number of houses and roads respectively.
// Next E lines will contain A and B, means there is a road between A house and B house. You can go only from A to B.
// Next line will contain K, the number of Kamal's house
// Constraints

// 0 < N <=20
// 0 <= E <= 190
// 0 <= A,B < N
// 0 <= K < N
// Output Format

// Output the number of houses that Kamal can go.
// Sample Input 0

// 6 5
// 0 1
// 0 2
// 0 3
// 2 3
// 4 5
// 2
// Sample Output 0

// 1
// Explanation 0

// image

// Kamal can go in only one house that is house no 3.
// Sample Input 1

// 6 5
// 0 1
// 0 2
// 2 3
// 3 0
// 4 5
// 2
// Sample Output 1

// 3
// Explanation 1

// image

// Kamal can go to 3 houses directly or indirectly. Those are house no 3, 0 and 1.



#include <bits/stdc++.h>
using namespace std;

int N, E;
vector<vector<int>> adjacencyList;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;

    for (int neighbor : adjacencyList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> N >> E;

    adjacencyList.resize(N);
    for (int i = 0; i < E; i++) {
        int a, b;
        cin >> a >> b;
        adjacencyList[a].push_back(b);
    }

    int K;
    cin >> K;

    visited.assign(N, false);
    dfs(K);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            count++;
        }
    }

    cout << count - 1 << endl;

    return 0;
}
