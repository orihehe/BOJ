/*
BOJ 15949 (https://www.acmicpc.net/problem/15949)
이미 방문한 색에 다시 방문할 수 있다는 점을 주의하자 ㅠㅠ
다음 블록을 선택하는 방법은 문제에서 지시하는 것을 잘 읽어본다. 흑

- 동쪽을 바라보는 경우
현재 블록의 동쪽 가장 끝의 코델들을 구하기 위해 색 탐색중 가장 큰 c값을 저장했다.
vec배열에 현재 블록의 모든 코델들을 저장
tmp배열에는 c값을 가지는 r들을 넣어준다. 그후 sort
cc가 왼쪽이라면 tmp[0]이 사용할 r값, 오른쪽이라면 tmp[tmp.size()-1]이 사용할 r값이 된다.
모든 방향에 대해 같은 방식으로 구해주면 된다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

char pic[102][102];
// 동 남 서 북
int rgo[4] = { 0,1,0,-1 };
int cgo[4] = { 1,0,-1,0 };
int n, m, d[4], cc = 3, dp; // cc 3은 왼쪽, 1은 오른쪽
vector<P> vec;
vector<int> tmp;
bool visited[101][101];
void dfs(int r, int c, char ch) {
	visited[r][c] = true;
	vec.push_back({ r,c });
	d[3] = min(d[3], r); d[1] = max(d[1], r);
	d[2] = min(d[2], c); d[0] = max(d[0], c);

	for (int i = 0; i < 4; i++) {
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
		if (!visited[nr][nc] && pic[nr][nc] == ch) {
			dfs(nr, nc, ch);
		}
	}
}
int main() {
	int cnt = 0, r = 0, c = 0, i;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", pic[i]);
	}
	while (true) {
		d[1] = d[3] = r, d[0] = d[2] = c;
		vec.clear();
		printf("%c", pic[r][c]);
		memset(visited, false, sizeof(visited));
		dfs(r, c, pic[r][c]);
		for (i = 0; i < 8; i++) {
			int nr = r, nc = c;
			tmp.clear();
			if (i % 2 == 1) cc = (cc + 2) % 4;
			if (i != 0 && i % 2 == 0) dp = (dp + 1) % 4;
			if (rgo[dp] == 0) {
				nc = d[dp];
				for (P &v : vec) {
					if (v.second == nc) tmp.push_back(v.first);
				}
				sort(tmp.begin(), tmp.end());
				if (rgo[(dp + cc) % 4] < 0) {
					nr = tmp[0];
				}
				else nr = tmp[tmp.size() - 1];
			}
			else {
				nr = d[dp];
				for (P &v : vec) {
					if (v.first == nr) tmp.push_back(v.second);
				}
				sort(tmp.begin(), tmp.end());
				if (cgo[(dp + cc) % 4] < 0) {
					nc = tmp[0];
				}
				else nc = tmp[tmp.size() - 1];
			}
			nr += rgo[dp], nc += cgo[dp];
			if (nr < n && nc < m && nr >= 0 && nc >= 0 && pic[nr][nc] != 'X') {
				r = nr, c = nc;
				break;
			}
		}
		if (i == 8)break;
	}

	return 0;
}