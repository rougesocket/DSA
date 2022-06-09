class Solution {
public:
    int hammingDistance(int x, int y) {
    	//finding xor so that we get the bit position that are different
        x=x^y;
        int ans=0;
        //finding number of set bits count
        while(x){
            x=x&(x-1);
            ans++;
        }
        return ans;
    }
};
