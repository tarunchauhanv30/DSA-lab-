#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestParentheses(string s) {
    stack<int> st;
    st.push(-1);

    int maxLength = 0;
    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            } 
            else {
                maxLength = max(maxLength, i - st.top());
            }
        }
    }
return maxLength;
}

int main() {
string s= "()())";
cout << longestParentheses(s) << endl;

return 0;
}