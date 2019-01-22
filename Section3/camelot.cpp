/*
ID: xinyu.l1
TASK: camelot
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
int R,C, ans = 10000000;
int boardInfo[27][31][27][31], totalInfo[27][31];
bool visited[27][31];
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

struct piece
{
	int x,y;
}knights[2500], carry[25];
piece king;

struct state
{
	int x, y, step;
};

void bfs(int a){
	int dx[8]={-1,1,2,2,1,-1,-2,-2};
	int dy[8]={2,2,1,-1,-2,-2,-1,1};
	memset(visited, 0, sizeof(visited));
	queue<state> myQueue;
	myQueue.push((state){knights[a].x, knights[a].y, 0});
	while(!myQueue.empty()){
		state cur = myQueue.front();
		myQueue.pop();
		if(visited[cur.x][cur.y]) continue;
		visited[cur.x][cur.y] = true;
		boardInfo[knights[a].x][knights[a].y][cur.x][cur.y] = cur.step;
		for(int q = 0;q<8;++q){
			int newX = cur.x + dx[q], newY = cur.y + dy[q];
			if(newX > 0 && newX <= C && newY > 0 && newY <= R) myQueue.push((state){newX, newY, cur.step+1});
		}
	}
}

void Carrybfs(int a){
	int dx[8]={-1,1,2,2,1,-1,-2,-2};
	int dy[8]={2,2,1,-1,-2,-2,-1,1};
	memset(visited, 0, sizeof(visited));
	queue<state> myQueue;
	myQueue.push((state){carry[a].x, carry[a].y, 0});
	while(!myQueue.empty()){
		state cur = myQueue.front();
		myQueue.pop();
		if(visited[cur.x][cur.y]) continue;
		visited[cur.x][cur.y] = true;
		boardInfo[carry[a].x][carry[a].y][cur.x][cur.y] = cur.step;
		for(int q = 0;q<8;++q){
			int newX = cur.x + dx[q], newY = cur.y + dy[q];
			if(newX > 0 && newX <= C && newY > 0 && newY <= R) myQueue.push((state){newX, newY, cur.step+1});
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("camelot.in","r",stdin);
	freopen("camelot.out","w",stdout);
	cin>>R>>C;
	char col;
	int row;
	cin>>col>>row;
	king.x = col - 'A' + 1;
	king.y = row;
	memset(boardInfo,20020226,sizeof(boardInfo));

	int k_num = 0;
	while(cin>>col){
		cin>>row;
		knights[k_num].x = col - 'A' + 1;
		knights[k_num].y = row;
		++k_num;
	}
	if(k_num==0){cout<<0<<endl;return 0;}
	for(int i = 0;i<k_num;++i) bfs(i);
	int pointer = 0;
	for(int dx = -2;dx<=2;++dx){
		for(int dy = -2;dy<=2;++dy){
			if(king.x+dx < 1 || king.x+dx > C || king.y+dy < 1 || king.y+dy > R) continue;
			carry[pointer].x = king.x+dx;
			carry[pointer].y = king.y+dy;
			++pointer;
		}
	}
	for(int i = 0;i<pointer;++i) Carrybfs(i);	
	
	for(int xx = 1;xx<=C;++xx){
		for(int yy = 1;yy<=R;++yy){
			for(int i = 0;i<k_num;++i){
				if(boardInfo[knights[i].x][knights[i].y][xx][yy] == 20020226){
					totalInfo[xx][yy] = 20020226;
					break;
				}
				totalInfo[xx][yy]+=boardInfo[knights[i].x][knights[i].y][xx][yy];
			}
		}
	}
	for(int dx = -2;dx<=2;++dx){
		for(int dy = -2;dy<=2;++dy){
			if(king.x+dx < 1 || king.x+dx > C || king.y+dy < 1 || king.y+dy > R) continue;
			for(int i = 0;i<k_num;++i){
				if(boardInfo[knights[i].x][knights[i].y][king.x+dx][king.y+dy] == 20020226) continue;
				for(int final_x = 1;final_x<=C;++final_x){
					for(int final_y = 1;final_y<=R;++final_y){
						ans = min(ans, totalInfo[final_x][final_y] - boardInfo[knights[i].x][knights[i].y][final_x][final_y] + max(abs(dx), abs(dy)) + boardInfo[knights[i].x][knights[i].y][king.x+dx][king.y+dy] + boardInfo[king.x+dx][king.y+dy][final_x][final_y]);
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}