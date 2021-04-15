#include <bits/stdc++.h>
using namespace std;
const int MAX = 350;

map<string, int> to1;
map<int, string> to2;
vector<int> gr[MAX];
string a, b, r;
int used[MAX];
int n, m;

void dfs(int u) {
	used[u] = true;
	for (int to : gr[u]) if (!used[to]) {
		dfs(to);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int c = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a >> r >> b;
		int p1, p2;
		if (!to1.count(a)) {
			to1[a] = c++;
			to2[c] = a;
		}
		p1 = to1[a];
		if (!to1.count(b)) {
			to1[b] = c++;
			to2[c] = b;
		}
		p2 = to1[b];
		gr[p1].push_back(p2);
		gr[p2].push_back(p1);
	}
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			++answer;
			dfs(i);
		}
	}
	cout << answer << '\n';
}