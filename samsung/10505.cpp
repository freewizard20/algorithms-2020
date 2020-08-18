#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int z = 0 ; z < t ; z++){
        int n;
        cin >> n;
        vector<int> buffer;
        int total = 0;
        for(int i = 0 ; i < n ; i++){
            int curr;
            cin >> curr;
            total += curr;
            buffer.push_back(curr);
        }
        float average = total/n;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(buffer[i]<=average) count++;
        }
        cout << "#" << (z+1) << " " << count << '\n';
    }
}
