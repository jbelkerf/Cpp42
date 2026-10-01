#include "RPN.hpp"
#include <stack>

RPN::RPN(std::string s){
    int val = 0;
    int val1,val2;
    for (int i = 0; s[i] != 0;i++){
        if (s[i] >= '0' && s[i] <= '9')
            st.push(s[i] - '0');
        else if (s[i] == '+' && st.size())
        {
            val1 = st.top();
            st.pop();
            val2 = st.top();
            st.pop();
            val = val2 + val1;
            st.push(val);
        }
        else if (s[i] == '*' )
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            val = val2 * val1;
            st.push(val);

        }
        else if (s[i] == '-' )
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            val = val2 - val1;
            st.push(val);

        }
        else if (s[i] == '/' )
        {
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();
            if (val1 == 0)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            val = val2 / val1;
            st.push(val);

        }
        else if (s[i] != ' ' && s[i] != '\0')
        {
            //? print to stderr
            std::cout << "Error" << std::endl;
            return;
        }

    }
    std::cout << val << std::endl;
}