#define _CRT_SECURE_NO_WARNINGS
/*
C与C++的关系
1.C++可以与C代码进行混编
2.C++面向对象编程语言, C面向过程的编程语言
3.C++是对C的一个增强
*/


/******************预览*******************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// 使用命名空间
// 类似于 Java 中的包名(归类)
using namespace std;

// 自定义命名空间
namespace NSP_A{
	int a = 9;
}
namespace NSP_B{
	int a = 10;
	// 命名空间嵌套 -- 不推荐这样写
	namespace NSP_C{
		int a = 11;
	}
}
// 命名空间中的结构体
namespace NSP_C{
	struct Teacher
	{
		char* name;
		int age;
	};
}

void main(){
	// c 输出方法
	printf("this is c++\n");

	// c++ 输出方法 <iostream>
	// 加入命名空间(std -- standard 标准命名空间,包含很多标准的定义)
	//		<< 运算符重载
	// std::cout << "this is c++\n" << std::endl;

	// 使用 using namespace
	cout << "this is c++" << endl;

	// 使用自定义命名空间
	// :: 访问符, 相当于Java中的.
	cout << "空间A:" << NSP_A::a << endl;
	cout << "空间B->C:" << NSP_B::NSP_C::a << endl;

	// 命名空间中的结构体
	// struct NSP_C::Teacher t1; 
	NSP_C::Teacher t1; // struct 写与不写都可以
	t1.age = 10;

	//using namespace NSP_C;
	using NSP_C::Teacher;
	Teacher t;
	t.name = "abc";
	t.age = 10;

	system("pause");
}
*/

/*******************数据类型******************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
void main(){
	// C++ 多了bool
	// bool isTrue = true;
	// bool isTrue = 100;// 大于0都是 true
	bool isTrue = 0;

	cout << sizeof(bool) << endl;

	if (isTrue){
		cout << "是的:" << endl;
	}
	else{
		cout << "不是的" << endl;
	}

	// 三元表达式在C++中可以表示左值
	int a = 10, b = 20;
	((a > b) ? a : b) = 30;
	// b = 30
	cout << b << endl;

	system("pause");
}
*/

/*********************类*********************/
/*
#define PI 3.14

class Circle{
	// 属性
private: // 权限访问修饰符 -- 共用
	double r;
	double s;
public:
	double l;
	// 方法
public:
	void setR(double r){
		this->r = r;
	}
	double getS(){
		return PI*r*r;
	}
};

// 结构体在C++中也有了访问修饰符
struct Teacher
{
private:
	int age = 10;
public:
	void say(){
		cout << age << "岁" << endl;
	}
};

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void main(){
	// 类: 可以直接使用
	Circle circle;
	circle.setR(4);
	cout << "圆的面积:" << circle.getS() << endl;

	// 结构体, 与类不同在于不能继承
	Teacher teacher;
	teacher.say();

	system("pause");
}
*/


/******************引用*****************/
// 引用的主要功能 : 作为函数的参数或返回值, 操作起来比指针方便
// 1. 单纯给变量起别名没有任何意义, 作为函数参数传递, 能保证参数传递过程中不产生副本
// 2. 引用可以直接操作变量, 而指针要通过取值(*p), 间接操作变量, 指针可读性差
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// 作为函数参数
void swap(int &a, int &b){
	// 交换 a,b 的值
	int c = 0;
	c = a;
	a = b;
	b = c;
}

struct Teacher{
	char* name;
	int age;
};
// 指针写法
void getTeacher(Teacher **p){
	Teacher *tmp = (Teacher*)malloc(sizeof(Teacher)); // 申请内存
	tmp->age = 20;
	*p = tmp;
}
// 指针的引用写法(Teacher* &p 代替二级指针  Teacher* &p = (Teacher* *p))
void getTeacher(Teacher* &p){
	p = (Teacher*)malloc(sizeof(Teacher)); // 申请内存
	p->age = 20;
}

// 常引用
void myPrint(const int &a){
	// 类似于 java 中的 final
	cout << a << endl;
}

void main(){
	int a = 10;
	// & 在 C++ 中表示引用(表示变量的别名), 和指针一样, 都是操作内存地址
	// 引用的 & 写在变量声明时
	// 引用必须要有值, 不能为空
	// int &a = NULL; // 错误
	int &b = a;
	int *c = &a;

	cout << b << endl;
	cout << *c << endl;

	int x = 10;
	int y = 20;
	printf("%d, %d\n", x,y);
	swap(x, y);
	printf("%d, %d\n", x,y);

	// 指针写法
	Teacher *t = NULL;
	getTeacher(t);
	cout << t->age << endl;

	Teacher *t1 = NULL;
	getTeacher(&t1);
	cout << t1->age << endl;

	// 常引用
	int a = 10, b = 9;
	const int &c = a;
	// c = b; // 错误

	// 常引用字面量写法
	const int &d = 10;

	system("pause");
}
*/

/********************指针常量/常量指针**********************/
/*
#include <stdlib.h>
#include <stdio.h>

void main(){
	int a = 2, b = 3;
	// 指针常量: 不改变地址的指针, 但是可以修改指向的内容
	int *const p1 = &a;
	// p1 = &b; // 错误 地址不可改变
	*p1 = 20; // 正确 可以改变内容

	// 常量指针: 指向常量的指针, 内容不可修改, 可以改变地址
	const int *p2 = &a;
	p2 = &b; // 正确 可以改变地址
	// *p2 = 10; // 错误 不可改变内容

	system("pause");
}
*/

/*********************函数******************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdarg.h>

using namespace std;

// 函数可以有默认值(有默认值的参数只能在最后)
void add(int x = 1, int y = 2){
	cout << x + y << endl;
}
// 会导致调用时的重载问题
//void add(int x, int y = 10, int z =20){}

// 可变参数(java 是 int...)
void func(int x, ...){
	// 可变参数指针, ... 开始
	va_list args;
	// 读取, 从最后一个固定参数x
	va_start(args, x);
	// 第二个参数类型, 类型要自己控制
	int a = va_arg(args, int);
	cout << a << endl;
	// 读取结束
	va_end(args);
}

void main(){
	add();
	add(5);

	func(9);
	func(9,10);

	system("pause");
}
*/

/****************类的写法****************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "MyTeacher.h"

using namespace std;

// c++中的类, 声明在.h文件中, 实现在 .cpp 中

void main(){
	MyTeacher t1;
	t1.name = "Json";
	// t1.setName("Jack"); 这样调会有问题, 下面构造函数理解
	t1.setAge(10);

	cout << t1.getName() << t1.getAge() << endl;

	system("pause");
}
*/

/****************构造函数/析构函数/拷贝构造函数*****************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
// 构造函数
class Teacher{
private:
	char* name;
	int age;
public:
	// 无参构造函数, 默认(没有其他构造函数时)只要创建了对象, 就会调用无参构造函数
	Teacher(){
		cout << "无参构造函数" << endl;
	}
	// 有参构造函数, 会覆盖默认的无参构造函数
	Teacher(char* name, int age){
		this->name = name;
		this->age = age;
		cout << "调用有参构造函数" << endl;
	}
};
// 析构函数
class Student{
private:
	char* name;
	int age;
public:
	Student(){
		this->name = (char*)malloc(100);
		strcpy(name, "jack");
		age = 20;
		cout << "无参构造函数" << endl;
	}
	// 析构函数, 当对象要被释放时调用
	// 作用 : 善后
	~Student(){
		// 释放内容
		free(this->name);
		cout << "析构函数" << endl;
	}
};
// 拷贝构造函数
// 浅拷贝 : 拷贝指针的地址
// 深拷贝 : 拷贝指针指向地址的内容
class Person{
private:
	char* name;
	int age;
public:
	Person(char* name, int age){
		this->name = (char*) malloc(100);
		strcpy(this->name, name); // 这种情况使用默认拷贝构造函数会有问题
		this->age = age;
		cout << "调用有参构造函数" << endl;
	}
	
	// 拷贝构造函数(值拷贝,用处很多,如集合)
	// 默认拷贝构造函数就是如下做法, 这是一种浅拷贝
	//Teacher(const Teacher &obj){
	//	this->name = obj.name;
	//	this->age = obj.age;
	//	cout << "拷贝构造函数" << endl;
	//}

	// 拷贝构造函数被调用场景(最基本的就是声明时被赋值时调用(t = t1 不算), 和java的clone类似)
	// 1. 声明时赋值  Teacher t = t1;
	// 2. 作为参数传入, 实参传递给形参 func(t)
	// 3. 作为函数返回值返回给变量初始化赋值 Teacher t = func();
	Person(const Person &obj){
		// 深拷贝
		int len = strlen(obj.name);
		this->name = (char*)malloc(len + 1);;
		strcpy(this->name, obj.name);
		this->age = obj.age;
		cout << "拷贝构造函数" << endl;
	}
	~Person(){
		free(this->name);
		cout << "析构函数" << endl;
	}
	void myPrint(){
		cout << name << " , " << age << endl;
	}
};
void func(){
	Student s2;
}
void func2(){
	// 若使用默认拷贝构造函数, func2()函数结束, Person的析构函数会被调用2次,  相当于一段内存释放两次
	// 所以, 使用默认拷贝构造函数进行浅拷贝会出现内存问题
	Person t4("ack", 20);
	Person t5 = t4; // 这时拷贝构造函数被调用
	t5.myPrint();
}
void main(){
	// Teacher t1;
	// Teacher t2("yuan", 20);
	// Teacher t3 = Teacher("jack", 20);

	// func(); // func被执行完毕的时候, 析构函数被调用

	func2();

	system("pause");
}
*/


/********************构造函数的属性初始化列表(属性对象赋值)***********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Teacher{
private:
	char* name;
public:
	Teacher(char* name){
		this->name = name;
		cout << "Teacher 有参构造函数" << endl;
	}
	~Teacher(){
		cout << "Teacher 析构函数" << endl;
	}
	char* getName(){
		return this->name;
	}
};

class Student{
private:
	int id;
	Teacher teacher_1;  // 属性对象
	Teacher teacher_2;
	Teacher teacher_3;
public:
									// 给属性对象 Teacher 构造函数传值, 多个用逗号分隔
	Student(int id, char* t_name) : teacher_1(t_name), 
									teacher_2(t_name),
									teacher_3("lala"){ 
		this->id = id;
		cout << "student 构造函数" << endl;
	}
	~Student(){
		cout << "student 析构函数" << endl;
	}
	void printModel(){
		cout << id << "," << teacher_1.getName() << endl;
	}
};

void main(){
	Student student(10, "Jsssson");
	student.printModel();
	system("pause");
}
*/


/******************new/delete**********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Teacher{
private:
	char* name;
public:
	char* getName(){
		return this->name;
	}
};

void main(){
	// ******类******
	// C++ 写法  和 malloc 一样
	Teacher *t1 = new Teacher(); 
	// new 出来的需要 delete 释放内存
	delete t1;

	// C 写法
	Teacher *t2 = (Teacher*)malloc(sizeof(Teacher));
	free(t2);

	// *****数组*****
	// c
	int *p1 = (int*)malloc(sizeof(int)* 10);
	p1[0] = 9;
	free(p1);
	
	// C++
	int *p2 = new int[10];
	p2[0] = 2;
	delete[] p2;  // 释放数组需要加上这个括号 ******

	system("pause");
}
*/


/************************static**************************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Teacher{
private:
	char* name;
public:
	// 静态属性
	static int total; // 不能直接初始化
	Teacher(char* name){ // 不能在构造函数中初始化
		this->name = name;
	}
	// 静态方法
	static void count(){
		total++;
		cout << total << endl;
	}
};

// 静态属性初始化必须在外部
int Teacher::total = 9;

void main(){
	// 访问方式一
	Teacher t1("jack");
	cout << t1.count << endl;

	// 访问方式二
	Teacher::total++;
	cout << Teacher::total << endl;

	Teacher::count();

	system("pause");
}
*/

/*************************类的大小*************************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class A{
public:
	int a;
	int b;
	int c;
	static int d;
};
class B{
public:
	int a;
	int b;
	int c;
	void printModel(){  // 相当于函数指针 void(*printModel)() = printModel; 指针是4个字节, 实际不占内存

	}
};

void main(){
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;

	// c/c++ 内存分区: 栈, 堆, 全局(静态, 全局), 常量区(字符串), 程序代码
	// 只有普通属性与结构体相同的内存分布
	// 静态属性(静态区) 和 方法(代码区)不计算在类之内

	system("pause");
}
*/

/**********************this*********************/
// 函数是共享的, 必须要有能够标识当前对象是谁的办法 -> this
// this 是一个常量指针 Teacher *const this
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Teacher
{
public:
	Teacher(char* name, int age);
	~Teacher();
	void printModel(){
		printf("%#x\n", this);
		cout << this->name << " , " << this->age << endl;
	}

	// 常函数 修饰的是this
	// 保证数据安全
	void constFunc() const{ // 常函数内部不能修改this/属性的值 
		// const Teacher* const this
		// this->name = "ds";
	}
private:
	char* name;
	int age;
};

Teacher::Teacher(char* name, int age)
{
	this->name = name;
	this->age = age;
}
Teacher::~Teacher()
{
}

void main(){
	Teacher t1("abc", 10);
	t1.printModel();
	printf("%#x\n", t1);

	t1.constFunc(); // 非常量对象可以调用常量函数
	// 调用常函数
	const Teacher t2("cs", 22);
	// t2.printModel(); 常量对象不能调用非常量函数
	t2.constFunc();

	system("pause");
}
*/

/***********************友元函数**************************/
// 友元函数中可以访问类的私有属性
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class A{
private:
	int i;
public:
	A(int i){
		this->i = i;
	}

	void printModel(){
		cout << i << endl;
	}
	// 声明友元函数
	friend void modifyI(A*p, int a);
};

// 实现友元函数
void modifyI(A*p, int a){
	p->i = a;
}

void main(){
	A *a = new A(10);
	a->printModel();

	modifyI(a, 20);
	a->printModel();

	system("pause");
}
*/

/********************友元类**********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// 友元类
class A{
	friend class B;
private:
	int i;
public:
	A(int i){
		this->i = i;
	}
	void printModel(){
		cout << i << endl;
	}
};

class B{
private:
	A a;
public:
	// B 这个友元类可以访问A类的任何成员
	void accessAny(){
		a.i = 30;
	}
};

void main(){


	system("pause");
}
*/


/******************运算符重载********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Point{
public:
	int x;
	int y;
	Point(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}
	void printModel(){
		cout << this->x << " , " << this->y << endl;
	}
	// 和下面一样
	//Point operator+(Point &p2){
	//	Point tmp(this->x + p2.x, this->y + p2.y);
	//	return tmp;
	//}
};
// 重载+号
Point operator+(Point &p1, Point &p2){
	Point tmp(p1.x + p2.x, p1.y + p2.y);
	return tmp;
}

void main(){
	Point p1(100, 200);
	Point p2(200, 300);

	Point p3 = p1 + p2;
	system("pause");
}
*/

/*************************继承************************/
/*
基类中      继承方式             子类中
public     ＆ public继承        => public
public     ＆ protected继承     => protected   
public     ＆ private继承       => private

protected  ＆ public继承        => protected
protected  ＆ protected继承     => protected   
protected  ＆ private继承       => private

private    ＆ public继承        => 子类无权访问
private    ＆ protected继承     => 子类无权访问
private    ＆ private继承       => 子类无权访问
*/

/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Human{
public:
	Human(char* name, int age){
		this->name = name;
		this->age = age;
	}
	void say(){
		cout << "说话" << endl;
	}
private:
	char* name;
	int age;
};
// 继承于人类
// 只有public类型才能由子类对象访问到父类方法/属性, 子类内部不影响访问
class Man : public Human{
public:
	Man(char* name, int age) : Human(name, age){

	}
	void chasing(){
		cout << "泡妞" << endl;
	}
	void say(){
		cout << "男人说话" << endl;
	}
};

void main(){
	Man m("jj", 20);
	m.say(); // 重写父类方法
	m.Human::say();// 调用父类的方法
	m.chasing();

	//Human* hp = &m;
	//hp->say();

	//Human &h1 = m;
	//h1.say();

	system("pause");
}
*/

/*********************多继承-虚类******************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//class Person{
//public:
//	char* name;
//};
//class Citizen{
//	char* name;
//};
//// 多继承
//class Student :public Person, public Citizen{
//	void say(){
//		// 多继承存在二义性
//		// cout << name << endl; // 错误
//		cout << Person::name << endl;
//	}
//};
class A{
public:
	char* name;
};
// 虚继承 解决二义性
class B :virtual public A{

};
class C :virtual public A{

};
// 多继承
class Student : public B, public C{
	void say(){
		cout << name << endl;
	}
};
void main(){

	system("pause");
}
*/

/************************多态-虚函数**********************/
// 要实现多态, 父类声明时需加入 virtual 关键字

// 静态多态 : 函数重载
// 动态多态 : 程序运行过程中, 觉得哪个函数被调用(子类重写父类)

// 发生多态的条件
// 1. 继承
// 2. 父类的引用指向或指针指向子类的对象
// 3. 函数重写
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Plane{
public:
	// 没有实现多态的方式
	void fly(){
		cout << "飞机起飞" << endl;
	}
	// 实现多态的方式
	virtual void land(){
		cout << "飞机降落" << endl;
	}
};
class Jet :public Plane{
	// 没有实现多态的方式
	void fly(){
		cout << "直升飞机起飞" << endl;
	}
	// 实现多态的方式 -- 子类加不加 virtual 貌似都可以
	virtual void land(){
		cout << "直升飞机降落" << endl;
	}
};

void bizPlay(Plane& p){
	// 没有实现多态的方式
	p.fly();
	// 实现多态的方式
	p.land();
}

void main(){
	Plane p1;
	bizPlay(p1);

	Jet p2;
	bizPlay(p2);

	system("pause");
}
*/

/*********************抽象类/接口-纯虚函数**********************/
/*
// 抽象类和接口实现方式一样, 只是逻辑上的划分
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// 抽象类/接口 -- 具有纯虚函数的类
class Shape{
public:
	// 纯虚函数
	virtual void sayArea() = 0;
};

class Circle :public Shape{
public:
	Circle(int r){
		this->r = r;
	}
	void sayArea(){
		cout << "圆的面积" << r*r*3.14 << endl;
	}
private:
	int r;
};

void main(){
	// 抽象类不能实例化
	// Shape s;
	// 必须重写 sayArea() 抽象函数才能实例化对象, 如果没有实现, 子类也是抽象类
	Circle c1(5);
	c1.sayArea();

	system("pause");
}
*/


/*************************泛型--模板函数*********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

//void mySwap(int& a, int& b){
//	int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void mySwap(char& a, char& b){
//	char tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//}

// 函数模板 -- 解决业务逻辑一样, 数据类型不一样
template <typename T>
void mySwap(T& a, T& b){
	T tmp = 0;
	tmp = a;
	a = b;
	b = tmp;
}

void main(){
	int a = 10, b = 20;
	mySwap(a, b);
	cout << a << "," << b << endl;

	char x = 'x', y = 'y';
	mySwap<char>(x, y); // 这种写法一样的
	cout << x << "," << y << endl;
	system("pause");
}
*/


/*************************模板类*********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// 模板类
template<class T>
class A
{
public:
	A(T a){
		this->a = a;
	}
protected:
	T a;
};

// 普通类继承模板类
class B :public A<int>{
public:
	B(int a) :A<int>(a){

	}
};

// 模板类继承模板类
template <class T>
class C : public A<T>{
public:
	C(T c, T a) :A<T>(a){

	}
};

void main(){
	// 实例化模板类对象
	A<int> a(6);

	system("pause");
}
*/

/*************************异常*********************/
/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class MyException{
public:
	MyException(){

	}
};

//void main(){
//	// 根据抛出的异常数据类型, 进入相应的catch块中
//	try{
//		int age = 300;
//		if (age > 200){
//			// throw age;
//			// throw "发生异常";
//			throw 9.8;
//		}
//	}
//	catch (int a){
//		cout << "int 异常" << endl;
//	}
//	catch (char* b){
//		cout << b << endl;
//	}
//	catch (...){
//		cout << "未知异常" << endl;
//	}
//
//	system("pause");
//}

//void main(){
//	try{
//		int a = 1;
//		if (a == 1){
//			throw MyException();
//			// throw new MyException; 不要抛出指针 需要释放对象
//		}
//	}
//	//catch (MyException ex){
//		//cout << "MyException" << endl;
//	//}
//	catch (MyException* ex1){
//		// 不推荐
//		cout << "MyException指针" << endl;
//		delete ex1;
//	}
//	catch (MyException& ex2){
//		// 需要注释掉 ex, 因为1和3都可以catch到
//		cout << "MyException引用" << endl;
//	}
//}

// throw 声明函数会抛出的异常类型
void myDiv(int a, int b) throw (char *){
	if (b == 0){
		throw "除数为0";
	}
}

// 标准异常(类似于 Java 的 NullPointerException)

class NullPointerException : public exception{
public:
	NullPointerException(char* msg) :exception(msg){

	}
};

void myDiv1(int a, int b){
	if (b == 0){
		// 超出范围
		throw out_of_range("超出范围");
	}
	else if (b > 19)
	{
		throw invalid_argument("参数不合法");
	}
	else
	{
		throw NullPointerException("为空");
	}
}

void main(){
	try{
		// myDiv1(1, 0);
		myDiv1(1, -1);
	}
	catch (out_of_range e1){
		cout << e1.what() << endl;
	}
	catch (NullPointerException& e2){
		cout << e2.what() << endl;
	}

	system("pause");
}
*/


/*
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

void main(){
	system("pause");
}
*/






