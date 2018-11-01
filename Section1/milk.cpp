/*
ID: xinyu.l1
TASK: milk
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

void qsorting(int x[],int y[],int start,int end){
    if(start<end){
        int pivot;
        pivot = x[start];
        int i = start; int j = end;
        
        while(i<j){
            while(i < j && x[j] >= pivot) --j;
            swap(x,i,j);
            swap(y,i,j);
            while(i < j && x[i] <= pivot) ++i;
            swap(x,i,j);
            swap(y,i,j);
        }
        x[i] = pivot;
        qsorting(x,y,start,i-1);
        qsorting(x,y,i+1,end);
    }
}

int main(int argc, char const *argv[])
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int total,n;
	cin>>total>>n;
	if(total == 0){
		cout<<0<<endl;
		return 0;
	}
	int unit_price[n],amount[n];
	for(int i =0;i<n;++i) cin>>unit_price[i]>>amount[i];
	qsorting(unit_price,amount,0,n-1);

	int p = 0;
	int result = 0;
	while(total!=0){
		if(total>amount[p]) {
			result+=unit_price[p]*amount[p];
			total-=amount[p];
		}
		else{
			result+=unit_price[p]*total;
			cout<<result<<endl;
			return 0;
		}
		++p;
	}
}