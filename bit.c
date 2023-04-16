#include<unistd.h>
#include<stdio.h>

unsigned char ft_swap(unsigned char i)
{
    return (i >> 4 | i << 4);
}

unsigned char ft_rewerse(unsigned char i)
{
    int             ind;
    unsigned char   bit;

    ind = 7;
    while (ind >= 0)
    {
        bit = ((bit * 2) + (i % 2));
        i /= 2;
        ind--;
    }
    return (bit);
}

void ft_bit_shift(unsigned char i)
{
    int     ind;
    unsigned char   n1;
    unsigned char   n2;

    ind = 7;
    n2 = 1;
    while (ind >= 0)
    {
        n1 = (((i >> ind) & n2) + '0');
        write(1, &n1, 1);
        ind--;
    }
    
}

int main ()
{
/*    ft_bit_shift('2');
    printf("\n");
    ft_bit_shift(ft_rewerse('2'));
     printf("\n");
    ft_bit_shift(ft_swap('2'));*/
    return (0);
}