/*
BOJ 15823 (https://www.acmicpc.net/problem/15823)

연속한 카드만으로 카드팩을 구성할수 있다.
따라서 현재 넣을 카드가 이미 넣어져있다면 그 카드가 없어질때까지 srt를 증가시켜준다.
몇 장의 카드를 넣을 수 있는지는 이분탐색으로 구해준다.
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
bool use[500001];
int arr[100000];
void init(int s, int e) { // 카드팩 다 구성 했을 때 초기화
	while (e >= s) {
		use[arr[e]] = false;
		e--;
	}
}
int main() {
	int n, m, l, r, mid, cnt, ccnt, srt, ans;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	l = 1, r = n;
	while (l <= r) {
		mid = (l + r) / 2;
		cnt = ccnt = srt = 0;
		for (int i = 0; i < n; i++) {
			while (srt <= i && use[arr[i]]) {
				use[arr[srt++]] = false;
				ccnt--;
			}
			ccnt++; // 현재 카드팩 카드 개수
			use[arr[i]] = true;
			if (ccnt >= mid) {
				cnt++; // 카드팩 수
				init(srt, i);
				ccnt = 0;
				srt = i + 1;
			}
		}
		init(srt, n - 1);
		if (cnt >= m) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d", ans);

	return 0;
}