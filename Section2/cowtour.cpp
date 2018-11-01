/*
ID: xinyu.l1
TASK: cowtour
LANG: C++                 
*/
#include <iostream>
#include <algorithm>
#include<cstdio>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
using namespace std;

int n;
struct pasture
{
	int x,y;
}myMap[151];
double distance_info[151][151], max_distance[151];
double left_max = 0.0, right_max = 0.0;
double INF = 1000000.0;
double diameter = INF;
bool cmp(double x,double y)
{
    return x>y;
}

double calculate_distance(int i, int j){
	return sqrt((myMap[i].x - myMap[j].x)*(myMap[i].x - myMap[j].x) + (myMap[i].y - myMap[j].y)*(myMap[i].y - myMap[j].y));
}
/*
void printInfo(){
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cout<<distance_info[i][j]<<" ";
		}
		cout<<endl;
	}
}
*/
void Floyd(){
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			for(int k = 0;k<n;++k){
				if(distance_info[i][k]+distance_info[k][j] < distance_info[i][j]){
					distance_info[i][j] = distance_info[i][k] + distance_info[k][j];
					distance_info[j][i] = distance_info[i][k] + distance_info[k][j];
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>myMap[i].x>>myMap[i].y;
		for(int j = 0;j<n;++j) distance_info[i][j] = INF;
	}
	for(int i = 0;i<n;++i){
		distance_info[i][i] = 0;
		string temp;
		cin>>temp;
		for(int j = 0;j<n;++j){
			if(temp[j] == '1') distance_info[i][j] = calculate_distance(i,j);
		}
	}
	Floyd();
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			if(distance_info[i][j] != INF) max_distance[i] = cmp(max_distance[i],distance_info[i][j]) ? max_distance[i] : distance_info[i][j];
		}
	}
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			if(distance_info[i][j] != INF) continue;
			for(int iter = 0;iter<n;++iter){
				if((distance_info[i][iter] != INF) && (i!=iter)) left_max = cmp(left_max,distance_info[i][iter]) ? left_max : distance_info[i][iter];
				if((distance_info[j][iter] != INF) && (j!=iter)) right_max = cmp(right_max,distance_info[j][iter]) ? right_max : distance_info[j][iter];
			}	
			double cur_diameter = calculate_distance(i,j) + max_distance[i] + max_distance[j];
			diameter = cur_diameter < diameter ? cur_diameter : diameter;
			diameter = (diameter > left_max) ? (diameter > right_max ? diameter : right_max) : (left_max > right_max ? left_max : right_max);
			/*
			copy(&archived_distance_info[0][0],&archived_distance_info[0][0]+151*151,&distance_info[0][0]);
			double tempdistance_info = calculate_distance(*iter_x,*iter_y);
			cout<<"ITERS ARE: "<<*iter_x<<" "<<*iter_y<<" "<<tempdistance_info<<endl;
			distance_info[*iter_x][*iter_y] = tempdistance_info;
			distance_info[*iter_y][*iter_x] = tempdistance_info;
			Floyd();
			for(int i = 0;i<n;++i){
				for(int j = 0;j<n;++j){
					//cout<<distance_info[i][j]<<" ";
					cur_max = distance_info[i][j] > cur_max ? distance_info[i][j] : cur_max;
				}
				//cout<<endl;
			}
			*/
		}
	}
	printf("%.6f\n",diameter);
	return 0;
}