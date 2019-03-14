/*
BOJ 13978 - Cameras
https://www.acmicpc.net/problem/13978

슬라이딩 윈도우! r만큼의 카메라가 없다면 가장 오른쪽에 설치해준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool h[100001];
int main() {
	int n, k, r, x, cur = 0, ans = 0;
	scanf("%d %d %d", &n, &k, &r);
	for (int i = 0; i < k; i++) {
		scanf("%d", &x);
		h[x] = true;
	}
	for (int i = 1; i <= r; i++) {
		if (h[i]) cur++;
	}
	if (cur == 0) {
		h[r] = h[r - 1] = true;
		ans = 2;
		cur = 2;
	}
	else if (cur == 1) {
		if (h[r]) h[r - 1] = true;
		else h[r] = true;
		ans = 1;
		cur = 2;
	}
	for (int i = r + 1; i <= n; i++) {
		if (h[i - r]) cur--;
		if (h[i]) cur++;
		if (cur < 2) {
			h[i] = true;
			cur++;
			ans++;
		}

	}
	printf("%d", ans);

	return 0;
}