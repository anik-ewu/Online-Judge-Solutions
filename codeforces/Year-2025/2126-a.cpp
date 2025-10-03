#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void solve(int x) {
    stringstream digit;
    digit<<x;
    string s;
    digit>>s;

    for (char y = '0'; y <= '9'; y++) {
        if (s.find(y) != string::npos) {
            cout<<y<<endl;
            return;
        }
    }
}

int main() {

    int t;
    int x, y;
    cin>>t;
    for (int i = 0; i < t; i++) {
        cin>>x;
        solve(x);
    }

    return 0;
}