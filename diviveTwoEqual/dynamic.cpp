#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
       int sum=0;
       int n=nums.size();
       for(int i=0;i<n;i++) sum+=nums[i];
       if(sum%2) return false;//sum不能平分一定无法满足题意
       //memo[编号][容量]-----返回结果memo[n-1][sum/2]
       int c=sum/2;
       vector<bool>memo(c+1,false);
       //开始计算
       for(int i=0;i<=c;i++) //第一个物品是否能填满
           memo[i]=(nums[0]==i);
        for(int i=1;i<n;i++)
           for(int j=c;j>=nums[i];j--)
              memo[j]=memo[j]||memo[j-nums[i]];
       return memo[c];
    }
};
int main(){
    vector<int> nums1={1,3,6,2,4};//1+3+4=6+2
    vector<int> nums2={1,3,3,4};//11无法平分
    cout<<Solution().canPartition(nums1)<<endl;
    cout<<Solution().canPartition(nums2)<<endl;
    return 0;
}