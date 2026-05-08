#include "password.h"
/*此密码是输入偏移，然后把字符向后偏移*/

void caesar(char str[])
{
    int i = 0,n;
    printf("please input offset n is:");
    scanf("%d", &n);
    while (str[i]) i++;
    for (int j = 0; j < i; j++)
    {
        if (str[j] >= 'a' && str[j] <= 'z')
            str[j] = (str[j] - 'a' + n) % 26 + 'a';
        else if (str[j] >= 'A' && str[j] <= 'Z')
            str[j] = (str[j] - 'A' + n) % 26 + 'A';
        
    }
    printf("%s", str);
}
void uncaesar(char str[])
{
    int i = 0,n;
    printf("please input offset n is:");
    scanf("%d", &n);
    while (str[i]) i++;
    for (int j = 0; j < i; j++)
    {
        if (str[j] >= 'a' && str[j] <= 'z')
            str[j] = (str[j] - 'a' - n + 26) % 26 + 'a';
        else if (str[j] >= 'A' && str[j] <= 'Z')
            str[j] = (str[j] - 'A' - n + 26) % 26 + 'A';
        
    }
    printf("%s", str);
}