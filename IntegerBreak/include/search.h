#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
//最优子结构（子问题的最优解可以得到原问题的最优解）
//重叠子问题，求解问题中有大量重叠
//重叠子问题+最优子结构=动态规划或记忆化搜索
private:
     vector<int> memo;
     int Max(int a,int b,int c){
        return max(a,max(b,c));
     }
    //将n进行分割（至少分割两部分）
    int breakInteger(int n){
       if(n==1) return 1;
       if(memo[n]!=-1) return memo[n];
       int res=-1;
       for(int i=1;i<=n-i;i++){
        res=Max(i*(n-i),i*breakInteger(n-i),res);
       }
       memo[n]=res;
       return res;
    }
public:
    int integerBreak(int n) {
        memo=vector<int>(n+1,-1);
        return breakInteger(n);
    }
};