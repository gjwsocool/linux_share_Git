//#include"knapsack.h"
#include"kn_dynasmic.h"
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> w={10,20,30,40,50};
    vector<int> v={30,50,70,90,110};
    int capcity=100;
    cout<<soluction().knapsack(w,v,capcity)<<endl;
    return 0;
}