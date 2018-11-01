/*
ID: xinyu.l1
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool check_same(int n,char ax[][101],char bx[][101]){
	bool flag0 = false;
	for(int i = 0;i<n;++i){
		if(flag0) break;
		for(int j = 0;j<n;++j){
			if(bx[i][j] != ax[i][j]){
				flag0 = true;
				break;
			}
		}
		if(i == n-1) return true;
	}
	return false;
}

int determine_rotate(int n,char origin[][101],char target[][101]){

	bool flag90 = false;
	bool flag180 = false;
	bool flag270 = false;

	for(int i = 0;i<n;++i){
		if(flag90) break;
		for(int j = 0;j<n;++j){
			if(target[j][n-i-1] != origin[i][j]){
				flag90 = true;
				break;
			}
		}
		if(i == n-1) return 1;
	}

	for(int i = 0;i<n;++i){
		if(flag180) break;
		for(int j = 0;j<n;++j){
			if(target[n-i-1][n-j-1] != origin[i][j]){
				flag180 = true;
				break;
			}
		}
		if(i == n-1) return 2;
	}

	for(int i = 0;i<n;++i){
		if(flag270) break;
		for(int j = 0;j<n;++j){
			if(target[n-j-1][i] != origin[i][j]){
				flag270 = true;
				break;
			}
		}
		if(i == n-1) return 3;
	}
	return -1;
}

int doit(int n,char origin[][101],char target[][101]){
	int a = determine_rotate(n,origin,target);

	if(a!=-1)return a;

	char tempo[101][101];
	
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			tempo[i][n-j-1] = origin[i][j];//need to work on here, change into vertical
		}
	}

	if(check_same(n,tempo,target)) return 4;

	int b = determine_rotate(n,tempo,target);

	if(b!=-1) return 5;

	if(check_same(n,origin,target)) return 6;
	
	return 7;
}

int main(int argc, char const *argv[])
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	int n;

	char target[101][101];
	char origin[101][101];
	cin>>n;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cin>>origin[i][j];
		}
	}
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cin>>target[i][j];
		}
	}

	int result = doit(n,origin,target);
	cout<<result<<endl;
	return 0;
}