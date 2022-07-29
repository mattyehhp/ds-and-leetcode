class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i++) {
            if (hashtable.find(target-nums[i]) != hashtable.end()) {
                return {i, hashtable[target-nums[i]]};
            } else {
                hashtable[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};