#include <password.h>
/*把三个8位一组的字节切断变为4个6位一组，
A-Z（0-25），a-z（26-51），0-9（52-61），+ 和 /（62-63），共 64 个。
重新输出，不足三字节补0后加‘=’补齐*/

static const char base64_table[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
'0','1','2','3','4','5','6','7','8','9',
'+','/'};

int fun(char c)
{
    int a = 0x03;
    int b = (c&a) << 4;
    return b;
}

int fun1(char c)
{
    for (int i = 0; i < 64; i++)
    {
        if (base64_table[i] == c)
            return i;
    }
    return -1;
}
void base64(char str[])
{
    int i = 0;
    while (str[i]) i++;
    if (i == 0)
    {
        printf("no str enter!");
        return;
    }else if (i % 3 == 0)
    {
        for (int j = 0; str[j]; j +=3)
        {
            int k = str[j] >>2;
            putchar(base64_table[k]);
            int c = fun(str[j]);
            int a = (str[j+1]>>4)|c;
            putchar(base64_table[a]);
            int b = ((str[j+1] << 4)|(str[j+2] >> 4)) >>2;
            putchar(base64_table[b]);
            int d = str[j+2] & 0x3f;
            putchar(base64_table[d]);
        }
        
    }else if (i % 3 == 1)
    {
        int j;
        for (j = 0; str[j+1]; j +=3)
        {
            int k = str[j] >>2;
            putchar(base64_table[k]);
            int c = fun(str[j]);
            int a = (str[j+1]>>4)|c;
            putchar(base64_table[a]);
            int b = ((str[j+1] << 4)|(str[j+2] >> 4)) >>2;
            putchar(base64_table[b]);
            int d = str[j+2] & 0x3f;
            putchar(base64_table[d]);
        }
        int k = str[j] >> 2;
        putchar(base64_table[k]);
        printf("==");
    }else if (i % 3 == 2)
    {
        int j;
        for (j = 0; str[j+1]; j +=3)
        {
            int k = str[j] >>2;
            putchar(base64_table[k]);
            int c = fun(str[j]);
            int a = (str[j+1]>>4)|c;
            putchar(base64_table[a]);
            int b = ((str[j+1] << 4)|(str[j+2] >> 4)) >>2;
            putchar(base64_table[b]);
            int d = str[j+2] & 0x3f;
            putchar(base64_table[d]);
        }
        int k = str[j] >>2;
        putchar(base64_table[k]);
        int c = fun(str[j]);
        int a = (str[j+1]>>4)|c;
        putchar(base64_table[a]);
        printf("=");
    }
    return;
}

void unbase64(char str[])
{
int len = strlen(str);
    if (len == 0)
    {
        printf("no str enter!");
        return;
    }
    for (int j = 0; j < len; j += 4)
    {
        int a = fun1(str[j]);
        int b = fun1(str[j+1]);
        int c, d;
        if (str[j+2] == '=')
            c = 0;
        else
            c = fun1(str[j+2]);
        if (str[j+3] == '=')
            d = 0;
        else
            d = fun1(str[j+3]);
        char b1 = (a << 2) | (b >> 4);
        putchar(b1);
        if (str[j+2] != '=')
        {
            char b2 = ((b & 0x0F) << 4) | (c >> 2);
            putchar(b2);
        }
        if (str[j+3] != '=')
        {
            char b3 = ((c & 0x03) << 6) | d;
            putchar(b3);
        }
    }
}