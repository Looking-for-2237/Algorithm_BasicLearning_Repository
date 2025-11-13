#include <iostream>
#include <cstring>
using namespace std;

int *build_next(char *pattern_string)
{
    int pLength = strlen(pattern_string), input_val_pioneer = 0;
    int *next = new int[pLength];
    int latter_iteration = next[0] = -1;
    while (input_val_pioneer < pLength - 1)
    {
        if (latter_iteration < 0 || pattern_string[latter_iteration] == pattern_string[input_val_pioneer])
        {
            ++latter_iteration;
            ++input_val_pioneer;
            next[input_val_pioneer] = latter_iteration;
        }
        else
            latter_iteration = next[latter_iteration];
    }
    return next;
}

int match(char *text, char *pattern_string)
{
    int *next = build_next(pattern_string);
    int tLength = (int)strlen(text), rank_of_text = 0;
    int pLength = (int)strlen(pattern_string), rank_of_pattern = 0;
    while ((rank_of_text < tLength) && (rank_of_pattern < pLength))
    {
        if (rank_of_pattern < 0 || text[rank_of_pattern] == pattern_string[rank_of_text])
        {
            ++rank_of_text;
            ++rank_of_pattern;
        }
        else
            rank_of_pattern = next[rank_of_pattern];
    }
    delete[] next;
    return rank_of_text - rank_of_pattern;
}

int main(void)
{
    char text[] = "acabaabaabcacaabc";
    char pattern[] = "aabcac";
    int matched_index = match(text, pattern);
    cout << "Mached index is " << matched_index;
}