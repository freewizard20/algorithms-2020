#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for (int i = 1; i < s.size(); i++) {
        vector<string> buffer;
        int index = 0;
        string tmp = "";
        for (int j = 0; j < s.size(); j++) {
            tmp.push_back(s[j]);
            if (j == s.size() - 1) {
                buffer.push_back(tmp);
                break;
            }
            index++;
            if (index == i) {
                buffer.push_back(tmp);
                tmp = "";
                index = 0;
            }
        }

        int tmp_length = 0;
        for (int j = 0; j < buffer.size();) {
            int count = 1;
            int curr = j+1;
            while (curr!=buffer.size() && buffer[j] == buffer[curr]) {
                count++;
                curr++;
                if (curr == buffer.size()) {
                    break;
                }
            }
            // cout << "curr : " << curr << endl;
            // cout << "bufferj " << buffer[j] << endl;
            tmp_length += buffer[j].size();
            j = curr;
            if (count > 1) {
                tmp_length++;
            }
            if (count >= 10) {
                tmp_length++;
            }
            if (count >= 100) {
                tmp_length++;
            }
            if (count >= 1000) {
                tmp_length++;
            }
            count = 1;
        }

        // cout << "tmp length " << tmp_length << endl;
        if (tmp_length < answer) {
            answer = tmp_length;
        }
    }
    return answer;
}

int main() {
    cout << solution("abcabcabcabcdededededede");
}
