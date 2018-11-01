/*
ID: xinyu.l1
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int n;
int find(string x[], string a){
	for(int i = 0;i<n;++i){
		if(x[i] == a) return i;
	}
	return -1;
}

int main(){
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);

	cin>>n;
	string name[n];
	for(int i = 0;i<n;++i)cin>>name[i];
	int account[n];
	for(int i = 0;i<n;++i)account[i] = 0;

	int count = 0;
	while(count<n){
		string giver;
		int give_total,recips;
		cin>>giver;
		cin>>give_total>>recips;
		int cur_id = find(name,giver);
		
		if(recips!=0){
			account[cur_id]-=give_total;
			account[cur_id]+=(give_total%recips);
			int give_per = int(give_total/recips);
			for(int j = 0;j<recips;++j){
				string receiver;
				cin>>receiver;
				int rec_id = find(name,receiver);
				account[rec_id]+=give_per;
			}
		}
		++count;
	}

	for(int i = 0;i<n;++i){
		cout<<name[i]<<" "<<account[i]<<endl;
	}
	return 0;
}