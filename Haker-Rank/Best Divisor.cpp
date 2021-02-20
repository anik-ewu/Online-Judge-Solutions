#include<bits/stdc++.h>
using namespace std;

#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);

int main(){

	read(x);
	write(x);

	int n;
	cin>>n;
	priority_queue< pair< int , int > > pq;

	for(int i=1; i<=n; i++){

		if(n%i==0){
			int sum=0;
			int j=i;
			while(j){
				sum+=(j%10);
				j/=10;
			}
			pq.push({sum, -i});


			sum=0;
			j=n/i;
			while(j){
				sum+=(j%10);
				j/=10;
			}
			pq.push({sum, -(n/i)});
		}

	}

	cout<<pq.top().second*-1<<endl;


	return 0;
}