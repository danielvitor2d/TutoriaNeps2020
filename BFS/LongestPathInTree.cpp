#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int, int> ii;
const int MAX = 1e4+4;
const int INF = 1e9;

int n;
vector<int> gr[MAX];

ii bfs(int s) {
	ii res(0, s); //Distance, Node
	vector<int> dist(n, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		res = max(res, ii(dist[u], u));
		for (int to : gr[u]) if (dist[to] == INF) {
			dist[to] = dist[u] + 1;
			q.push(to);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0, a, b; i < n-1; ++i) {
		cin >> a >> b, --a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	cout << bfs(bfs(0).se).fi << '\n';
}