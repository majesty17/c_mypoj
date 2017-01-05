#include <stdio.h>

int m, n, s, k;
char map[5001];

int getType()
{
    int i = 0;
    while(i < n && map[i] != '*'){
        ++i;
    }
    if(i == n)
        return 0;
    int count = 0;
    while(i < n && map[i] == '*' && count < s){
        ++i;
        ++count;
    }
    if(count < s)
        return 2;
    while(i < n && map[i] != '*'){
        ++i;
    }
    if(i == n)
        return 1;
    return 2;
}

int getResult(int type)
{
    if(type == 0){
        if(k - 1 < s && m - k < s)
            return 0;
        if(n > s)
            return 2;
        if(k - 1 == s && m - k < s || k - 1 < s && m - k == s )
            return 1;
        return 2;
    }
    if(type == 1){
        if(k == 1 || k == m || m == s || s == 1)
            return 1;
        return 2;
    }
    return 0;
}

int main()
{
    scanf("%d %d %d %d", &m, &n, &s, &k);
    scanf("%s", map);
    int type = getType();
    int result = getResult(type);
    if(result == 0)
        printf("Impossible\n");
    else if(result == 1)
        printf("Unique\n");
    else
        printf("Ambiguous\n");
    return 0;
}
