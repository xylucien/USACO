/*
ID: xinyu.l1
TASK: ride
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);

	int ap = 1; 
	int bp = 1;
	string a,b;
	cin>>a>>b;

	int i = 0,j=0;
	while(a[i]!='\0'){
		ap*=(int)a[i] - 64;
		++i;
	}
	while(b[j]!='\0'){
		bp*=(int)b[j] - 64;
		++j;
	}
	if((ap%47) == (bp%47)) cout<<"GO"<<endl;
	else{
		cout<<"STAY"<<endl;
	}
	return 0;
}