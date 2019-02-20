/*
BOJ 11977 (https://www.acmicpc.net/problem/11977)

모든 i지점에 대해 터뜨려보고 가장 많이 터뜨릴 수 있는 개수를 출력한다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int arr[101];
int n, dist, l, r, cnt, mV;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		dist = 1, l = i - 1, r = i + 1;
		cnt = 0;
		while (l >= 0) {
			int cur = l + 1;
			bool suc = false;
			while (l >= 0 && arr[cur] - arr[l] <= dist) {
				l--;
				suc = true;
				cnt++;
			}
			if (suc) {
				dist++;
			}
			else break;
		}
		dist = 1;
		while (r < n) {
			int cur = r - 1;
			bool suc = false;
			while (r<n && arr[r] - arr[cur] <= dist) {
				r++;
				suc = true;
				cnt++;
			}
			if (suc) {
				dist++;
			}
			else break;
		}
		mV = max(mV, cnt);
	}
	printf("%d", mV + 1);

	return 0;
}