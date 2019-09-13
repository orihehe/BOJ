/*
BOJ 17365 - 별다줄
https://www.acmicpc.net/problem/17365

트라이로 현재 접두사를 가진 문자열 개수를 구해주고, 경우의 수를 세준다.
*/
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;

/* 🐣🐥 */
int dp[200001];
char ori[200001], tmp[1000002];
int trie[1000301][26], sz[1000301][26];
int main() {
	int p = 0, c, ss, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", tmp);
		int len = strlen(tmp);
		c = 0;
		for (int j = 0; j < len; j++) {
			tmp[j] -= 'a';
			sz[c][tmp[j]]++;
			if (trie[c][tmp[j]])
				c = trie[c][tmp[j]];
			else {
				trie[c][tmp[j]] = ++p;
				c = p;
			}
		}
	}
	scanf("%s", ori);
	ss = strlen(ori);
	dp[0] = 1;
	for (int i = 0; i < ss; i++) {
		c = 0;
		for (int j = 0; j + j < ss && sz[c][ori[i + j] - 'a']; j++) {
			dp[i + j + 1] = (dp[i + j + 1] + 1LL * sz[c][ori[i + j] - 'a'] * dp[i]) % mod;
			c = trie[c][ori[i + j] - 'a'];
		}
	}

	printf("%d", dp[ss]);

	return 0;
}