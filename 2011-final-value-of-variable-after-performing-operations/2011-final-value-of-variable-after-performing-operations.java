class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int X = 0;
        for(String str : operations){
            if(str.contains("--")){
                X--;
            }
            else{
                X++;
            }
        }
        return X;
    }
}