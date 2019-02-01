/*
BOJ 14527 (https://www.acmicpc.net/problem/14527)

두 수의 합들 중 최댓값이 최소가 되도록 해야함, 시간별로 정렬 후 앞뒤를 짝지어준다.
소들의 총 합이 10억이므로 한마리씩 빼주지 않고 뭉탱이로 빼준다.
*/
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

pii arr[100001];
int main() {
	int n, a, b, l, r, lt, rt, maxT = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		arr[i] = { b,a };
	}
	sort(arr, arr + n);
	l = 0, r = n - 1, lt = arr[l].second, rt = arr[r].second;
	while (l <= r) {
		maxT = max(maxT, arr[l].first + arr[r].first);
		if (arr[l].second > arr[r].second) {
			arr[l].second -= arr[r].second;
			r--;
		}
		else if (arr[l].second == arr[r].second) {
			l++, r--;
		}
		else {
			arr[r].second -= arr[l].second;
			l++;
		}
	}
	printf("%d", maxT);

	return 0;
}