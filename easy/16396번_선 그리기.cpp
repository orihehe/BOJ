#include <iostream>
using namespace std;

int n, x, y, arr[10001], cnt = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> x >> y;
		for (int i = x; i < y; i++) arr[i]++;
	}
	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] != 0) cnt++;
	}
	cout << cnt;

	return 0;
}