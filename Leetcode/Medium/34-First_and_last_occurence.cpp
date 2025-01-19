class Solution {
public:
    int findFirst(vector<int> nums, int target){
        int low = 0, high = nums.size()-1;
        int first = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return first;
    }

    int findLast(vector<int> nums, int target){
        int low = 0, high = nums.size()-1;
        int last = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                last = mid;
                low = mid+1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(findFirst(nums,target));
        res.push_back(findLast(nums,target));
        return res;
    }
};
