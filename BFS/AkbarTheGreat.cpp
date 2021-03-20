#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+6;

int tc;
int n, r, m, a, b;
int safe[MAX], par[MAX];
vector<int> gr[MAX];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> tc;
	while (tc--) {
		cin >> n >> r >> m;
		for (int i = 0; i < n; ++i) {
			par[i] = -1;
			safe[i] = 0;
			gr[i].clear();
		}
		for (int i = 0; i < r; ++i) {
			cin >> a >> b, --a, --b;
			gr[a].push_back(b);
			gr[b].push_back(a);
		}
		vector<int64_t> sd(n, 0);
		while (!q.empty()) q.pop();
		bool ok = true;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b, --a;
			if (safe[a] != 0) {
				ok = false;
			}
			safe[a] = i+1;
			sd[a] = b;
			q.push(a);
		}
		while (!q.empty() and ok) {
			int u = q.front(); q.pop();
			for (int to : gr[u]) if (to != par[u] and sd[u] > 0) {
				if (safe[to] != 0 and safe[to] != safe[u]) {
					ok = false;
					break;
				} else if (safe[to] == 0) {
					safe[to] = safe[u];
					par[to] = u;
					sd[to] = sd[u] - 1;
					q.push(to);
				}
			}
		}
		for (int i = 0; i < n and ok; ++i) {
			ok &= (safe[i] != 0);
		}
		if (!ok) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}
}