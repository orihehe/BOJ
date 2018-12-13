/*
백준 16680 안수빈수 (https://www.acmicpc.net/problem/16680)
처음엔 그냥 안수빈수를 찾을 때까지 n을 더해줬다 - TLE
9로만 이루어진 9의 개수가 짝수인 수, 예를 들어 99999999는 100000000999999989가 최초의 안수빈수였다.
이런 경우만 좀 느린 것 같아 n에 100000011을 곱하고 시작했다. 결과는 240ms로 AC였지만
0ms인 분들 코드를 보니 n다음은 n*n을 더해주며 찾는 걸 봤다. 왜 이렇게 하면 되는지..모르겠다..ㅜ
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll sbin(ll x) {
	ll sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
int main() {
	int t;
	ll n, tmp;
	scanf("%d", &t);
	while (t--) {
		tmp = 0;
		scanf("%lld", &n);
		tmp = n * 100000011;
		while (true) {
			if (sbin(tmp) % 2 == 1) break;
			tmp += n;
		}
		printf("%lld\n", tmp);
	}

	return 0;
}