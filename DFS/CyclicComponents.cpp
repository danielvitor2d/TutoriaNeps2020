#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define fi first
#define se second
const int MAX = 2e5+5;

int n, m;
int used[MAX], in[MAX], out[MAX];
vector<int> gr[MAX];

bool ok;
void dfs(int u) {
	used[u] = true;
	ok &= (in[u] == 2 and out[u] == 2);
	for (int to : gr[u]) if (!used[to]) {
		dfs(to);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b, --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
		++in[a]; ++in[b];
		++out[a]; ++out[b];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			ok = true;
			dfs(i);
			ans += ok;
		}
	}
	cout << ans << '\n';
}