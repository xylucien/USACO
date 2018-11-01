/*
ID: xinyu.l1
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	int n;
	cin>>n;
	int max_yes = 0;
	int max_no = 0;
	int start[n];
	int ends[n];
	for(int i = 0;i<n;++i) cin>>start[i]>>ends[i];

	qsorting(start,0,n-1);
	qsorting(ends,0,n-1);
	int cur = 0;
	for(int i = 0;i<n;++i){
		if(i == n-1){
			int yes = ends[i] - start[cur];
			max_yes = yes > max_yes?yes:max_yes;
		}

		else if(ends[i]>=start[i] && ends[i] < start[i+1]){
			int yes = ends[i] - start[cur];
			max_yes = yes > max_yes?yes:max_yes;
			int no = start[i+1] - ends[i];
			max_no = max_no < no?no:max_no;
			cur = i + 1;	
		}
	}
	cout<<max_yes<<" "<<max_no<<endl;
	return 0;
}