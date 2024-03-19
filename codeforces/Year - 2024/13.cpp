#include<bits/stdc++.h>
using namespace std;

void solve() {
    int introvert;
    int extrovert;
    int universal;
    cin>>introvert>>extrovert>>universal;

    int extraExtroverts = extrovert  % 3;
    if (extraExtroverts && ((3 - extraExtroverts) > universal)) {
        cout<<-1<<endl;
        return;
    }

    int tentNeeded = 0;
    tentNeeded += introvert;
    tentNeeded += (extrovert / 3);
    tentNeeded += (extraExtroverts != 0);
    if (extraExtroverts) {
    universal -= (3 - extraExtroverts);
    }
    tentNeeded += (universal / 3) + (universal % 3 != 0);

    cout<<tentNeeded<<endl;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
