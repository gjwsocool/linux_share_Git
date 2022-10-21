#include<vector>
using namespace std;
class soluction{
public:
    int knapsack_single(const vector<int>& w,const vector<int>& v,int c){
        int n=w.size();
        vector<int>memo(c+1,-1);//只记录容量
        for(int j=0;j<=c;j++)
            memo[j]=(w[0]<=j?v[0]:0);
        for(int i=1;i<n;i++)
           for(int j=c;j>=w[i];j--)//从后往前编号
            if(w[i]<=j){
                memo[j]=max(memo[j],v[i]+memo[j-w[i]]);
            }
        return memo[c];
    }
};