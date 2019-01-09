/*
BOJ 14452 (https://www.acmicpc.net/problem/14452)
k�� ���� ũ��
1~k ��° �Ұ� ���� ���뿡 ����, �ð��� ���� ���� �ڸ��� k+1��°���� ������� ����.
���� ũ�⸸ŭ �տ������� �ð��� pq�� �־��־� �ּڰ��� ���Ѵ�.
���� �ҵ��� �� �������� top���ִ� ���� �� + ���� ���� �ð��� t���� ũ�ٸ� �� ũ���� ���뿡�� �� �� ����.
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