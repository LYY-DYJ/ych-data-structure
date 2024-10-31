# DS_HW_9.1 prepend_palindrome #
## 实现 ##
思路是将字符串反转，然后用kmp与自己匹配。这里反转后的字符串是kmp中的text，而原字符串是pattern，因为这里是在原字符串前加上字符，所以匹配出的回文应当是原字符串的真前缀，通过kmp找出反转后的字符串中第一个与原字符串真前缀匹配的子串。kmp输出的int就是子串首个字符的index，也可以理解为需要添加到原字符串前的字符的个数。
### prepend_palindrome.cpp
```cpp
#include <string.h>

int kmp(char *p, char *t);

char *prepend_palindrome(char *s)
{
    int n = strlen(s);
    char t[n];
    for (int i = 0; i < n; i++)
    {
        t[i] = s[n - 1 - i];
    }
    t[n] = '\0';
    int k = kmp(s, t);
    char *result;
    result = new char[n + k];
    for (int i = 0; i < n + k; i++)
    {
        if (i < k)
        {
            result[i] = s[n - 1 - i];
        }
        else
        {
            result[i] = s[i-k];
        }
    }
    result[n + k] = '\0';
    return result;
}
```
## 测试 ##
### main.cpp ###
```cpp
#include <iostream>
#include <string.h>

char *prepend_palindrome(char *s);

int main()
{
    char str[100];
    while (scanf("%s",str))
    {
        char *result = prepend_palindrome(str);
        for (int i = 0; i < int(strlen(result)); i++)
        {
            std::cout << result[i];
        }
        std::cout << std::endl;
 
    }
    return 0;
}
```
## 结果 ##
![alt text](image.png)