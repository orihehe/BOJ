/*
BOJ 14627 (https://www.acmicpc.net/problem/14627)
이분탐색을 이용하여 각 치킨에 넣을 같은 양의 파의 최대 크기를 구한다.
파의 양을 정하고 파들에서 그 파의 양이 몇개 나올지 센 뒤 
목표치보다 적게 나온다면 파의 양을 줄이고, 많게 나온다면 파의 양을 늘린다.
최대 크기로 넣었을 때 넣을 파의 갯수가 치킨의 수보다 많을 수 있으므로 고려해서 출력해준다. 
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[1000001];
int main() {
	ll s, c, left, right, mid, ramen = 0, cnt, ans, acnt;
	scanf("%lld %lld", &s, &c);
	for (int i = 0; i < s; i++) {
		scanf("%lld", &arr[i]);
	}
	acnt = c;
	sort(arr, arr + s);
	left = 1, right = arr[s - 1];
	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;
		for (int i = 0; i < s; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt < c) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			ans = mid; acnt = cnt;
		}
	}
	for (int i = 0; i < s; i++) {
		ramen += arr[i] % ans;
	}
	printf("%lld", (acnt - c)*ans + ramen);
	return 0;
}