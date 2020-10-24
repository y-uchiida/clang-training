#include <stdio.h>

int main(void)
{
    int juice, milk, price, pay, cng;
    double tax;

    juice = 198;
    milk = 138;
    pay = 1000;
    tax = 1.05;
    
    price = (int) ( ( (juice * 1) + (milk * 2) ) * tax );

    cng = pay - price;

    printf("おつりは%d円です\n", cng);

    return 0;
    
}