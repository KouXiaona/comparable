#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<time.h>
/*
//比较引用与值做参数的效率
struct A
{
	int array[100000];

};

A globalA;//给一个全局变量

void funval(A a)
{}
void funref(A& ra)
{}

void test1()
{//结论：参数传引用比传值效率高很多
	size_t begin = clock();
	for (int i = 0; i < 100000; ++i)
		funval(globalA);
	size_t end = clock();
	std::cout << "funval" << end - begin << std::endl;
	begin = clock();
	for (int i = 0; i < 100000; ++i)
		funref(globalA);//引用不用拷贝
	end = clock();
	std::cout << "funref" << end - begin << std::endl;
};
*/
struct A
{
	int array[100000];

};

A globalA;//给一个全局变量

A funval()
{
	return globalA;
}
A& funref()
{
	return globalA;
}
void test2()
{//结论:返回引用比返回值效率高很多，原因也是不用拷贝
	size_t begin = clock();
	for (int i = 0; i < 100000; ++i)
		funval();
	size_t end = clock();
	std::cout << "funval" << end - begin << std::endl;
	begin = clock();
	for (int i = 0; i < 100000; ++i)
		funref();//引用不用拷贝
	end = clock();
	std::cout << "funref" << end - begin << std::endl;
};

void test3 ()
{//，进入反汇编，可以发现：引用的底层就是指针，通过指针实现引用
	int a = 10;
	int *pa = &a;
	*pa = 20;

	int b = 1;
	int& rb = b;
	rb = 2;
}


int main()
{
	test3();
	//test2();
	//test1();
	system("pause");
	return 0;
}
/*
引用：可以理解成const指针——>指针指向空间不能变，内容可以变。类型“*const”——>指向不会发生变化，从一而终
引用价值：
1、使用简单，不用取地址，不用解引用
2、使用较安全，没有空引用，没有解引用异常

const 类型*const——>类型和空间都不能变  
*/