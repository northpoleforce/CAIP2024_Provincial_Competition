#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[1005][1005];

const int tx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int ty[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool check_cold_0(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	if (a[x][y] == 'c') return 1;
	return 0;
}
bool check_cold(int x, int y) {
	for (int i = 0; i < 8; ++i)
		if (check_cold_0(x+tx[i], y+ty[i])) return 1;
	return 0;
}

bool check_m(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	if (a[x][y] == 'm') return 1;
	return 0;
}
bool check_no(int x, int y) {
	for (int i = 0; i < 8; ++i)
		if (check_m(x+tx[i], y+ty[i])) return 0;
	return 1;
}

bool check_ok(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	if (a[x][y] != '.') return 0;
	if (check_cold(x, y)) return 0;
	return 1;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) cin >> a[i][j];
		
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) cout << a[i][j];
//		cout << "\n";
//	}
	
	bool all_warm = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'w') {
				if (check_no(i, j)) {
					for (int k = 0; k < 8; ++k) {
						if (check_ok(i+tx[k], j+ty[k])) {
							cout << i+tx[k] << " " << j+ty[k] << "\n";
							all_warm = 1;
						}
					}
				}
			}
	if (all_warm == 0) cout << "Too cold!";
//			if (a[i][j] == '.') {
//				if (check(i, j)) cout << i << " " << j << "\n";
//			}
	
	return 0;
}
