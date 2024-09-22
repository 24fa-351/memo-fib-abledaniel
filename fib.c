#include <stdio.h>
#include <stdint.h>

//write in C fibonnaci recursively and write it iteratively 
//then accept the command line argument read the file then calculate the value to the Nth fibbnoaci

int memo_fib[100];

uint64_t fibo_recursive_wrapper(uint64_t f){
    if (f <= 1){
        memo_fib[f] = f;
        return f;
    }
    if (memo_fib[f-1] == -1){
        memo_fib[f-1] = fibo_recursive_wrapper(f-1);
    }
    if (memo_fib[f-2] == -1) {
        memo_fib[f-2]= fibo_recursive_wrapper(f-2);
    } 
    memo_fib[f] = memo_fib[f-1] + memo_fib[f-2];
    return memo_fib[f];
}

uint64_t fibo_iterative_wrapper(uint64_t f){
    if (f != -1){
        return memo_fib[f];
    }

    memo_fib[0] = 0;
    memo_fib[1] = 1;

    for (int i = 2; i<= f; i++){
        memo_fib[i] = memo_fib[i -1] + memo_fib[i-2];
    } 
    return memo_fib[f];
}

int main(int argc, char *cmd[]) {
    if (argc != 4) {
        return 1;
    }

    uint64_t input_number = atoi(cmd[1]), file_number;
    FILE *file = fopen(cmd[3], "r");
    fscanf(file, "%llu", &file_number);

    uint64_t N = input_number + file_number;
    uint64_t result = 0;
    char fib = cmd[2][0];
    if (fib == 'r'){
        result = fibo_recursive_wrapper(N);
    }
    if (fib == 'i'){
        result = fibo_iterative_wrapper(N);
    }
    fscanf("%llu\n", result);

    return 0;
}
