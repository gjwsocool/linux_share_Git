#include<iostream>
#include<vector>
using namespace std;
class soluction{
public:
   int knapsack(const vector<int>& w,const vector<int>& v,int c){
        int n=w.size();
        vector<vector<int>>memo(n,vector<int>(c+1,-1));
        //i-----商品编号 j-----容量
        for(int j=0;j<=c;j++)
           memo[0][j]=(w[0]<=j?v[0]:0);//商品0，比较w[0]和容量j,累计v[0]
        for(int i=1;i<n;i++)
           for(int j=0;j<=c;j++){
             memo[i][j]=memo[i-1][j];
             if(w[i]<=j){//w[i]---商品i重量；j---容量
             memo[i][j]=max(memo[i][j],v[i]+memo[i-1][j-w[i]]);
             }
           }
        return memo[n-1][c];
   }
};
int main(){
   vector<int> w={10,20,30,40,50,60};
   vector<int> v={1,3,5,7,9,11};
   int capcity=120;
   cout<<soluction().knapsack(w,v,capcity)<<endl;
   return 0;
}