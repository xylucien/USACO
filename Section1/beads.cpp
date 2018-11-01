/*
ID: xinyu.l1
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	string necklace;
	int n;
	cin>>n;
	cin>>necklace;
	int count = 0;

	char color1;
	char color2;
	bool flag1;
	bool flag2;

	for(int i = 0;i<n;++i){
		int curcount = 0;
		int iter = i;
		flag1 = false;
		flag2 = false;
		while(true){
			
			if(!flag1){
				
				if(necklace[iter] == 'w') ++curcount;

				else{
					color1 = necklace[iter];
					++curcount;
					flag1 = true;
				}
			}


			else if(flag2){
				if(necklace[iter] == 'w' || necklace[iter] == color2) ++curcount;
				else{
					break;
				}
			}

			else if(flag1){
				
				if(necklace[iter] == 'w' || necklace[iter] == color1) ++curcount;
				
				else{
					flag2 = true;
					color2 = necklace[iter];
					++curcount;
				}
			}


			if(curcount == n) break;
			iter = (iter == n - 1) ? 0 : iter+1;
		}
		
		if(curcount>count) count = curcount;
	}


	cout<<count<<endl;
	return 0;
}