/*
BOJ 9426 (https://www.acmicpc.net/problem/9426)

첫 중앙값을 구해두고, 중앙값 앞의 수 개수를 구한다.
map에는 현재 구간에서 등장하는 수를 key, 수의 개수를 value에 저장하고
구간을 한 칸씩 옮기며 map에 더하고 빼준다.
앞의 수의 개수가 (k+1)/2개 이상이라면 mid값을 줄여야하고,
앞의수 + mid값 개수가 (k+1)/2개 미만이라면 mid값을 키워야 한다.
*/
#include <cstdio>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;

int arr[250000], mid, bf;
ll sum;
map<int, int> mp;
map<int, int> ::iterator iter, tmp;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < k; i++) {
		mp[arr[i]]++;
	}
	iter = mp.begin();
	while (bf < (k + 1) / 2) {
		bf += mp[iter->first];
		mid = iter->first;
		++iter;
	}
	bf -= mp[mid];
	sum = mid;
	for (int i = k; i < n; i++) {
		mp[arr[i - k]]--;
		mp[arr[i]]++;
		tmp = mp.find(mid);

		if (arr[i - k] < mid) {
			bf--;
		}
		if (arr[i] < mid) bf++;
		if (bf >= (k + 1) / 2) {
			mid = (--tmp)->first;
			bf -= mp[mid];
		}
		else if (bf+mp[mid] < (k + 1) / 2) {
			bf += mp[mid];
			mid = (++tmp)->first;
		}
		sum += mid;
		if (mp[arr[i - k]] == 0) mp.erase(arr[i - k]);
	}
	printf("%lld", sum);

	return 0;
}