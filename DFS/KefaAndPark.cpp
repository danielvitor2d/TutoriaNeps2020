#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAX = 1e5+5;

int n, m;
int cat[MAX];
vector<int> gr[MAX];

int dfs(int u, int par, int cats) {
	int ans = 0, son = 0;
	for (int to : gr[u]) if (to != par) {
		if (cats + cat[to] <= m) {
			int res = dfs(to, u, (cat[to] ? cats + 1 : 0));
			ans += res;
		}
		++son;
	}
	if (!son) return 1;
	else return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> cat[i];
	}
	for (int i = 0, a, b; i < n-1; ++i) {
		cin >> a >> b, --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	int res = dfs(0, -1, cat[0]);
	cout << res << '\n';
}