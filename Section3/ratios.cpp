/*
ID: xinyu.l1
TASK: ratios
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
int feeds_info[3][3], target[3], i, j, k, ans;
int check(int i, int j, int k){
	int multiple = -1;
	int s1 = feeds_info[0][0]*i + feeds_info[1][0]*j + feeds_info[2][0]*k;
	int s2 = feeds_info[0][1]*i + feeds_info[1][1]*j + feeds_info[2][1]*k;
	int s3 = feeds_info[0][2]*i + feeds_info[1][2]*j + feeds_info[2][2]*k;
	
	if(target[0]==0 && s1!=0) return -1;
	if(target[1]==0 && s2!=0) return -1;
	if(target[2]==0 && s3!=0) return -1;

	if(target[0]!=0 && s1%target[0]==0) multiple = s1/target[0];
	else if(target[1]!=0 && s2%target[1]==0) multiple = s2/target[1];
	else if(target[2]!=0 && s3%target[2]==0) multiple = s3/target[2];
	if(multiple == -1) return -1;
	//cout<<multiple<<endl;
	//cout<<"ok so far with"<<i<<j<<k<<endl;
	/*
	if(target[0] == 0 && s1!=0) return -1;
	else if(s1==0&&target[0]==0){}
	else if(s1%target[0]!=0 || s1/target[0]!=multiple) return -1;
	if(target[1] == 0 && s2!=0) return -1;
	else if(s2==0&&target[1]==0){}
	else if(s2%target[1]!=0 || s2/target[1]!=multiple) return -1;
	if(target[2] == 0 && s3!=0) return -1;
	else if(s3==0&&target[2]==0){}
	else if(s3%target[2]!=0 || s3/target[2]!=multiple) return -1;
	*/
	if((target[0]*multiple == s1) && (target[1]*multiple == s2) && (target[2]*multiple == s3)) return multiple;
	return -1;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	cin>>target[0]>>target[1]>>target[2];
	for(int ii = 0;ii<3;++ii){
		for(int jj = 0;jj<3;++jj){
			cin>>feeds_info[ii][jj];
		}
	}
	for(i = 0; i<100; ++i){
		for(j = 0; j<100;++j){
			for(k = 0; k<100;++k){
				ans = check(i,j,k);
				if(ans!=-1 && ((i!=0)||(j!=0)||(k!=0))){
					cout<<i<<" "<<j<<" "<<k<<" "<<ans<<endl;
					return 0;
				}
				
			}
		}
	}
	cout<<"NONE"<<endl;
	return 0;
}