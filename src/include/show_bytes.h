#include <stdio.h>
#include <stdint.h>
#include <cstdlib>
#include <string.h>
void test_case_2_1(void);
void test_case_2_2(void);
void test_case_2_5(void);
void test_case_2_7(void);
/**
 * @brief this case used for exercise 2.1
 * 
 */
void test_case_2_1(void)
{
      //1. convert hex to binary
    uint32_t example_1       = 0x39A7F8;
    char     string_para[32] = {0};
    uint8_t  temp[32]        = {0};
    uint32_t example_num     = example_1;
    uint8_t  i               = 0;
    while (example_num)
    {
        temp[31 - i++] = (example_num & 0x1);
        example_num    = example_num >> 1;
    }
    for (uint8_t i = 0; i < 32; i++)
    {
        printf("%d", temp[i]);
    }
    printf("\nHex 0x%x to Binary %s\n", example_1, string_para);
}

/**
 * @brief testcase for show_bytes
 * 
 */
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for ( i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
    
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}


void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}


/**
 * @brief this case used for exercise 2.1
 * 
 */
void test_case_2_5(void)
{
    printf("test case for 2.5\n");
    uint32_t val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    show_bytes(valp, 1);
    show_bytes(valp, 2);
    show_bytes(valp, 3);
}

void test_case_2_7(void)
{
    printf("test case for 2.7\n");
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));
}