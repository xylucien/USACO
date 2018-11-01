/*
ID: xinyu.l1
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
using namespace std;

int stall[201];
int stall_info[201];
int info[51];

void swap(int arr[],int i,int j){
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void qsorting(int x[],int start,int end){
    if(start<end){
        int pivot;
        pivot = x[start];
        int i = start; int j = end;
        
        while(i<j){
            while(i < j && x[j] >= pivot) --j;
            swap(x,i,j);
            while(i < j && x[i] <= pivot) ++i;
            swap(x,i,j);
        }
        x[i] = pivot;
        qsorting(x,start,i-1);
        qsorting(x,i+1,end);
    }
}

int main(int argc, char const *argv[])
{
	freopen("barn1.in","r",stdin);
	freopen("barn1.out","w",stdout);

	int max_board,s,c;
	cin>>max_board>>s>>c;
	for(int i = 0;i<c;++i) cin>>stall[i];
	
	qsorting(stall,0,c-1);
	if(max_board == 1){
		cout<<stall[c-1]-stall[0]+1<<endl;
		return 0;
	}
	else if(max_board>=c){
		cout<<c<<endl;
		return 0;
	}
	for(int i = 0;i<c;++i){
		if(i==0) continue;
		else{stall_info[i] = stall[i] - stall[i-1];}
	}
	int temp = max_board-1;
	while(temp!=0){
		int max = -1, pos = 0;
		for(int i = 0;i<c;++i){
			if(stall_info[i] > max){
				max = stall_info[i];
				pos = i;
				info[temp-1] = pos;
			}
		}
		stall_info[pos] = 0;
		--temp;
	}

	int result = 0;
	qsorting(info,0,max_board-2);

	for(int i = 0;i<max_board-1;++i){
		int caonima;
		if(i == max_board-2){
			caonima=(stall[info[i]-1] - stall[info[i-1]] + 1) + (stall[c-1] - stall[info[i]] + 1);
		}
		else if(i == 0){
			caonima=(stall[info[i]-1] - stall[0] + 1);
		}
		else{
			caonima=(stall[info[i]-1] - stall[info[i-1]] + 1);
		}
		result+=caonima;
	}
	cout<<result<<endl;
	return 0;
}