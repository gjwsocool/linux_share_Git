#include"soluction.h"
#include<iostream>
using namespace std;
int main(){
    vector<int> w={1,2,3,4,5};
    vector<int> v={1,3,5,7,9};
    int c=10;
    cout<<soluction().knapsack_single(w,v,c)<<endl;;
    return 0;
}