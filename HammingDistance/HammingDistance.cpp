class Solution {
public:
    int hammingDistance(int x, int y) {
    	//taking xor to identify different bit position in a number
        x=x^y;
        int ans=0;
        //counting set bit in the number
        while(x){
            x=x&(x-1);
            ans++;
        }
        return ans;
    }
};
