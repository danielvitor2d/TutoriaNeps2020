#include <bits/stdc++.h>
using namespace std;
const int MAX = 505;

int n, m, q;
int id[MAX], p[MAX], c[MAX];
int used[MAX], timer;
vector<int> gr[MAX];

int dfs(int u, int age) {
	used[u] = timer;
	int k = age;
	for (int to : gr[u]) if (used[to] != timer) {
		k = min(k, dfs(to, id[p[to]]));
	}
	return k;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	while (cin >> n >> m >> q) {
		for (int i = 1; i <= n; ++i) {
			cin >> id[i];
			p[i] = i;
			c[i] = i;
			gr[i].clear();
		}
		for (int i = 0, a, b; i < m; ++i) {
			cin >> a >> b;
			gr[b].push_back(a);
		}
		char op;
		int a, b;
		while (q--) {
			cin >> op;
			if (op == 'T') {
				cin >> a >> b;
				swap(p[c[a]], p[c[b]]);
				swap(c[a], c[b]);
			} else {
				cin >> a;
				++timer;
				int r = dfs(c[a], 150);
				if (r == 150) cout << "*\n";
				else cout << r << '\n';
			}
		}
	}
}