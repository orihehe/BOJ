/*
BOJ 8103 (https://www.acmicpc.net/problem/8103)

x, y�� ���� ������ �Է¹��� ������ xx����ü�� ����
i���� ��� ������ ���� ���ϴµ�, i�� x1�� ���� �� pq�� �־��ְ� pq�� �������� i�� �������� ������ pop���ش�.
pq�� �ִ� ���� x2���ε�, i~x2������ ���� ���� ���� i�� �־��ָ� ���� ���� i�� ��ġ���� �� �ֱ� �����̴�.
x��, y���� ���� ���� �� ������ ���ش�.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define P pair<int, int>
using namespace std;

struct xx {
	int x1, x2, idx;
	bool operator < (const xx & a) const {
		if (x1 == a.x1) return x2 < a.x2;
		return x1 < a.x1;
	}
};
int n;
xx arrX[3001], arrY[3001];
P ans[3001];
bool solve(xx *arr, int s) {
	priority_queue<P, vector<P>, greater<P>> pqX;
	int xp = 0;
	for (int i = 1; i <= n; i++) {
		while (xp < n && arr[xp].x1 == i) {
			pqX.push({ arr[xp].x2 , arr[xp].idx });
			xp++;
		}
		while (!pqX.empty() && pqX.top().first < i) pqX.pop();
		if (pqX.empty()) {
			return false;
		}
		else {
			if (s)
				ans[pqX.top().second].second = i;
			else ans[pqX.top().second].first = i;
			pqX.pop();
		}
	}
	return true;
}
int main() {
	bool suc = true;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &arrX[i].x1, &arrY[i].x1, &arrX[i].x2, &arrY[i].x2);
		arrX[i].idx = arrY[i].idx = i;
	}
	sort(arrX, arrX + n);
	if (!solve(arrX, 0)) printf("NIE");
	else {
		sort(arrY, arrY + n);
		if (!solve(arrY, 1)) printf("NIE");
		else {
			for (int i = 0; i < n; i++)
				printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}

	return 0;
}