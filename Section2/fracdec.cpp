/*
ID: xinyu.l1
TASK: fracdec
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, integer_part;
int num_info[100010], remainder_info[100010];
bool flag = false;
int myLeft, myRight, pointer = 0;
int newline_detector = 0;
void myDivision(int x){
	//cout<<"CURRENTLY WORKING ON "<<x<<endl;
	num_info[pointer] = x*10/b;
	remainder_info[pointer] = (x*10)%b;
	//cout<<pointer<<" "<<num_info[pointer]<<" "<<remainder_info[pointer]<<endl;
	if(remainder_info[pointer] == 0){
		flag = true; 
		myLeft = pointer+1;
		return;
	}
	for(int i = 0;i<pointer;++i){
		if(i>500)break; //MAGIC, destroy the problem by this line :) L
		if(remainder_info[i] == remainder_info[pointer]){
			flag = true;
			//cout<<"FOUND "<<i<<" "<<pointer<<endl;
			if(num_info[i] == num_info[pointer]){
				myLeft = i;
				myRight = pointer;
			}
			else{
				myLeft = i+1;
				myRight = pointer+1;
			}
			return;
		}
	}
	a = remainder_info[pointer];
	++pointer;
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("fracdec.in","r",stdin);
	freopen("fracdec.out","w",stdout);
	cin>>a>>b;
	if(a>=b){
		integer_part = a/b;
		a%=b;
	}
	while(!flag) myDivision(a);
	newline_detector+= to_string(integer_part).length();
	cout<<integer_part<<'.'; ++newline_detector;
	for(int i = 0;i<myLeft;++i){cout<<num_info[i];++newline_detector;}
	if(myRight != 0){
		cout<<'(';++newline_detector;
		for(int i = myLeft;i<myRight;++i){
			if(newline_detector == 76){newline_detector = 0; cout<<endl;}
			cout<<num_info[i]; ++newline_detector;
		}
		cout<<')';
	}
	cout<<endl;
	return 0;
}