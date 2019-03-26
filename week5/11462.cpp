#include <stdio.h>
// #include <vector>
using namespace std;

void ms(int container[], int low, int high)
{
    if (low < high)
    {
        ms(container, low, (low + high) / 2);
        ms(container, ((low + high) / 2) + 1, high);

        int c_i[(low + high) / 2 + 1];
        int c_ii[high - ((low + high) / 2 + 1)];
        for (int i = 0; i < (low + high) / 2 + 1; i++)
            c_i[i] = container[low + i];
        for (int i = 0; i < high - ((low + high) / 2 + 1); i++)
            c_ii[i] = container[i + ((low + high) / 2 + 1)];
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    int n;
    // vector<int> ans;
    do
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        int container[n];
        for (int i = 0; i < n; i++)
            scanf("%d", &container[i]);
        // cin >> container[i];

        ms(container, 0, n - 1);

        for (int i = 0; i < n; i++)
            printf("%d ", container[i]);
        // cout << container[i] << " ";
        printf("\n");
    } while (1);
}