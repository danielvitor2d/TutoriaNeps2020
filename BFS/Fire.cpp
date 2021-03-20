#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAX = 1010;
const int dx[4] = {-1, +1, +0, +0};
const int dy[4] = {+0, +0, -1, +1};

int tc;
int n, m;
int a, b;
char gr[MAX][MAX];
int dist[MAX][MAX];

bool bfs(int x, int y) {
	if (gr[x][y] == '#' or gr[x][y] == '*') return false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dist[i][j] = INF;
		}
	}
	dist[x][y] = 0;
	queue<pair<int, int>> q;
	q.push({x, y});
	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();
		if (gr[i][j] == '*') {
			if (dist[a][b] == INF) return false;
			return dist[i][j] > dist[a][b];
		}
		for (int k = 0; k < 4; ++k) {
			int ni = i + dx[k], nj = j + dy[k];
			if (0 <= ni and ni < n and 0 <= nj and nj < m and dist[ni][nj]==INF and gr[ni][nj] != '#') {
				dist[ni][nj] = dist[i][j] + 1;
				q.push({ni, nj});
			}
		}
	}
	return (dist[a][b] != INF);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> m >> n;
		a = -1, b = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> gr[i][j];
				if (gr[i][j] == '@') {
					a = i; b = j;
				}
			}
		}
		bool ok = false;
		int ans = INF;
		for (int i = 0; i < n; ++i) {
			if (bfs(i, 0) or bfs(i, m-1)) {
				ok = true;
				ans = min(ans, dist[a][b]);
			}
		}
		for (int j = 0; j < m; ++j) {
			if (bfs(0, j) or bfs(n-1, j)) {
				ok = true;
				ans = min(ans, dist[a][b]);
			}
		}
		if (ok) cout << ans+1 << '\n';
		else cout << "IMPOSSIBLE\n";
	}
}