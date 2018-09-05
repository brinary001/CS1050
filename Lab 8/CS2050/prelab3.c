/*br7pc
 *  * Brian Robinson
 *   * Lab B
 *    * Prelab3
 *     */
#include <stdio.h>
#include <stdlib.h>

void int_to_binary(int number);

int main (int argc, char** argv)
{
              int num;
        while (num != -1)
        {
                printf("Please enter a positive number to be converted to binary.\nEnter -1 to terminate: ");
                scanf("%d", &num);
        }
        if (num == 0 || num < -1)
        {
                printf("Please enter a poisitive number: ");
                scanf("%d", &num);
        }
        //printf("%d", int_to_binary);
        
        return 0;       
}

void int_to_binary(int number)
{

int remainder; 
int binary = 0, i = 1;
     
    while (number != 0) 
        {
                remainder = number%2;
                number = number/2;
                binary = binary + (remainder*i);
                i = i*10;
    }
}
