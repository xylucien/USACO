/*
ID: xinyu.l1
TASK: frac1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>

using namespace std;

int n;
int fraction[50050][2];
double value[50050];

void qsorting(int start,int end){
    if(start<end){
        double pivot;
        pivot = value[start];
        int i = start; int j = end;
        while(i<j){
        	int temp0,temp1;
        	double temp;
            while(i < j && value[j] >= pivot) --j;
            temp0 = fraction[i][0];
		    fraction[i][0] = fraction[j][0];
		    fraction[j][0] = temp0;
		    
		    temp1 = fraction[i][1];
		    fraction[i][1] = fraction[j][1];
		    fraction[j][1] = temp1;
		    
		    temp = value[i];
		    value[i] = value[j];
		    value[j] = temp;
            
            while(i < j && value[i] <= pivot) ++i;
            
            temp0 = fraction[i][0];
		    fraction[i][0] = fraction[j][0];
		    fraction[j][0] = temp0;
		    
		    temp1 = fraction[i][1];
		    fraction[i][1] = fraction[j][1];
		    fraction[j][1] = temp1;
		    
		    temp = value[i];
		    value[i] = value[j];
		    value[j] = temp;
        }
        value[i] = pivot;
        qsorting(start,i-1);
        qsorting(i+1,end);
    }
}

int gcd_template(int a, int b){
	return b == 0 ? a : gcd_template(b,a%b);
}

int main(int argc, char const *argv[])
{
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	cin>>n;
	int count = 2;
	
	fraction[0][0] = 0;
	fraction[0][1] = 1;
	value[0] = 0;
	fraction[1][0] = 1;
	fraction[1][1] = 1;
	value[1] = 1;
	for(int i = 2;i<=n;++i){
		for(int j = 1;j<i;++j){
			if(gcd_template(i,j)==1){
				fraction[count][0] = j;
				fraction[count][1] = i;
				value[count] = double(j)/i;
				++count;
			}
		}
	}
	qsorting(0,count-1);
	for(int i = 0;i<count;++i) cout<<fraction[i][0]<<'/'<<fraction[i][1]<<endl;
	return 0;
}