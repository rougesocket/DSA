class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
    	//cnt is basically the number of times we need to shift number to left or the part which is changing
        int cnt =0;
        //we increase the count and shift right.untill both number becomes equal.  
        while(left!=right){
            cnt++;
            left>>=1;
            right>>=1;
        }
        //once we have common part it will have same value in left and right we use left variable here and left shift it by the value held by cnt variable 
        left<<=cnt;
        return left;
    }
};
