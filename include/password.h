#ifndef _PASSWORD_H_
#define _PASSWORD_H_

#include <stdio.h>
#include <string.h>

void caesar(char*);
void uncaesar(char*);        //凯撒密码加解密

void morse(char*);
void unmorse(char*);         //摩斯密码加解密

void URL(char*);
void UURL(char*);         //URL编解码

void base64(char*);       
void unbase64(char*);         //base64编解码
#endif