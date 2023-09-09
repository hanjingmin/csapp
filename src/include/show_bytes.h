#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
void test_case_2_1(void);


void test_case_2_1(void)
{
    //1. convert hex to binary
    uint32_t example_1 = 0x39A7F8;
    printf("example num is 0x%x \n", example_1);
    char string_para[32] = {0};
    uint8_t temp[32] = {0};
    uint32_t example_num = example_1;
    uint8_t i = 0;
    while (example_num)
    {
        temp[31 - i++] = (example_num & 0x1);
        example_num = example_num >> 1;
    }
    for (uint8_t i = 0; i < 32; i++)
    {
        printf("%d", temp[i]);
    }
    printf("\nHex 0x%x to Binary %s\n", example_1, string_para);
}