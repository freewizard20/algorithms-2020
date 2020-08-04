#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[15][15];
int n, k;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 1) {
					count++;
					if (j == n - 1 && count==k) {
						result++;
					}
				}
				else {
					if (count == k) {
						result++;
					}
					count = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (board[j][i] == 1) {
					count++;
					if (j == n - 1 && count == k) {
						result++;
					}
				}
				else {
					if (count == k) {
						result++;
					}
					count = 0;
				}
			}
		}

		cout << "#" << (z + 1) << " " << result << endl;
	}
}
