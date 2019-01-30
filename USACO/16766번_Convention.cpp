/*
BOJ 16766 (https://www.acmicpc.net/problem/16766)

최대 차이 값을 mid로 두고 이분탐색을 돌린다.
그때 버스 최대인원 이하만큼, mid차이 이하만큼 태우고
버스 개수를 초과하지 않는 가장 큰 값을 찾아준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int cow[100001];
int main() {
	int n, m, c, ans, l, r, mid, cnt;
	scanf("%d %d %d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &cow[i]);
	}
	sort(cow, cow + n);
	l = 0; r = 1000000000;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = 0;
		for (int i = 0; i < n; ) {
			int ti = i;
			while (ti - i + 1 <= c && cow[ti] - cow[i] <= mid)
				ti++;
			i = ti;
			cnt++;
		}
		if (cnt > m) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	printf("%d", ans);

	return 0;
}