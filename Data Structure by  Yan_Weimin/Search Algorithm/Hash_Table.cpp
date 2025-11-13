// Hash table search using linear probing for collision resolution.
#include <iostream>
using namespace std;
#define m 16
#define NULLKEY -1 // Marker for empty cell
struct HashTable
{
    int key;
};
int H(int key)
{
    int result;
    result = key % 13;
    return result;
}
int SearchHash(HashTable HT[], int key)
{
    int H0 = H(key);
    int Hi;
    if (HT[H0].key == NULLKEY)
        return -1;
    else if (HT[H0].key == key)
        return H0;
    else
    {
        for (int i = 1; i < m; ++i)
        {
            Hi = (H0 + i) % m;
            if (HT[Hi].key == NULLKEY)
                return -1;
            else if (HT[Hi].key == key)
                return Hi;
        }
        return -1;
    }
}
int main(void)
{
    int result;
    int a[16] = {-1, 14, 1, 68, 27, 55, 19, 20, 84, 79, 23, 11, 10, -1, -1, -1};
    /* Array a is the final state of a hash table that has been constructed using
       linear probing */
    HashTable HT[m];
    for (int i = 0; i < 16; i++)
    {
        HT[i].key = a[i];
    }
    result = SearchHash(HT, 55);
    if (result != -1)
    {
        cout << "Found at position " << result << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }
    return 0;
}
