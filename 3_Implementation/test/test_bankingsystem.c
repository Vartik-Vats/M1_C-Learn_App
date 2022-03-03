#include "bankingsystem.h"
#include "unity.h"
void setup(){

}
void tearDown(){

}
void test_phone(void){
    TEST_ASSERT_EQUAL_CHAR(1,(1));     //char
}
void test_ac(void){
    TEST_ASSERT_EQUAL_CHAR(2,(2));      //char
}
void test_password(void){
    TEST_ASSERT_EQUAL_CHAR(3,(3));      //char
}
void test_balance(void){
    TEST_ASSERT_EQUAL_FLOAT(4,(4));     //float
}
int main (void){
    UNITY_BEGIN();
    RUN_TEST(test_phone);
    RUN_TEST(test_ac);
    RUN_TEST(test_password);
    RUN_TEST(test_balance);
    return UNITY_END();
}