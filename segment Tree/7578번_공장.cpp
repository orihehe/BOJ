/*
백준 7578 공장 (https://www.acmicpc.net/problem/7578)
두 케이블 a,b가 교차하려면 aA < bA && aB > bB 이거나 aA > bA && aB < bB 여야 한다.
따라서 A나 B를 기준으로 케이블을 차례로 연결하여 위의 조건중 하나를 사용하면 된다.
B기준 i번째 케이블을 연결할 때 i번째의 A도착지 j 이상에 연결된 케이블 수를 세면 된다.
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

int *tree, idx[1000001], arr[500001];
void change(int k, int idx, int start, int end) {
	if (start > k || end < k) return;
	tree[idx]++;
	if (start == end) return;
	int mid = (start + end) / 2;
	change(k, idx * 2, start, mid);
	change(k, idx * 2 + 1, mid + 1, end);
}
int find_sum(int fs, int fe, int idx, int start, int end) {
	if (start > fe || end < fs) return 0;
	if (fs <= start && end <= fe) {
		return tree[idx];
	}
	int mid = (start + end) / 2;
	return find_sum(fs, fe, idx * 2, start, mid) +
		find_sum(fs, fe, idx * 2 + 1, mid + 1, end);
}

int main() {
	int n, h, x;
	ll sum = 0;
	scanf("%d", &n);
	h = ceil(log2(n))+1;
	tree = new int [1 << h];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		idx[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x); 
		arr[i] = idx[x];
	}
	fill(tree, tree + (1 << h), 0);
	for (int i = 1; i <= n; i++) {
		// 도착지 arr[i]~n에 연결된 케이블 수 더함
		sum += (ll)find_sum(arr[i], n, 1, 1, n);
		// arr[i]번째 케이블 연결
		change(arr[i], 1, 1, n);
	}
	printf("%lld", sum);
	delete[] tree;

	return 0;
}