class Solution {
public:
    string destCity(vector<vector<string>>& arr) {
        int a = arr.size();
        multimap<string,string>mp;
        for(int i=0;i<a;i++){
            mp.insert({arr[i][0], arr[i][1]});
        }
        for(auto i : mp){
            auto it = mp.find(i.second);
            if(it == mp.end()){
                return i.second;
            }
        }
        return "";
    }
};