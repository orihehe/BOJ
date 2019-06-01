/*
BOJ 13335 - 트럭
https://www.acmicpc.net/problem/13335
*/
#include <cstdio>
using namespace std;

/* 🐣🐥 */
int arr[1001], brg[100001];
int main() {
	int n, w, l, bp = 0;
	scanf("%d %d %d", &n, &w, &l);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		while (brg[bp] + arr[i] > l) bp++;
		for (int j = bp; j < bp + w; j++) brg[j] += arr[i];
		bp++;
	}
	for (int i = n * w; i >= 0; i--) if (brg[i]) return !printf("%d", i + 2);

	return 0;
}