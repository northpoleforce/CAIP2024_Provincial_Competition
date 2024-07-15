#include <bits/stdc++.h>

using namespace std;

int calc(int x) {
	if (x == 1) return 12;
	if (x == 2) return 9;
	if (x == 3) return 7;
	if (x == 4) return 5;
	if (x == 5) return 4;
	if (x <= 7) return 3;
	if (x <= 10) return 2;
	if (x <= 15) return 1;
	return 0;
}

int s[25];

int main() {
	int n; cin >> n;
	int p, k;
	while (n--) {
		for (int i = 1; i <= 20; ++i) {
			cin >> p >> k;
			s[i] += calc(p)+k;
		}
	}
	for (int i = 1; i <= 20; ++i) {
		cout << i << " " << s[i];
		if (i <= 19) cout << "\n";
	}
	
	return 0;
}
