class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;

        for(int x: nums){
            mp[x]++;
        }
        int n =nums.size();
        vector<vector<int>>bucket(n+1);
        for(auto it : mp){
            int size= it.second;
            bucket[size].push_back(it.first);
        }
        vector<int>ans;
        for(int i = n ; i>=1 && ans.size()<k ;i--){
           for(int num:bucket[i]){
            ans.push_back(num);
           }
           if(ans.size() == k)break;
        }
        return ans ;
    }
};
