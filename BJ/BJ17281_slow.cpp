#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <algorithm>

using namespace std;

int result[50][9];
int n;

int getresult(int inning, int curr, vector<int> tmp) {
	if (curr <= 2) {
		if (tmp[curr] == 0) {
			return result[inning][8];
		}
		else {
			return result[inning][tmp[curr]];
		}
	}
	else if (curr == 3) {
		return result[inning][0];
	}
	else {
		if (tmp[curr - 1] == 0) {
			return result[inning][8];
		}
		else {
			return result[inning][tmp[curr - 1]];
		}
	}
}

int solve(int m, vector<int>& tmp, unordered_set<int> &set) {
	if (m == 0) {
		/*for (int i = 0; i < tmp.size(); i++) {
			cout << tmp[i] << " ";
		}
		cout << '\n';*/
		// simulate
		int point = 0;
		int curr = 0;
		for (int i = 0; i < n; i++) {
			int roo[3] = { 0, };
			int out = 0;			
			while (out != 3) {
				int thisgame = getresult(i, curr, tmp);
				//cout << thisgame << endl;
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
					}
					else {
						roo[2] = 0;
					}
					if (roo[0] == 1) {
						roo[1] = 1;
					}
					else {
						roo[1] = 0;
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
					}
					else {
						roo[2] = 0;
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

				curr++;
				if (curr == 9) curr = 0;
			}
		}
		// cout << "point : " << point << endl;
		return point;
	}

	int ret = 0;

	for (int i = 0; i < 8; i++) {
		if (set.find(i) == set.end()) {
			set.insert(i);
			tmp.push_back(i);
			ret = max(ret, solve(m - 1, tmp, set));
			tmp.pop_back();
			set.erase(i);
		}
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
	cout << solve(8, tmp, set) << endl;
}
