/*
ID: xinyu.l1
TASK: sort3
LANG: C++                 
*/
#include <iostream>

using namespace std;
int n;
int info[1010];
int count = 0;
int n_number[4] = {0,0,0,0};
void swap(int i, int j){
	int temp;
	temp = info[i];
	info[i] = info[j];
	info[j] = temp;
	++count;
}

int main(int argc, char const *argv[])
{
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	cin>>n;

	for(int i = 0;i<n;++i){
		cin>>info[i];
		++n_number[info[i]];
	}

	int start_2, start_3;
	start_2 = n_number[1];
	start_3 = start_2 + n_number[2];

	for(int i = 0;i<start_2;++i){
		if(info[i]==2){
			int j;
			bool flag = false;
			for(j = start_2;j<start_3;++j){
				if(info[j]==1){
					swap(i,j);
					flag = true;
					break;
				}
			}
			if(flag) continue;
			for(j = start_3;j<n;++j){
				if(info[j]==1){
					swap(i,j);
					break;
				}
			}
		}

		else if(info[i]==3){
			int j;
			bool flag = false;
			for(j = start_3;j<n;++j){
				if(info[j]==1){
					swap(i,j);
					flag = true;
					break;
				}
			}
			if(flag) continue;
			for(j = start_2;j<start_3;++j){
				if(info[j]==1){
					swap(i,j);
					break;
				}
			}
		}
	}

	for(int i = start_2;i<start_3;++i){
		if(info[i]!=2){
			for(int j = start_3;j<n;++j){
				if(info[j]==2) {swap(i,j);break;}
			}
		}
	}

	cout<<count<<endl;

	return 0;
}