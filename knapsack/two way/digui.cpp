#include<iostream>
#include<vector>
using namespace std;
class soluction{
private:
   vector<int> w;
   vector<int> v;
   vector<vector<int>> memo;
   int bestvalue(int index,int c){
        if(index<0||c<=0) return 0;
        if(memo[index][c]!=-1) return memo[index][c];
        int res=bestvalue(index-1,c);
        if(w[index]<=c){
         res=max(res,v[index]+bestvalue(index-1,c-w[index]));
        }
        memo[index][c]=res;
        return res;
   }
public:
   int knapsack(const vector<int>& w,const vector<int>& v,int c){
        this->w=w;
        this->v=v;
        int n=w.size();
        memo=vector<vector<int>>(n,vector<int>(c+1,-1));
        return bestvalue(n-1,c);
   }
};
int main(){
   vector<int> w={10,20,30,40,50,60};
   vector<int> v={1,3,5,7,9,11};
   int capcity=120;
   cout<<soluction().knapsack(w,v,capcity)<<endl;
   return 0;
}