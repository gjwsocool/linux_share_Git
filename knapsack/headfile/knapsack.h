#include<vector>
using namespace std;
class soluction{
private:
   vector<int> w;
   vector<int> v;
   vector<vector<int>> memo;
   int bestValue(int index,int c){
        //递归结束条件---物品没了，容量没了
        if(index<0||c<=0) return 0;
        if(memo[index][c]!=-1) return memo[index][c];//已经遍历过啦
        int res=bestValue(index-1,c);//不取商品index
        if(w[index]<=c){
            //取了index商品
            res=max(res,v[index]+bestValue(index-1,c-w[index]));
        }
        memo[index][c]=res;//记录
        return res;
   }
public:
   int knapsack(const vector<int>& w,const vector<int>& v,int capcity){
       this->w=w;
       this->v=v;
       int n=w.size();
       //memo[i][j]----当前i个物品，背包容量为j
       //i的上限n-1;j的上限capcity
       memo=vector<vector<int>>(n,vector<int>(capcity+1,-1));
       return bestValue(n-1,capcity);
   }
};