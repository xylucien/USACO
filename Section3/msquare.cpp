/*
ID: xinyu.l1
TASK: msquare
LANG: C++11                 
*/
#include<set>  
#include<map>  
#include<list>  
#include<queue>  
#include<stack>  
#include<string>  
#include<cmath>  
#include<assert.h>  
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
int factorial[] = {1,1,2,6,24,120,720,5040,40320};

char cur_info[8], temp_info[8], target_info[8];
bool find_info[41000], flag;
int info[100000], pointer, max_pos, temp_cantorNum, target, cur_cantorNum;
string search_map[41000];

int hf_module(int k, int mod){
	while(k>=mod) k-=mod;
	return k;
}

int Cantor(char a[])
{
    int ii,jj,cnt,mySum;
    mySum=0;
    for(ii=0;ii<8;++ii)
    {
        cnt = 0;
        for(jj=ii+1;jj<8;++jj){
            if(a[ii]>a[jj]){
            	++cnt;
            }
        }
        mySum+=(cnt*factorial[7-ii]);
    }
    return mySum + 1;
}

void reverse_Cantor(int k)
{
    int ii, jj, cnt, visited[9]={0,0,0,0,0,0,0,0,0};
    --k;
    for(ii=0;ii<8;++ii)
    {
        cnt = k/factorial[7-ii];
        for(jj=1;jj<=8;jj++)
            if (!visited[jj])
            {
                if (cnt == 0) break;
                --cnt;
            }
        cur_info[ii] = '0' + jj;
        visited[jj] = 1;
        k = hf_module(k,factorial[7-ii]);
    }
}

void move(char x){
	if(!find_info[temp_cantorNum]){
		find_info[temp_cantorNum] = true;
		info[max_pos] = temp_cantorNum;
		++max_pos;
		search_map[temp_cantorNum] = search_map[cur_cantorNum] + x;
	}	
	return;
}

void search(){
	cur_cantorNum = info[pointer];
	++pointer;
	reverse_Cantor(cur_cantorNum);
	//cout<<"CURRENT CANTOR SERIE IS "<<cur_info[0]<<cur_info[1]<<cur_info[2]<<cur_info[3]<<cur_info[4]<<cur_info[5]<<cur_info[6]<<cur_info[7]<<endl;
	//cout<<cur_cantorNum<<" with ";
	
	//case A
	temp_info[0] = cur_info[7];
	temp_info[1] = cur_info[6];
	temp_info[2] = cur_info[5];
	temp_info[3] = cur_info[4];
	temp_info[4] = cur_info[3];
	temp_info[5] = cur_info[2];
	temp_info[6] = cur_info[1];
	temp_info[7] = cur_info[0];
	temp_cantorNum = Cantor(temp_info);
	move('A');

	//case B
	//cout<<"SEARCHING FOR B"<<endl;
	temp_info[0] = cur_info[3];
	temp_info[1] = cur_info[0];
	temp_info[2] = cur_info[1];
	temp_info[3] = cur_info[2];
	temp_info[4] = cur_info[5];
	temp_info[5] = cur_info[6];
	temp_info[6] = cur_info[7];
	temp_info[7] = cur_info[4];
	temp_cantorNum = Cantor(temp_info);
	move('B');
	
	//case C
	//cout<<"SEARCHING FOR C"<<endl;
	temp_info[0] = cur_info[0];
	temp_info[1] = cur_info[6];
	temp_info[2] = cur_info[1];
	temp_info[3] = cur_info[3];
	temp_info[4] = cur_info[4];
	temp_info[5] = cur_info[2];
	temp_info[6] = cur_info[5];
	temp_info[7] = cur_info[7];
	temp_cantorNum = Cantor(temp_info);
	move('C');
	return;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("msquare.in","r",stdin);
	freopen("msquare.out","w",stdout);
	cin>>target_info[0]>>target_info[1]>>target_info[2]>>target_info[3]>>target_info[4]>>target_info[5]>>target_info[6]>>target_info[7];
	target = Cantor(target_info);
	if(target==1){cout<<0<<endl<<endl;return 0;}
	find_info[1] = true;
	info[0] = 1;
	max_pos = 1;

	while(!find_info[target]) search();

	cout<<search_map[target].length()<<endl;
	int printansCount = 0;	
	for(int i = 0; i < search_map[target].size();++i){
   		cout<<search_map[target][i];
   		++printansCount;
   		if(printansCount==60){
   			cout<<endl;
   			printansCount = 0;
   		}
	}
	if(printansCount!=0) cout<<endl;	
	
	return 0;
}