#include <stdio.h>
#include <string.h>
#include <ctype.h>
void find_sequence(char* str);
int main(void)
{
    char str[100];
    
    printf("Please enter a string: ");
    fgets(str, 100 , stdin);
    printf("Got string : %s\n", str);
    find_sequence(str);
}

void find_sequence(char* str)
{
    int len = strlen(str);
    int i = 0,new_str_index=0,k;
    for (i = 0; i < len; i++)
    {
        if (i+1 <len &&str[i]+1 == str[i +1]  && isalpha(str[i]) ){
            if (i+2 <len && str[i+2] == str[i]+2){
                str[new_str_index++] = str[i];
                str[new_str_index++] = '-';
                k= i +2;
            while (k<len && str[k]  + 1 == str[k + 1])
            {
                k++;
                
            }
            i = k;
            str[new_str_index++] = str[k];
            }
            else{
                str[new_str_index++] = str[i];
            }
        
        }
        else{
           str[new_str_index] = str[i];
           new_str_index++;
        }
    }
        
    str[new_str_index++] = '\0';
    printf("Output: %s\n", str);
}
