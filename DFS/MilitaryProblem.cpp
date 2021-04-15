#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;

int n, q, u, k, st[MAX];
int tour[MAX], id[MAX], timer;
vector<int> gr[MAX];

void dfs(int u) {
	st[u] = 1;
	tour[timer] = u;
	id[u] = timer++;
	for (int to : gr[u]) {
		dfs(to); st[u] += st[to];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 2, p; i <= n; ++i) {
		cin >> p;
		gr[p].push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		sort(gr[i].begin(), gr[i].end());
	}
	dfs(1);
	while (q--) {
		cin >> u >> k, --k;
		if (id[u] + k > n-1 or k >= st[u]) {
			cout << "-1\n";
		} else {
			cout << tour[id[u] + k] << '\n';
		}
	}
}