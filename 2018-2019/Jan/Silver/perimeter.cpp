/*
ID: xinyu.l1
TASK: perimeter
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
const long long MAX = 2147483647;
int n;
string info[1010];
bool visited[1010][1010];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}
int ans_size, ans_p, cur_size, cur_p;
void dfs(int i, int j){
	if(visited[i][j]) return;
	visited[i][j] = true;
	++cur_size;
	if(i==0||info[i-1][j]=='.') ++cur_p;
	if(i==n-1||info[i+1][j]=='.') ++cur_p;
	if(j==0||info[i][j-1]=='.') ++cur_p;
	if(j==n-1||info[i][j+1]=='.') ++cur_p;
	if((i!=n-1)&&(info[i+1][j]=='#')&&(!visited[i+1][j])) dfs(i+1,j);
	if((j!=n-1)&&(info[i][j+1]=='#')&&(!visited[i][j+1])) dfs(i,j+1);
	if((i!=0)&&(info[i-1][j]=='#')&&(!visited[i-1][j])) dfs(i-1,j);
	if((j!=0)&&(info[i][j-1]=='#')&&(!visited[i][j-1])) dfs(i,j-1);
}

int main(int argc, char const *argv[])
{
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	n = read();
	for(int i = 0;i<n;++i) cin>>info[i];
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			if(!visited[i][j] && info[i][j] == '#'){
				cur_size = 0;
				cur_p = 0;
				dfs(i,j);
				if(ans_size < cur_size || (ans_size==cur_size && ans_p>cur_p)){
					ans_size = cur_size;
					ans_p = cur_p;
				}
			}
		}
	}
	cout<<ans_size<<' '<<ans_p<<endl;
	return 0;
}