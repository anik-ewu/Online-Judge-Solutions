#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y, int n) {
    return (x >= 0 && x <= 1 && y >= 0 && y < n );
}

void solve() {
    int n;
    cin>>n;
    
    char arr[2][n];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin>>arr[i][j];
        }
    }

    int matrix[2][n];
    memset(matrix, 0, sizeof(matrix));

    queue<pair<int, int>>q;
    q.push({0, 0});
    matrix[0][0] = 1;
    bool canvisit = false;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == 1 && y == n - 1) {
            canvisit = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (valid(newX, newY, n)) {
                if (arr[newX][newY] == '>') {
                    newY++;
                }
                else {
                    newY--;
                }
            }
            
            if (valid(newX, newY, n) && matrix[newX][newY] == 0) {
                q.push({newX, newY});
                matrix[newX][newY] = 1;
            }
        }
    }

    if (canvisit) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
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
