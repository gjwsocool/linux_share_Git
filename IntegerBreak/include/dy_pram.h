#include<vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n+1,-1);
        memo[1]=1;
        for(int i=2;i<=n;i++)
        //求解memo[i]ma
            for(int j=1;j<=i-1;j++){
                //把i分割成j和i-j两部分
                memo[i]=max(memo[i],max(j*(i-j),j*memo[i-j]));
            }
        return memo[n];
    }
};