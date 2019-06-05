/*
���� 16716 (https://www.acmicpc.net/problem/16716)
�� �Ѿ˷� �������� �ִ� ������ ��� ���� �� �ִ�.
������ ��ġ�� ���� �� ���� ��ҿ��� ��ġ�� �̾��� ���� ����� ���� ��� ���� ��и� ��ġ�� �����ߴ�.
���⸦ �Ǽ������� ���� �ʱ� ���� �ִ������� ���� �����־���.
�� ���� ��ҿ� ���� ��ġ�� x�� y�� ���ٸ� ���Ⱑ 0�� �ǹǷ� ���� ó�������.
*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

// �ִ�����
int gcd(int a, int b) {
	bool minus;
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0)) {
		minus = false;
	}
	else { // ���Ⱑ ������ ���
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

// ���� ��� ���� ��и� ���ϱ�
int find_loc(int x, int y) {
	if (x >= 0 && y >= 0) return 1;
	else if (x <= 0 && y>=0) return 2;
	else if (x <= 0 && y <= 0) return 3;
	else return 4;
}

struct info {
	// y/x�� ����
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
			// ��� �ٲ� ���
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

		if (i == sz) { // ���� ����, ���� ��и� ���� ���
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
			// x�࿡ ������ ����
			if (nx == 0) {
				A[j][i] = { 0,1, find_loc(nx,ny) };
			}
			// y�࿡ ������ ����
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