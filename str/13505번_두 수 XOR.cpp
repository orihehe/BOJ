/*
BOJ 13505 - 두 수 XOR
https://www.acmicpc.net/problem/13505

수를 2진수로 나타내고, 왼쪽에서부터 최대한 내가 가지지 못한 비트를 가진 원소를 고른다.
trie를 통해 빠르게 해준다.
*/
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

/* 🐣🐥 */
map<int, int> mp[3000001];
map<int, int> sz[3000001];
int arr[100000];
int bnr[32], bp;
int main() {
	int n, cnt = 0, pre, pp, mu, ans = 0, ori, tmp;
	bool s0 = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	if (arr[0] == 0) s0 = true;
	for (int i = 0; i < n; i++) {
		bp = 1;
		ori = arr[i];
		while (arr[i] > 0) {
			bnr[bp++] = arr[i] % 2;
			arr[i] /= 2;
		}
		pre = mu = 0;
		tmp = -1;
		pp = bp - 2;

		while (pp >= 1 && (bnr[pp] != 0 || sz[1][pp] == 0)) pp--;
		if (pp >= 1) tmp = 0;
		for (int j = pp; j >= 1; j--) {
			if (mp[pre].find(1) != mp[pre].end() && mp[pre].find(0) != mp[pre].end() && sz[mp[pre][1]][j] != 0 && sz[mp[pre][0]][j] != 0) {
				if (bnr[j] == 0 && sz[mp[pre][1]][j] != 0) {
					pre = mp[pre][1];
					tmp += 1 << (j - 1);
				}
				else {
					pre = mp[pre][0];
				}
			}
			else if (mp[pre].find(1) != mp[pre].end() && sz[mp[pre][1]][j] != 0) {
				pre = mp[pre][1];
				tmp += 1 << (j - 1);
			}
			else {
				pre = mp[pre][0];
			}
		}
		if (tmp != -1)
			ans = max(ans, ori^tmp);
		if (s0) ans = max(ans, ori);
		pre = 0;
		for (int j = bp - 1; j >= 1; j--) {
			if (mp[pre].find(bnr[j]) == mp[pre].end()) {
				mp[pre][bnr[j]] = ++cnt;
			}
			pre = mp[pre][bnr[j]];
			sz[pre][j]++;
		}
	}
	printf("%d", ans);


	return 0;
}