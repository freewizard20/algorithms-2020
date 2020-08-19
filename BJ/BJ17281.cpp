#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

int result[50][9];
int n;

int arr[] = { 0,1,2,3,4,5,6,7 };

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int getresult(int inning, int curr) {
	if (curr <= 2) {
		if (arr[curr] == 0) {
			return result[inning][8];
		}
		else {
			return result[inning][arr[curr]];
		}
	}
	else if (curr == 3) {
		return result[inning][0];
	}
	else {
		if (arr[curr - 1] == 0) {
			return result[inning][8];
		}
		else {
			return result[inning][arr[curr - 1]];
		}
	}
}

int solve(int m, int depth) {
	if (m == depth) {
		/*for (int i = 0; i < 8; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';*/
		// simulate
		int point = 0;
		int curr = 0;
		for (int i = 0; i < n; i++) {
			int roo[3] = { 0, 0,0 };
			int out = 0;
			while (out != 3) {
				int thisgame = getresult(i, curr);
				// cout << thisgame << endl;
				if (thisgame == 0) {
					out++;
				}
				else if (thisgame == 1) {
					if (roo[2] == 1) {
						point++;
						roo[2] = 0;
					}
					if (roo[1] == 1) {
						roo[2] = 1;
						roo[1] = 0;
					}
					if (roo[0] == 1) {
						roo[1] = 1;
						roo[0] = 0;
					}
					roo[0] = 1;
				}
				else if (thisgame == 2) {
					if (roo[2] == 1) {
						point++;
						roo[2] = 0;
					}
					if (roo[1] == 1) {
						point++;
						roo[1] = 0;
					}
					if (roo[0] == 1) {
						roo[2] = 1;
						roo[0] = 0;
					}
					roo[1] = 1;
				}
				else if (thisgame == 3) {
					if (roo[2] == 1) {
						point++;
						roo[2] = 0;
					}
					if (roo[1] == 1) {
						point++;
						roo[1] = 0;
					}
					if (roo[0] == 1) {
						point++;
						roo[0] = 0;
					}
					roo[2] = 1;
				}
				else {
					for (int i = 0; i < 3; i++) {
						if (roo[i] == 1) {
							point++; roo[i] = 0;
						}
					}
					point++;
				}
				// cout << "temp point : " << point << endl;
				curr++;
				if (curr == 9) curr = 0;
			}
		}
		//cout << "point : " << point << endl;
		return point;
	}

	int ret = 0;

	for (int i = depth; i < 8; i++) {
		swap(&arr[i], &arr[depth]);
		ret = max(ret, solve(8, depth + 1));
		swap(&arr[i], &arr[depth]);

	}

	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> result[i][j];
		}
	}
	unordered_set<int> set;
	vector<int> tmp;
	cout << solve(8, 0) << endl;
}
