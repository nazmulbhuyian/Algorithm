// Problem Statement

// You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

// You can move in only 4 directions (Up, Down, Left and Right).

// The area of a component is the number of dots(.) in that component that can be accessible. You need to tell the minimum area of all available components.

// Note: If there are no components, print -1.

// Input Format

// First line will contain N and M.
// Next you will be given the 2D matrix.
// Constraints

// 1 <= N, M <= 1000
// Output Format

// Output the minimum area.
// Sample Input 0

// 6 5
// ..-..
// ..-..
// -----
// .-...
// .----
// .....
// Sample Output 0

// 3
// Sample Input 1

// 3 3
// ---
// ---
// ---
// Sample Output 1

// -1




#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N = 1005;
char grid[N][N];
bool vis[N][N];
int n, m;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '.');
}

int dfs(int r, int c) {
    if (!isValid(r, c) || vis[r][c]) {
        return 0;
    }

    vis[r][c] = true;

    int componentSize = 1;

    for (int i = 0; i < 4; i++) {
        pi p = path[i];
        int nr = r + p.first;
        int nc = c + p.second;
        componentSize += dfs(nr, nc);
    }

    return componentSize;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int minArea = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                int componentSize = dfs(i, j);
                minArea = min(minArea, componentSize);
            }
        }
    }

    if (minArea == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minArea << endl;
    }

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int dis[N];
// bool vis[N];
// vector<int> v[N];
// vector<int> cmp;
// void dfs(int s)
// {
//     vis[s] = true;
//     cmp.push_back(s);
//     for (int child : v[s])
//     {
//         if (!vis[child])
//         {
//             dfs(child);
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         v[a].push_back(b);
//         v[b].push_back(a);
//     }
//     int cnt = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             cnt++;
//             dfs(i);
//             for (int val : cmp)
//             {
//                 cout << val << " ";
//             }
//             cout << endl;
//             cmp.clear();
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }