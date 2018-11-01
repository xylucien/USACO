/*
ID: xinyu.l1
TASK: castle
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int wall_info[55][55];
int visited[55][55];
int room_size[2501];
int n,m;
int room_number = 0;
int cur_size = 0;
void search(int i, int j){
	visited[i][j] = room_number;
	++cur_size;
	if(((wall_info[i][j]&1) == 0) && (visited[i][j-1] == 0)) search(i,j-1);
	if((((wall_info[i][j]>>1)&1) == 0) && (visited[i-1][j] == 0)) search(i-1,j);
	if((((wall_info[i][j]>>2)&1) == 0) && (visited[i][j+1] == 0)) search(i,j+1);
	if((((wall_info[i][j]>>3)&1) == 0) && (visited[i+1][j] == 0)) search(i+1,j);
}

int main(int argc, char const *argv[])
{
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<m;++i){
		for(int j = 0;j<n;++j){
			cin>>wall_info[i][j];
		}
	}
	for(int i = 0;i<m;++i){
		for(int j = 0;j<n;++j){
			if(visited[i][j] == 0){
				++room_number;
				cur_size = 0;
				search(i,j);
				room_size[room_number] = cur_size;
			}
		}
	}
	cout<<room_number<<endl;
	int max = 0;
	for(int i = 1;i<=room_number;++i){
		if(room_size[i] > max) max = room_size[i];
	}
	cout<<max<<endl;
	int combined_max = 0;
	int final_i,final_j;
	char direction;
	for(int j = 0;j<n;++j){
		for(int i = (m-1);i>=0;--i){
			if((i!=0)&&(visited[i][j]!=visited[i-1][j])){
				int tsum1 = room_size[visited[i][j]]+room_size[visited[i-1][j]];
				if(combined_max<tsum1){
					final_i = i;
					final_j = j;
					direction = 'N';
					combined_max = tsum1;
				}
			}
			if((j!=(n-1))&&(visited[i][j]!=visited[i][j+1])){
				int tsum2 = room_size[visited[i][j]]+room_size[visited[i][j+1]];
				if(combined_max<tsum2){
					final_i = i;
					final_j = j;
					direction = 'E';
					combined_max = tsum2;
				}
			}
		}
	}
	cout<<combined_max<<endl;
	cout<<final_i+1<<" "<<final_j+1<<" "<<direction<<endl;
	return 0;
}