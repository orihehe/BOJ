/*
백준 14891 (https://www.acmicpc.net/problem/14891)

*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

// N=0 S=1, 반시계=-1 시계=1, 오른=2 왼=6
int main() {
	char a[5][9];
	int k, w, d, visited[5], dir;
	vector<int> vec[5];
	scanf("%s %s %s %s %d", a[1], a[2], a[3], a[4], &k);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			vec[i].push_back(a[i][j] - '0');
		}
	}
	while (k--) {
		scanf("%d %d", &w, &d);
		queue<int> q;
		q.push(w);
		memset(visited, false, sizeof(visited));
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			visited[cur] = true;
			if (cur - 1 > 0 && !visited[cur - 1]) {
				if (vec[cur - 1][2] != vec[cur][6]) {
					q.push(cur - 1);
				}
			}
			if (cur + 1 <= 4 && !visited[cur + 1]) {
				if (vec[cur][2] != vec[cur + 1][6]) {
					q.push(cur + 1);
				}
			}
			// 회전 전의 상태로 다음 톱니의 회전 여부가 결정되므로 회전은 나중에
			if (abs(w - cur) % 2 == 1)dir = -d;
			else dir = d;
			if (dir == -1) {
				int tmp = vec[cur][0];
				vec[cur].erase(vec[cur].begin());
				vec[cur].push_back(tmp);
			}
			else {
				int tmp = vec[cur][7];
				vec[cur].erase(vec[cur].end() - 1);
				vec[cur].insert(vec[cur].begin(), tmp);
			}
		}
	}
	printf("%d", 1 * vec[1][0] + 2 * vec[2][0] + 4 * vec[3][0] + 8 * vec[4][0]);

	return 0;
}