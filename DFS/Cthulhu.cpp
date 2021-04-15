#include <bits/stdc++.h>
using namespace std;
const int MAX = 110;

int n, m;
bool used[MAX];
vector<int> gr[MAX];

int solve(int u, int par = -1) {
	int cnt = 0;
	used[u] = true;
	for (int to : gr[u]) if (to != par and !used[to]) {
		cnt += solve(to, u);
	}
	return cnt+1;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b, --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	if (solve(0) == n and n==m) cout << "FHTAGN!\n";
	else cout << "NO\n";
}