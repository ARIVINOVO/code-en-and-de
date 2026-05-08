#include <password.h>
/*摩斯密码*/

typedef struct {
    char ch;
    char *morse;
}Morse;

static const Morse table[] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."},
    {'\0', NULL}
};

char* find_morse(char c)
{
    for (int i = 0; table[i].ch != '\0'; i++)
    {
        if (table[i].ch == c)
            return table[i].morse;
    }
    return NULL;
}

char find_char(char *m)
{
    for (int i = 0; table[i].ch != '\0'; i++)
    {
        if (strcmp(table[i].morse, m) == 0)
            return table[i].ch;
    }
    return ' ';
}
void morse(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
            c -= ('a' - 'A');
        char *code = find_morse(c);
        if (code)
            printf("%s ", code);
        else if (c == ' ')
            printf(" ");
    }
    puts("");
}
void unmorse(char str[])
{
    char temp[20];
    int ti = 0;

    for (int i = 0;; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            temp[ti] = '\0';

            if (strcmp(temp, "/") == 0)
            {
                printf(" ");
            }
            else if (ti > 0)
            {
                char ch = find_char(temp);
                printf("%c", ch);
            }

            ti = 0;

            if (str[i] == '\0')
                break;
        }
        else
        {
            temp[ti++] = str[i];
        }
    }
    puts("");
}