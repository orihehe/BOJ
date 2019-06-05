/*
BOJ 11577 (https://www.acmicpc.net/problem/11577)

q에 전구를 켰을 때 그 범위를 넣는다.
q의 사이즈가 현재 위치에서 전구가 켜진 횟수이다.
*/
#include <cstdio>
#include <queue>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
int arr[100001];
queue<pii> q;
int main() {
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i <= n - k; i++) {
		if (!q.empty() && q.front().second < i) {
			q.pop();
		}
		if ((arr[i] + q.size()) % 2 == 1) {
			cnt++;
			q.push({ i,i + k - 1 });
		}
	}
	for (int i = n - k; i < n; i++) {
		if (!q.empty() && q.front().second < i) {
			q.pop();
		}
		if ((arr[i] + q.size()) % 2 == 1) {
			return !printf("Insomnia");
		}
	}
	printf("%d", cnt);

	return 0;
}