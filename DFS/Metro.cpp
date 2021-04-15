#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+5;

vector<int> gr[MAX];
vector<int> order;
int used[MAX], pos[MAX];
int n, m, ans;

void dfs(int u) {
	used[u] = true;
	order.push_back(u);
	pos[u] = order.size();
	for (int to : gr[u]) {
		if (!used[to]) {
			dfs(to);
		} else {
			ans = max(ans, (int)order.size()-pos[to]);
		}
	}
	order.pop_back();
	pos[u] = -1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b, --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	memset(pos, -1, sizeof(pos));
	dfs(0);
	cout << ans << '\n';
}