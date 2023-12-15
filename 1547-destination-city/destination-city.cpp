class Solution {
public:
  string destCity(vector<vector<string>>& paths) {                
        unordered_set<string> hash;
        for(auto e: paths)  
            hash.insert(e[0]);
        for(auto e: paths) 
            if(hash.find(e[1]) == hash.end()) return e[1];             
        return "";
    }
};