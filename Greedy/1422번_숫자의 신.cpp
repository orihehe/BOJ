/*
BOJ 1422 - 숫자의 신
https://www.acmicpc.net/problem/1422

수 두개를 앞뒤, 뒤앞으로 붙였을 때 더 큰 수가 앞에오도록 정렬
*/
#include <cstdio>
#include <algorithm>
#define ll unsigned long long
#define MAX 1000000000
using namespace std;

/* 🐣🐥 */
int arr[1001];
bool cmp(int a, int b) {
	int ma = MAX, mb = MAX;
	while (!(a / ma)) ma /= 10;
	while (!(b / mb)) mb /= 10;
	return (ll)a*(ll)mb * (ll)10 + (ll)b > (ll)b * (ll)ma * (ll)10 + (ll)a;
}
int main() {
	int k, n, mxn = 0;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);
		mxn = max(mxn, arr[i]);
	}
	n -= k;
	sort(arr, arr + k, cmp);
	for (int i = 0; i < k; i++) {
		printf("%d", arr[i]);
		if (mxn == arr[i] && n > 0)
			while (n--) printf("%d", arr[i]);
	}

	return 0;
}