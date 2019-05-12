/*
BOJ 14529 - Where's Bessie?
https://www.acmicpc.net/problem/14529

가능한 좌표를 모두 넣어서 조건에 맞게 잘 탐색해주자.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
struct info {
	int r1, c1, r2, c2;
	info(int a, int b, int c, int d) {
		r1 = a, c1 = b, r2 = c, c2 = d;
	}
	bool operator<(const info &a) const {
		if ((r2 - r1 + 1)*(c2 - c1 + 1) == (a.r2 - a.r1 + 1)*(a.c2 - a.c1 + 1)) {
			if (r1 == a.r1 && c1 == a.c1 && r2 == a.r2) return c2 < a.c2;
			if (r1 == a.r1 && c1 == a.c1) return r2 < a.r2;
			if (r1 == a.r1) return c1 < a.c1;
			return r1 < a.r1;
		}
		return (r2 - r1 + 1)*(c2 - c1 + 1) > (a.r2 - a.r1 + 1)*(a.c2 - a.c1 + 1);
	}
};
vector<info> vec;
bool use[160001];
char arr[21][21], v1, v2;
int rgo[4] = { 0,1,0,-1 }, cgo[4] = { 1,0,-1,0 };
int n, ans, lr,lc,rr,rc, num[26];
bool visited[20][20];
void dfs(int r, int c, char aa) {
	visited[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < lr || nc < lc || nr > rr || nc > rc || visited[nr][nc]) continue;
		if (arr[nr][nc] == aa) dfs(nr, nc, aa);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			for (int r = i; r < n; r++) 
				for (int c = j; c < n; c++) 
					vec.push_back({ i,j,r,c });
	sort(vec.begin(), vec.end());
	int sz = vec.size();
	for (int z = 0; z < sz; z++) {
		info v = vec[z];
		if (use[z]) continue;
		v1 = v2 = ' ';
		bool suc = true;
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		memset(num, 0, sizeof(num));
		lr = v.r1, lc = v.c1, rr = v.r2, rc = v.c2;
		for (int r = v.r1; r <= v.r2; r++) {
			for (int c = v.c1; c <= v.c2; c++) {
				if (!visited[r][c]) {
					dfs(r, c, arr[r][c]);
					num[arr[r][c] - 'A']++;
				}
				if (arr[r][c] == v1 || arr[r][c] == v2) continue;
				if (v1 == ' ') v1 = arr[r][c];
				else if (v2 == ' ')v2 = arr[r][c];
				else suc = false;
			}
		}
		if (!suc || v2==' ' || num[v1 - 'A']+ num[v2 - 'A'] <=2 || (num[v1 - 'A']>=2 && num[v2-'A']>=2)) {
			use[z] = true;
		}
		else {
			for (int i = v.r1; i <= v.r2; i++) {
				for (int j = v.c1; j <= v.c2; j++) {
					for (int r = i; r <= v.r2; r++) {
						for (int c = j; c <= v.c2; c++) {
							if (i == v.r1 && j == v.c1 && r == v.r2 && c == v.c2) continue;
							int idx = lower_bound(vec.begin(), vec.end(), info(i, j, r, c)) - vec.begin();
							use[idx] = true;
						}
					}
				}
			}
			
		}
	}
	for (int i = 0; i < sz; i++) {
		if (!use[i]) {
			ans++;
		}
	}

	printf("%d", ans);

	return 0;
}