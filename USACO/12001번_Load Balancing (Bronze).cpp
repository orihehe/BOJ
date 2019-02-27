/*
BOJ 12001 (https://www.acmicpc.net/problem/12001)

각 x좌표, y좌표 + 1 값을 저장해두고, 모든 좌표에 대해 완전탐색
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

/* 🐣🐥 */
pii arr[101];
vector<int> X;
vector<int> Y;
int main() {
	int n, b, a1, a2, a3, a4, fr, fc, ans = 987654321;
	scanf("%d %d", &n, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].first, &arr[i].second);
		X.push_back(arr[i].first + 1);
		Y.push_back(arr[i].second + 1);
	}
	for (int i : X) {
		for (int k : Y) {
			a1 = a2 = a3 = a4 = 0;
			for (int j = 0; j < n; j++) {
				if (arr[j].first < i && arr[j].second < k) {
					a1++;
				}
				else if (arr[j].first > i && arr[j].second < k) {
					a2++;
				}
				else if (arr[j].first < i && arr[j].second > k) {
					a3++;
				}
				else {
					a4++;
				}
			}
			ans = min(max({ a1,a2,a3,a4 }), ans);
		}
	}
	printf("%d", ans);

	return 0;
}