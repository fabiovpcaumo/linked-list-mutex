#include <stdio.h>
#include <assert.h>

#define run_test(function_name)      \
    printf("%s \n", #function_name); \
    function_name()

//Stupid sample test
void test_foo()
{
    assert(1 > 2);
}

void test_bar()
{
    assert(NULL == (void *)0);
}

int main()
{
    run_test(test_bar);
    run_test(test_foo);
    printf("Tests ran. ");

    getchar();
    return 0;
}