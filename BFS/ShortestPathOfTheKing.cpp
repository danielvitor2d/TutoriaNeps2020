#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define fi first
#define se second
const int dx[9] = {-1, -1, -1, +0, +0, +0, +1, +1, +1};
const int dy[9] = {-1, +0, +1, -1, +0, +1, -1, +0, +1};

inline ii getNode(const string &s) {
	return {s[1]-'1', s[0]-'a'};
}

map<ii, int> dist;
map<ii, ii> par;
string a, b;
int gr[8][8];
ii u, v;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b;
  u = getNode(a);
  v = getNode(b);
  queue<pair<int, int>> q;
  dist[u] = 0;
  q.push(u);
  while (!q.empty()) {
  	ii cur = q.front(); q.pop();
  	for (int k = 0; k < 9; ++k) {
  		ii to(cur.fi + dx[k], cur.se + dy[k]);
  		if (0 <= to.fi and to.fi < 9 and 0 <= to.se and to.se < 9 and !dist.count(to)) {
  			dist[to] = dist[cur] + 1;
  			par[to] = cur;
  			q.push(to);
  		}
  	}
  }
  cout << dist[v] << '\n';
  vector<ii> restore;
  ii cur = v;
  while (cur != u) {
  	restore.push_back(cur);
  	cur = par[cur];
  }
  reverse(restore.begin(), restore.end());

  ii last = u;
  for (auto x : restore) {
  	// cout << x.fi << ' ' << x.se << '\n';
  	if (x.fi == last.fi) {
  		if (x.se == last.se) {
  			cout << "Fudeo\n";
  		} else if (x.se-1 == last.se) {
  			cout << "R\n";
  		} else {
  			cout << "L\n";
  		}
  	} else if (x.fi-1 == last.fi) {
  		if (x.se == last.se) {
  			cout << "U\n";
  		} else if (x.se-1 == last.se) {
  			cout << "RU\n";
  		} else {
  			cout << "LU\n";
  		}
  	} else  {
  		if (x.se == last.se) {
  			cout << "D\n";
  		} else if (x.se-1 == last.se) {
  			cout << "RD\n";
  		} else {
  			cout << "LD\n";
  		}
  	}
  	last = x;
  }
}