#include<bits/stdc++.h>
using namespace std;
#define Fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N= 1e5+5;

int main(){

    int n, val;
    cin>>n;

    int minimum = INT_MAX;
    int second_minimum = INT_MAX;

    for (int i = 1; i <= n; i++) {
        cin>>val;
        if (i == 1) {
            minimum = val;
        }
        else {
            if (val < minimum) {
                second_minimum = minimum;
                minimum = val;
            }
            else if(val < second_minimum && val != minimum) {
                second_minimum = val;
            }
        }
//        what_is(minimum);
//        what_is(second_minimum);
    }

    if (second_minimum == INT_MAX || second_minimum == minimum) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<second_minimum<<endl;
    }

    return 0;
}

