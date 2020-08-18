#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

		string test;
        cin >> test;
        int first = 10*(test[0]-'0') + (test[1]-'0');
        int second = 10*(test[2]-'0') + (test[3]-'0');
        
        string result;
		if(first==0 && second==0){
            result = "NA";
        }else if(first ==0 && second>=1 && second <=12){
            result = "YYMM";
        }else if(first==0 && second > 12){
            result = "NA";
        }else if(first >= 1 && first <= 12 && second ==0 ){
            result = "MMYY";
        }else if(first >= 1 && first <= 12 && second >= 1 && second <= 12){
            result="AMBIGUOUS";
        }else if(first >= 1 && first <= 12 && second > 12){
            result="MMYY";
        }else if(first > 12 && second == 0){
            result="NA";
        }else if(first>12 && second >= 1 && second <=12){
            result="YYMM";
        }else{
            result = "NA";
        }
        
		cout << "#" << test_case << " " << result << '\n';

	}
	return 0;
}
