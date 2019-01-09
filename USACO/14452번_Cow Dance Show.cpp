/*
BOJ 14452 (https://www.acmicpc.net/problem/14452)
k는 무대 크기
1~k 번째 소가 먼저 무대에 서고, 시간이 끝난 소의 자리는 k+1번째부터 순서대로 들어간다.
무대 크기만큼 앞에서부터 시간을 pq에 넣어주어 최솟값을 구한다.
남은 소들을 다 보기전에 top에있는 작은 값 + 다음 소의 시간이 t보다 크다면 그 크기의 무대에는 설 수 없다.
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int arr[10001];
int main() {
	int n, t, l, r, mid, i, minK;
	scanf("%d %d", &n, &t);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	l = 1, r = n, minK = n;
	while (l <= r) {
		priority_queue<int, vector<int>, greater<int>> pq;
		mid = (l + r) / 2;
		for (i = 1; i <= mid; i++) {
			pq.push(arr[i]);
		}
		for (i = mid + 1; i <= n; i++) {
			if (pq.top() + arr[i] > t)break;
			pq.push(pq.top() + arr[i]);
			pq.pop();
		}
		if (i == n + 1) {
			r = mid - 1;
			minK = mid;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d", minK);

	return 0;
}