#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {

    Fast;

    int t, n;
    string s;

    cin>>t;
    while (t--) {
        cin>>n;

        if ((n + 4) % 3 == 0 || (n + 2) % 3 == 0) {
            cout << "First" <<endl;
        }
        else {
            cout << "Second" <<endl;
        }
    }

    return 0;
}