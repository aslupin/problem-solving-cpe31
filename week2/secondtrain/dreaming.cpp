#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string a, b;
    stack<int> ans;
    cin >> a >> b;
    int carry = 0;
    int len_a = a.length() - 1;
    int len_b = b.length() - 1;
    int max_length = (len_a >= len_b) ? len_a + 1 : len_b + 1; //plus 1 for string one length => get loop
    // cout << max_length;
    for (int i = 0; i < max_length; i++)
    {
        if (len_a - i >= 0 && len_b - i >= 0)
        {
            int int_a = (int)a[len_a - i] - 48;
            int int_b = (int)b[len_b - i] - 48;
            int result = int_a + int_b + carry;
            ans.push(result % 10);
            carry = result / 10;
        }
        else
        {
            if (len_a - i < 0)
            {
                int result = ((int)b[len_b - i] - 48 + carry);
                ans.push(result % 10);
                carry = result / 10;
            }
            else if (len_b - i < 0)
            {
                int result = ((int)a[len_a - i] - 48 + carry);
                ans.push(result % 10);
                carry = result / 10;
            }
        }
        if (i == max_length - 1 && carry != 0)
        {
            ans.push(carry);
        }
    }
    while (!ans.empty())
    {

        cout << ans.top();
        ans.pop();
    }
}