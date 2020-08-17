#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool isright(string v) {
    stack<char> test;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == ')') {
            if (test.size() != 0 && test.top() == '(') {
                test.pop();
            }
            else {
                return false;
            }
        }
        else {
            test.push(v[i]);
        }
        }
    return true;
}

string solution(string p) {
    if (p.size() == 0) return "";
    if (isright(p)) return p;
    int leftcount = 0;
    int rightcount = 0;
    int endindex = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') leftcount++;
        else rightcount++;
        if (leftcount == rightcount) {
            endindex = i;
            break;
        }
    }

    string u = "";
    string v = "";
    for (int i = 0; i < p.size(); i++) {
        if (i <= endindex) u.push_back(p[i]);
        else v.push_back(p[i]);
    }

    if (isright(u)) {
        return u + solution(v);
    }
    else {
        string answer = "(";
        answer += solution(v);
        answer += ")";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') {
                answer.push_back(')');
            }
            else {
                answer.push_back('(');
            }
        }
        return answer;
    }        
}
