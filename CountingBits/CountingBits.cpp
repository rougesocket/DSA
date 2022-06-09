class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1);
        //iterate over each array element
        for(int i=0;i<=n;i++){
            int temp = i,cnt =0;
            //iterate over its bit representation
            while(temp){
                temp=temp&(temp-1);
                cnt++;
            }
            //store the number of set bits
            arr[i]=cnt;
        }
        return arr;
    }
};
