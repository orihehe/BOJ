/*
BOJ 11993 (https://www.acmicpc.net/problem/11993)

0인 지점을 채울 때 반시계 방향으로 가장 가까운 소를 데려오는 것이 적은 에너지가 든다.
이제 어떤 지점에서부터 소를 찾아야 할지 찾아야한다.
소들은 시계방향으로만 움직이니, 임의의 정점에서 시작하여 시계방향으로
남는 소가 있다면 데려가주면서, 빈 곳을 채워주는데 가장 마지막으로 채워지는 곳부터 시작해야한다.
만약 마지막으로 채워지는곳 외의 다른곳에서 시작한다면, 그 곳에서 가장 가까운 소를 데려왔을 때,
마지막에서 소를 데려오려 하면 저 멀리서 데려올 수밖에 없다.
*/
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;

/* 🐣🐥 */
int arr[100001];
bool one[100001];
int cnt, ap, sp;
ll ans;
bool suc;
queue<int> q;
int main() {
	int n, end;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	do { // 마지막 채워지는 지점 ap
		if (!one[ap] && arr[ap] > 1) {
			cnt += arr[ap] - 1;
			one[ap] = true;
		}
		else if (arr[ap] == 0 && !one[ap] && cnt > 0) {
			cnt--;
			one[ap] = true;
		}
		ap = (++ap) % n;
		if (ap == 0) suc = true;
	} while (!suc || cnt > 0);

	end = ap--;
	if (end >= n) end = 0;
	if (ap < 0) ap = n - 1;
	while (true) {
		cnt++;
		if (!arr[ap]) {
			q.push(cnt);
		}
		else {
			while (arr[ap] > 0 && !q.empty()) {
				int cur = q.front();
				q.pop();
				cur = cnt - cur;
				ans += (ll)cur*(ll)cur;
				arr[ap]--;
			}
			if (arr[ap] == 0) q.push(cnt);
		}
		if (ap == end) break;
		ap = (--ap + n) % n;
	}
	printf("%lld", ans);

	return 0;
}