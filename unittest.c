#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedList.h"
#include "node.h"
#include "time.h"
#define MAX_TESTS 100
//gcc -o runTest.exe unittest.c linkedList.c linkedList.h node.h -std=c99 -l pthread

const char *passed_tests[MAX_TESTS];
const char *failed_tests[MAX_TESTS];

int total_tests = 0;
int succeeded = 0;
int failed = 0;

time_t begin, end;

void evaluateTestResult(char *f_name, int status)
{
    if (status == 0)
    {
        passed_tests[succeeded] = f_name;
        succeeded++;
    }
    else
    {
        failed_tests[failed] = f_name;
        failed++;
    }

    total_tests++;
}

void printTestResults()
{
    printf("\n------------------------------");
    printf("\nTests results: ");

    for (int i = 0; i < succeeded; i++)
    {
        printf("\n%s: OK", passed_tests[i]);
    }

    for (int j = 0; j < failed; j++)
    {
        printf("\n%s: FAIL", failed_tests[j]);
    }

    printf("\nTotal test cases ran: %d", total_tests);
    printf("\nTest case result: %d passed, %d failed (%2.f %% success)", succeeded, failed, ((double)succeeded / (double)total_tests) * 100);
    printf("\nFinished test suite.");
    printf("\n------------------------------");
}

LinkedList *setUp()
{
    LinkedList *list = createList();
    printf("%p", list);
    return list;
}

void *tearDown(LinkedList *list)
{
    list = NULL;
    free(list);
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
    int status = 0;
    char *f_name = "Test: Insert at list should return element in last position";

    LinkedList *testList = setUp();
    insertNode(testList, 10000);

    if (getNextNode(testList))
    {
        status = 1;
    }

    tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_delete_from_list_should_return_list_without_the_element()
{
    int status = 0;
    char *f_name = "Test: Delete from list should return list without the element";

    LinkedList *testList = setUp();
    insertNode(testList, 10000);
    insertNode(testList, 10001);
    deleteNode(testList, 10000);

    if (findNode(testList, 10000))
    {
        status = 1;
    }

    tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_delete_from_middle_position_should_return_list_without_the_middle_element()
{
    int status = 0;
    char *f_name = "Test: Delete from middle position should return list without the middle element";

    LinkedList *testList = setUp();
    insertNode(testList, 10000);
    insertNode(testList, 10001);
    insertNode(testList, 10002);

    deleteNodeFromSpecificPosition(testList, 1);

    if (findNode(testList, 10001))
    {
        status = 1;
    }

    tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_delete_from_last_position_should_return_list_without_the_last_element()
{
    int status = 0;
    char *f_name = "Test: Delete from last position should return list without the last element";

    LinkedList *testList = setUp();
    insertNode(testList, 10000);
    insertNode(testList, 10001);
    insertNode(testList, 10002);

    deleteNodeFromSpecificPosition(testList, 2);

    tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_delete_from_first_position_should_return_list_without_the_first_element()
{
    int status = 0;
    char *f_name = "Test: Delete from first position should return list without the first element";

    LinkedList *testList = setUp();
    insertNode(testList, 10000);
    insertNode(testList, 10001);
    insertNode(testList, 10002);

    deleteNodeFromSpecificPosition(testList, 0);

    tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_delete_from_empty_list_should_not_do_anything()
{
    int status = 0;
    char *f_name = "Test: Delete from empty list should not do anything";

    // LinkedList *testList = setUp();

    // if (deleteNodeFromSpecificPosition(testList, 0))
    // {
    //     status = 1;
    // }

    // tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_is_empty_should_return_true_on_empty_list()
{
    int status = 0;
    char *f_name = "Test: Is empty should return true on empty list";

    LinkedList *testList = setUp();

    if (!isEmpty(testList))
    {
        status = 1;
    }

    tearDown(testList);
    evaluateTestResult(f_name, status);
}

void test_should_fail()
{
    int status = 1;
    char *f_name = "Test: Should fail";

    evaluateTestResult(f_name, status);
}

void test_find_node_on_empty_list_should_return_false()
{
}

void test_find_node_on_list_with_wanted_node_should_return_true()
{
}

int main()
{
    begin = time(NULL);
    printf("\nRunning tests.");
    test_create_list_should_return_empty_list();
    test_insert_at_list_should_return_element_in_last_position();
    test_delete_from_list_should_return_list_without_the_element();
    test_delete_from_first_position_should_return_list_without_the_first_element();
    test_delete_from_middle_position_should_return_list_without_the_middle_element();
    test_delete_from_last_position_should_return_list_without_the_last_element();
    test_is_empty_should_return_true_on_empty_list();
    end = time(NULL);
    printTestResults();
    printf("\nTests finished in %f seconds.", difftime(end, begin));
    getchar();
    return 0;
}