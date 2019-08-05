/*
BOJ 15133 - Consonant Fencity
https://www.acmicpc.net/problem/15133
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;

/* 🐣🐥 */
char st[1000001];
int len, mx, cn[677];
bool mo[128], up[128], ans[128];
void dfs(int cur) {
	if (cur == 'z' + 1) {
		int cnt = 0;
		for (int i = 'a'; i <= 'z'; i++) {
			if (mo[i]) continue;
			for (int j = i + 1; j <= 'z'; j++) {
				if (mo[j]) continue;
				if (up[i] ^ up[j])
					cnt += cn[(i - 'a') * 26 + j - 'a'];
			}
		}
		if (cnt > mx) {
			mx = cnt;
			memcpy(ans, up, sizeof(ans));
		}
		return;
	}
	if (!mo[cur]) {
		up[cur] = true;
		dfs(cur + 1);
	}
	up[cur] = false;
	dfs(cur + 1);
}
int main() {
	scanf("%s", st);
	len = strlen(st);

	mo['a'] = mo['e'] = mo['u'] = mo['o'] = true;
	mo['i'] = mo['w'] = mo['y'] = true;

	for (int i = 1; i < len; i++) {
		if (!mo[st[i]] & !mo[st[i - 1]]) {
			int a = st[i] - 'a', b = st[i - 1] - 'a';
			if (a > b) swap(a, b);
			cn[a * 26 + b]++;
		}
	}

	dfs('a');
	for (int i = 0; i < len; i++) {
		if (ans[st[i]]) printf("%c", st[i] - 'a' + 'A');
		else printf("%c", st[i]);
	}
	return 0;
}