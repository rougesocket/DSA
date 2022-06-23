class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        //sorting the array to use two pointer
        sort(nums.begin(),nums.end());
        vector<vector<int> > ans;
        //itearting over all the n-2 elements since size is 3 of array
        for(int i=0;i<n-2;i++){
        	//detecting duplicate to avoid set in solution
            if(i!=0 &&  nums[i]==nums[i-1])continue;
            //intializing pointers
            int l = i+1;
            int r = n-1;
            //till both pointer do not cross each other
            while(l<r){
            	//compute the sum
                int exp =nums[i]+nums[l]+nums[r];
                if(exp==0){
                	//it statisfies our condition add it to ans
                    ans.push_back({nums[i],nums[l],nums[r]});
                    //since we need to skip all the instance as it will create a duplicate triplet
					while(l<r && nums[l]==nums[l+1])l++;
                    //since we need to skip all the instance of same number as it will create duplicate triplet and we need to till our pointers haven't meet because once we
                    //l>r we are not in a valid state so we check everytime we enter into the loop
                    while(l<r && nums[r]==nums[r-1])r--;
                    l++;
                    r--;
                }
                //if sum is greater we need to reduce it so decrement the right pointer
                else if(exp>0)r--;
                //if sum is less we need to make it larger so we increment left pointer
                else l++;
            }
        }
        return ans;
    }
};
