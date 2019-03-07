/*
BOJ 11964 - Fruit Feast
https://www.acmicpc.net/problem/11964

go에서 h에 가능한 fullness를 모두 구해준다.
모두 채우고 그것을 arr에 가능한것만 놓은 뒤,
t-arr[i]/2를 upperbound로 찾으면 현재 arr[i]를 나눴을 때 최대 fullness를 찾을 수 있다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
bool h[5000001];
int t, a, b, ans;
void go(int ac, int bc) {
	if (a*ac + b * bc > t) return;
	if (h[a*ac + b * bc]) return;
	h[a*ac + b * bc] = true;
	go(ac + 1, bc);
	go(ac, bc + 1);
}
int arr[5000001], ap;
int main() {
	scanf("%d %d %d", &t, &a, &b);
	go(0, 0);
	for (int i = 0; i <= t; i++) {
		if (h[i]) arr[ap++] = i;
	}
	for (int i = 0; i < ap; i++) {
		int idx = upper_bound(arr, arr + ap, t - arr[i] / 2) - arr;
		if (idx != 0) {
			ans = max(ans, arr[i] / 2 + arr[idx - 1]);
		}
	}
	printf("%d", ans);

	return 0;
}