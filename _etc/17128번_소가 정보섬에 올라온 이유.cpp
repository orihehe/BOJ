/*
BOJ 17128 - 소가 정보섬에 올라온 이유
https://www.acmicpc.net/problem/17128

현재 위치로부터 4칸까지 곱해둔 뒤 합을 구해두고
쿼리별로 변화하는 값을 구해 합에 더해준다.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

/* 🐣🐥 */
int dd[200001];
int main() {
	int n, q, sum = 0, x;
	scanf("%d %d", &n, &q);
	fill(dd, dd + n, 1);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		for (int j = 0; j < 4; j++) {
			dd[(i + j) % n] *= x;
		}
	}
	for (int i = 0; i < n; i++) {
		sum += dd[i];
	}
	while (q--) {
		scanf("%d", &x);
		int tmp = 0;
		for (int i = 0; i < 4; i++) {
			tmp += 2 * -dd[(x - 1 + i) % n];
			dd[(x - 1 + i) % n] = -dd[(x - 1 + i) % n];
		}
		sum += tmp;
		printf("%d\n", sum);
	}

	return 0;
}