#include <cstdio>
#include <cstring>
char s[2][2001], x[] = "MDCLXVI";
int num, sum, sym[26], val[26], y[] = {1000, 500, 100, 50, 10, 5, 1};
char x1[] = "MCXI", x5[] = ".DLV", x4[][3] =  {"", "CD", "XL", "IV"}, x9[][3] = {"", "CM", "XC", "IX"};
int main(){
    scanf("%s %s", s[0], s[1]);
    for(int i = 0; i < 7; i++)val[x[i] - 'A'] = y[i];
    for(int i = 0; i < 2; i++){
        int sn = strlen(s[i]);
        for(int j = 0; j < sn; j++){
            if(s[i][j] == 'I' && s[i][j + 1] == 'V')sum += 4, j++;
            else if(s[i][j] == 'I' && s[i][j + 1] == 'X')sum += 9, j++;
            else if(s[i][j] == 'X' && s[i][j + 1] == 'L')sum += 40, j++;
            else if(s[i][j] == 'X' && s[i][j + 1] == 'C')sum += 90, j++;
            else if(s[i][j] == 'C' && s[i][j + 1] == 'D')sum += 400, j++;
            else if(s[i][j] == 'C' && s[i][j + 1] == 'M')sum += 900, j++;
            else sum += val[s[i][j] - 'A'];
        }
    }
    printf("%d\n", sum);
    int tens = 1000;
    for(int i = 0; i < 4; i++){
        num = sum / tens, sum %= tens, tens /= 10;
        if(num == 0)continue;
        if(num == 9)printf("%s", x9[i]);
        else if(num == 8)printf("%c%c%c%c", x5[i], x1[i], x1[i], x1[i]);
        else if(num == 7)printf("%c%c%c", x5[i], x1[i], x1[i]);
        else if(num == 6)printf("%c%c", x5[i], x1[i]);
        else if(num == 5)printf("%c", x5[i]);
        else if(num == 4)printf("%s", x4[i]);
        else if(num == 3)printf("%c%c%c", x1[i], x1[i], x1[i]);
        else if(num == 2)printf("%c%c", x1[i], x1[i]);
        else if(num == 1)printf("%c", x1[i]);
        
    }

}