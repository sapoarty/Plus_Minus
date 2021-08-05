#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverse_str(char *s)
{
    int count = 0;
    int begin;
    int end;
    char *r;
    while (s[count] != '\0')
        count++;

    r = malloc(sizeof(char) * count);

    end = count - 1;

    for (begin = 0; begin < count; begin++) {
        r[begin] = s[end];
        end--;
    }
    return r;
}
char* plusMinusRec(char *str, int sum)
{
    if(strlen(str) == 1){
        if(sum + (str[0] - '0') == 0){
            return "+";
        } else if(sum - (str[0] - '0') == 0){
            return "-";
        } else {
            return "not possible";
        }
    }

    char *add_str_plus;
    char *add_str_minus;

    add_str_plus = malloc(sizeof(char) * 15);
    add_str_minus = malloc(sizeof(char) * 15);

    strcpy(add_str_minus, plusMinusRec(str + 1, sum - (str[0] - '0')));
    if(strcmp(add_str_minus, "not possible"))
    {

        return strcat(add_str_minus, "-");
    }

    strcpy(add_str_plus, plusMinusRec(str + 1, sum + (str[0] - '0')));
    if(strcmp(add_str_plus, "not possible"))
    {
        return strcat(add_str_plus, "+");
    }

    return "not possible";
}

void PlusMinus(int num)
{
    char str[15];
    sprintf(str, "%d", num);
    strcpy(str, plusMinusRec(str + 1, (str[0] - '0')));
    if (strcmp(str, "not possible"))
        printf("%s\n", reverse_str(str));
    else
        printf("%s\n", str);
}

int main(void) {

    // keep this function call here
    PlusMinus(26712);
    return 0;

}