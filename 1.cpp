#include <bits/stdc++.h>

using namespace std;

int main()  {
	int n, w, a;
	cin >> n >> w;
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		if (a >= 35) {
			if (w == 4) ans2++;
			else ans1++;
		}
		w++;
		if (w > 7) w = 1;
	}
	cout << ans1 << " " << ans2;
	
	return 0;
}
