class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1) return;
        k = k%nums.size();
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin(),nums.end());
    }
};
