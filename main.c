#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

const uint8_t MAX_WORD_LENGTH = 20;

bool is_word_in_words_file(char* word, FILE* words_file);

int main(int argc, char** argv)
{
    /* Open words file */
    FILE* words_file = NULL;
    // TODO: Check for debian-based distributions
    words_file = fopen("/usr/share/dict/words", "r");

    if(words_file == NULL)
    {
        perror("\nWas not able to open file.\n");
        return 1;
    }


    /* Run anagram solver */
    char word[MAX_WORD_LENGTH];

    printf("\n===== Anagram Solver =====\n");
    bool read_input = false;
    while(!read_input)
    {
        printf("\nEnter a word > ");
        if(scanf("%s", &word) != 1)
        {
            printf("Error reading input.\n");
            continue;
        }

        if(!is_word_in_words_file(word, words_file))
        {
            printf("\n%s is NOT a valid word. Try again.\n", word);
            continue;
        }

        read_input = true;
    }


    /* Clean up / End program */
    fclose(words_file);
    return 0;
}

bool is_word_in_words_file(char* word, FILE* words_file)
{
    // Search for a word in a file with word delimited by a new line
    // Case sensitive
    // Assumes valid FILE pointer

    char buffer[MAX_WORD_LENGTH];

    while(fgets(buffer, sizeof buffer, words_file) != NULL)
    {
        // remove new line character
        size_t length = strlen(buffer);
        if(length > 0 && buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }

        if(strcmp(word, buffer) == 0)
        {
            rewind(words_file);
            return true;
        }
    }

    // check for EOF status
    if(!feof(words_file))
    {
        perror("Error reading file.\n");
    }

    rewind(words_file);
    return false;
}

