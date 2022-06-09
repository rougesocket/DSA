class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        //iterating over all 32 bit of a number
        for(int i=0;i<32;i++){
        	//initializing count to count number of set bit at a particular position and val is used to hold the mask at ith position
            int cnt = 0,val = 1<<i;;
            //iterating over each number in array and checking if it has ith bit set or not the increasing count according
            for(int x : nums){
                if(x&(val))cnt++;
            }
            //checking if the number if not a multiple of three so as to include it in ans as discussed in notes.
            if(cnt%3)ans|=val;
        }
        return ans;
    }
};
