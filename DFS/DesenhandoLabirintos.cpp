#include <bits/stdc++.h>
using namespace std;
const int MAX = 101;

int tc;
int n, m, s;
int used[MAX], timer;
vector<int> gr[MAX];

int dfs(int u) {
	used[u] = timer;
	int res = 0;
	for (int to : gr[u]) if (used[to] != timer) {
		++res;
		res += dfs(to);
		++res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> s;
		cin >> n >> m;
		for (int i = 0, a, b; i < m; ++i) {
			cin >> a >> b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		++timer;
		cout << dfs(s) << '\n';
		for (int i = 0; i < n; ++i) {
			gr[i].clear();
		}
	}
}