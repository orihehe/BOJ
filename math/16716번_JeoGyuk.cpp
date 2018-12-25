/*
백준 16716 (https://www.acmicpc.net/problem/16716)
한 총알로 반직선상에 있는 적들을 모두 맞출 수 있다.
적들의 위치에 대해 두 저격 장소에서 위치를 이었을 때의 기울기와 저격 장소 기준 사분면 위치를 저장했다.
기울기를 실수형으로 하지 않기 위해 최대공약수를 구해 나눠주었다.
또 저격 장소와 적의 위치의 x나 y가 같다면 기울기가 0이 되므로 따로 처리해줬다.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

// 최대공약수
int gcd(int a, int b) {
	bool minus;
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0)) {
		minus = false;
	}
	else { // 기울기가 음수일 경우
		minus = true;
	}
	a = abs(a); b = abs(b);
	if (b > a) swap(a, b);
	while (b > 0) {
		int tmp = a;
		a = b;
		b = tmp % b;
	}
	return minus ? -a : a;
}

// 저격 장소 기준 사분면 구하기
int find_loc(int x, int y) {
	if (x >= 0 && y >= 0) return 1;
	else if (x <= 0 && y>=0) return 2;
	else if (x <= 0 && y <= 0) return 3;
	else return 4;
}

struct info {
	// y/x는 기울기
	int x, y, loc;
};
bool operator == (info a, info b) {
	return a.x == b.x && a.y == b.y && a.loc == b.loc;
}
P enemy[20];
info A[2][20];
vector<info> vec[2];
int n, minB=20, chan;

void dfs(int cnt, int bul) {
	if (cnt == n) {
		if (bul < minB) {
			minB = bul;
			// 장소 바꾼 경우
			chan = vec[1].size() == 0 ? 0 : 1;
		}
		return;
	}
	for (int j = 0; j < 2; j++) {
		int i, sz = vec[j].size();
		info tmp = A[j][cnt];
		for (i = 0; i < sz; i++) {
			if (tmp == vec[j][i]) break;
		}

		if (i == sz) { // 같은 기울기, 같은 사분면 없는 경우
			vec[j].push_back(tmp);
			dfs(cnt + 1, bul + 1);
			vec[j].erase(vec[j].begin() + sz);
		}
		else {
			dfs(cnt + 1, bul);
		}
	}
}

int main() {
	int fx[2], fy[2];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &enemy[i].first, &enemy[i].second);
	}
	scanf("%d %d", &fx[0], &fy[0]);
	scanf("%d %d", &fx[1], &fy[1]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			int nx = enemy[i].first - fx[j],
				ny = enemy[i].second - fy[j];
			int tmp1 = gcd(nx, ny);
			// x축에 평행한 직선
			if (nx == 0) {
				A[j][i] = { 0,1, find_loc(nx,ny) };
			}
			// y축에 평행한 직선
			else if (ny == 0) {
				A[j][i] = { 1,0, find_loc(nx,ny) };
			}
			else A[j][i] = { nx / tmp1,ny / tmp1, find_loc(nx,ny) };
		}
	}
	dfs(0, 0);
	printf("%d %d", minB, chan);

	return 0;
}