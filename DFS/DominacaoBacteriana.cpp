#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;
const int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[9] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};

int tc, n, cor[2];
int gr[MAX][MAX], used[MAX][MAX];

void dfs(int x, int y, int cl) {
	used[x][y] = true;
	++cor[cl];
	for (int k = 0; k < 9; ++k) {
		int nx = x + dx[k], ny = y + dy[k];
		if (0 <= nx and nx < n and 0 <= ny and ny < n and !used[nx][ny] and gr[nx][ny] == cl) {
			dfs(nx, ny, cl);
		}
	}
}

void dfs2(int x, int y, int cl) {
	used[x][y] = true;
	++cor[cl];
	for (auto [nx, ny] : vector<pair<int, int>>({{x-1, y}, {x+1, y}, {x, y-1}, {x, y+1}})) {
		if (0 <= nx and nx < n and 0 <= ny and ny < n and !used[nx][ny] and gr[nx][ny] == cl) {
			dfs2(nx, ny, cl);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n;
		cor[0] = cor[1] = 0;
		int a = -1, b = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> gr[i][j];
				used[i][j] = false;
				if (gr[i][j]) {
					a = i; b = j;
				}
			}
		}
		dfs(a, b, 1);
		for (int i = 0; i < n; ++i) {
			if (!used[0][i]) {
				dfs2(0, i, 0);
			}
			if (!used[n-1][i]) {
				dfs2(n-1, i, 0);
			}
			if (!used[i][0]) {
				dfs2(i, 0, 0);
			}
			if (!used[i][n-1]) {
				dfs2(i, n-1, 0);
			}
		}
		double ans = (cor[1] + (n*n-cor[1]-cor[0]))/2.0;
		cout << fixed << setprecision(2);
		cout << ans << '\n';
	}
}