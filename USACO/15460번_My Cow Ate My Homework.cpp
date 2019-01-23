/*
BOJ 15460 (https://www.acmicpc.net/problem/15460)

pq에 점수와 인덱스를 넣어주어 현재 범위의 최솟값을 찾는다.
최고점수가 갱신 됐을 땐 백터를 클리어 후 넣어주고, 점수가 같을 경우 백터에 그냥 넣어줌.
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#define P pair<int,int>
using namespace std;

int arr[100001];
priority_queue <P, vector<P>, greater<P>> pq;
vector<int> vec;
int main() {
	int n, x;
	double avg, la = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		pq.push({ x,i });
		arr[i] = x + arr[i - 1];
	}
	for (int i = 1; i <= n - 2; i++) {
		int cur = arr[n] - arr[i];
		while (pq.top().second <= i) 
			pq.pop(); // i이전은 소가 먹었으니 pop
		cur -= pq.top().first;

		if ((double)cur / (n - i - 1) > la) {
			vec.clear();
			vec.push_back(i);
			la = (double)cur / (n - i - 1);
		}
		else if ((double)cur / (n - i - 1) == la) {
			vec.push_back(i);
		}
	}
	for (int &v : vec) printf("%d\n", v);

	return 0;
}