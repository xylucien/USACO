/*
ID: xinyu.l1
TASK: rental
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
int n, a, b, pointer;
int production[100010], rental[100010];
long long sum_r[100010];
pair<int, int> sell[100010];
long long last_sum, ans;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second > b.second;
}
bool Mycmp(int a, int b){
	return a > b;
}

long long myArrange(int i){
	//cout<<"milking "<<i+1<<" cows"<<endl;
	long long sell_sum = last_sum;
	int cur_product = production[i];
	//cout<<cur_product<<' '<<sell[pointer].first<<endl;
	bool flag = true;
	while(cur_product > sell[pointer].first){
		sell_sum+=sell[pointer].first*sell[pointer].second;
		cur_product-=sell[pointer].first;
		++pointer;
		//cout<<"order "<<pointer-1<<" filled and remained "<<cur_product<<endl;
		if(pointer==a){flag = false;break;}
	}
	if(flag){
		sell_sum+=cur_product*sell[pointer].second;
		sell[pointer].first -= cur_product;
		last_sum = sell_sum;
		//cout<<"order "<<pointer<<" took "<<cur_product<<endl;		
	}

	int temp = min(n-i-1,b);
	//cout<<sell_sum <<'+'<< sum_r[temp]<<endl<<endl;
	return sell_sum + sum_r[temp];
}

int main(int argc, char const *argv[])
{
	freopen("rental.in","r",stdin);
	freopen("rental.out","w",stdout);
	n = read();
	a = read();
	b = read();
	for(int i = 0;i<n;++i) production[i] = read();
	for(int i = 0;i<a;++i){sell[i].first = read();sell[i].second = read();}
	for(int i = 0;i<b;++i) rental[i] = read();
	sort(production,production+n,Mycmp);
	sort(sell,sell+a,cmp);
	sort(rental,rental+b,Mycmp);
	for(int i = 1;i<=n;++i) {sum_r[i] = sum_r[i-1] + rental[i-1];}
	int tempp = min(b,n);
	ans = sum_r[tempp];
	for(int i = 0;i<n;++i){
		if(pointer==a) break;
		ans = max(ans, myArrange(i));
	}
	cout<<ans<<endl;
	return 0;
}