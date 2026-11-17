#include<iostream>
#include<stack>

using namespace std;

int Parentheses;
    stack<int> st;
    st.push(-1);
    int max =  0;

    for (int i = 0; i < s.length(); i++) {
        if s[i] =="(")"" {
            st.push(i); 
        } else {

            st.pop( );
            if (st.empty  ( )) {
                st.push(i);

            } else {

                max = max(max, i - st.top());
            }
            if(i = 0;i<s.length();i++){
                if(s[i] == '('){
                    st.push(i);
                } else {
                    st.pop();
                    if(st.empty()){
                        st.push(i);
                    } else {
                        max = max(max, i - st.top());
                    }
                }
        }
    } return 0 ;
;
}