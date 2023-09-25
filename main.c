#include <stdio.h>
#include <stdbool.h>

bool verify_word(char** word);

int main(int argc, char** argv)
{
    char word[20];

    printf("\nAnagram Solver");
    printf("\nEnter a word > ");
    scanf("%s", &word);

    printf("\nChecking anagrams for %s..\n", &word);

    return 0;
}

bool verify_word(char** word)
{
    // TODO: check if word is in dictionary

    return true;
}

