#include "utils.h"

int main(){
    int size = 5;
    int array[5] = {1, 2, 3, 4, 5};
    int value = 3;
    fill_array(array, size, value);
    print_array(array, size);
}