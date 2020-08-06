#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[1000][1000];
int m, n;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	cin >> m >> n;
	queue<pair<pair<int, int>, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				q.push(pair<pair<int, int>, int>(pair<int, int>(i, j), 0));
			}
		}
	}

	int maxtime = 0;
	while (q.size() != 0) {
		int currx = q.front().first.first;
		int curry = q.front().first.second;
		int time = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tmpx = currx + dx[i];
			int tmpy = curry + dy[i];
			if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m && board[tmpx][tmpy] == 0) {
				board[tmpx][tmpy] = 1;
				q.push(pair<pair<int, int>,int>(pair<int, int>(tmpx, tmpy), time + 1));
				maxtime = time + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				maxtime = 9999999;
			}
		}
	}

	if (maxtime == 9999999) cout << -1;
	else cout << maxtime;
}
