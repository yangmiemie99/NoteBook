# 第一章

## 1、C++的优点

既可以用高级的编程方式编写应用程序，又可以以低级的 编程方式编写与硬件紧密协作的库。强大的灵活性，可以控制资源的使用和可用性，从而最大限度地提高性能。

## 2、编写第一个c++程序

```c++
#include <iostream>
int main()
{
    std::cout << "hello world" <<std::endl;
    return 0;
}
```

在LINUX中，可以使用如下命令编译:

gcc -o hello hello.cpp

## 3、C++的开发步骤



编写代码；通过编译创建目标文件；通过链接创建可执行文件；执行应用程序以便调试；调试；修复代码中的错误并重复这些步骤。

# 第二章

## 1、C++的组成部分

预处理器编译指令#include

程序主题

`int main() //代表程序的返回值是int`

`int main(int argc,char* argv[]) `

//main函数变种，括号内提供程序的参数，argc记录了用户在运行程序的命令行中输入的参数的个数。arg[]指向的数组中至少有一个字符指针，即arg[0].他通常指向程序中的可执行文件的文件名。在有些版本的编译器中还包括程序文件所在的路径。

返回值

## 2、命名空间

`std::cout`,cout 位于标准（std）命名空间中，让编译器知道调用那个cout。命名空间就是给代码指定的名称，有助于减低命名冲突的风险。

```c++
//方法1
//pre-processor directive
#include <iostream>
//start your programe
int main()
{
    using namespace std;
    //write to the screen using std::cout
    cout << " hello world!"<<endl;
    
    return 0;
}
//更加严谨的方式，不包含整个命名空间，只包含使用的元素
#include <iostream>
int main()
{
    using std::cout;
    using std::endl;
    cout <<"hello world!"<<endl;
    return 0;
}
```

## 3、注释

//this is a command

/*this is a command 

and it spans two lines*/

## 4、函数

```c++
#include <iostream>
using namespace std;
int fuction1();
int main()
{
    fuction1();
    return 0;
}
int fuction1()
{
    cout<< "this is a string literal"<<endl;
    cout<<"Pi when approximated is 22/7 = "<<22/7<<endl;
    cout<<"pi when accurately is 22/7 = " << 22.0/7<<endl;
    return 0;//函数的返回值
}
/*输出结果 
3
3.14268
*/
```

## 5、执行基本的输入输出操作。

 使用 std::cin和std::cout

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int inputNum;
    cout<<"Enter a integer";
    cin>>inputNum;
    string inputNam；
    cout << "Enter your name:";
    cin >> inputNam;
    
    cout << inputNam << "entered" <<inputNum <<endl;
        
    
}
```

# 第三章

## 1、变量

理解变量的作用域，标识函数结束的花括号（}）也限定了函数内部声明变量的作用域。

全局变量声明在函数外，但不分青红皂白使用全局变量是一种编程坏习惯。

|        类型        |            值            |       类型       |                          |
| :----------------: | :----------------------: | :--------------: | :----------------------: |
|        bool        |        true/false        |     int(16)      |      -32768 - 32768      |
|        char        |       256个字符值        |     int(32)      | -2147483648 - 2147483648 |
| unsigned short int |        0 - 65535         | unsigned int(16) |        0 - 65535         |
|     short int      |      -32768 - 32768      | unsigned int(32) |      0 - 4294967295      |
| unsigned long int  |      0 - 4294967295      |      float       |    1.2e-38 -- 3.4e38     |
|      long int      | -2147483648 - 2147483648 |      double      |   2.2e-308 -- 1.8e308    |

在我的电脑上看 long int 是64位的不知道为什么

而在进行隐式的整型转换的时候，一般是按照低等级整型转换为高等级整型，有符号的转换为无符号。



## 基本的内置类型

C++ 为程序员提供了种类丰富的内置数据类型和用户自定义的数据类型。下表列出了七种基本的 C++ 数据类型：

| 类型     | 关键字  |
| :------- | :------ |
| 布尔型   | bool    |
| 字符型   | char    |
| 整型     | int     |
| 浮点型   | float   |
| 双浮点型 | double  |
| 无类型   | void    |
| 宽字符型 | wchar_t |

其实 wchar_t 是这样来的：

```
typedef short int wchar_t;
```

所以 wchar_t 实际上的空间是和 short int 一样。

一些基本类型可以使用一个或多个类型修饰符进行修饰：

- signed
- unsigned
- short
- long

下表显示了各种变量类型在内存中存储值时需要占用的内存，以及该类型的变量所能存储的最大值和最小值。

**注意：**不同系统会有所差异。

| 类型               | 位            | 范围                                                         |
| :----------------- | :------------ | :----------------------------------------------------------- |
| char               | 1 个字节      | -128 到 127 或者 0 到 255                                    |
| unsigned char      | 1 个字节      | 0 到 255                                                     |
| signed char        | 1 个字节      | -128 到 127                                                  |
| int                | 4 个字节      | -2147483648 到 2147483647                                    |
| unsigned int       | 4 个字节      | 0 到 4294967295                                              |
| signed int         | 4 个字节      | -2147483648 到 2147483647                                    |
| short int          | 2 个字节      | -32768 到 32767                                              |
| unsigned short int | 2 个字节      | 0 到 65,535                                                  |
| signed short int   | 2 个字节      | -32768 到 32767                                              |
| long int           | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| signed long int    | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| unsigned long int  | 8 个字节      | 0 到 18,446,744,073,709,551,615                              |
| float              | 4 个字节      | 精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字) |
| double             | 8 个字节      | 双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字) |
| long double        | 16 个字节     | 长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。 |
| wchar_t            | 2 或 4 个字节 | 1 个宽字符                                                   |

从上表可得知，变量的大小会根据编译器和所使用的电脑而有所不同。

下面实例会输出您电脑上各种数据类型的大小。

## 实例

```c++
#include<iostream>  
 
using namespace std;  
  
int main()  
{  
    cout << "type: \t\t" << "************size**************"<< endl;  
    cout << "bool: \t\t" << "所占字节数：" << sizeof(bool);  
    cout << "\t最大值：" << (numeric_limits<bool>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<bool>::min)() << endl;  
    cout << "char: \t\t" << "所占字节数：" << sizeof(char);  
    cout << "\t最大值：" << (numeric_limits<char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<char>::min)() << endl;  
    cout << "signed char: \t" << "所占字节数：" << sizeof(signed char);  
    cout << "\t最大值：" << (numeric_limits<signed char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<signed char>::min)() << endl;  
    cout << "unsigned char: \t" << "所占字节数：" << sizeof(unsigned char);  
    cout << "\t最大值：" << (numeric_limits<unsigned char>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<unsigned char>::min)() << endl;  
    cout << "wchar_t: \t" << "所占字节数：" << sizeof(wchar_t);  
    cout << "\t最大值：" << (numeric_limits<wchar_t>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<wchar_t>::min)() << endl;  
    cout << "short: \t\t" << "所占字节数：" << sizeof(short);  
    cout << "\t最大值：" << (numeric_limits<short>::max)();  
    cout << "\t\t最小值：" << (numeric_limits<short>::min)() << endl;  
    cout << "int: \t\t" << "所占字节数：" << sizeof(int);  
    cout << "\t最大值：" << (numeric_limits<int>::max)();  
    cout << "\t最小值：" << (numeric_limits<int>::min)() << endl;  
    cout << "unsigned: \t" << "所占字节数：" << sizeof(unsigned);  
    cout << "\t最大值：" << (numeric_limits<unsigned>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned>::min)() << endl;  
    cout << "long: \t\t" << "所占字节数：" << sizeof(long);  
    cout << "\t最大值：" << (numeric_limits<long>::max)();  
    cout << "\t最小值：" << (numeric_limits<long>::min)() << endl;  
    cout << "unsigned long: \t" << "所占字节数：" << sizeof(unsigned long);  
    cout << "\t最大值：" << (numeric_limits<unsigned long>::max)();  
    cout << "\t最小值：" << (numeric_limits<unsigned long>::min)() << endl;  
    cout << "double: \t" << "所占字节数：" << sizeof(double);  
    cout << "\t最大值：" << (numeric_limits<double>::max)();  
    cout << "\t最小值：" << (numeric_limits<double>::min)() << endl;  
    cout << "long double: \t" << "所占字节数：" << sizeof(long double);  
    cout << "\t最大值：" << (numeric_limits<long double>::max)();  
    cout << "\t最小值：" << (numeric_limits<long double>::min)() << endl;  
    cout << "float: \t\t" << "所占字节数：" << sizeof(float);  
    cout << "\t最大值：" << (numeric_limits<float>::max)();  
    cout << "\t最小值：" << (numeric_limits<float>::min)() << endl;  
    cout << "size_t: \t" << "所占字节数：" << sizeof(size_t);  
    cout << "\t最大值：" << (numeric_limits<size_t>::max)();  
    cout << "\t最小值：" << (numeric_limits<size_t>::min)() << endl;  
    cout << "string: \t" << "所占字节数：" << sizeof(string) << endl;  
    // << "\t最大值：" << (numeric_limits<string>::max)() << "\t最小值：" << (numeric_limits<string>::min)() << endl;  
    cout << "type: \t\t" << "***********size**************"<< endl;  
    return 0;  
}
```

本实例使用了 **endl**，这将在每一行后插入一个换行符，<< 运算符用于向屏幕传多个值。我们也使用 **sizeof()** 函数来获取各种数据类型的大小。

当上面的代码被编译和执行时，它会产生以下的结果，结果会根据所使用的计算机而有所不同：

```
type:         ************size**************
bool:         所占字节数：1    最大值：1        最小值：0
char:         所占字节数：1    最大值：        最小值：?
signed char:     所占字节数：1    最大值：        最小值：?
unsigned char:     所占字节数：1    最大值：?        最小值：
wchar_t:     所占字节数：4    最大值：2147483647        最小值：-2147483648
short:         所占字节数：2    最大值：32767        最小值：-32768
int:         所占字节数：4    最大值：2147483647    最小值：-2147483648
unsigned:     所占字节数：4    最大值：4294967295    最小值：0
long:         所占字节数：8    最大值：9223372036854775807    最小值：-9223372036854775808
unsigned long:     所占字节数：8    最大值：18446744073709551615    最小值：0
double:     所占字节数：8    最大值：1.79769e+308    最小值：2.22507e-308
long double:     所占字节数：16    最大值：1.18973e+4932    最小值：3.3621e-4932
float:         所占字节数：4    最大值：3.40282e+38    最小值：1.17549e-38
size_t:     所占字节数：8    最大值：18446744073709551615    最小值：0
string:     所占字节数：24
type:         ************size**************
```

C++11新定义数据类型：

| 类型      | 含义        | 最小存储空间 |
| --------- | ----------- | ------------ |
| char16_t  | Unicode字符 | 2字节        |
| char32_t  | Unicode字符 | 4字节        |
| long long | 超长整型    | 8字节        |



d.dddE+n指的是将小数点向右移n位，而dddE-n指的是将小数点向左移n位。之所以称为“浮点”，就是因为小数点可移动。

浮点数a用两个数m（尾数）和e（指数）来表示：a = m × b^e   2^127*(2-2^-23)约等于2^128=3.4E+38。加上符号之后可得float表示范围为(-3.4E+38)~(3.4E+38)。当然实际是取不到的，开区间。绝对值最小则可以取到2^-127*1，即为1.175E-38。

![img](https://img-blog.csdn.net/20170802123224735?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvVm9uU2RpdGU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

float 是 32位, 其中有23位用于存放尾数, 带有一个固定隐含位… 所以float的有24个二进制有效位位数。2^24共有8个十进制位. 所以有些编译器 float的有效数字位是 8位 , 有些有效数字位是 7位.(注意不是小数的位数, 是有效数字位)double也一样,是64位, 其中有52位用于存放尾数, 一个固定隐含位. 共有 53个二进制有效位位数。2^53次方有15个十进制位, 所以有些编译器double的有效数字位是15位, 有些是16位。

## 2、sizeof确定变量长度

```c++
cout << "size of int" <<sizeof(int)
```

## 3、auto推断类型

`auto Flag = ture;`编译器检查赋值给变量的初值的性质，再确定将变量声明为什么类型合适。

## 4、使用typedef替换变量类型

`typedef unsigned int uint;`

## 5、常量

`const double PI = 22.0/7;//PI是一个double类型的常量 `

const type-name constant-name

使用constexpr声明常量

```c++
constexpr double Getpi()
{
    return 22.0/7;
}
```

枚举常量：

```c++
enum CardinalDirection
{
    North,
    South,
    East,
    West
};
CardinalDirection Mydirection = North;
//编译器默认其实的初始值为1 ，之后每一个加1
```

使用#define 定义常量：
	`#define Pi 3.14`这种方法已经基本摒弃；

练习计算周长和面积

```c++
#include <iostream>
using namespace std;
int main()
{
	const double PI = 3.1415;
	int Radius = 0.0;
	//float Perimeter = 0.0, Area = 0.0;
	cout << "请输入圆的半径：" << endl;
	cin >> Radius;
	cout << "面积 = " << PI*Radius*Radius << endl;
	cout << "周长 = " << 2 * PI*Radius << endl;
	system("pause");
	return 0;
}
```

# 第四章

## 1、数组

1.声明和初始化静态数组

`int Mynum[5] = {1,2,3,4,5}`

`int Mynum[5] = {0}`

```c++
const int ArrayLengh = 5;//当需要在多个地方访问并使用数组长度时这很有用，比如需要遍历时。
int Mynum[ArrayLengh] = {0};
```

多维数组 `int Solar[2][3] = {{1,2,3},{4,5,6}}`

2、动态数组

`std::vector`

```c++
//使用例子
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> DynArrNum(3);
	DynArrNum[0] = 1;
	DynArrNum[1] = 2;
	DynArrNum[2] = 3;
	cout << "数组中元素的个数" << DynArrNum.size() << endl;
	cout << "输入新的元素" << endl;
	int AnotherArr = 0;
	cin >> AnotherArr;
	DynArrNum.push_back(AnotherArr);
	cout << "数组中元素的个数" << DynArrNum.size() << endl;
	cout << "数组中最后的元素" << DynArrNum[DynArrNum.size() - 1] << endl;
	system("pause");
	return 0;
}
```

## 2、字符串

C语言风格的字符串是一种特殊的字符数组。

`std::cout << "hello";`

`char Sayhello[] = {'h','e','l','l','o'，'\n'};`

`std::cout << Sayhello <<endl;`

两者之间想等价。加入的\n不会影响字符串的长度。危险，自动寻找空字符。

C++ 字符串操作 `std::string`  动态，在需要更多存储数据时将其容量增大。

进行初始化字符串，用户输入，复制和拼接字符串以及确定字符串的长度。

- 直接初始化，利用小括号来完成，推荐使用，可以提高程序的效率
- 拷贝初始化，利用等号的初始化，以后使用类或者结构体中尽可能写减少这个使用方法

```c++
//定义和初始化string对象
string s1;	//定义以空字符，使用类中默认初始化
string s2 = s1;	//拷贝初始化，用s1赋值给s2
string s3 = "Hello";//拷贝初始化，用字符串字面值初始化s3
string s4(10, 'c');	//直接初始化，s4的内容是cccccccccc
string s5(s3);	//直接初始化，这是新的初始化方式，等价于s5 = s3
string s6("World");	//直接初始化，这是新的初始化方式，等价于s6 = "World"

```

**读写string对象**

```c++
//方法1
string s1;
cin >> s1;	//输入第一个非空格，换行符，制表符等字符中，遇到空格就会停止。如" hello world"
cout << s1 << endl;	//显示的是 hello
string s2, s3;
cin >> s2 >> s3; //输入"Hello world!"
cout << s2 << s3 << endl;//输出 "Helloworld"
//方法2
string content;
while (cin >> content)    //一直输入，知道遇到文件结束符
{
cout << content;
}
//方法3 推荐

string Firstline;
getline(cin,Firstline);

```

**相加**

```c++
string Concat = Firstline + " " + Secendline;
```

**string::size_type类型**
size_type是一个无符号类型的值
string::size_type从本质上来说，是一个整型数。关键是由于机器的环境，它的长度有可能不同。
添加这种类型是为了几种配套的类型，这样实现了使用的时候就与机器无关
可以通过 auto 或者decltype 来推断string类中的size()类,在使用的过程中切记不要与带符号的数混用,如与int 混用

```c++
//字符串的size_type类型
string s1("abcdefgh");
string::size_type t = s1.size();
cout << "t = " << t << endl;
auto at = s1.size();
cout << "at = " << at << endl;
//注意这个是 size_type 是一个无符号的数，如果与负数混合使用会带来如下的错误
```

**比较string对象**

可以实现以下符合的比较 == ，！= ,<,<=,>,>= 

区分大小写,规则如下

根据长度不同时，如果对应位置字符相同时，较长的大于较短的

如果对应位置不同时，直接比较第一个不同字符的结果

# 第五章

## 1、运算符

++ 和 -- 分为前缀和后缀，使用后缀运算符3时先将右值赋予给左值在,进行++或--。前缀运算符则相反。

按位运算符XOR ^ (ctrl + 6) 

```c++
//演示按位运算符的用法
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	unsigned short inputNum;
	cout << "请输入一个数字 0-255" << endl;
	cin >> inputNum;
	bitset<8> inputBit1(inputNum);
	cout << "您输入数字的二进制" << inputBit1 << endl;
	cout << "与 0x0f得" << (inputBit1 & (bitset<8>)0x0F) << endl; //注意想与需要类型一样，0x0F为int类型
	cout << "与 0x0f异或" << (inputBit1 ^ (bitset<8>)0x0F) << endl;
	system("pause");

	return 0;
}
```

## 2、使用sizeof运算符

sizeof()看上去像函数调用，但是他是运算符，程序员不能定义这个运算符，因此不能从载

## 3、运算符的优先级

简写，不一定用到。

::(作用域解析运算符)

成员选择(.)，下标(->)，函数调用，后缀递增，后缀递减

sizeof，前缀递增递减，求补(^) ，NOT，单目加减，取地址，new,new[],delete,delete[]，类型转换，sizeof()

用于指针成员的运算  .*    ->*

乘除，求模

加减

移位

不等关系

逻辑运算符

条件运算符

# 第六章 流程控制

 熟悉的不列出

```c++
switch(expression)
{
    case Lablel1:
        DOsomething;
        break;
    case Lablel2:
        DOsomethingelse;
        break;
        ....
    default:
        Dosomething;
        break;
}// Lable 经常用枚举的方式表示出来
```

条件运算符

`int Max = (Num1 >Num2)?Num1:Num2;`

不成熟的goto

```c++
somefunction()
{
    JumpToPonit; //这里定义了一个标签
    CodeRepeat;
    goto JumpRepeat;
}
```

do...while 循环

```c++
do
{
    StatementBlock;  //至少执行一次
}while(expression);
```

在for循环中也可以初始化多个变量

```c++
for(int Index = 0,OtherIndex = 1; Index < Array_Length; ++Index,--OtherIndex)
```

使用continue 和break

continue 能让您跳转懂到循环开头，跳过循环块中后面的代码，因此在while ,do,,,while,for循环中，continue导致循环条件从新评估，如果是for在评估前执行第三个表达式。

break 结束当前循环

练习

```c++
//两个数组倒序相加
#include <iostream>
using namespace std;
int main()
{
	const int Max_Array_1 = 3;
	const int Max_Array_2 = 2;
	int MyInst1[Max_Array_1] = { 1,2,3 };
	int MyInst2[Max_Array_2] = { 4,5 };
	for (int i = Max_Array_1 - 1; i >= 0; i--)
		for (int j = Max_Array_2 - 1; j >= 0; j--)
			cout << MyInst1[i] << "+" << MyInst2[j] << "=" << MyInst1[i] + MyInst2[j] << endl;
	system("pause");
	return 0;
}
```

# 第七章 函数

函数组成部分 `double Area(double InputRadius);//返回值类型，函数名，函数参数`

熟悉的部分不在列出

## 1、递归函数

递归函数必须有明确的退出条件，例子用递归函数做斐波那契函数

```c++
#include <iostream>
using namespace std;
int Fabonaqi(int SeqNum);
int main()
{
	int Index = 0;
	cout << "请输入序号" << endl;
	cin >> Index;
	cout << "结果 = " << Fabonaqi(Index) << endl;
	system("pause");
	return 0;
}
int Fabonaqi(int SeqNum)
{
	if (SeqNum < 2)
		return SeqNum;
	else
		return Fabonaqi(SeqNum - 1) + Fabonaqi(SeqNum -2);
}
```

## 2、函数从载

名称和返回值相同，但是参数不同的函数称之为函数从载。

## 3、将数组传递给函数

`int DisplayInteger(int[] Number,int Length)//输入第一个为数组，第二个参数为数组长度`

`int DispayArray(int Number[],int Length)`

## 4、按引用传递参数

```c++
void Area(double Radius ,double& Result)
{
    Result = Pi * Radius *Radius;
}

//第二个形参旁边的&告诉编译器，不要把实参传递给result,而是将该实参的引用传递给函数，面积按引用以输出参数的方式提供  
//使用return语句，函数只能返回一个值，函数需要执行影响众多值得操作，且需要在调用者中使用这些值，按引用参数的方式是让函数将修改结果提供给调用模块的方式之一。
```

## 5、内联函数

函数调用时产生压栈和出栈的操作，如果函数过于简单，相对于执行函数的时间，执行函数调用的操作可能花销更高，使用inline关键字发出请求，要求函数就地展开他们。以提高代码执行速度。

```c++
inline long DoubleNumber(int Number)
{
    return 2*Number;
}
```

## 6、lambda 函数

简单了解

语法如下：`[option parameter](parameter list){statement;}`

一元函数：接受一个参数的函数，如f(x)。如果一元函数返回一个布尔值，则该函数称为一元谓词。

二元函数：接受两个参数的函数，如f(x,y)。如果二元函数返回一个布尔值，则该函数称为二元谓词。

通常排序算法需要提供一个二元谓词。

```c++
//使用lanbda函数对数组中的元素排序并显示他们
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void DisplayNums(vector<int>& DynArray);
int main()
{
	vector<int> MyNum;
	MyNum.push_back(500);
	MyNum.push_back(200);
	MyNum.push_back(-1);
	MyNum.push_back(-20);

	DisplayNums(MyNum);

	cout << "升排序" <<  endl;

	sort(MyNum.begin(), MyNum.end(), [](int Num1, int Num2) {return (Num2 > Num1); });

	DisplayNums(MyNum);
	system("pause");
	return 0;
}
void DisplayNums(vector<int>& DynArray)
{
	for_each(DynArray.begin(), DynArray.end(), [](int Element) {cout << Element << " "; });
	cout << endl;
}
```

## 7、默认参数

函数的默认只参数应该放在列表末尾

**练习**，写一个返回值为void的含糊，在提供半径的情况下，班主计算圆的周长和面积

```c++
#include <iostream>
using namespace std; 
const double Pi = 3.14;
void Culcu_Peri_Area(double Radius, double& Perimeter, double& Area);
int main()
{
	double Radius = 0.0,Perimeter = 0.0,Area = 0.0;
	cout << "请输入半径" << endl;
	cin >> Radius;
	Culcu_Peri_Area(Radius, Perimeter, Area);
	cout << "周长 =" << Perimeter << " " << "面积 = " << Area << endl;
	system("pause");
	return 0;
}

void Culcu_Peri_Area(double Radius, double& Perimeter, double& Area)
{
	Perimeter = 2 * Pi *Radius;
	Area = Pi * Radius *Radius;
}
```

# 第八章 指针和引用

## 1、指针,引用运算符（&）

指针式存储内存地址的变量，指针变量用于存储内存地址。

`int *PInteger = NULL;`

如果Varename 是一个变量，&Varename将是存储变量的地址

使用指针获取变量的地址

```c++
int Age = 30;
int *pInteger = &Age;
```

使用解除引用运算符（*）访问指向的数据，也叫间接运算符。

```c++
int Age = 3;
int *pInteger = &Age;
cout << *pInteger << endl;//输出值为3
```

解除运算符用于指针时，应用程序从他存储开始的地址取回内存中的4个字节的内容

使用sizeof()作用于指针，得到的结果与指针变量无关和系统有关。

## 2、动态内存的分配

**1、使用new 和delete动态分配内存和释放内存**

分配如果成功，new将返回一个指针

`Type *Pointer = new Type;`

`int *Integer= new int;`

`int *Integer = new int[10]`

使用new分配的内存最终都需要相应的delete进行释放。

`delete Pointer;`

`delete[] Poniter;`

c_str() 以 char* 形式传回 string 内含字符串如果一个函数要求char*[参数](http://www.so.com/s?q=%E5%8F%82%E6%95%B0&ie=utf-8&src=internal_wenda_recommend_textn)，可以使用c_str()方法:

c_str()[函数](http://www.so.com/s?q=%E5%87%BD%E6%95%B0&ie=utf-8&src=internal_wenda_recommend_textn)返回一个指向正规C[字符串](http://www.so.com/s?q=%E5%AD%97%E7%AC%A6%E4%B8%B2&ie=utf-8&src=internal_wenda_recommend_textn)的指针, 内容与本string串相同.这是为了与[c语言](http://www.so.com/s?q=c%E8%AF%AD%E8%A8%80&ie=utf-8&src=internal_wenda_recommend_textn)兼容，在c语言中没有string[类型](http://www.so.com/s?q=%E7%B1%BB%E5%9E%8B&ie=utf-8&src=internal_wenda_recommend_textn)，故必须通过string[类对象](http://www.so.com/s?q=%E7%B1%BB%E5%AF%B9%E8%B1%A1&ie=utf-8&src=internal_wenda_recommend_textn)的[成员函数](http://www.so.com/s?q=%E6%88%90%E5%91%98%E5%87%BD%E6%95%B0&ie=utf-8&src=internal_wenda_recommend_textn)c_str()把string 对象转换成c中的字符串样式。注意:一定要使用strcpy()函数 等来操作方法c_str()返回的指针 

使用new[] 分配内存，并用delete[]释放他，例子

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout << "Enter your name" << endl;
	string Name;
	cin >> Name;
	int CharAllocate = Name.length() + 1;
	char *CopyName = new char[CharAllocate];
	strcpy_s(CopyName, CharAllocate, Name.c_str()); //三个参数
	cout << "动态内存" << CopyName << endl; //为什么不直接打印出地址？
	delete[] CopyName;
 	system("pause");
	return 0;
}
```

## 3、递增和递减运算符(++,--)用于指针的结果

指针包含内存地址，对指针进行递加或递减，编译器认为您将要指向内存块的相邻的值。

例子

`Type * pType = Adress;`

执行++pType后，pType 将包含指向 address + sizeof(pType)。

**练习，根据动态内存分配，研究指针偏移量**

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int InputNum = 0;
	cout << "how much integer you wish to enter?" << endl;
	cin >> InputNum;
	int *pNum = new int[InputNum];
	int *pCopy = pNum;   //第二个循环中改变了指针的值，pNum必须保留，delete时需要提供它
	cout << "Successfully allocated memory for" << InputNum << "integers" << endl;
	for (int Index = 0; Index < InputNum; ++Index)
	{
		cout << "int number" << Index << endl;
		cin >> *(pNum + Index);
	}

	for (int Index = 0; Index < InputNum; ++Index)
		cout << *(pCopy++) << " " <<endl;
	delete[] pNum;
 	system("pause");
	return 0;
}
```

## 4、关键字const用于指针

const指针有如下三种

**1、指针指向的数据是常量，不能修改，但可以修改指针包含的地址**

```c++
int HoursInDay = 24;
const int *pInteger = &HoursDay;
int MouthInYear = 12;
pInteger = &MouthInYear; // 可以修改指针的地址。
*pInteger = 12; //错误，不能改变数据
```

**2、指针包含的地址是常量，不能修改，但是可以改指针指向的数据**

```c++
int DayInmonth = 30;
int* const pInteger = &DayInmonth;
*pInteger = 15;  //这么修改是可行的
```

**3、指针包含的地址和它指向的值都是常量，不能修改**

```c++
int HourInDay = 12;
const int* const pInteger = &HourInDay;
```

**指针传递给函数时**，这些形式的const 很有用。函数声明应该为最严格const指针，以确保函数不会修改指针指向的值。

## 5、将指针传递给函数

例子

```c++
#include <iostream>
using namespace std;
void CalcArea(const double* const pPi, const double* const pRadius, double* const pArea)
{
	if (pPi && pRadius && pArea)
		*pArea = (*pPi) * (*pRadius) *(*pRadius);
}
int main()
{
	double Radius = 0.0;
	const double Pi = 3.1416;
	cout << "请输入半径" << endl;
	cin >> Radius;
	double Area = 0.0;
	CalcArea(&Pi, &Radius, &Area);
	cout << Area << endl;
	return 0;
}
```

## 6、数组和指针的类似之处

数组是指向其第一个元素的指针。访问元素使用MyNum[1] 和*(MyNum +1)等价。

数组名就是数组的地址。可以将数组赋给指针，但是不可以将指针赋给数组。数组是静态的不能用作左值。

lvalue（locator value）代表一个在内存中占有确定位置的对象（换句话说就是有一个地址）。 
rvalue通过排他性来定义，每个表达式不是lvalue就是rvalue。因此从上面的lvalue的定义，rvalue是在不在内存中占有确定位置的表达式。

## 7、使用指针常见错误

**1、内存泄露**

C++没用自动垃圾收集器，对已经分配但不能使用的内存不能进行清理。

使用new动态分配内存后没有使用配套的delete将其释放。

**2、指针指向无效的内存单元**

使用运算符*对指针解除引用，确保指针指向了有效的内存单元。否则程序崩溃，或行为不端（常见）。

**3、悬浮指针**

使用delete后指针无效，为了避免这种情况，很多程序员在初始化指针或释放指针后将其设置为NULL，并在解除引用前检查它是否有效。

## 8、指针编程实践

务必初始化指针变量，如果不能将指针初始化为new，初始化为NULL，使用指针前检查他是否为NULL，，务必在指针有效时使用它。

**检查new发出的内存分配请求是否得到满足**

如果内存分配失败产生bad_alloc异常。

```c++
#include <iostream>
using namespace std;
int main()
{
	try
	{
		int *pName = new  int[530000000];
		delete[] pName;
	}
	catch(bad_alloc)
	{
		cout << "内存不足" << endl;
	}
	system("pause");
	return 0;
}
```

使用new 的变种----new(nothrow),他不引发异常，而是返回NULL。

## 9、引用运算符

引用是变量的别名，声明引用时，需要将其初始化为一个变量，因此应用只是另一种访问相应变量的存储数据的方式。**引用是真正的别名，都指向相应变量的内存地址**

```c++
int Age = 20;
int &Ref= Age;
//Ref = 30; 
```

在函数中使用，参数按应用传递，不按拷贝传递 ，减小开销。避免将实参复制给形参。

**将const关键字用于引用**：

需要禁止通过引用修改它指向的变量的值

```c++
int Origin = 20;
const int& ConstRef = Origin;
ConstRef =40; //禁止
int &Ref = ConstRef;  //禁止
const int& ConstRef2 = ConstRef;
```

const引用，将参数标识符输入参数，并禁止调用的函数修改引用传入的值。

```C++
viod Calcu(const int& Num,int & Result)
{
    Result = Num *Num;
}//这里的num在函数中不能修改，在函数声明是应该尽可能提高函数的const程度
```

# 第九章 类和对象

## 1、类和对象

class{ }，创建自己的数据类型并在其中封装属性和使用他们的函数。封装：将数据方法进行逻辑编组。

在运行阶段类是对象的化身。

实例化一个对象，并通过对象访问方法和属性

```c++
Human Tom;   //实例化一个类
//就像为int动态分配内存一样，使用new为Human对象动态分配内存
Human * pAnother = new Human();  
delete pAnother;
```

使用点运算符访问成员（属性，方法）

使用指针运算符访问成员（->）访问成员，也可以用间接运算符(*)来获取对象，在用点运算符来访问成员。

```c++
(*pAnother).INtroduceyourself();
pAnother -> Dateofbirth = "1996";
delete pAnother;
```

## 2、关键字 private 和public

## 3、构造函数

在创建对象时调用，与函数一样，构造函数可以重载。与类同名且不返回任何值。

```c++
class  Human
{
    public:
    	Human();  //可以在类声明中实现也可以在类外实现
}
Human::Human()
{
    //程序段
}
 //::作用域解析运算符
```

**构造函数是初始化成员变量的理想场所**

在不提供参数的条件下调用的构造函数称之为默认构造函数，默认构造函数是可选的。

构造函数是可以从载的。如果提供了从载构造函数时，编译器不会自动生成默认构造函数。这表明创建对象时**必须提供相应参数**eg.`Human Firstname("yang",20);`

```c++
class  Human
{
    public:
    	Human()  //可以在类声明中实现也可以在类外实现
        {
            //代码段
        }
    	Human(string HumansName)
        {
            //新的代码段
        }
}
```

**带默认值的构造函数**

```c++
class Human
{
    private:
		string Name;
    	int age;
    public:
    	Human(string IntNames = "ming",int IntAge = 22)
        {
            Name = IntName;
            age = IntAge;
        }
    
    //other code
}
```

**包含初始化列表的构造函数,直接将输入的值赋给属性**

```c++
#include <iostream>
#include <string>
using namespace std;

class Human
{
private:
	string Name;
	int age;
public:
	Human(string IntNames = "yang" , int IntAge = 22) :Name(IntNames), age(IntAge)
	{
		cout << "construct a Name called  " << Name << ", Age " << age << endl;
	}

	//other code
};
int main()
{
	Human ming;
	Human yang("li", 30);
	system("pause");
	return 0;
}
```

## 4、析构函数

```c++
class Human  //可以在类声明实现，也可以在类外实现
{
    ~Human();
}

class ~Human()
{
    // destructor code
}
```

**封装一个C风格 的字符串并通过析构函数释放他**

```C++
#include <iostream>
using namespace std;
class Mystring
{
public:
	Mystring(const char* InitString)
	{
		if (InitString != NULL)
		{
			Buffer = new char[strlen(InitString) + 1];
			strcpy_s(Buffer, strlen(InitString) +1, InitString);
		}
        else
        {
            Buffer = NULL;
        }
	};
	~Mystring()
	{
		if (Buffer != NULL)
		{
			delete[] Buffer;
		}
	};
	int GetLength()
	{
		return strlen(Buffer);
	}

	const char * ShowString()
	{
		return Buffer;
	}

private:
	char* Buffer;
};

int main()
{
	Mystring Hello("My name is yangxinming");
	Hello.GetLength();
	cout << Hello.ShowString() << endl;
	system("pause");
}
```

## 5、复制构造函数

,一个特殊的重载构造函数，当对象被复制，包括按值传递给函数时，都将调用他。浅复制导致两个对象指向同一块动态分配内存，这被称为浅复制会导致程序不稳定。

### 对比拷贝构造函数和赋值运算符

的行为比较相似，都是将一个对象的值复制给另一个对象；但是其结果却有些不同，拷贝构造函数使用传入对象的值生成一个新的对象的实例，而赋值运算符是将对象的值复制给一个**已经存在的实例**。这种区别从两者的名字也可以很轻易的分辨出来，拷贝构造函数也是一种构造函数，那么它的功能就是创建一个新的对象实例；赋值运算符是执行某种运算，将一个对象的值复制给另一个对象（已经存在的）。**调用的是拷贝构造函数还是赋值运算符，主要是看是否有新的对象实例产生。如果产生了新的对象实例，那调用的就是拷贝构造函数；如果没有，那就是对已有的对象赋值，调用的是赋值运算符**。

调用拷贝构造函数主要有以下场景：

- 对象作为函数的参数，以值传递的方式传给函数。　

- 对象作为函数的返回值，以值的方式从函数返回

- 使用一个对象给另一个对象**初始化**

  调用拷贝构造函数主要有以下场景：

  - 对象作为函数的参数，以值传递的方式传给函数。　
  - 对象作为函数的返回值，以值的方式从函数返回
  - 使用一个对象给另一个对象**初始化**

  代码如下：

  ```
  class Person
  {
  public:
      Person(){}
      Person(const Person& p)
      {
          cout << "Copy Constructor" << endl;
      }
  
      Person& operator=(const Person& p)
      {
          cout << "Assign" << endl;
          return *this;
      }
  
  private:
      int age;
      string name;
  };
  
  void f(Person p)
  {
      return;
  }
  
  Person f1()
  {
      Person p;
      return p;
  }
  
  int main()
  {
      Person p;
      Person p1 = p;    // 1
      Person p2;
      p2 = p;           // 2
      f(p2);            // 3
  
      p2 = f1();        // 4
  
      Person p3 = f1(); // 5
  
      getchar();
      return 0;
  }
  ```

  上面代码中定义了一个类`Person`，显式的定义了拷贝构造函数和赋值运算符。然后定义了两个函数:`f`，以值的方式参传入Person对象；`f1`，以值的方式返回Person对象。在`main`中模拟了5中场景，测试调用的是拷贝构造函数还是赋值运算符。执行结果如下：
  ![img](https://images2015.cnblogs.com/blog/439761/201612/439761-20161207163440429-300030531.png)

  分析如下：

  1. 这是虽然使用了"="，但是实际上使用对象p来创建一个新的对象p1。也就是产生了新的对象，所以调用的是拷贝构造函数。
  2. 首先声明一个对象p2，然后使用赋值运算符"="，将p的值复制给p2，显然是调用赋值运算符，为一个已经存在的对象赋值 。
  3. 以值传递的方式将对象p2传入函数f内，调用拷贝构造函数构建一个函数f可用的实参。
  4. 这条语句拷贝构造函数和赋值运算符都调用了。函数f1以值的方式返回一个Person对象，在返回时会调用拷贝构造函数创建一个临时对象tmp作为返回值；返回后调用赋值运算符将临时对象tmp赋值给p2.
  5. 按照4的解释，应该是首先调用拷贝构造函数创建临时对象；然后再调用拷贝构造函数使用刚才创建的临时对象创建新的对象p3，也就是会调用两次拷贝构造函数。不过，编译器也没有那么傻，应该是直接调用拷贝构造函数使用返回值创建了对象p3。

**使用复制构造函数确保深复制**

```c++
class Mystring()
{
    Mystring(const Mystring& CopySource);
}
```

类中包含原始指针成员（char*）等，务必编列复制构造函数和复制赋值运算符。编写复制构造函数时，务必接收源对象为const引用。

```c++
	Mystring(const Mystring& CopySorce)
	{
		cout << "copy constructor:copy from mt string" << endl;
		if (CopySorce.Buffer != NULL)
		{
			Buffer = new char[strlen(CopySorce.Buffer) + 1];
			strcpy_s(Buffer, strlen(CopySorce.Buffer) + 1, CopySorce.Buffer);
			cout << "Buffer point to :0x" << hex << (unsigned int *)Buffer << endl;
		}
		else
		{
			Buffer = NULL;
		}
	}
```

```c++
Mystring copy(Mystring &Source)
{
	Mystring CopyForReturn(Source.ShowString());
	return CopyForReturn;
}

int main()
{
	Mystring Hello("My name is yangxinming");
	Hello.GetLength();
	cout << Hello.ShowString() << endl;
	 
	cout << "---------" << endl;

	copy(Hello); //调用一次复制构造函数

	cout << "--------" << endl;

	Mystring SayHello(Hello.ShowString()); //不调用复制构造函数

	Mystring SayHello(Copy(Hello));//调用一次复制构造函数
	system("pause");
}
```



## 6、移动构造函数

有助于改善性能，避免多次调用复制构造函数影响性能。

```c++
Mystring(Mystring && MoveSource)  //没太看懂。
{
	if(MoveSource.Buffer!=NULL)
    {
        Buffer = MoveSource.Buffer;;
        
        MoveSource.Buffer = NULL;
    }
}
```

## 7、构造函数和析构函数的其他用途

可以解决众多设计问题

**1、不允许被复制的类**

禁止对象被复制，声明一个私有的复制构造函数。为禁止复制赋值，声明一个私有赋值运算符。

```c++
class President
{
    private:
    	President(const President&);
    	President& Operator = (const President&);
}
```

**2、只能有一个实例的单例类**

静态实例成员

注：关键字static用于类成员时，该数据成员在所有实例之间共享。

将static用于函数中声明的局部变量时，该变量值在两次调用中保持不变。

将static用于函数成员时，该方法在所有成员那之间共享。

单例类，禁止复制、赋值、创建多个实例

```c++
#include <iostream>
#include <string>
using namespace std;
class President
{
	private:
		string Name;
		President() {};
		President(const President&) {};
		President & President::operator=(const President &)
		{
			// TODO: 在此处插入 return 语句
		}

	public:
		static President& GetInnstance()
		{
			static President OnlyInstance;
			return OnlyInstance;
		}
		string GetName()
		{
			return Name;
		}
		void SetName(string InitName)
		{
			Name = InitName;
		}

};
int main()
{
	President& OnlyPresident = President::GetInnstance();//不能创建President实例
	OnlyPresident.SetName("XinMing");
	cout << "The name of President is" << OnlyPresident.GetName() << endl;
	system("pause");
	return 0;
}


```

**3、禁止在栈中实例化类**

　　堆和栈的区别：
　　一、[堆栈](http://www.so.com/s?q=%E5%A0%86%E6%A0%88&ie=utf-8&src=internal_wenda_recommend_textn)空间分配区别：
　　1、栈（操作系统）：由操作系统自动分配释放 ，存放[函数](http://www.so.com/s?q=%E5%87%BD%E6%95%B0&ie=utf-8&src=internal_wenda_recommend_textn)的参数值，[局部变量](http://www.so.com/s?q=%E5%B1%80%E9%83%A8%E5%8F%98%E9%87%8F&ie=utf-8&src=internal_wenda_recommend_textn)的值等。其操作方式类似于[数据结构](http://www.so.com/s?q=%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84&ie=utf-8&src=internal_wenda_recommend_textn)中的栈；
　　2、堆（操作系统）： 一般由[程序员](http://www.so.com/s?q=%E7%A8%8B%E5%BA%8F%E5%91%98&ie=utf-8&src=internal_wenda_recommend_textn)分配释放， 若程序员不释放，[程序](http://www.so.com/s?q=%E7%A8%8B%E5%BA%8F&ie=utf-8&src=internal_wenda_recommend_textn)结束时可能由OS回收，分配方式倒是类似于[链表](http://www.so.com/s?q=%E9%93%BE%E8%A1%A8&ie=utf-8&src=internal_wenda_recommend_textn)。
　　二、堆栈缓存方式区别：
　　1、栈使用的是一级缓存， 他们通常都是被调用时处于[存储空间](http://www.so.com/s?q=%E5%AD%98%E5%82%A8%E7%A9%BA%E9%97%B4&ie=utf-8&src=internal_wenda_recommend_textn)中，调用完毕立即释放；
　　2、堆是存放在[二级缓存](http://www.so.com/s?q=%E4%BA%8C%E7%BA%A7%E7%BC%93%E5%AD%98&ie=utf-8&src=internal_wenda_recommend_textn)中，[生命周期](http://www.so.com/s?q=%E7%94%9F%E5%91%BD%E5%91%A8%E6%9C%9F&ie=utf-8&src=internal_wenda_recommend_textn)由[虚拟机](http://www.so.com/s?q=%E8%99%9A%E6%8B%9F%E6%9C%BA&ie=utf-8&src=internal_wenda_recommend_textn)的垃圾回收算法来决定（并不是一旦成为孤儿对象就能被回收）。所以调用这些对象的速度要相对来得低一些。
　　三、堆栈数据结构区别：
　　堆（数据结构）：堆可以被看成是一棵树，如：堆排序；
　　栈（数据结构）：一种先进后出的数据结构。

栈中空间有限。如果编写一个数据库内部结构包含1GB数据，禁止在栈中实例化。

**关键在于将析构函数声明为私有。**

只能在堆中实例化,需要制作一销毁实例的静态公有函数。

```c++
int main()
{
    MonsterDB *mydatebase = new MonsterDB();
    
}
class MonsterDB
{
    private:
    	~MonsterDB;
    public:
    	static void DestroyInstance(MonsterDB* Instance)
        {
            delete Instance;
        }
}
```

## 8、this指针

this包含当前对象的地址。当您在类成员方法中调用其他成员方法时，编译器将隐士传递this指针。

## 9、将sizeof用于类

指出类声明中所有的数据属性占用的总内存量。（不考虑成员函数和局部变量），可能受到结果字填充等影响。

## 10、结构不同于类的地方

关键字struct来自C语言，于类很相似，除非制定，否则结构中成员默认为共有的（类中成员默认为私有地）。

## 11、声明友元

可以从外部访问私有属性的成员和方法，使用关键字friend

```c++
class Human
{
    private:
		string Name;
    	int Age;
    
    friend void Display(cosnt Human& Person); //用引用省着它拷贝，再加个const就改不了啥东西了
    public:
    	Human(string IntNames = "ming",int IntAge = 22)
        {
            Name = IntName;
            age = IntAge;
        }
    
    //other code
}

friend void Display(cosnt Human& Person)
{
    cout << Person.Age <<endl;
}
```

让外部类utility访问私有成员。

```c++
class Human
{
    private:
		string Name;
    	int Age;
    	friend class utility;
    friend void Display(cosnt Human& Person);
    public:
    	Human(string IntNames = "ming",int IntAge = 22)
        {
            Name = IntName;
            age = IntAge;
        }
    
    //other code
}
class utility
{
    public:
    	static void DisplayAge(const Human& Person)
        {
            cout << Person.Age() << endl;
        }
}
```

# 第十章 实现继承

## 1、继承和派生

派生类继承了基类 

```c++
class base()
{
    
};
class Drived:acsess-specifier Base
{

};
```

访问限定符protected ,将属性声明为protected时，相当于允许派生类和友元类可以访问，禁止在继承结构外部。

**基类初始化，向基类传递参数**

```c++
#include <iostream>
using namespace std;

class Fish
{
protected:
	bool FreshWaterFish;
public:
	Fish(bool InitFish):FreshWaterFish(InitFish){}
	void swim()
	{
		if (FreshWaterFish)
		{
			cout << "Swim in the lake" << endl;
		}
		else
		{
			cout << "Swim in the sea" << endl;
		}
	}
};
class Tuna :public Fish
{
public:
	Tuna():Fish(false){}
};
int main()
{
	Tuna paopao;
	paopao.swim();
	system("pause");
	return 0;
}
```

**在派生类中覆盖基类**派生类实现了基类继承的函数，返回值和特征标都相同。

如果需要调用被覆盖的方法使用作用域解析运算符（::）eg.`mydinner.Fish::swim();`

在派生类中调用基类的方法`Fish::swim();`

**在派生类中隐藏基类的方法**

有两个同名函数，传入参数不同，父类的函数就被隐藏了。解决办法。

1、作用域解析运算符(::)，`mydinner.Fish::swim();`

2、在子类中用using解除对Fish::swim()的隐藏。

3、在子类中覆盖所有Fish::swim的重载版本。

**构造顺序**

基类对象在派生对象前实例化，先实例化成员属性，在调用构造函数

**析构顺序**

析构顺序与构造顺序相反

## 2、私有继承

has-a 的关系。子类有父类。制定派生类的基类时使用关键字private,基类中所有的共有成员和方法都是私有地，不能从外部访问。公有继承是is-a的关系。子类是父类。

## 3、保护继承

也表示has-a的关系。能让派生类访问基类所有的共有和保护成员，继承结构外边也不能通过派生类的对象访问基类的共有成员。

在继承结构上，子类的子类能够访问Base类的共有成员，私有继承就不行了。

**仅当必要时才使用私有或保护继承**

更好的选择是将基类的对象作为派生类的一个成员属性。

```c++
class Moter
{
    private:
    	Motor heartOfCar;
    public:
    void Move()
    {
        heartOfCar.swithIgnition();
    }
}
```

## 4、切除问题

将派生类对象复制给基类对象，编译器值复制派生类的基类部分，而不是整个对象，称之为切除。**避免切除不要安值传递参数，而是应指向基类的指针或者const引用的方式传递。

## 5、多继承

```c++
class Drived:access-specifier Base1,access-specifier Base2
{
	//
};
```

## 6、总结

通过使用访问限定符protected，可将基类的属性暴露给派生类，同时对继承层次结构外部隐藏他们。保护继承与私有继承的不同之处在于，派生类的子类可以访问基类的共有和保护成员，但是私有继承不能。

类继承默认为私有



# 第十一章 多态

## 1、基础

以类似的方式处理不同类型的对象。可以通过继承结构实现多态。

```c++
#include <iostream>
using namespace std;
class Fish
{
    public:
    	void swim()
        {
            cout << "fish swim" << endl;
        }
};
class Tuna:public Fish
{
    void swim()
    {
    	cout << "tuna swim" <<<endl;
    }
};
void MakeFishSwim(Fish& InputFish)
{
    InputFish.swim();
}
int main()
{
    Tuna Paopao;
    Tuna.swim();
    MakeFishSwim(paopao); // 此处实现父类的方法，与预想不一致，解决如下。
    return 0;
}
```

## 2、实现虚函数实现多态行为

1、通过指针或引用访问父类对象，这些指针可以指向子类，要是想实现各自的方法，在基类中将函数设置为虚函数。

```c++
class Fish
{
    public:
    	virtual void swim()  //确保编译器调用覆盖版本。
        {
            cout <<"Fish swim"<<endl;
        }
};
```

对于使用new在堆区实例化派生类的对象，如果将其赋值给基类的指针，并通过该指针调用delete，将不会调用派生类的delete，导致资源未释放，内存泄露等问。**避免这种问题可以将基类析构函数声明为虚函数**

**2、抽象基类和纯虚函数**

不能实例化的基类称为抽象基类，用图派生其他的类。要创建抽象基类，可声明纯虚函数。

```c++
class AbstrctBase
{
    public:
    	virtual void DOsomething() = 0; //纯虚方法，派生类中必须实现该方法。
}
```



虽然不能实例化抽象基类，但是可以将指针或引用的类型指定为抽象基类，**非常好的机制** 能够声明所有派生类都**必须实现的函数。**

## 3、使用虚继承解决菱形问题

​	父

子	子	子

​	子           多继承



这样由于采用了多继承，实例化派生类的子类时将实例化三个父类的对象。导致问题。

使用虚继承，如果派生类可能被用于基类，派生他最好的方式是使用关键字virtual

```c++
class Derived:public virtual Base
{
	//members and function
}
class Derived:public virtual Base
{
	//members and function
}
```

**再创建子类的时候原始的父类只构造一次。**

c++不允许使用虚复制构造函数。利用自建clone函数模拟复制构造函数

```c++
#include <iostream>
using namespace std;
class Fish
{
public:
	virtual void swim() = 0;
	virtual Fish* clone() = 0;
};
class Tuna:public Fish
{
public:
	void swim()
	{
		cout << "Tuna is swim" << endl;
	}
	Fish* clone()
	{
		return new Tuna(*this);  //不加this也没什么影响，为啥呢
	}
};
class Carp:public Fish
{
public:
	void swim()
	{
		cout << "carp is swim" << endl;
	}
	Fish* clone()
	{
		return new Carp(*this);
	}
};
int main()
{
	const int MaxIndex = 3;
	Fish* MyFishArray[MaxIndex] = { NULL };
	MyFishArray[0] = new Tuna();
	MyFishArray[1] = new Carp();
	MyFishArray[2] = new Carp();

	for (int Index = 0; Index < MaxIndex; ++Index)
	{
		MyFishArray[Index]->swim();
	}
	Fish* MyNewFishArray[MaxIndex] = { NULL };
	for (int Index = 0; Index < MaxIndex; ++Index)
	{
		MyNewFishArray[Index] =MyFishArray[Index] ->clone();  //进行拷贝
	}
	for (int Index = 0; Index < MaxIndex; ++Index)
	{
		MyNewFishArray[Index]->swim();
	}
	for (int Index = 0; Index < MaxIndex; ++Index)
	{
		delete MyFishArray[Index];
		delete MyNewFishArray[Index];
	}
	system("pause");
	return 0;
}
```

**问答**

编译器为何创建虚拟函数表？	

由于存储函数指针，确保调用正确的虚函数版本。

基类总是应该包含一个虚析构函数吗？

是的。

```c++
Base *pBase = new Derived();
delete pBase;//当且仅当虚构函数~Base声明为虚函数时，delete pBase才会调用虚构函数~Derived
```



# 第十二章 运算符类型和运算符重载

class类中不仅能封装数据和方法，还能封装运算符。

运算符声明起来和函数类似`return_type operator operator_symble(...parameter list)`

## 1、单目运算符

只对一个操作数进行操作

作为类成员的单目运算符

return_type operator operator_type()

{

}

 在类中编写单目运算符，前缀递增运算符，后缀递增运算符

处理年月日的类

**单目递增、递减运算符**

```c++
class Date
{
    private:
    int Day,Mounth,year;
    public(int InitDay,int InitMounth,InitYear):Day(InitDay),Mounth(InitMounth),year(Inityear)
    {};
    Date& operator ++ ()       //在这个类中不返回这个引用区别不大
    {
        Day++;
        return *this                        
    }
    Date operator ++ (int)     //后缀++
    {
        Date Copy(Day,Mounth,year);   //先复制原对象
        Day++;						//当前对象进行操作
        return Copy;				//返回拷贝的对象
    }
}
```

## **2、转换运算符**

cout 能够很好的解读const char * ，让cout显示data对象，只需要添加一个返回const char* 的运算符

 //这块不太懂以后仔细研究

```c++
class Date
{
    //...
    private: 
    	string DateInstring;
}
operator cosnt char*()
{
    ostringstream formattedDate;     // std:: ostringstream
    formattedDate << Day << "/" << Mounth << "/" << year; //局部变量不能直接返回
    DateInString = FormattedDate.str();   //将转换出来的std::string对象保存起来，不能直接返回
    return DateInString.c_str();		//局部变量在返回时销毁
}
int main()
{
    //简写
    Date Oneday(1,1,1001);
    cout << Oneday <<endl;    //将oneday转化成const char*运算符
}
```

## 3、解除引用运算符（*）和成员选择运算符（->）

看完模版再回来看

```c++
#include <iostream>
using namespace std;

template <typename T>
class smart_pointer
{
private:
	T* m_pRawPointer;
public:
	smart_pointer(T* pData):m_pRawPointer(pData){};
	~smart_pointer(){delete m_pRawPointer;};
	T& operator* () const
	{
		return *(m_pRawPointer);
	}
	T* operator-> () const
	{
		return m_pRawPointer;
	}

};

class Data
{
private:
	int Day,Month,Year;
	string DataInString;
public:
	Data(int inputDay,int inputMonth,int inputYear):Day(inputDay),Month(inputMonth),Year(inputYear){};
	void Display()
	{
		cout << Day << '/' << Month << '/' <<Year << endl;
	}
};

int main()
{
	smart_pointer<Data> pData(new Data(10,10,1996));
	cout << "Data is" <<endl;
	pData -> Display();
	return 0;

}
```



## 4、双目运算符

全局函数或静态函数的方法实现双目运算符的定义

`return_type operator_type (parameter1,parameter2)`

以类成员方式实现的双目运算符只接受一个参数，**原因是第二个参数通常从类属性中获得 。**

**1、双目加法运算符**

```c++
	Date operator +(int Daystoadd)
	{
		Date newDate(month, day + Daystoadd, year);
		return newDate;
	}
```

实现第九章Mystring类的＋

```c++
Mystring operator + (Mystring& addstring)
{
    Mystring Newsting;
    if(addstring != NULL)
    {
        Newstring.Buff = new char[GetLength() + strlen(addstring.Buff) +1];  //第一个字符串的长度加第二个的
        strcpy(Newstring.Buff,Buff);
        strcat(Newstring.Buff,addstring.Buff);
    }
    return Newstring;
}
```

实现运算符+=

```c++
void operator += (int addDays)
{
    Day += addDays;
}
```

**从载运算符 = =**

如果没有从载运算符，编译器将对这两个对象的二进制进行比较。如果遇到 char * 即使内容相同也会返回false

```c++
bool operator == (cosnt Date& compareto)
{
    return ((Day == compareto.Day && Mounth == compareto.Mounth && year == compareto.year));
}
```

**从载运算符 < ,>= 和 < =**

```c++
bool operator< (const Date& compareTo)
{
	if (year < compareTo.year)
		return true;
	else if ((year == compareTo.year) && (month < compareTo.month))
		return true;
	else if ((year == compareTo.year) && (month == compareTo.month)
		&& (day < compareTo.day))
		return true;
	else
		return false;
}
bool operator <= (const Date& Compare)
{
    if(this ->opreator== (Compare)) //这里this是一个指针，调用之前定义的方法
        return true;
    else return  (this -> operator< (Compare));
}
```

 **从载赋值运算符 = **

确保深复制

```c++
ClassType& operator= (const ClassType&CopySource)
{
    if(*this != &CopySource)
    {
        //
    }
    return *this;
}
```

对第九章的程序改进

```c++
Mystring& operator= (const Mystring& Copysource)
{
    if((this != &Copysource) && (Copysource != NULL))
    {
        if(Buff != NULL) 
            delete[] Buff;
        Buffer = new char[strlen(Copysource.Buff) +1];
        strcpy(Buffer,Copysource.Buffer);
    }
    return *this;    //this指针解除运算符，返回Mystring类。
}
```

**下标运算符**

访问数组一样的访问类。

```c++
const char&  operator[] (int Index) const   //const防止外部直接用[]运算符直接修改成员Buffer
    //第二个const防止禁止该运算符修改类的成员属性，即this指针的指向的值（也就是成员变量）都是不可修改。
{
    if(Index < strlen(Buffer))
        return Buffer[Index];
}
```

双目运算符可以被从新定义或者从载。

## 5、函数运算符operator()

让对象像函数，通常用于标准模版库中，通常是STL算法中。通过操作数的数量，这样的函数对象称为单目谓词或者双目谓词。

```c++
class Display()
{
	public:
		void operator() (string Input)const
        {
            cout << Input <<endl;
        }
}
```

## 6、移动构造函数和移动赋值运算符

**只有动态分配的资源才会导致复制构造函数和复制赋值运算符进行不必要的内存分配和释放，在没有动态资源分配的类中，不需要提供这样的函数**

**避免了复制不必要的临时值（当前语句执行完就不在存在的右值）**

创建按值返回的临时拷贝时，执行赋值构造函数，然而生成的临时拷贝在该表达式执行完毕后就不复存在。当编译器意识到要创建临时拷贝时，将转用移动构造函数和移动赋值运算符。**将资源转移到目的地**，不用进行复制。

**这两个函数使用之前，与复制构造函数和移动赋值构造函数一样，使用复制构造函数编译器调用一个默认构造函数创建默认的对象，这个对象将作为函数的返回值，使用移动构造函数主函数通常会创建一个对象**

````c++
Mystring(Mystring&& MoveSource)   //移动构造函数
{
    if(MoveSouece != NULL)
    {
        Buffer = MoveSource.Buffer;
        MoveSource.Buffer = NULL;
    }
}
Mystring& operator= (Mystring&& Movesource)  //移动赋值运算符
{
    if((Movesource != NULL) && (this ! = Movesource))
    {
        delete Buffer;
        Buffer = Moesource.Buffer;
        Movesource.Buffer = NULL;
    }
    return *this;
}
````

**注意：对于包含原始指针的类，务必给他提供复制赋值运算符。，对于管理动态分配资源（如数组）的类，务必提供移动赋值运算符，和移动构造运算符**

**对于您自己编写的智能指针类的时候，除非实现 *和->，否则他就不是指针，另外，除非您实现析构函数，并对复制赋值和复制构造的情况深思熟虑，否则 他就不够智能**

**在C++中不允许连个函数名称相同但是返回值类型不同**

练习

```c++
//以Date编写一个类型转换运算符，将存储的日期转化为整数
#include <iostream>
using namespace std;
class Date
{
    private:
    	int year,mouth,day;
    public:
    	operator int() 
        {
            return (year * 10000 +mouth *100+day);
        }
}
int main()
{
    return 0;
}
```



```c++
//DynIntegers类以私有成员int*私有成员的方式封装了了一个动态分配的数组，请给他编写移动构造函数和移动赋值运算符
#include <iostream>
using namespace std;
class  DynIntegers
{
private:
	int* pIntegers;
public:
	DynIntegers(DynIntegers&& MoveSource)
	{
		if (MoveSource.pIntegers != NULL)
		{
			pIntegers = MoveSource.pIntegers;
			MoveSource.pIntegers = NULL;
		}
	}
	DynIntegers& operator= (DynIntegers&& MoveSource)
	{
		if ((MoveSource.pIntegers != NULL) && (this != &MoveSource))
		{
			delete[] pIntegers;
			pIntegers = MoveSource.pIntegers;
			MoveSource.pIntegers = NULL;
		}
		return *this;
	}
	~DynIntegers() { delete[] pIntegers; }
};
```

# 第十三章 类型转换运算符

类型转换并不是改变了对象本身而是暂时或永久改变了对对象的解释。

有些C++程序员不喜欢C风格的类型转换因为，C风格的类型转换实际上是强迫编译器遵循自己的意见，破坏其倡导的类型安全。

C++提供了一种新的类型转换运算符，专门用于基于继承的情形。

## 1、使用static_cast

**用于在相关类型的指针之间进行转换，还可以显示执行标准数据类型的类型转换，这种转换原本将自动或隐式的进行。不执行运行阶段的检查**

使用static_cast可以将 指针向上转换为基类型（无需显示转换运算符就可以进行），向下转换为派生类型。

```c++
Base *pBase = new Base();
Derived* pDerived = static_cast<Derived*>(pBase);   //指向的其实是一个不完整的pDerived类型
//基类的对象调用派生类的函数可能会出现错误
```

还可将隐士类型转化为显示转换

```c++
double PI = 3.1415;
int NUM = static_cast<int>(PI);//引起读者的注意，不加也是可以的；
```

## 2、使用dynamic_cast和运行阶段类型识别

在运行阶段执行类型转换。可检查dynamic_cast的运行结果以判断类型转换是否成功。

```C++
destination_type* pDest = dynamic_cast<class_type*>(pSource);
if(pDest)
    pDest -> Callfuc;         //检查dynamic_cast的操作结果，以判断转换是否成功。
```

## 3、使用reinterpret_cast   重新解释

与C的风格想近，不管相关与否强行重新解释类型。

```c++
Base *pBase = new Base();
CUnrelated* pCUnrelated = reinterpret_cast<pCUnrelated*>(pBase); 
```

## 4、使用const_cast

让程序员关闭对象的访问修饰符const.

例如，在类中显示函数应该是const

```c++
class Someclass
{
    public :
    	void DisplayMember();  //在这里没有定义为CONST
}
```



```c++
viod DisplayDate(const Someclass& mDate)
{
    mDate.DisplayMembers();  //编译失败，以const引用传入mDate对象，不能调用非CONST函数。
    //这样写,也可以用与指针。
    Someclass& refDate = cosnt_cast<Someclass&>(mDate);
    refDate.DisplayMembers;
    //用指针的方式
    Someclass *refData = const_cast<Someclass*>(mData)
    refData -> DisplayMembers;
}
//都可以用c风格的类型转换代替
Derived* pDerivedSimple = (Derived*)pBase;
```

**注意：**

类向上转换是安全的，向下转换是不安全的，（Derived*）   (Base *)。除非使用Dynamic

创建继承函数时，应该尽量将函数声明为虚函数，这样通过基类指针调用这样的函数时，如果指针指向派生对象，调用相应的函数版本。

# 第14章 宏和模版简介

## 1、预处理和编译器

预处理器在编译器之前运行，预处理编译指令都以#打头。

## 2、使用#define定义常量

`#define ARRAY_LEBGH 25`

`#define MY_DOUBLE double`

`#define FAV_WISKY "IAC　DAN"`

对于预处理器定义的东西它不知道数据类型，可能导致编译错误。

因此定义常量时，使用关键字const就好很多。

```c++
const int ARRAY_LIGHT =25;
const char* FAV_WISKY = "IAC　DAN";
typedef double MY_DOUBLE        //使用typedef作为一个类型的别名
```

使用宏避免多次包含

C++程序员通常在.h中声明类和函数，在.cpp中定义函数，因此需要在.cpp文件使用预处理器编译指令 #include<header>包含头文件

避免两个头文件相互包含导致递归。结合使用#ifdef 和##endif

```c++
#ifndef HEADER_H_
#define HEADER_H_

#endif
```

## 3、使用define编写宏函数

编写简单函数

`#define SQURE(x) ((x)*(x))`

`#define MAX(a,b) ((a>b)?(a):(b))`

`#define AREA(r) (PI*(r)*(r))`   使用这么多括号的原因是避免简单的文本破坏编程的逻辑，让代码不受优先级的影响

**使用assert宏验证表达式**

包含<assert.h>,      assert(表达式的值是true 或者false)

`assert(sayhello != NULL)   //丢出消息，如果sayhello = NULL`

使用宏定义可以减少代码量，可以用于不同精度的类型，简单的宏性能优于函数常规调用，

**存在的问题，不支持任何形式的类型安全。**

可以使用内联函数inline就地展开。

## 4、模版

模版让程序员能够定义一种适用于不同类型的对象的行为。安全。

模版的语法template    

`template <parameter list >`模板参数列表，定义了若干类型的局部变量，但是并没有指出如何初始化，在运行时，调用者提供实参来初始化形参。编译器生成的版本通常称为模板的实例。

`template function /class declaration`

```c++
template <typename T1,template T2 = T1> //关键字typename,定义了模版参数objectType,用T代替了int,float之类的东西,T表示一个类型
bool TemplateFuction(const T1& param1,const T2& param2);

template <typename T1,template T2 = T1>
class Template
{
private:
	T1 m_obj1;
    T2 m_obj2;
    
public:
    T1 GetObj1(){return m_obj1;}
    //  ...othermembers
}

template <typename A>
const A& GetMax(cosnt A& NUM1,const A& NUM2)
{
    if(NUM1 >=NUM2)
    {
        return NUM1;
    }
    else
        return NUM2;
}
//调用它 GetMax<int> (Integer1,Integer2)
//调用模版函数也不一定指定它的类型  GetMax(Integer1,Integer2),对于模版类必须指定它的类型
#include <iostream>
#include <string>
using namespace std;
template <typename A>
const A& GetMax(const A& NUM1, const A& NUM2)
{
	if (NUM1 >= NUM2)
		return NUM1;
	else
		return NUM2;
};
template <typename B>
void DisplayFunction(const B& value1, const B& value2)
{
	cout << "GETMAX(" << value1 << "," << value2 << ") =";
	cout << GetMax<B>(value1, value2);
}
int main()
{
	string Name1("Jack");
	string Name2("John");
	DisplayFunction(Name1, Name2);
	system("pause");
	return 0;
}
```

```c++
//简单的模版类

template <typename A>
class MyFirstTemplateClass
{
    private:
    	A Value;
    public:
    void Setvalue(const A& InitValue){
        Value = InitValue;
    }
    const A& GetValue() const
    {
        return Value;
    }
}
//调用
MyFirstTemplateClass<int> Myclass;
Myclass.SetValue(5);
Myclass.GetValue();
```

可以声明包含多个参数的模版，以便存储不同类型的对象，也可包含默认类型

`template <typename A = int ,typename B = int>`

**模版类与静态成员**

由特定具体化的所有实例之间共享。如果将类成员声明为静态的，该成员将由类的所有实例共享。如果模板类T包含静态成员函数X,那么该成员在针对int具体化的所有实例之间共享。同样的它还针对double具体化的所有实例之间共享。

```c++

template <typename T>
class TestStatic
{
public:
	static int staticVal;
};

// static member initialization，初始化模板类的静态成员函数。
template<typename T> int TestStatic<T>::staticVal;

int main()
{
	TestStatic<int> intInstance;
	cout << "Setting staticVal for intInstance to 2011" << endl;
	intInstance.staticVal = 2011;

	TestStatic<double> dblnstance;
	cout << "Setting staticVal for Double_2 to 1011" << endl;
	dblnstance.staticVal = 1011;

	cout << "intInstance.staticVal = " << intInstance.staticVal << endl;
	cout << "dblnstance.staticVal = " << dblnstance.staticVal << endl;

	return 0;
}
```

**使用static_assert 执行编译阶段的审查**

static_assert(要验证的表达式，不满足时的错误信息)。

`static_assert(sizeof(T) != sizeof(int),"no int please")`

**在编写函数时，局部变量不能返回为引用**



小练习，编写一个简单的模版类，存储两个数组，模版应该包含存储器函数，用于操作数组的元素等

```c++
//不完善
#include <iostream>
//#define muliplate(a,b) ((a) * (b))
using namespace std;

template <typename T>
class Array
{
private:
	T array1[10];
	T array2[10];
	int array1Index = 0;
	int array2Index = 0;
public:
	void array1Append(const T& Value) //必须加const,非常量的引用初始值必须为左值，那样就不能用字符初始化了。
	{
		array1[array1Index] = Value;
		array1Index++;
	}
	void array2Append(const T& Value)
	{
		array2[array2Index] = Value;
		array2Index++;
	}
	const T& array1Get(const int Index)
	{
		return array1[Index];
	}
	const T& array2Get(const int Index)
	{
		return array2[Index];
	}
};

int main()
{
	Array <char> myArray;
	myArray.array1Append('a');
	cout << myArray.array1Get(0) << endl;
	system("pause");
	return 0;
}
```



# 第15 章 标准模板库

标准模板库（STL）是一组模版类和函数

STL容器 ：用于存储信息



## 1、顺序容器

按顺序存储数据，如数组和列表。插入速度较快，但是查找操作较慢的特征。

std::vector 操作与动态数组类似，在最后插入数据。

std::deque 与上述类似，但允许在开头插入数据

std::list 操作与双向链表一样

std::forward_list 类似一个单向链表，只能沿着一个方向遍历；

## 2、关联容器

降低插入数据的速度，但是在查询方面有很大的优势。

std::set 存储各不相同的值。插入时进行排序，容器的复杂度为对数。

std::unordered_set 存储各不相同的值。插入时进行排序，容器的复杂度为常数。

std::map  存储 键值对，并根据唯一的键排序。容器的复杂度为对数。

std::unordered_map 存储 键值对，并根据唯一的键排序。容器的复杂度为对数。

std:: multiset 与set类似，但允许存储多个值相同的项

std:: unordered_multiset    与unordered_set 类似，但允许存储多个值相同的项

std:: multimap     与map类似但是不要求键唯一

std::unordered_multimap 与unordered_map类似，不要求键是唯一的



**容器优缺点**
　　用哪种容器的选择看起来非常繁琐，头脑中如果有个每个容器大概的模型，在选择的时候会更为轻松点。

Vector的数据模型就是数组。

　优点：内存和C完全兼容、高效随机访问、节省空间

　缺点：内部插入删除元素代价巨大、动态大小查过自身容量需要申请大量内存做大量拷贝。

List 的数据结构模型是链表

　优点：任意位置插入删除元素常量时间复杂度、两个容器融合是常量时间复杂度

　缺点：不支持随机访问、比vector占用更多的存储空间

Deque的数据模型是数组和链表的折衷：

　优点：高效随机访问、内部插入删除元素效率方便、两端push pop

　缺点：内存占用比较高

Map、set、multimap、multiset的数据结构模型是二叉树(红黑树)

　优点：元素会按照键值排序、查找是对数时间复杂度、通过键值查元素、map提供了下标访问

容器类型	容器特性

vector	典型的序列容器，C++标准严格要求次容器的实现内存必须是连续的唯一可以和标准C兼容的stl容器，任意元素的读取、修改具有常数时间复杂度，在序列尾部进行插入、删除是常数时间复杂度，但在序列的头部插入、删除的时间复杂度是O(n)，可以 在任何位置插入新元素，有随机访问功能，插入删除操作需要考虑

deque	典型的序列容器，C++标准严格要求次容器的实现内存必须是连续的，唯一可以和标准C兼容的stl容器，任意元素的读取、修改具有常数时间复杂度，在序列尾部进行插入、删除是常数时间复杂度，但在序列的头部插入、删除的时间复杂度是O(n)，可以 在任何位置插入新元素，有随机访问功能，插入删除操作需要考虑

list	典型的序列容器，C++标准严格要求次容器的实现内存必须是连续的，唯一可以和标准C兼容的stl容器，任意元素的读取、修改具有常数时间复杂度，在序列尾部进行插入、删除是常数时间复杂度，但在序列的头部插入、删除的时间复杂度是O(n)，可以 在任何位置插入新元素，有随机访问功能，插入删除操作需要考虑

set	关联容器，元素不允许有重复，数据被组织成一棵红黑树，查找的速度非常快，时间复杂度是O(logN)

multiset	关联容器，和set一样，区别是允许有重复的元素，具备时间复杂度O(logN)查找功能 。

map	关联容器，按照{键，值}方式组成集合，按照键组织成一棵红黑树，查找的时间复杂度O(logN)，其中键不允许重复

multimap	和map一样，区别是键可以重复

## 3、容器适配器

顺序容器和关联容器的变种。

## 4、STL迭代器

STL迭代器是模版类，从某种程度上说，他们是范泛型指针。这些模版类能够让程序员对STL容器进行操作，注意，操作也可以是函数模板提供的STL算法。迭代器是一座桥梁，模板函数能够以一只而无缝的方式处理容器。

### 输入迭代器

通过对输入迭代器的解除引用，他将引用对象，而对象可能位于集合之中，最严格的输入迭代器只能以只读的方式访问对象。

### 输出迭代器

输出迭代器让程序员对集合执行写入操作。最严格的输出迭代器只能执行写入操作。

### 细化

前向迭代器，输入和输出迭代器的细化，前向迭代器可以是const的，只能读取他指向的对象。通常用于单向链表。

双向迭代器，前向迭代器的细化，可对其执行递减操作，从而向后移动。通常用于双向链表。

随机访问迭代器，双向迭代器的细化，可以将其加减一个偏移量，还可以将两个迭代器相见以得到集合中两个元素的相对距离。

## 5、STL算法

查找排序和反转都是编程的标准需求，STL算法提供这些函数，通过使用这些函数和迭代器，允许程序员执行一些最常见的操作。迭代器为容器和算法之间建立桥梁，让算法不知道容器类型的条件下进行操作。

常用的STL算法如下所示。

```python
std::find:   #在集合中查找值
std::find_if: #跟据用户指定的谓词在集合中查找值
std::reverse: #反转集合中元素的排列顺序
std::remove_if: #跟据用户定义得谓词将元素从集合之中删除
std::transform: #使用用户定义的变换函数对容器中的元素进行变换
 

#这些算法都是std命名空间中的模板函数。要使用他们必须包含标准文件头<algorithm>
```

## 6、使用迭代器在容器和算法之间交互

例子

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector <int> vecIntegerArray;
	vecIntegerArray.push_back(1);
	vecIntegerArray.push_back(22);
	vecIntegerArray.push_back(2233);
	vecIntegerArray.push_back(34);
	cout << "the constant of vector are:" <<endl;
	vector <int>::iterator iArrayWalker = vecIntegerArray.begin();
	while(iArrayWalker != vecIntegerArray.end())
	{
		cout << *iArrayWalker <<endl;
		++iArrayWalker;
	}

	//find  an element 2233
	vector<int>::iterator iElement = find(vecIntegerArray.begin(),vecIntegerArray.end(),2233);

	if (iElement != vecIntegerArray.end());
	{
		int Positon = distance(vecIntegerArray.begin(),iElement); // 计算元素所处位置的偏移量
		cout << "Value " <<*iElement;
		cout << "found in the vector at position" << Positon <<endl;
	}

}
```

所有的容器都提供了begin()指向第一个元素和end()函数指向最后一个元素的后面。

C++11  使用关键字auto 确定类型

`vector <int>::iterator iArrayWalker = vecIntegerArray.begin();`

上面的迭代器定义起来很复杂，可以使用auto代替

`auto iArrayWalker = vectIntegerArray.begin();` 

## 6、STL字符串类

std::string 基于char的std :: basic_string 具体化，用于操纵简单的字符串。

std::wstring 基于wcahr 的std::basic_string 的具体化,用于操纵宽字符串。





# 第16章 STL String类

可提供的帮助，减少了程序员创建和操作字符串方面需要做的工作。在内部管理内存分配细节，提高了应用程序的稳定性，提供了复制构造函数和赋值运算符。提供了帮助执行复制，截断，查找和删除等实用函数。提供了比较运算符。让程序员精力放在程序主体而不是字符串操作上

## 1、使用STL String类

复制，连接，查找字符和子字符串，截断，使用标准模板库提供算法实现字符串反转和大小写转换。

### 1、实例化和复制STL

```c++
//可以使用常量字符串初始化STL String 对象或将常量字符串赋值给STL string对象
const char* constCStyleString = "Hello world!";
std::string strFromconst(constCStyleString);
std::string strFromconst=constCStyleString;
//
std::string str2("Hello string!");
//用一个string来初始化另一个
std::string str2Copy(str2)
//可以让string构造函数只接受输入字符串的前n个字符
std::string strPatialCopy(constCStylyString,5);
//包含指定数量的特定字符
std::string strRepeatChar(10,'a');
```

### 2、访问std:string之中的字符内容

要访问stl string之中的字符内容，可以使用迭代器，也可以使用类似于数组的语法使用[]提供偏移量，要获得string对象的C风格表示，可以使用成员函数c_str()

```c++
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string strSTLstring("Hello world!");
   // size_t在C语言中就有了。它是一种“整型”类型，里面保存的是一个整数，就像int, long那样。这种整数用来记录一个大小(size)。size_t的全称应该是size type，就是说“一种用来记录大小的数据类型”。
   //使用[]来访问
    for(size_t ncharCounter =0;ncharCounter < strSTLstring.length(); ++ncharConter)
    {
        cout << strSTLstring[ncharCounter] <<endl;
    }
    //使用迭代器进行索引
    for(icharactorLocator = strSTLstring.begin();
        icharactorLocator < strSTLstring.end();
       icharactorLocator++)
    {
        cout << *icharactorLocator <<endl;
    }
    //打印全部的
    cout << strSTLstring.c_str() << endl;
}
```

### 3、拼接字符串

可以使用运算符+= ,还可以使用成员函数append

```c++
string strsample1("hhello");
string strsample2("string!");
strsample1 += strsample2; //使用 std::string::operator+=
strsample1.append(strsample2);
```

### 4、查找字符串

提供成员函数find,有多个重载版本，给定对象中查找字符或者是字符串。

```c++
//从位置0开始查找
size_t charPos = strsample.find("day",0);
//检查是否检测到，如果没有检测到，charPos 之中的值为-1
if (charPos != string::npos)
    cout << "First instant of day was found at position" << charpos <<endl;
else
    cout << "substring not found" <<endl;
```

### 5、截断STL string

提供erase函数

```c++
//给定偏移位置和字符数时删除指定数目的字符
string strsample("adfadfa faadfaf");
strsample.erase(13,20);
//给定指向字符迭代器时删除字符
strsample.erase(ichars);
//两个迭代器范围时删除该范围的字符
strsample.erase(strsample.begin(),strsample.end());
strsample.clear();
```

### 6、字符反转

有时需要反转字符串中的内容使用泛型算法，std::reverse:

```c++
string strsample("Hello string ,i will reverse you");
reverse(strsample.begin(),strsample.end());
```

### 7、字符串大小写转换

可以使用算法std::transform 

```c++
using namespace std;
string stringInput;
getline(cin,strInput);
cout <<endl;
//向上转换，转换为大写字母
trasform(stringInput.begin(),stringInput.end(),stringInput.begin(),toupper);
//向下转换，成小写字母
tranform(stringInput.begin(),stringInput.end(),stingInput.begin(),tolower);
```

 

### 8、转换为字符串

功能：将数字常量转换为字符串

 

参数：value

 

返回值：转换好的字符串

 

定义于头文件

std::string to_string(int value); (1) (C++11起) 
std::string to_string(long value); (2) (C++11起) 
std::string to_string(long long value); (3) (C++11起) 
std::string to_string(unsigned value); (4) (C++11起) 
std::string to_string(unsigned long value); (5) (C++11起) 
std::string to_string(unsigned long long value); (6) (C++11起) 
std::string to_string(float value); (7) (C++11起) 
std::string to_string(double value); (8) (C++11起) 
std::string to_string(long double value); (9) (C++11起)

### 9.其他常用 

            pos=str.find_first_of(' ',i);//相当于返回每个空格的索引值,如果找不到空格则-1
            string temp=str.substr(i,pos-i);//截取单词
### std::string 基于 std::basic_string< T >实现



## 练习开始，编！

1、判断一个单词是否为回文

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string mystringInput;
	getline(cin,mystringInput);
	string mystringInput2 = mystringInput;
	reverse(mystringInput2.begin(),mystringInput2.end());
	if(mystringInput == mystringInput2)
	{
		cout << "是回文" <<endl;
	}
	else
	{
		cout << "不是回文" <<endl;
	}
	return 0;
}
```

2、告诉句子中包含多少元音字母

```c++
#include <iostream>
#include <algorithm>
using namespace std;
//我的写法
int main()
{
	string mystringInput;
	getline(cin,mystringInput);
	string::iterator count;
	int i = 0;
	for (count = mystringInput.begin(); count != mystringInput.end(); ++count)
	{
		if (*count == 'a' || *count == 'e'|| *count == 'i'|| *count == 'o'|| *count == 'u')
		{
			i++;
		}
	}
	cout << i << endl;
	return 0;
} 
//答案的写法，通用性更强了，学习学习
int GetNumCharcters(string & strInput,char chToFind)
{
	int nNumCharacterFind = 0;
	size_t ncharOffset = strInput.find(chToFind);
	while(ncharOffset != string::npos)
	{
		nNumCharacterFind++;
		ncharOffset = strInput.find(chToFind,ncharOffset+1);
	}
	return nNumCharacterFind;
}
int main()
{
	string mystringInput;
	getline(cin,mystringInput);

	int nNumVowels = GetNumCharcters(mystringInput,'a');
	nNumVowels += GetNumCharcters(mystringInput,'e');
	nNumVowels += GetNumCharcters(mystringInput,'i');
	nNumVowels += GetNumCharcters(mystringInput,'o');
	nNumVowels += GetNumCharcters(mystringInput,'u');

	cout << nNumVowels <<endl;
	return 0;
}
```

3、将字符串的字符交替的转换为大写

```c++
int main()
{
	string mystringInput;
	getline(cin,mystringInput);

	string::iterator npointer;
	for(npointer = mystringInput.begin();npointer != mystringInput.end();npointer+= 2)
	{
		*npointer = toupper(*npointer);
	}

	cout << mystringInput <<endl;

	return 0;
}
//答案用判断长度的方式写的
for(size_t ncharIndex = 0; ncharIndex < strInput.length(); ncharIndex+=2)
{
    strInput[ncharIndex] = toupper(strInput[ncahrIndex]);
}
```



# 第 17 章 STL动态数组类

std::vector 是一个模板类，提供了动态数组的功能，在数组尾部插入、删除 元素时间固定，在数组中间添加元素所需时间和该元素后面的元素个数成正比。

## 1、实例化vector

```c++
std::vector<int> vecDynamic;
std::vector<float> vecDynamic;
std::vector<Tuna> vecDynamic;

//指向list元素中的迭代器,如果需要课修改值的迭代器用iterator
std::list<int> const_iterator iElenmentSet;

//各种初始化的方式
//使用初始化列表
std::vector<int> vecDynamic = {1,2,3,45,6};
// 初始化十个单元，可以增长
std::vector <int> vecwithTenElenment(10);
//初始化十个单元，内容全为90
std::vector <int> vecWithTenInitializeElenmet(10,90);
//用一个初始化另一个
std::vector<int> vectorCopy(vecwithTenElenment);
//使用迭代器复制前五个元素
std::vector<int> vectorCopy(vecWithTenInitializeElenmet.begin(),
                            vecWithTenInitializeElenmet.begin() +4);

```

## 2、末尾插入元素

```c++
std::vector<int> vecDynamic;
vecDyanmic.push_back(50);
```

## 3、使用insert 在指定位置插入元素

```c++

//z在开始插入把元素
vecIntegere.insert(vecInteger.begin(),14);
//指定插入位置，插入元素个数，插入的值
vecInteger.insert(vecInteger.end(),2,30);
//将另一个vector中的内容插入到指定位置
vector <int> vecAnother(2,10);
vecInteger.insert(vecInteger.begin+1,vecAnother.begin(),vecAnother.end());
```

这个操作开销很大，如果使用频繁插入，因该用std::list

## 4、使用数组语法和指针问vector中的元素

```c++
std::vector<int> vectorArray(10);
vectorArray[2] = 2011;
//上述情况如果超出边界就不安全了，使用成员函数at(),在这样超出边界就会引发异常
vectorArray.at(2);

//使用指针访问
std::vector<int> vecDynamic = {1,2,3,45,6};
auto iElementLocator = vecDynamic.begin();

while(iElenmetLocator != vecDynamic.end())
{
    Index = distance(vecDynamic.begin(),iElenmetLocator);
    cout << Index << "is " << *iElenmentLocator <<endl;
    ++iElenmtLocator;
}








```



## 5、删除vector中的元素

正像所说的那样，只能通过容器的成员函数来删除元素。可以通过使用 vector 的成员函数 clear() 来删除所有的元素。例如：

```c++
std::vector<int> data(100, 99);// Contains 100 elements initialized to 99
data.clear(); // Remove all element
```

第一条语句创建了一个有 100 个 int 型元素的 vector 对象，它的大小和容量都是 100；所有元素的初始值都是 99。第二条语句移除了所有的元素，因此大小变为 0，因为这个操作并没有改变容器的容量，所以容量还是 100。

可以使用vector成员函数pop_back()来删除尾部的元素。例如：

```c++
std::vector<int> data(100, 99); // Contains 100 elements initialized to 99
data.pop_back(); // Remove the last element
```

第二条语句移除了最后一个元素，因此 data 的大小变为 99，容量还是 100。只要不在意元素的顺序，就可以通过删除最后一个元素的方式来删除容器的任何元素，这不需要移动大量元素。假设要删除 data 中的第二个元素，可以像这样操作：

```c++
std::swap(std::begin(data)+1,std::end(data)-1);// Interchange 2nd element with the last data.pop_back(); // Remove the last element
```

第一条语句调用了模板函数 swap()，它在头文件 algorithm 和 utility 中都有定义。这个函数将第二个元素和最后一个元素互相交换。然后调用 pop_back() 移除最后一个元素，这样就从容器中移除了第二个元素。
注意，vector 也有成员函数 swap()，这个函数用来交换两个 vector 容器中的元素。显然，这两个容器的元素类型必须相同。全局的 swap() 函数只要将两个容器作为参数，也可以交换它们的元素。

如果要去掉容器中多余的容量，例如不再向容器中添加新元素，那么可以通过使用成 员函数 shrink_to_fit() 来实现：

```c++
data.shrink_to_fit(); // Reduce the capacity to that needed for elements
```

不管这个操作是否依赖STL的实现，如果它生效了，那么这个容器现有的迭代器都失效，所以在执行完这个操作后，最好重新获取迭代器。

可以使用成员函数 erase() 来删除容器中的一个或多个元素。如果只删除单个元素，那么只需要提供一个参数，例如：

```c++
auto iter = data.erase(std::begin(data)+1); //Delete the second element
```

删除一个元素后，vector 的大小减 1；但容量不变。会返回一个迭代器，它指向被删除元素后的一个元素。这里的返回值和表达式 std::begin(data)+1 相关；如果移除了最后一个元素，会返回 std::end(data)。

如果要移除一个元素序列，只需要传入两个迭代器，用来指定移除元素的范围。例如：

```c++
// Delete the 2nd and 3rd elements
auto iter = data.erase(std::begin(data)+1,std::begin(data)+3);
```

不要忘记，第二个迭代器指向这段元素末尾的下一个位置。上面的语句删除了位于 std::begin(data)+1 和 std::begin(data)+2 的元素。返回的迭代器指向被删除元素后的位置，它是 std::begin(data)+1 ；如果删除了最后一个元素，它就是 std::end(data)。

remove() 算法由定义在 algorithm 头文件中的模板生成，它可以删除匹配特定值的一段元素。例如：

```c++
std::vector<std::string> words { "one", "none","some", "all”, "none", "most","many"};
auto iter = std::remove(std::begin(words), std::end(words), "none");
```

第二条语句在头两个参数指定的元素范围内，移除了所有匹配 remove() 的第三个参数 string("none") 的元素。移除元素这个表述有一点误导，remove() 是一个全局函数，所以它不能删除容器中的元素。remove() 移除元素的方式和从字符串中移除空格的方式相似，都是通过用匹配元素右边的元素来覆盖匹配元素的方式移除元素。图 1 展示了这个过程：

![img](http://c.biancheng.net/uploads/allimg/180912/2-1P9121100234T.jpg)
											图 1 remove() 算法的工作原理
如果在 remove() 操作后输出 words 中的元素，只会输出前 5 个元素。尽管 size() 返回的值仍然是 7，而且最后两个元素仍然存在，但是它们被替换成了空字符串对象。为了摆脱这些多余的元素，可以使用成员函数 erase()。remove() 返回的迭代器可以这样使用：

```c++
words.erase(iter, std::end(words)); //Remove surplus elements
```

这被叫作 erase-remove，执行删除操作后，iter 指向最后一个元素之后的位置，所以它标识了被删除序列的第一个元素，被删除序列的结束位置由 std::end(words) 指定。当然，在一条语句中，也能先移除元素，然后再删除末尾不想要的元素：

erase 和 remove结合

```c++
words.erase(std::remove(std::begin(words),std::end(words),"none"), std::end(words));
```

remove() 算法返回的迭代器作为 erase() 的第一个参数，erase() 的第二个参数是所指向容器中最后一个元素后一个位置的迭代器。了解如何为 vector 容器分配额外容量，可以让你明白会产生多少额外开销，以及可分配的内存量。下面是一个示例，可以让你了解到这一点：

```c++
// Understanding how capacity is increased in a vector container
#include <iostream>                            
// For standard streams
#include <vector>                               
// For vector container
int main()
{
    std::vector <size_t> sizes;                    
    // Record numbers of elements
    std::vector <size_t> capacities;               
    // and corresponding capacities
    size_t el_incr {10};                      // Increment to initial element count
    size_t incr_count {4 * el_incr};          // Number of increments to element count
     for (size_t n_elements {}; n_elements < incr_count; n_elements += el_incr)
    {
        std::vector<int> values(n_elements);
        std::cout << "\nAppending to a vector with " << n_elements << " initial elements:\n";
        sizes.push_back(values.size());
       	size_t space {values.capacity()};
        capacities.push_back(space);
        // Append elements to obtain capacity increases
        size_t count {};                             
         // Counts capacity increases
        size_t n_increases {10};
        while (count < n_increases)
        {
            values.push_back(22);                      
            // Append a new element
            if (space < values.capacity())             
                // Capacity increased...
            {                                            
                // ...so record size and capacity
                space = values.capacity();
                capacities.push_back(space);
                sizes.push_back(values.size());
                ++count;
            }
        }
        // Show sizes & capacities when increments occur
        std::cout << "Size/Capacity: ";
        for (size_t i {}; i < sizes.size(); ++i)
            std::cout << sizes.at(i) << "/" << capacities.at(i) << "  ";
        std::cout << std::endl;
        sizes.clear();       // Remove all elements
        capacities.clear();  // Remove all elements
    }
}
```

这个示例中的操作很简单。向容器中添加元素，直到不得不增加容器容量，这时候容器的大小和容量会被保存在 sizes 和 capacities 容器中。对不同初始元素个数的容器重复几次这种操作。编译器得到的输出结果如下：

```
Appending to a vector with 0 initial elements:
Size/Capacity: 0/0  1/1  2/2  3/4  5/8  9/16  17/32  33/64  65/128  129/256  257/512

Appending to a vector with 10 initial elements:
Size/Capacity: 10/10  11/20  21/40  41/80  81/160  161/320  321/640  641/1280  1281/2560  2561/5120  5121/10240

Appending to a vector with 20 initial elements:
Size/Capacity: 20/20  21/40  41/80  81/160  161/320  321/640  641/1280  1281/2560  2561/5120  5121/10240  10241/20480

Appending to a vector with 30 initial elements:
Size/Capacity: 30/30  31/60  61/120  121/240  241/480  481/960  961/1920  1921/3840  3841/7680  7681/15360  15361/30720
```

不同编译器的输出结果可能不同，这取决于用来增加 vector 容量的算法。从第一组的输出可以看出，当开始使用一个空的 vector 时，需要频繁地分配更多的内存，因为容量增量很小——内存从一个元素开始增加。其他组的输出表明，容量增量和容器的大小相关。每次分配，会额外分配相当于当前元素数目 50% 的内存。这意味着在能够选择容器初始大小时，需要注意一些事情。

假设生成了一个初始容量为 1000 个元素的 vector，但实际上存储了 1001 个元素。这样就会有用于 499 个元素的多余容量。如果元素是数组或其他不会占用太多空间的对象，这不会有任何问题。但是如果对象非常大，例如每个 10KB，那么程序需要分配几乎 5MB 的多余内存。所以，最好可以稍微高估 vector 的初始大小，而不能低估。

## 6、理解大小和容量

vector的大小指的是实际存储元素的个数，容量是指再从新分配内存以存储更多元素之前，vector能存储元素的个数。

```c++
vecInteger.size(); //大小

vecInteger.capacity(); //容量
```



## 7、STL deque 类

也是一个动态数组类，不过支持在数组开头和末尾插入或删除元素。实例化

`deque <int> dqIntegers;`

可以使用 push_front() 和pop_front() 在开头插入和删除元素

## 小练习，编就完事了

1、编写一个交互程序，他接受用户输入整数并存储到vector中。用户能够随时使用索引查询vector中的值，使其能告诉用户，他查询的值是否在vector中

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;



int main()
{
	vector <int> vecInitial;
	int myFlag = 0;

	while(myFlag != 3)
	{
		cout << "查询请按1,输入请按2,退出请按3,查询请按4" << endl;
		cin >> myFlag;

		if( myFlag == 2)
		{
			int inputData;
			cin >> inputData;
			cout << "请输入数据" <<endl;
			vecInitial.push_back(inputData);
		}
		else if(myFlag == 1)
		{
			int Index;
			cout << "请输入查询的下标 0 -- " << (vecInitial.size() - 1) <<endl;
			cin >> Index;
			if (Index < vecInitial.size())
			{
				cout << "position" << Index << " is " << vecInitial[Index] <<endl;
			}
		}
		else if (myFlag == 4)
		{
			int findData;
			cout << "请输入要查寻的数据" << endl;
			cin >>findData;
			auto iElenment = find(vecInitial.begin(),vecInitial.end(),findData);
			if( iElenment != vecInitial.end() )
			{

				//cout << "数据所处位置为" << (&*iElenment - &*vecInitial.begin())<<endl;
				auto Index1 = distance(vecInitial.begin(),iElenment);
				cout << "数据所处位置为" << Index1 <<endl;
				
			}
			else
			{
				cout << "没找到数据" <<endl;
			}
		}
	}	
 	return 0;
}
```



# 18 、 STL list 和 forword_list 

在标准模板库(STL) 以模板类 std::list 的方式向程序提供了一个双向链表。主要优点是，插入和删除元素的速度快，且时间是固定的， std::forward_list 只能沿着一个方向遍历。

#include <list>               std命名空间中的模板类

## 1、基本的list 操作

### 1、实例化对象

```c++
std::list<int> listIntegers;
std::list<float> listIntegers;
//指向list中元素的迭代器
std::list<int>::const_iterator iElementInset;

// 初始化空列表
std::list<int> listIntegers;
//初始化10个整数的列表
std::list<int> listInteger(10);
//初始化10个樟树单元的列表，每个数都是99
std::list<int> listInteger(10,99);
//拷贝一个list
std::list<int> ListCopy(listInteger);
//使用vector 初始化list
std::vector<int> vectorIntial(10,200);
list<int> ListCopyFromVector(vectorIntial);

```

### 2、在list开头、中间或者结尾插入数据

```c++
//在尾部插入数据
listIntegers.push_back(-1);
listIntegers.push_back(2001);
//在开头插入数据
listIntegerss.push_front(20);
//在中间插入元素
listIntegers.insert(listIntegers.begin(),2);
//在位置0插入4个1
listIntegers.insert(listIntegers.begin(),4,1);
//第一个为位置参数，后面两个为迭代器
listIntegers2.insert(listIntegers2.end(),listIntegers.begin(),listIntegers.end())
```

### 3、删除list 中的元素

```c++
//接受迭代器参数并删除迭代器指向的元素
listIntegers.erase(iValue);
//接受两个迭代器参数
listIntegers.erase(listIntegers.begin(),listIntegers.end());

//可以用size()的方法确定std::list的大小，适用于所有的STL容器

```



### 4、对list的元素进行反转和排序

`listIntegers.reverse();`    //反转排序

list成员函数sort有两个版本

```c++
listIntegers.sort(); // 升序排列

//接受一个二元谓词函数作为参数，指定排序的标准
bool SortPrediction_Deceding(const int& lsh,const int& rlsh)
{
    return (lsh > rlsh)
}
listIntegers.sort(SortPrediction_Deceding);
```



### 5、包含list对象的元素类型为类，实现排序要进行运算符重载实现运算符  <,和删除其中的 元素 

```c++

struct ConscatItem
{
    string strContactsName;
    string strPhoneNum;
    string strDisplayRepresentation;
    
    ContactItem(const string& strName,const string & strNUm)
    {
        strContactsName = strName;
        strPhoneNum = strNUm;
        strDisplayRepresentation = (strContactsName + " :" strPhoneNUm);
	}
  	bool operator == (const CantactItem& itemTOcampare) const
    {
        return (itemTOcampare.strContactsName == this -> strContactsName);
    }
    bool operator < (const ContactItem& itemTOCampare) const
    {
		return (this -> strConstsName < itemTOCompare.strConstsName);	
    }
    operator char*() const
    {
        return strDisplayRepresentation.c_str();
    }
};
bool SortOnNUm(const ContactItem& item1,const Contacr& item2)
{
    return (item1.strPhoneNUm < item2.strPhoneNUm)
}
//编写一个通用显示函数
template <typename T>
void DisplayContacts(const T& Input)
{
    for(auto iElenment = Input.begin();iElemet != Input.end();  ++iElenmet)
    {
        cout << *iElenment <<endl;
    }
    cout <<endl;
}
int main()
{
    list <ContactItem> Contacts;
    Contacts.push_back(ContactItem("yang"."10086"));
    Contacts.push_back(ContactItem("xin","20017"));
	//按字母升序排列
	Contacts.sort();   
    //按照数字升序排列
    Contacts.sort(SortOnNUM);
    //删除一个元素,使用之前实现的 运算符== 将对象与list 元素进行比较，运算符在姓名相同的时候返回TUre
    Contacts.remove(ContactsItem("yang",""));
}
//可以用list::clear() 清空list

```



### 6、 std::forward_list

插入元素时只能使用push_front(),只能对迭代器使用++而不能使用--，比双向链表占用的内存少。



## 小练习

1、接受用户输入的数字将他们插入到list的开头

```c++
#include <list>
using namespace std;

template <typename T>
void DisplayFuctionn(const T& InputElenmet)
{
	for (auto iElement = InputElenmet.begin();iElement != InputElenmet.end();++iElement)
	{
		cout << * iElement <<endl;
	}
	cout <<endl;
}

int main()
{
	int Input = 0;
	list <int> listInitial = {1,2,1,4};

	cin >> Input;
	listInitial.push_front(Input);	
	DisplayFuctionn(listInitial);
 	return 0;
}
```





## 发现的问题

1、std::list是顺序容器，但不是随机访问容器（仅有std::vector，C数组和c++11中的std::array是），所以其迭代器只支持++和--这种双向的链式操作（c++11中的slist则只支持++）。



2、如果想一次移动多个位置，也可以使用<iterator>里的advance函数，例子如下：

```c++
list<int>::iterator it = mylist.begin();
advance (it,5);
cout << "The sixth element in mylist is: "<< *it << endl;`
```



2、使用程序证明，在list中插入一个新元素，导致迭代器指向的元素相对位置发生变化后，迭代器依然有效。

```c++

int main()
{
	int Input = 0;
	list <int> listInitial = {1,2,1,4};

	cin >> Input;
	listInitial.push_front(Input);	
	DisplayFuctionn(listInitial);

	auto ipElement = listInitial.begin();
    //迭代器指向对象向后移动两个
	advance(ipElement,2);

	cout << *ipElement <<endl;
	//插入后迭代器指向的元素不改变
	listInitial.insert(ipElement,15);

	cout << *ipElement <<endl;

 	return 0;
}
```



3、使用list 的insert函数将一个vector的内容插入到一个 STL list 中。

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename T>
void DisplayFuctionn(const T& InputElenmet)
{
	for (auto iElement = InputElenmet.begin();iElement != InputElenmet.end();++iElement)
	{
		cout << * iElement <<endl;
	}
	cout <<endl;
}

int main()
{
	std::vector<int> v = {1,2,3,4,5,6};
	int Input = 0;
	list <int> listInitial(10);

	listInitial.insert(listInitial.begin(),v.begin(),v.end());

	DisplayFuctionn(listInitial);
 	return 0;
}
```





# 第19 章 STL集合类

便于应用程序进行频繁快速的搜索。std::set 和 std::multiset 用于存储一组经过排序的元素，后者能够存储重复的值，其时间复杂度为对数。能在容器中快速的查找键。而unordered集合的插入和查找时间是固定的。

## 1、STL set 和 multiset的基本操作

### 1、实例化对象

```c++
std::set<int> setIntegers;
std::multiset<int> msetIntegers;

std::set<Tuna> setIntegers;
//声明一个指向ste或multiset中元素的迭代器,如果需要修改值，或调用非const函数的迭代器用iterator
std::set<int>::const_iterator iElements;

//set 和 multiset 都是在插入时对元素进行排序，默认是用谓词std::less ，保证升序排列
//创建二维排序谓词，在类中定义一个operator() ，接受两个参数，并根据V排序标准返回ture.
template <typename T>
struct SortDesceding
{
    bool operator() (const T& lhs,const T& rhs) const
    {
        return (lhs > rhs)
    }
};
set <int, DortDesceding<int>> setIntegers;
multiset<int> msetIntegers2(setIntegers.cbegin(),setIntegers.cend());
```

### 2、插入元素

```c++
//这里的插入不用指定位置，默认按照升序排列
setIntegers.insert(-1)
msetIntegers.insert(setIntegers.cbegin(),setIntegers.cend())
//统计元素的个数
msetIntegers.count(300)
```

### 3、查找元素

set,multiset,map,mutimap等关联容器提供了成员函数find()

```c++
auto iElementFound = setIntegers.find(-1);
//检查是否查找到
if (iElementFound != setIntegers.cend())
	cout << *iElementFound << "found!" << endl;
else
{
    cout << "Elements not found in set" << endl;
}

```

### 4、删除STL set 或 multiset 中的元素

set,multiset,map,mutimap等关联容器提供了成员函数erase()

```c++
//能让我跟据键删除值
setObject.erase(-1);
//接受迭代器作为参数，并删除迭代器指向的元素
setObject.erase(iElement);
//通过迭代器指定的边界，删除
setObject.erase(iLowerBound,iUpperBound);
//删除指定范围的元素
std::multiset<int> mIntegers;
mIntegers.insert(-1);
mIntegers.insert(44);
mIntegers.insert(45);
mIntegers.insert(45);
std::multiset<int>::iterator iElementFound = mIntegers.find(45);
if (iElementFound != mInteger.cend())
{
    //删除前两个元素，不包括45！！！
    mIntegers.erase(mIntegers.cbegin(),iElementFound);
}
```

## 2、实际应用 电话簿的简单实现

```c++
#include <set>
#include <iostream>
#include <string>
using namespace std;

//打印各种容器之中的值
template <typename T>
void DisplayConstents (const T& input)
{
	for(auto iElement = input.cbegin(); iElement != input.cend();++iElement)
	{
		cout << *iElement <<endl;
	}
};
struct ContactItem
{
	string strContactsName;
	string strContactsNum;
	string DisplayRepresesbtation;
	ContactItem(const string& strName,const string& stringNum):strContactsName(strName),strContactsNum(stringNum)
	{
		DisplayRepresesbtation = (strName + ':' +stringNum);
	}
	//运算符重载用于之后的find 和 sort
	bool operator == (const ContactItem& itemCompare) const
	{
		return (itemCompare.strContactsName == this -> strContactsName);
	}
	bool  operator < (const ContactItem& itemCompare) const
	{
		return (this -> strContactsName < itemCompare.strContactsName);
	}
	operator const char*() const
	{
		return DisplayRepresesbtation.c_str();
	}
 };

int main()
{
	set<ContactItem> setContacts;
	setContacts.insert(ContactItem("yang","123455"));
	setContacts.insert(ContactItem("xin","123456"));
	setContacts.insert(ContactItem("ming","123477"));
	setContacts.insert(ContactItem("hao","34235"));
	setContacts.insert(ContactItem("ren","63455"));
	DisplayConstents(setContacts);

	cout << "请输入想删除的人名" << endl;
	string NameInput;
	getline(cin,NameInput);

	auto iContactFound = setContacts.find(ContactItem(NameInput,""));
	if (iContactFound != setContacts.cend())
	{
		setContacts.erase(iContactFound);
		cout << "删除之后" <<endl;
		DisplayConstents(setContacts);
	}
	else
	{
		cout << "啥也没找到" <<endl;
	}
	return 0;
}
```



## 3、使用set 和 multiset 的优缺点

对于需要频繁查找的应用程序来说很有优势。应为其中的内容是排序的，容器在插入时元素进行排序，有额外的开销。find()内部利用了二差树结构，就有了一个缺点，**在顺序容器中可以使用新值替换迭代器指向的元素。但是set跟据元素的值进行了为排序，因此不能用迭代器覆盖之前的值。**



## 4、STL散列集合实现 std::unordered_set 和 std::unorsered_multiset

程序员和数学家都喜欢固定的查询时间，使用散列函数计算出唯一的一个索引，在跟据这个索引约定将元素放在哪个桶（bucket）中。

#include <unordered_set> 相比与set差别不大

**重要的的特征是，有一个负责确定排列顺序的散列函数**

`unordered_set<int> useInt;`

`unordered_set<int>::hasher HFn = usettInt.hash_fuction();`

```c++
//实现常用的一些方法
template <typename T>
void DIsplayConstents(const T& Input)
{
    //元素个数
    cout << Input.size() <<endl;
    //桶的个数
    cout << Input.max_bucket_count() <<endl;
    //负载系数  ， 桶被分配的比例
    cout << Input.load_factor() << endl;
    //最大负载系数
    cout << Input.max_load_factor() <<endl;
}
```



注意：

务必使用 multiset::count(value) 确定有几个元素包含特定的值。使用set::size() 指出容器中包含多少元素。使用.操作就可以调用了。不要忘了实现operator == < ,==用于find函数，< 将成为排序谓词。



## 5、一些问题

声明按照降序排列的set，set<int> 定义了一个整形set,使用默认排序谓词std::less < T > 将元素按照升序排列，将set定义为  set< int ,greater< int> > 



电话簿增加功能，按照电话删除

```c++
#include <set>
#include <iostream>
#include <string>
using namespace std;

//打印各种容器之中的值
template <typename T>
void DisplayConstents (const T& input)
{
	for(auto iElement = input.cbegin(); iElement != input.cend();++iElement)
	{
		cout << *iElement <<endl;
	}
};
struct ContactItem
{
	string strContactsName;
	string strContactsNum;
	string DisplayRepresesbtation;
	ContactItem(const string& strName,const string& stringNum):strContactsName(strName),strContactsNum(stringNum)
	{
		DisplayRepresesbtation = (strName + ':' +stringNum);
	}
	//运算符重载用于之后的find 和 sort
	bool operator == (const ContactItem& itemCompare) const
	{
		return (itemCompare.strContactsName == this -> strContactsName);
	}
	bool  operator < (const ContactItem& itemCompare) const
	{
		return (this -> strContactsName < itemCompare.strContactsName);
	}
	operator const char*() const
	{
		return DisplayRepresesbtation.c_str();
	}
 };
template <typename T>
struct FindContactNumber
{
	bool operator() (const T& lcn,const T& rcn) 
	{
		return (lcn.strContactsNum < rcn.strContactsNum);
	};
};
int main()
{
	set<ContactItem,FindContactNumber<ContactItem>> setContacts;
	setContacts.insert(ContactItem("yang","123455"));
	setContacts.insert(ContactItem("xin","123456"));
	setContacts.insert(ContactItem("ming","123477"));
	setContacts.insert(ContactItem("hao","34235"));
	setContacts.insert(ContactItem("ren","63455"));
	DisplayConstents(setContacts);

	cout << "请输入电话" << endl;
	string NumInput;
	getline(cin,NumInput);

	auto iContactFound = setContacts.find(ContactItem("",NumInput));

	cout << "找到的数据为" << *iContactFound <<endl;
	if (iContactFound != setContacts.cend())
	{
		setContacts.erase(iContactFound);
		cout << "删除之后" <<endl;
		DisplayConstents(setContacts);
	}
	else
	{
		cout << "啥也没找到" <<endl;
	}
	return 0;
}
```



2、定义一个multiset 存储单词的含义，用multiset用作词典

```c++
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
string str;
struct PARE_WORD_MEANING
{
	string strWord;
	string strMeaning;
	string strwdMning;
	PARE_WORD_MEANING(const string& strWordInput,const string& strMeaningInput):strWord(strWordInput),strMeaning(strMeaningInput)
	{
		strwdMning = strWord +':' +strMeaning;
	};
	bool operator < (const PARE_WORD_MEANING& pairotherword) const
	{
		return (this -> strWord < pairotherword.strWord);
	}
	operator const char*() const
	{
		// string concat;
		// concat = this -> strWord + this -> strMeaning;
		// cout << concat << endl;
		// cout << this -> strWord + this -> strMeaning << endl;	
		// str += concat;
		return strwdMning.c_str();
	}
};

template <typename T>
void DisplayFuction(const T& InputElenmet)
{
	for (auto iElement = InputElenmet.begin();iElement != InputElenmet.end();++iElement)
	{


		
		cout << *iElement <<endl;
	}
	// cout <<endl;
}

int main()
{
	multiset<PARE_WORD_MEANING> msetDictionary;
	msetDictionary.insert(PARE_WORD_MEANING("C++" , "A language"));
	msetDictionary.insert(PARE_WORD_MEANING("xinming" , "A good person"));
	DisplayFuction(msetDictionary);

	cout << str << endl;
 	return 0;
}



-------------------------------------------------------------------
    ------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
string str;
struct PARE_WORD_MEANING
{
	string strWord;
	string strMeaning;
	//string strwdMning;
	PARE_WORD_MEANING(const string& strWordInput,const string& strMeaningInput):strWord(strWordInput),strMeaning(strMeaningInput)
	{
		//strwdMning = strWord +':' +strMeaning;
	};
	bool operator < (const PARE_WORD_MEANING& pairotherword) const
	{
		return (this -> strWord < pairotherword.strWord);
	}
	operator const char*() const
	{
		//直到这个程序运行结束依然存在，不能将局部变量返回为const
		static string concat;
		concat = this -> strWord + this -> strMeaning;
		// cout << concat << endl;
		//cout << this -> strWord + this -> strMeaning << endl;	
		str += concat;
		return concat.c_str();
	}
};

template <typename T>
void DisplayFuction(const T& InputElenmet)
{
	for (auto iElement = InputElenmet.begin();iElement != InputElenmet.end();++iElement)
	{


		
		cout << *iElement <<endl;
	}
	// cout <<endl;
}

int main()
{
	multiset<PARE_WORD_MEANING> msetDictionary;
	msetDictionary.insert(PARE_WORD_MEANING("C++" , "A language"));
	msetDictionary.insert(PARE_WORD_MEANING("xinming" , "A good person"));
	DisplayFuction(msetDictionary);

	//cout << str << endl;
 	return 0;
}    
```



# 第20 章 STL映射类

map 和mutimap 是一种键-值对容器，支持跟据键进行查找。前者只能存放唯一的键，后者能存放重复的键。

内部结构看起来像二叉树，在插入元素时进行排序，不能使用其他远呢素替换给定位置的元素。

#include < map >

## 1、 map 的一些基本操作

### 1、实例化

```c++
//实例化语法
#include <map>
using namespace std;
//第三个模板参数是可以选择的默认 std::less<T>
map<keyType,valueType,Predicate = std::less<KeyType>> mpaObject;
//
map<string,int> mapStringToInt;

#include <iostream>
#include <map>
using namespace std;
// 将结构体当成函数用
template <typename T>
struct ReverseSort
{
	bool operator () (const T& lkey,const T& rkey)
	{
		return (lkey > rkey)
	}
}

int main()
{
	map<int, string> mapIntToString1;
	multimap<int,stirng> mmapIntToString1;
	//用另个map初始化
	map<int ,string> mapIntToString2(mapIntToString1);
	multimap<int ,string> mmapIntToString2(mmapIntToString1);
	//用其他map的一部分初始化 
	map<int,string> mapIntToString3(mapIntToString1.cbegin(),mapIntToString1.cend());
	//用其他的map反转后初始化
	map<int,string,ReverseSort<int>> mapIntToString4(mapIntToString1.cbegin(),mapIntToString1.cend());
	return 0;
}
```





### 2、在map中插入元素  打印

```c++
map<int,string> mapIntTppstring;
//使用make_pair 函数
mapIntTostring.insert(make_pair(-1,"Minus one"));
//也可以使用std::pair来指定要插入的键值
mapIntTostring.insert(pair<int ,string>(100,"one hundrod"));
//使用value_type 插入
mapIntTostring.insert(map<int,string>::value_type(3,"three"));
//使用类似数组的语法插入
mapIntTostring[1000] = "one thousand";


//打印与之前有所不同
template <typename T>
void DisplayFuction(const T& InputElenmet)
{
	for (auto iElement = InputElenmet.begin();iElement != InputElenmet.end();++iElement)
	{
//  打印key ,value
		cout << iElement ->first <<"->" << iElement -> second <<endl;
	}
	// cout <<endl;
}
//计算key 1000的个数
mmapIntToString.count(1000);
```



### 3、查找元素 打印

提供成员函数find能够跟据键查找值。find()中是否那会一个迭代器

```c++
multimap <int,string>::const_iterator iPairFound = mapInteTostring.find(1000);
//检查迭代器是否查找成功
if (iPairFound != mapIntTostring.end())
{
    cout << iPairFound -> first << "--key" <<endl;
    cout << iPairFound -> second << "--value" <<endl;
}
else
{
    cout << "啥也没有" << endl;
}
//容器中包含多个键值相同的键值对，为此可以使用multimap::count()确定有几个值与键对应，再跟据迭代器的递增，以访问这些相邻的值。
auto iPairFound = mmapIntToString.find(key);
if (iPairFound != mmapIntToString.end())
{
    size_t nNumPairsInMap = mmapIntToString.count(1000);
    for (size_t nValuesCounter=0;nValuesCounter < nNumPairsInMap; ++ nValuesCounter)
    {
        cout << "key:" << iPairFound -> first<<endl;
        cout << "value:" << iPairFound -> second <<endl;
        ++iPairFound;
    }
}
```

### 4、删除STL map 或 STL multimap

```c++

mapObject.erase(key);
mapObject.erase(iElment);
//指定范围，迭代器的边界的所有元素从map,multimap中删除
mapObject.erase(iLowerBound,iUpperBound);
//返回的值为删除元素的个数
auto NumpairsErase = mmapIntToString.erase(-1);
//可以使用 函数 lower_bound() upper_bound() 指定范围
mmapIntToString.erase(mmapIntToString.lower_bound(1000),mmapIntToString.upper_bound(1000));
```



## 2、提供自定义的排序谓词

```c++
//默认使用std::less<>提供排序标准
//编写一个二元谓词---实现了operator() 的类或者结构
//降序排列
template <typename T>
struct Predicate
{
    bool operator() (const T& key1,const T& key2)
    {
        return (key1 > key2);
    }
}
//小用途，执行插入和搜索操作时不区分的小写
//在实例化map时提供了一个排序谓词，他跟据不区分大小写的比较结果返回True 或 false

struct PreIgnoreCase
{
    bool operator() (const string& str1,const string& str2) const
    {
        string str1Nocase(str1),str2NoCase(str2);
        std::transform(str1.begin(),str1.end(),str1Nocase.begin(),tolower);
       	std::transform(str2.begin(),str2.end(),str2Nocase.begin(),tolower);
  		return (str1Nocase < str2Nocase);      
    };
};
```



 注意：非常适合存储键值对，在查找方面。性能强于list ,vector ，查找速度随着元素的增加爱而降低。插入速度更慢，散列表查找和插入的时间固定。



## 3、散列表  ，unordered_map 和 unordered_multimap

平均插入删除时间固定，查找元素时间也是固定的

#include < unordered_map >

跟据散列函数计算索引

`Index = HashFunction(key,Tablesize);`

使用find跟据键值查找元素使，将使用HashFunction()计算元素位置，并返回该位置的值。如果HashFunction设计不佳，就会导致多个元素的索引值相同。这种情况称之为冲突（collision）。

与之前的map使用差别不大

重要的特点，unordered_map包含一个散列函数南湖，用于计算排序

`unordered_map<int,string>::hasher HFn = usmapIntTostring.hash_function;`

实现一些常用的方法

```c++
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
template <typename T1,typename T2>
void DisplayUnorderedMap(unordered_map<T1,T2>& Input)
{
    cout <<"键值对的大小" << Input.size() <<endl;
    cout << "桶的最大容量" <<Input.max_bucket_count() <<endl;
    cout << "负载系数" << Input.load_factor() <<endl;
    cout << "最大负载系数" <<Input.max_load_factor() <<endl;
    //dayin
    for (auto iElemnt = Input.begin();iElement != Input.end(); ++iElement)
    {
        cout << iElement ->first << "-->>" << iElemet ->second <<endl;
    }
}
```



## 注意：

无论使用的键是什么。都不要编写unordered_map中元素的排列顺序的代码。在其中元素的顺序取决于很多因素。在包括元素不太多的情况下，插入和查找所需要的固定时间可能长很多，导致unordered_map的速度比map慢很多。





# 第21 章 理解函数对象

函数对象也叫functor

## 1、概念

从概念上说函数对象是用作函数的对象，从实现上说，函数对象是实现了operator()的类对象。虽然函数和函数指针也可以归为函数对象，但是实现了operator的类对象才能保存状态（即类的成员属性的值），才能用于标准模板库（STL）算法。

C++程序员常用于STL算法的函数对象可以分为以下两种类型。

一元函数：接受一个参数的函数。如f(x)。如果一元函数返回一个布尔值，该函数称为谓词。

二元函数：接受两个参数的函数。如f(x,y)。如果二元函数返回一个bool值，则该函数称之为二元谓词。

返回布尔类型的函数对象通常用于需要进行判断的算法。组合两个函数对象的函数称之为自适应对象。

## 2、函数对象的典型用途

### 1、一元函数

只对一个参数进行操作的函数称之为一元函数，如在屏幕上显示元素。

```c++
template <typename elementType>
void DisplayElement(const elementType& element)
{
    cout << element <<' ';
};
//上面的函数也可以通过另一种表现形式，即其实现包含在类或结构的operator中
template <typenaem elementType>
struct DisplayElemment
{
    void operator()(const elementType& element) const
    {
        cout << element << ' ';
    }
};
//使用结构的函数对象存储信息，则使用在结构中实现的函数对象的优点将显现出来。
template <typenaem elementType>
struct DisplayElemment
{
    //记录自己被调用于显示的个数
    int Count;
    DisplayElementKeepCount()
    {
        Count =0;
    }
    void operator()(const elementType& element) const
    {	
        ++Count;
        cout << element << ' ';
    }
};
//如果在类中，必须给operator()指定访问限定符public，结构中默认为公有成员。

//用于实现算法for_each()
int main()
{
    vector<int> vecIntegers;
    for(int Count = 0;Count <10;++Count)
    {
        vector.push_back(Count);
    };
    //传入三个参数，第一个额参数的起点，第二个参数指定范围的终点，第三个参数对vector 
    //vecIntegers的每个元素调用DisplayElement::operator()
    //返回值为结构体
    for_each(vecIntegers.begin(),vecIntegers.end(),DisplayElement<int>());
    return 0;
}
//引入lambda表达式可以大大简化代码
for_each(vecIntegers.begin(),vecIntegers.end(),
         [](int& element) {cout << element << ' ';});
```

### 2、一元谓词

返回布尔值的一元函数就是谓词。

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
struct IsMutiple
{
	T Divisor;
	IsMutiple(const T& Input):Divisor(Input){};
	bool operator() (const T& element) const
	{
		return (element % Divisor == 0);
	}
};
int main()
{
	vector<int> myVector;
	for(int Count = 25;Count <31;++Count)
	{
		myVector.push_back(Count);
	}
	int Divisor = 0;
	cout << "请输入除数" <<endl;
	cin >> Divisor; 
	//find_if对指定范围内的每个元素调用一元谓词，IsMutiple::operator(),当operator()返回ture时，find_if返回一个指向该元素的迭代器。
	auto iElement = find_if(myVector.begin(),myVector.end(),IsMutiple<int>(Divisor));

	if(iElement != myVector.end())
	{
		cout << "我找到的第一个能整除的数是" <<endl;
		cout << *iElement <<endl;
	}
	return 0;
}
```



### 3、二元函数

二元函数可以用于对两个操作数执行运算，如加减乘除。

```c++
template <typename elementType>
class Mutiply
{
    public:
    elementType operator() (const elementType& element1,const elementType& element2)
    {
    	return (element1 * element2);    
    };
};
//在std::transform等算法中，可以使用二元函数计算两个容器内的积。
int main()
{
    vector<int> myvector1,myvector2;
    for(int ncount1 = 0;ncount1<10;++ncount1)
    {
        myvector1.push_back(ncount1);
    }
    for(int ncount2 = 100;ncount2 < 110; ++ncount2)
    {
        myvector2.push_back(ncount2);
    }
    
    vector<int> vecResult;
    vecResult.resize(10);
    //两个范围内的东西对应相乘，结果存在vecResult中
    transform(myvector1.begin(),
             myvector1.end(),
             myvector2.begin(),
             vecResult.begin(),
             Mutiply<int>());
}
```

### 4、二元谓词

接受两个参数值返回布尔类型的函数是二元谓词。例如std::sort() 等 STL函数中。

实现对字符串进行不区分大小写排序的二元谓词

```c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class CompareStringNode
{
public:
	bool operator() (const string& str1,const string& str2) const
	{
		string str1LowerCase;
		str1LowerCase.resize(str1.size());
		string str2LowerCase;
		str2LowerCase.resize(str2.size());
        //这里很奇怪，tolower没有指定一个确定的作用域，有两个tolower
		transform(str1.begin(),str1.end(),str1LowerCase.begin(),::tolower);
		transform(str2.begin(),str2.end(),str2LowerCase.begin(),::tolower);
		return (str1LowerCase < str2LowerCase);
	};	
};
template <typename T>
void DisplayFuction(const T& Element)
{
	for(auto iElement = Element.begin(); iElement != Element.end();++iElement)
	{
		cout << *iElement << endl;
	}
	cout << endl;
}
int main()
{
	vector<string> mystring;
	mystring.push_back("Yang");
	mystring.push_back("xin");
	mystring.push_back("Ming");
	mystring.push_back("good");
	DisplayFuction(mystring);

	sort(mystring.begin(),mystring.end());
	DisplayFuction(mystring);

	sort(mystring.begin(),mystring.end(),CompareStringNode());
	DisplayFuction(mystring);
	return 0;
}

>>>>>>
Yang
xin
Ming
good

Ming
Yang
good
xin

good
Ming
xin
Yang

```



## 3、练习

```c++
//编写一个函数，使他能够提供std::for_each 用来显示输入参数的两倍
template <typename T>
struct DobleInput
{
    int nCount;
    DobleInput():nCount(0){};
    void operator(T& Input) const
    {
    	++nCount;
    	cout << Input * 2 << ' ';
    }
};
//编写一个使用降序排列的谓词
template <typename T>
struct Descending
{
    bool operator() (const T& lElement,const T& rElement) const
    {
        return (lElement > rElement);
    }
};
int main()
{
	vector<int> myIntegers = {1,78,3,5,72,546,32,345,4,67,8};
	sort(myIntegers.begin(),myIntegers.end(),Descending<int>());
	DisplayFuction(myIntegers);

	return 0;
}
```

# 第 22 章 lambda表达式

可将lambda表达式视为包含公有operator()的匿名结构或类，lambda表达式属于21章介绍的函数对象。

编译器见到lambda表达式时，自动张开类似于结构或类的形式

```c++
[](int &element) {cout << element << ' ';}
//自动展开
struct Node
{
	void operator() (const int& element) const
    {
        cout << element <<' ';
    }
}

```

## 1、如何定义lambda表达式

定义必须是以方括号[]为开头，方括号后面跟着一个参数列表，该参数列表与不使用lambda表达式时提供的operator() 的参数列表相同。

### 1、一元函数对应的lambda表达式

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vecIntegers;
	for (int nCount = 0; nCount < 10; ++nCount)
	{
		vecIntegers.push_back(nCount);
	}

	for_each(vecIntegers.begin(),vecIntegers.end(),[](int & element) {cout << element << ' ';});
	cout <<endl;
	return 0;
}
>>>>>
//0 1 2 3 4 5 6 7 8 9
```



### 2、一元谓词对应的lambda表达式

在vector是偶数时打印

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vecIntegers = {1,23,44,234,5,24,52,55,55,13};

	auto iElement = find_if(vecIntegers.begin(),vecIntegers.end(),[](const int & Input){ return (Input % 2 == 0);});

	if (iElement != vecIntegers.end())
	{
		cout << *iElement << " " <<endl;
	}
	else
	{
		cout << "find nothing" <<endl;
	}
	return 0;
}
```

### 3、通过捕获列表接受状态变量的lambda表达式

让lambda表达式接受除数，一系列以**状态变量**的方式传递的参数（[.......]）也被称为lambda表达式的捕获列表（capture list）。

使用lambda表达式跟据状态变量在集合中查找可被用户提供的除数整除的元素

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vecIntegers = {1,23,44,234,5,24,52,55,55,13};
	int Divisor = 2;
	cout << "请输入除数" << endl;
	cin >> Divisor;
	auto iElement = find_if(vecIntegers.begin(),vecIntegers.end(),[Divisor](int & Input){ return (Input % Divisor == 0);});

	if (iElement != vecIntegers.end())
	{
		cout << *iElement << " " <<endl;
	}
	else
	{
		cout << "find nothing" <<endl;
	}
	return 0;
}
```



## 2、通用语法

表达式总是以方括号开头，并可接受多个状态变量

`[stateVar1,statrVar2](type& param) {// lambda code here;}`

如果要在lambda中修改这些值，添加关键字multable

`[stateVar1,statrVar2](type& param) multable{// lambda code here;}`

还可以接受多个参数

`[stateVar1,statrVar2](type& param1,type& param2) {// lambda code here;}`

如果需要指出明确的返回类型 可以使用 ->

```c++
[stateVar1,statrVar2](type& param) -> ReturnType
{ lambda code here;}
```

复合语句可以包含多条用分号分隔的语句

```c++
[stateVar1,statrVar2](type& param) -> ReturnType
{Statement 1; Statement 2;return (value or expression);}
```

**注意** :如果lambda表达式包含多行代码，你必须显式的指定返回值类型



## 3、二元函数对应的lambda表达式

 将两个容器内的数据V相乘，并将结果存储到第三个vector中

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vecInteger1;
	vector<int> vecInteger2;
	for(auto nCount1 = 0;nCount1 <10; ++nCount1)
	{
		vecInteger1.push_back(nCount1);
	}
	for(auto nCount2 = 100;nCount2 <110; ++nCount2)
	{
		vecInteger2.push_back(nCount2);
	}
	vector<int> vecInteger3;
	vecInteger3.resize(vecInteger1.size());

	transform(vecInteger1.begin(),vecInteger1.end(),vecInteger2.begin(),vecInteger3.begin(),
				[](int & Input1,int& Input2) {return (Input1 * Input2);});

	for (auto iElement = vecInteger3.begin();iElement != vecInteger3.end(); ++iElement)
	{
		cout << *iElement << ' ';
	}
	cout << endl;
	return 0;
}
```



## 4、二元谓词对应的lambda表达式

可以用于sort()等算法，进行人名不区分大小写排序

```c++
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void DisplayFuction(const T& Element)
{
	for(auto iElement =Element.begin();iElement != Element.end(); ++iElement)
	{
		cout << *iElement <<' ';
	}
	cout << endl;
}
int main()
{
	vector<string> vecString;
	vecString.push_back("yang");
	vecString.push_back("Xin");
	vecString.push_back("Ming");
	vecString.push_back("hao");
	vecString.push_back("Ren");
	DisplayFuction(vecString);

	sort(vecString.begin(),vecString.end());
	DisplayFuction(vecString);

	sort(vecString.begin(),vecString.end(),[](const string& str1,const string& str2) -> bool
		{
			string str1ToLower;
			str1ToLower.resize(str1.size());
			transform(str1.begin(),str1.end(),str1ToLower.begin(),::tolower);
			string str2ToLower;
			str2ToLower.resize(str2.size());
			transform(str2.begin(),str2.end(),str2ToLower.begin(),::tolower);
			return (str1ToLower < str2ToLower);
		});
	DisplayFuction(vecString);


	return 0;
}

//在lambda表达式的语句块{}包含多条语句时，别忘了显示指定返回类型
```



注意： 要传递所有的局部变量 [ = ] ( Typename& Param) { ... expression;}

编写一个lambda表达式，即用于for_each时，给vector容器中的元素加上用户指定的值。

```c++
int main()
{
    int Input = 0;
    vector<int> vecIntegers = {2,4,5,6};
    cout << "请输入要加的数" <<endl;
    cin >> Input;
    for_each(vecIntegers.begin(),vecIntegers.end(),[=](int& Element) { Element + = Input;});
    
}
```

# 第 23 章  STL算法

位于头文件< algorithm > 中。

STL通过模板函数提供了很多算法，可以通过迭代器对容器进行操作。

分为 变序算法和非变序算法



![](/home/brook/下载/1.jpeg)

![](/home/brook/下载/2.jpeg)

![](/home/brook/下载/3.jpeg)



# 1、使用STL算法

### 1、根据值或条件查找元素

STL算法 find() 和 find_if() 用于vector等容器查找匹配或满足条件的元素。

```c++
auto iElement = find(vecIntegers.cbegin()
                    ,vecIntegers.cend()
                    ,NumTfind);   //输入要查找的元素
if (iElement!= vecIntegers.cend())
    cout << "result: value find" <<*iElement <<endl;

//find_if 第三个参数需要提供一个一元谓词,查找一个偶数
auto iElement = find(vecIntegers.cbegin()
                    ,vecIntegers.cend()
                    ,[](int element) {return (element %2) == 0;});
if (iElement!= vecIntegers.cend())
    cout << "result: value find" <<*iElement <<endl;

```

### 2、计算包含给定值或满足给定条件的元素数

```c++
size_t nNumZeroes = count(vecIntegers.begin(),vecIntegers.end(),0);
cout << "number of instances of zero" << nNumZeros <<endl<<endl;

//使用std::count_if(),满足传递的一元谓词
template <typename T>
struct Countdouble
{
    bool operator() (const T& Input)
    {
        return ((Input % 2) == 0);
    }
}

size_t nNumEvenElement = count_if(vecIntegers.begin(),vecIntegers.end()
                                  ,Countdouble<int>());
```



### 3、在集合中搜索元素或序列

search用于在一个序列中查找另一个序列//

```c++
//返回迭代器，指向在vecIntegers找到的最开始位置
auto iRange = search(vecIntegers.begin()
                    ,vecIntegers.end()
                    ,listIntegers.begin()
                    ,listIntegers.end());
//search_n()用于在容器中查找n个相邻的指定值,返回序列{999}在vector中首次出现的位置
auto iPartialRange = search_n(vecIntegers.begin()
                             ,vecIntegers.end()
                             ,3         //计数
                             ,9);		//要查找的值

```



### 4、将容器中的元素初始化为指定值

fill() 和fill_n()

```c++
//fill将指定范围内的元素设置为指定值
vector<int> vecIntegers(3);
//三个位置全部填上9
fill(vecIntegers.begin(),vecIntegers.end(),9)
//fill_n()将前n 个元素这定为值，结合搜参数包括起始位置，元素个数，要设定的值
fill_n(vecIntegers.begin(),3,-9);    
```



### 5、使用std::generate()将元素设置为运行阶段生成的值

将集合中的内容设置为一元函数返回的值

```c++
//指定范围内的元素设置为生成器函数返回的值

generate(vecIntegers.begin(),vecIntegers.end(),rand);//生成随机值

//能指定个数
generate(vecIntegers.begin(),5,rand);
```



### 6、使用for_each()处理指定范围内的元素

对指定范围内的元素应用了指定的一元函数对象。

```c++
//接受一元函数对象，返回用于指定范围内的每个元素进行处理的函数对象。可以存储信息
unarryFuctionObjectType mReturn = for_each(start_of_range
											,end_of_range
											,unarryFuctionObject);
//显示范围内的函数并指出他显示了多少函数
//部分代码
template <typename T>
struct DisplayFuction
{
    int nCount;
    DisplayFuction():nCount(0){};
    void operator() (const T& element) 
    {
        cout << element <<' ';
        ++ nCount;
    }
};
int main()
{
    vector<int> vecIntegers = {12,4324,436,56,3,78,5};
    string Sample = "for each display";
    DisplayFunction<int> Func = for_each(vecIntegers.begin(),vecIntegers.end(),DisplayFuction<int>());
    
    cout << "'" << Func.nCount << "elements is display" <<endl;
    return 0;
	//使用lambda 函数
    int Numchar =  0;
    for_each(Sample.begin(),Sample.end()
             ,[&Numchar](char c) { cout << c <<' ';++Numchar;});

}



```



### 7、使用transform()对范围内进行变换

与for_each有点像，都是对源范围内的每个元素调用指定的函数对象。但是transform有两个版本。

```c++
//一个版本接受一元函数常用于将字符串转换大小写
	string Sample("this Is A TEST sTring");
	// transform(Sample.begin() //源容器
	// 		,Sample.end()
	// 		,Sample.begin() //目标容器
	// 		,::tolower);
	string strCopySample;
	strCopySample.resize(Sample.size());
	transform(Sample.begin() //源容器
			,Sample.end()
			,strCopySample.begin() //目标容器
			,::tolower);	
	DisplayFuction(strCopySample);
//第二个版本接受一个二元函数，让transform()能够处理一对来自两个不同范围的元素
//相加两个范围内的元素，存储到第三个个范围range中
transform(vecIntergers1.begin()
         ,vecIntegers1.end()
         ,vecIntegers2.begin()
         ,ResultAddition.begin()
         ,plus<int>());
```

### 8、复制和删除操作

STL 提供了三个重要的复制函数：copy(),copy_if(),copy_backward()

删除 remove(),remove_if()

```c++
//copy向强将源范围内的内容复制给目标范围，返回值指向复制到目标范围的结尾
auto iLastPos = copy(listIntegers.begin()
                    ,listIntegers.end()
                    ,vecIntegers.begin());  
copy_if(listIntegers.begin()
        ,listIntegers.end()
        ,iLastPos
        ,[](int Element) {return ((Element % 2) == 1); });
//沿向后的方向将源范围的内容赋值给目标范围
copy_backward(listIntegers.begin()
             ,listIntegers.end()
             ,vecIntegers.end());
//remove() 将容器中指定值匹配的元素删除
auto iNewEnd = remove(vecIntegers.begin()
                     ,vecIntegers.end()
                     ,0);
//remove()返回一个指向容器末尾的迭代器，删除算法删除元素时，其他元素向前移，这样就需要从新调整容器的大小，否则末尾将包含不需要的值
vecIntegers.erase(iNewEnd,vecIntegers.end());

//remove_if
iNewEnd = remove_if(vecIntegers.begin(),vecIntegers.end()
                    ,[](int element) { return ((element % 2) == 1);});
vecIntegers.erase(iNewEnd,vecIntegers.end()); //resizing
```



### 9、替换值以及满足给定条件的元素

replace(),replace_if()用于替换集合中等于指定值和满足给定条件的元素

```c++
//用8 替换5 
replace(vecIntegers.begin(),vecIntegers.end(),5,8);
//用-1替换能被2整除的数
replace(vecIntegers.begin(),vecIntegers.end()
        ,[](int element) {return ((element % 2) == 0);},-1);
```



### 10、排序、在有序集合中搜索以及删除重复的元素

```c++
sort(vecIntegers.begin(),vecIntegers.end());//上升排序，默认谓词std::less<>
//指定谓词
sort(vecIntegers.begin(),vecIntegers.end()，
					[](const int& vec1,const int& vec2){return (vec1 > vec2);});
//要删除重复相邻的值可以使用，unique()
auto iNewEnd = unique(vecIntegers.begin(),vecIntegers.end());
vecIntegers.erase(iNewEnd,vecIntegers.end());//to resize
//要进行快速搜索，binary_search(),只能用与有序容器
bool bElementFound = binary_search(vecIntegers.begin(),vecIntegers.end(),100);
if (bElementFound)
    cout << "Element found in the vector" << endl;

```

### 11、将范围分区

std::partition()将输入范围分为两部分，一部分满足一元谓词，另一部分还不满足。

```c++
partition(vecIntegers.begin(),vecIntegers.end(),
          [](int &Elemnt){return((Element % 2)==0);});
//如果想保证每个分区的元素相对顺序保持不变。std::stable_partition
```

### 12、在有序集合中插入元素

这样就不破坏顺序了

```c++
//lower_bound() 和 upper_bound()都返回一个迭代器，分别指不破坏现有顺序的情况下，元素可插入到有序范围内的最前位置和最后位置
auto iMiniInsertPos = lower_bound(listNames.begin(),listnames.end(),"Brad Pitty");
auto iMiniInsertPos = upper_bound(listNames.begin(),listnames.end(),"Brad Pitty");

listNames.insert(iMiniInsertPos,"Brad Pitty");
```



## 注意：

使用算法remove(),remove_if(),unique()后，务必使用erase调整容器的大小

使用find(),find_if(),search(),search_n()返回的迭代器之前，务必与容器的end()进行比较

仅当元素的相对顺序很重要时，才因该使用stable_partition()

调用unique()删除重复元素之前，先sort保证相邻的元素彼此相临。



是否应对list使用std::sort()？

可以使用但是，会导致现有的迭代器失效，因此stl list 通过成员函数list::sort提供了排序算法，迭代器不会失效。



小练习：

1、编写一个二元谓词，他接受字符串作为输入参数，并根据V不区分大小写的比较结果返回一个值。

```c++
struct StringToLower1
{
	bool operator() (const string& str1,const string& str2) const
	{
		string str1Copy(str1);
		string str2Copy(str2);
		transform(str1Copy.begin(),str1Copy.end(),str1Copy.begin(),::tolower);
		transform(str2Copy.begin(),str2Copy.end(),str2Copy.begin(),::tolower);
		return (str1Copy < str2Copy);
	}
};
int main()
{
	vector<string> vecString;
	vecString.push_back("yang");
	vecString.push_back("Xin");
	vecString.push_back("Ming");
	vecString.push_back("hao");
	vecString.push_back("Ren");
	string yang("yang");
	string xin("xin");
    //这里一定注意，刚开始的括号是初始化结构体的不要在其中输入参数
	auto a = StringToLower1()(yang,xin); 
	cout << a <<endl;
	return 0; 
}
```





# 第 24 章 自适应容器：栈和队列

栈海河队列与数组或list极其相似，但是对插入，访问和删除元素的方式有一定限制。可以将元素插入到什么位置以及可以从什么位置删除元素决定了容器的行为特征。

栈 LIFO 后入先出 std::stack 模拟了这种行为。

队列 FIFO  先入先出，std::queue模拟了队列的这种行为。

## 1、使用std::stack类 

### 1、实例化stack类

定义如下

```c++
template <class elementTpye,class Container = deque<Type>> class stack;
//第二个模板参数默认是用deque来存储数据
std::stack<int> stackInt;
srd::stack<double,vector<double> > stackDOubleInvector;
std::stack<int> stackIntCopy(stackInt);
```

### 2、stack的成员函数

stack改变了另一种容器(list,vector,deque)的行为，通过限制元素插入或删除的方式实现功能。

```c++
stackInt.push();//在栈顶压入元素
stackInt.pop(); //删除栈顶的元素
if(stackInt.empty()) //检查栈是否为空并返回一个布尔值
    Dosometing();
stackInt.size() //返回栈中的元素个数
stackInt.top(); //获得指向栈顶的元素引用
cout <<stackInt.top() <<endl;
```



## 2、使用stl queue 类

只允许在末尾插入元素和在开头删除元素。

```c++
template<
	class elementType;
	class Container = deque<type>
>class queue;
```



### 1、实例化queue

```c++
std::queue <int> qIntegers;
srd::queue<double,vector<double> > qDOubleInvector;
std::queue<int> stackIntCopy(qIntegers);
```



### 2、成员函数

实现基于 STL容器vector,list,deque

```c++
qIntegers.push(); //在最后一个位置插入一个元素
qIntegers.pop(); //在队首弹出一个元素删除
qIntegers.front(); //返回指向队首元素的引用
qIntegers.back(); //返回指向队尾元素的引用
if (qIntegers.empty())
    cout << "this queue is empty"<< endl;
qIntegers.size()
```



## 3、使用STL优先级队列

priority_queue 是一个模板类， #include < queue >, 包含最大值的元素位于队首，且只能在队首执行操作。

```c++
//类定义如下
template <
	class elementType,
	class Container = vector<Type>,
//指定一个二元谓词，以帮助判断哪个元素应该位于队首。
	class Compare = less<typename Container::value_type>
>
```

### 1、实例化

```c++
std::priority_queue <int> pqIntegers;
//导致最小的元素位于队首
priority_queue <int,deque<int>,greater<int>> pqIntegers;
priority_queue <int> pqCopy(pqIntegrs);
```

### 2、priority_queue 的成员函数

push，pop，top，empty，size



## 练习

邮局哟偶一个包含人的队列。person包含两个成员属性，编写一个二元谓词，帮助priority_queue优先向老人和妇女提供服务。 //没写明白

```c++
class Person
{
    public:
    int Age;
    bool IsFemal;
}

```



# 第25 章  使用 STL 位标志位

位是存储设置与标志的高校方法。标准模板库（STL）提供了可以帮助组织与操作位信息的类。

bitset类    vector< bool >

## 1、bitset类

std::bitset 是一个STL类，用于处理以位和标志位表示的信息。std::bitset不是STL容器类，因为他不能调整长度。

#include < bitset >

### 实例化

```c++
bitset<4> fourBits;
bitset<5> fiveBits("10101");
bitset<8> eightBitsCopy(eightBits);
bitset<8> eight(255);   //打印出来11111111
//长度不可以更改
```

### bitset的运算符

```c++
cout << fourBits;  //输出到流中
"0101" >> fourBits; //插入到bitset对象中
//运算符  & | ~ ^异或
bitset <4> result(fouBits1 & fourBits2);

fourBits >>=(2); //右移两位
fourBits <<=(2); //左移两位

//运算符[N]，指向位序类的（N +1）位的引用。
bool bNUm = fourBits[2];
```

### bitset的成员方法

```c++

fourBits.set();  //将序列中的所有位置都设置为1
set(N,val = 1);
fourBits.set(2,3); //将第三位设置为3
fourBts.reset(); //将序列中所有的位置0
fourBits.reset(2); //将第三位设置为0
fourBits.flip(); //将所有的位取反
fourBits.size(); 
fourBits.count();  //返回序列中值为1 的个数
```



## 2、vector< bool >

可以动态调整长度

### 实例化

```c++
vector<bool> vecBool1;
vector<bool> vecBool2(10,true);
vector<bool> vecBool2Copy(vecBool2);
```

### 成员函数和运算符

提供 函数flips，其余的函数与vector 类似

```c++
vector <bool> vecBoolFlags(3);
vecBoolFlags[1] = true;
vecBoolFlags[2] = false;
vecBoolFlags[0] = true;

vecBoolFlags.push_back(true);

vecBoolFlags.flip();
```



## 问题：问题biset不属于STL容器类？

因为他不能像其他容器动态的调整长度，也不支持迭代器



练习：创建一个长为4位的bitset对象，并使用一个数字来初始化它，然后结果与另一个bitset相加

```c++

#include <bitset>
#include <iostream>

using namespace std;

int main()
{

	bitset<4> fourBitset1(10);
	bitset<4> fourBitset2(5);
	bitset<4> Result;
	Result = fourBitset2 | fourBitset1;
	//转化为十进制输出
	cout << fourBitset1.to_ulong() << endl;
	cout << Result.to_ulong() <<endl;
    
	//bitset<4> addresilt(fourBitset1.to_ulong()+fourBitset2.to_ulong());
    return 0;
}


```



# 第26章 理解智能指针

c++标准库提供智能指针类，std::unique_ptr;

c++智能指针是包含重载运算符的类，其行为类似常规指针，但是**智能指针能够及时妥善的销毁动态分配内存**的数据V，并实现了明确的对象周期。

常规指针存在的问题： c++在内存分配。释放和管理上向程序眼提供了全面的灵活性。强大，实施可能出现与内存相关的问题，动态内存没有正确的释放导致内存泄露。

当c++程序员需要管理堆（自由存储区）中的数据时，并非一定是用传统指针，还可以使用智能指针。

## 1、智能指是如何实现的

智能指针从在了解除引用运算符* ,  和成员选择运算符 -> ,让程序员可以像使用常规指针那样使用他们。

简单的智能指针实现(最基本的组成部分)

```c++
template <typename T>
class smart_pointer
{
    private:
    	T* m_pRawPointer;
    public:
    	smart_pointer(T* pData): m_pRawPointer(pData){};
    	~smat_pointer(){delete pData};
    	//copy constructor
    	smart_pointer(const smart_pointer & anotherSP);
    	//copy assignment operator
    	smart_pointer& operator= (const smart_pointer & anotherSP);
    	
    	T& operator*() const
        {
            return *(m_pRawPointer);
        }
    	T* operator ->() const
        {
            return m_pRawPointer;
        }
}

//这个类就能用作常规意义上的指针了
smart_pointer <Tuna> pSmartTuna(new Tuna);
pSmartTuna -> Swim();
(*pSmartDog).Swim();
```

## 2、智能指针类型

内存资源管理（即实现的内存所有权模型）是智能指针类与众不同的地方。

智能指针的分类实际上就是内存资源管理策略的分类。可以分为如下几类

深复制。

写时复制（COW），共享指针，直到首次写入对象，首次调用非const函数时，COW指针通常为该非const函数操作的对象创建一个副本，而其他指针依然共享源对象。**实现const和非const版本的运算符 * 和-> 是实现COW指针功能的关键。非const对象用于创建副本**



引用计数智能指针，记录对象的用户数量的机制。当计数降低到零后，将对象释放。引用计数提供了一个优良的机制，使得可共享对象而无法对其进行复制。这种智能指针被复制时，需要将对象的引用计数加1.至少有两种常用的方法跟踪计数。1、在对象中维护引用计数（修改对象以维护和递增引用计数）2、引用计数由共享对象中的指针类维护。（智能指针类将计数保存在自由存储区，如动态分配的整形，复制时将这个值加1）



引用链接智能指针，不主动维护对象的引用计数，只需要直到计数什么时候变为0,以释放对象。基于双向链表，复制智能指针来创建新的智能指针时，新指针将被插入到链表中。当智能指针离开作用域进而被销毁时，析构函数把他们从链表中删除。



破坏性复制，在智能指针被复制时，将对象的所有权交给目标指针并重置原来的指针。复制构造函数在复制之后将源指针置为NULL。该智能指针类的复制构造函数和赋值构造函数不能接受const引用。销毁源引用，使得他不适合STL容器或任何其他的动态类集合。

## 使用std::unique_ptr

必须包含头文件 #include < memory >,由于他的复制构造函数和赋值构造函数被声明为私有的，因此不能复制他，也不能将它赋给其他指针。

例子

```c++
#include  <iostream>
#include <memory>
using namespace std;

class Fish
{
    public:
    	Fish() {cout << "Fish:Constructed" <<endl;}
    	~Fish() {cout << "Fish: Destructed" <<endl;}
    	void Swim() const {cout << "Fish swim in water" <<endl;}
};
//只能按照引用传递
void MakeFishSwim(const unique_ptr<Fish>& inFish)
{
    inFish -> Swim();
}
int main()
{
    unique_ptr<Fish> smartFish(new Fish);
    smartFish -> Swim();
    MakeFishSwim(smartFish);
    unique_ptr<Fish> copysmartFish;
    //copysmartFish = smartFish;   当场阵亡，不能复制
}
```



## 3、还有很多其他的智能指针库

Boost(www.boost.org) 提供了一些经过测试且文档完善的智能指针类。



# 第 27 章 使用流进行输入和输出

std::cout c++的流是读写（输入输出）逻辑的通用实现，让您能够统一的模式读写数据。不论是磁盘还是键盘读取数据V，还是输入写入显示器或者磁盘。

```c++

#include <iostream>
using namespace std;
int main()
{
    std::cout << "hello world"  << std::endl;
    //可以用一致的语法访问不同的设备，写入文本文件，可以用同样的语法用于文件流对象fsHW:
    fsHW << "hello world" << endl; //into a file stream
}
```

## 1、std 命名空间中常用的C++流类

```c++
cout  //标准输出流，常用于被重定向到控制台
cin   //标准输入流，常用于数据V读入变量
cerr  //用于显示错误信息的标注输出流
fstream    //用于操作文件的输入和输出流，继承了ofstream和ifstream
ofstream   //用于操作文件输出流类，即用于创建文件
ifstream   //用于操作文件的输入流类，用于读取文件
stringstream //用于操作字符串的输入和输出流类，继承了istringstream,ostringstream,通常用于在字符串和其他类型之间进行转换。    
```

注意：cout,cin,cerr分别是ostream ,istream,ostream的全局对象，在main()开始之前就已经初始化。

## 2、常用的控制符

```c++
endl
ends  //插入一个空字符
//基数控制符
dec  //让流以十进制的方式解释输入或显示输出
hex   // 16进制
oct   //八进制
//浮点数表示操作符
fixed  //让流以定点白哦是法显示数据
scientific  //让流以科学表示法显示数据
//<iomanip>控制符
setprecision  //设置小数点精度
setw   //设置宽度
setfill //设置填充字符
setbase  //设置基数，与使用hex,oct,dec等效
setiosflag   //通过类型为std::ios_base::fmtflags 的掩码输入参数设置标志位
resstiosflag  //将std::ios_base::fmtflags参数指定的标志重置为默认值
```



## 3、cout的使用

让cout以十六进制和八进制的方式显示整数。

```c++
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{

	cout << "int a integer:";
	int input = 0;
	cin >> input;

	cout << "Integers in octal:" << oct <<input <<endl;
	cout << "Integers in hex"  << hex << input <<endl;

//设置为大写字母显示，16进制
	cout << "Integer in hex using base notation" <<endl;
	cout << setiosflags(ios_base::hex|ios_base::showbase|ios_base::uppercase);
	cout << input <<endl;
	cout << "Integers after resetting I/O flags" <<endl;
	cout<<resetiosflags(ios_base::hex|ios_base::showbase|ios_base::uppercase);
	cout << input <<endl;
}
///////////////////////
int a integer:123
Integers in octal:173
Integers in hex7b
Integer in hex using base notation
0X7B
Integers after resetting I/O flags
123

```

使用cout 显示使用他们时的精度

```c++
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{

	const double Pi = (double) 22.0/7;
	cout << "Pi = " << Pi <<endl;
	cout <<endl <<"setting precision to 7" <<endl;
	cout <<setprecision(7);
	cout << "Pi = " << Pi <<endl;
	//定点表示法
	cout << fixed << "Fixed Pi = " << Pi <<endl;
	//科学数字法
	cout << scientific << "scientific Pi = " << Pi <<endl;

	  
}
//////////////////////////////
Pi = 3.14286

setting precision to 7
Pi = 3.142857
Fixed Pi = 3.1428571
scientific Pi = 3.1428571e+00

```



使用文本对其和设置文本宽度

setw() 控制字符宽度，右对齐，还可以使用setfill()指定用什么字符填充空白区域

```c++
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{

	cout << "hey-default"<<endl;
	cout << setw(30);
	cout <<"hey-right aligned"<<endl;
	cout <<setw(30) << setfill('*');
	cout <<"hey-right aligned"<<endl;

	cout << "hey-default"<<endl;
}
/////////////////////////////////////
hey-default
             hey-right aligned
*************hey-right aligned
hey-default

```

## 4、使用std::cin 进行输入

读取到基本类型中

```c++
int InputInt = 0;
cin >> INputInt;
double Inputdouble = 0;
cin >> Inputdouble;
char char1='\0',char2 ='\0',char3 = '0';
cin >>char1>>char2>>char3;
```

使用std::cin::get 将输入读取到char数组中

```c++
//当cin直接写入int变量，也可以直接写入char数组，危险，容易超过缓冲区的边界
char CstyleStr[10] = {0};
cin >> CstyleStr;   //危险
//更好的方法
cin.get(CstyleStr,9);//在第九个位置停止插入
```

使用std::cin读取到std::string之中

```c++
string Name;
cin >>Name;
//上面的情况在遇到空白时就停止输入，，更好的方法如下
getline(cin,Name);
```



## 5、使用std::fstream处理文件

`#include <fstream>`

使用open()和close()打开和关闭文件

```c++
fstream myfile;
//文件路径+名，设置为可读，可写，即便指定的文件存在，也重新创建他。
myfile.open("HelloFile.txt",ios_base::in|ios_base::out|ios_base::trunc);

if (myfile.is_open())
{
    //do something
    myfile.close();
}

//使用构造函数打开文件流
fstream myfile("HelloFile.txt",ios_base::in|ios_base::out|ios_base::trunc);
//可以在下述各种模式下打开文件流
ios_base::app //附加到现有文件末尾，而不是覆盖他
ios_base::ate  //切换到 文件末尾，但是可以在文件的任何地方写入数据
ios_base::trunc     //导致现有文件被覆盖
ios_base::binary  //创建二进制文件
ios_base::in     //以只读的方式打开文件
ios_base::out    //以只写的方式打开文件    
```



用open()创建文本文件并运用运算符<< 写入文本  , >> 读取文本文件

```c++
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("HelloFile.txt",ios_base::out);
	if (myfile.is_open())
	{
		cout <<"File open successful" <<endl;
		myfile << "my first text file" << endl;
		myfile << "hello file ";
		cout << "Finished writing to file" <<endl;
		myfile.close();
	}
	return 0;
}
int main()
{
	ifstream myfile;
	myfile.open("HelloFile.txt",ios_base::in);
	if (myfile.is_open())
	{
		cout << "file open successful,it contains"<<endl;
		string fileContents;
		while(myfile.good())
		{
			getline(myfile,fileContents);
			cout <<fileContents <<endl;
		}
		cout << "Finished reading File ,will close now" << endl;
		myfile.close();
	}
	else
	{
		cout << "open failed" <<endl;
	}
}
```



读写二进制文件

在打开文件时使用ios_base::binary标志。通常使用ofstream::write 和 ifstream::read 来读写二进制文件

```c++
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
using namespace std;

struct Human
{
public:
	Human(){}
	Human(const char* inName,int inAge,const char* inDob):Age(inAge){
		strcpy(Name,inName);
		strcpy(Dob,inDob);
	}
	char Name[30];
	int Age;
	char Dob[20];
};
int main()
{
	Human Input("Sidddharari Rao",100,"May 1999");
	ofstream fsOut("myBinary.bin",ios_base::out|ios_base::binary);
	if (fsOut.is_open())
	{
		cout << "writing one object" << endl;
        //将结构解释为char*
		fsOut.write(reinterpret_cast<const char*>(&Input),sizeof(Input));
		fsOut.close();
	}
	ifstream fsIn("myBinary.bin",ios_base::in|ios_base::binary);
	if (fsIn.is_open())
	{
		Human somePerson;
		fsIn.read((char*)& somePerson,sizeof(somePerson));
		cout << "reading informatin" <<endl;
		cout << "Name = " << somePerson.Name <<endl;
		cout << "Age = " << somePerson.Age <<endl;
		cout << "Data of birth = " << somePerson.Dob <<endl;
	}
	return 0;
}


>>
writing one object
reading informatin
Name = Sidddharari Rao
Age = 100
Data of birth = May 1999

```





## 6、使用std::stringstream 对字符串进行转换

假设您有一个字符串，包含数值为45,如何将其转换为整形值45,如何将整形值45 转换为字符串45

#include <sstream>

```c++
//整形和字符串之间相互转换
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int Input =0;
	cout << "int a integer" <<endl;
	cin >> Input;

	stringstream converterStream;
	converterStream << Input;
	string strInput;
	converterStream >> strInput;

	cout << "Integer INput = " << Input << endl;
	cout << "String gain from integer,strInput" << strInput <<endl;

	stringstream anotherStream;
	anotherStream << strInput;
	int Copy =0;
	anotherStream >> Copy;

	cout << "Integr gained from string,Copy = "  << Copy << endl;  
	return 0;
}
```





## 注意

只想读文件时务必使用ifstream ,只想写文件时务必使用ofstream，插入文件流或从文件流提取之前，务必使用is_open()核实文件是否打开。使用之后别忘了close()





# 第 28 章 异常处理

通过异常处理有助于避免出现访问违规，和未处理异常等。异常可能是由外部因素引起的，如系统没有足够的内存，也可能是程序内部引起的，如使用的指针包含无效值或除数为0.为向调用者指出错误，有些模块引发异常。

## 1、使用try和catch捕获异常

要捕获的语句可能引发异常，可将他们放在try块中，并使用catch块对try块可能引发的异常进行处理

```c++
void SomFunc()
{
    try
    {
		int *pNumber;
        *pNumber = 99;
        delete pNumber;
    }
    catch(...) //
    {
        cout << "exception in function,quitting" <<endl;
    }
}
```

## 2、使用catch(...) 处理所有的异常

```c++
#include <iostream>
using namespace std;

int main()
{
	cout << "Enter number of integers you wish to reserve" << endl;
	try
	{
		int Input = 0;
		cin >> Input;
		int* pReservedInts = new int[Input];
		delete[] pReservedInts;
	}
	catch(...)
	{
		cout << "eception encountered.go to end,sorry" << endl;
	}
	return 0;
}
```



## 3、捕获特定的异常

捕获bad_alloc类型异常。

```c++
#include <iostream>
#include <exception>
using namespace std;

int main()
{
	cout << "Enter number of integers you wish to reserve" << endl;
	try
	{
		int Input = 0;
		cin >> Input;
		int* pReservedInts = new int[Input];
		delete[] pReservedInts;
	}
	catch(std::bad_alloc& exp)
	{
		cout << "exception encountered:" << exp.what() << endl;
	}
	catch(...)
	{
		cout << "eception encountered.go to end,sorry" << endl;
	}
	return 0;
}
>>>>>>>>>
Enter number of integers you wish to reserve
-1
exception encountered:std::bad_array_new_length

```



## 4、使用throw 引发特定类型的异常

上面的函数实际上是捕获new引发的std::bad_alloc异常，我也可以引发这样的异常

```c++
void DoSomething()
{
    if(something_unwanted)
    {
        throw Value;
    }
}
```

在试图处以0的时候自动引发一个异常

```c++
#include <iostream>
#include <exception>
using namespace std;
double Divide(double Dividend, double Divisor)
{
	if (Divisor == 0)
		throw "DIviding by 0 is a crime";
	return (Dividend / Divisor);
}
int main()
{
	cout << "Enter Dividend"<< endl;
	double Dividend = 0;
	cin >> Dividend;
	cout << "Enter Divisor" << endl;
	double Divisor = 0;
	cin >> Divisor;
	try
	{
		cout << "Result of division is" << Divide(Dividend,Divisor);
	}
    //这里的类型必须对，const char* ,抛出的字符串就是这个类型，少了const 都不行
	catch (const char* exp)
	{
		cout << "exception:" << exp <<endl;
		cout << "sorry" << endl;
	}
	return 0;
}
```

## 5、异常处理的工作原理

当我使用throw引发异常时，编译器都将查找能够处理 异常的catch(Type)。异常处理逻辑首先检查引发异常的代码是否包含在try中，如果是查询能够处理该异常的catch(Type)。如果throw与句不再try块内，或者没有与引发异常兼容的catch()，异常处理逻辑将在调用函数中继续查找。因此，异常处理逻辑沿着调用栈向上逐个地在调用函数中寻找，直到找到可以处理异常的catch(Type)。在退栈的每一步中，都将销毁当前函数的局部变量，这些局部变量的销毁顺序与创建顺序相反。



## 6、std::exception类

上面程序中的std::bad_alloc捕获时，实际上是捕获new引发的bad_alloc对象。std::bad_alloc继承了C++标准类std::exception,而std::exception是在头文件< exception>中声明的。

下面重要的异常类，都是由std::exception中派生来的。

bad__alloc:使用new时请求内存失败引发的异常

bad_cast:试图使用dynamic_cast转换错误类型时引发。（没有继承关系的类型）

ios_base::failure:由iostream库中的函数和方法引用。

std::exception 类是异常基类，它定义了虚方法what();它详细的说明了导致异常的原因。

## 7、从std::exception派生出自定义的异常类

好处是，现有的异常处理程序catch(const std::exception&) 不但能捕获bad_alloc,bad_cast等异常，还可以捕获自定义异常。

```c++
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class CustomException: public std::exception
{
	string Reason;
public:
	CustomException(const char* why):Reason(why) {};
//what()的声明，它以throw()为结尾，意味着这个函数本身不会引发异常，这是对异常类的一个重要约束，如果您在该函数中包含一条throw语句，编译器将发出警告，如果函数以throw(int)结尾，那么意味着该函数可能引发类型为int的异常。	
	virtual const char* what() const throw()
	{
		return Reason.c_str();
	}
};
double Divide(double Dividend, double Divisor)
{
	if (Divisor == 0)
		throw CustomException("CustomException: Dividing by 0 is a crime");
	return (Dividend / Divisor);
}
int main()
{
	cout << "Enter Dividend"<< endl;
	double Dividend = 0;
	cin >> Dividend;
	cout << "Enter Divisor" << endl;
	double Divisor = 0;
	cin >> Divisor;
	try
	{
		cout << "Result of division is" << Divide(Dividend,Divisor);
	}
    //这里的类型必须对，const char* ,抛出的字符串就是这个类型，少了const 都不行
	catch (exception& exp)
	{
		cout << "exception:" << exp.what() <<endl;
		cout << "sorry" << endl;
	}
	return 0;
}
```

## 注意：

务必捕获类型为exception的异常，务必谨慎的引发异常，异常不能替代返回值，不要再析构函数中引发异常，不要认为异常总能分配成功，务必将使用new的代码放在try中，并使用catch捕获可能发生的异常。不要在catch中实现逻辑或者分配资源的代码。





线程：应用程序总是运行在线程之中的，线程是一个同步执行实体，其中的语句依次执行。可将main()中的代码视为在应用程序的主线程中执行。在这个主线程中，可以创建并行运行的线程。可以直接调用操作系统提供的api创建线程。std::thread  头文件< thread >,最好使用针对操作系统的线程函数，编写C++程序时如果希望线程可移植务必了解BOOST线程库，网址 www.boost.org 

使用多线程技术的应用程序并行地执行特定任务的会话（session）。

另一个常见的多线程示例是，与用户交互的同时做其他工作的应用程序。这样的应用程序通常包含用户界面线程和工作线程。所以线程之间的彼此通信很重要。

通信的方式：线程之间可以共享变量，可以访问全局数据。创建线程时，可以给他提供一个指向共享对象（结构或者类）的指针。但是如果多个线程读写相同的内存单元，有些线程开始读取数据的时候，其他线程可能还没有结束写入操作，这将使得数据不完整。

使用互斥量和信号量同步线程。

线程是操作系统级的实体，而使用同步线程的兑现嗯也是操作系统提供的。大多数操作系统提供了信号量和互斥量，供我来同步线程。

互斥量通常用于避免多个线程同时访问一段代码。

通过信号量可以指定多少个线程可以同时执行某段代码。只允许一个线程访问的信号量被称为二值信号量。

多线程带来的问题：

竞争死锁，多个线程试图写入同一项数据。

死锁，两个线程彼此等待对方结束，导致他们都将处于等待状态。



# C++中堆的实现

使用 make_heap() 创建的堆可以提供一些 priority_queue 没有的优势：

1. 可以访问堆中的任意元素，而不限于最大的元素，因为元素被存储在一个容器中，就像是我们自己的 vector。这也提供了偶然破坏元素顺序的可能，但是总可以调用 make_heap() 来还原堆。
2. 可以在任何提供随机访问迭代器的序列容器中创建堆。这些序列容器包括普通数组、string 对象、自定义容器。这意味着无论什么时候需要，都可以用这些序列容器的元素创建堆，必要时，可以反复创建。甚至还可以为元素的子集创建堆。

<1>为了向堆中添加元素，首先可以用任何方法将元素附加到序列中。然后调用 push_heap() 来插入最后一个元素，为了保持堆的结构，这个元素会被重新排列到一个适当的位置。

```cpp
std::vector<double> numbers {2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0};
std::make_heap(std::begin(numbers),std::end(numbers));
// Result: 12 10 3.5 6.5 8 2.5 1.5 6
numbers.push_back(11); // Result: 12 10 3.5 6.5 8 2.5 1.5 6 11
std::push_heap(std::begin(numbers), std::end(numbers));
// Result: 12 11 3. 5 10 8 2. 5 1. 5 6 6. 5
```

也可以用自己的比较函数来创建堆，但是必须和 push_heap() 使用相同的比较函数：

```cpp
std::vector<double> numbers {2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0};
std::make_heap(std::begin(numbers), std::end(numbers),
std::greater<>());//Result: 1.5 6 2.5 6.5 8 12 3.5 10 numbers. push—back(1. 2);
//Result: 1.5 6 2.5 6.5 8 12 3.5 10 1.2
std::push_heap(std::begin(numbers), std::end(numbers),std::greater<>());
//Result: 1.2 1.5 2.5 6 8 12 3.5 10 6.5
```

<2> 删除最大元素和添加元素到堆的过程有些相似，但所做的事是相反的。首先调用 pop_heap()，然后从容器中移除最大的元素，例如：

```cpp
std::vector<double> numbers{2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0};
std::make_heap(std::begin(numbers),std::end(numbers));
//Result:12 10 3.5 6.5 8 2.5 1.5 6
std::pop_heap(std::begin(numbers),std::end(numbers));
// Result:10 8 3.5 6.5 6 2.5 1.5 12
numbers.pop_back();// Result:10 8 3.5 6.5 6 2.5 1.5
```

<3>此外， STL 提供了一个检查序列是否仍然是堆的方法：

```cpp
if(std::is_heap(std::begin(numbers),std::end(numbers)))
    std::cout << "Great! We still have a heap.\n";
else
    std::cout << "oh bother! We messed up the heap.\n";
```

 <4>STL 提供的最后一个操作是 sort_heap()，它会将元素段作为堆来排序。如果元素段不是堆，程序会在运行时崩溃。这个函数有以两个迭代器为参数的版本，迭代器指向一个假定的大顶堆(用 less<> 排列)，然后将堆中的元素排成降序。结果当然不再是大顶堆。下面是一个使用它的示例：

```cpp
std::vector<double> numbers {2.5, 10.0, 3.5, 6.5, 8.0, 12.0, 1.5, 6.0};
std::make_heap(std::begin(numbers), std::end(numbers));
//Result: 12 10 3.5 6.5 8 2.5 1.5 6
std::sort_heap(std::begin(numbers), std::end(numbers));
// Result: 1.5 2.5 3.5 6 6.5 8 10 12
```

实例代码： 

```cpp
#include <iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
void show(const double &n)
{
   cout<<n<<" ";
}
int main()
{
    vector<double>num(8);
    cout<<"please input eight number:";
    for(int i=0;i<8;i++)
    cin>>num.at(i);
    make_heap(num.begin(),num.end(),greater<double>());
    sort_heap(num.begin(),num.end(),greater<double>());//堆排序
    for_each(num.begin(),num.end(),show);
    cout<<endl;
    num.push_back(7);
    push_heap(num.begin(),num.end(),less<double>());
    sort_heap(num.begin(),num.end(),less<double>());
    for_each(num.begin(),num.end(),show);
    cout<<endl;
    pop_heap(num.begin(),num.end(),less<double>());
    num.pop_back();
    sort_heap(num.begin(),num.end(),less<double>());
    for_each(num.begin(),num.end(),show);
    cout<<endl;
    return 0;
}
```

