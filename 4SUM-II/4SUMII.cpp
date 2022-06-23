class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int ans = 0;
        //declaring map to store sum and its corresponding count
		unordered_map<int,int> ump;
		//itearting over pairs and updating their count in map
        for(int &p : nums3){
            for(int &q: nums4){
                ump[p+q]++;
            }
        }
        
        //iterating over all pairs and finding the negative pairs count and updating it into ans
        for(int &x : nums1){
            for(int &y: nums2){
                if(ump.find(-(x+y))!=ump.end())ans+=ump[-(x+y)];
            }
        }
        
        return ans;
    }
};
