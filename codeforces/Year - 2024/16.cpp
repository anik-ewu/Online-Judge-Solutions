#include<bits/stdc++.h>
using namespace std;

void solve() {
    
    int n;
    cin>>n;
    
    set<int>st;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
        st.insert(arr[i]);
    }

    int MEX = 0;
    for (int val: st) {
        if (val > MEX) {
            break;
        }
        MEX++;
    }

    set<int>st1;
    int l1, r1 = n;
    for (int i = 0; i < n; i++) {
        if (arr[i] < MEX) {
            st1.insert(arr[i]);
        }
        if (st1.size() == MEX) {
            l1 = 1;
            r1 = i +  1;
            break;
        }
    }

    set<int>st2;
    int l2, r2 = 0;
    bool isDivisionPossible = false;
    for (int i = r1; i < n; i++) {
        if (arr[i] < MEX) {
            st2.insert(arr[i]);
        }
        if (st2.size() == MEX) {
            l2 = r1 + 1;
            r2 = n;
            isDivisionPossible = true;
            break;
        }
    }

    if (isDivisionPossible == true) {
        cout<<2<<endl;
        cout<<l1<<' '<<r1<<endl;
        cout<<l2<<' '<<r2<<endl;
    }
    else {
        cout<<-1<<endl;
    }

}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
