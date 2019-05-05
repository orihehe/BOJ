/*
BOJ 6038 - Need For Speed
https://www.acmicpc.net/problem/6038

a = F/m의 값이 큰 순서로 정렬해서 그리디하게 선택
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

/* 🐣🐥 */
struct car {
	ll f, s, idx;
};
car arr[10001];
bool ans[10001];
bool cmp(car a, car b) {
	return a.f * b.s > b.f * a.s;
}
int main() {
	ll f, m, n, af,am;
	int cnt = 0;
	double ori;
	scanf("%lld %lld %lld", &f, &m, &n);
	ori = (double)f / (double)m;
	af = f, am = m;
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &arr[i].f, &arr[i].s);
		arr[i].idx = i + 1;
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		if ((double)(af + arr[i].f) / (double)(am + arr[i].s) >= (double)af / (double)am) {
			af += arr[i].f;
			am += arr[i].s;
			cnt++;
			ans[arr[i].idx] = true;
		}
	}
	if (cnt == 0) printf("NONE");
	else {
		for (int i = 1; i <= n; i++) if (ans[i]) printf("%d\n", i);
	}

	return 0;
}