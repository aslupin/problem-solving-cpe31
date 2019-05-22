

#include <iostream>

using namespace std;
int inversion = 0;
void Merge(int *A, int *L, int leftCound, int *R, int rightCount)
{
    inversion++;
    int i = 0, j = 0, k = 0;
    while (i < leftCound && j < rightCount)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            inversion++;
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < leftCound)
        A[k++] = L[i++];
    while (j < rightCount)
        A[k++] = R[j++];
}

void MergeSort(int *A, int n)
{

    if (n < 2)
        return;
    int mid = n / 2;
    int *L = new int[mid];
    int *R = new int[n - mid];
    for (int i = 0; i < mid; i++)
        L[i] = A[i];
    for (int i = mid; i < n; i++)
        R[i - mid] = A[i];

    MergeSort(L, mid);
    MergeSort(R, n - mid);
    Merge(A, L, mid, R, n - mid);
    delete (L);
    delete (R);
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int i, numberOfElements;

    numberOfElements = sizeof(A) / sizeof(A[0]);

    MergeSort(A, numberOfElements);

    cout << inversion - 1;

    return 0;
}