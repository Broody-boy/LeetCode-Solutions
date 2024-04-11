class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size() == k) return "0";
        
        stack<char> st;

        for(auto c : num){

            while(!st.empty() && st.top() > c && k){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k && !st.empty()){

            st.pop();
            k--;
        }

        string ans ;
        while(!st.empty()){

            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        int zeros = 0 ;

        while(ans[zeros] == '0'){
            zeros++;
        }

        ans =  ans.substr(zeros);

        if (ans == "") return "0";

        return ans;
    }
};