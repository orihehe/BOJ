/*
BOJ 2629 (https://www.acmicpc.net/problem/2629)

나올 수 있는 추의 합, 차로 구슬의 무게를 잴 수 있다.
이전 추를 사용했을 때 나올 수 있는 무게에 현재 추를 더하거나 빼준다.
추를 더해줄 때는 이미 더한 큰 값이 배열에 저장되므로 적은 무게부터 보면 더한것에 또 더하게된다.
따라서 더할 때는 큰 값부터 내려오고, 뺄 때는 작은 값부터 올라간다.
빼는 경우 이미 더한 값이 들어있지만 더한 것을 빼면 제자리이므로 상관 없다.
*/
#include <cstdio>
#include <cmath>
using namespace std;

int chu[31];
bool can[40001];
int main() {
	int n, t, x;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &chu[i]);
	}
	can[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 15000 - chu[i]; j >= 0; j--) {
			if (can[j]) {
				can[j + chu[i]] = true;
			}
		}
		for (int j = 0; j <= 15000; j++) {
			if (can[j]) {
				can[abs(j - chu[i])] = true;
			}
		}
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &x);
		printf(can[x] ? "Y " : "N ");
	}

	return 0;
}