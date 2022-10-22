#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    //从[index,n-1]的物品中，选择装入当前容量为c的背包
    bool tryPartition(vector<int>& nums,int index,int c) {
       //递归结束条件
       if(c==0) return true;//背包容量为0，说明装满了
       //没物品可选了或者容量过了---结束
       if(c<0||index>=nums.size()) return false;
       /*进行选择*/
       return tryPartition(nums,index+1,c)||//不选该物品
              tryPartition(nums,index+1,c-nums[index]);//选了该物品
    }
public:
    bool canPartition(vector<int>& nums) {
       //首先计算出和sum
       int sum=0;
       for(int i=0;i<nums.size();i++) sum+=nums[i];
       //sum不能平分一定无法满足题意
       if(sum%2) return false;
       return tryPartition(nums,0,sum/2);
    }
};
int main(){
    vector<int> nums1={1,3,6,2,4};//1+3+4=6+2
    vector<int> nums2={1,3,3,4};//11无法平分
    cout<<Solution().canPartition(nums1)<<endl;
    cout<<Solution().canPartition(nums2)<<endl;
    return 0;
}