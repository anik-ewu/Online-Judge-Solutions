#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string grid[12];

int main() {

    Fast;

    int n, val, minimum = INT_MAX;
    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>val;
        minimum = min(minimum, abs(val));
    }

    cout<<minimum<<endl;

    return 0;
}