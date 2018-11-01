/*
ID: xinyu.l1
TASK: combo
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	int n,a1,a2,a3,m1,m2,m3;
	cin>>n;
	cin>>a1>>a2>>a3;
	cin>>m1>>m2>>m3;
	int upper,lower;
	switch(n){
		case 1:
			cout<<1<<endl;
			return 0;
		case 2:
			upper = 0;
			lower = -1;
			break;	
		case 3:
			upper = 1;
			lower = -1;
			break;
		case 4:
			upper = 2;
			lower = -1;
			break;
		default:
			upper = 2;
			lower = -2;
			break;
	}

	int a = 0,b = 0,c = 0;
	for(int i = lower;i<=upper;++i){
		for(int j = lower;j<=upper;++j){
			if(((a1+i+n)%n) == ((m1+j+n)%n)) ++a;
			if(((a2+i+n)%n) == ((m2+j+n)%n)) ++b;
			if(((a3+i+n)%n) == ((m3+j+n)%n)) ++c;
		}
	}

	cout<<((n>=5)?250:n*n*n*2)-a*b*c<<endl;
	
	return 0;
}