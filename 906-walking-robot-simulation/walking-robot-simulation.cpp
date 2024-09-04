class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dx={0,1,0,-1};
        vector<int> dy={1,0,-1,0};
        int maxi = 0 ;
        int x = 0 , y = 0 , direction = 0 ; 
        set<pair<int,int>>st ; 
        for(auto it : obstacles){
            st.insert({it[0],it[1]}) ;
        }
        int idx = 0 ; 
        for(auto it: commands){
            if(it==-2){
                direction = (direction+3)%4 ; 
            }
            if(it==-1){
                direction = (direction+1)%4 ; 
            }
            else{
                int k = it ; 
                while(k>0){
                    int new_X = x + dx[direction] ; 
                    int new_Y = y + dy[direction] ; 
                    if(st.find({new_X,new_Y})==st.end()){
                        x = new_X ;
                        y = new_Y;
                        maxi = max(maxi , (x*x + y*y)) ;  
                    }
                    k--;
                }
            }
        }
        return maxi ; 
    }
};