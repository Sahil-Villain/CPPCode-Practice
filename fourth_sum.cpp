#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1])continue;
                int st=j+1,end=n-1;
                while(st<end){
                    long long int sum=(long long)nums[i]+nums[j]+nums[st]+nums[end];
                    if(target==sum){
                        ans.push_back({nums[i],nums[j],nums[st],nums[end]});
                        while(st<end && nums[st]==nums[st+1]){
                            st++;
                        }
                        while(st<end && nums[end]==nums[end-1]){
                            end--;
                        }
                        st++;
                        end--;
                    }
                    else if(target>sum){
                        st++;
                    }else{
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution obj;
    vector<int> val = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = obj.fourSum(val, 0);
    for(const auto&i:result){
        for(int j:i){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
