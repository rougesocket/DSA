#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
     
        int n = nums.size();
        //sorting it to have order inorder to decide which pointer to move
        sort(nums.begin(),nums.end());
        //hold only unique arrays
        set<vector<int> > st;
        //iterating over first array
        for(int i=0;i<n-3;i++){
        	//iterating over second array
            for(int j=i+1;j<n-2;j++){
                //setting two pointers
				int  start = j+1;
                int end = n-1;
                while(start<end){
                	//computing the sum
                    ll exp = (ll)nums[i]+(ll)nums[j]+(ll)nums[start]+(ll)nums[end];
                    if(exp>target){
                    	//decrementing the pointer since our sum has exceeded the target so we want some lower values and since it is sorted we can get lower values by decrementing
                        end--;
                    }
                    //incrementing pointer since our sum is less than the target so we want some higher values so that we can reach the sum value
                    else if(exp<target)start++;
                    else{
                    	//we land here when we have equal to target we store the values and decrement the both pointer as we want to find other sum values
                        st.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++;
                        end--;
                    }
                }
            }
        }
        //creating vector to return ans
        vector<vector<int> > ans{st.begin(),st.end()};
        return ans;
    }
};
