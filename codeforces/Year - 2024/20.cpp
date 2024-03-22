/*
Binary Search + DFS
Try to find a solution between 1 to N with a binary search.
Once you pick a point X, create k + 1 segment and make sure 
each segment has at least X nodes in it.
*/

#include<bits/stdc++.h>
using namespace std;

int tempOperation;
vector<int>graph[100005];


int dfs(int u, int p, int mid) {
    int cnt = 1;
    for (int v: graph[u]) {
        if (v != p) {
            cnt += dfs(v, u, mid);
        }
    }
    if (cnt >= mid && tempOperation) {
        cnt = 0;
        tempOperation--;
    }
    return cnt;
}

bool check(int mid, int operation) {
    tempOperation = operation;
    int total = dfs(1, 1, mid);
    if (total >= mid && tempOperation == 0) {
        return true;
    }
    return false;
}

void solve() {
    int n, k;
    cin>>n>>k;

    for (int i = 0; i <= n; i++) {
        graph[i].clear();
    }

    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int lo = 1;
    int hi = n;
    int res = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, k)) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    cout<<res<<endl;
}

int main(){

    int t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}
