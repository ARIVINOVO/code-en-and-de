#include <password.h>
/*此编码是除却一些字符，其他的转化为%加16进制*/

int is_safe_char(char c)
{
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') ||
           c == '-' || c == '_' || c == '.' || c == '~';
}

void URL(char str[])
{
   for (int i = 0; str[i]; i++) 
    {
        if (is_safe_char(str[i])) 
        {
            putchar(str[i]);
        } else 
        {
            printf("%%%02X", (unsigned char)str[i]);
        }
    }
    
}

int fun2(char c)
{
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

void UURL(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == '%' && str[i+1] && str[i+2])
        {
            int high = fun2(str[i+1]);
            int low  = fun2(str[i+2]);
            char ch = (high << 4) | low;
            putchar(ch);
            i += 2;
        }
        else
        {
            putchar(str[i]);
        }
    }
}