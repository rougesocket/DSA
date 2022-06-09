class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	//initilizing array to hold count of set bits
        vector<int> arr(32,0);
        int ans = 0,n=nums.size();
        //iterating over each array elements
        for(int i=0;i<n;i++){
        	//iterating over its bit representation and checking to see if there is a set bit or not if it has set bit the updating its count in array
            for(int j=0;j<32;j++){
                if(nums[i]&1)arr[j]++;
                nums[i]>>=1;
            }
        }
        //iterating over arr to set those bits that appear more than n/2
        for(int i=0;i<32;i++){
            if(arr[i]>n/2)ans|=1<<i;
        }
        return ans;
    }
};
