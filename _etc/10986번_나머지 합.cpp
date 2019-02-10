/*
BOJ 10986 (https://www.acmicpc.net/problem/10986)

ans배열에 0에서 시작하는 모든 구간을 m으로 나눈 나머지의 개수를 저장
그리고나서 0~n-1로 시작하는 각 구간에서 나머지가 0 인 구간의 개수를 카운트해준다
다음 i에서는 이전 나머지값을 제외하여 보면 된다
*/
#include <cstdio>
#define ll long long
using namespace std;

ll ans[1001];
ll arr[1000001];
int main() {
	ll n, m, cnt = 0 , mm = 0;
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		cnt += arr[i];
		ans[cnt%m]++;
	}
	cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += ans[mm%m];
		ans[(mm + arr[i]) % m]--;
		mm += arr[i];
	}
	printf("%lld", cnt);

	return 0;
}