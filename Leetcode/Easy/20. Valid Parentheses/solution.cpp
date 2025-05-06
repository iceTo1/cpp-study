class Solution {
    public:
        bool isValid(string s) 
        {
            std::stack<char> prnths;
            for (const char& c : s)
            {
                if (c == '(')
                    prnths.push('(');
                else if (c == '{')
                    prnths.push('{');
                else if (c == '[')
                    prnths.push('[');
                else if (c == ')')
                {
                    if (prnths.empty() || ('(' != prnths.top()))
                        return false;
                    else
                         prnths.pop();
                }
                else if (c == '}')
                {
                    if (prnths.empty() || ('{' != prnths.top()))
                        return false;
                    else
                         prnths.pop();
                }
                else if (c == ']')
                {
                   if (prnths.empty() || ('[' != prnths.top()))
                        return false;
                    else
                         prnths.pop();
                }
            }
    
            return prnths.empty();
        }
    };