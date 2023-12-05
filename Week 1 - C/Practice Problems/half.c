// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill_amount, float tax_percent, float tip_percent);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    float tip_percent = get_float("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// Calculates the amount to be paid by the two people
float half(float bill_amount, float tax_percent, float tip_percent)
{
    // Convert percent to decimal and calculate the tax and tip
    float tax = (tax_percent / 100) * bill_amount;
    float tip = (tip_percent / 100) * (bill_amount + tax);

    // Calculates the total bill, divides by half and returns the value
    float bill_total = bill_amount + tax + tip;
    float bill_half = bill_total / 2;
    return bill_half;
}
