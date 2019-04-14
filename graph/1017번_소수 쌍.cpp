/*
BOJ 1017 - 소수 쌍
https://www.acmicpc.net/problem/1017

2를 제외한 모든 소수는 홀수이다.
모든 홀수는 짝수 + 홀수 형태이므로 짝수 혹은 홀수를 기준으로 간선을 이어 이분그래프를 만들어준다.
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

/* 🐣🐥 */
bool visited[51];
vector<int> vec[51];
int arr[51], B[51], ss;
bool dfs(int cur) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (v == ss) continue;
		if (B[v] == -1 || !visited[B[v]] && dfs(B[v])) {
			B[v] = cur;
			return true;
		}
	}
	return false;
}
bool isPrime(int a) {
	for (int i = 2; i*i <= a; i++) {
		if (a%i == 0) return false;
	}
	return true;
}
int main() {
	int n, x, c = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	x = arr[0] % 2;
	sort(arr + 1, arr + n);
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 != x) continue;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			if (isPrime(arr[i] + arr[j]))
				vec[i].push_back(j);
		}
	}
	for (int i : vec[0]) {
		int cnt = 0;
		ss = i;
		memset(B, -1, sizeof(B));
		for (int j = 1; j < n; j++) {
			memset(visited, false, sizeof(visited));
			if (dfs(j)) cnt++;
		}
		if (cnt == n / 2 - 1) {
			printf("%d ", arr[i]);
			c++;
		}
	}
	if (c == 0) printf("-1");

	return 0;
}