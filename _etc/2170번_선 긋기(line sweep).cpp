// BOJ 2170 (https://www.acmicpc.net/problem/2170)
#include <cstdio>
#include <algorithm>
#define ll long long
#define P pair<int,int>
using namespace std;

P arr[1000000];
int main() {
	int n, l, r;
	ll sum = 0;
	l = r = -1000000001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (r >= arr[i].first) {
			if (r < arr[i].second)
				r = arr[i].second;
		}
		else {
			sum += r - l;
			l = arr[i].first;
			r = arr[i].second;
		}
	}
	sum += r - l;
	printf("%lld", sum);

	return 0;
}