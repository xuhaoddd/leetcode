// there are bugs in this code

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        if(nums.empty()) return result;
        int flag=0;
        for(int i=0;i<nums.size();i++)
            if(nums[i]!=0) flag=1;
        vector<vector<int>> ilist = {{0,0,0}};
        if(flag==0){
            return ilist;
        }
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        result.push_back(tmp);
                        tmp.clear();
                    }
                }
        for(int i=0;i<result.size();i++){
            sort(result[i].begin(),result[i].end());
        }
        for(int i=0;i<result.size();i++)
        for(int j=i+1;j<result.size();j++)
        if(result[i]==result[j]) result.erase(result.begin()+j);
        return result;
    }
};