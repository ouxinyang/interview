#include <stdio.h>
#include <stdlib.h>
#include "qh_string.h"
#include <assert.h>
#include <string.h>
#include <iostream>
#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

#define H_ARRAY_SIZE H_ARRAYSIZE
using namespace qh;

void test1()
{
	//最基本的构造函数
    const char* srcstring = "test1";
    qh::string qh_mystring(srcstring);
    assert(!strcmp(qh_mystring.data(), srcstring));
}

void test2()
{
	//拷贝构造函数
    const char* srcstring = "test2";
    qh::string qh_mystring1(srcstring);
    qh::string qh_mystring2(qh_mystring1);
    assert(!strcmp(qh_mystring2.data(), srcstring));
}

void test3()
{
	//指定长度的拷贝构造函数
    const char* srcstring = "test3test3";
    qh::string qh_mystring1(srcstring,5);
    assert(!strcmp(qh_mystring1.data(), "test3"));
}

void test4()
{
	//运算符=
    const char* srcstring = "test4";
    qh::string qh_mystring1(srcstring);
    qh::string qh_mystring2 = qh_mystring1;
    assert(!strcmp(qh_mystring2.data(), srcstring));
}

void test5()
{
	//运算符[]
    qh::string qh_mystring("test5");
    assert(*qh_mystring[1]=='e');
}

void test6()
{
	//空字符串
    qh::string qh_mystring1;
    assert(qh_mystring1.size() == 0);
	assert(!strcmp(qh_mystring1.data(), "\0"));
}

int main(int argc, char* argv[])
{
    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
    //TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    std::cout<<"All test passed!"<<std::endl;

#ifdef WIN32
    system("pause");
#endif
	return 0;
}
