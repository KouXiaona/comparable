#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<time.h>
/*
//�Ƚ�������ֵ��������Ч��
struct A
{
	int array[100000];

};

A globalA;//��һ��ȫ�ֱ���

void funval(A a)
{}
void funref(A& ra)
{}

void test1()
{//���ۣ����������ñȴ�ֵЧ�ʸߺܶ�
	size_t begin = clock();
	for (int i = 0; i < 100000; ++i)
		funval(globalA);
	size_t end = clock();
	std::cout << "funval" << end - begin << std::endl;
	begin = clock();
	for (int i = 0; i < 100000; ++i)
		funref(globalA);//���ò��ÿ���
	end = clock();
	std::cout << "funref" << end - begin << std::endl;
};
*/
struct A
{
	int array[100000];

};

A globalA;//��һ��ȫ�ֱ���

A funval()
{
	return globalA;
}
A& funref()
{
	return globalA;
}
void test2()
{//����:�������ñȷ���ֵЧ�ʸߺܶ࣬ԭ��Ҳ�ǲ��ÿ���
	size_t begin = clock();
	for (int i = 0; i < 100000; ++i)
		funval();
	size_t end = clock();
	std::cout << "funval" << end - begin << std::endl;
	begin = clock();
	for (int i = 0; i < 100000; ++i)
		funref();//���ò��ÿ���
	end = clock();
	std::cout << "funref" << end - begin << std::endl;
};

void test3 ()
{//�����뷴��࣬���Է��֣����õĵײ����ָ�룬ͨ��ָ��ʵ������
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
���ã���������constָ�롪��>ָ��ָ��ռ䲻�ܱ䣬���ݿ��Ա䡣���͡�*const������>ָ�򲻻ᷢ���仯����һ����
���ü�ֵ��
1��ʹ�ü򵥣�����ȡ��ַ�����ý�����
2��ʹ�ýϰ�ȫ��û�п����ã�û�н������쳣

const ����*const����>���ͺͿռ䶼���ܱ�  
*/