class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n= nums.size(),ans=nums[0];
        //iterating and find xor as per the approach in the notes
	for(int i=1;i<n;i++)ans^=nums[i];
        return ans;
    }
};
