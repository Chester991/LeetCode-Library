class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = haystack.size();
        int b = needle.size();

        for(int i=0;i<a;i++){
            string str = haystack.substr(i,b);
            if(str == needle){
                return i;
            }
        }
        return -1;
    }
};