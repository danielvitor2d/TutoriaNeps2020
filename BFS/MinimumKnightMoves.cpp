#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int tc;
int s, t;

inline int getCell(const string &s) {
	return (s[1]-'1')*8+(s[0]-'a');
}

vector<int> getNeig(int u) {
	vector<int> res;
	int a = u%8, b = u/8;
	if (a >= 2 and b >= 1) res.push_back((a-2) + (b-1)*8);
	if (a >= 2 and b+1 < 8) res.push_back((a-2) + (b+1)*8);
	if (a+2 < 8 and b >= 1) res.push_back((a+2) + (b-1)*8);
	if (a+2 < 8 and b+1 < 8) res.push_back((a+2) + (b+1)*8);
	if (b >= 2 and a >= 1) res.push_back((a-1) + (b-2)*8);
	if (b >= 2 and a+1 < 8) res.push_back((a+1) + (b-2)*8);
	if (b+2 < 8 and a >= 1) res.push_back((a-1) + (b+2)*8);
	if (b+2 < 8 and a+1 < 8) res.push_back((a+1) + (b+2)*8);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> tc;
	while (tc--) {
		string a, b;
		cin >> a >> b;
		s = getCell(a);
		t = getCell(b);
		queue<int> q;
		vector<int> dist(64, INF);
		dist[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			for (int to : getNeig(u)) {
				if (dist[to] == INF) {
					dist[to] = dist[u] + 1;
					q.push(to);
				}
			}
		}
		cout << dist[t] << '\n';
	}
}