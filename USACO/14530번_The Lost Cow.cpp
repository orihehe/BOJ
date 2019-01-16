/*
BOJ 14530 (https://www.acmicpc.net/problem/14530)
i를 증가시켜주며 i%2가 0일땐 오른쪽 방향으로, 1일땐 왼쪽 방향으로
가는 도중 만나는 경우만 이전 위치에서 목적지를 빼주고, 나머지는 이전위치와 현재위치 차이를 더해준다.
*/
#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	ll x, y, t = 1, i = 0;
	ll dist = 0, last;
	scanf("%lld %lld", &x, &y);
	last = x;
	if (x == y) {
		printf("0");
		return 0;
	}
	while (true) {
		if (x<y && !(i % 2) && x + t >= y) {
			dist += y - last;
			break;
		}
		else if (x > y && (i % 2) && x - t <= y) {
			dist += last - y;
			break;
		}
		dist += llabs(last - (i % 2 ? x - t : x + t));
		last = (i % 2 ? x - t : x + t);
		t *= 2;
		i++;
	}

	printf("%lld", dist);

	return 0;
}