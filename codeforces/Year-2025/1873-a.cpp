#include<iostream>
using namespace std;
#define Fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string grid[12];

int main() {

    Fast;

    int t, n, k, val;
    cin>>t;
    while (t--) {

        for (int i = 1; i <= 10; i++) {
            cin>>grid[i];
        }

        int totalPoints = 0;
        for (int row = 1; row <= 10 ; row++) {
            for (int col = 0; col < 10; col++) {
                if (grid[row][col] != '.') {
                    int up = row;
                    int left = col + 1;
                    int right = 10 - left + 1;
                    int down = 10 - row + 1;
                    totalPoints += min(up, min(left, min(right, down)));
                }
            }
        }

        cout<<totalPoints<<endl;
    }

    return 0;
}