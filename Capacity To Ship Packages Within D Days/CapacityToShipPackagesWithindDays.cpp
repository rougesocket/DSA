class Solution {
public:
    bool good(vector<int> & weights,int k,int days){
        int n = weights.size(),ans=0,curr=0;
		//iterating and counting days to ship package
        for(int i=0;i<n;i++){
        	//if we cannot accomodate the current element we have to ship it from other ship that marks completion of one day so we decrement the count
            if(curr+weights[i]>k){
                days--;
                curr=weights[i];
                continue;
            }
            curr+=weights[i];
        }
        if(curr<=k)days--;
        //if we have still days left or it is exactly zero we have a good capacity
        return days>=0;
    }
    int shipWithinDays(vector<int>& weights, int days) {
    	/*see notes.txt for detailed explanation*/
        int n = weights.size(),l=0,r=0;
        for(int i=0;i<n;i++){
            r+=weights[i];
            l=max(l,weights[i]);
        }
        //performing binary search
        while(l<r){
            int mid = l+(r-l)/2;
            if(good(weights,mid,days)){
                r=mid;
            }
            else l=mid+1;
        }
        //since the right pointer which will contain the answer
        return r;
    }
};
