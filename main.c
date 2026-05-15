#include "password.h"

int main()
{
    printf("\n===加密解密工具===\n");
    printf("1.凯撒密码\n2.URL编码\n3.Base64编码\n4.摩斯密码\n");
    printf("输入q!退出\n");
    while (1)
    {
        setbuf(stdin,NULL);
        printf("请选择功能：");
        char n[5],str[100];
        scanf("%s", n);
        if (strcmp(n, "q!") == 0)
        return 0;
        printf("请输入文本：");
        scanf("%s",str);
        int mod;
        printf("模式(0=加密/编码,1=解密/解码):");
        scanf("%d", &mod);
        switch (n[0])
        {
        case '1':
            if (mod == 0)
            caesar(str);
            else
            uncaesar(str);
            puts("");
            break;
    
        case '2':
            if (mod == 0)
            URL(str);
            else
            UURL(str);
            puts("");
            break;

        case '3':
            if (mod == 0)
            base64(str);
            else
            unbase64(str);
            puts("");
            break;

        case '4':
            if (mod == 0)
            morse(str);
            else
            unmorse(str);
            puts("");
            break;
            
        default:
        puts("");
            break;
        }
    }
    return 0;
}