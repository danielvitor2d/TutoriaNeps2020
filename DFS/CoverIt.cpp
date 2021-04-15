#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;

int tc;
int n, m, cor[2];
int color[MAX];
vector<int> order;
vector<int> gr[MAX];

void dfs(int u, bool ch) {
	color[u] = ch;
	++cor[ch];
	for (int to : gr[u]) {
		if (color[to] == -1) {
			dfs(to, ch^1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		cor[0] = 0;
		cor[1] = 0;
		for (int i = 1; i <= n; ++i) {
			color[i] = -1;
			gr[i].clear();
		}
		for (int i = 0, a, b; i < m; ++i) {
			cin >> a >> b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		dfs(1, 0);
		int r = (cor[0] < cor[1] ? 0 : 1);
		cout << cor[r] << '\n';
		for (int i = 1; i <= n; ++i) {
			if (color[i] == r) {
				cout << i << ' ';
			}
		} cout << '\n';
	}
}