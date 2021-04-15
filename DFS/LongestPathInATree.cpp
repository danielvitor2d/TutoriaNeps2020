#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int MAX = 1e4+4;

vector<int> gr[MAX];
int n;

ii dfs(int u, int par = -1, int d = 0) {
	ii res(d, u);
	for (int to : gr[u]) if (to != par) {
		res = max(res, dfs(to, u, d + 1));
	}
	return res;
}

int main() {
	cin >> n;
	for (int i = 0, a, b; i < n-1; ++i) {
		cin >> a >> b, --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	cout << dfs(dfs(0).second).first << '\n';
}