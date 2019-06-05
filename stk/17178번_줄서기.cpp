/*
BOJ 17178 - 줄서기
https://www.acmicpc.net/problem/17178
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

/* 🐣🐥 */
stack<int> sk;
vector<int> arr;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	int n, x;
	char c;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %c-%d", &c, &x);
			arr.push_back((c - 'A') * 1000 + x);
			pq.push((c - 'A') * 1000 + x);
		}
	}
	for (int i = 0; i < n * 5; i++) {
		sk.push(arr[i]);
		while (!sk.empty() && sk.top() == pq.top()) {
			pq.pop();
			sk.pop();
		}
	}
	if (!pq.empty()) printf("BAD");
	else printf("GOOD");

	return 0;
}