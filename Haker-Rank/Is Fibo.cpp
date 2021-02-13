#include <bits/stdc++.h>

using namespace std;
unordered_set< long long > st;
const long MX=1e10;
void precal(){

   st.insert(0);
   st.insert(1);

   long long a=0, b=1, fibo=1;
   while(fibo<=MX){
       fibo=a+b;
       a=b;
       b=fibo;
       st.insert(fibo);
   }
}

// Complete the solve function below.
string solve(long n) {

    return st.find(n)!=st.end()?"IsFibo":"IsNotFibo";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    precal();

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = solve(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
