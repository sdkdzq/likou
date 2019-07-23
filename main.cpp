#include <iostream>


//动态规划找最大回文子串
char * longestPalindrome(char * s){
    int len = strlen(s);
    char a[1000] = {0};
//    char *start = s;
//    char *end = s+len-1;
    if(len == 0 || len == 1)
        return s;
    if(len == 2)
    {
        if(s[0] == s[1])
            return s;
        else {
            memcpy(a, s, 1);
            return a;
        }
    }

    int start = 0;
    int max = 1;
    for(int l = 3; l <= len; l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
    {
        for(int i = 0; i + l - 1 < len; i++)
        {
            int ss = i;
            int j = l + i - 1;//终止字符位置
            //printf("len %d %s\n", l, s + i);
            if(s[i] == s[j])
            {
                while(s[i + 1] == s[j - 1] && i + 1 <= j - 1)
                {
                    i++;
                    j--;
                }
            }

            if(i == j || i+1 == j)
            {
                if(max < l)
                {
                    max = l;
                    start = ss;
                    //printf(" %d\n", ss);
                }
            }
            i = ss;
        }
    }
    if(max < 3)
    {
        for(int i = 0; i < len; i++)
        {
            if(s[i] == s[i+1])
            {
                max = 2;
                start = i;
            }
        }
    }

    memcpy(a, s + start, max);
    return a;

}


bool isPalindrome(int x){
    if(x < 0)
        return false;
    if(x < 10)
        return true;

    int a[10] = {0};
    int number;
    int i = 0;
    while(1)
    {
        number = x % 10;

        a[i] = number;
        i++;
        x = x/ 10;
        if(x < 1)
            break;
    }
    int j = 0;
    i--;
    while(a[i] == a[j] && i >= j)
    {
        i--;
        j++;
        //printf("%d %d \n", i, j);
    }
    if(i + 1 == j - 1 || i + 1 == j)
        return true;
    else return false;
}

bool isMatch(char * s, char * p){
    while(p != NULL && s != NULL)
    {
        if(p[0] == ' ')
            break;
        if(p[0] == '.')
        {
            if(s[0] == s[1]) {
                while (p != NULL && p + 1 != NULL && s != NULL && s[0] == s[1]) {
                    if (p[1] == '*') {
                        s++;
                        continue;
                    } else if (p[1] == s[0] || p[1] == '.') {
                        s++;
                        p++;
                        continue;
                    } else {
                        return false;
                    }
                }
            }else {
                s++;
//                continue;
            }
        }else
        {
            if(p[0] != s[0])
                return false;
            else{
                if(s[0] == s[1]) {
                    while (p != NULL && p + 1 != NULL && s != NULL  && s[0] == s[1]) {
                        if (p[1] == '*') {
                            s++;
                            continue;
                        } else if (p[1] == s[0] || p[1] == '.') {
                            s++;
                            p++;
                            continue;
                        } else {
                            return false;
                        }
                    }
                }else {
                    s++;
//                    continue;
                }
            }
        }
    }
    if(p[0] == ' ' || s[0] == ' ')
        return false;
    else
        return true;
}

int main() {

    printf("最长回文子串\n");
    printf("%s \n", longestPalindrome("bcbbbbcb"));

    printf("回文数判断\n");
    printf("%d \n", isPalindrome(2147483647));

    printf("正则表达式匹配\n");
    printf("%d \n", isMatch("aa", "a*"));

    //std::cout << "Hello, World!" << std::endl;
    return 0;

}