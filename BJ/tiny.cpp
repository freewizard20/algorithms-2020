#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> height;
bool found;

void solve(int k, vector<int> & buffer) {
	if (k == 0) {
		int total = 0;
		for (int i = 0; i < 7; i++) {
			total += height[buffer[i]];
		}
		if (total == 100 && found==false) {
			for (int i = 0; i < 7; i++) {
				cout << height[buffer[i]] << endl;
			}
			found = true;
		}
		return;
	}

	int small = buffer.size() == 0 ? 0 : buffer.back() + 1;
	for (int i = small; i < 9; i++) {
		buffer.push_back(i);
		solve(k - 1, buffer);
		buffer.pop_back();
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		int tmp;
		cin >> tmp;
		height.push_back(tmp);
	}

	sort(height.begin(), height.end());
	
	found = false;
	vector<int> tmp;
	solve(7, tmp);
}
