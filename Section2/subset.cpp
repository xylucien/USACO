/*
ID: xinyu.l1
TASK:subset 
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;
int n, target_sum;
long long magic[1000010];
//int count = 0;
//int initial[25];
//int max_length;
//bool flag = false;

/*
void search(int num_left){
	if(num_left == 0){
		int temp = 0;
		for(int i = 0;i<cur_totals;++i) temp+=cur_sum[i];
		if(temp == target_sum){
			for(int jj = 0;jj<cur_totals;++jj) cout<<cur_sum[jj]<<" ";
			cout<<endl;
			//count+=calculate();
			flag = true;
			return;}
	}
	else{
		if(flag) return;
		for(int i = (cur_totals != num_left)?(cur_sum[cur_totals - num_left -1]+1):1;i<=n;++i){
			if(flag) return;
			cur_sum[cur_totals - num_left] = i;
			search(num_left-1);
		}
	}
}
*/
int main(int argc, char const *argv[])
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	cin>>n;
	if(!(n%4 == 0 || n%4 == 3)){
		cout<<0<<endl;
		return 0;
	}
	target_sum = (1+n)*n/4;
	/*
	for(int i = 2;i<=(n/2);++i){
		cout<<"searching for "<<i<<endl;
		memset(cur_sum,0,sizeof(cur_sum));
		flag = false;
		cur_totals = i;
		search(i);
	}
	
	max_length = n/2;
	int i;
	for(i = 0;i<(n/4);++i) initial[i] = i+1;
	for(int j = (n%4==3)? (n-(n/4)) : (n-(n/4)+1); j<=n; ++j){
		initial[i] = j;
		++i;
	}

	//for(int i = 0;i<max_length;++i) cout<<initial[i]<<" ";
	//cout<< endl<<max_length<< endl;
	*/

	//what the actual fuck???
	magic[0]=1;
    for(int i=1;i<=n;i++)
        for(int j=target_sum;j>=i;--j)
            magic[j]+=magic[j-i];
    cout<<magic[target_sum]/2<<endl;
	return 0;
}