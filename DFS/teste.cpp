#include <bits/stdc++.h>
using namespace std;

typedef std::pair<int, int> ii;
template<bool dir=false>
struct EulerianPath {
	std::vector<std::vector<ii>> gr;
	std::vector<int> ans, ng;
	std::vector<bool> used;
	int N, m;
	EulerianPath(int n) : N(n) {
		m = 0;
		gr.assign(N, std::vector<ii>());
	}
	inline void addEdge(int a, int b) {
		int eg = m++;
		gr[a].push_back({b, eg});
		if (!dir) gr[b].push_back({a, eg});
	}
	void dfs(int u) {
		while (ng[u] < (int)gr[u].size()) {
			auto [to, id] = gr[u][ng[u]++];
			if (!used[id]) {
				used[id] = true;
				dfs(to);
			}
		}
		ans.push_back(u);
	}
	std::vector<int> getPath(int s) {
		for (int i = 0; i < N; ++i) {
			cout << i << ": ";
			for (auto [x, y] : gr[i]) {
				cout << x << ' ';
			} cout << '\n';
		}
		
		ng.assign(N, 0);
		used.assign(m, false);
		ans.clear();
		dfs(s);
		std::reverse(ans.begin(), ans.end());
		return ans;
	}
};

int n, m;

int main() {
	cin >> n >> m;
	EulerianPath<true> E(n);
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		E.addEdge(a, b);
	}
	for (int v : E.getPath(0)) {
		cout << v << ' ';
	} cout << '\n';
}
//0 1 3 7 3 8 4 9 5 11 3 1 4 10 6 13 5 12 4 2 6 14 6 2 5 1 

