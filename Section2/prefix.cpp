/*
ID: xinyu.l1
TASK: prefix
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
string x = "";
string dictionary[201];
int cur_index;
int n;
bool info[300000];
bool flag = false;

int main(int argc, char const *argv[])
{
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	while(1){
		string temp;
		cin>>temp;
		if(temp!=".") {dictionary[n] = temp;++n;}
		else break;
	}
	while(1){
		string temp;
		cin>>temp;
		if(temp == "")break;
		else x+=temp;
	}
	
	for(int i = 0;i<x.length();++i){
		if(i==0 || info[i-1]){
			for(int j = 0;j<n;++j){
				if(info[i + dictionary[j].length() -1]) continue;
				if(dictionary[j] == x.substr(i,dictionary[j].length())) info[i + dictionary[j].length() -1] = true;
			}
		}
	}

	for(int i = x.length() - 1;i>=0;--i){
		if(info[i]){cout<<i+1<<endl;flag = true;break;}
	}
	if(!flag)cout<<0<<endl;
	
	return 0;
}