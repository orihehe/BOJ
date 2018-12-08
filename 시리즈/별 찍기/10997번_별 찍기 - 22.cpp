#include <iostream>
using namespace std;

int arr[401][401];
int main() {
	int num;
	cin >> num;

	if (num == 1) {
		cout << '*';
		return 0;
	}
	int a = num * 4 - 1;
	int b = (num - 1) * 4 + 1;

	for (int k = 0; k < a / 2; k++) {
		for (int i = k; i < a - k; i++) {
			for (int j = k; j < b - k; j++) {
				if (i == k + 1 && j == b - k - 1 && i != a / 2) {
					continue;
				}
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
				}
				else {
					arr[i][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < a; i++) {
		if (i == 1) {
			cout << "*\n";
			continue;
		}
		for (int j = 0; j < b; j++) {
			if (arr[i][j] == 1) {
				cout << "*";
			}
			else cout << " ";
		}
		cout << "\n";
	}
	return 0;
}