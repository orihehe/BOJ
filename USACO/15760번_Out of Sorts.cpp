/*
BOJ 15760 (https://www.acmicpc.net/problem/15760)

정렬 후 원래 위치와 가장 많은 차이를 출력해준다.
*/ 
#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[100001];
int main() {
	int n, maxV = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		maxV = max(maxV, arr[i].second - i);
	}
	printf("%d", maxV + 1);

	return 0;
}