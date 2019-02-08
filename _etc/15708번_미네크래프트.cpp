/*
BOJ 15708 (https://www.acmicpc.net/problem/15708)

�� ���� �ε����� pq�� �־��ְ�, �ڿ������� ���ش�.
i������ ���߿��� ä���� �� �ִ� ���� �����ִµ�, i���� ���� �ð� + �� ĳ�� �ð����� ���Ѵ�.
pq���� ���� �ð��� ��� ���� ���� �����ϰ�, max�� ���� �� i--�� ���ֹǷ�
i���� �����߾��ٸ� �ð��� ī��Ʈ�� ���ش�.
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long
#define pii pair<int,int>
using namespace std;

priority_queue<pii, vector<pii>, greater<pii>> pq;
bool use[100001];
int arr[100001];
int main() {
	int n, cnt = 0, maxC = 0;
	ll now, t, p;
	scanf("%d %lld %lld", &n, &t, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		pq.push({arr[i],i});
	}
	now = p * (n - 1);
	for (int i = n - 1; i >= 0; i--) {
		while (!pq.empty()) {
			if (pq.top().second > i) pq.pop();
			else if((ll)pq.top().first+now <= t){
				now += pq.top().first;
				use[pq.top().second] = true;
				cnt++;
				pq.pop();
			}
			else break;
		}
		maxC = max(maxC, cnt);
		if (use[i]) {
			cnt--;
			now -= arr[i];
		}
		now -= p;
	}
	printf("%d", maxC);

	return 0;
}