/*
BOJ 2143 (https://www.acmicpc.net/problem/2143)

n,m이 1000으로 작기 때문에 n의 부 배열은 약 50만개 나온다.
따라서 n의 모든 경우를 구해 map에 세놓고, m의 각 경우에 따라 카운트해준다.
*/
#include <cstdio>
#include <map>
#define ll long long
using namespace std;

/* 🐣🐥 */
map<int, int> mp;
int arrN[1000], arrM[1000];
int main() {
	int t, n, m, sum;
	ll ans = 0;
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arrN[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arrM[i]);
	}
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) sum += arrN[j];
		mp[sum]++;
		for (int j = i; j < n; j++) {
			sum += arrN[j];
			sum -= arrN[j - i];
			mp[sum]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		sum = 0;
		for (int j = 0; j < i; j++) sum += arrM[j];
		ans += (ll)mp[t - sum];
		for (int j = i; j < m; j++) {
			sum += arrM[j];
			sum -= arrM[j - i];
			ans += (ll)mp[t - sum];
		}
	}
	printf("%lld", ans);

	return 0;
}