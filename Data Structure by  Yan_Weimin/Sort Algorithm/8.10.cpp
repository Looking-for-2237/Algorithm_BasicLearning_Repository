#include <iostream>
using namespace std;
#define MAXSIZE 20
typedef struct
{
    int key;
    char *otherinfo;
} RedType;
void Create_Sq(RedType *R)
{
    int i, n;
    cout << "Please enter the number of elements (no more than " << MAXSIZE << "):" << endl;
    cin >> n; // input count
    cout << "Please enter the data to be merged:\n";
    while (n > MAXSIZE)
    {
        cout << "Number exceeds the limit, must not exceed " << MAXSIZE << ", please re-enter" << endl;
        cin >> n;
    }
    for (i = 0; i < n; i++)
        cin >> R[i].key;
}
void Merge(RedType R[], RedType T[], int low, int mid, int high)
{
    int i, j, k;
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (R[i].key <= R[j].key)
        {
            T[k++] = R[i++];
        }
        else
        {
            T[k++] = R[j++];
        }
    }
    while (i <= mid)
        T[k++] = R[i++];
    while (j <= high)
        T[k++] = R[j++];
}
void show(RedType *T, int low, int high)
{
    int i;
    for (i = low; i <= high; i++)
        cout << T[i].key << endl;
}
int main()
{
    RedType *R = new RedType[MAXSIZE];
    RedType *T = new RedType[MAXSIZE];
    Create_Sq(R);
    int low, mid, high;
    cout << "Please enter the start index and end index of the first sorted subsequence, and the end index of the second sorted subsequence:\n";
    cin >> low >> mid >> high;
    Merge(R, T, low, mid, high);
    cout << "Merged result:" << endl;
    show(T, low, high);
    return 0;
}