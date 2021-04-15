#include <bits/stdc++.h>
using namespace std;
const int MAX = 505;
const int dx[4] = {-1, +1, +0, +0};
const int dy[4] = {+0, +0, -1, +1};

int n, m, k;
bool used[MAX][MAX];
char gr[MAX][MAX];

void dfs(int i, int j, int &r) {
	used[i][j] = true;
	for (int k = 0; k < 4; ++k) {
		int ni = i + dx[k], nj = j + dy[k];
		if (0 <= ni and ni < n and 0 <= nj and nj < m and !used[ni][nj] and gr[ni][nj] != '#') {
			dfs(ni, nj, r);
		}
	}
	if (r > 0) {
		--r;
		gr[i][j] = 'X';
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> k;

	int a = -1, b = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> gr[i][j];
			if (gr[i][j] == '.') {
				a = i; b = j;
			}
		}
	}

	dfs(a, b, k);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << gr[i][j];
		}
		cout << '\n';
	}
}