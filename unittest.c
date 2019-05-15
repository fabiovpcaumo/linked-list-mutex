#include <stdio.h>
#include <assert.h>
#include "linkedList.h"
#include "node.h"

#define run_test(function_name)      \
    printf("%s \n", #function_name); \
    function_name()

#define MAX_TESTS 100
//gcc -o runTest.exe unittest.c linkedList.c linkedList.h node.h -std=c99 -l pthread

const char *passed_tests[MAX_TESTS];
const char *failed_tests[MAX_TESTS];

int total_tests = 0;
int succeeded = 0;
int failed = 0;

void evaluateTestResult(char *f_name, int status)
{
    if (status == 0)
    {
        passed_tests[total_tests] = f_name;
        succeeded++;
    }
    else
    {
        failed_tests[total_tests] = f_name;
        failed++;
    }

    total_tests++;
}

void printTestResults()
{
    for (int i = 0; i < succeeded; i++)
    {
        printf("\n%s: OK", passed_tests[i]);
    }

    for (int i = 0; i < failed; i++)
    {
        printf("\n%s: FAIL", failed_tests[i]);
    }

    printf("\nTotal test cases ran: %d", total_tests);
    printf("\nTest case result: %d passed, %d failed (%2.f %% success)", succeeded, failed, ((double)succeeded / (double)total_tests) * 100);
    printf("\nTests ran.");
    printf("\n------------------------------");
}

void test_create_list_should_return_empty_list()
{
    int status = 0;
    char *f_name = "Test: Create list should return empty list";

    LinkedList *testList = createList();

    if (getHead(testList))
    {
        status = 1;
    }

    evaluateTestResult(f_name, status);
}

void test_insert_at_list_should_return_element_in_last_position()
{
    char *f_name = "Test: Insert at list should return element in last position";
    evaluateTestResult(f_name, 1);
}

int main()
{
    printf("\nRunning tests.");
    test_create_list_should_return_empty_list();

    printTestResults();

    getchar();
    return 0;
}