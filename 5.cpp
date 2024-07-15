#include <bits/stdc++.h>

using namespace std;

const short maxn = 5e3+5;

//int N, t[maxn], d[maxn], p[maxn];
short N;

struct task {
	short t, d, p;
} ta[maxn];

bool cmp(const task &a, const task &b) {
	return a.d < b.d;
}

//short f[maxn][maxn];
int f[maxn];

//short max(short a, short b) {
//	if (a > b) return a;
//	return b;
//}

int main() {
	int T; cin >> T;
	
	while (T--) {
		cin >> N;
//		for (int i = 1; i <= N; ++i) cin >> t[i] >> d[i] >> p[i];
		short maxd = 0;
		for (int i = 1; i <= N; ++i) {
			cin >> ta[i].t >> ta[i].d >> ta[i].p;	
			maxd = max(maxd, ta[i].d);
		}
		sort(ta+1, ta+N+1, cmp);
		memset(f, 0, sizeof(f));
//		short ans = 0;
		int ans = 0;
		for (short i = 1; i <= N; ++i) {
			for (short j = ta[i].d-ta[i].t; j >= 0; --j)
				f[j+ta[i].t] = max(f[j+ta[i].t], f[j]+ta[i].p);
		}
		for (short i = 1; i <= maxd; ++i) 
			ans = max(ans, f[i]);
//		for (short i = 1; i <= maxd; ++i) {
//			for (short j = 1; j <= N; ++j) {
//				f[i][j] = max(f[i][j], f[i][j-1]);
//				f[i][j] = max(f[i][j], f[i-1][j]);
//				if (ta[j].d >= i && i-ta[j].t >= 0) {
//					f[i][j] = max(ta[j].p+f[i-ta[j].t][j-1], f[i][j]);
//				}
//				ans = max(ans, f[i][j]);
////				cout << i << " " << j << " ";
////				cout << "ta: " << ta[j].d << " " << ta[j].t << " " << ta[j].p << " ";
////				cout << "ans: " << ans << "\n";
//			}
//		}
//		cout << "===";
		cout << ans << "\n";
	}
	
	return 0;
}
