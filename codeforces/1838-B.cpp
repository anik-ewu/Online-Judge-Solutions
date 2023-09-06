#include<bits/stdc++.h>
using namespace std;

void pr(int a, int b) {
    cout<<a<< ' '<<b<<endl;
}

void solve(int n) {

    int one, two, last, val;

    for (int i = 1; i <= n; i++) {
        cin>>val;
        if (val == 1) one = i;
        if (val == 2) two = i;
        if (val == n) last = i;
    }

    if (last < min(one, two)) {
        pr(last, min(one, two));
    }
    if (last > max(one, two)) {
        pr(max(one, two), last);
    }
    else {
        pr(one, two);
    }

    return;
}

int main() {

    int t, n;
    cin>>t;
    for (int i = 1; i <= t; i++) {
        cin>>n;
        solve(n);
    }



    return 0;
}
