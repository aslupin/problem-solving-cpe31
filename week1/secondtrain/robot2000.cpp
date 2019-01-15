#include <iostream>
#include <string>
using namespace std;

// "F",    // NN SS EE WW
// "RRRF", // SE WS NW EN
// "RRF",  // WE NS EW SN
// "RF",   // NE ES SW WN

int main()
{

    string ns_walk[4] = {"F", "RRRF", "RRF", "RF"};
    string walked;
    string new_walk = "";
    cin >> walked;
    char prev_state = 'N';
    for (int i = 0; i < walked.length(); i++)
    {
        if (walked[i] == 'Z')
        {
            prev_state = 'N';
            new_walk += 'Z';
        }
        else if ((prev_state == 'N' && walked[i] == 'E') ||
                 (prev_state == 'E' && walked[i] == 'S') ||
                 (prev_state == 'S' && walked[i] == 'W') ||
                 (prev_state == 'W' && walked[i] == 'N'))
        {
            prev_state = walked[i];
            new_walk += ns_walk[3]; // RF
        }
        else if ((prev_state == 'W' && walked[i] == 'E') ||
                 (prev_state == 'N' && walked[i] == 'S') ||
                 (prev_state == 'E' && walked[i] == 'W') ||
                 (prev_state == 'S' && walked[i] == 'N'))
        {
            prev_state = walked[i];
            new_walk += ns_walk[2]; // RRF
        }
        else if ((prev_state == 'S' && walked[i] == 'E') ||
                 (prev_state == 'W' && walked[i] == 'S') ||
                 (prev_state == 'N' && walked[i] == 'W') ||
                 (prev_state == 'E' && walked[i] == 'N'))
        {
            prev_state = walked[i];
            new_walk += ns_walk[1]; // RRRF
        }
        else
        {
            prev_state = walked[i];
            new_walk += ns_walk[0]; // F
        }
    }
    cout << new_walk;
}
