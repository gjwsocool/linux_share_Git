#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int rob(vector<int> &nums) {
        int n=nums.size();
        /*memo[i]:nums[i,....,n-1]的最大收益*/
        vector<int> memo(n,-1);
        //注意：起点应该是memo[n-1]
        memo[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){//计算memo
            for(int j=i;j<n;j++)
               memo[i]=max(memo[i],nums[j]+(j+2<n ?memo[j+2]:0));
        }
        return memo[0];
    }
};
int main(){
    vector<int> mm={9,2,5,8,4,33,4};
    cout<<Solution().rob(mm)<<endl;
    return 0;
}