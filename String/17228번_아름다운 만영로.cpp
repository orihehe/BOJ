/*
BOJ 17228 - 아름다운 만영로
https://www.acmicpc.net/problem/17228
*/
#include <cstdio>
#include <cstring>
#include <vector>
#define pci pair<char,int>
using namespace std;

/* 🐣🐥 */
vector<pci> vec[500001];
int fail[500001], len, ans;
char st[500001];
void dfs(int i, int j) {
	int use[26] = { 0, };
	int w[26] = { 0, };
	for (pci v : vec[i]) {
		use[v.first - 'a']++;
	}
	for (int i = 'a'; i <= 'z'; i++) {
		if (use[i - 'a']) {
			int tt = j;
			while (tt > 0 && st[tt] != i) tt = fail[tt - 1];
			if (i == st[tt]) {
				if (tt == len - 1) {
					ans += use[i - 'a'];
					w[i - 'a'] = fail[tt];
				}
				else w[i - 'a'] = tt + 1;
			}
		}
	}
	for (pci v : vec[i]) {
		dfs(v.second, w[v.first - 'a']);
	}
}
int main() {
	int n, a, b;
	char c;
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d %d %c", &a, &b, &c);
		vec[a].push_back({ c,b });
	}
	scanf("%s", st);
	len = strlen(st);
	for (int i = 1, j = 0; i < len; i++) {
		while (j > 0 && st[i] != st[j]) j = fail[j - 1];
		if (st[i] == st[j]) fail[i] = ++j;
	}
	dfs(1, 0);
	printf("%d", ans);

	return 0;
}