#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
class soluction{
public:
   int knapsack(const vector<int>& w,const vector<int>& v,int cap){
       assert(w.size()==v.size());
       int n=w.size();
       vector<vector <int>> memo(n,vector <int>(cap+1,-1));
       //自底向上
       for(int j=0;j<=cap;j++){
           memo[0][j]=(j>=w[0]?v[0]:0);
       }
       for(int i=1;i<n;i++){
        for(int j=0;j<=cap;j++){
            memo[i][j]=memo[i-1][j];
            if(j>=w[i]){
                memo[i][j]=max(memo[i][j],v[i]+memo[i-1][j-w[i]]);
            }
        }
       }
       return memo[n-1][cap];
   }
};