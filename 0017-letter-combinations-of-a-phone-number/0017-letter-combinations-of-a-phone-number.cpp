class Solution {
public:
    vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void backtrack(string &digits,int index,vector<string> &result,string &ans){
        if(index==digits.size()){
            result.push_back(ans);
            return;
        }
        for(auto ch:map[digits[index]-'0']){
            ans.push_back(ch);
            backtrack(digits,index+1,result,ans);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits=="")
            return result;
        string ans;
        backtrack(digits,0,result,ans);
        return result;        
    }
};