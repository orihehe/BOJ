/*
BOJ 2814 - 최소인수
https://www.acmicpc.net/problem/2814

p의 배수에서 p보다 작은 소수를 소인수로 가진 값을 없애주어 답을 찾는다.
*/
#include <cstdio>
#include <vector>
#define MAX 1000000000
using namespace std;

/* 🐣🐥 */
vector<int> vec;
bool sosu[100000];
int p, n, l, r, mid, ans, sz;
int dfs(int cur, int sum) {
	int ret = mid / sum;
	for (int i = cur + 1; i < sz; i++) {
		if (1LL * sum * vec[i] > mid) break;
		ret -= dfs(i, sum * vec[i]);
	}
	return ret;
}
int main() {
	scanf("%d %d", &n, &p);
	if (1LL * p * p > MAX) {
		if (n == 1) printf("%d", p);
		else printf("0");
		return 0;
	}
	for (int i = 2; i < p; i++) {
		if (!sosu[i]) {
			vec.push_back(i);
			for (int j = 2; j*i < p; j++) {
				sosu[j*i] = true;
			}
		}
	}
	sz = vec.size();
	l = p, r = MAX;
	while (l <= r) {
		mid = (l + r) / 2;
		if (dfs(-1, p) >= n) {
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	printf("%d", ans);

	return 0;
}