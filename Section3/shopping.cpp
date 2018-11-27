/*
ID: xinyu.l1
TASK: shopping
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
const long long  MAX=2147483647;
map<int, int> productMap;
int mapPointer;
struct offer
{
	int price;
	int quantity[5];
}offers[100];
int info[6][6][6][6][6], need[6], single_price[6];
int num_of_offers, num_of_products;
int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	cin>>num_of_offers;
	for(int i =0;i<num_of_offers;++i){
		int cur_offer_kinds;
		cin>>cur_offer_kinds;
		for(int j = 0;j<cur_offer_kinds;++j){
			int code,q;
			cin>>code>>q;
			if(productMap.find(code) == productMap.end()){
				productMap[code] = mapPointer;
				++mapPointer;
			}
			offers[i].quantity[productMap[code]] = q;
		}
		cin>>offers[i].price;
	}
	cin>>num_of_products;
	for(int i = 0;i<num_of_products;++i){
		int temp;
		cin>>temp;
		if(productMap.find(temp) == productMap.end()){
			productMap[temp] = mapPointer;
			++mapPointer;
		}
		cin>>need[productMap[temp]]>>single_price[productMap[temp]];
	}
	for(int x1 = 0;x1<=need[0];++x1){
		for(int x2 = 0;x2<=need[1];++x2){
			for(int x3 = 0;x3<=need[2];++x3){
				for(int x4 = 0;x4<=need[3];++x4){
					for(int x5 = 0;x5<=need[4];++x5){
						info[x1][x2][x3][x4][x5] = single_price[0]*x1 + single_price[1]*x2 + single_price[2]*x3 + single_price[3]*x4 + single_price[4]*x5;
					}
				}
			}
		}	
	}
	for(int i = 0;i<num_of_offers;++i){
		for(int x1 = offers[i].quantity[0];x1<=need[0];++x1){
			for(int x2 = offers[i].quantity[1];x2<=need[1];++x2){
				for(int x3 = offers[i].quantity[2];x3<=need[2];++x3){
					for(int x4 = offers[i].quantity[3];x4<=need[3];++x4){
						for(int x5 = offers[i].quantity[4];x5<=need[4];++x5){
							info[x1][x2][x3][x4][x5] = min(info[x1][x2][x3][x4][x5], info[x1 - offers[i].quantity[0]][x2- offers[i].quantity[1]][x3- offers[i].quantity[2]][x4 - offers[i].quantity[3]][x5- offers[i].quantity[4]] + offers[i].price);
						}
					}
				}
			}	
		}
	}
	cout<<info[need[0]][need[1]][need[2]][need[3]][need[4]]<<endl;
	return 0;
}