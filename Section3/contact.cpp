/*
ID: xinyu.l1
TASK: contact
LANG: C++                 
*/
#include <iostream>
#include <string>
#include <cmath>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const long long  MAX=2147483647;
char info[200001];
int lbound, ubound, n;
struct contact_pattern
{
	int p_freq;
	string p_info;
}patterns[200001];
unordered_map<string, int> patt_map;
int pointer = 0, c_total = -1, total_freq_cnt = 0, cur_freq_cnt = 0;

bool cmp(contact_pattern a, contact_pattern b){
	if(a.p_freq != b.p_freq) return a.p_freq > b.p_freq;
	if(a.p_info.length() != b.p_info.length()) return a.p_info.length() < b.p_info.length();
	for(int i = 0; i<a.p_info.length(); ++i){
		if(a.p_info[i]!=b.p_info[i]) return !(a.p_info[i] == '1');
	}
}

void map_checker(string x){
	if(patt_map.count(x) > 0){
		++patterns[patt_map[x]].p_freq;
	}
	else{
		patt_map[x] = pointer;
		patterns[pointer].p_freq = 1;
		patterns[pointer].p_info = x;
		++pointer;
	}
}

void process_data(int z){
	if(z > c_total) return;
	string cur_info = "";
	int cur_pointer = z-1;
	for(int j = 0;j<z;++j) cur_info+=info[j];
	//cout<<cur_info<<endl;
	map_checker(cur_info);
	for(int i = z;i<c_total;++i){
		cur_info = cur_info.substr(1,z-1) + info[i];
		//cout<<cur_info<<endl; //fucked up, fix later
		map_checker(cur_info);
	}
}

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	freopen("contact.in","r",stdin);
	freopen("contact.out","w",stdout);
	cin>>lbound>>ubound>>n;
	while(1){
		cin>>info[++c_total];
		if(info[c_total] == 0x00)break;
		else if(info[c_total] == '\n')continue;
		//else cout<<info[c_total];
	}
	//cout<<c_total<<" characters in total"<<endl;
	for(int i = lbound; i <=ubound;++i){
		process_data(i);
	}
	//cout<<patt_map.size()<<" kinds of patterns detected"<<endl;
	sort(patterns, patterns+patt_map.size(), cmp);
	/*
	for(int i = 0;i<patt_map.size();++i){
		cout<<patterns[i].p_info<<" "<<patterns[i].p_freq<<endl;
	}
	*/
	for(int i = 0;i<patt_map.size();++i){
		if(i==0){
			cout<<patterns[0].p_freq<<endl<<patterns[0].p_info;
			++total_freq_cnt;
			++cur_freq_cnt; 
			continue;
		}
		if(patterns[i].p_freq == patterns[i-1].p_freq){
			if(cur_freq_cnt == 5){
				cout<<" "<<patterns[i].p_info;
				cur_freq_cnt = 0;
			}
			else if(cur_freq_cnt == 0){
				cout<<endl<<patterns[i].p_info;
				++cur_freq_cnt;
			}
			else{
				cout<<" "<<patterns[i].p_info;
				++cur_freq_cnt;
			}
		}
		else{
			cout<<endl;
			if(total_freq_cnt == n) return 0;
			cout<<patterns[i].p_freq<<endl<<patterns[i].p_info;
			++total_freq_cnt;
			cur_freq_cnt = 1;			
		}
	}
	if(total_freq_cnt != n) cout<<endl;
	return 0;
}