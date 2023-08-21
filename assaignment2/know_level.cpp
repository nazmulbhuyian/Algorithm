// Problem Statement

// Zaman lives in a city of pizzas where every street has several pizza shops and everyone loves pizza there. Suppose there are N pizza shops in Zaman's area. All pizza shops have unique numbers written in the shop, the number of the first pizza shop in his city is from 0 to 10^5. There are E roads between pizza shops, and these pizza shops form a undirected connected graph where you can divide them in levels where the level starts from 0. Zaman lives in level L, now he wants to know which pizza shops are there in his level. Can you help him to get the desired pizza shops?

// Note: If there are no pizza shops at level L, then print -1.

// Input Format

// First line will contain two integers N and E, number of pizza shops and roads repectively.
// The next E lines will contain two integeres A and B, which means there is a road between A and B.
// The last line will contain L, the level where Zaman lives.
// Constraints

// 0 < N <= 10^5
// 1 <= E <= 10^5
// 0 <= A, B, L <= 10^5
// Output Format

// Output the numbers written on the pizza shops that are in level L in ascending order.
// Sample Input 0

// 3 2
// 0 1
// 0 2
// 1
// Sample Output 0

// 1 2 


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> pizzaShops[N];
vector<bool> visited(N, false);

void dfs(int n, int level) {

    if (level == 0) {
        cout << n << " ";
    }
    visited[n] = true;

    for (int neighbor : pizzaShops[n]) {
        if (!visited[neighbor]) {
            dfs(neighbor, level - 1);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        pizzaShops[a].push_back(b);
        pizzaShops[b].push_back(a);
    }

    int l;
    cin >> l;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    dfs(0, l);

    return 0;
}
