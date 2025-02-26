class Solution {
public:
    int maxScore(string str) {
        int n = str.size();
        int count0=0,count1=0;
        if(str[0] == '0'){
            count0++;
        }
        for(int i=1;i<n;i++){
            if(str[i] == '1'){
                count1++;
            }
        }
        int ans = count0 + count1;
        int mxans = ans;
        int w = 1;
        while(w<n-1){
            if(str[w] == '0'){
                count0++;
            }
            if(str[w] == '1'){
                count1--;
            }
            w++;
            ans = count0 + count1;
            mxans = max(mxans,ans);
        }
        return mxans;
    }
};