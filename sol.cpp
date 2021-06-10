#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int least_dist = 0;
		int greatest_dist = 0;
		// find the position of the least and greatest power
		for (int i = 0; i < n; i++) {
			if (a[i] == 1) {
				least_dist = i + 1;
			} else if (a[i] == n) {
				greatest_dist = i + 1;
			}
		}
		// find the minimum number of operations to get the least power by
		// comparing its distance from the origin (0) and distance from the end (n) 
		// (add 1 to both since the positions are 1-based meaning if they are in place
		// then one more operation is required to fully remove them from the list)
		int min_least = min(least_dist, (n + 1) - least_dist);
		// find the minimum number of operations to get the greatest power by
		// comparing its distance from the origin (0) and distance from the end (n)
		int min_greatest = min(greatest_dist, (n + 1) - greatest_dist);
		// calculate the distance between the least and greatest power
		int dist_between = abs(least_dist - greatest_dist);
		// there will be three distances to check:
		// 1. if the least and greatest power are adjacent and they are near the origin (0)
		// 2. if the least and greatest power are adjacent and they are near the end (n)
		// 3. if the least and greatest power are totally apart
		cout << min({dist_between + min_least, dist_between + min_greatest, min_least + min_greatest}) << '\n';
	}
	return 0;
}
