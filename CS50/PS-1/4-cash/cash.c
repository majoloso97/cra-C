#include <cs50.h>
#include <stdio.h>

int update_owed_change(int owed, int coin_value, int coin_amount);
int get_coin_amount(int owed, int coin_value);

int main(void) {
    int owed = -1;
    int coin_amount = 0;

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    int total_quarters = 0;
    int total_dimes = 0;
    int total_nickels = 0;
    int total_pennies = 0;

    while (owed < 0) {
        owed = get_int("Change owed: ");
        if (owed > 5) {
            get_int("Give me one: ");
        }
    }

    total_quarters = get_coin_amount(owed, quarter);
    owed = update_owed_change(owed, quarter, total_quarters);

    total_dimes = get_coin_amount(owed, dime);
    owed = update_owed_change(owed, dime, total_dimes);

    total_nickels = get_coin_amount(owed, nickel);
    owed = update_owed_change(owed, nickel, total_nickels);

    total_pennies = get_coin_amount(owed, penny);
    owed = update_owed_change(owed, quarter, total_pennies);

    coin_amount = total_quarters + total_dimes + total_nickels + total_pennies;

    printf("%i\n", coin_amount);
}

int update_owed_change(int owed, int coin_value, int coin_amount) {
    if (coin_amount > 0) {
        owed -= coin_amount * coin_value;
    }
    return owed;
}

int get_coin_amount(int owed, int coin_value) {
    int coins = 0;
    if (owed >= coin_value) {
        coins = owed / coin_value;
    }
    return coins;
}
