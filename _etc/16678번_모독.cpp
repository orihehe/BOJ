/*
백준 16678 모독 (https://www.acmicpc.net/problem/16678)
Defile을 한번만 수행해야 하므로 명예점수가 최대 1씩 차이가 나아햔다.
해커 수가 최소여야 하므로 소트 후 차이가 0or1인 증가하는 수열을 만들면 된다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	long long arr[100001], last = 0, sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] > last) {
			last++;
			sum += arr[i] - last;
		}
	}
	printf("%lld", sum);

	return 0;
}