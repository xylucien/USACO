/*
ID: xinyu.l1
TASK: maze1
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int width,height;
int exit1_x, exit1_y, exit2_x, exit2_y;
int cur_minStep;
int global_max = -1;
int myMap[110][110];
bool readexit_flag1 = false;
bool flag = false;
bool visited[110][110];
struct search_info
{
	int x,y,cur_step;
};
queue<search_info> search_queue;

void hf_read_exit(int i, int j){
	if(readexit_flag1){
		exit2_x = i;
		exit2_y = j;
	}
	else{
		readexit_flag1 = true;
		exit1_x = i;
		exit1_y = j;
	}	
	return;
}

void next_step(int cur_x, int cur_y, int cur_step){
	if(cur_x!=0){
	if(((myMap[cur_x][cur_y]&1) == 0) && !visited[cur_x-1][cur_y]){ 
		//cout<<"GOING UP POSSIBLE"<<endl;
		search_info a = {cur_x-1,cur_y,cur_step+1};
		search_queue.push(a);
	}}
	if(cur_y!=width-1){
	if((((myMap[cur_x][cur_y]>>1)&1) == 0) && !visited[cur_x][cur_y+1]){
		//cout<<"GOING RIGHT POSSIBLE"<<endl;
		search_info a = {cur_x,cur_y+1,cur_step+1};
		search_queue.push(a);
	}}
	if(cur_x!=height-1){
	if((((myMap[cur_x][cur_y]>>2)&1) == 0) && !visited[cur_x+1][cur_y]){
		//cout<<"GOING DOWN POSSIBLE"<<endl;
		search_info a = {cur_x+1,cur_y,cur_step+1};
		search_queue.push(a);
	}}
	if(cur_y!=0){
	if((((myMap[cur_x][cur_y]>>3)&1) == 0) && !visited[cur_x][cur_y-1]){
		//cout<<"GOING LEFT POSSIBLE"<<endl;
		search_info a = {cur_x,cur_y-1,cur_step+1};
		search_queue.push(a);
	}}	
}

search_info search(search_info cur_info){
	if((exit1_x == cur_info.x && exit1_y == cur_info.y) || (exit2_x == cur_info.x && exit2_y == cur_info.y)){
		cur_minStep = cur_info.cur_step;
		flag = true;
		search_info a = {-1,-1,-1};
		return a;
	}

	if(visited[cur_info.x][cur_info.y]){
		search_info a = search_queue.front();
		search_queue.pop();
		return a;
	}
	else{
		visited[cur_info.x][cur_info.y] = true;
		next_step(cur_info.x,cur_info.y,cur_info.cur_step);
		search_info a = search_queue.front();
		search_queue.pop();
		return a;
	}
}

int main(int argc, char const *argv[])
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	cin>>width>>height;
	for(int i = 0;i<=2*height+1;++i){
		string cur_row;
		getline(cin,cur_row);
		if(i==0)continue;
		if((i%2)==1){
			if(i==1){
				for(int j = 0;j<width;++j){
					if(cur_row[2*j+1] == ' ') hf_read_exit(0,j);
					myMap[0][j]+=1;
				}
			}
			else if(i==2*height+1){
				for(int j = 0;j<width;++j){
					if(cur_row[2*j+1] == ' ') hf_read_exit(height-1,j);
					myMap[height-1][j]+=4;
				}
			}
			else{
				for(int j = 0;j<width;++j){
					if(cur_row[2*j+1] == '-'){
						myMap[i/2-1][j]+=4;
						myMap[i/2][j]+=1;
					}
				}
			}
		}
		else{
			for(int j = 0;j<=width;++j){
				if(j == 0){
					if(cur_row[0] == ' ') hf_read_exit(i/2-1,0);
					myMap[i/2-1][0]+=8;
				}
				else if (j == width){
					if(cur_row[2*j] == ' ') hf_read_exit(i/2-1,width-1);
					myMap[i/2-1][width-1]+=2;
				} 
				else if(cur_row[2*j] == '|'){
					myMap[i/2-1][j]+=8;
					myMap[i/2-1][j-1]+=2;
				}
			}
		}
	}
	
	for(int i = 0;i<height;++i){
		for(int j = 0;j<width;++j){
			search_queue = queue<search_info>();
			cur_minStep = -1;
			flag = false;
			memset(visited,false,sizeof(visited));
			search_info initial = {i,j,0};
			search_info next = search(initial);
			while(!flag) next = search(next);
			global_max = global_max<cur_minStep?cur_minStep:global_max;
		}
	}
	
	cout<<global_max+1<<endl;
	return 0;
}