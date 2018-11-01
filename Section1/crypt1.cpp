/*
ID: xinyu.l1
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int dict[11];

bool is_contained(int x,int n){
	while(x!=0){
		int temp = x%10;
		bool flag = false;
		for(int i = 0;i<n;++i){
			if(dict[i] == temp){
				x/=10;
				flag = true;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	freopen("crypt1.in","r",stdin);
	freopen("crypt1.out","w",stdout);
	int n, count = 0;
	cin>>n;
	for(int i = 0;i<n;++i) cin>>dict[i];

	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			for(int k = 0;k<n;++k){
				
				int abc = 100*dict[i]+10*dict[j]+dict[k];
				
				for(int x = 0;x<n;++x){
					for(int y = 0;y<n;++y){
						int partial1 = abc*dict[x];
						int partial2 = abc*dict[y];
						if ((partial1>=100 && partial1<=999) && (partial2>=100 && partial2<=999) && is_contained(partial1,n) && is_contained(partial2,n) && is_contained(10*partial1+partial2,n)) ++count;
					}
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;
}