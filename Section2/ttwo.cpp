/*
ID: xinyu.l1
TASK: ttwo
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

bool myMap[10+1][10+1];
bool flag = false;
int cnt = 0;
const int direction_dict[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
struct MyObject
{
	int x,y,direction;
};
MyObject farmer, cow;

int main(int argc, char const *argv[])
{
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	for(int i = 0;i<10;++i){
		for(int j = 0;j<10;++j){
			char temp;
			cin>>temp;
			if(temp == '.') myMap[i][j] = false;
			if(temp == '*') myMap[i][j] = true;
			if(temp == 'F') {
				myMap[i][j] = false;
				farmer.x = i;
				farmer.y = j;
				farmer.direction = 0;
			}
			if(temp == 'C') {
				myMap[i][j] = false;
				cow.x = i;
				cow.y = j;
				cow.direction = 0;
			}
		}
	}
	
	while(!flag){
		if (farmer.x == cow.x && farmer.y == cow.y){
			flag = true;
			break;
		}
		else if (cnt > 500000) break;
		int ctarget_x = cow.x + direction_dict[cow.direction][0];
		int ctarget_y = cow.y + direction_dict[cow.direction][1];
		int ftarget_x = farmer.x + direction_dict[farmer.direction][0];
		int ftarget_y = farmer.y + direction_dict[farmer.direction][1];

		if ((ctarget_x<0||ctarget_x>9) || (ctarget_y<0||ctarget_y>9) || myMap[ctarget_x][ctarget_y]) cow.direction = (cow.direction+1)%4;
		else {cow.x = ctarget_x; cow.y = ctarget_y;}

		if ((ftarget_x<0||ftarget_x>9) || (ftarget_y<0||ftarget_y>9) || myMap[ftarget_x][ftarget_y]) farmer.direction = (farmer.direction+1)%4;
		else {farmer.x = ftarget_x; farmer.y = ftarget_y;}

		++cnt;		
	}
	if(flag) cout<<cnt<<endl;
	else cout<<0<<endl;
	return 0;
}