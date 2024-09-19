class Solution {
public: 
    map <string , vector <int>> memo ;
    vector<int> diffWaysToCompute(string expression) {
        vector <int>result; 
        if(memo.find(expression) !=memo.end()){
            return memo[expression] ; 
        }
        for (int i = 0 ; i < expression.size() ; i++){
            char c =expression[i]  ; 
            if ( c=='+' || c=='-' || c=='*'){
                vector <int> left = diffWaysToCompute(expression.substr(0,i)) ; 
                vector <int> right =diffWaysToCompute( expression.substr(i+1 )   ) ; 
            
            for (auto num1 : left){
                for (auto num2 : right){
                    if (c == '-'){
                        result.push_back(num1-num2) ; 
                    }else if (c=='+'){
                        result.push_back(num1+num2) ;
                    }else {
                        result.push_back(num1*num2) ; 
                    }
                }
            }                        
            }
        }
        if (result.empty()){
            result.push_back(stoi(expression)) ; 
        }
        memo[expression]=result ;
        return result ;
    }
};