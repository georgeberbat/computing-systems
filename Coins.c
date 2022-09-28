//
// Created by invar on 28.09.2022.
//

//Динамика:
//numCoins = min {
//        1+numCoins(originalamount−1)
//        1+numCoins(originalamount−2)
//        1+numCoins(originalamount−5)
//        1+numCoins(originalamount−7)
//        1+numCoins(originalamount−10)

#include <stdio.h>
#include "Coins.h"

int dp_make_change (int coins[], int money, int min_coins[], int coins_used[]) {
    for (int cents = 0; cents < money + 1; ++cents) {
        int coin_count = cents;
        int new_coin = 1;

        int array_size = 0;

        for (int j = 0; j < 5; ++j) {
            if(coins[j] <= cents)
                array_size++;
        }

        int allowed_coins[array_size];

        for (int j = 0; j < 5; ++j) {
            if(coins[j] <= cents) allowed_coins[j] = coins[j];
        }

        for (int j = 0; j < array_size; ++j) {
            if(min_coins[cents - allowed_coins[j]] + 1 < coin_count){
                coin_count = min_coins[cents - allowed_coins[j]] + 1;
                new_coin = allowed_coins[j];
            }
        }
        min_coins[cents] = coin_count;
        coins_used[cents] = new_coin;
    }
    return min_coins[money];
}

void print_coins(int coins_used[], int money) {
    int coin = money;
    while (coin > 0) {
        int this_coin = coins_used[coin];
        printf("%d ", this_coin);
        coin = coin - this_coin;
    }
}

void print_array(const int arr[], int size) {

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void solve_coins (int amnt) {
    printf("\n\nDEMO COINS: \n");
    int clist[5] = {1,2,5,7,10};
    int coinsUsed[amnt+1];
    int coinCount[amnt+1];

    printf("Making change for %d requires %d", amnt, dp_make_change(clist,amnt,coinCount,coinsUsed));
    printf(" coins.");
    printf(" They are: ");
    print_coins(coinsUsed,amnt);
    printf("\n");
    printf("The used list is as follows: ");
    print_array(coinsUsed, amnt+1);
}