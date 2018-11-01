/*
ID: xinyu.l1
TASK: wormhole
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>

using namespace std;
int count = 0;
int n;
struct Position
{
	long long x,y;
}info[12];

void swap(int i,int j){
    Position temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}

void qsorting(int start,int end){
    if(start<end){
        int pivot;
        pivot = info[start].x;
        int i = start; int j = end;
        while(i<j){
            while(i < j && info[j].x >= pivot) --j;
            swap(i,j);
            while(i < j && info[i].x <= pivot) ++i;
            swap(i,j);
        }
        info[i].x = pivot;
        qsorting(start,i-1);
        qsorting(i+1,end);
    }
}

bool find_loop(int paired[]){
	for(int i = 0;i<n;++i){
		bool visited[n];
		memset(visited,false,n);
		visited[i] = true;
		bool in = true;
		bool final_flag = false;		
		int pointer = i;
		int iter = 0;
		while(iter<100){
			if(in){
				int next = paired[pointer];
				visited[next] = true;
				in = false;
				pointer = next; 
				++iter;
			}	
			else{
				int next;
				bool flag = false;
				for(next = pointer+1;next<n;++next){
					if(info[pointer].y == info[next].y) {flag = true;break;}
				}
				if(flag){
					if(visited[next]) final_flag = true;
					visited[next] = true;
					in = true;
					pointer = next; ++iter;
				}
				else{final_flag = false;break;}
			}
		}
		if(final_flag) return true;
	}
	return false;
}

void generate_pair(int paired[], int couples){
	
	if(couples == (n/2)){
		if(find_loop(paired)){
			++count;
			return;
		}
		else return;
	}
	int pointer;
	for(pointer =0;pointer<n;++pointer){
		if(paired[pointer] == -1) break;
	}
	for(int i = 0;i<n;++i){
		if(paired[i] == -1 && i!=pointer){
			int cur_paired[12];
			copy(paired,paired+12,cur_paired);
			cur_paired[pointer] = i;
			cur_paired[i] = pointer;
			generate_pair(cur_paired,couples+1);
		}
	}
}
int main(int argc, char const *argv[])
{
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	cin>>n;
	for(int i = 0;i<n;++i) cin>>info[i].x>>info[i].y;
	qsorting(0,n-1);
	int paired[12] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	generate_pair(paired,0);
	cout<<count<<endl;
	return 0;
}