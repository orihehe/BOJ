/*
BOJ 1949 (https://www.acmicpc.net/problem/1949)
현재 노드를 선택 했을 때, 선택 안 했을 때의 경우를 나눠 본다.
현재노드를 선택 했을 경우 다음 노드는 선택할 수 없고, 
현재노드를 선택하지 않았다면 다음노드를 선택하거나, 선택하지 않을 수 있다.
그중 큰 경우가 답이 된다. 큰 경우를 선택하게 되면 우수마을이 아닌 마을이 연속해서 3개가 되는 경우는 나올 수 없다.
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec[10001];
int arr[10001];
int parent[10001];
int dfs(int cur, bool good) {
	int res = 0;
	for (int &v : vec[cur]) {
		if (v != parent[cur]) {
			parent[v] = cur;
			if (good) {
				res+=dfs(v, false);
			}
			else {
				res += max(dfs(v, false), dfs(v, true)+arr[v]);
			}
		}
	}
	return res;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	printf("%d", max(dfs(1,true)+arr[1],dfs(1,false)));

	return 0;
}