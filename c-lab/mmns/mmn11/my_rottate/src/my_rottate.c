#include <stdio.h>
void print_as_binary(unsigned int num);
void print_as_hex(unsigned int num);
void print_as_octet(unsigned int num);
void print_as_decimal(unsigned int num);
unsigned int my_rottate (unsigned int a, int b);
 void print_number(unsigned int num);
int main()
{

    unsigned int origin_num;
    int rottation_num;
    unsigned int result;
    printf("Please enter a : ");
    fscanf(stdin, "%d", &origin_num);
    printf("got - a : %d\n", origin_num);
    printf("Please enter b : ");
    fscanf(stdin, "%d", &rottation_num);
    printf("got - b : %d\n", rottation_num);
    printf(" Original Value : \n");
    print_number(origin_num);
    result = my_rottate(origin_num,rottation_num);
    printf(" Shifted Value :\n");
    print_number(result);

    

}


unsigned int my_rottate (unsigned int a, int b){
    int shifted_bits;
    int int_bits = sizeof(int)*8;
    
    if(b>0){
       shifted_bits = a<<(int_bits - b);
       a = a>>b;
      
    }  
    else{
        b = b*(-1);
       shifted_bits = a>>(int_bits - b);
       a = a<<b;
      
    }
    
     a = a | shifted_bits;


return(a);

}
 void print_number(unsigned int num){
    print_as_decimal(num);
    print_as_binary(num);
    print_as_octet(num);
    print_as_hex(num);

 }

void print_as_binary(unsigned int num){
    int size_of_int = sizeof(int);
    int i;
    int char_to_print=0;
    printf("the binary value is : ");
    for (i = (size_of_int*8)-1; i >= 0 ; i--)
    {
        int mask = 1<<i;
        int mask_value = mask& num;
        if (mask_value)
            printf("1");
        else
            printf("0");
        
        if (i%4 == 0){
            printf(" ");
        }
        
    }
    printf("\n");
}

void print_as_octet(unsigned int num){
    int size_of_int = sizeof(int);
    int i;
    int char_to_print=0;
    printf(" the octet value is : ");
    for (i = (size_of_int*8)/3; i >= 0 ; i--)
    {
        unsigned int mask = 0x7<<(i*3);
        unsigned int mask_value = (mask & num);
        mask_value = mask_value >> (i*3);
      
        printf("%x",mask_value);
         if (i%3 == 0)
            printf(" ");
    }
        
     printf("\n");
}

void print_as_hex(unsigned int num){
   
    int size_of_int = sizeof(int);
    int i;
    int char_to_print=0;
    printf(" the hex value is : 0x ");
    for (i = size_of_int-1; i >= 0 ; i--)
    {
        unsigned int mask = 0xff<<(i*8);
        unsigned int mask_value = (mask & num);
        mask_value = mask_value >> (i*8);
      
        printf("%x ",mask_value);
    }
        
     printf("\n");
}

void print_as_decimal(unsigned int num){
    printf(" the decimal value is : %u ", num);
    printf("\n");
}