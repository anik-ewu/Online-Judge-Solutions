#include<bits/stdc++.h>
using namespace std;

int getRectangleArea(vector<pair<int,int>>&vp) {
    sort(vp.begin(), vp.end());

    int area = vp[1].second - vp[0].second;
    return area * area;

}

int main() {

    int t, a, b;
    cin>>t;
    for (int i = 0; i < t; i++) {
        vector<pair<int,int>>vp;
        for (int j = 0; j < 4; j++) {
            cin>>a>>b;
            vp.push_back({a, b});
        }
        
        int rectangleArea = getRectangleArea(vp);
        cout<<rectangleArea<<endl;
    }

    return 0;
}