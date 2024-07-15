#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int N, M;
vector <int> to[maxn];

void add_e(int x, int y) {
	to[x].push_back(y);
}

bool huan[maxn];

bool color[maxn];
bool dfs_huan(int x) {
	int v;
	color[x] = 1;
	for (int i = 0; i < to[x].size(); ++i) {
		v = to[x][i];
		if (!huan[v]) continue;
		if (color[v]) return 1;
	}
	return 0;
}

bool check_status() {
	memset(color, 0, sizeof(color));
	bool is_huan = 0;
	for (int i = 1; i <= N; ++i)
		if (huan[i]) {
			is_huan = dfs_huan(i);
			break;
		}
	return is_huan;
}

int huan_cnt = 0;
int huan_nodes;

void dfs(int rt, int x) {
	if (check_status()) {
		huan_cnt++;
		int tot = 0;
		for (int i = 1; i <= N; ++i) tot += huan[i];
		huan_nodes = min(huan_nodes, tot);
	}
	if (rt > N) {
		return;
	}
	for (int i = x; i <= N; ++i) {
		huan[i] = 1;
		dfs(rt+1, i+1);
		huan[i] = 0;
	}
}

int main() {
	int T; cin >> T;
	
	int u, v;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= M; ++i) {
			cin >> u >> v;
			add_e(u, v);
			add_e(v, u);
		}
		if (N <= 2) {
			cout << "No 0\n";
		} else {
			huan_nodes = N;
			dfs(1, 1);
			if (huan_cnt == 1)
				cout << "Yes " << huan_nodes << "\n";
			else
				cout << "No " << huan_cnt << "\n";
		}
	}
	
	return 0;
}
