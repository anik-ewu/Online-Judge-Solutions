#include<bits/stdc++.h>
using namespace std;

bool canSortTheArray(vector<int>&arr) {
    int n = arr.size() - 1;
    bool canSortIt = true;

    for (int i = n - 1; i >= 0; i--) {
        int prev = arr[i + 1];
        int curr = arr[i];

        if (curr > prev) {
            if (curr < 10) {
                canSortIt = false;
            }
            else if ((curr/10) > curr % 10) {
                canSortIt = false;
            }
            else if((curr/10) > prev || curr % 10 > prev) {
                canSortIt = false;
            }
            else {
                arr[i] = curr / 10;
            }
        }
        //cout<<prev <<' '<<curr <<' '<<arr[i]<<endl;
    }
    return canSortIt;
}


int main(){

    int t, n;
    cin>>t;
    
    while(t--){
        
        bool possible = true;
        cin>>n;
        vector<int>arr(n, 0);

        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }

        possible = canSortTheArray(arr);

        cout<<(possible ? "YES": "NO")<<endl;

    }
    return 0;
}
