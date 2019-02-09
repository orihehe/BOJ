/*
BOJ 3020 (https://www.acmicpc.net/problem/3020)

�����κ��� 1~x, ������ �κ��� h-x+1 ~ h ������ �����Ѵ�.
�� ������ pair�� �ְ� sort�� i�������� �����ϴ� ���鿡 ���� pq�� ������ ������ �־��ְ�,
���� �������� i�� ũ�� pq���� ���ش�. 
�׷��ԵǸ� pq�� ����� �� ������ �����ϴ� �������� ���� ������ �ȴ�.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
pii arr[200001];
int ap;
int main() {
	int n, h, x, minV=500001, cnt = 0;
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (i % 2) {
			arr[i] = { h - x + 1,h };
		}
		else {
			arr[i] = { 1,x };
		}
	}
	sort(arr, arr + n);
	for (int i = 1; i <= h; i++) {
		while (arr[ap].first == i) {
			pq.push(arr[ap++].second);
		}
		while (!pq.empty() && pq.top() < i) {
			pq.pop();
		}
		if (minV > pq.size()) {
			minV = pq.size();
			cnt = 1;
		}
		else if (minV == pq.size()) cnt++;
	}
	printf("%d %d",minV, cnt);

	return 0;
}