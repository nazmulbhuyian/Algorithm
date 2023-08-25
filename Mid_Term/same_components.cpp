// Problem
// Submissions
// Leaderboard
// Discussions
// Problem Statement

// You will be given a 2D matrix of size NxM which will contain only dot(.) and minus(-) where dot(.) means you can go in that cell and minus(.) means you can't.

// You can move in only 4 directions (Up, Down, Left and Right).

// You will be given the indexes of to cells - S(si,sj) and D(di,dj). You need to tell if these cells are in the same component or not where you can go from S to D.

// Input Format

// First line will contain N and M.
// Next you will be given the 2D matrix.
// Next line will contain si and sj.
// Last line will contain di and dj.
// Constraints

// 1 <= N, M <= 1000
// 0 <= si, di < N
// 0 <= sj, dj < M
// Output Format

// Output "YES" if those cell are in the same component, "NO" otherwise.
// Sample Input 0

// 5 4
// ..-.
// ---.
// ..-.
// --..
// ....
// 0 1
// 3 2
// Sample Output 0

// NO
// Sample Input 1

// 5 4
// ....
// ---.
// ..-.
// --..
// ....
// 0 1
// 3 2
// Sample Output 1

// YES


#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int n, m;
const int N = 1005;
bool vis[N][N];
char a[N][N];
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.')
        return true;
    else
        return false;
}
bool dfs(int si, int sj,int di, int dj)
{
    if (si == di && sj == dj)
    {
        return true;
    }
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            if (dfs(ci, cj, di, dj))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    if (dfs(si, sj, di, dj)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}