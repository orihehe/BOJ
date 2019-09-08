/*
BOJ 13967 - Balls and Needles
https://www.acmicpc.net/problem/13967
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define pii pair<int,int> 
using namespace std;

/* 🐣🐥 */
struct info {
	int x, y, z;
	bool operator<(const info &a)const {
		if (x == a.x && y == a.y) return z < a.z;
		if (x == a.x) return y < a.y;
		return x < a.x;
	}
};
bool visited[100001], fin[100001];
vector<pair<pii, pii>> edge;
vector<int> vec[100001];
map<info, int> mp;
map<pii, int> mm;
bool suc;
void dfs(int cur, int p) {
	visited[cur] = true;
	for (int v : vec[cur]) {
		if (v != p) {
			if (!visited[v]) dfs(v, cur);
			else if (!fin[v]) suc = true;
		}
	}
	fin[cur] = true;
}
int main() {
	int n, cnt = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		info fr, ba;
		scanf("%d %d %d", &fr.x, &fr.y, &fr.z);
		scanf("%d %d %d", &ba.x, &ba.y, &ba.z);
		if (mp[fr] == 0)
			mp[fr] = cnt++;
		if (mp[ba] == 0) mp[ba] = cnt++;
		vec[mp[fr]].push_back(mp[ba]);
		vec[mp[ba]].push_back(mp[fr]);
		if (ba < fr) swap(fr, ba);
		edge.push_back({ { fr.x, fr.y },{ ba.x,ba.y } });
	}
	for (int i = 1; i < cnt; i++) {
		if (!visited[i]) dfs(i, i);
	}
	if (suc) printf("True closed chains\n");
	else printf("No true closed chains\n");

	for (int i = 1; i < cnt; i++) vec[i].clear();
	memset(fin, false, sizeof(fin));
	memset(visited, false, sizeof(visited));
	suc = false; cnt = 1;

	sort(edge.begin(), edge.end());
	edge.erase(unique(edge.begin(), edge.end()), edge.end());
	for (pair<pii, pii> v : edge) {
		if (v.first != v.second) {
			if (mm[v.first] == 0) mm[v.first] = cnt++;
			if (mm[v.second] == 0) mm[v.second] = cnt++;
			vec[mm[v.first]].push_back(mm[v.second]);
			vec[mm[v.second]].push_back(mm[v.first]);
		}
	}
	for (int i = 1; i < cnt; i++) {
		if (!visited[i]) dfs(i, i);
	}
	if (suc) printf("Floor closed chains\n");
	else printf("No floor closed chains\n");

	return 0;
}