/*
ID: xinyu.l1
TASK: preface
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>

using namespace std;
int n;
int info[7];

void converter(int x){
	int x1,x2,x3,x4;
	x1 = x%10;
	x2 = (x/10)%10;
	x3 = (x/100)%10;
	x4 = x/1000;
	switch(x1){
		case 0: break;
		case 1: ++info[0];break;
		case 2: info[0]+=2;break;
		case 3: info[0]+=3;break;
		case 4: ++info[0];++info[1];break;
		case 5: ++info[1];break;
		case 6: ++info[0];++info[1];break;
		case 7: info[0]+=2;++info[1];break;
		case 8: info[0]+=3;++info[1];break;
		case 9: ++info[0];++info[2];break;
	}

	switch(x2){
		case 0: break;
		case 1: ++info[2];break;
		case 2: info[2]+=2;break;
		case 3: info[2]+=3;break;
		case 4: ++info[2];++info[3];break;
		case 5: ++info[3];break;
		case 6: ++info[2];++info[3];break;
		case 7: info[2]+=2;++info[3];break;
		case 8: info[2]+=3;++info[3];break;
		case 9: ++info[2];++info[4];break;
	}

	switch(x3){
		case 0: break;
		case 1: ++info[4];break;
		case 2: info[4]+=2;break;
		case 3: info[4]+=3;break;
		case 4: ++info[4];++info[5];break;
		case 5: ++info[5];break;
		case 6: ++info[4];++info[5];break;
		case 7: info[4]+=2;++info[5];break;
		case 8: info[4]+=3;++info[5];break;
		case 9: ++info[4];++info[6];break;
	}

	info[6]+=x4;
}

int main(int argc, char const *argv[])
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;++i) converter(i);

	if(n>0) cout<<"I "<<info[0]<<endl;
	if(n>=4) cout<<"V "<<info[1]<<endl;
	if(n>=9) cout<<"X "<<info[2]<<endl;
	if(n>=40) cout<<"L "<<info[3]<<endl;
	if(n>=90) cout<<"C "<<info[4]<<endl;
	if(n>=400) cout<<"D "<<info[5]<<endl;
	if(n>=900) cout<<"M "<<info[6]<<endl;

	return 0;
}