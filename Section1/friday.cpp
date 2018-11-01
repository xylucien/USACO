/*
ID: xinyu.l1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int days[7];
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int calc_year(int year, int day){
	int temp = (day == 0 || day == 1)?(day+5):(day-2);
	if(year%4 == 0){
		if(year%400 == 0 || year%100 != 0){
			++month[1];
			for(int i = 0;i<12;++i){
				++days[temp];
				temp += month[i]%7;
				temp%=7;
			}
			--month[1];
			return (day == 6 || day == 5)?(day-5):(day+2);
		}
	}

	for(int i = 0;i<12;++i){
		++days[temp];
		temp += month[i]%7;
		temp%=7;
	}
	return (day == 6)?0:(day+1);

}

int main(int argc, char const *argv[])
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);

	int n;
	cin>>n;
	int year = 1900;
	int start_day = 0;
	while(n>0){
		start_day = calc_year(year,start_day);
		++year;
		--n;
	}

	cout<<days[5]<<" "<<days[6]<<" "<<days[0]<<" "<<days[1]<<" "<<days[2]<<" "<<days[3]<<" "<<days[4]<<endl;
	return 0;
}