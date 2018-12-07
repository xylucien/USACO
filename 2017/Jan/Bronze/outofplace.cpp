/*
ID: xinyu.l1
TASK: outofplace
LANG: C++                 
*/
#include<set>  
#include<map>  
#include<list>  
#include<queue>  
#include<stack>  
#include<string>  
#include<cmath>  
#include<time.h>  
#include<vector>  
#include<bitset>  
#include<memory>  
#include<utility>  
#include<stdio.h>  
#include<iostream>  
#include<stdlib.h>  
#include<string.h>  
#include<algorithm> 

using namespace std;
const long long  MAX=2147483647;
int n, cnt;
int arr[101],origin[101];

void myPrint(){
	for(int i = 0;i<n;++i) cout<<origin[i]<<' ';
	cout<<endl;
	for(int i = 0;i<n;++i) cout<<arr[i]<<' ';
	cout<<endl<<endl;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("outofplace.in","r",stdin);
	freopen("outofplace.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i) {cin>>arr[i]; origin[i] = arr[i];}
	sort(arr,arr+n);
	for(int i = 0;i<n;++i){
		if(arr[i]==origin[i])continue;
		++cnt;
		for(int j = i+1;j<n;++j){
			if(arr[j] == origin[i] && arr[j]!=origin[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		//myPrint();
	}
	cout<<cnt<<endl;
	return 0;
}