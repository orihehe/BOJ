/*
BOJ 3020 (https://www.acmicpc.net/problem/3020)

석순부분은 1~x, 종유석 부분은 h-x+1 ~ h 범위를 차지한다.
그 범위를 pair에 넣고 sort후 i범위부터 시작하는 값들에 대해 pq에 끝나는 지점을 넣어주고,
끝난 지점보다 i가 크면 pq에서 빼준다. 
그렇게되면 pq의 사이즈가 그 지점을 포함하는 종유석과 석순 개수가 된다.
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