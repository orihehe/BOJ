/*
BOJ 1949 (https://www.acmicpc.net/problem/1949)
���� ��带 ���� ���� ��, ���� �� ���� ���� ��츦 ���� ����.
�����带 ���� ���� ��� ���� ���� ������ �� ����, 
�����带 �������� �ʾҴٸ� ������带 �����ϰų�, �������� ���� �� �ִ�.
���� ū ��찡 ���� �ȴ�. ū ��츦 �����ϰ� �Ǹ� ��������� �ƴ� ������ �����ؼ� 3���� �Ǵ� ���� ���� �� ����.
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