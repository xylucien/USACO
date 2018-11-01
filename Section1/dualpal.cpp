/*
ID: xinyu.l1
TASK: dualpal
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

long long qpow(int x, int n){
	long long result;
	if(n==0) return 1;
	else{
		while((n&1)==0){
			n>>=1;
			x*=x;
		}
	}
	result = x;
	n>>=1;
	while(n!=0){
		x*=x;
		if((n&1)!=0) result*=x;
		n>>=1;
	}
	return result;
}

bool is_pal(string x){
	for(int i = 0;i<int(x.length()/2);++i){
		if(x[i] != x[x.length()-1-i]) return false;
	}
	return true;
}

string converter(int base, int num){
	int remain = num;
	if(num == 1) return "1";
	string result = "";
	int length = 0;
	while(qpow(base,length) <= num) {++length;}
	--length;
	while(length>=0){
		int i,temp;
		for(i = 0;i<base;++i){
			temp = i*qpow(base,length);
			if(temp>remain){--i;break;}
			else if(temp == remain) break;
			else if(i == base-1) break;
		}
		if(i<10) result+=to_string(i);
		else{result+=char(i+55);}
		remain-=i*qpow(base,length);
		--length;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int n,s;
	cin>>n>>s;
	int count = 0;
	while(count!=n){
		++s;
		bool flag = false;
		for(int base = 2;base<=10;++base){
			if(flag && is_pal(converter(base,s))) {cout<<s<<endl;++count;break;}
			else if(!flag && is_pal(converter(base,s))) {flag = true;}
		}
	}
	return 0;
}