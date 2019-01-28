/*
ID: xinyu.l1
TASK: heritage
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
string in_order, pre_order;
const long long MAX = 2147483647;
inline int read(){
    int x=0, sign=1;
    char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*sign;
}

struct node
{
	char l, r;
}tree[26];

int getPosition(string x, char target){
	for(int i = 0;i<x.length();++i){
		if(x[i] == target) return i;
	}
	return -1;
}

void printTree(char x){
	if(tree[x-'A'].l != '?') printTree(tree[x-'A'].l);
	if(tree[x-'A'].r != '?') printTree(tree[x-'A'].r);
	cout<<x;
	return;
}

void constructTree(string in_order, string pre_order){
	if(in_order.length() == 1) return;
	string newInorder1, newInorder2, newPreorder1, newPreorder2;
	char root = pre_order[0];
	int pos = getPosition(in_order, root);
	if(pos!=0){
		tree[root - 'A'].l = pre_order[1];
		newInorder1 = in_order.substr(0, pos);
		newPreorder1 = pre_order.substr(1, pos);
		constructTree(newInorder1, newPreorder1);
	}
	if(pos!=in_order.length()-1){
		tree[root - 'A'].r = pre_order[1+pos];
		newInorder2 = in_order.substr(pos+1);
		newPreorder2 = pre_order.substr(pos+1);
		constructTree(newInorder2, newPreorder2);	
	}
	return;
}

int main(int argc, char const *argv[])
{
	freopen("heritage.in","r",stdin);
	freopen("heritage.out","w",stdout);
	cin>>in_order>>pre_order;
	char root = pre_order[0];
	for(int i = 0;i<26;++i){
		tree[i].l = '?';
		tree[i].r = '?';
	}
	constructTree(in_order, pre_order);
	/*
	tree['C'-'A'].l = 'B';
	tree['C'-'A'].r = 'G';
	tree['B'-'A'].l = 'A';
	tree['B'-'A'].r = 'D';
	tree['D'-'A'].l = 'E';
	tree['D'-'A'].r = 'F';
	tree['G'-'A'].r = 'H';
	*/
	printTree(root);
	cout<<endl;
	return 0;
}