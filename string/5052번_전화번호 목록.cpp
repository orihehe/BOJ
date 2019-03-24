/*
BOJ 5052 - 전화번호 목록
https://www.acmicpc.net/problem/5052

트라이로 풀었다. 
마지막 문자일때 이미 값이 있으면 false, 현재가 다른 문자열의 마지막 문자라면 false
*/
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

/* 🐣🐥 */
map<char, int> mp[100001];
bool lf[100001];
int main() {
	int t, n, cnt, len, pre;
	char tel[11];
	scanf("%d", &t);
	while (t--) {
		cnt = 0;
		bool ans = true;
		memset(lf, false, sizeof(lf));
		scanf("%d", &n);
		while (n--) {
			scanf("%s", tel);
			len = strlen(tel);
			pre = 0;
			for (int i = 0; i < len; i++) {
				if (mp[pre].find(tel[i]) == mp[pre].end()) {
					mp[pre][tel[i]] = ++cnt;
				}
				else if (i == len - 1) ans = false;
				pre = mp[pre][tel[i]];
				if (lf[pre]) ans = false;
			}
			lf[pre] = true;
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
		for (int i = 0; i <= cnt; i++) {
			mp[i].clear();
		}
	}

	return 0;
}