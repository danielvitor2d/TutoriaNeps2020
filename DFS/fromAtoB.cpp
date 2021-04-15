#include <bits/stdc++.h>
using namespace std;
const int64_t MAX_VALUE = 1000000000;

int64_t a, b;
map<int64_t, int> dist;

void print(int64_t u) {
	if (u == a) {
		cout << u << ' ';
		return;
	}
	if (u % 10 != 1) {
		print(u >> 1);
	} else if (u & 1) {
		print(u / 10);
	} else if (!dist.count(u / 10)) {
		print(u >> 1);
	} else if (!dist.count(u >> 1)) {
		print(u / 10);
	} else if (dist[u / 10] <= dist[u >> 1]) {
		print(u / 10);
	} else {
		print(u >> 1);
	}
	cout << u << ' ';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b;

	queue<int64_t> q;
	q.push(a);
	dist[a] = 1;

	while (!q.empty()) {
		int64_t u = q.front(); q.pop();
		if (u == b) break;
		if (2 * u <= MAX_VALUE and !dist.count(2 * u)) {
			dist[2 * u] = dist[u] + 1;
			q.push(2 * u);
		}
		if (10 * u + 1 <= MAX_VALUE and !dist.count(10 * u + 1)) {
			dist[10 * u + 1] = dist[u] + 1;
			q.push(10 * u + 1);
		}
	}
	if (dist.count(b)) {
		cout << "YES\n";
		cout << dist[b] << '\n';
		print(b);
		cout << '\n';
	} else {
		cout << "NO\n";
	}
}