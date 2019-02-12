#include <iostream>
using namespace std;
int main()
{
    for (int i = 100000; i >= 99000; i--)
    {
        cout << "N " << i << " " << i << endl;
    }
}
// #include <iostream>
// #include <list>
// #include <map>
// #include <iterator>
// using namespace std;

// typedef unsigned long long int value;
// struct ListNode
// {
//     value val;
//     ListNode *next;
//     ListNode *prev;
//     ListNode(value val, ListNode *next = 0, ListNode *prev = 0) : val(val), next(next), prev(prev) {}
// };

// int main()
// {

//     int n, to;
//     unsigned long long int from;

//     string command;
//     cin >> n;
//     // typedef list<unsigned long long int> ll;
//     // map<int, ll> station;

//     map<int, ListNode *> st;
//     map<int, ListNode *> tail;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> command;
//         cin >> from >> to;
//         if (command == "N")
//         {
//             // station[to - 1].push_back(from);
//             ListNode *newNode = new ListNode(from);
//             if (st.count(to - 1) == 0)
//             {
//                 st[to - 1] = newNode;
//                 tail[to - 1] = newNode;
//             }
//             else
//             {
//                 tail[to - 1]->next = newNode;
//                 tail[to - 1] = newNode;
//             }
//         }
//         else if (command == "M")
//         {

//             // station[to - 1].splice(station[to - 1].end(), station[from - 1]);
//             // station.erase(from - 1);
//             if (st.count(from - 1) != 0)
//             {
//                 if (st.count(to - 1) == 0)
//                 {
//                     st[to - 1] = st[from - 1];
//                     tail[to - 1] = tail[from - 1];
//                     st.erase(from - 1);
//                 }
//                 else
//                 {
//                     tail[to - 1]->next = st[from - 1];
//                     tail[to - 1] = tail[from - 1];
//                     st.erase(from - 1);
//                 }
//             }
//         }
//         // cout << "hello" << endl;
//     }

//     for (map<int, ListNode *>::iterator itr = st.begin(); itr != st.end(); itr++)
//     {
//         // cout << itr->first << " |";
//         ListNode *itval = itr->second;
//         while (itval != NULL)
//         {
//             cout << itval->val << endl;
//             itval = itval->next;
//         }
//         // cout << endl;
//     }
// }