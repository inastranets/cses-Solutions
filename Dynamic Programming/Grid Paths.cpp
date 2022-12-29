#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	vector<vector<char> > path(n, vector<char>(n));

	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			cin >> path[i][j];
		}
	}

	int dp[n][n];
	memset(dp,0x0,sizeof(dp));

	dp[0][0] = 1;
	
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < n; ++ j) {
			if(path[i][j] != '*') {
				if(i > 0)
					dp[i][j] += dp[i-1][j];
				if(j > 0)
					dp[i][j] += dp[i][j-1];

				dp[i][j] %= (unsigned int)(1e9+7);

			} else {
				dp[i][j] = 0;
			}
		}
	}

	cout << dp[n - 1][n - 1];

	return 0;
}
