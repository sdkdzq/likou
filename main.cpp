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


int divide(int dividend, int divisor){

}

int strStr(char * haystack, char * needle){

    if(needle == "")
        return 0;
    if(haystack == "")
        return -1;
    char *p = needle;
    char *q = haystack;
    int count = 0;
    while(*haystack != '\0' && *p != '\0')
    {
        if(*haystack == *p)
        {
            haystack++;
            p++;
//            if(p[0] == '\0')
//                break;
        }else
        {
            count++;
            haystack = q + count;
            p = needle;
        }
    }
    if(*p == '\0')
        return count;
    else
        return -1;
}

char num_char[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

char *intTostr(int n)
{
    char num[100] = {0};
    char *p = "";
    while(n)
    {
        char q = num_char[n % 10];

        sprintf(num, "%c%s", q, p);
//        printf("%s\n", p);
        p = num;

//        strcat(q, p);
        n /= 10;
    }
    return num;
}
char * countAndSay(int n){
    if(n == 1)
        return "1";
    if(n == 2)
        return "11";
    char *p = countAndSay(n - 1);
    int count = 1;
    char num[1000] = {0};
    char *count_char = "";
    while(p[0] != NULL && p[1] != NULL && p[0] != '\0' && p[1] != '\0')
    {
        if(p[0] == p[1]) {
            p++;
            count++;
        }else
        {
            count_char = intTostr(count);
            sprintf(num, "%s%s", num, count_char);
            sprintf(num, "%s%c", num, p[0]);
            p++;
            count = 1;
        }
    }
    count_char = intTostr(count);
    sprintf(num, "%s%s", num, count_char);
    sprintf(num, "%s%c", num, p[0]);
//    *num += count_char + p[0];

    return num;
}

int max(int x, int y)
{
    return x>y?x:y;
}
int min(int x, int y)
{
    return x>y?y:x;
}

int maxProduct(int* nums, int numsSize){
    if(numsSize < 0)
        return 0;
    int i, ret, pos, neg, temp;
    pos = nums[0];
    neg = nums[0];
    ret = nums[0];

    for(i = 1; i < numsSize; i++)
    {
        temp = pos;
        pos = max(nums[i], max(pos * nums[i], neg * nums[i]));
        neg = min(nums[i], min(temp * nums[i], neg * nums[i]));
        ret = max(pos, ret);
    }


    return ret;
}

int binarySearch(int *nums, int start, int end)
{
    if(start == end)
        return nums[start];
    int maxLeft;
    int maxRight;
    int middle = start + (end - start) / 2;
    maxLeft = binarySearch(nums, start, middle);
    maxRight = binarySearch(nums, middle + 1, end);
    printf("%d-%d is %d %d-%d is %d\n", start, middle, maxLeft, middle + 1, end, maxRight);
    int tmp = 0;
    int maxL = nums[start];
    for(int i = start + 1; i < middle + 1; i++)
    {
        maxL += nums[i];
        maxL = max(maxL, tmp);
    }

    tmp = 0;
    int maxR = nums[middle + 1];
    for(int i = middle + 2; i < end; i++)
    {
        maxR += nums[i];
        maxR = max(maxR, tmp);
    }

    int maxE = max(maxLeft, maxRight);
    maxE = max(maxE, maxR);
    maxE = max(maxE, maxL);
    maxE = max(maxE, maxLeft + maxRight);
    printf("%d %d  %d %d %d \n", maxL, maxR, maxLeft, maxRight, maxLeft + maxRight);
    return maxE;

}

int maxSubArray(int* nums, int numsSize){
    if(numsSize < 1)
        return 0;
    int neg = nums[0];
    int pos = nums[0];
    int i, ret, temp;
    ret = nums[0];
    int mm = nums[0];
    for(i = 1; i < numsSize; i++)
    {
       if(ret + nums[i] > nums[i])
       {
           mm = max(mm, ret + nums[i]);
           ret = ret + nums[i];
       }else
       {
           mm = max(mm, ret);
           mm = max(mm, nums[i]);
           ret = nums[i];
       }
    }
    return ret;
//    return binarySearch(nums, 0, numsSize);
}

int isHW(char *s)
{
    int len = strlen(s);
    int i = 0;
    int j = len - 1;
    while(s[i] == s[j] && i <= j)
    {
        i++;j--;
    }
    if(i >= j)
        return 1;
    else
        return 0;
}
int minCut(char * s){
    if(strlen(s) <= 1)
        return 0;
    int i, j;
    int fenge;
    int record[1000] = {0};
    for(i = 0; i < strlen(s); i++)
    {
        record[i] = -1;
    }

    for(i = 1; i < strlen(s) + 1; i++)
        for(j = 0; j < i; j++)
        {
            char p[100] = {0};
            memcpy(p, s, sizeof(char) * i);
            if(isHW(p))
                record[i] = min(record[i], record[j] + 1);
        }
    return record[strlen(s) - 1];
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int partition(char * s, int* returnSize, int** returnColumnSizes){
    int len = strlen(s);
    if(len <= 1)
    {
        printf("[\n");
        printf("  [\"%s\"]\n", s);
        printf("]\n");
        return 1;
    }
    int i, j;
    printf("[\n");
    printf("  [");

    for(i = 0; i < len; i++)
    {
        for(j = i; )
    }

    for(i = 1; i < len; i++)
        for(j = 0; j < i; j++)
        {
            char p[100] = {0};
            memcpy(p, s, sizeof(char) * (i - j));
            if(isHW(p))

        }
    printf("]");
    printf("]\n");
}


int main() {

    printf("分割回文串\n");
    printf("%d %d\n", isHW("adbda"), minCut("aab"));

    int *returnSize;
    int **returnColumnSizes;
    partition("a", returnSize, returnColumnSizes);
    return 0;
    printf("乘积子序列和\n");
    int nums[100] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d \n", maxSubArray(nums, 9));

    printf("乘积最大子序列\n");
    int nums1[100] = {-2, 3, -4};
    printf("%d \n", maxProduct(nums1, 3));

    printf("报数\n");
    printf("%s \n", countAndSay(4));

    printf("最长回文子串\n");
    printf("%s \n", longestPalindrome("bcbbbbcb"));

    printf("回文数判断\n");
    printf("%d \n", isPalindrome(2147483647));

    printf("正则表达式匹配\n");
    printf("%d \n", isMatch("aa", "a*"));

    printf("两数相除\n");
    printf("%d \n", divide(10, 3));

    printf("实现strStr（）\n");
    printf("%d \n", strStr("aaaaa", "bba"));
    //std::cout << "Hello, World!" << std::endl;
    return 0;

}