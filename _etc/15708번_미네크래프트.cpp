/*
BOJ 15708 (https://www.acmicpc.net/problem/15708)

각 돌과 인덱스를 pq에 넣어주고, 뒤에서부터 봐준다.
i까지의 돌중에서 채취할 때 최대 수를 구해주는데, i까지 가는 시간 + 돌 캐는 시간으로 구한다.
pq에서 작은 시간이 드는 돌을 먼저 선택하고, max값 저장 후 i--를 해주므로
i돌을 선택했었다면 시간과 카운트를 빼준다.
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