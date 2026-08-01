class Solution {
public:
    string solve(int i , int j , string s){
        
        while(i>=0 && j < s.size()&& s[i]== s[j] ){
            i--;
            j++;
        }
        return s.substr(i+1 , j-i- 1);
    }
    string longestPalindrome(string s) {
        string longest ="";
        for(int i = 0 ;i< s.size() ;i++){
            //if the palindrome is of odd size
            string odd = solve(i ,i , s );
            if(odd.size() > longest.size()){
                longest= odd ; 
            }

            //for even size

            if(i+1 <s.size() && s[i] == s[i+1]){
                string even = solve(i , i+1 ,s);
                if(even.size() > longest.size()){
                    longest= even;
                }
            }
        }
        return longest; 
    }
};
