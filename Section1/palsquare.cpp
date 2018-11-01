/*
ID: xinyu.l1
TASK: palsquare
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

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
	while(pow(base,length) <= num) {++length;}
	--length;
	while(length>=0){
		int i,temp;
		for(i = 0;i<base;++i){
			temp = i*round(pow(base,length));
			if(temp>remain){
				--i;break;
			}
			else if(temp == remain) break;
			else if(i == base-1) break;
		}
		if(i<10) result+=to_string(i);
		else{
			result+=char(i+55);
		}
		int ij = round(double(i)*pow(double(base),double(length)));
		remain-=ij;
		--length;
	}

	return result;
}

int main(int argc, char const *argv[])
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	int n;

	cin>>n;
	for(int i = 1;i<=300;++i){
		string a = converter(n,i);
		string b = converter(n,i*i);
		if(is_pal(b)) cout<<a<<" "<<b<<endl;
	}

	return 0;
}