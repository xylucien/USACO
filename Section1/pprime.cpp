/*
ID: xinyu.l1
TASK: pprime
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int a;
void test_prime(int x){
    int lim = int(sqrt(x));
    for(int i = 2;i<=lim;i++){
        if(x%i==0)return;
    }
    cout<<x<<endl;
    return;
}

void generate_until_the_end(int max,int p){
    if(p==3){
    bool flag = false;
    int d1,d2;
    for (d1 = 1; d1 <= 9; d1+=2) {
        if(flag)break;
        for (d2 = 0; d2 <= 9; d2++) {
            int pn = 100*d1 + 10*d2 + d1;
            if(pn > max){flag = true;break;}
            if(pn < a){continue;}
            test_prime(pn);
        
    }}if(!flag){generate_until_the_end(max,p+1);}}
    if(p==4){
    bool flag = false;
    int d1,d2;
    for (d1 = 1; d1 <= 9; d1+=2) {
        if(flag)break;
        for (d2 = 0; d2 <= 9; d2++) {
            int pn = 1000*d1 + 100*d2 + 10*d2+ d1;
            if(pn > max){flag = true;break;}
            test_prime(pn);    
    }}if(!flag){generate_until_the_end(max,p+1);}}
    if(p==5){
        int d1,d2,d3;
        bool flag = false;
        for (d1 = 1; d1 <= 9; d1+=2) {
            if(flag)break;
            for (d2 = 0; d2 <= 9; d2++) {
                if(flag)break;
                for (d3 = 0; d3 <= 9; d3++) {
                    int pn = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;
                    if(pn > max){flag = true;break;}
                    if(pn < a){continue;}
                    test_prime(pn);
         }
     }
 }if(!flag){generate_until_the_end(max,p+1);}
    }
    if(p==6){
        int d1,d2,d3;
        bool flag = false;
        for (d1 = 1; d1 <= 9; d1+=2) {
            if(flag)break;
            for (d2 = 0; d2 <= 9; d2++) {
                if(flag)break;
                for (d3 = 0; d3 <= 9; d3++) {
                    int pn = 100000*d1 + 10000*d2 + 1000*d3 + 100*d3+ 10*d2 + d1;
                    if(pn > max){flag = true;break;}
                    if(pn < a){continue;}
                    test_prime(pn);
    }}}if(!flag){generate_until_the_end(max,p+1);}}
    if(p==7){
        int d1,d2,d3,d4;
        bool flag = false;
        for (d1 = 1; d1 <= 9; d1+=2) {
            if(flag)break;
            for (d2 = 0; d2 <= 9; d2++) {
                if(flag)break;
                for (d3 = 0; d3 <= 9; d3++) {
                    if(flag)break;
                    for(d4=0;d4<=9;d4++){
                    int pn = 1000000*d1 + 100000*d2 + 10000*d3 + 1000*d4+ 100*d3 + 10*d2 + d1;
                    if(pn > max){flag = true;break;}
                    if(pn < a){continue;}
                    test_prime(pn);
    }}}}if(!flag){generate_until_the_end(max,p+1);}}
    if(p==8){
                int d1,d2,d3,d4;
        bool flag = false;
        for (d1 = 1; d1 <= 9; d1+=2) {
            if(flag)break;
            for (d2 = 0; d2 <= 9; d2++) {
                if(flag)break;
                for (d3 = 0; d3 <= 9; d3++) {
                    if(flag)break;
                    for(d4=0;d4<=9;d4++){
                    int pn = 10000000*d1 + 1000000*d2 + 100000*d3 + 10000*d4+ 1000*d4 + 100*d3+ 10*d2 + d1;
                    if(pn > max){flag = true;break;}
                    if(pn < a){continue;}
                    test_prime(pn);
    }}}}
    if(!flag){generate_until_the_end(max,p+1);}
    }
    if(p==9){
                        int d1,d2,d3,d4,d5;
        bool flag = false;
        for (d1 = 1; d1 <= 9; d1+=2) {
            if(flag)break;
            for (d2 = 0; d2 <= 9; d2++) {
                if(flag)break;
                for (d3 = 0; d3 <= 9; d3++) {
                    if(flag)break;
                    for(d4=0;d4<=9;d4++){
                        if(flag)break;
                        for(d5=0;d5<=9;d5++){
                            int pn = 100000000*d1 + 10000000*d2 + 1000000*d3 + 100000*d4+ 10000*d5+ 1000*d4 + 100*d3+ 10*d2 + d1;
                            if(pn > max){flag = true;break;}
                            if(pn < a){continue;}
                            test_prime(pn);
    }}}}}
    }
}
int main(){

    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);

    int b;
    cin>>a>>b;

    if(a==5){cout<<5<<endl;cout<<7<<endl;cout<<11<<endl;}
    else if(a<=7){cout<<7<<endl;cout<<11<<endl;}
    else if(a<=11)cout<<11<<endl;
    
    generate_until_the_end(b,3);
    return 0;
}