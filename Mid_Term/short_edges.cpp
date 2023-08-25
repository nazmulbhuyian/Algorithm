// Problem Statement

// You will be given E, the number of edges. For each you will be given A and B which means there is an edge between A and B.

// You need to sort all edges in such a way that the edges are sorted in ascending order for A. If multiple edges have same A, then you will sort them according to B in ascending order.

// Input Format

// First line will contain E.
// Next E lines will contain A and B.
// Constraints

// 1 <= E <= 10^5
// 0 <= A, B <= 10^9
// Output Format

// Output all the edges in sorted order.
// Sample Input 0

// 6
// 3 4
// 3 2
// 3 5
// 1 2
// 1 4
// 1 5
// Sample Output 0

// 1 2
// 1 4
// 1 5
// 3 2
// 3 4
// 3 5


#include <bits/stdc++.h>
using namespace std;

int main() {
    int e;
    cin >> e;

    vector<pair<int, int>> edges;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    sort(edges.begin(), edges.end());

    for (auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
