class Solution {
public:
    int countCharacters(vector<string>& arr, string chars) {
        int n = arr.size();
        unordered_map<char,int>mp;
        for(auto i : chars){
            mp[i]++;
        }
        int count = 0;
        for(int i=0;i<n;i++){
            string str = arr[i];
            unordered_map<char,int>temp = mp;
            bool possible = true;
            for(int j=0;j<str.size();j++){
                auto it = temp.find(str[j]);
                if(it == temp.end()){
                    possible = false;
                    break;
                }
                if(temp[str[j]] == 0){
                    possible = false;
                    break;
                }
                temp[str[j]]--;
            }
            if(possible){
                count+=str.size();
            }
        }
        return count;
    }
};