#include <stdio.h>
#include <cs50.h>

//start

int main()
{

    //user input

    long credit;
    long credit_copy ;
    int total_sum = 0, pos = 0, total_length = 0;
    do
    {
        credit = get_long("Number: ");
        credit_copy = credit;

        //luhns algorithm

        while (credit != 0)
        {
            if (pos % 2 != 0)
            {
                int temp = 2 * (credit % 10);
                if (temp > 9)
                {
                    total_sum += (temp % 10 + temp / 10);
                }
                else
                {
                    total_sum += temp;
                }
            }
            else
            {
                total_sum += credit % 10;
            }
            credit = credit / 10;
            pos++;
            total_length++;
        }

    }

    //Card checking

    while (credit != 0);

    if (total_sum % 10 == 0)
    {

        //american express card check

        long amex_start = credit_copy / 10000000000000;
        if ((amex_start == 34 || amex_start == 37) && total_length == 15)
        {
            printf("AMEX\n");
            return 0;
        }

        //mastercard check
        long master_card_start = credit_copy / 100000000000000;
        if ((total_length == 16) && (master_card_start >= 51 && master_card_start <= 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }

        //visa card check
        long visa_start = credit_copy / 1000000000000;
        if ((total_length == 16 || total_length == 13) && (visa_start == 4 || master_card_start / 10 == 4))
        {
            printf("VISA\n");
            return 0;
        }



        printf("INVALID\n");






    }
    else
    {
        printf("INVALID\n");
    }

//end

}
