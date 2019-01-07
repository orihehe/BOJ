/*
BOJ 3967 (https://www.acmicpc.net/problem/3967)
vec배열에 비어있는 위치를 모두 넣어둔다.
모든 원들은 두 개의 줄에 영향을 미친다. 
그 두 줄의 채워진 합이 26을 넘지 않도록 하고 사용되지 않은 수를 넣어보면 된다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

int rgo[6] = { -1,0,1,1,0,-1 };
int cgo[6] = { 1,2,1,-1,-2,-1 };
int star[5][10];
bool stop, num[13];
vector<P> vec;
void dfs(int cur) {
	if (cur == vec.size()) {
		stop = true; return;
	}
	int cnt = 0, t[2], r = vec[cur].first, c = vec[cur].second;
	t[0] = t[1] = 0;
	for (int i = 0; i < 6; i++) {
		if (cnt == 2) break;
		int nr = r + rgo[i], nc = c + cgo[i];
		if (nr < 0 || nc < 0 || nr>=5 || nc>=9 || star[nr][nc]==-1) continue;
		while (nr >= 0 && nr < 5 && 
			nc >= 0 && nc < 9 && star[nr][nc] != -1) {
			t[cnt] += star[nr][nc];
			nr += rgo[i], nc += cgo[i];
		}
		nr = r + rgo[(i + 3) % 6];
		nc = c + cgo[(i + 3) % 6];
		while (nr >= 0 && nr < 5 &&
			nc >= 0 && nc < 9 && star[nr][nc] != -1) {
			t[cnt] += star[nr][nc];
			nr += rgo[(i+3)%6], nc += cgo[(i + 3) % 6];
		}
		cnt++;
	}
	int mm = max(t[0], t[1]);
	if (mm >= 26) return;
	for (int i = 1; i <= 12; i++) {
		if (i + mm > 26) break;
		if (!num[i]) {
			num[i] = true;
			star[r][c] = i;
			dfs(cur + 1);
			if (stop) return;
			num[i] = false;
		}
	}
	
	star[r][c] = 0;
}
int main() {
	char x;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%c", &x);
			if (x == '.') star[i][j] = -1;
			else if (x == 'x') {
				star[i][j] = 0;
				vec.push_back({ i,j });
			}
			else {
				star[i][j] = x - 'A' + 1;
				num[star[i][j]] = true;
			}
		}
		getchar();
	}
	dfs(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			if (star[i][j] == -1) printf(".");
			else printf("%c", star[i][j] + 'A' - 1);
		}
		printf("\n");
	}
	return 0;
}