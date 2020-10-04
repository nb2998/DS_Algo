#include <iostream>
using namespace std;
const int MAXN = 1e3 + 7;
const long long MOD = 1e9 + 7;
int h, w, f[MAXN][MAXN];
char a[MAXN][MAXN];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> h >> w;
	for (int i = 1; i <= h; i++) cin >> (a[i] + 1);
	f[0][1] = 1;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			if (a[i][j] != '#')
				f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
	cout << f[h][w] << endl;
	return 0;
}