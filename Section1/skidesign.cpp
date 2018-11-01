/*
ID: xinyu.l1
TASK: skidesign
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
using namespace std;

int h[1001];
int n;
int minn = 1000000;
int arr_max;
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
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	for(int i = 0;i<n;++i) cin>>h[i];
	qsorting(h,0,n-1);
	arr_max = h[n-1];
	for(int i = 0;i<=arr_max;++i){
		int cur_total = 0;
		for(int j = 0;j<n;++j){
			if(h[j]>i) cur_total+=((h[j]-i)*(h[j]-i));
			else if(h[j]+17<i) cur_total+=((i-h[j]-17)*(i-h[j]-17));
		}
		minn = minn>cur_total?cur_total:minn;
	}
	cout<<minn<<endl;
	return 0;
}