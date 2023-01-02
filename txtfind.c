#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE 256
#define FILENAME "find_inputb.txt"

FILE *fp;
char line[LINE];
char copy_line[LINE], *target_word, *token, *func_type;

int find_word(int word_letters[256], int seq_letters[256], char *word, char *token)
{

    if (strlen(token) > strlen(word) + 1)
    {
        return 0;
    }

    for (int i = 0; i < strlen(word); i++)
    {
        if (word_letters[*(word + i)] > seq_letters[*(word + i)])
        {
            return 0;
        }
    }
    // printf("%ld : %ld\n", strlen(token), strlen(word));
    return 1;
}

int printFunc(char *line, char *word, int printWord)
{
    int word_letters[256] = {0}, line_end_type = 1; // line end is \n
    //printf("%d : %d\n", *(line + strlen(line) - 2),*(line + strlen(line) - 1));
    if(13 == *(line + strlen(line) - 2)){line_end_type = 2;} // line end is tab maybe
    if(10 != *(line + strlen(line) - 1)){line_end_type = 0;} // no unique line end

    //create same line without unique end and split line to words
    char new_line[strlen(line) - line_end_type];
    strncpy(new_line, line, sizeof(new_line));
    new_line[strlen(line) - line_end_type] = '\0';
    char *token = strtok(new_line, " ");

    // enter target word letters in array
    for (int i = 0; i < strlen(word); i++)
    {
        word_letters[*(word + i)]++;
    }

    // check for the target word in each word in the line
    while (token != NULL)
    {
        int seq_letters[256] = {0};

        // enter current word letters in array
        for (int i = 0; i < strlen(token); i++)
        {
            seq_letters[*(token + i)]++;
        }

        int found = find_word(word_letters, seq_letters, word, token);
        if (found && printWord)
        {
            printf("%s\n", token);
        }
        if (found && !printWord)
        {
            printf("%s", line);
            break;
        }

        token = strtok(NULL, " ");
    }

    return 0;
}

int main(int argc, char *argv[])
{

    // save target word and type of function
    fgets(line, sizeof(line) , stdin);
    strcpy(copy_line, line);
    token = strtok(copy_line, " ");
    target_word = token;

    // printf("%s.\n", target_word);
    token = strtok(NULL, " ");
    func_type = token;
    func_type[1] = '\0';

    // printf("%s.\n", func_type);

    fgets(line, sizeof(line) , stdin);
    while (fgets(line, sizeof(line) , stdin))
    {
        printFunc(line, target_word, !strcmp("a", func_type));
    }

    fclose(stdin);

    return 0;
}
