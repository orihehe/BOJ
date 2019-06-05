/*
BOJ 1421 (https://www.acmicpc.net/problem/1421)
완전탐색으로 어느 길이 i로 자를 때 최대가 나오는지 찾았다.
주의할 점은 이 나무를 i길이로 잘랐을 때 이익이 아니라면 이 나무를 i경우에 두지 않아야 한다.
또한 한번 자를 때 i길이 두 개가 나오는 경우(나무%i==0)도 고려해야한다.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
	int n;
	ll maxM = 0, cut, nc, c, w, tree[1000], tmp;
	scanf("%d %lld %lld", &n, &c, &w);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &tree[i]);
	}
	for (ll i = 1; i <= 10000; i++) {
		cut = 0; nc = 0; tmp = 0;
		for (int j = 0; j < n; j++) {
			if (tree[j] % i == 0) nc = 1;
			else nc = 0;
			cut = tree[j] / i;
			if (cut*i*w > c * (cut - nc)) {
				tmp += cut * i*w - c * (cut - nc);
			}
		}
		maxM = max(maxM, tmp);
	}
	printf("%lld", maxM);

	return 0;
}