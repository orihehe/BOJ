/*
BOJ 1893 - 시저 암호
https://www.acmicpc.net/problem/1893
*/
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
char A[63], W[50001], S[500001];
vector<int> ans;
int fail[50001], ii[128];
int main() {
	int tt, a, w, s;
	scanf("%d", &tt);
	while (tt--) {
		ans.clear();
		scanf("%s %s %s", A, W, S);
		a = strlen(A);
		w = strlen(W);
		s = strlen(S);
		for (int i = 0; i < a; i++) ii[A[i]] = i;

		for (int k = 0; k < a; k++) {
			int cnt = 0;
			memset(fail, 0, sizeof(fail));
			for (int i = 1, j = 0; i < w; i++) {
				while (j > 0 && W[i] != W[j]) j = fail[j - 1];
				if (W[i] == W[j]) fail[i] = ++j;
			}
			for (int i = 0, j = 0; i < s; i++) {
				while (j > 0 && S[i] != W[j]) j = fail[j - 1];
				if (S[i] == W[j]) {
					if (j == w - 1) {
						j = fail[j];
						cnt++;
						if (cnt > 1) break;
					}
					else j++;
				}
			}
			if (cnt == 1) ans.push_back(k);

			for (int i = 0; i < w; i++) {
				W[i] = A[(ii[W[i]] + 1) % a];
			}
		}
		if (ans.size() == 0) printf("no solution");
		else if (ans.size() == 1) printf("unique: ");
		else printf("ambiguous: ");
		for (int v : ans) printf("%d ", v);
		printf("\n");
	}

	return 0;
}