/*
ID: xinyu.l1
TASK: fence9
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
int x, y, p;
double k,b;
int cur_x1, cur_x2, ans;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

void calculate(int cur_y){
	double int_part_x1;
	double raw_x1 = ((double)cur_y*x/y);
	cur_x1 = (int) raw_x1 + 1;
	if(x==p){
		cur_x2 = x - 1;
		return;
	}
	else{
		double raw_x2 = ((double)cur_y-b)/k;
		double int_part_x2;
		if(modf(raw_x2, &int_part_x2) == 0.0){
			cur_x2 = (int) raw_x2 - 1;
		}
		else{
			cur_x2 = (int) raw_x2;
		}
	}
}

int gcd(int x, int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}

int main(int argc, char const *argv[])
{
	freopen("fence9.in","r",stdin);
	freopen("fence9.out","w",stdout);
	x = read();
	y = read();
	p = read();
	if(x!=p){
		k = (double)y/(x-p);
		b = (double)(-p)*k;		
	}
	/*
	for(int cur_y = 1;cur_y<y;++cur_y){
		calculate(cur_y);
		//cout<<"y = "<<cur_y<<": "<<cur_x1<<' '<<cur_x2<<endl;
		ans+=cur_x2-cur_x1+1;
	}
	*/
	int b = gcd(x,y) + gcd(abs(x-p),y) + p;
	double area = p*y/2;
	ans = area - b/2 + 1;
	cout<<ans<<endl;
	return 0;
}