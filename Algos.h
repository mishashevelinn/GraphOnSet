//
// Created by misha on 3/20/2021.
//

#ifndef PRACTICE_ALGOS_H
#define PRACTICE_ALGOS_H

#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include "Stack.h"

typedef unsigned char uc;

void dec_to_bin_bits(uc num) {
    uc bit = 1 << (sizeof(uc)*8 - 1);
    for(int i = 0; i < sizeof(uc) * 8 ; i++, num <<= 1) {
        printf("%d", num & bit ? 1 : 0);
    }
}

char * dec_to_mit_arithmetic(uc num){
    uc pow = 1;
    uc size = sizeof (uc) * 8;
    char * res = (char*)malloc(size + 1);
    //res = (char*)memset((void*)res, '0', size);

    uc bit = 0;
    while(num > 0) {
        bit = num % 2 == 1 ? '1' : '0';
        res[size - pow] = bit;
        num /= 2;
        pow++;
    }
    res = (char*)memset((void*)res, '0', size - pow + 1); //zeros completion
    res[size] = '\0';
    return res;
}

char * unsigned_to_signed_arithmetic(uc num){
    uc pow = 1;
    uc size = sizeof (uc)*8;
    //char * res = (char*)calloc(size + 1, sizeof(char));
    char* res = (char*)malloc((size + 1)*sizeof(char));
    uc sign = num & (1 << (size - 1)) ? '-' : '+';
    if(!res){
        printf("%s\n%s\n", "Memory allocation failed \n", __LINE__);
        exit(-1);
    }
    for (int i = 0; i < size - 1; i++) {
        char bit = num % 2 ? '1' : '0';
        num /= 2;
        res[size - pow] = bit;
        pow++;
    }
    res[0] = sign;
    res[size] = '\0';
    return res;
}

void unsigned_to_signed_bits(uc num){
    dec_to_bin_bits(~num + 1);
}

//Return the rightmost 1 in the binary representation of a number.

uc rightmost_bit(uc n){
    return (n^(n&(n-1)));
}

char* removeDuplicates(char* pString){
    short binTable[256] = {0};
    int start = 0, res = 0;
    uc table_index;
    while(*(pString + start)){
        table_index = *(pString + start);
        if(!binTable[table_index]){
            binTable[table_index] = 1;
            *(pString + res) = *(pString + start);
            res++;
        }
        start++;
    }
    *(pString + res) = '\0';
    return pString;
}
bool isMatchingPair(char c, char d) {
    if(c == '(' && d == ')') return true;
    else if(c == '[' && d == ']') return true;
    else if(c == '{' && d == '}') return true;
    return false;
}
bool BalancedBrackets(const char * string){
    const char * left = "{[(";
    const char * right = "}])";
    Node stack = NULL;

    int i = 0;
    while(string[i]){
        if(string[i] == '{' || string[i] == '(' || string[i] == '['){
            push(&stack, string[i]);
        }
        if(string[i] == '}' || string[i] == ')' || string[i] == ']'){
            if(stack == NULL){
                return false;
            }
            else if(!isMatchingPair(pop(&stack), string[i])){
                return false;
            }
        }
        i++;
    }
    return stack == NULL;
    }



#endif //PRACTICE_ALGOS_H
