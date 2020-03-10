#    1、一些包

   python中对于对象的拷贝分为浅拷贝(copy)和深拷贝(deepcopy)两种方式。其中浅拷贝由“=”完成。而深拷贝由copy模块中deepcopy()函数担任。
    浅拷贝和深拷贝的区别是：浅拷贝只是将原对象在内存中引用地址拷贝过来了。让新的对象指向这个地址。而深拷贝是将这个对象的所有内容遍历拷贝过来了，相当于跟原来没关系了，所以如果你这时候修改原来对象的值跟他没关系了，不会随之更改。
1.浅拷贝"="的使用

```python
val1 = 1000
val2 = val1
print("val1 is :{0},val2 is :{1}".format(val1,val2))#val1 is :1000,val2 is :1000
print(id(val1),id(val2))  #34052192 34052192
#这时候修改val1的值，尽管val2指向val1.但因为val1是不可变类型，修改其值，会重新给新值分配内存，然后指向他。
val1 += 1
print(val1,id(val1),val2,id(val2)) #1001 10131616 1000 10131568  值不一样，内存地址也不一样了

#1.使用=复制可变对象的值，以及复制以后修改其值后的变化。
ls1 =[1,2,3,4]
ls2 = ls1
print(id(ls1),id(ls2)) #43702792 43702792 直接使用=复制变量，内存地址一样，值也一样。
print(ls1,ls2) #[1, 2, 3, 4] [1, 2, 3, 4]直接使用=复制变量，内存地址一样，值也一样。
#这时候修改可变对的值,因为其值可变，所以只需要在原内存地址上修改即可。
ls1.append(5)
print(id(ls1),id(ls2)) #可变对象修改其值，内存引用不变
print(ls1,ls2) #[1, 2, 3, 4, 5] [1, 2, 3, 4, 5] 因为两个变量的内存指向一样，所以值也一样。
#1.使用=复制不可变对象的值，以及复制以后修改其值后的变化。
```





2.深拷贝：copy.deepcopy()函数

```python


#1.使用copy.deepcopy()拷贝不可变对象的值，以及复制以后修改其值后的变化。
val1 = 1000
val2 = copy.deepcopy(val1)
print("val1 is :{0},val2 is :{1}".format(val1,val2))#val1 is :1000,val2 is :1000
print(id(val1),id(val2))  #33717408 33717408 对于不可变对象，深度拷贝内存地址没有修改。

val1 += 1
print(val1,id(val1),val2,id(val2)) #1001 33717904 1000 33717408

#1.使用copy.deepcopy()复制可变对象的值，以及复制以后修改其值后的变化。
ls1 =[1,2,3,4]
ls2 = copy.deepcopy(ls1)
print(id(ls1),id(ls2)) #34628472 34628712 注意对于可变对象深度拷贝后内存地址都修改了。
print(ls1,ls2) #[1, 2, 3, 4] [1, 2, 3, 4]
ls1.append(5)
print(id(ls1),id(ls2)) #34628472 34628712
print(ls1,ls2) #[1, 2, 3, 4, 5] [1, 2, 3, 4] #注意这个时候ls2的值没有随着ls1修改。
```

总结：其实对于浅拷贝和深拷贝来说，如果拷贝对象都是不可变对象的话，那么两者效果是一样的。如果是可变对象的话，“=”拷贝的方式，只是拷贝了内存中的地址引用，两个对象的地址引用一样，所以两个对象的值会随着一方的修改而修改。而对于deepcopy()来说，如果是可变对象的话，那么拷贝内容后新对象的内存地址也会重新分配，跟原来的内存地址不一样了。所以两者任意修改变量的内容不会对另一方造成影响。
3.注意一个特殊的copy(),跟深浅拷贝都有区别，慎用。

```python
copy.copy对于可变类型，会进行浅拷贝
copy.copy对于不可变类型，不会拷贝，仅仅是指向
1.使用copy()拷贝不可变对象
val1 = 1000
val2 = copy.copy(val1)
print(val1,val2)##1000 1000
print(id(val1),id(val2))#8551568 8551568
2.使用copy（）拷贝可变对象
ls1 =[1,2,3,4]
ls2 = copy.copy(ls1)
ls1.append(5)
print(ls1,ls2)  #[1, 2, 3, 4, 5] [1, 2, 3, 4]

看上去copy()函数效果和deepcopy()效果一样，可变对象拷贝后值也没有随着一个对象的修改而修改。
然后真实情况真是这样嘛？请看下面的案例，同样是拷贝可变对象。

origin = [1, 2, [3, 4]]
cop1 = copy.copy(origin)
cop2 = copy.deepcopy(origin)
origin[2][0] = "hey!"  #修改数据源的值
print(cop1,cop2) #[1, 2, ['hey!', 4]] [1, 2, [3, 4]]

很显然这时copy（）函数拷贝的值随着原对象的值修改了，而deepcopy()的值没有随着原对象的值修改。
主要是因为deepcopy会将复杂对象的每一层复制一个单独的个体出来对于copy（）函数要慎用，慎用.
```







```
浅copy的实现方法：
l1 = list[:]
l2 = copy.copy(list)
l3 = list(list)
```

```
那能不能完全copy呢，可以，使用命令deepcopy就可以
import copy
list = ['beijing','tianjin','hebei',['neimeng','xinjiang'],'wuhan','shandong']
list_copy = copy.deepcopy(list)
```

列表解析式

将一个函数作用到整个列表中每一个元素上

```python
[x*2 for x in range(1,8)]
```

自python2.6开始，新增了一种格式化字符串的函数

## 2、str.format()，此函数可以快速处理各种字符串。

语法它通过{}和:来代替%。

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```python
 1 #通过位置
 2 print '{0},{1}'.format('chuhao',20)
 3 
 4 print '{},{}'.format('chuhao',20)
 5 
 6 print '{1},{0},{1}'.format('chuhao',20)
 7 
 8 #通过关键字参数
 9 print '{name},{age}'.format(age=18,name='chuhao')
10 
11 class Person:
12     def __init__(self,name,age):
13         self.name = name
14         self.age = age
15 
16     def __str__(self):
17         return 'This guy is {self.name},is {self.age} old'.format(self=self)
18 
19 print str(Person('chuhao',18))
20 
21 #通过映射 list
22 a_list = ['chuhao',20,'china']
23 print 'my name is {0[0]},from {0[2]},age is {0[1]}'.format(a_list)
24 #my name is chuhao,from china,age is 20
25 
26 #通过映射 dict
27 b_dict = {'name':'chuhao','age':20,'province':'shanxi'}
28 print 'my name is {name}, age is {age},from {province}'.format(**b_dict)
29 #my name is chuhao, age is 20,from shanxi
30 
31 #填充与对齐
32 print '{:>8}'.format('189')
33 #     189
34 print '{:0>8}'.format('189')
35 #00000189
36 print '{:a>8}'.format('189')
37 #aaaaa189
38 
39 #精度与类型f
40 #保留两位小数
41 print '{:.2f}'.format(321.33345)
42 #321.33
43 
44 #用来做金额的千位分隔符
45 print '{:,}'.format(1234567890)
46 #1,234,567,890
47 
48 #其他类型 主要就是进制了，b、d、o、x分别是二进制、十进制、八进制、十六进制。
49 
50 print '{:b}'.format(18) #二进制 10010
51 print '{:d}'.format(18) #十进制 18
52 print '{:o}'.format(18) #八进制 22
53 print '{:x}'.format(18) #十六进制12
```

## 3、collection

是Python标准库的一部份

### 1、namedtuple具名元组

每一个值都有名字的元组 

```python
>>> from collections import namedtuple
#在定义具名元组时，namedtuple的第一个参数是元组的名字。第二个值为键值
>>> nt = namedtuple('nt','name age loc') 
>>> nt1 = nt('xinnming','22','haerbin')
>>> print(nt1)
nt(name='xinnming', age='22', loc='haerbin')
#通过点操作就可以调用value值
>>>nt1.name
'xinming'
```

### 2、Counter 累加器，可以做word count

counter是字典的一个子类

Counter类的目的是用来跟踪值出现的次数。它是一个无序的容器类型，以字典的键值对形式存储，其中元素作为key，其计数作为value。计数值可以是任意的Interger（包括0和负数）。

```python
from collections import Counter
import re
wenjian = """The returned dictionary, known as a feature set, maps from feature names to their values.
 Feature names are case-sensitive strings that typically provide a short human-readable description of the 
 feature, as in the example 'last_letter'. Feature values are values with simple types, such as booleans, 
 numbers, and strings."""

ret = re.sub("[,\.']"," ", wenjian)

print(ret)
wordList = ret.split()

print(wordList)

cc = Counter(wordList)
#most_common() 类似于字典的items
for k,v in cc.most_common():  
	print(k,v)
```

### 3、defaultdict

在defaultdict中，可以为一个字典中设定一个默认值。

在[Python](http://lib.csdn.net/base/python)中如果访问字典中不存在的键，会引发KeyError异常

既然如此，首先可能想到的方法是在单词第一次统计的时候，在counts中相应的键存下默认值1。这需要在处理的时候添加一个判断语句：

```python
strings = ('puppy', 'kitten', 'puppy', 'puppy',
           'weasel', 'puppy', 'kitten', 'puppy')
counts = {}

for kw in strings:
    if kw not in counts:
        counts[kw] = 1
    else:
        counts[kw] += 1
```

```python
for kw in strings:
    counts[kw] = counts.setdefault(kw, 0) + 1
```

defaultdict类就好像是一个dict，但是它是使用一个类型来初始化的：

```python
>>> from collections import defaultdict
>>> dd = defaultdict(list)
>>> dd
defaultdict(<type 'list'>, {})
```

defaultdict类的初始化函数接受一个类型作为参数，当所访问的键不存在的时候，可以实例化一个值作为默认值：

```python
>>> dd['foo']
[]
>>> dd
defaultdict(<type 'list'>, {'foo': []})
>>> dd['bar'].append('quux')
>>> dd
defaultdict(<type 'list'>, {'foo': [], 'bar': ['quux']})
```

### 4、OrderedDict 

通常情况下，python通常会是无序的散列表，有时候希望保留顺序

```python
from collections import OrderedDict

c = {}

dd = OrderedDict()

for x in ["a","b","c"]:
	c[x] = 1;
	dd[x] = 1;
#d = dict(dd)   不能把他转换为字典，转换为字典之 顺序消失  
print(c,dd)

for x in range(len(dd)):
	print(list(dd.keys())[x],list(c.keys()) [x])
    
>>>
{'b': 1, 'a': 1, 'c': 1} OrderedDict([('a', 1), ('b', 1), ('c', 1)])
a b
b a
c c

```

也能接受元组组成的序列作为输入

```python
tuple_list = zip(["a","b","c","d"],[1]*4)

for u,v in OrderedDict(tuple_list).items():
    print(u,v)
```

## 5、math模块

```python
import math
#实现pi 和 e自然底数
math.pi
math.e
#更高精度
print("pi = %.30f" % math.pi)
#无穷
#超出1.0E-37到1.0E+37为 inf 
#判断是否为无穷大
math.isinf(y)
#乘法计算不会抛出异常，计算乘方运算时会抛出异常，这点注意。
#inf/inf没有意义，返回NaN ,可以用math.isnan()判断
#整数转换
# 会将浮点小数后面的数字全部截掉
math.trunc() 
#会选择比当前值小的最接近整数
math.floor() 
#选择比当前值大的最接近整数
math.ceil()
#绝对值
math.fabs( )
#copysign第一个参数是指定值，第二个参数是提供符号的值
math.copysign(1,f)
#消除进行浮点运算时造成的误差
values = [0.1] *10
math.fsum(values)  
#阶乘
for i in [0,1,2,3,4,5]:
    print(i,math.factorical(i))
#指数 x 的 y 次幂
math.pow(x,y)
#对数 
math.log(8) #默认以对数为底
math.log(8,2)  # 等于3
#专门提供log10()函数, 更加精确
math.log10()
#专门提供math.exp()计算指数e的值
math.exp()



```



5、time 模块

time 基础是处理时间的模块，功能基本和datetime 相同。

`import time `

`time.time()`      格林威治时间1970.1.1        返回北京时间1970.1.1.8时以来经历过的秒数。(时间戳)

`time.ctime()`   返回当前时间

> 'Sun Mar 17 08:58:48 2019'

`time.ctime（time.time() - 1000)`    返回时间戳加减相应秒数的时间字符串

```python
>>>t = time.gmtime()   #格林威治时间，可以使用点操作返回要取的时间值
time.struct_time(tm_year=2019, tm_mon=3, tm_mday=17, tm_hour=1, tm_min=14, tm_sec=2, tm_wday=6, tm_yday=76, tm_isdst=0)
>>> t.tm_year
2019

>>> time.localtime()  #本地时间
time.struct_time(tm_year=2019, tm_mon=3, tm_mday=17, tm_hour=9, tm_min=19, tm_sec=10, tm_wday=6, tm_yday=76, tm_isdst=0)

time.mktime(timme.localtime())  #还原成时间戳
```

时区转换用

`import pytz`

`pytz.all_timezones`

`import os`

`os.environ['TZ'] = 'Asia/Shanghai'`

提供函数将时间字符串转换为stuct_time

```python
>>> t = time.strptime("2018-03-12T08-11-25+00:00","%Y-%m-%dT%H-%M-%S+00:00")
>>> print(t)
time.struct_time(tm_year=2018, tm_mon=3, tm_mday=12, tm_hour=8, tm_min=11, tm_sec=25, tm_wday=0, tm_yday=71, tm_isdst=-1)
>>> t.tm_year
2018

将struc_time转化成字符串表达式
time.strftime("%Y-%m-%dT%H:%M:%S+00:00" ,t)
>>>'2018-03-12T08:11:25+00:00'

```

让程序间接休息    `time.sleep(1)`休息一秒



## 6、random 生成随机数

生成0-1的随机浮点数

```python
import random
for i in range(5):
    print(random.random())
    
#在进行行重复性实验时，使用随机数种子
random.seed(5)
for i in range(5):
    print(random.random())

#生成随机整数
for i in range(5):
    print(random.randint(1,500))
	print(random.randrange(0,1000,100))
    
    
```

取样

有时候需要打乱数据的一些顺序

```python
random.shuffle()  #将列表中数据的顺序打乱之后输出,会改变列表的原始顺序

random.choice() # 随机取列表中的一个值

random.sample(a,3) # 随机取列表中的几个值
```

## 7、glob 和fileinput

当需要读取多个文件的内容时,glob中是一个通配符的写法

```python
>>> from glob import glob
>>> file_path = glob("/home/brook/udp/*")
>>> print(file_path)
['/home/brook/udp/zhengze.py', '/home/brook/udp/myCounter.py', '/home/brook/udp/udpRecv.py', '/home/brook/udp/udpSend.py', '/home/brook/udp/tcpSever.py']

```

```python
import fileinput
fr = fileinput.input(file_path)   #文件名组成一个列表
for line in fr:
    print(line.strip(),fileinput.filename(),fileinput.filelineno())
    #数据。数据来哪个文件。数据的行数。
```

## 8、bz2和gzip

 对这两种压缩文件做读写

```python
import bz2
import gzip
f = bz2.BZ2File("路径",'w')
for i in [1,2,3]:
	f.write(i +'\n')
f.close()

f = bz2.BZ2File("路径",'r')
for i in f.readlines():
	print(i)
f.close()

f = gzip.open("路径",'w')
for i in [1,2,3]:
	f.write(i +'\n')
f.close()
```

## 9、pprint(pretty-print)

有些结构复杂的数据，pprint结构更加美观。 

## 10、异常

python 用 异常对象（exception object）来表示异常情况。异常对象可以被处理、捕获，避免程序终止执行。

内建异常类
python3.5 官网手册

Exception   所有异常的基类

AttributeError  特征引用或者赋值失败时引发的

IOError 试图打在不存在的文件（包括其他情况）

IndexError  使用序列中不存在的索引

KeyError    使用映射中不存在的键

NameError   找不到名字（变量）

SyntaxError 在代码为错误形式时引发

SystemExit  系统异常退出

TypeError   在内建操作或者函数应用与错误类型的对象时

ValueError  正确的类型对象，但是对象使用不合适的值

ZeroDivisionError   除法，第二参数为0

**捕捉异常**

```python
try:
    需要执行的操作
except 异常类 as e:
    如果发生异常，执行以下代码
else:
    如果没有发生异常，执行的命令
finally:
    无论如何，都要执行的代码
```

- 注意 except as e 的写法，e 是一个变量，记录了异常的类，可以用 print 函数打印出来
- except 后面的异常类，建议写 Exception，这样就一定能捕获到异常。
- `捕获到异常，就不会去执行 else 模块`

抛出异常
raise 关键字可以自主抛出异常，规则如下：

raise NameError([str])

raise 后面跟异常的类，类括号里面，可以指定要抛出的异常示例，约详细越好
>>> raise NameError()
>>> Traceback (most recent call last):
>>>   File "<stdin>", line 1, in <module>
>>> NameError


>>> raise NameError('bad name')
>>> Traceback (most recent call last):
>>>   File "<stdin>", line 1, in <module>
>>> NameError: bad name
---------------------
## 11、traceback

当异常无法打印出堆栈时，可以使用`traceback.print_exc()`来达到同样的效果。

```python
class ShortInputException(Exception):
	def __init__(self, length, atleast):
		Exception.__init__(self)
		self.length = length
		self.atleast = atleast
try:
	s = input('请输⼊ --> ')
	if len(s) < 3:
		# raise引发⼀个你定义的异常
		raise ShortInputException(len(s), 3)
except EOFError:
	print("你输⼊了⼀个结束标记EOF")
except ShortInputException as x:#x这个变量被绑定到了错误的实例
	print('ShortInputException: 输⼊的⻓度是 %d,⻓度⾄少应是 %d'% (x.length, x.atleast))
else:
	print('没有异常发⽣.')
>>>请输⼊ --> 1
ShortInputException: 输⼊的⻓度是 1,⻓度⾄少应是 3

```

```python
class ShortInputException(Exception):
	def __init__(self, length, atleast):
		Exception.__init__(self)
		self.length = length
		self.atleast = atleast
try:
	s = input('请输⼊ --> ')
	if len(s) < 3:
		# raise引发⼀个你定义的异常
		raise ShortInputException(len(s), 3)
except EOFError:
	print("你输⼊了⼀个结束标记EOF")
except ShortInputException as x:#x这个变量被绑定到了错误的实例
	traceback.print_exc()
	print('ShortInputException: 输⼊的⻓度是 %d,⻓度⾄少应是 %d'% (x.length, x.atleast))
else:
	print('没有异常发⽣.')
    
>>>Traceback (most recent call last):
  File "yichang.py", line 14, in <module>
    traceback.print_exc()
NameError: name 'traceback' is not defined

#如果想把错误堆栈以字符串的形式在其他地方利用

err = traceback.format_exc()
```

## 12、JSON

便利网络传输的数据格式，可以和Python相互转换。

```python
import json

json.loads()   #将JSON转化为字典

json.dumps()    #将字典转化为JSON
```



# 2、读写外部数据

## 1、读取csv文件

```python
import csv  
import os
import shutil
import string
import copy
original_path = '/home/brook/af2019-cv-training-20190312/'

target_path = '/home/brook/Futurelab/Date_cleaned/'
with open('/home/brook/af2019-cv-training-20190312/list.csv','r') as cvsfile:
	datas = csv.reader(cvsfile) ##读取csv文件，返回一个列表，并且加每个数据加上引号

	for data in datas:    #历遍这个列表
		if data[0] == 'id':
			continue
		mysplit = "".join(data[0])

		if os.path.exists(target_path + data[3]):
			full_path = original_path + mysplit[0:2] + '/' +data[0]
			shutil.move(full_path + "_a.jpg", target_path + data[3] + '/')
			shutil.move(full_path + "_b.jpg", target_path + data[3] + '/')
			shutil.move(full_path + "_c.jpg", target_path + data[3] + '/')
		else:
			os.makedirs(target_path + data[3])
			full_path = original_path + mysplit[0:2] + '/' +data[0]
			shutil.move(full_path + "_a.jpg", target_path + data[3] + '/')
			shutil.move(full_path + "_b.jpg", target_path + data[3] + '/')
			shutil.move(full_path + "_c.jpg", target_path + data[3] + '/')
```

### 2、创建cvs文件

使用writer方法

创建并写入csv文件：

```python
import csv

with open("./csv_tutorial.csv",'a') as fw:
	writer = csv.writer(fw)
	writer.writerow(["c1","c2","c3"])
	for x in range(10):
        #ord()函数主要用来返回对应字符的ascii码；
        # chr()主要用来表示ascii码对应的字符，可以用十进制，也可以用十六进制。
		writer.writerow([x,chr(ord('a') +x) , "abc"])
		
```

写入的字符并没有加引号，如果想增加双引号 

`writer = csv.writer(fw,quoting = csv.QUOT_NONUMERIC)`

附加：

### 3、python利用open打开文件的方式：

w：以写方式打开， 
a：以追加模式打开 (从 EOF 开始, 必要时创建新文件) 
r+：以读写模式打开 
w+：以读写模式打开 (参见 w ) 
a+：以读写模式打开 (参见 a ) 
rb：以二进制读模式打开 
wb：以二进制写模式打开 (参见 w ) 
ab：以二进制追加模式打开 (参见 a ) 
rb+：以二进制读写模式打开 (参见 r+ ) 
wb+：以二进制读写模式打开 (参见 w+ ) 

ab+：以二进制读写模式打开 (参见 a+ )

### 4、处理方言

可能有”|“作为分隔符

```python
#读取方言
csv.register_dialect("pipes",delimiter = '|')
with open('/home/brook/af2019-cv-training-20190312/list.csv','r') as cvsfile:
    rows = csv.reader(fr.dialect = 'pipes')
    
    for row in rows:
		print(row)
        
#创建方言

在csv.witer 中传入参数   dialect = "pipes"
```

### 5、读取结果转化为字典

```python
with open('/home/brook/af2019-cv-training-20190312/list.csv','r') as cvsfile:
    rows = csv.DictReader(fr)
    for row in rows:
        print(row)
```

## 2、excel文件读取写入

使用pandas

```python
pip3 install pandas
pip3 install xlrd
pip3 install xlwts
```

一个excel文件中可能有多个sheet

```python
import pandas as pd 
from pandas import read_excel

pd.set_option('display.max_columns',7)
pd.set_option('display.max_rows',10)
#不止一个sheet
df = read_excel('/home/brook/python/myFirstXsl.xls','myFirstXsl') #第二个参数是sheet的名字

print(df)


////////////////////////////////////
#不显示第一列，去掉前三行
df = read_excel('/home/brook/python/myFirstXsl.xls','myFirstXsl',index_col=0,skiprows = 3)
print(df)

```



写入

```python
df = pd.DateFrame([[1,2,3,4],[5,6,78,8],[12,4,56,7]],index = [0,1,2] , columns = list("ABCD"))

df.to_excel('路径')
```

## 3、Python os模块

包含普遍的操作系统功能，如果你希望你的程序能够与平台无关的话，这个模块是尤为重要的。

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

### 1、os.access()

查看文件是否有指定权限，有则返回True否则返回flase

```python
os.access(path, mode)
path:指定文件路径
mode:参数有F_OK(是否存在),R_OK(可读),W_OK(可写),X_OK(可执行)
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```python
>>> os.access('/python/test.py',os.F_OK)  #是否存在
True
>>> os.access('/python/test.py',os.R_OK)  #是否可读
True
>>> os.access('/python/test.py',os.W_OK)  #是否可写
True
>>> os.access('/python/test.py',os.X_OK)  #是否可执行
False
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

### 2、os.chdir()

方法用于改变当前工作目录到指定的路径。

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
>>> os.getcwd()   #查看当前工作路径
'/python
>>> os.chdir('/root/')  #修改当前工作路径到‘/root’
>>> os.getcwd()
'/root'
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

### 3、os.chmod()

方法用于更改文件或目录的权限。

 权限指定：

- **stat.S_IXOTH:** 其他用户有执行权0o001
- **stat.S_IWOTH:** 其他用户有写权限0o002
- **stat.S_IROTH:** 其他用户有读权限0o004
- **stat.S_IRWXO:** 其他用户有全部权限(权限掩码)0o007
- **stat.S_IXGRP:** 组用户有执行权限0o010
- **stat.S_IWGRP:** 组用户有写权限0o020
- **stat.S_IRGRP:** 组用户有读权限0o040
- **stat.S_IRWXG:** 组用户有全部权限(权限掩码)0o070
- **stat.S_IXUSR:** 拥有者具有执行权限0o100
- **stat.S_IWUSR:** 拥有者具有写权限0o200
- **stat.S_IRUSR:** 拥有者具有读权限0o400
- **stat.S_IRWXU:** 拥有者有全部权限(权限掩码)0o700
- **stat.S_ISVTX:** 目录里文件目录只有拥有者才可删除更改0o1000
- **stat.S_ISGID:** 执行此文件其进程有效组为文件所在组0o2000
- **stat.S_ISUID:** 执行此文件其进程有效用户为文件所有者0o4000
- **stat.S_IREAD:** windows下设为只读
- **stat.S_IWRITE:** windows下取消只读

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
# ll
---------- 1 nobody nobody 167 9月  10 13:43 test.py
>>> import stat,os
>>> os.chmod('/python/test.py',stat.S_IXOTH)  #其他用户有可执行权限
[root@python python]# ll test.py 
---------x 1 nobody nobody 167 9月  10 13:43 test.py
>>> os.chmod('/python/test.py',stat.S_IWOTH)  #写权限
>>> os.chmod('/python/test.py',stat.S_IROTH)  #读权限
>>> os.chmod('/python/test.py',stat.S_IRWOT)  #全部权限

>>> os.chmod('/python/test.py',stat.S_IXGRP)  #组用户有执行权限
[root@python python]# ll test.py 
------x--- 1 nobody nobody 167 9月  10 13:43 test.py
#注意修改权限会消除以前的权限，只保留修改的权限
>>> os.chmod('/python/test.py',stat.S_IWGRP)  #组用户有写权限
>>> os.chmod('/python/test.py',stat.S_IRGRP)  #组用户有读权限
>>> os.chmod('/python/test.py',stat.S_IRWXG)  #组用户有所有权限
>>> os.chmod('/python/test.py',stat.S_IXUSR)  #拥有者有执行权限
>>> os.chmod('/python/test.py',stat.S_IWUSR) #拥有者有写权限
>>> os.chmod('/python/test.py',stat.S_IRUSR)  #拥有者有读权限
>>> os.chmod('/python/test.py',stat.S_IRWXU) #拥有者有所有权限
[root@python python]# ll test.py 
-rwx------ 1 nobody nobody 167 9月  10 13:43 test.py
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

### 4、os.chown()

方法用于更改文件所有者，如果不修改可以设置为 -1, 你需要超级用户权限来执行权限修改操作。

只支持在 Unix 下使用。

```
>>> os.chown('/python/test.py',0,0) #设置文件的UID为0，root用户，GID为0,root组
[root@python python]# ll test.py 
-rwx------ 1 root root 167 9月  10 13:43 test.py
```

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

### 5、os.chroot()

方法用于更改当前进程的根目录为指定的目录，使用该函数需要管理员权限。

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

###  6、os.close()

方法用于关闭指定的文件描述符 fd。

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```python
>>> os.name #判断现在的实用平台，windows返回‘nt’,linux返回
'posix'
>>> os.getcwd() #返回当前工作的目录
'/root'
>>> os.listdir('.') #返回指定目录下所有的文件和目录名
['file.txt', 'test', 'caidan.py', 'test.txt', 'test.py', 'test1.py', 'enumerate.py', 'login.py']
>>> os.remove('test1.py') #删除指定文件
>>> os.listdir('.')
['file.txt', 'test', 'caidan.py', 'test.txt', 'test.py', 'enumerate.py', 'login.py']
>>> os.rmdir('aaa')  #删除指定目录
>>> os.mkdir('directory')  #创建目录，只能创建一层目录
>>>os.path.isfile()  #——判断指定对象是否为文件。是返回True,否则False
>>> os.path.isfile('test.py')  #为文件返回True
True
>>> os.path.isfile('directory') #此为目录则返回false
False
>>> os.path.isdir('directory')  #判断指定对象是否为目录。
True
>>> os.path.exists('/python/test.py') #判断指定的对象是否存在
True
>>> os.path.exists('/python/caidan')
False
>>> os.path.split('/python/test.py') #返回路径的目录和文件名
('/python', 'test.py')
>>> os.getcwd()  #获取当前工作的目录
'/python'
>>> os.system('pwd')  #执行shell命令
/python
0
>>> os.system("echo 'hello world!'")
hello world!
0
>>> os.path.getsize('directory') #获得文件的大小，如果为目录返回0
4096
>>> os.path.abspath('.') #获得绝对路径
'/python'
>>> os.path.join('/python/directory/','test.py') #链接目录和文件名
'/python/directory/test.py'
>>> os.path.basename('/python/directory/test.py') #返回文件名
'test.py'
>>> os.path.basename('/python/directory')
'directory'
>>> os.path.dirname('/root/directory/test.py') #返回文件路径
'/root/directory'
>>> os.path.getmtime('.') #返回在此path下最后一次修改的时间戳
1510553280.2887046
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

[回到顶部](https://www.cnblogs.com/zhangxinqi/p/7826872.html#_labelTop)

## 二、sys模块

提供了一系列有关Python运行环境的变量和函数

 sys.argv命令行参数List，第一个元素是程序本身路径

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```python
#!/usr/bin/env python35
#encodind:utf-8

import sys
#sys.argv[0]  获取脚本名
#sys.argv[1]  获取第一个参数

print('脚本名称:{}'.format(sys.argv[0]))
for i in sys.argv:
     if i == sys.argv[0]:
         continue
     print('参数为:',i)
                                                                    
print('总参数个数:{}'.format(len(sys.argv)-1)

[root@python python]# ./sysargv.py s1 s2 s3 s4 s5
脚本名称:./sysargv.py
参数为: s1
参数为: s2
参数为: s3
参数为: s4
参数为: s5
总参数个数:5
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

sys.modules.keys() 返回所有已经导入的模块列表

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
>>> import sys
>>> sys.modules.keys()
dict_keys(['_sysconfigdata', 'posixpath', 'rlcompleter', 'stat', 'encodings.latin_1', 'atexit', 'io', 'zipimport', '_codecs', '_frozen_importlib_external', 'sys', '_weakrefset', '_sitebuiltins', '_warnings', 'marshal', 'os', 'genericpath', 'encodings', 'abc', 'codecs', '_imp', '_frozen_importlib', 'os.path', '_weakref', '_collections_abc', 'readline', 'encodings.aliases', 'errno', '_io', 'site', '_signal', 'builtins', 'sysconfig', 'encodings.utf_8', '__main__', '_stat', 'posix', '_thread'])
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

sys.exc_info() 获取当前正在处理的异常类,exc_type、exc_value、exc_traceback当前处理的异常详细信息

```
>>> sys.exc_info()
(None, None, None)
```

sys.exit(n) 退出程序，正常退出时exit(0)

```
>>> sys.exit()
```

sys.hexversion 获取Python解释程序的版本值，16进制格式如：0x020403F0

```
>>> import sys
>>> sys.hexversion
50660592
```

sys.version 获取Python解释程序的版本信息

```
>>> sys.version
'3.5.4 (default, Sep 22 2017, 10:57:08) \n[GCC 4.4.7 20120313 (Red Hat 4.4.7-11)]'
```

sys.maxsize 最大的Int值

```
>>> sys.maxsize
9223372036854775807
```

sys.maxunicode 最大的Unicode值

```
>>> sys.maxunicode
1114111
```

sys.modules 返回系统导入的模块字段，key是模块名，value是模块

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```python
>>> sys.modules
{'encodings.latin_1': <module 'encodings.latin_1' from '/usr/local/python35/lib/python3.5/encodings/latin_1.py'>, 'io': <module 'io' from '/usr/local/python35/lib/python3.5/io.py'>, 'builtins': <module 'builtins' (built-in)>, '_sitebuiltins': <module '_sitebuiltins' from '/usr/local/python35/lib/python3.5/_sitebuiltins.py'>, 'zipimport': <module 'zipimport' (built-in)>, 'encodings': <module 'encodings' from '/usr/local/python35/lib/python3.5/encodings/__init__.py'>, 're': <module 're' from '/usr/local/python35/lib/python3.5/re.py'>, 'stat': <module 'stat' from '/usr/local/python35/lib/python3.5/stat.py'>, '_imp': <module '_imp' (built-in)>, '_codecs': <module '_codecs' (built-in)>, '_frozen_importlib': <module '_frozen_importlib' (frozen)>, 'encodings.aliases': <module 'encodings.aliases' from '/usr/local/python35/lib/python3.5/encodings/aliases.py'>, 'abc': <module 'abc' from '/usr/local/python35/lib/python3.5/abc.py'>, 'genericpath': <module 'genericpath' from '/usr/local/python35/lib/python3.5/genericpath.py'>, '_warnings': <module '_warnings' (built-in)>, 'sysconfig': <module 'sysconfig' from '/usr/local/python35/lib/python3.5/sysconfig.py'>, 'os': <module 'os' from '/usr/local/python35/lib/python3.5/os.py'>, 'sre_compile': <module 'sre_compile' from '/usr/local/python35/lib/python3.5/sre_compile.py'>, 'marshal': <module 'marshal' (built-in)>, 'readline': <module 'readline' from '/usr/local/python35/lib/python3.5/lib-dynload/readline.cpython-35m-x86_64-linux-gnu.so'>, '_sysconfigdata': <module '_sysconfigdata' from '/usr/local/python35/lib/python3.5/_sysconfigdata.py'>, 'copyreg': <module 'copyreg' from '/usr/local/python35/lib/python3.5/copyreg.py'>, '_sre': <module '_sre' (built-in)>, 'sys': <module 'sys' (built-in)>, '_weakref': <module '_weakref' (built-in)>, '_thread': <module '_thread' (built-in)>, '_signal': <module '_signal' (built-in)>, '_locale': <module '_locale' (built-in)>, 'rlcompleter': <module 'rlcompleter' from '/usr/local/python35/lib/python3.5/rlcompleter.py'>, '_io': <module 'io' (built-in)>, 'errno': <module 'errno' (built-in)>, 'sre_constants': <module 'sre_constants' from '/usr/local/python35/lib/python3.5/sre_constants.py'>, 'os.path': <module 'posixpath' from '/usr/local/python35/lib/python3.5/posixpath.py'>, 'encodings.utf_8': <module 'encodings.utf_8' from '/usr/local/python35/lib/python3.5/encodings/utf_8.py'>, 'posixpath': <module 'posixpath' from '/usr/local/python35/lib/python3.5/posixpath.py'>, '_weakrefset': <module '_weakrefset' from '/usr/local/python35/lib/python3.5/_weakrefset.py'>, 'site': <module 'site' from '/usr/local/python35/lib/python3.5/site.py'>, '_stat': <module '_stat' (built-in)>, 'atexit': <module 'atexit' (built-in)>, '_collections_abc': <module '_collections_abc' from '/usr/local/python35/lib/python3.5/_collections_abc.py'>, 'posix': <module 'posix' (built-in)>, 'sre_parse': <module 'sre_parse' from '/usr/local/python35/lib/python3.5/sre_parse.py'>, '__main__': <module '__main__' (built-in)>, 'codecs': <module 'codecs' from '/usr/local/python35/lib/python3.5/codecs.py'>, '_frozen_importlib_external': <module '_frozen_importlib_external' (frozen)>}
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

sys.path 返回模块的搜索路径，初始化时使用PYTHONPATH环境变量的值

```
>>> sys.path
['', '/usr/local/python35/lib/python35.zip', '/usr/local/python35/lib/python3.5', '/usr/local/python35/lib/python3.5/plat-linux', '/usr/local/python35/lib/python3.5/lib-dynload', '/usr/local/python35/lib/python3.5/site-packages']
```

sys.platform 返回操作系统平台名称

```
>>> sys.platform
'linux'
```

sys.stdout 标准输出

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
#!/usr/bin/env python35
import sys
f = open('log.txt','a')   #以追加的模式打开一个文件
__console__ = sys.stdout   #备份默认console命令行
sys.stdout = f   #指定标准输出到文件
print('hello python')
sys.stdout = __console__  #将标准输出改为模式的console命令行模式
print('hello world')    #输出将会在console命令行下


[root@python python]# python35 stdout.py 
hello world
[root@python python]# cat log.txt 
hello python
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

sys.stdin 标准输入

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
#!/usr/bin/env python35
 
import sys
name = sys.stdin.readline()  #接受标准输入，等价于raw_input()
print('输出:',name) 
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

sys.stderr 错误输出

sys.exc_info() 返回当前捕获的异常信息

sys.exec_prefix 返回平台独立的python文件安装的位置

```
>>> sys.exec_prefix
'/usr/local/python35'
```

sys.byteorder 本地字节规则的指示器，big-endian平台的值是'big',little-endian平台的值是'little'

```
>>> sys.byteorder
'little'
```

sys.copyright 记录python版权相关的东西

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
>>> sys.copyright
'Copyright (c) 2001-2017 Python Software Foundation.\nAll Rights Reserved.\n\nCopyright (c) 2000 BeOpen.com.\nAll Rights Reserved.\n\nCopyright (c) 1995-2001 Corporation for National Research Initiatives.\nAll Rights Reserved.\n\nCopyright (c) 1991-1995 Stichting Mathematisch Centrum, Amsterdam.\nAll Rights Reserved.'
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

sys.api_version 解释器的C的API版本

```
>>> sys.api_version
1013
```



# 3、统计编程

数据可视化部分，主要是用matplotlib库中的pyplot模块

人口普查的数据统计成字典

```python
import pandas as pd 
import pprint
from collections import OrderedDict 

def read_exccel():
	excel_content = pd.read_excel('/home/brook/下载/A0201.xls',skiprows=2)
	#print(excel_content)
	#提取出列表中0行一列到最后一列的数据，并且去掉空格，提取民族
	race_list = list(map(lambda x: str(x).replace(' ','') , excel_content.iloc[0,1:][::3]))
	#提取年龄阶段
	age_list = list(map(lambda x: str(x).replace(' ','') , excel_content.iloc[2:,0]))
	print(race_list)
	print(age_list)
	excel_content = pd.read_excel('/home/brook/下载/A0201.xls',skiprows=4)
	#print(excel_content)

	def get_num(lines):
		ret_dict = OrderedDict()
		#这里k为合计，男女，v又是一个字典，v字典包括序号，和总数
		for k,v in lines.to_dict().items():
			new_v_dict = OrderedDict()
			for vk,vv in v.items():
				# 将v中的 key 由数字改为 岁数,将new_v_dict变为字典
				new_v_dict[age_list[int(vk)]] = vv
			#ret 的键值改为 小计 男 女   value改为new_v_dict
			ret_dict[k.split('.',1)[0]] = new_v_dict
		return ret_dict		


	result_dict = OrderedDict()
	for i, x in enumerate(range(1,178,3)):
		ids = [x,x+1,x+2]
		#这个东西打印自动带表头，转化为字典后将表头加上，这个表头为，x小计。男.女. 
		#print(excel_content.iloc[:,ids].to_dict())
		#获取 每一列的数据 ，三列为一组
		result_dict[race_list[i]] = get_num(excel_content.iloc[:,ids])
	return result_dict	

#将字典转化为json格式
if __name__ == '__main__':
	import json                
	print(json.dumps(read_exccel(),ensure_ascii = False,indent = 4))
```

## 1、均值和中位数

```python
def calc_mean(d):  #均值
	total = 0
	total_age = 0
	for age ,count in d.items():
		if age.isdigit():
			total += count
			total_age += int(age) *count
	return total_age / float(total)
#将字典转化为json格式
if __name__ == '__main__':
	d = read_exccel()
    #u表示utf-8的编码方式，并没有实际的意义
	for t in [u"合计",u"男",u"女"]:
		mean_count = calc_mean(d.get(u"合计").get(t))
		print("{}人口平均年龄".format(t),mean_count)
```

```python
def calc_median(d):  #中位数
	count_total = 0
	total = d.get("总计")
	half_total = total / 2
	for age,count in d.items():
		if age.isdigit():
			count_total += count 
		if count_total > half_total:
			break
	return int(age)		  
if __name__ == '__main__':
	d = read_exccel()
	for t in [u"合计",u"男",u"女"]:
		mean_count = calc_mean(d.get(u"合计").get(t))
		median_count = calc_median(d.get("合计").get(t))
		print("{}人口平均年龄".format(t),mean_count)
		print("{}人口中位数".format(t),median_count)
```

## 2、方差和标准差

```python
#重新共建数据，将小计，男 ，女统计出来 其中放入所有的民族		  
def get_race_num():
	from collections import defaultdict
	d = read_exccel()
	cc = defaultdict(list)
	for t in ["小计","男","女"]:
		for k,v in d.items():
			if k == "合计":
				continue
			#k中存放的是民族，将民族中小计的总计提出	
			cc[t].append((k,v.get(t).get("总计")))	
	race_num_dict = OrderedDict()
	#这个k放的是之前的t,是个字典
	for k,v in cc.items():
		race_num_dict[k] = dict(v)
	return race_num_dict			
#计算方差
def calc_varaiance(d):
	mean = sum(d.values()) / float(len(d.values()))
	total = 0
	for k,v in d.items():
		total += (v - mean) ** 2
	return total /float(len(d.values()))
#将字典转化为json格式
if __name__ == '__main__':
	import math
	d = read_exccel()
	for t in [u"合计",u"男",u"女"]:
		mean_count = calc_mean(d.get(u"合计").get(t))
		median_count = calc_median(d.get("合计").get(t))
		print("{}人口平均年龄".format(t),mean_count)
		print("{}人口中位数".format(t),median_count)
	d = get_race_num()
	for k,v in d.items():
		var = calc_varaiance(v)
		std = math.sqrt(var)
		print(k,var,std)	
```



## 3、分布

使用pylab绘制直方图

`import matplotlib.pyplot as plt`

## enumerate()说明

- enumerate()是python的内置函数

- enumerate在字典上是枚举、列举的意思

- 对于一个可迭代的（iterable）/可遍历的对象（如列表、字符串），enumerate将其组成一个索引序列，利用它可以同时获得索引和值

- enumerate多用于在for循环中得到计数

- 例如对于一个seq，得到：

  ```
  (0, seq[0]), (1, seq[1]), (2, seq[2])
  ```

```python
if __name__ == '__main__':
	import matplotlib.pyplot as plt 
	d = read_exccel()
	men_num = d.get("合计").get("男")
	women_num = d.get("合计").get("女")
	bottom = [0] *100
	color_list = ['b' ,'y']
	p_list = []
	for i,item in enumerate([men_num,women_num]):
		dr = OrderedDict()
		for k,v in item.items():
			if k.isdigit():
				dr[int(k)] = v
		age_list ,num_list= dr.keys(),dr.values()
		#画柱状图的函数 plt.bar
		p = plt.bar(age_list,num_list,bottom = bottom,color = color_list[i])
		#绘制完男性后将直方图顶端赋值给bottom
        bottom = num_list
        p_list.append(p)	
    plt.legend((p_list[0],p_list[1]) , ('Men' ,'Women'))    
	plt.ylabel('polution')
	plt.xlabel('Age')
	plt.title('The distribution of population')
	plt.show()
```

## 归一化

```python
def calc_pmf(data_list):   #概率质量函数（PMF）
	ret_list = []
	total = sum(data_list)
	for item in data_list:
		ret_list.append(float(item) / total)
	return ret_list	

#在主程序中加一句
num_list = calc_pm(num_list)
```

## 4、数据可视化入门

### 1、折线图

`import matplotlib.pyplot as plt`

```python
import matplotlib.pyplot as plt

plt.figure(1)
plt.plot([1,2,3,4],[2,5,8,6])
plt.figure(2)
plt.plot([1,5],[4,1])
plt.figure(1)
plt.plot([3,4,5],[1,2,5])
plt.til
plt.savefig('/home/brook/下载/figure1')
plt.show()
```

指定线型，颜色

```python
import matplotlib.pyplot as plt

x = range(30)
#红色的圈
l1 = plt.plot(x,x,'ro')
#蓝色的方块
l2 = plt.plot(x,[y**2 for y in x],'bs')
#绿色的三角
l3 = plt.plot(x,[y**3 for y in x],'g^')

plt.title('title')
plt.xlabel(u"xlabel")
plt.ylabel('ylabel')
#加个说明不是挺好
plt.legend((l1[0],l2[0],l3[0]),('1','2','3'))
plt.show()
```

### 2、柱状图和饼图

直方图之前画过了

饼图

```python
if __name__ == '__main__':
	import matplotlib.pyplot as plt
	d = read_exccel()
	total_num = d.get("合计").get("合计")
	frace = []
	label = []
	for k,v in total_num.items():
		if k.endswith("岁"):
			frace.append(v)
			label.append(k)
	plt.pie(frace,labels = label,autopct='%1.1f%%',startangle = 90)
	plt.show()		


#pie()饼图
import matplotlib.pyplot as plt
import numpy as np
 
#数据
data = [100, 500, 300, 200, 400]
 
plt.figure(dpi=100)
plt.pie(
	data,  #每个饼的实际数据 若大于1 会进行归一化 计算百分比
	explode = [0.0, 0.0, 0.1, 0.2, 0.8],  #每个饼块离中心距离
	colors=['y', 'r', 'g', 'b', '#91e8e1'], #每个饼块的颜色
	labels=['A', 'B', 'C', 'D', 'E'], #每个饼块的标签
	labeldistance=0.8,  #每个饼块标签离中心的距离
	autopct='%1.1f%%',   #百分比的显示模式
	pctdistance=0.4,     #百分比离中心的距离
	shadow=True,          #每个饼块是否显示阴影
	startangle=0,        #默认从x正半轴逆时针起
	radius=1             #饼块半径
	)
 
    
    
```

### 3、坐标中文

```python
from matplotlib.font_manager import FontProperties
font = FontProperties(fname='/usr/share/fonts/opentype/noto/NotoSansCJK-Black.ttc', size=12)
	plt.title(u'不同种类的鸢尾花', fontproperties=font)
```



## 3、概率

验证掷色子两次都为1的概率

```python
from random import	choice

def throw_dice():
	return choice([1,2,3,4,5,6])
def one_trail(train_count = 1000):
	success_count = 0
	for i in range(train_count):
		t1 = throw_dice()
		t2 = throw_dice()
		if t1 == t2 == 1:
			success_count +=1
	return float(success_count) / train_count
	
if __name__ == '__main__':
	for x in range(10):
		print(x+1,one_trail())

```

# 4、数据V科学的第三方库介绍

Numpy是python的科学计算库，提供矩阵运算能力

Pandas 是python的统计分析库

Scikit-learn是python的机器学习库。内置很多的机器学习算法

## 1、Numpy入门和实战

```python
import numpy as np 

#创建  , 列表中放元组
a = np.array([(1,2,3),(4,4,5)])

print(a)
#计算矩阵的秩
print(a.ndim)

#随机生成
np.random.seed(42)
objectCentriod = np.random.uniform(size=(2,2))
Centriod = np.random.uniform(size=(3,2))

a = np.arange(15).reshape(3,5)
#arrange支持小步长
b = np.arange(10,10,5)
c= np.arange(0, 10, 0.1)
#numpy 提供了pi和e linspace() 第三个参数不是步长而是数量，自动找步长
d = np.linspace(0, np.e *10, 5)
#提供了直接生成随机元素的多维数组的方法
e = np.random.random((3,2))

print('a = ' ,a)
print('b = ' ,b)
print('c = ' ,c)
print('d = ' ,d)
print('e = ' ,e)

a = np.arange(15).reshape(3,5)

print('a            ', ' = ' ,a)
#a的秩
print('a.ndim       ', ' = ' ,a.ndim)
#返回数组的形状
print('a.shape      ', ' = ' ,a.shape)
#数组中数据V的类型
print('a.dtype.name ', ' = ' ,a.dtype.name)
#数据类型占用的空间
print('a.itemsize   ', ' = ' ,a.itemsize)
#数组中一共有多少元素
print('a.size       ', ' = ' ,a.size)
#数组的类型
print('type(a)      ', ' = ' ,type(a))

a = np.zeros((3,4), dtype = np.int16)
b = np.ones((2,3))
#创建随机小值组成的矩阵
c = np.empty((4,5))
print('zeros\n',a)
print('ones\n',b)
print('empty\n',c)

```

## 2、基本的运算

`a * b //对应元素相乘`    `a.dot(b)  //矩阵相乘`

```python
import numpy as np 

a = np.random.random((3,3))
print('a \n',a)
#下面三个都按照一维数组进行处理
print('a.sum \n',a.sum())
print('a.min \n',a.min())
print('a.max \n',a.max())
#传入参数 axis =0 按列求和，axis = 1按行求和
print('a.sum（axis = 0） \n',a.sum(axis = 0))
print('a.sum（axis = 1） \n',a.sum(axis = 1))
#cumsum逐步累加，按照行的方向
print('a.cumsum（axis = 1） \n',a.cumsum(axis = 1))

>>>
a 
 [[0.25521074 0.99461405 0.08683476]
 [0.81732497 0.27930411 0.46739379]
 [0.90451537 0.94663268 0.64266418]]
a.sum 
 5.39449465758077
a.min 
 0.08683475980377364
a.max 
 0.9946140493279078
a.sum（axis = 0） 
 [1.97705108 2.22055085 1.19689273]
a.sum（axis = 1） 
 [1.33665955 1.56402287 2.49381224]
a.cumsum（axis = 1） 
 [[0.25521074 1.24982479 1.33665955]
 [0.81732497 1.09662908 1.56402287]
 [0.90451537 1.85114806 2.49381224]]

```



## 3、切片索引操作

```python
import numpy as np 

#两个参数，第一个为传入x,y索引序号的函数，第二个为数组的形状
a = np.fromfunction(lambda x,y: 5*x + y, (5, 4))
#切片，下标和列表相似
print('a\n',a)
print('a[2,-1]\n',a[2,-1])
print('a[:,1:3]\n',a[:,1:3])

b = np.fromfunction(lambda x,y,z: x+y+z, (4,5,6))
print('b\n',b)
#在较高大的维度下，...代表剩下的所有维度
print('b[1,...]\n',b[1,...])

>>>
a
 [[ 0.  1.  2.  3.]
 [ 5.  6.  7.  8.]
 [10. 11. 12. 13.]
 [15. 16. 17. 18.]
 [20. 21. 22. 23.]]
a[2,-1]
 13.0
a[:,1:3]
 [[ 1.  2.]
 [ 6.  7.]
 [11. 12.]
 [16. 17.]
 [21. 22.]]
b
 [[[ 0.  1.  2.  3.  4.  5.]
  [ 1.  2.  3.  4.  5.  6.]
  [ 2.  3.  4.  5.  6.  7.]
  [ 3.  4.  5.  6.  7.  8.]
  [ 4.  5.  6.  7.  8.  9.]]

 [[ 1.  2.  3.  4.  5.  6.]
  [ 2.  3.  4.  5.  6.  7.]
  [ 3.  4.  5.  6.  7.  8.]
  [ 4.  5.  6.  7.  8.  9.]
  [ 5.  6.  7.  8.  9. 10.]]

 [[ 2.  3.  4.  5.  6.  7.]
  [ 3.  4.  5.  6.  7.  8.]
  [ 4.  5.  6.  7.  8.  9.]
  [ 5.  6.  7.  8.  9. 10.]
  [ 6.  7.  8.  9. 10. 11.]]

 [[ 3.  4.  5.  6.  7.  8.]
  [ 4.  5.  6.  7.  8.  9.]
  [ 5.  6.  7.  8.  9. 10.]
  [ 6.  7.  8.  9. 10. 11.]
  [ 7.  8.  9. 10. 11. 12.]]]
b[1,...]
 [[ 1.  2.  3.  4.  5.  6.]
 [ 2.  3.  4.  5.  6.  7.]
 [ 3.  4.  5.  6.  7.  8.]
 [ 4.  5.  6.  7.  8.  9.]
 [ 5.  6.  7.  8.  9. 10.]]

```

## 3、numpy的迭代

与列表类似，无论原来的数组是几维的，flat属性都会获得一个摊平的数组

```python
#按行迭代
for row in a:
	print(row)
#按元素迭代
for e in a.flat:
	print(e)
>>>
[0. 1. 2. 3.]
[5. 6. 7. 8.]
[10. 11. 12. 13.]
[15. 16. 17. 18.]
[20. 21. 22. 23.]
0.0
1.0
2.0
3.0
.....
```

## 4、数组的形状改变

```python
import numpy as np 

a = np.random.random((3,4))
print('a\n',a)
print('a.shape\n',a.shape)
print('a.T\n',a.T) #转置

a.resize((2,6)) #原地修改
print('resize(2,6)\n',a)

#使用reshape()函数，被赋值为-1的维度会自动计算
print('a.reshape(3,-1)',a.reshape(3,-1))
>>> c = np.array([1,2,3,4])
#整形成4行一列
>>> np.tile(c,(4,1))
array([[1, 2, 3, 4],
       [1, 2, 3, 4],
       [1, 2, 3, 4],
       [1, 2, 3, 4]])
```

## 5、数组的堆叠

```python
a = np.random.random((2,3))
b = np.random.random((2,3))

print(a,'\n')
print(b,'\n')
#垂直方向堆叠
print('np.vstack((a,b))\n',np.vstack((a,b)))
#水平方向堆叠
print('np.hstack((a,b))\n',np.hstack((a,b)))

#堆叠分割
a.hsplit(a,3) #纵向切割
a.vsplit(a,2) #水平切割
```

## 6、【NumPy】 之常见运算（np.around、np.floor、np.ceil、np.where）

around
np.around 返回四舍五入后的值，可指定精度。

around(a, decimals=0, out=None)

a 输入数组

decimals 要舍入的小数位数。 默认值为0。 如果为负，整数将四舍五入到小数点左侧的位置

```python
import numpy as np

n = np.array([-0.746, 4.6, 9.4, 7.447, 10.455, 11.555])

around1 = np.around(n)
print(around1)  # [ -1.   5.   9.   7.  10.  12.]

around2 = np.around(n, decimals=1)
print(around2)  # [ -0.7   4.6   9.4   7.4  10.5  11.6]

around3 = np.around(n, decimals=-1)
print(around3)  # [ -0.   0.  10.  10.  10.  10.]

```



 floor
np.floor 返回不大于输入参数的最大整数。 即对于输入值 x ，将返回最大的整数 i ，使得 i <= x。 注意在Python中，向下取整总是从 0 舍入。



```python
import numpy as np

n = np.array([-1.7, -2.5, -0.2, 0.6, 1.2, 2.7, 11])

floor = np.floor(n)
print(floor)  # [ -2.  -3.  -1.   0.   1.   2.  11.]
```



ceil
np.ceil 函数返回输入值的上限，即对于输入 x ，返回最小的整数 i ，使得 i> = x。



```python
import numpy as np

n = np.array([-1.7, -2.5, -0.2, 0.6, 1.2, 2.7, 11])

ceil = np.ceil(n)
print(ceil)  # [ -1.  -2.  -0.   1.   2.   3.  11.]
·

 

np.where
numpy.where(condition[, x, y])

#根据 condition 从 x 和 y 中选择元素，当为 True 时，选 x，否则选 y。

import numpy as np

data = np.random.random([2, 3])
print data
'''
[[ 0.93122679  0.82384876  0.28730977]
 [ 0.43006042  0.73168913  0.02775572]]
'''

result = np.where(data > 0.5, data, 0)
print result
'''
[[ 0.93122679  0.82384876  0.        ]
 [ 0.          0.73168913  0.        ]]
'''

## 

```



---------------------
## 7、numpy 高级特性

可以使用numpy提供的数组进行取值

```python
a = np.random.random(20) *3
i = np.array([1,3,7,2,4])
print('a[i]\n',a[i])
j = np.array([[3,4],[5,6]])
print('a[j]\n',a[j])

>>>
a[i]
 [1.66613807 2.88637904 1.67483648 2.32280711 2.39973917]
a[j]
 [[2.88637904 2.39973917]
 [0.25579477 0.24425026]]
a = np.arange(12).reshape(3,4)
i = np.array([[1,1],[3,3]]) #行向索引
j = np.array([[1,1],[2,2]]) #列向索引
print(i,j)


```

### 生成随机数numpy.random模块的用法

```python
import numpy as np

np.random.uniform(low=0.0,high=1.0,size=None)
#生出size个符合分布的浮点数，范围[low,high)
np.random.uniform(5,6,size=(2,3))
>>
array([[5.82416021, 5.68916836, 5.89708586],
       [5.63843125, 5.22963754, 5.4319899 ]])


#生成一个(d0, d1, ..., dn)维的数组，数组的元素取自[0, 1)上的均分布，若没有参数输入，则生成一个数
numpy.random.rand(d0, d1, ..., dn)
>>> random.rand(3,2,1)
array([[[0.00404447],
        [0.3837963 ]],

       [[0.32518355],
        [0.82482599]],

       [[0.79603205],
        [0.19087375]]])
#设置随机生成算法的初始值
numpy.random.seed(seed=None)

#生成size个整数，取值区间为[low, high)，若没有输入参数high则取值区间为[0, low)
numpy.random.randint(low, high=None, size=None, dtype='I')
```





### megrid

```python
import numpy as np
import matplotlib.pyplot as plt
%matplotlib inline
m, n = (5, 3)
x = np.linspace(0, 1, m)
y = np.linspace(0, 1, n)
X, Y = np.meshgrid(x,y)

>>>X
out:
array([[ 0.  ,  0.25,  0.5 ,  0.75,  1.  ],
       [ 0.  ,  0.25,  0.5 ,  0.75,  1.  ],
       [ 0.  ,  0.25,  0.5 ,  0.75,  1.  ]])
Y
out:
array([[ 0. ,  0. ,  0. ,  0. ,  0. ],
       [ 0.5,  0.5,  0.5,  0.5,  0.5],
       [ 1. ,  1. ,  1. ,  1. ,  1. ]])
```

axis

- 使用0值表示沿着每一列或行标签\索引值向下执行方法
- 使用1值表示沿着每一行或者列标签模向执行对应的方法

## **排序**

```python
data = np.sin(np.arange(20)).reshape(5,4)
print(data)
ind = data.argmax(axis = 0)  #返回的是排序之后的坐标 ，按照跨行来排序
print(ind)
sort = data.argsort() #返回值为按每行从小到大排序，获得对应的坐标
print(sort)


#使用布尔索引获取我们想要的值
>>> a = np.arange(15).reshape(3,5)
>>> b = a > 3
>>> print('a\n',a)
a
 [[ 0  1  2  3  4]
 [ 5  6  7  8  9]
 [10 11 12 13 14]]
>>> print(b)
[[False False False False  True]
 [ True  True  True  True  True]
 [ True  True  True  True  True]]
>>> print('a[b]\n',a[b])
a[b]
 [ 4  5  6  7  8  9 10 11 12 13 14]

```



## 8、有关线性代数的计算





```python
import numpy as np
a = np.array([[1,2],[3,4]]) # 示例矩阵

A1 = np.linalg.eigvals(a)  # 得到特征值

A2,B = np.linalg.eig(a) # 其中A2也是特征值，B为特征向量

a.T,a.transpose() #转置

np.eye(4)           #对角矩阵
np.trace(np.eye(3))      #矩阵的迹

a = np.array([1,2],[3,4])
y = np.array([3.],[4.])
print(np.linalg.solve(a,y))   #解线性方程组

```



## 9、KNN实战

```python
>>> c = np.array([1,2,3,4])
>>> np.tile(c,(4,1))
array([[1, 2, 3, 4],
       [1, 2, 3, 4],
       [1, 2, 3, 4],
       [1, 2, 3, 4]])




```



```python
import csv
import random
import matplotlib.pyplot as plt 
import numpy as np 
from collections import defaultdict,Counter
from matplotlib.font_manager import FontProperties
font = FontProperties(fname='/usr/share/fonts/opentype/noto/NotoSansCJK-Black.ttc', size=12)
def get_data(loc):
	with open(loc,'r') as fr:
		lines = csv.reader(fr)
		data_file = np.array(list(lines))
	# ****************将字符串转化为数字太重要了××××××××××××88888	
	data = data_file[1:,1:5].astype(float)
	labels = data_file[1:,5]
	return data,labels	

def draw():
	style_list = ['ro','go','bo']
	data,labels = get_data(loc_files)
	cc = defaultdict(list)
	for i ,d in enumerate(data):
		cc[labels[i]].append(d)
	p_list = []
	c_list = []
	for i ,(c,cd) in enumerate(cc.items()):
		draw_data = np.array(cd)
		#花瓣的长度和宽度
		p = plt.plot(draw_data[:,2],draw_data[:,3],style_list[i])
		#萼片的长度和宽度
		#p = plt.plot(draw_data[:,2],draw_data[:,3],style_list[i])
		p_list.append(p)
		c_list.append(c)   
		print(p_list)
	plt.legend(map(lambda x:x[0],p_list),c_list)
	plt.title(u'不同种类的鸢尾花', fontproperties=font)
	plt.xlabel(u'lenghCm')
	plt.ylabel(u'withCm')
	plt.show()	
#KNN的算法实现
#计算一个未分类的数据，将值与已知的点与点之间的距离做分类。
#选择距离最近的k个点，将位置分类的数句归类到占比最多的类中。
  
def classify(input_data,train_data,labels,k):
	 data_size = train_data.shape[0]
	 #将input_data 整合成括号里的形式
	 #print(input_data,train_data)
	 diff = np.tile(input_data,(data_size,1))-train_data
	# print(np.tile(input_data,(data_size,1)))
	 sqrt_diff = diff **2
	 sqrt_distance = sqrt_diff.sum(axis = 1)
	 distance = np.sqrt(sqrt_distance)
	 #将distance从大到小排序，返回索引下标。
	 sorted_index = distance.argsort()
	 #下标的前k个取出来label计数选出来最多的lablel
	 class_count = Counter(labels[sorted_index[:k]])
	 return class_count.most_common()[0][0]

def try_once():
	data ,labels = get_data(loc_files)
	index = list(range(len(data)))
	labels = labels[index]
	data = data[index]
	#将index随机打乱
	random.shuffle(index)
	data = data[index]
	labels = labels[index]
	input_data = data[-1]
	input_label = labels[-1]
	data = data[:-1]
	labels = labels[:-1]
	print('input_index:',index[-1])
	print('true class:',input_label)
	print(classify(input_data, data, labels, 5))











'''
>>>seasons = ['Spring', 'Summer', 'Fall', 'Winter']
>>> list(enumerate(seasons))
[(0, 'Spring'), (1, 'Summer'), (2, 'Fall'), (3, 'Winter')]
'''
if __name__ == '__main__':

	loc_files = '/home/brook/下载/iris-species/Iris.csv'	


	draw()

	try_once()
```



# 5、Pandas的入门和实战

Pandas是一个基于Numpy的数句分析库，提供了DataFrame这个数据结构，直接在数聚集上能完成分组（group by），聚合(agg)和联合(join)等操作。完成数据V清洗建模最终组织结果/绘图等工作。

提供基础类型Series类型，**只能包含同一类型的元素**。有索引的类型，可以像字典一样的工作。

```python
import numpy as np 
import pandas as pd 
 
a = pd.Series([1,0.3,np.nan])

b= pd.Series(np.array([1,2,3]))
print("a\n",a)
print("b\n",b)
print('a[a >0.5]',a[a >0.5])
print('a[[2,1]]',a[[2,1]])
>>>
a
 0    1.0
1    0.3
2    NaN
dtype: float64
b
 0    1
1    2
2    3
dtype: int64
#第一列为序号。    
a[a >0.5] 0    1.0
dtype: float64
a[[2,1]] 2    NaN
1    0.3
dtype: float64
  # 其中的类型会被统一化
c = pd.Series([1,2,3],index = ['a','b','c'])
print('c\n',c)
print('c[b]\n',c['b'])
print(c.get('a'))
d = pd.Series({'c':0,'d':1})
print('d\n',d)
>>>
c
 a    1
b    2
c    3
dtype: int64
c[b]
 2
1
d
 c    0
d    1
dtype: int64

```



### 10、numpy 和pytorch中的数据进行转换

```python
import numpy as np
import torch
 
np_arr = np.array([1,2,3,4])
tor_arr=torch.from_numpy(np_arr)    # np >> tensor
tor2numpy=tor_arr.numpy()            # tensor >> np
print('\nnumpy\n',np_arr,'\ntorch\n',tor_arr,'\nnumpy\n',tor2numpy)

```



## DataFrame

 



```python
df = pd.DataFrame(np.random.randn(8, 4),columns = ['A','B','C','D'])
df1 = pd.DataFrame({'A':[4]})

print(df1)
#print(df)
print(df.append(df1,ignore_index = True))
```



Pandas 数据结构

 

Series 是一种一维数组，和 NumPy 里的数组很相似。事实上，Series 基本上就是基于 NumPy 的数组对象来的。和 NumPy 的数组不同，Series 能为数据自定义标签，也就是索引（index），然后通过索引来访问数组中的数据。

 

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648024ba0a19a677)

 

 

 

创建一个 Series 的基本语法如下：

 

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648061692b4fe9b1)

 

 

 

上面的 data 参数可以是任意数据对象，比如字典、列表甚至是 NumPy 数组，而index 参数则是对 data 的索引值，类似字典的 key。

下面这个例子里，将创建一个 Series 对象，并用字符串对数字列表进行索引：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371676480985eb9ca4d03)

 

 

注意：请记住， index 参数是可省略的，你可以选择不输入这个参数。如果不带 index 参数，Pandas 会自动用默认 index 进行索引，类似数组，索引值是 [0, ..., len(data) - 1] ，如下所示：

从 NumPy 数组对象创建 Series：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648188c160e18f7c)

 

 

从 Python 字典对象创建 Series：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648188c160e18f7c)

 

 

如上图的 out[24] 中所示，如果你从一个 Python 字典对象创建 Series，Pandas 会自动把字典的键值设置成 Series 的 index，并将对应的 values 放在和索引对应的 data 里。

和 NumPy 数组不同，Pandas 的 Series 能存放各种不同类型的对象。

从 Series 里获取数据

 

访问 Series 里的数据的方式，和 Python 字典基本一样：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/15371676481061fe9ccbd40)

 

 

对 Series 进行算术运算操作

 

对 Series 的算术运算都是基于 index 进行的。我们可以用[加减乘除](https://www.baidu.com/s?wd=%E5%8A%A0%E5%87%8F%E4%B9%98%E9%99%A4&tn=24004469_oem_dg&rsv_dl=gh_pl_sl_csd)（+ - * /）这样的运算符对两个 Series 进行运算，Pandas 将会根据索引 index，对响应的数据进行计算，结果将会以浮点数的形式存储，以避免丢失精度。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648255e2aa9779fc)

 

 

如上，如果 Pandas 在两个 Series 里找不到相同的 index，对应的位置就返回一个空值 NaN。

DataFrames

 

Pandas 的 DataFrame（数据表）是一种 2 维数据结构，数据以表格的形式存储，分成若干行和列。通过 DataFrame，你能很方便地处理数据。常见的操作比如选取、替换行或列的数据，还能重组数据表、修改索引、多重筛选等。

构建一个 DataFrame 对象的基本语法如下：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371676480615200256da4)

 

 

 

举个例子，我们可以创建一个 5 行 4 列的 DataFrame，并填上随机数据：

看，上面表中的每一列基本上就是一个 Series ，它们都用了同一个 index。因此，我们基本上可以把 DataFrame 理解成一组采用同样索引的 Series 的集合。

下面这个例子里，

### 1、我们将用许多 Series 来构建一个DataFrame：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648175706ea6cd06)

 

 

### 2、以及用一个字典来创建 DataFrame：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/153716764818864ecd36d9f)

 

 

获取 DataFrame 中的列

 

要获取一列的数据，还是用中括号 [] 的方式，跟 Series 类似。比如尝试获取上面这个表中的 name 列数据：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167648149dcfd11f04a)

 

 

因为我们只获取一列，所以返回的就是一个 Series。可以用 type() 函数确认返回值的类型：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648167eceac0f312)

 

 

如果获取多个列，那返回的就是一个 DataFrame 类型：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648224603843ca3b)

 

 

向 DataFrame 里增加数据列

 

创建一个列的时候，你需要先定义这个列的数据和索引。举个栗子，比如这个 DataFrame：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371676483830ac1ebcb79)

 

 

增加数据列有两种办法：可以从头开始定义一个 pd.Series，再把它放到表中，也可以利用现有的列来产生需要的新列。比如下面两种操作：

### 3、定义一个 Series ，并放入 'Year' 列中：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648300b730636b8b)

 

 

从现有的列创建新列：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648300b730636b8b)

 

 

### 4、从 DataFrame 里删除行/列

想要删除某一行或一列，可以用 .drop() 函数。在使用这个函数的时候，你需要先指定具体的删除方向，axis=0 对应的是行 row，而 axis=1 对应的是列 column 。

删除 'Birth_year' 列：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/15371676482175c85846c6e)

 

 

删除 'd' 行：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/15371676482175c85846c6e)

 

 

请务必记住，除非用户明确指定，否则在调用 .drop() 的时候，Pandas 并不会真的永久性地删除这行/列。这主要是为了防止用户误操作丢失数据。

你可以通过调用 df 来确认数据的完整性。如果你确定要永久性删除某一行/列，你需要加上 inplace=True 参数，比如：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648210c5e80b1fed)

 

 

获取 DataFrame 中的一行或多行数据

 

要获取某一行，你需要用 .loc[] 来按索引（标签名）引用这一行，或者用 .iloc[]，按这行在表中的位置（行数）来引用。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371676481564e15d9347a)

 

 

同时你可以用 .loc[] 来指定具体的行列范围，并生成一个子数据表，就像在 **NumPy**里做的一样。比如，提取 'c' 行中 'Name’ 列的内容，可以如下操作：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167648213854b9333a6)

 

 

此外，你还可以制定多行和/或多列，如上所示。

条件筛选

用中括号 [] 的方式，除了直接指定选中某些列外，还能接收一个条件语句，然后筛选出符合条件的行/列。比如，我们希望在下面这个表格中筛选出 'W'>0 的行：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648160a6e8ca16e0)

 

 

如果要进一步筛选，只看 'X' 列中 'W'>0 的数据：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371676480615200256da4)

 

 

类似的，你还可以试试这样的语句 df[df['W']>0][['X','Y']] ，结果将会是这样：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371676480615200256da4)

 

 

上面那行相当于下面这样的几个操作连在一起：

 

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371676481189a41cc34b2)

 

 

 

你可以用逻辑运算符 &（与）和 |（或）来链接多个条件语句，以便一次应用多个筛选条件到当前的 DataFrame 上。举个栗子，你可以用下面的方法筛选出同时满足 'W'>0 和'X'>1 的行：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648181aaf4317fee)

 

 

### 5、重置 DataFrame 的索引

如果你觉得当前 DataFrame 的索引有问题，你可以用 .reset_index() 简单地把整个表的索引都重置掉。这个方法将把目标 DataFrame 的索引保存在一个叫 index 的列中，而把表格的索引变成默认的从零开始的数字，也就是 [0, ..., len(data) - 1] 。比如下面这样：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648125ff01fef26c)

 

 

和删除操作差不多，.reset_index() 并不会永久改变你表格的索引，除非你调用的时候明确传入了 inplace 参数，比如：.reset_index(inplace=True)

设置 DataFrame 的索引值

类似地，我们还可以用 .set_index() 方法，将 DataFrame 里的某一列作为索引来用。比如，我们在这个表里新建一个名为 "ID" 的列：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371676482594f47b6ff7e)

 

 

然后把它设置成索引：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371676482594f47b6ff7e)

 

 

注意，不像 .reset_index() 会保留一个备份，然后才用默认的索引值代替原索引，.set_index() 将会完全覆盖原来的索引值。

多级索引（MultiIndex）以及命名索引的不同等级

 

多级索引其实就是一个由元组（Tuple）组成的数组，每一个元组都是[独一无二](https://www.baidu.com/s?wd=%E7%8B%AC%E4%B8%80%E6%97%A0%E4%BA%8C&tn=24004469_oem_dg&rsv_dl=gh_pl_sl_csd)的。你可以从一个包含许多数组的列表中创建多级索引（调用 MultiIndex.from_arrays ），也可以用一个包含许多元组的数组（调用 MultiIndex.from_tuples ）或者是用一对可迭代对象的集合（比如两个列表，互相两两配对）来构建（调用MultiIndex.from_product ）。

下面这个例子，我们从元组中创建多级索引：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167648207f516c304cc)

 

 

最后这个 list(zip()) 的嵌套函数，把上面两个列表合并成了一个每个元素都是元组的列表。这时 my_index 的内容是这样的：[('O Level', 21), ('O Level', 22), ('O Level', 23), ('A Level', 21), ('A Level', 22), ('A Level', 23)]

接下来，我们调用 .MultiIndex.from_tuples(my_index) 生成一个多级索引对象：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/153716764826052ab36ed2b)

 

 

最后，将这个多级索引对象转成一个 DataFrame：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371676480615200256da4)

 

 

### #要获取多级索引中的数据

，还是用到 .loc[] 。比如，先获取 'O Level' 下的数据：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/15371676482017d56a6447f)

 

 

然后再用一次 .loc[]，获取下一层 21 里的数据：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/15371676482017d56a6447f)

 

 

如上所示，df 这个 DataFrame 的头两个索引列没有名字，看起来不太易懂。我们可以用 .index.names 给它们加上名字：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/153716764819226a36d0dd9)

 

 

交叉选择行和列中的数据

 

我们可以用 .xs() 方法轻松获取到多级索引中某些特定级别的数据。比如，我们需要找到所有 Levels 中，Num = 22 的行：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648198a4e3b0c29a)

 

 

清洗数据

### **6、删除或填充空值**

在许多情况下，如果你用 Pandas 来读取大量数据，往往会发现原始数据中会存在不完整的地方。在 DataFrame 中缺少数据的位置， Pandas 会自动填入一个空值，比如 NaN或 Null 。因此，我们可以选择用 .dropna() 来丢弃这些自动填充的值，或是用.fillna() 来自动给这些空值填充数据。

比如这个例子：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167648210f3ac03561e)

 

 

当你使用 .dropna() 方法时，就是告诉 Pandas 删除掉存在一个或多个空值的行（或者列）。删除列用的是 .dropna(axis=0) ，删除行用的是 .dropna(axis=1) 。

请注意，如果你没有指定 axis 参数，默认是删除行。

**删除行：**

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/15371676482041e0ea097e4)

 

 

删除列：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/15371676482041e0ea097e4)

 

 

类似的，如果你使用 .fillna() 方法，Pandas 将对这个 DataFrame 里所有的空值位置填上你指定的默认值。比如，将表中所有 NaN 替换成 20 ：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167648190bf6d370b0b)

 

 

当然，这有的时候打击范围太大了。于是我们可以选择只对某些特定的行或者列进行填充。比如只对 'A' 列进行操作，在空值处填入该列的平均值：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371676480615200256da4)

 

 

如上所示，'A' 列的平均值是 2.0，所以第二行的空值被填上了 2.0。

同理，.dropna() 和 .fillna() 并不会永久性改变你的数据，除非你传入了inplace=True 参数。

**Pandas** 是基于 **NumPy** 的一个开源 Python 库，它被广泛用于快速分析数据，以及数据清洗和准备等工作。它的名字来源是由“ Panel data”（面板数据，一个计量经济学名词）两个单词拼成的。简单地说，你可以把 Pandas 看作是 Python 版的 Excel。

我喜欢 Pandas 的原因之一，是因为它很酷，它能很好地处理来自一大堆各种不同来源的数据，比如 Excel 表格、CSV 文件、SQL 数据库，甚至还能处理存储在网页上的数据。

### 7、分组统计

 

Pandas 的分组统计功能可以按某一列的内容对数据行进行分组，并对其应用统计函数，比如求和，平均数，中位数，标准差等等…

举例来说，用 .groupby() 方法，我们可以对下面这数据表按 'Company' 列进行分组，并用 .mean() 求每组的平均值：

首先，初始化一个DataFrame：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726629b2de42e661)

 

 

然后，调用 .groupby() 方法，并继续用 .mean() 求平均值：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726629b2de42e661)

 

 

上面的结果中，Sales 列就变成每个公司的分组平均数了。

计数

 

用 .count() 方法，能对 DataFrame 中的某个元素出现的次数进行计数。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726467563000d2f8)

 

 

### 8、数据描述

 

Pandas 的 .describe() 方法将对 DataFrame 里的数据进行分析，并一次性生成多个描述性的统计指标，方便用户对数据有一个直观上的认识。

生成的指标，从左到右分别是：计数、平均数、标准差、最小值、25% 50% 75% 位置的值、最大值。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726517bfb4bed41d)

 

 

如果你不喜欢这个排版，你可以用 .transpose() 方法获得一个竖排的格式：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/153716772661880ff8648b5)

 

 

如果你只想看 Google 的数据，还能这样：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/153716772661880ff8648b5)

 

 

### 9、堆叠（Concat）

 

堆叠基本上就是简单地把多个 DataFrame 堆在一起，拼成一个更大的 DataFrame。当你进行堆叠的时候，请务必注意你数据表的索引和列的延伸方向，堆叠的方向要和它一致。

比如，有这样3个 DataFrame：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726467563000d2f8)

 

 

我们用 pd.concat() 将它堆叠成一个大的表：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/153716772659092e26779a4)

 

 

因为我们没有指定堆叠的方向，Pandas 默认按行的方向堆叠，把每个表的索引按顺序叠加。

如果你想要按列的方向堆叠，那你需要传入 axis=1 参数：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726626868062538f)

 

 

注意，这里出现了一大堆空值。因为我们用来堆叠的3个 DataFrame 里，有许多索引是没有对应数据的。因此，当你使用 pd.concat() 的时候，一定要注意堆叠方向的坐标轴（行或列）含有所需的所有数据。

归并（Merge）

 

使用 pd.merge() 函数，能将多个 DataFrame 归并在一起，它的合并方式类似合并 SQL 数据表的方式。

归并操作的基本语法是 pd.merge(left, right, how='inner', on='Key') 。其中 left 参数代表放在左侧的 DataFrame，而 right 参数代表放在右边的 DataFrame；how='inner' 指的是当左右两个 DataFrame 中存在不重合的 Key 时，取结果的方式：inner 代表交集；Outer 代表并集。最后，on='Key' 代表需要合并的键值所在的列，最后整个表格会以该列为准进行归并。

对于两个都含有 key 列的 DataFrame，我们可以这样归并：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167726577d6c95b6e2f)

 

 

同时，我们可以传入多个 on 参数，这样就能按多个键值进行归并：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371677266174d48271ea6)

 

 

连接（Join）

 

如果你要把两个表连在一起，然而它们之间没有太多共同的列，那么你可以试试 .join() 方法。和 .merge() 不同，连接采用索引作为公共的键，而不是某一列。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/153716772658042e6c73fb7)

 

 

同样，inner 代表交集，Outer 代表并集。

数值处理

 

- **查找不重复的值**

 

不重复的值，在一个 DataFrame 里往往是独一无二，[与众不同](https://www.baidu.com/s?wd=%E4%B8%8E%E4%BC%97%E4%B8%8D%E5%90%8C&tn=24004469_oem_dg&rsv_dl=gh_pl_sl_csd)的。找到不重复的值，在数据分析中有助于避免样本偏差。在 Pandas 里，主要用到 3 种方法：

首先是 .unique() 方法。比如在下面这个 DataFrame 里，查找 col2 列中所有不重复的值：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726619ef4eab81df)

 

 

除了列出所有不重复的值，我们还能用 .nunique() 方法，获取所有不重复值的个数：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726556f5b5f5b3fd)

 

 

此外，还可以用 .value_counts() 同时获得所有值和对应值的计数：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371677265753f5868262f)

 

 

- **apply() 方法**

 

用 .apply() 方法，可以对 DataFrame 中的数据应用自定义函数，进行数据处理。比如，我们先定义一个 square() 函数，然后对表中的 col1 列应用这个函数：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726605e7a77e9a98)

 

 

在上面这个例子中，这个函数被应用到这一列里的每一个元素上。同样，我们也可以调用任意的内置函数。比如对 col3 列取长度 len ：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726580699381f88a)

 

 

有的时候，你定义了一个函数，而它其实只会被用到一次。那么，我们可以用 lambda 表达式来代替函数定义，简化代码。比如，我们可以用这样的 lambda 表达式代替上面 In[47] 里的函数定义：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726591fac715dc3a)

 

 

- **获取 DataFrame 的属性**

 

DataFrame 的属性包括列和索引的名字。假如你不确定表中的某个列名是否含有空格之类的字符，你可以通过 .columns 来获取属性值，以查看具体的列名。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726601c0dc81d9f1)

 

 

### 10、排序

 

如果想要将整个表按某一列的值进行排序，可以用 .sort_values() ：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/15371677266361ad0adbc81)

 

 

如上所示，表格变成按 col2 列的值从小到大排序。要注意的是，表格的索引 index 还是对应着排序前的行，并没有因为排序而丢失原来的索引数据。

查找空值

 

假如你有一个很大的数据集，你可以用 Pandas 的 .isnull() 方法，方便快捷地发现表中的空值：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726610c5a6c9161f)

 

 

这返回的是一个新的 DataFrame，里面用布尔值（True/False）表示原 DataFrame 中对应位置的数据是否是空值。

### 11、数据透视表

 

在使用 Excel 的时候，你或许已经试过数据透视表的功能了。数据透视表是一种汇总统计表，它展现了原表格中数据的汇总统计结果。Pandas 的数据透视表能自动帮你对数据进行分组、切片、筛选、排序、计数、求和或取平均值，并将结果直观地显示出来。比如，这里有个关于动物的统计表：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/1537167726633120e66d962)

 

 

Pandas 数据透视表的语法是 .pivot_table(data, values='', index=[''], columns=['']) ，其中 values 代表我们需要汇总统计的数据点所在的列，index 表示按该列进行分组索引，而 columns 则表示最后结果将按该列的数据进行分列。你可以在 Pandas 的官方文档 中找到更多数据透视表的详细用法和例子。

于是，我们按上面的语法，给这个动物统计表创建一个数据透视表：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726643dc1a8b6fce)

 

 

或者也可以直接调用 df 对象的方法：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726643dc1a8b6fce)

 

 

在上面的例子中，数据透视表的某些位置是 NaN 空值，因为在原数据里没有对应的条件下的数据。

导入导出数据

 

采用类似 pd.read_ 这样的方法，你可以用 Pandas 读取各种不同格式的数据文件，包括 Excel 表格、CSV 文件、SQL 数据库，甚至 HTML 文件等。

- ### **11、读取 CSV 文件**

 

简单地说，只要用 pd.read_csv() 就能将 CSV 文件里的数据转换成 DataFrame 对象：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p1.pstatp.com/large/pgc-image/15371677266111e9c50b7b2)

 

 

- **写入 CSV 文件**

 

将 DataFrame 对象存入 .csv 文件的方法是 .to_csv()，例如，我们先创建一个 DataFrame 对象：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167726700912f9c23e7)

 

 

然后我们将这个 DataFrame 对象存成 'New_dataframe' 文件，Pandas 会自动在磁盘上创建这个文件。

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/1537167726700912f9c23e7)

 

 

这里传入 index=False 参数是因为不希望 Pandas 把索引列的 0~5 也存到文件中。

为了确保数据已经保存好了，你可以试试用 pd.read_csv('New_dataframe') ，把这个文件的内容读取出来看看。

### 12、读取 Excel 表格文件

 

Excel 文件是一个不错的数据来源。使用 pd.read_excel() 方法，我们能将 Excel 表格中的数据导入 Pandas 中。请注意，Pandas 只能导入表格文件中的数据，其他对象，例如宏、图形和公式等都不会被导入。如果文件中存在有此类对象，可能会导致 pd.read_excel() 方法执行失败。

举个例子，假设我们有一个 Excel 表格 'excel_output.xlsx'，然后读取它的数据：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p98.pstatp.com/large/pgc-image/153716772659962fe6bf680)

 

 

请注意，每个 Excel 表格文件都含有一个或多个工作表，传入 sheet_name='Sheet1' 这样的参数，就表示只读取 'excel_output.xlsx' 中的 Sheet1 工作表中的内容。

写入 Excel 表格文件

 

跟写入 CSV 文件类似，我们可以将一个 DataFrame 对象存成 .xlsx 文件，语法是 .to_excel() ：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/1537167726759e1b13ff554)

 

 

和前面类似，把数据存到 'excel_output.xlsx' 文件中：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p9.pstatp.com/large/pgc-image/1537167726759e1b13ff554)

 

 

### 13、读取 HTML 文件中的数据

 

为了读取 HTML 文件，你需要安装 htmllib5，lxml 以及 BeautifulSoup4 库，在终端或者命令提示符运行以下命令来安装：

 

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/1537167726598611d4c5c5c)

 

 

 

举个例子，我们用让 Pandas 读取这个页面的数据： https://en.wikipedia.org/wiki/Udacity 。由于一个页面上含有多个不同的表格，我们需要通过下标 [0, ..., len(tables) - 1] 访问数组中的不同元素。

下面的这个例子，我们显示的是页面中的第 2 个表格：

![用一个月整理的Pandas的教程！最全面的教程没有之一！先收藏吧！](http://p3.pstatp.com/large/pgc-image/15371677266756ead4d0063)

 

 

结语



原

# argparse用法总结 (命令行参数)

```python
parse.add_argument('pkg',help='help')
//这是最基础的参数格式，如果是这样的格式，说明pkg是一个必须的参数，如果不加入这样的参数，则会报错。
12
import argparse    //导入命令行解析的库文件
parse = argparse.ArgumentParser(description="test!!")  //为了别人执行代码的时候用--help看出来怎么使用这些代码

```

以上两句是必须的，下面是根据你的代码需要添加的参数命令行：

```python
parse.add_argument('keyoukewu',help='keyoukewu'，nargs='?')  //如果不加上最后一个参数nargs则执行代码的时候必须加上这个参数，
															//如果有nargs说明这个参数可带可不带
12
parse.add_argument('-a','--abc',help='a sourcedir',nargs='?')
print(args.abc)
print(args.a) //是错误的
//运行时使用python demo.py -a abc
//或者使用python demo.py --abc abc(使用的是两个短横)
//参数的前面可以添加‘-’，也可以添加‘--’。说明添加的参数可以用简写也可以用全称来标明。但是解析的时候必须用全称。
123456
```

有些参数可以不加上的时候默认的值是bool变量。

```python
parse.add_argument('-a','--abc',help='a sourcedir',action='store_true')
//这里的参数action的作用标明如果不写参数的话默认的print(args.a)的值是false，但是如果加上参数的话默认的print(args.a)的值
//为true，其中运行的参数的值不需要加上。
//如果很多的参数都加上了这些参数

parser.add_option("-v", action="store_true", dest="verbose")  
parser.add_option("-q", action="store_false", dest="verbose")  
这样的话，当解析到 ‘-v’，options.verbose 将被赋予 True 值，反之，解析到 ‘-q’，会被赋予 False 值。
12345678
```

上面的情况是默认为bool类型变量的0，当然也可以设置为自己想要的默认值。

```python
parse.add_argument('-a','--abc',help='a sourcedir',action='store_true'，default=3)
//这时如果加上default的关键字，如果加上参数的话为则参数的值为1，但如果不加则采用默认的3，不再是0
//但是这时由于采用了action='store_true'的关键字，所以不再加上得关键字不能再跟着int的数字
//例如：python demo.py -a (is not ture.)
parse.add_argument('-a','--abc',help='a sourcedir',default=3)
//must add！！！！！！！1
123456
```

f
添加互斥的参数组，因为有些参数的使用是不能同时出现的：

```python
group = parse.add_mutually_exclusive_group()   //必须先要定义一个互斥的参数组
group.add_argument('-a','--abc',help='a sourceaaa',action='store_true') //在参数组内添加互斥的参数，必须加上store_true的参数
group.add_argument('-b','--bc',help='a sourceabb',action='store_true')

如果定义了以上参数后，运行以上的代码时，-a -b的参数只能加上一个，加上的为true，不可以同时加上。无论在互斥组内有多少的参数，都只能出现一个。
12345
```

说明，在其中如果出现形式如下：

```
parse.add_argument('-a','--abc',help='a sourcedir',nargs='?')
//这时参数的全名为abc，但是如果出现dest关键字，则全程为dest关键字定义的字段
parse.add_argument('-a','--abc'，dest='mn',help='a sourcedir',nargs='?')
//这时无论全名是mn，不再是abc
1234
```

python 中默认的sys.argv[]会自动保存运行python代码时的参数，如果参数为一个就保存在sys.argv[1]中，多的会依次向下存：

```python
import sys

print(sys.argv[1])
print(sys.argv[2])
1234
```

如果执行以上的代码：
python 1 2
会自动打印1，2
但是必须是两个参数。不然会提示参数过多而导致数组下标越界.



### 提取输入的数据

```python
args = parser.parse_args()
print(args)
name = args.name
year = args.year
print('Hello {}  {}'.format(name,year))
```





















![img](https://img-blog.csdn.net/2018100917221176?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)







# yolo系列之yolo v3【深度解析】

置顶 2018年09月12日 16:24:48 [木盏](https://me.csdn.net/leviopku) 阅读数：35331



**版权申明：转载和引用图片，都必须经过书面同意。获得留言同意即可**
本文使用图片多为本人所画，需要高清图片可以留言联系我，先点赞后取图
这篇博文比较推荐的yolo v3代码是qwe的keras版本，复现比较容易，代码相对来说比较容易理解。同学们可以结合代码和博文共同理解v3的精髓。
github地址：<https://github.com/qqwweee/keras-yolo3>
基于tensorflow的实现代码可以参考：
<https://github.com/wizyoung/YOLOv3_TensorFlow>

------

## 前言

前言就是唠唠嗑，想直接看干货可以跳过前言，直接看Yolo v3。
yolo_v3是我最近一段时间主攻的算法，写下博客，以作分享交流。
看过yolov3论文的应该都知道，这篇论文写得很随意，很多亮点都被作者都是草草描述。很多骚年入手yolo算法都是从v3才开始，这是不可能掌握yolo精髓的，因为v3很多东西是保留v2甚至v1的东西，而且v3的论文写得很随心。想深入了解yolo_v3算法，是有必要先了解v1和v2的。以下是我关于v1和v2算法解析所写的文章：
v1算法解析：《[yolo系列之yolo v1](https://blog.csdn.net/leviopku/article/details/82588059)》
v2算法解析：《[yolo系列之yolo v2](https://blog.csdn.net/leviopku/article/details/82588959)》
yolo_v3作为yolo系列目前最新的算法，对之前的算法既有保留又有改进。先分析一下yolo_v3上保留的东西：

1. “分而治之”，从yolo_v1开始，yolo算法就是通过划分单元格来做检测，只是划分的数量不一样。
2. 采用"leaky ReLU"作为激活函数。
3. 端到端进行训练。一个loss function搞定训练，只需关注输入端和输出端。
4. 从yolo_v2开始，yolo就用batch normalization作为正则化、加速收敛和避免过拟合的方法，把BN层和leaky relu层接到每一层卷积层之后。
5. 多尺度训练。在速度和准确率之间tradeoff。想速度快点，可以牺牲准确率；想准确率高点儿，可以牺牲一点速度。

yolo每一代的提升很大一部分决定于backbone网络的提升，从v2的darknet-19到v3的darknet-53。yolo_v3还提供替换backbone——tiny darknet。要想性能牛叉，backbone可以用Darknet-53，要想轻量高速，可以用tiny-darknet。总之，yolo就是天生“灵活”，所以特别适合作为**工程**算法。
当然，yolo_v3在之前的算法上保留的点不可能只有上述几点。由于本文章主要针对yolo_v3进行剖析，不便跑题，下面切入正题。

------

## **YOLO v3**

网上关于yolo v3算法分析的文章一大堆，但大部分看着都不爽，为什么呢？因为他们没有这个玩意儿：
![img](https://img-blog.csdn.net/2018100917221176?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

图1. yolo_v3结构图

yolo系列里面，作者只在v1的论文里给出了结构图，而v2和v3的论文里都没有结构图，这使得读者对后两代yolo结构的理解变得比较难。but，对于yolo学习者来说，脑子里没有一个清晰的结构图，就别说自己懂yolo了。上图是我根据官方代码和官方论文以及模型结构可视化工具等经过好几个小时画出来的，修订过几个版本。所以，

上图的准确性是可以保证的

。

**这里推荐的模型结构可视化工具是**：[Netron](https://blog.csdn.net/leviopku/article/details/81980249)
netron方便好用，可以直观看到yolo_v3的**实际计算结构**，精细到卷积层。But，要进一步在人性化的角度分析v3的结构图，还需要结合论文和代码。对此，我是下了不少功夫。
上图表示了yolo_v3整个yolo_body的结构，没有包括把输出解析整理成咱要的[box, class, score]。对于把输出张量包装成[box, class, score]那种形式，还需要写一些脚本，但这已经在神经网络结构之外了(我后面会详细解释这波操作)。
**为了让yolo_v3结构图更好理解，我对图1做一些补充解释：**
**DBL**: 如图1左下角所示，也就是代码中的Darknetconv2d_BN_Leaky，是yolo_v3的基本组件。就是卷积+BN+Leaky relu。对于v3来说，BN和leaky relu已经是和卷积层不可分离的部分了(最后一层卷积除外)，共同构成了最小组件。
**resn**：n代表数字，有res1，res2, … ,res8等等，表示这个res_block里含有多少个res_unit。这是yolo_v3的大组件，yolo_v3开始借鉴了ResNet的残差结构，使用这种结构可以让网络结构更深(从v2的darknet-19上升到v3的darknet-53，前者没有残差结构)。对于res_block的解释，可以在图1的右下角直观看到，其基本组件也是DBL。
**concat**：张量拼接。将darknet中间层和后面的某一层的上采样进行拼接。拼接的操作和残差层add的操作是不一样的，拼接会扩充张量的维度，而add只是直接相加不会导致张量维度的改变。

我们可以借鉴netron来分析网络层，整个yolo_v3_body包含252层，组成如下：
![layers](https://img-blog.csdn.net/20181009162100741?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

表0. yolo_v3_layers

根据表0可以得出，对于代码层面的layers数量一共有252层，包括add层23层(主要用于res_block的构成，每个res_unit需要一个add层，一共有1+2+8+8+4=23层)。除此之外，BN层和LeakyReLU层数量完全一样(72层)，在网络结构中的表现为：

每一层BN后面都会接一层LeakyReLU

。卷积层一共有75层，其中有72层后面都会接BN+LeakyReLU的组合构成基本组件DBL。看结构图，可以发现上采样和concat都有2次，和表格分析中对应上。每个res_block都会用上一个零填充，一共有5个res_block。

------

## 1. backbone

整个v3结构里面，是**没有池化层和全连接层**的。前向传播过程中，**张量的尺寸变换是通过改变卷积核的步长来实现的**，比如stride=(2, 2)，这就等于将图像边长缩小了一半(即面积缩小到原来的1/4)。在yolo_v2中，要经历5次缩小，会将特征图缩小到原输入尺寸的1/251/2^51/25，即1/32。输入为416x416，则输出为13x13(416/32=13)。
yolo_v3也和v2一样，backbone都会将输出特征图缩小到输入的1/32。所以，通常都要求输入图片是32的倍数。可以对比v2和v3的backbone看看：（DarkNet-19 与 DarkNet-53）
![img](https://img-blog.csdn.net/20180912153040110?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

图2. darknet-19 vs darknet-53

yolo_v2中对于前向过程中张量尺寸变换，都是通过

最大池化

来进行，一共有5次。而v3是通过卷积核

增大步长

来进行，也是5次。(darknet-53最后面有一个全局平均池化，在yolo-v3里面没有这一层，所以张量维度变化只考虑前面那5次)。

这也是416x416输入得到13x13输出的原因。从图2可以看出，darknet-19是不存在残差结构(resblock，从resnet上借鉴过来)的，和VGG是同类型的backbone(属于上一代CNN结构)，而darknet-53是可以和resnet-152正面刚的backbone，看下表：

![这里写图片描述](https://img-blog.csdn.net/20180912153712370?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

表1. backbone对比图

从上表也可以看出，darknet-19在速度上仍然占据很大的优势。其实在其他细节也可以看出(比如bounding box prior采用k=9)，

yolo_v3并没有那么追求速度，而是在保证实时性(fps>60)的基础上追求performance

。不过前面也说了，你要想更快，还有一个

tiny-darknet

作为backbone可以替代darknet-53，在官方代码里用一行代码就可以实现切换backbone。搭用tiny-darknet的yolo，也就是tiny-yolo在轻量和高速两个特点上，显然是state of the art级别，tiny-darknet是和squeezeNet正面刚的网络，详情可以看下表：

 



表2. 轻量级对比图

所以，有了yolo v3，就真的用不着yolo v2了，更用不着yolo v1了

。这也是[yolo官方网站](https://pjreddie.com/darknet/)，在v3出来以后，就没提供v1和v2代码下载链接的原因了。

------

## 2. Output

对于图1而言，更值得关注的是输出张量：
![img](https://img-blog.csdn.net/20180912160208680?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
yolo v3输出了3个不同尺度的feature map，如上图所示的y1, y2, y3。这也是v3论文中提到的为数不多的改进点：**predictions across scales**
这个借鉴了FPN(feature pyramid networks)，采用多尺度来对不同size的目标进行检测，越精细的grid cell就可以检测出越精细的物体。
y1,y2和y3的深度都是255，边长的规律是13:26:52
对于COCO类别而言，有80个种类，所以每个box应该对每个种类都输出一个概率。
yolo v3设定的是每个网格单元预测3个box，所以每个box需要有(x, y, w, h, confidence)五个基本参数，然后还要有80个类别的概率。所以3*(5 + 80) = 255。这个255就是这么来的。（还记得yolo v1的输出张量吗？ 7x7x30，只能识别20类物体，而且每个cell只能预测2个box，和v3比起来就像老人机和iphoneX一样）
v3用上采样的方法来实现这种多尺度的feature map，可以结合图1和图2右边来看，图1中concat连接的两个张量是具有一样尺度的(两处拼接分别是26x26尺度拼接和52x52尺度拼接，通过(2, 2)上采样来保证concat拼接的张量尺度相同)。作者并没有像SSD那样直接采用backbone中间层的处理结果作为feature map的输出，而是和后面网络层的上采样结果进行一个拼接之后的处理结果作为feature map。为什么这么做呢？ 我感觉是有点玄学在里面，一方面避免和其他算法做法重合，另一方面这也许是试验之后并且结果证明更好的选择，再者有可能就是因为这么做比较节省模型size的。这点的数学原理不用去管，知道作者是这么做的就对了。

------

## 3. some tricks

上文把yolo_v3的结构讨论了一下，下文将对yolo v3的若干细节进行剖析。
**Bounding Box Prediction**
b-box预测手段是v3论文中提到的又一个亮点。先回忆一下v2的b-box预测：想借鉴faster R-CNN [RPN](https://blog.csdn.net/leviopku/article/details/80875368)中的anchor机制，但不屑于手动设定anchor prior(模板框)，于是用维度聚类的方法来确定anchor box prior(模板框)，最后发现聚类之后确定的prior在k=5也能够又不错的表现，于是就选用k=5。后来呢，v2又嫌弃anchor机制线性回归的不稳定性(因为回归的offset可以使box偏移到图片的任何地方)，所以v2最后选用了自己的方法：**直接预测相对位置**。预测出b-box中心点相对于网格单元左上角的相对坐标。
![img](https://img-blog.csdn.net/20180912172007833?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)

公式1

![这里写图片描述](https://img-blog.csdn.net/2018091217215138?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2xldmlvcGt1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70)
yolo v2直接predict出(*t**x*t_x*t**x*​, *t**y*t_y*t**y*​, *t**w*t_w*t**w*​, *t**h*t_h*t**h*​, *t**o*t_o*t**o*​)，并不像[RPN](https://blog.csdn.net/leviopku/article/details/80875368)中anchor机制那样去遍历每一个pixel。可以从上面的公式看出，b-box的位置大小和confidence都可以通过(*t**x*t_x*t**x*​, *t**y*t_y*t**y*​, *t**w*t_w*t**w*​, *t**h*t_h*t**h*​, *t**o*t_o*t**o*​)计算得来，v2相当直接predict出了b-box的位置大小和confidence。box宽和高的预测是受prior影响的，对于v2而言，b-box prior数为5，在论文中并没有说明抛弃anchor机制之后是否抛弃了聚类得到的prior(没看代码，所以我不能确定)，如果prior数继续为5，那么v2需要对不同prior预测出*t**w*t_w*t**w*​和*t**h*t_h*t**h*​。
对于v3而言，在prior这里的处理有明确解释：选用的b-box priors 的k=9，对于tiny-yolo的话，k=6。priors都是在数据集上聚类得来的，有确定的数值，如下:

```
10,13,  16,30,  33,23,  30,61,  62,45,  59,119,  116,90,  156,198,  373,326
1
```

每个anchor prior(名字叫anchor prior，但并不是用anchor机制)就是两个数字组成的，一个代表高度另一个代表宽度。
v3对b-box进行预测的时候，采用了**logistic regression**。这一波操作sao得就像RPN中的线性回归调整b-box。v3每次对b-box进行predict时，输出和v2一样都是(*t**x*t_x*t**x*​, *t**y*t_y*t**y*​, *t**w*t_w*t**w*​, *t**h*t_h*t**h*​, *t**o*t_o*t**o*​)，然后通过公式1计算出绝对的(x, y, w, h, c)。
logistic回归用于对anchor包围的部分进行一个目标性评分(objectness score)，即这块位置是目标的可能性有多大。这一步是在predict之前进行的，可以去掉不必要anchor，可以减少计算量。作者在论文种的描述如下：

> If the bounding box prior is not the best but does overlap a ground truth object by more than some threshold we ignore the prediction, following[17]. We use the threshold of 0.5. Unlike [17] our system only assigns one bounding box prior for each ground truth object.

如果模板框不是最佳的即使它超过我们设定的阈值，我们还是不会对它进行predict。
不同于faster R-CNN的是，yolo_v3只会对1个prior进行操作，也就是那个最佳prior。而logistic回归就是用来从9个anchor priors中找到objectness score(目标存在可能性得分)最高的那一个。logistic回归就是用曲线对prior相对于 objectness score映射关系的线性建模。
**疑问解答和说明：**

```
在评论里有同学问我关于输出的问题，看来我在这里没有说的很清楚。了解v3输出的输出是至关重要的。

第一点， 9个anchor会被三个输出张量平分的。根据大中小三种size各自取自己的anchor。

第二点，每个输出y在每个自己的网格都会输出3个预测框，这3个框是9除以3得到的，这是作者设置
的，我们可以从输出张量的维度来看，13x13x255。255是怎么来的呢，3*(5+80)。80表示80个种类，5表
示位置信息和置信度，3表示要输出3个prediction。在代码上来看，3*(5+80)中的3是直接由
num_anchors//3得到的。

第三点，作者使用了logistic回归来对每个anchor包围的内容进行了一个目标性评分(objectness score)。
根据目标性评分来选择anchor prior进行predict，而不是所有anchor prior都会有输出。
1234567891011
```

------

## loss function

对掌握Yolo来讲，loss function不可谓不重要。在v3的论文里没有明确提所用的损失函数，确切地说，yolo系列论文里面只有[yolo v1](https://blog.csdn.net/leviopku/article/details/82588059)明确提了损失函数的公式。对于yolo这样一种讨喜的目标检测算法，就连损失函数都非常讨喜。在v1中使用了一种叫sum-square error的损失计算方法，就是简单的差方相加而已。想详细了解的可以看我关于v1解释的[博文](https://blog.csdn.net/leviopku/article/details/82588059)。我们知道，在目标检测任务里，有几个关键信息是需要确定的:(*x*,*y*),(*w*,*h*),*c**l**a**s**s*,*c**o**n**f**i**d**e**n**c**e*(x, y), (w, h), class, confidence(*x*,*y*),(*w*,*h*),*c**l**a**s**s*,*c**o**n**f**i**d**e**n**c**e*
根据关键信息的特点可以分为上述四类，损失函数应该由各自特点确定。最后加到一起就可以组成最终的loss_function了，也就是一个loss_function搞定端到端的训练。可以从代码分析出v3的损失函数，同样也是对以上四类，不过相比于v1中简单的总方误差，还是有一些调整的：

```python
xy_loss = object_mask * box_loss_scale * K.binary_crossentropy(raw_true_xy, raw_pred[..., 0:2],
                                                                       from_logits=True)
wh_loss = object_mask * box_loss_scale * 0.5 * K.square(raw_true_wh - raw_pred[..., 2:4])
confidence_loss = object_mask * K.binary_crossentropy(object_mask, raw_pred[..., 4:5], from_logits=True) + \
                          (1 - object_mask) * K.binary_crossentropy(object_mask, raw_pred[..., 4:5],
                                                                    from_logits=True) * ignore_mask
class_loss = object_mask * K.binary_crossentropy(true_class_probs, raw_pred[..., 5:], from_logits=True)

xy_loss = K.sum(xy_loss) / mf
wh_loss = K.sum(wh_loss) / mf
confidence_loss = K.sum(confidence_loss) / mf
class_loss = K.sum(class_loss) / mf
loss += xy_loss + wh_loss + confidence_loss + class_loss
12345678910111213
```

以上是一段keras框架描述的yolo v3 的loss_function代码。忽略恒定系数不看，可以从上述代码看出：除了w, h的损失函数依然采用总方误差之外，其他部分的损失函数用的是二值交叉熵。最后加到一起。那么这个binary_crossentropy又是个什么玩意儿呢？就是一个最简单的交叉熵而已，一般用于二分类，这里的两种二分类类别可以理解为"对和不对"这两种。关于binary_crossentropy的公式详情可参考博文《[常见的损失函数](https://blog.csdn.net/legalhighhigh/article/details/81409551)》。

------

## 总结

v3毫无疑问现在成为了工程界首选的检测算法之一了，结构清晰，实时性好。这是我十分安利的目标检测算法，更值得赞扬的是，yolo_v3给了近乎白痴的复现教程，这种气量在顶层算法研究者中并不常见。**你可以很快的用上v3，但你不能很快地懂v3**，我花了近一个月的时间才对v3有一个清晰的了解(可能是我悟性不够哈哈哈)。在算法学习的过程中，去一些浮躁，好好理解算法比只会用算法难得很多。





# 代码

## darknet.py

```python

#darknet.py 文件详解


from __future__ import division
 
import torch 
import torch.nn as nn
import torch.nn.functional as F 
from torch.autograd import Variable
import numpy as np
from util import * 
 
 
def get_test_input():
    img = cv2.imread("dog-cycle-car.png")
    img = cv2.resize(img, (416,416))          #Resize to the input dimension
    img_ =  img[:,:,::-1].transpose((2,0,1))  #img是【h,w,channel】，这里的img[:,:,::-1]是将第三个维度channel从opencv的BGR转化为pytorch的RGB，然后transpose((2,0,1))的意思是将[height,width,channel]->[channel,height,width]
    img_ = img_[np.newaxis,:,:,:]/255.0       #Add a channel at 0 (for batch) | Normalise
    img_ = torch.from_numpy(img_).float()     #Convert to float
    img_ = Variable(img_)                     # Convert to Variable
    return img_
 
def parse_cfg(cfgfile):
    """
    输入: 配置文件路径
    返回值: 列表对象,其中每一个元素为一个字典类型对应于一个要建立的神经网络模块（层）
    
    """
    # 加载文件并过滤掉文本中多余内容
    file = open(cfgfile, 'r')
    lines = file.read().split('\n')                        # store the lines in a list等价于readlines
    lines = [x for x in lines if len(x) > 0]               # 去掉空行
    lines = [x for x in lines if x[0] != '#']              # 去掉以#开头的注释行
    lines = [x.rstrip().lstrip() for x in lines]           # 去掉左右两边的空格(rstricp是去掉右边的空格，lstrip是去掉左边的空格)
    # cfg文件中的每个块用[]括起来最后组成一个列表，一个block存储一个块的内容，即每个层用一个字典block存储。
    block = {}
    blocks = []
    
    for line in lines:
        if line[0] == "[":               # 这是cfg文件中一个层(块)的开始           
            if len(block) != 0:          # 如果块内已经存了信息, 说明是上一个块的信息还没有保存
                blocks.append(block)     # 那么这个块（字典）加入到blocks列表中去
                block = {}               # 覆盖掉已存储的block,新建一个空白块存储描述下一个块的信息(block是字典)
            block["type"] = line[1:-1].rstrip()  # 把cfg的[]中的块名作为键type的值   
        else:
            key,value = line.split("=") #按等号分割
            block[key.rstrip()] = value.lstrip()#左边是key(去掉右空格)，右边是value(去掉左空格)，形成一个block字典的键值对
    blocks.append(block) # 退出循环，将最后一个未加入的block加进去
    # print('\n\n'.join([repr(x) for x in blocks]))
    return blocks
 
# 配置文件定义了6种不同type
# 'net': 相当于超参数,网络全局配置的相关参数
# {'convolutional', 'net', 'route', 'shortcut', 'upsample', 'yolo'}
 
# cfg = parse_cfg("cfg/yolov3.cfg")
# print(cfg)
 
 
 
class EmptyLayer(nn.Module):
    """
    为shortcut layer / route layer 准备, 具体功能不在此实现，在Darknet类的forward函数中有体现
    """
    def __init__(self):
        super(EmptyLayer, self).__init__()
        
 
class DetectionLayer(nn.Module):
    '''yolo 检测层的具体实现, 在特征图上使用锚点预测目标区域和类别, 功能函数在predict_transform中'''
    def __init__(self, anchors):
        super(DetectionLayer, self).__init__()
        self.anchors = anchors
 
 
 
def create_modules(blocks):
    net_info = blocks[0]     # blocks[0]存储了cfg中[net]的信息，它是一个字典，获取网络输入和预处理相关信息    
    module_list = nn.ModuleList() # module_list用于存储每个block,每个block对应cfg文件中一个块，类似[convolutional]里面就对应一个卷积块
    prev_filters = 3   #初始值对应于输入数据3通道，用来存储我们需要持续追踪被应用卷积层的卷积核数量（上一层的卷积核数量（或特征图深度））
    output_filters = []   #我们不仅需要追踪前一层的卷积核数量，还需要追踪之前每个层。随着不断地迭代，我们将每个模块的输出卷积核数量添加到 output_filters 列表上。
    
    for index, x in enumerate(blocks[1:]): #这里，我们迭代block[1:] 而不是blocks，因为blocks的第一个元素是一个net块，它不属于前向传播。
        module = nn.Sequential()# 这里每个块用nn.sequential()创建为了一个module,一个module有多个层
    
        #check the type of block
        #create a new module for the block
        #append to module_list
        
        if (x["type"] == "convolutional"):
            ''' 1. 卷积层 '''
            # 获取激活函数/批归一化/卷积层参数（通过字典的键获取值）
            activation = x["activation"]
            try:
                batch_normalize = int(x["batch_normalize"])
                bias = False#卷积层后接BN就不需要bias
            except:
                batch_normalize = 0
                bias = True #卷积层后无BN层就需要bias
        
            filters= int(x["filters"])
            padding = int(x["pad"])
            kernel_size = int(x["size"])
            stride = int(x["stride"])
        
            if padding:
                pad = (kernel_size - 1) // 2
            else:
                pad = 0
        
            # 开始创建并添加相应层
            # Add the convolutional layer
            # nn.Conv2d(self, in_channels, out_channels, kernel_size, stride=1, padding=0, bias=True    - padding - 每一维补零的数量
            conv = nn.Conv2d(prev_filters, filters, kernel_size, stride, pad, bias = bias)
            module.add_module("conv_{0}".format(index), conv)
        
            #Add the Batch Norm Layer
            if batch_normalize:
                bn = nn.BatchNorm2d(filters)
                module.add_module("batch_norm_{0}".format(index), bn)
        
            #Check the activation. 
            #It is either Linear or a Leaky ReLU for YOLO
            # 给定参数负轴系数0.1
            if activation == "leaky":
                activn = nn.LeakyReLU(0.1, inplace = True)
                module.add_module("leaky_{0}".format(index), activn)
                   
        elif (x["type"] == "upsample"):
            '''
            2. upsampling layer
            没有使用 Bilinear2dUpsampling
            实际使用的为最近邻插值    上采样
            '''
            stride = int(x["stride"])#这个stride在cfg中就是2，所以下面的scale_factor写2或者stride是等价的
            upsample = nn.Upsample(scale_factor = 2, mode = "nearest")
            module.add_module("upsample_{}".format(index), upsample)
                
        # route layer -> Empty layer
        # route层的作用：当layer取值为正时，输出这个正数对应的层的特征，如果layer取值为负数，输出route层向后退layer层对应层的特征 
        #路由层需要一些解释，它的参数 layers 有一个或两个值。当只有一个值时，它输出这一层通过该值索引的特征图。在我们的实验中设置为了-4，所以层级将输出路由层之前第四个层的特征图。

		#当层级有两个值时，它将返回由这两个值索引的拼接特征图。在我们的实验中为-1 和 61，因此该层级将输出从前一层级（-1）到第 61 层的特征图，并将它们按深度拼接。
        elif (x["type"] == "route"):
            x["layers"] = x["layers"].split(',')
            #Start  of a route
            start = int(x["layers"][0])
            #end, if there exists one.
            try:
                end = int(x["layers"][1])
            except:
                end = 0
            #Positive anotation: 正值
            if start > 0: 
                start = start - index            
            if end > 0:# 若end>0，由于end= end - index，再执行index + end输出的还是第end层的特征
                end = end - index
            route = EmptyLayer()
            module.add_module("route_{0}".format(index), route)
            if end < 0: #若end<0，则end还是end，输出index+end(而end<0)故index向后退end层的特征。
                filters = output_filters[index + start] + output_filters[index + end]
            else: #如果没有第二个参数，end=0，则对应下面的公式，此时若start>0，由于start = start - index，再执行index + start输出的还是第start层的特征;若start<0，则start还是start，输出index+start(而start<0)故index向后退start层的特征。
                filters= output_filters[index + start]
    
        #shortcut corresponds to skip connection
        #跳过连接与残差网络中使用的结构相似，参数 from 为-3 表示捷径层的输出会通过将之前层的和之前第三个层的输出的特征图与模块的输入相加而得出。
        elif x["type"] == "shortcut":
            shortcut = EmptyLayer() #使用空的层，因为它还要执行一个非常简单的操作（加）。没必要更新 filters 变量,因为它只是将前一层的特征图添加到后面的层上而已。
            module.add_module("shortcut_{}".format(index), shortcut)
            
        #Yolo is the detection layer
        elif x["type"] == "yolo":
            mask = x["mask"].split(",")
            mask = [int(x) for x in mask]
    
            anchors = x["anchors"].split(",")
            anchors = [int(a) for a in anchors]
            #变成两兩一对的元组
            anchors = [(anchors[i], anchors[i+1]) for i in range(0, len(anchors),2)]
            anchors = [anchors[i] for i in mask]
    		#我们定义一个新的层 DetectionLayer 保存用于检测边界框的锚点。
            detection = DetectionLayer(anchors)# 锚点,检测,位置回归,分类，这个类见predict_transform中
            module.add_module("Detection_{}".format(index), detection)
                              
        module_list.append(module)
        prev_filters = filters
        output_filters.append(filters)
    #blocks[0]存储了cfg中[net]的信息
    return (net_info, module_list)
 
class Darknet(nn.Module):
    def __init__(self, cfgfile):
        super(Darknet, self).__init__()
        self.blocks = parse_cfg(cfgfile) #调用parse_cfg函数
        self.net_info, self.module_list = create_modules(self.blocks)#调用create_modules函数
     #forward 主要有两个目的。一，计算输出；二，尽早处理的方式转换输出检测特征图（例如转换之后，这些不同尺度的检测图就能够串联，不然会因为不同维度不可能实现串联）。
    def forward(self, x, CUDA):
        #forward 函数有三个参数：self、输入 x 和 CUDA（如果是 true，则使用 GPU 来加速前向传播）。
        modules = self.blocks[1:] # 除了net块之外的所有，forward这里用的是blocks列表中的各个block块字典
        outputs = {}   #We cache the outputs for the route layer
        
        write = 0#write表示我们是否遇到第一个检测。write=0，则收集器尚未初始化，write=1，则收集器已经初始化，我们只需要将检测图与收集器级联起来即可。
        for i, module in enumerate(modules):        
            module_type = (module["type"])
            
            if module_type == "convolutional" or module_type == "upsample":
                x = self.module_list[i](x)
    
            elif module_type == "route":
                layers = module["layers"]
                layers = [int(a) for a in layers]
    
                if (layers[0]) > 0:
                    layers[0] = layers[0] - i
                # 如果只有一层时。从前面的if (layers[0]) > 0:语句中可知，如果layer[0]>0，则输出的就是当前layer[0]这一层的特征,如果layer[0]<0，输出就是从route层(第i层)向后退layer[0]层那一层得到的特征 
                if len(layers) == 1:
                    x = outputs[i + (layers[0])]
                #第二个元素同理 
                else:
                    if (layers[1]) > 0:
                        layers[1] = layers[1] - i
    
                    map1 = outputs[i + layers[0]]
                    map2 = outputs[i + layers[1]]	
                    x = torch.cat((map1, map2), 1)#第二个参数设为 1,这是因为我们希望将特征图沿anchor数量的维度级联起来。
                
    
            elif  module_type == "shortcut":
                from_ = int(module["from"])
                x = outputs[i-1] + outputs[i+from_] # 求和运算，它只是将前一层的特征图添加到后面的层上而已
            
            elif module_type == 'yolo':        
                anchors = self.module_list[i][0].anchors
                #从net_info(实际就是blocks[0]，即[net])中输入维度
                inp_dim = int (self.net_info["height"])
        
                #Get the number of classes
                num_classes = int (module["classes"])
        
                #Transform 
                x = x.data # 这里得到的是预测的yolo层feature map
                # 在util.py中的predict_transform()函数利用x(是传入yolo层的feature map)，得到每个格子所对应的anchor最终得到的目标
                # 坐标与宽高，以及出现目标的得分与每种类别的得分。经过predict_transform变换后的x的维度是(batch_size, grid_size*grid_size*num_anchors, 5+类别数量)
                #batch , class ,宽高
                #将x由 n c w h _> n w*h*3 c
                x = predict_transform(x, inp_dim, anchors, num_classes, CUDA)
                 
                if not write:               #if no collector has been intialised. 因为一个空的tensor无法与一个有数据的tensor进行concatenate操作，
                    detections = x #所以detections的初始化在有预测值出来时才进行，
                    write = 1   #用write = 1标记，当后面的分数出来后，直接concatenate操作即可。
        
                else:  
                    '''
                    变换后x的维度是(batch_size, grid_size*grid_size*num_anchors, 5+类别数量)，这里是在维度1上进行concatenate，即按照
                    anchor数量的维度进行连接，对应教程part3中的Bounding Box attributes图的行进行连接。yolov3中有3个yolo层，所以
                    对于每个yolo层的输出先用predict_transform()变成每行为一个anchor对应的预测值的形式(不看batch_size这个维度，x剩下的
                    维度可以看成一个二维tensor)，这样3个yolo层的预测值按照每个方框对应的行的维度进行连接。得到了这张图处所有anchor的预测值，后面的NMS等操作可以一次完成
                    '''
                    detections = torch.cat((detections, x), 1)# 将在3个不同level的feature map上检测结果存储在 detections 里
        
            outputs[i] = x
        
        return detections
# blocks = parse_cfg('cfg/yolov3.cfg')
# x,y = create_modules(blocks)
# print(y)
 
    def load_weights(self, weightfile):
        #Open the weights file
        fp = open(weightfile, "rb")
    
        #The first 5 values are header information 
        # 1. Major version number
        # 2. Minor Version Number
        # 3. Subversion number 
        # 4,5. Images seen by the network (during training)
        header = np.fromfile(fp, dtype = np.int32, count = 5)# 这里读取first 5 values权重
        self.header = torch.from_numpy(header)
        self.seen = self.header[3]   
        
        weights = np.fromfile(fp, dtype = np.float32)#加载 np.ndarray 中的剩余权重，权重是以float32类型存储的
        
        ptr = 0#我们保留一个变量ptr来跟踪我们在权重数组中的位置。
        #进入循环，我们首先检查convolutional块是否为batch_normaliseTrue。基于此，我们加载权重。
        for i in range(len(self.module_list)):
            module_type = self.blocks[i + 1]["type"] # blocks中的第一个元素是网络参数和图像的描述，所以从blocks[1]开始读入
    
            #If module_type is convolutional load weights
            #Otherwise ignore.
            
            if module_type == "convolutional":
                model = self.module_list[i]
                try:
                    batch_normalize = int(self.blocks[i+1]["batch_normalize"]) # 当有bn层时，"batch_normalize"对应值为1
                except:
                    batch_normalize = 0
            
                conv = model[0]
                
                
                if (batch_normalize):
                    bn = model[1]
        
                    #Get the number of weights of Batch Norm Layer
                    num_bn_biases = bn.bias.numel()
        
                    #Load the weights
                    bn_biases = torch.from_numpy(weights[ptr:ptr + num_bn_biases])
                    ptr += num_bn_biases
        
                    bn_weights = torch.from_numpy(weights[ptr: ptr + num_bn_biases])
                    ptr  += num_bn_biases
        
                    bn_running_mean = torch.from_numpy(weights[ptr: ptr + num_bn_biases])
                    ptr  += num_bn_biases
        
                    bn_running_var = torch.from_numpy(weights[ptr: ptr + num_bn_biases])
                    ptr  += num_bn_biases
        
                    #Cast the loaded weights into dims of model weights. 
                    bn_biases = bn_biases.view_as(bn.bias.data)
                    bn_weights = bn_weights.view_as(bn.weight.data)
                    bn_running_mean = bn_running_mean.view_as(bn.running_mean)
                    bn_running_var = bn_running_var.view_as(bn.running_var)
        
                    #Copy the data to model 将从weights文件中得到的权重bn_biases复制到model中(bn.bias.data)
                    bn.bias.data.copy_(bn_biases)
                    bn.weight.data.copy_(bn_weights)
                    bn.running_mean.copy_(bn_running_mean)
                    bn.running_var.copy_(bn_running_var)
                
                else:#如果 batch_normalize 的检查结果不是 True，只需要加载卷积层的偏置项
                    #Number of biases
                    num_biases = conv.bias.numel()
                
                    #Load the weights
                    conv_biases = torch.from_numpy(weights[ptr: ptr + num_biases])
                    ptr = ptr + num_biases
                
                    #reshape the loaded weights according to the dims of the model weights
                    conv_biases = conv_biases.view_as(conv.bias.data)
                
                    #Finally copy the data
                    conv.bias.data.copy_(conv_biases)
                    
                #Let us load the weights for the Convolutional layers
                num_weights = conv.weight.numel()
                
                #Do the same as above for weights
                conv_weights = torch.from_numpy(weights[ptr:ptr+num_weights])
                ptr = ptr + num_weights
                
                conv_weights = conv_weights.view_as(conv.weight.data)
                conv.weight.data.copy_(conv_weights)


```



### 测试打印网络结构测试

```python
blocks = parse_cfg("cfg/yolov3.cfg") 
print(blocks)
print(create_modules(blocks))
```

### 测试前向传播

```python
model = Darknet("cfg/yolov3.cfg")
inp = get_test_input()
pred = model(inp, torch.cuda.is_available())
print (pred)
```

```python
tensor([[[ 15.1999,  15.1151, 124.1339,  ...,   0.5666,   0.5098,   0.4919],
         [ 14.4641,  16.1470, 183.7116,  ...,   0.5253,   0.4638,   0.5042],
         [ 15.7080,  15.4652, 373.1461,  ...,   0.4585,   0.4819,   0.5084],
         ...,
         [412.2068, 412.0437,   9.0147,  ...,   0.5168,   0.4769,   0.4773],
         [412.2354, 411.8904,  15.0341,  ...,   0.4977,   0.5203,   0.5010],
         [412.0429, 411.8109,  27.8348,  ...,   0.5499,   0.5057,   0.4733]]])
The shape of this tensor is 1 x 10647 x 85
#现在，我们的网络有随机权重，并且不会输出正确的类别。我们需要为网络加载权重文件，因此可以利用官方权重文件。
```



### 测试加权重的前向传播

```python
model = Darknet("cfg/yolov3.cfg")
model.load_weights("yolov3.weights")
inp = get_test_input()
pred = model(inp, torch.cuda.is_available())
np.set_printoptions(threshold=np.inf)   #这样就能使np的数组全部打印
print (pred.numpy()) 					#将tensor 转化为 np



'''
[[[8.54257488e+00 1.90151520e+01 1.11301834e+02 ... 1.73059851e-03
   1.38740113e-03 9.29847825e-04]
  [1.41049366e+01 1.88674183e+01 9.40142059e+01 ... 5.95010817e-04
   9.24709777e-04 1.30852161e-03]
  [2.11250744e+01 1.52692204e+01 3.57931763e+02 ... 8.36093165e-03
   5.10674715e-03 5.85615914e-03]
  ...
  [4.12679108e+02 4.10687134e+02 3.71572924e+00 ... 1.71854526e-06
   4.09553513e-06 6.58974614e-07]
  [4.11322937e+02 4.10231628e+02 8.03526020e+00 ... 1.39265730e-05
   3.22520718e-05 1.20764107e-05]
  [4.10762604e+02 4.13180725e+02 4.96349602e+01 ... 4.21740424e-06
   1.07937549e-05 1.81042815e-05]]]

'''
```























## util.py

```python
from __future__ import division
 
import torch 
import torch.nn as nn
import torch.nn.functional as F 
from torch.autograd import Variable
import numpy as np
import cv2 
 
def unique(tensor):#因为同一类别可能会有多个真实检测结果，所以我们使用unique函数来去除重复的元素，即一类只留下一个元素，达到获取任意给定图像中存在的类别的目的。
    tensor_np = tensor.cpu().numpy()
    unique_np = np.unique(tensor_np)#np.unique该函数是去除数组中的重复数字，并进行排序之后输出
    unique_tensor = torch.from_numpy(unique_np)
    # 复制数据
    tensor_res = tensor.new(unique_tensor.shape)# new(args, *kwargs) 构建[相同数据类型]的新Tensor
    tensor_res.copy_(unique_tensor)
    return tensor_res
 
 
def bbox_iou(box1, box2):
    """
    Returns the IoU of two bounding boxes 
    
    
    """
    #Get the coordinates of bounding boxes
    b1_x1, b1_y1, b1_x2, b1_y2 = box1[:,0], box1[:,1], box1[:,2], box1[:,3]
    b2_x1, b2_y1, b2_x2, b2_y2 = box2[:,0], box2[:,1], box2[:,2], box2[:,3]
    
    #get the corrdinates of the intersection rectangle
    inter_rect_x1 =  torch.max(b1_x1, b2_x1)
    inter_rect_y1 =  torch.max(b1_y1, b2_y1)
    inter_rect_x2 =  torch.min(b1_x2, b2_x2)
    inter_rect_y2 =  torch.min(b1_y2, b2_y2)
    
    #Intersection area
    # Intersection area  交集区域，这里没有对inter_area为负的情况进行判断，后面计算出来的IOU就可能是负的
    #将输入input张量每个元素的夹紧到区间 [min,max][min,max]，并返回结果到一个新张量。
    '''  
      | min, if x_i < min
y_i = | x_i, if min <= x_i <= max
      | max, if x_i > max
    '''
    inter_area = torch.clamp(inter_rect_x2 - inter_rect_x1 + 1, min=0) * torch.clamp(inter_rect_y2 - inter_rect_y1 + 1, min=0)
 
    #Union Area
    b1_area = (b1_x2 - b1_x1 + 1)*(b1_y2 - b1_y1 + 1)
    b2_area = (b2_x2 - b2_x1 + 1)*(b2_y2 - b2_y1 + 1)
    
    iou = inter_area / (b1_area + b2_area - inter_area)
    
    return iou
 
def predict_transform(prediction, inp_dim, anchors, num_classes, CUDA = True):
    """
    在特征图上进行多尺度预测, 在GRID每个位置都有三个不同尺度的锚点.predict_transform()利用一个scale得到的feature map预测得到的每个anchor的属性(x,y,w,h,s,s_cls1,s_cls2...),其中x,y,w,h
    是在网络输入图片坐标系下的值,s是方框含有目标的置信度得分，s_cls1,s_cls_2等是方框所含目标对应每类的概率。输入的feature map(prediction变 量) 维度为(batch_size, num_anchors*bbox_attrs, grid_size, grid_size)，类似于一个batch彩色图片BxCxHxW存储方式。参数见predict_transform()里面的变量。
   prediction = x   x >> 的尺度n c w h   
   并且将结果的维度变换成(batch_size, grid_size*grid_size*num_anchors, 5+类别数量)的tensor，同时得到每个方框在网络输入图片(416x416)坐标系下的(x,y,w,h)以及方框含有目标的得分以及每个类的得分。
   再来看下维度变换n,3*85,13,13的输入，如何变成n,13*13*3,85的输出。这样一转换，在第1维度上就可以torch.cat加26*26*3的结果和，52*52*3的结果。表示每一行的每一种anchor对应的85. n,3*85,13,13  _>  n,13*13*3,85.
    """
    batch_size = prediction.size(0)
    # stride表示的是整个网络的步长，等于图像原始尺寸与yolo层输入的feature mapr尺寸相除，因为输入图像是正方形，所以用高相除即可
    stride =  inp_dim // prediction.size(2)#416//13=32
    # feature map每条边格子的数量，416//32=13
    grid_size = inp_dim // stride
    # 一个方框属性个数，等于5+类别数量
    bbox_attrs = 5 + num_classes
    # anchors数量
    num_anchors = len(anchors)   
    # 输入的prediction维度为(batch_size, num_anchors * bbox_attrs, grid_size, grid_size)，类似于一个batch彩色图片BxCxHxW
    #n,3*85,13,13 _> n,3*85,13*13
    # 存储方式，将它的维度变换成(batch_size, bbox_attrs*num_anchors, grid_size*grid_size)
    prediction = prediction.view(batch_size, bbox_attrs*num_anchors, grid_size*grid_size)
    #contiguous：view只能用在contiguous的variable上。如果在view之前用了transpose, permute等，需要用contiguous()来返回一个contiguous copy。
    #n,3*85,13*13 _> n,13*13,3*85
    prediction = prediction.transpose(1,2).contiguous()
    # 将prediction维度转换成(batch_size, grid_size*grid_size*num_anchors, bbox_attrs)。不看batch_size，
    # (grid_size*grid_size*num_anchors, bbox_attrs)相当于将所有anchor按行排列，即一行对应一个anchor属性，此时的属性仍然是feature map得到的值
    # n,13*13,3*85 _>  n,13*13*3,85
    prediction = prediction.view(batch_size, grid_size*grid_size*num_anchors, bbox_attrs)
    # 锚点的维度与net块的height和width属性一致。这些属性描述了输入图像的维度，比feature map的规模大（二者之商即是步幅）。因此，我们必须使用stride分割锚点。
    #变换后的anchors是相对于最终的feature map的尺寸
    anchors = [(a[0]/stride, a[1]/stride) for a in anchors]
 
    #Sigmoid the tX, tY. and object confidencce.tx与ty为预测的坐标偏移值
    prediction[:,:,0] = torch.sigmoid(prediction[:,:,0])
    prediction[:,:,1] = torch.sigmoid(prediction[:,:,1])
    prediction[:,:,4] = torch.sigmoid(prediction[:,:,4])
    
    #这里生成了每个格子的左上角坐标，生成的坐标为grid x grid的二维数组，a，b分别对应这个二维矩阵的x,y坐标的数组，a,b的维度与grid维度一样。每个grid cell的尺寸均为1，故grid范围是[0,12]（假如当前的特征图13*13）
    grid = np.arange(grid_size)
    a,b = np.meshgrid(grid, grid)
    #x_offset即cx,y_offset即cy，表示当前cell左上角坐标
    x_offset = torch.FloatTensor(a).view(-1,1)#view是reshape功能，-1表示自适应
    y_offset = torch.FloatTensor(b).view(-1,1)
 
    if CUDA:
        x_offset = x_offset.cuda()
        y_offset = y_offset.cuda()
    #这里的x_y_offset对应的是最终的feature map中每个格子的左上角坐标，比如有13个格子，刚x_y_offset的坐标就对应为(0,0),(0,1)…(12,12) .view(-1, 2)将tensor变成两列，unsqueeze(0)在0维上添加了一维。
    '''tensor([[[ 0.,  0.,  0.,  0.,  0.,  0.],
         [ 1.,  0.,  1.,  0.,  1.,  0.],
         [ 2.,  0.,  2.,  0.,  2.,  0.],
         ...,
         [10., 12., 10., 12., 10., 12.],
         [11., 12., 11., 12., 11., 12.],
         [12., 12., 12., 12., 12., 12.]]])
'''
    '''
    tensor([[[ 0.,  0.],
         [ 0.,  0.],
         [ 0.,  0.],
         ...,
         [12., 12.],
         [12., 12.],
         [12., 12.]]])
	'''
    x_y_offset = torch.cat((x_offset, y_offset), 1).repeat(1,num_anchors).view(-1,2).unsqueeze(0)
 
    prediction[:,:,:2] += x_y_offset#bx=sigmoid(tx)+cx,by=sigmoid(ty)+cy
 
   
    anchors = torch.FloatTensor(anchors)
 
    if CUDA:
        #ancher 虽然有9对，但是跟据cfg文件中的mask只取出来3对，这个问题困惑了我好久。哇
        anchors = anchors.cuda()
    # 这里的anchors本来是一个长度为6的list(三个anchors每个2个坐标)，然后在0维上(行)进行了grid_size*grid_size个复制，在1维(列)上
    # 一次复制(没有变化)，即对每个格子都得到三个anchor。Unsqueeze(0)的作用是在数组上添加一维，这里是在第0维上添加的。添加grid_size是为了之后的公式bw=pw×e^tw的tw。
    '''
    tensor([[[10., 13.],
         [16., 30.],
         [33., 23.],
         ...,
         [10., 13.],
         [16., 30.],
         [33., 23.]]]) torch.Size([1, 507, 2])

    '''
    anchors = anchors.repeat(grid_size*grid_size, 1).unsqueeze(0)
    #对网络预测得到的矩形框的宽高的偏差值进行指数计算，然后乘以anchors里面对应的宽高(这里的anchors里面的宽高是对应最终的feature map尺寸grid_size)，
    # 得到目标的方框的宽高，这里得到的宽高是相对于在feature map的尺寸
    prediction[:,:,2:4] = torch.exp(prediction[:,:,2:4])*anchors#公式bw=pw×e^tw及bh=ph×e^th，pw为anchorbox的长度
    # 这里得到每个anchor中每个类别的得分。将网络预测的每个得分用sigmoid()函数计算得到
    prediction[:,:,5: 5 + num_classes] = torch.sigmoid((prediction[:,:, 5 : 5 + num_classes]))
 
    prediction[:,:,:4] *= stride#将相对于最终feature map的方框坐标和尺寸映射回输入网络图片(416x416)，即将方框的坐标乘以网络的stride即可
    
    return prediction
 
 
 
    '''
    必须使我们的输出满足 objectness 分数阈值和非极大值抑制（NMS），以得到后文所提到的「真实」检测结果。要做到这一点就要用 write_results函数。
    函数的输入为预测结果、置信度（objectness 分数阈值）、num_classes（我们这里是 80）和 nms_conf（NMS IoU 阈值）。
    write_results()首先将网络输出方框属性(x,y,w,h)转换为在网络输入图片(416x416)坐标系中，方框左上角与右下角坐标(x1,y1,x2,y2)，以方便NMS操作。
    然后将方框含有目标得分低于阈值的方框去掉，提取得分最高的那个类的得分max_conf，同时返回这个类对应的序号max_conf_score,
    然后进行NMS操作。最终每个方框的属性为(ind,x1,y1,x2,y2,s,s_cls,index_cls)，ind 是这个方框所属图片在这个batch中的序号，
    x1,y1是在网络输入图片(416x416)坐标系中，方框左上角的坐标；x2,y2是在网络输入图片(416x416)坐标系中，方框右下角的坐标。
    s是这个方框含有目标的得分,s_cls是这个方框中所含目标最有可能的类别的概率得分，index_cls是s_cls对应的这个类别所对应的序号.
    '''
def write_results(prediction, confidence, num_classes, nms_conf = 0.4):
    # confidence: 输入的预测shape=(1,10647, 85)。conf_mask: shape=(1,10647) => 增加一维度之后 (1, 10647, 1)
    conf_mask = (prediction[:,:,4] > confidence).float().unsqueeze(2)#我们的预测张量包含有关Bx10647边界框的信息。对于含有目标的得分小于confidence的每个方框，它对应的含有目标的得分将变成0,即conf_mask中对应元素为0.而保留预测结果中置信度大于给定阈值的部分prediction的conf_mask
    #经过尝试原来，（prediction[:,:,4] > confidence）会直接返回一个二维的张量，内涵1,0,经过unsqueeze之后升维得到类似如下结果
    """
    tensor([[[1.],
         [0.],
         [0.],
         [0.],
         [1.],
         [1.]]])
    """
    prediction = prediction*conf_mask # 小于置信度的条目值全为0, 剩下部分不变。conf_mask中含有目标的得分小于confidence的方框所对应的含有目标的得分为0，
    #根据numpy的广播原理，它会扩展成与prediction维度一样的tensor，所以含有目标的得分小于confidence的方框所有的属性都会变为0，故如果没有检测任何有效目标,则返回值为0
   
    '''
    保留预测结果中置信度大于阈值的bbox
    下面开始为nms准备
    '''
 
    # prediction的前五个数据分别表示 (Cx, Cy, w, h, score)，这里创建一个新的数组，大小与predicton的大小相同   
    box_corner = prediction.new(prediction.shape)
    '''
    我们可以将我们的框的 (中心 x, 中心 y, 高度, 宽度) 属性转换成 (左上角 x, 左上角 y, 右下角 x, 右下角 y)
    这样做用每个框的两个对角坐标能更轻松地计算两个框的 IoU
    '''
    box_corner[:,:,0] = (prediction[:,:,0] - prediction[:,:,2]/2)# x1 = Cx - w/2
    box_corner[:,:,1] = (prediction[:,:,1] - prediction[:,:,3]/2)# y1 = Cy - h/2
    box_corner[:,:,2] = (prediction[:,:,0] + prediction[:,:,2]/2)# x2 = Cx + w/2 
    box_corner[:,:,3] = (prediction[:,:,1] + prediction[:,:,3]/2)# y2 = Cy + h/2
    prediction[:,:,:4] = box_corner[:,:,:4]# 计算后的新坐标复制回去
    
    batch_size = prediction.size(0)# 第0个维度是batch_size
    # output = prediction.new(1, prediction.size(2)+1) # shape=(1,85+1)
    write = False # 拼接结果到output中最后返回
    
    #对每一张图片得分的预测值进行NMS操作，因为每张图片的目标数量不一样，所以有效得分的方框的数量不一样，没法将几张图片同时处理，因此一次只能完成一张图的置信度阈值的设置和NMS,不能将所涉及的操作向量化.
    #所以必须在预测的第一个维度上（batch数量）上遍历每张图片，将得分低于一定分数的去掉，对剩下的方框进行进行NMS
    for ind in range(batch_size):
        image_pred = prediction[ind]          # 选择此batch中第ind个图像的预测结果,image_pred对应一张图片中所有方框的坐标(x1,y1,x2,y2)以及得分，是一个二维tensor 维度为10647x85
      
        # 最大值索引, 最大值, 按照dim=1 方向计算
        max_conf, max_conf_score = torch.max(image_pred[:,5:5+ num_classes], 1)#我们只关心有最大值的类别分数，prediction[:, 5:]表示每一分类的分数,返回每一行中所有类别的得分最高的那个类的得分max_conf，同时返回这个类对应的序号max_conf_score
        # 维度扩展max_conf: shape=(10647->15) => (10647->15,1)添加一个列的维度，max_conf变成二维tensor，尺寸为10647x1
        max_conf = max_conf.float().unsqueeze(1)
        max_conf_score = max_conf_score.float().unsqueeze(1)
        seq = (image_pred[:,:5], max_conf, max_conf_score)#我们移除了每一行的这 80 个类别分数，只保留bbox4个坐标以及objectnness分数，转而增加了有最大值的类别分数及索引。
        #将每个方框的(x1,y1,x2,y2,s)与得分最高的这个类的分数s_cls(max_conf)和对应类的序号index_cls(max_conf_score)在列维度上连接起来，
        # 即将10647x5,10647x1,10647x1三个tensor 在列维度进行concatenate操作，得到一个10647x7的tensor,(x1,y1,x2,y2,s,s_cls,index_cls)。
        image_pred = torch.cat(seq, 1)# shape=(10647, 5+1+1=7)
        #image_pred[:,4]是长度为10647的一维tensor,维度为4的列是置信度分数。假设有15个框含有目标的得分非0，返回15x1的tensor
        non_zero_ind =  (torch.nonzero(image_pred[:,4]))#torch.nonzero返回的是索引，会让non_zero_ind是个2维tensor
        try:# try-except模块的目的是处理无检测结果的情况.non_zero_ind.squeeze()将15x1的non_zero_ind去掉维度为1的维度，变成长度为15的一维tensor，相当于一个列向量，
            # image_pred[non_zero_ind.squeeze(),:]是在image_pred中找到non_zero_ind中非0目标得分的行的所有元素(image_pred维度
            # 是10647x7，找到其中的15行)， 再用view(-1,7)将它变为15x7的tensor，用view()确保第二个维度必须是7.
            image_pred_ = image_pred[non_zero_ind.squeeze(),:].view(-1,7)
        except:
            continue
        
        if image_pred_.shape[0] == 0:#当没有检测到时目标时，我们使用 continue 来跳过对本图像的循环，即进行下一次循环。
            continue             
  
         # 获取当前图像检测结果中出现的所有类别
        img_classes = unique(image_pred_[:,-1])  #pred_[:,-1]是一个15x7的tensor，最后一列保存的是每个框里面物体的类别，-1表示取最后一列。
        #用unique()除去重复的元素，即一类只留下一个元素，假设这里最后只剩下了3个元素，即只有3类物体。
        
        #按照类别执行 NMS
        
        for cls in img_classes:
            #一旦我们进入循环，我们要做的第一件事就是提取特定类别（用变量 cls 表示）的检测结果,分离检测结果中属于当前类的数据 -1: index_cls, -2: s_cls
            '''
            本句是将image_pred_中属于cls类的预测值保持不变，其余的全部变成0。image_pred_[:,-1] == cls，返回一个与image_pred_
            行数一样的一维tensor，这里长度为15.当image_pred_中的最后一个元素(物体类别索引)等于第cls类时，返回的tensor对应元素为1，
            否则为0. 它与image_pred_相乘时，先扩展为15x7的tensor(似乎这里还没有变成15x7的tensor)，为0元素一行全部为0，再与
            image_pred_相乘，属于cls这类的方框对应预测元素不变，其它类的为0.unsqueeze(1)添加了列这一维，变成15x7的二维tensor。
            '''
            cls_mask = image_pred_*(image_pred_[:,-1] == cls).float().unsqueeze(1) 
            class_mask_ind = torch.nonzero(cls_mask[:,-2]).squeeze() #cls_mask[:,-2]为cls_mask倒数第二列,是物体类别分数。
#cls_mask本身为15x7，cls_mask[:,-2]将cls_mask的倒数第二列取出来，此时是1维tensor，torch.nonzero(cls_mask[:,-2])得到的是非零元素的索引，
#将返回一个二维tensor，这里是4x2，再用squeeze()去掉长度为1的维度(这里是第二维)，得到一维tensor(相当于一列)。
            image_pred_class = image_pred_[class_mask_ind].view(-1,7) #从prediction中取出属于cls类别的所有结果，为下一步的nms的输入.
#找到image_pred_中对应cls类的所有方框的预测值，并转换为二维张量。这里4x7。image_pred_[class_mask_ind]本身得到的数据就是4x7，view(-1,7)是为了确保第二维为7
            ''' 到此步 prediction_class 已经存在了我们需要进行非极大值抑制的数据 '''
            # 开始 nms
            # 按照score排序, 由大到小
            # 最大值最上面            
            
            conf_sort_index = torch.sort(image_pred_class[:,4], descending = True )[1]# # 这里的sort()将返回两个tensor，第一个是每个框含有有目标的分数由低到高排列，第二个是现在由高到底的tensor中每个元素在原来的序号。[0]是排序结果, [1]是排序结果的索引
            image_pred_class = image_pred_class[conf_sort_index]#根据排序后的索引对应出的bbox的坐标与分数，依然为4x7的tensor
            idx = image_pred_class.size(0)   #detections的个数
 
            '''开始执行 "非极大值抑制" 操作'''
            for i in range(idx):
                # 对已经有序的结果，每次开始更新后索引加一，挨个与后面的结果比较
                
                try:# image_pred_class[i].unsqueeze(0)，为什么要加unsqueeze(0)？这里image_pred_class为4x7的tensor，image_pred_class[i]是一个长度为7的tensor，要变成1x7的tensor，在第0维添加一个维度。
                    ious = bbox_iou(image_pred_class[i].unsqueeze(0), image_pred_class[i+1:])#这句话的作用是计算第i个方框和i+1到最终的所有方框的IOU。
                except ValueError:
                '''
                在for i in range(idx):这个循环中，因为有一些框(在image_pred_class对应一行)会被去掉，image_pred_class行数会减少，
                这样在后面的循环中，idx序号会超出image_pred_class的行数的范围，出现ValueError错误。
                所以当抛出这个错误时，则跳出这个循环，因为此时已经没有更多可以去掉的方框了。
                '''
                    break
            
                except IndexError:
                    break
            
                
                iou_mask = (ious < nms_conf).float().unsqueeze(1)# 计算出需要保留的item（保留ious < nms_conf的框）而ious < nms_conf得到的是torch.uint8类型，用float()将它们转换为float类型。因为要与image_pred_class[i+1:]相乘，故长度为7的tensor，要变成1x7的tensor？，需添加一个维度。
                image_pred_class[i+1:] *= iou_mask #将iou_mask与比序号i大的框的预测值相乘，其中IOU大于阈值的框的预测值全部变成0.得出需要保留的框    
            
                # 开始移除
                non_zero_ind = torch.nonzero(image_pred_class[:,4]).squeeze()#torch.nonzero返回的是索引，是2维tensor。将经过iou_mask掩码后的每个方框含有目标的得分为非0的方框的索引提取出来，non_zero_ind经squeeze后为一维tensor，含有目标的得分非0的索引
                image_pred_class = image_pred_class[non_zero_ind].view(-1,7)#得到含有目标的得分非0的方框的预测值(x1, y1, x2, y2, s,  s_class,index_cls)，为1x7的tensor
            # 当前类的nms执行完之后，下一次循环将对剩下的方框中得分第i+1高的方框进行NMS操作，因为刚刚已经对得分第1到i高的方框进行了NMS操作。直到最后一个方框循环完成为止
            # 在每次进行NMS操作的时候，预测值tensor中都会有一些行(对应某些方框)被去掉。接下来是保存结果。
            # new()创建了一个和image_pred_class类型相同的tensor，tensor行数等于cls这个类别所有的方框经过NMS剩下的方框的个数，即image_pred_class的行数，列数为1.
            #再将生成的这个tensor所有元素赋值为这些方框所属图片对应于batch中的序号ind(一个batch有多张图片同时测试)，用fill_(ind)实现   
            batch_ind = image_pred_class.new(image_pred_class.size(0), 1).fill_(ind)     
            seq = batch_ind, image_pred_class
            #我们没有初始化我们的输出张量，除非我们有要分配给它的检测结果。一旦其被初始化，我们就将后续的检测结果与它连接起来。我们使用write标签来表示张量是否初始化了。在类别上迭代的循环结束时，我们将所得到的检测结果加入到张量输出中。
            if not write:
            # 将batch_ind, image_pred_class在列维度上进行连接，image_pred_class每一行存储的是(x1,y1,x2,y2,s,s_cls,index_cls)，现在在第一列增加了一个代表这个行对应方框所属图片在一个batch中的序号ind
                output = torch.cat(seq,1)
                write = True
            else:
                out = torch.cat(seq,1)
                output = torch.cat((output,out))
    
    try:#在该函数结束时，我们会检查输出是否已被初始化。如果没有，就意味着在该 batch 的任意图像中都没有单个检测结果。在这种情况下，我们返回 0。
        return output
    except:# 如果所有的图片都没有检测到方框，则在前面不会进行NMS等操作，不会生成output，此时将在except中返回0
        return 0
    # 最终返回的output是一个batch中所有图片中剩下的方框的属性，一行对应一个方框，属性为(x1,y1,x2,y2,s,s_cls,index_cls)，batch号和所属的类别号
    # ind 是这个方框所属图片在这个batch中的序号，x1,y1是在网络输入图片(416x416)坐标系中，方框左上角的坐标；x2,y2是在网络输入图片(416x416)坐标系中，方框右下角的坐标。s是这个方框含有目标的得分s_cls是这个方框中所含目标最有可能的类别的概率得分，index_cls是s_cls对应的这个类别所对应的序号
 '''
 write_results 函数输出一个形状为 Dx8 的张量；其中 D 是所有图像中的「真实」检测结果，每个都用一行表示。每一个检测结果都有 8 个属性，即：该检测结果所属的 batch 中图像的索引、4 个角的坐标、objectness 分数、有最大置信度的类别的分数、该类别的索引。
 '''


def letterbox_image(img, inp_dim):
    """
    lteerbox_image()将图片按照纵横比进行缩放，将空白部分用(128,128,128)填充,调整图像尺寸
    具体而言,此时某个边正好可以等于目标长度,另一边小于等于目标长度
    将缩放后的数据拷贝到画布中心,返回完成缩放
    """
    img_w, img_h = img.shape[1], img.shape[0]
    w, h = inp_dim　#inp_dim是需要resize的尺寸（如416*416）
    # 取min(w/img_w, h/img_h)这个比例来缩放，缩放后的尺寸为new_w, new_h,即保证较长的边缩放后正好等于目标长度(需要的尺寸)，另一边的尺寸缩放后还没有填充满.
    new_w = int(img_w * min(w/img_w, h/img_h))
    new_h = int(img_h * min(w/img_w, h/img_h))
    resized_image = cv2.resize(img, (new_w,new_h), interpolation = cv2.INTER_CUBIC) #将图片按照纵横比不变来缩放为new_w x new_h，768 x 576的图片缩放成416x312.,用了双三次插值
    # 创建一个画布, 将resized_image数据拷贝到画布中心。
    canvas = np.full((inp_dim[1], inp_dim[0], 3), 128)#生成一个我们最终需要的图片尺寸hxwx3的array,这里生成416x416x3的array,每个元素值为128
    # 将wxhx3的array中对应new_wxnew_hx3的部分(这两个部分的中心应该对齐)赋值为刚刚由原图缩放得到的数组,得到最终缩放后图片
    canvas[(h-new_h)//2:(h-new_h)//2 + new_h,(w-new_w)//2:(w-new_w)//2 + new_w,  :] = resized_image
    
    return canvas
 
def prep_image(img, inp_dim):#prep_image用来将numpy数组转换成PyTorch需要的的输入格式。即（3，416,416）
    """
    为神经网络准备输入图像数据
    返回值: 处理后图像, 原图, 原图尺寸
    """
    img = (letterbox_image(img, (inp_dim, inp_dim)))# lteerbox_image()将图片按照纵横比进行缩放，将空白部分用(128,128,128)填充
    img = img[:,:,::-1].transpose((2,0,1)).copy()#img是【h,w,channel】，这里的img[:,:,::-1]是将第三个维度channel从opencv的BGR转化为pytorch的RGB，然后transpose((2,0,1))的意思是将[height,width,channel]->[channel,height,width]
    img = torch.from_numpy(img).float().div(255.0).unsqueeze(0)# from_numpy(()将ndarray数据转换为tensor格式，div(255.0)将每个元素除以255.0，进行归一化，unsqueeze(0)在0维上添加了一维，
# 从3x416x416变成1x3x416x416，多出来的一维表示batch。这里就将图片变成了BxCxHxW的pytorch格式
    return img
 
def load_classes(namesfile): #load_classes会返回一个字典——将每个类别的索引映射到其名称的字符串
    """
    加载类名文件
    :param namesfile:
    :return: 元组,包括类名数组和总类的个数
    """
    fp = open(namesfile, "r")
    names = fp.read().split("\n")[:-1] #如果不加-1会打印出来一个空字符
    return names

```



## test.py

```python
from __future__ import division
import time
import torch 
import torch.nn as nn
from torch.autograd import Variable
import numpy as np
import cv2 
from util import *
import argparse
import os 
import os.path as osp
from darknet import Darknet
import pickle as pkl
import pandas as pd
import random
 
def arg_parse():
    """
    检测模块的参数转换
    
    """
    #创建一个ArgumentParser对象，格式: 参数名, 目标参数(dest是字典的key),帮助信息,默认值,类型 
    #dest 允许自定义ArgumentParser的参数属性名称 
    parser = argparse.ArgumentParser(description='YOLO v3 检测模型')
    
    parser.add_argument("--images", dest = 'images', help = 
                        "待检测图像目录",
                        default = "imgs", type = str)  # images是所有测试图片所在的文件夹
    parser.add_argument("--det", dest = 'det', help =   #det保存检测结果的目录
                        "检测结果保存目录",
                        default = "det", type = str)
    parser.add_argument("--bs", dest = "bs", help = "Batch size，默认为 1", default = 1)
    parser.add_argument("--confidence", dest = "confidence", help = "目标检测结果置信度阈值", default = 0.5)
    parser.add_argument("--nms_thresh", dest = "nms_thresh", help = "NMS非极大值抑制阈值", default = 0.4)
    parser.add_argument("--cfg", dest = 'cfgfile', help = 
                        "配置文件",
                        default = "cfg/yolov3.cfg", type = str)
    parser.add_argument("--weights", dest = 'weightsfile', help = 
                        "模型权重",
                        default = "yolov3.weights", type = str)
    parser.add_argument("--reso", dest = 'reso', help = 
                        "网络输入分辨率. 分辨率越高,则准确率越高; 反之亦然.",
                        default = "416", type = str)#reso输入图像的分辨率，可用于在速度与准确度之间的权衡
    parser.add_argument("--scales", dest="scales", help="缩放尺度用于检测", default="1,2,3", type=str)
    return parser.parse_args()# 返回转换好的结果
    
args = arg_parse()# args是一个namespace类型的变量，即argparse.Namespace, 可以像easydict一样使用,就像一个字典，key来索引变量的值   
# Namespace(bs=1, cfgfile='cfg/yolov3.cfg', confidence=0.5,det='det', images='imgs', nms_thresh=0.4, reso='416', weightsfile='yolov3.weights')
images = args.images
batch_size = int(args.bs)
confidence = float(args.confidence)
nms_thesh = float(args.nms_thresh)
start = 0
CUDA = torch.cuda.is_available()# GPU环境是否可用
 
 
 
num_classes = 80# coco 数据集有80类
classes = load_classes("data/coco.names") #将类别文件载入到我们的程序中，coco.names文件中保存的是所有类别的名字，load_classes()返回一个列表classes，每个元素是一个类别的名字
 
 
 
#初始化网络并载入权重
print("载入神经网络...") 
model = Darknet(args.cfgfile)# Darknet类中初始化时得到了网络结构和网络的参数信息，保存在net_info，module_list中
model.load_weights(args.weightsfile)# 将权重文件载入，并复制给对应的网络结构model中
print("模型加载成功.")
# 网络输入数据大小
model.net_info["height"] = args.reso # model类中net_info是一个字典。’’height’’是图片的宽高，因为图片缩放到416x416，所以宽高一样大
inp_dim = int(model.net_info["height"])　#inp_dim是网络输入图片尺寸（如416*416）
assert inp_dim % 32 == 0 # 如果设定的输入图片的尺寸不是32的位数或者不大于32，抛出异常
assert inp_dim > 32
 
 # 如果GPU可用, 模型切换到cuda中运行
if CUDA:
    model.cuda()
 
 
 
model.eval()#变成测试模式，这主要是对dropout和batch normalization的操作在训练和测试的时候是不一样的
 
read_dir = time.time() #read_dir 是一个用于测量时间的检查点,开始计时
# 加载待检测图像列表
try: #从磁盘读取图像或从目录读取多张图像。图像的路径存储在一个名为 imlist 的列表中,imlist列表保存了images文件中所有图片的完整路径，一张图片路径对应一个元素。 
     #osp.realpath('.')得到了图片所在文件夹的绝对路径，images是测试图片文件夹，listdir(images)得到了images文件夹下面所有图片的名字。
     #通过join()把目录（文件夹）的绝对路径和图片名结合起来，就得到了一张图片的完整路径
    '''
    os.path.join()函数用于路径拼接文件路径。 
os.path.join()函数中可以传入多个路径：

会从第一个以”/”开头的参数开始拼接，之前的参数全部丢弃。

以上一种情况为先。在上一种情况确保情况下，若出现”./”开头的参数，会从”./”开头的参数的上一个参数开始拼接

    '''
    imlist = [osp.join(osp.realpath('.'), images, img) for img in os.listdir(images)]
except NotADirectoryError:# 如果上面的路径有错，只得到images文件夹绝对路径即可
    imlist = []
    imlist.append(osp.join(osp.realpath('.'), images))
except FileNotFoundError:
    print ("No file or directory with the name {}".format(images))
    exit()
# 存储结果目录    
if not os.path.exists(args.det): #如果保存检测结果的目录（由 det 标签定义）不存在，就创建一个
    os.makedirs(args.det)
 
load_batch = time.time()# 开始载入图片的时间。 load_batch - read_dir 得到读取所有图片路径的时间
loaded_ims = [cv2.imread(x) for x in imlist] #使用 OpenCV 来加载图像，将所有的图片读入，一张图片的数组在loaded_ims列表中保存为一个元素
 
# 加载全部待检测图像
# loaded_ims和[inp_dim for x in range(len(imlist))]是两个列表，lodded_ims是所有图片数组的列表，[inp_dim for x in range(len(imlist))] 遍历imlist长度(即图片的数量)这么多次，每次返回值是图片需resize的输入尺寸inp_dim（如416）
im_batches = list(map(prep_image, loaded_ims, [inp_dim for x in range(len(imlist))]))#map函数将对应的元素作为参数传入prep_image函数，最终的所有结果也会组成一个列表(im_batches)，是BxCxHxW
im_dim_list = [(x.shape[1], x.shape[0]) for x in loaded_ims]#除了转换后的图像，我们也会维护一个列表im_dim_list用于保存原始图片的维度。一个元素对应一张图片的宽高,opencv读入的图片矩阵对应的是 HxWxC
#将im_dim_list转换为floatTensor类型的tensor，此时维度为11x2，（因为本例测试集一共11张图片）并且每个元素沿着第二维(列的方向)进行复制，最终变成11x4的tensor。一行的元素为(W,H,W,H)，对应一张图片原始的宽、高，且重复了一次。(W,H,W,H)主要是在后面计算x1,y1,x2,y2各自对应的缩放系数时好对应上。
im_dim_list = torch.FloatTensor(im_dim_list).repeat(1,2)#repeat(*size), 沿着指定维度复制数据，size维度必须和数据本身维度要一致
 
leftover = 0 #创建 batch，将所有测试图片按照batch_size分成多个batch
if (len(im_dim_list) % batch_size):# 如果测试图片的数量不能被batch_size整除，leftover=1
    leftover = 1
#如果batch size 不等于1，则将一个batch的图片作为一个元素保存在im_batches中，按照if语句里面的公式计算。如果batch_size=1,则每一张图片作为一个元素保存在im_batches中
if batch_size != 1:
# 如果batch_size 不等于1，则batch的数量=图片数量//batch_size + leftover(测试图片的数量不能被batch_size整除，leftover=1，否则为0)。本例有11张图片，假设batch_size=2,则batch数量=6
    num_batches = len(imlist) // batch_size + leftover
# 前面的im_batches变量将所有的图片以BxCxHxW的格式保存。而这里将一个batch的所有图片在B这个维度(第0维度)上进行连接，torch.cat()默认在0维上进行连接。将这个连接后的tensor作为im_batches列表的一个元素。
#第i个batch在前面的im_batches变量中所对应的元素就是i*batch_size: (i + 1)*batch_size，但是最后一个batch如果用(i + 1)*batch_size可能会超过图片数量的len(im_batches)长度，所以取min((i + 1)*batch_size, len(im_batches)            
    im_batches = [torch.cat((im_batches[i*batch_size : min((i +  1)*batch_size,
                        len(im_batches))]))  for i in range(num_batches)]  
 
# The Detection Loop
write = 0
 
 
if CUDA:
    im_dim_list = im_dim_list.cuda()
# 开始计时，计算开始检测的时间。start_det_loop - load_batch 为读入所有图片并将它们分成不同batch的时间    
start_det_loop = time.time()
# enumerate返回im_batches列表中每个batch在0维连接成一个元素的tensor和这个tensor在im_batches中的序号。本例子中batch只有一张图片
for i, batch in enumerate(im_batches):
#load the image 
    start = time.time()
    if CUDA:
        batch = batch.cuda()
    # 取消梯度计算
    with torch.no_grad():
    # Variable(batch)将图片生成一个可导tensor，现在已经不再支持这种写法，Autograd automatically supports Tensors with requires_grad set to True。
    # prediction是一个batch所有图片通过yolov3模型得到的预测值，维度为1x10647x85，三个scale的图片每个scale的特征图大小为13x13,26x26,52x52,一个元素看作一个格子，每个格子有3个anchor，将一个anchor保存为一行，
    #所以prediction一共有(13x13+26x26+52x52)x3=10647行，一个anchor预测(x,y,w,h,s,s_cls1,s_cls2...s_cls_80)，一共有85个元素。所以prediction的维度为Bx10647x85，加为这里batch_size为1，所以prediction的维度为1x10647x85
        prediction = model(Variable(batch), CUDA)
    # 结果过滤.这里返回了经过NMS后剩下的方框，最终每个方框的属性为(ind,x1,y1,x2,y2,s,s_cls,index_cls) ind是这个方框所属图片在这个batch中的序号，x1,y1是在网络输入图片(416x416)坐标系中，方框左上角的坐标；x2,y2是方框右下角的坐标。
    # s是这个方框含有目标的得分，s_cls是这个方框中所含目标最有可能的类别的概率得分，index_cls是s_cls对应的这个类别在所有类别中所对应的序号。这里prediction维度是3x8，表示有3个框
    prediction = write_results(prediction, confidence, num_classes, nms_conf = nms_thesh)
 
    end = time.time()
    # 如果从write_results()返回的一个batch的结果是一个int(0)，表示没有检测到时目标，此时用continue跳过本次循环
    if type(prediction) == int:
    # 在imlist中，遍历一个batch所有的图片对应的元素(即每张图片的存储位置和名字)，同时返回这张图片在这个batch中的序号im_num
        for im_num, image in enumerate(imlist[i*batch_size: min((i +  1)*batch_size, len(imlist))]):
　　　　　　　　　　　　# 计算图片在imlist中所对应的序号,即在所有图片中的序号
            im_id = i*batch_size + im_num
　　　　　　　　　　　　# 打印图片运行的时间，用一个batch的平均运行时间来表示。.3f就表示保留三位小数点的浮点
            print("{0:20s} predicted in {1:6.3f} seconds".format(image.split("/")[-1], (end - start)/batch_size))
　　　　　　　　　　　　# 输出本次处理图片所有检测到的目标的名字
            print("{0:20s} {1:s}".format("Objects Detected:", ""))
            print("----------------------------------------------------------")
        continue
　　　　# prediction[:,0]取出了每个方框在所在图片在这个batch(第i个batch)中的序号，加上i*batch_size，就将prediction中每个框(一行)的第一个元素（维度0）变成了这个框所在图片在imlist中的序号，即在所有图片中的序号
    prediction[:,0] += i*batch_size    
    # 这里用一个write标志来标记是否是第一次得到输出结果，因为每次的结果要进行torch.cat()操作，而一个空的变量不能与tensor连接，所以第一次将它赋值给output，后面就直接进行cat()操作
    if not write:                      #If we have't initialised output
        output = prediction  
        write = 1
    else:
    # output将每个batch的输出结果在0维进行连接，即在行维度上连接，每行表示一个检测方框的预测值。最终本例子中的11张图片检测得到的结果output维度为 34 x 8
        output = torch.cat((output,prediction))
    # 在imlist中，遍历一个batch所有的图片对应的元素(即每张图片的存储位置加名字)，同时返回这张图片在这个batch中的序号im_num
    for im_num, image in enumerate(imlist[i*batch_size: min((i +  1)*batch_size, len(imlist))]):
        im_id = i*batch_size + im_num# 计算图片在imlist中所对应的序号,即在所有图片中的序号
        # objs列表包含了本次处理图片中所有检测得到的方框所包含目标的类别名称。每个元素对应一个检测得到的方框所包含目标的类别名称。for x in output遍历output中的每一行(即一个方框的预测值)得到x，如果这个方
     　　 #框所在图片在所有图片中的序号等于本次处理图片的序号，则用classes[int(x[-1])找到这个方框包含目标类别在classes中对应的类的名字。
        objs = [classes[int(x[-1])] for x in output if int(x[0]) == im_id]# classes在之前的语句classes = load_classes("data/coco.names")中就是为了把类的序号转为字符名字
        print("{0:20s} predicted in {1:6.3f} seconds".format(image.split("/")[-1], (end - start)/batch_size))# 打印本次处理图片运行的时间，用一个batch的平均运行时间来表示。.3f就表示保留三位小数点的浮点
        print("{0:20s} {1:s}".format("Objects Detected:", " ".join(objs)))# 输出本次处理图片所有检测到的目标的类别名字
        print("----------------------------------------------------------")
 
    if CUDA:
        torch.cuda.synchronize()  # 保证gpu和cpu同步，否则，一旦 GPU 工作排队了并且 GPU 工作还远未完成，那么 CUDA 核就将控制返回给 CPU（异步调用）。
# 对所有的输入的检测结果        
try:
#  check whether there has been a single detection has been made or not
    output
except NameError:
    print ("没有检测到任何目标")
    exit() # 当所有图片都有没检测到目标时，退出程序
# 最后输出output_recast - start_det_loop计算的是从开始检测，到去掉低分，NMS操作的时间.    
output_recast = time.time()
# 前面im_dim_list是一个4维tensor，一行的元素为(W,H,W,H)，对应一张图片原始的宽、高，且重复了一次。(W,H,W,H)主要是在后面计算x1,y1,x2,y2各自对应的缩放系数时好对应上。
#本例中im_dim_list维度为11x4.index_select()就是在im_dim_list中查找output中每行所对应方框所在图片在所有图片中的序号对应im_dim_list中的那一行，最终得到的im_dim_list的行数应该与output的行数相同。
#因此这样做后本例中此时im_dim_list维度34x4
'''
参数说明：index_select(x, 1, indices)

1代表维度1，即列，indices是筛选的索引序号。
'''
im_dim_list = torch.index_select(im_dim_list, 0, output[:,0].long())# pytorch 切片torch.index_select(data, dim, indices)
"""
应该将方框的坐标转换为相对于填充后的图片中包含原始图片区域的计算方式。min(416/im_dim_list, 1)，416除以im_dim_list中的每个元素，然后在得到的tensor中的第1维(每行)去找到最小的元素.torch.min()返回一个
有两个tensor元素的tuple，第一个元素就是找到最小的元素的结果，这里没有给定 keepdim=True的标记，所以得到的最小元素的tensor会比原来减小一维，
另一个是每个最小值在每行中对应的序号。torch.min(416/im_dim_list, 1)[0]得到长度为34的最小元素构成的tensor，通过view(-1, 1)
变成了维度为34x1的tensor。这个tensor，即scaling_factor的每个元素就对应一张图片缩放成416的时候所采用的缩放系数
注意了！！！ Scaling_factor在进行计算的时候用的416，如果是其它的尺寸，这里不应该固定为416，在开始检测时util.py里所用的缩放系数就是用的 min(w/img_w, h/img_h)    
    torch.min(input, dim, keepdim=False, out=None) -> (Tensor, LongTensor)
返回新的张量，其中包括输入张量input中指定维度dim中每行的最小值，同时返回每个最小值的位置索引。
若keepdim值为True，则在输出张量中，除了被操作的dim维度值降为1，其它维度与输入张量input相同。否则，dim维度相当于被执行torch.squeeze()维度压缩操作，导致此维度消失，最终输出张量会比输入张量少一个维度。
"""
 
#scaling_factor = torch.min(416/im_dim_list,1)[0].view(-1,1)#这是源代码，下面是我修改的代码
scaling_factor = torch.min(int(args.reso)/im_dim_list,1)[0].view(-1,1)
# 将相对于输入网络图片(416x416)的方框属性变换成原图按照纵横比不变进行缩放后的区域的坐标。
#scaling_factor*img_w和scaling_factor*img_h是图片按照纵横比不变进行缩放后的图片，即原图是768x576按照纵横比长边不变缩放到了416*372。
#经坐标换算,得到的坐标还是在输入网络的图片(416x416)坐标系下的绝对坐标，但是此时已经是相对于416*372这个区域的坐标了，而不再相对于(0,0)原点。
output[:,[1,3]] -= (inp_dim - scaling_factor*im_dim_list[:,0].view(-1,1))/2#x1=x1−(416−scaling_factor*img_w)/2,x2=x2-(416−scaling_factor*img_w)/2
output[:,[2,4]] -= (inp_dim - scaling_factor*im_dim_list[:,1].view(-1,1))/2#y1=y1-(416−scaling_factor*img_h)/2,y2=y2-(416−scaling_factor*img_h)/2
 
 
# 将方框坐标(x1,y1,x2,y2)映射到原始图片尺寸上，直接除以缩放系数即可。output[:,1:5]维度为34x4，scaling_factor维度是34x1.相除时会利用广播性质将scaling_factor扩展为34x4的tensor
output[:,1:5] /= scaling_factor # 缩放至原图大小尺寸
 
# 如果映射回原始图片中的坐标超过了原始图片的区域，则x1,x2限定在[0,img_w]内，img_w为原始图片的宽度。如果x1,x2小于0.0，令x1,x2为0.0，如果x1,x2大于原始图片宽度，令x1,x2大小为图片的宽度。
#同理，y1,y2限定在0,img_h]内，img_h为原始图片的高度。clamp()函数就是将第一个输入对数的值限定在后面两个数字的区间
for i in range(output.shape[0]):
    output[i, [1,3]] = torch.clamp(output[i, [1,3]], 0.0, im_dim_list[i,0])
    output[i, [2,4]] = torch.clamp(output[i, [2,4]], 0.0, im_dim_list[i,1])
    
 
class_load = time.time()# 开始载入颜色文件的时间
 # 绘图
colors = pkl.load(open("pallete", "rb"))# 读入包含100个颜色的文件pallete，里面是100个三元组序列
 
draw = time.time() # 开始画方框的文字的时间
 
# x为映射到原始图片中一个方框的属性(ind,x1,y1,x2,y2,s,s_cls,index_cls)，results列表保存了所有测试图片，一个元素对应一张图片
def write(x, results):
   
    c1 = tuple(x[1:3].int())# c1为方框左上角坐标x1,y1
    c2 = tuple(x[3:5].int()) # c2为方框右下角坐标x2,y2
    img = results[int(x[0])]# 在results中找到x方框所对应的图片，x[0]为方框所在图片在所有测试图片中的序号
    cls = int(x[-1])
    color = random.choice(colors)  # 随机选择一个颜色，用于后面画方框的颜色
    label = "{0}".format(classes[cls])# label为这个框所含目标类别名字的字符串
    cv2.rectangle(img, c1, c2,color, 1)# 在图片上画出(x1,y1,x2,y2)矩形，即我们检测到的目标方框
    t_size = cv2.getTextSize(label, cv2.FONT_HERSHEY_PLAIN, 1 , 1)[0] # 得到一个包含目标名字字符的方框的宽高
    c2 = c1[0] + t_size[0] + 3, c1[1] + t_size[1] + 4　 # 得到包含目标名字的方框右下角坐标c2，这里在x,y方向上分别加了3、4个像素
    cv2.rectangle(img, c1, c2,color, -1) # 在图片上画一个实心方框，我们将在方框内放置目标类别名字
    cv2.putText(img, label, (c1[0], c1[1] + t_size[1] + 4), cv2.FONT_HERSHEY_PLAIN, 1, [225,255,255], 1); # 在图片上写文字，(c1[0], c1[1] + t_size[1] + 4)为字符串的左下角坐标
    return img
 
# 开始逐条绘制output中结果.将每个框在对应图片上画出来，同时写上方框所含目标名字。map函数将output传递给map()中参数是函数的那个参数，每次传递一行。
#而lambda中x就是output中的一行，维度为1x8。loaded_ims列表保存了所有图片内容数组,一个元素对应一张图片，原地修改了loaded_ims 之中的图像，使之还包含了目标类别名字。
list(map(lambda x: write(x, loaded_ims), output))
#将带有方框的每张测试图片重新命名。det_names 是一个series对象，类似于一个列表，pd.Series(imlist)返回一个series对象。
#对于imlist这个列表(保存的是所有测试图片的绝对路径+名字，一个元素对应一张图片路径加名字)，生成的series对象包含两列，一列是每个imlist元素的索引，一列是 imlist 元素。
#apply()函数将这个series对象传递给apply()里面的函数，以遍历的方式进行。apply()返回结果是经过 apply()里面的函数返回每张测试图片将要保存的文件路径，这里依然是一个series对象
#x是Series()返回的对象中的一个元素，即一张图片的绝对路径加名字，args.det是将要保存图片的文件夹(默认det)，返回”det/det_图片名”,x.split("/")[-1]中的 ”/” 是linux下文件路径分隔符
det_names = pd.Series(imlist).apply(lambda x: "{}/det_{}".format(args.det,x.split("/")[-1]))# 每张图像都以「det_」加上图像名称的方式保存。我们创建了一个地址列表，这是我们保存我们的检测结果图像的位置。
 
list(map(cv2.imwrite, det_names, loaded_ims))# 保存标注了方框和目标类别名字的图片。det_names对应所有测试图片的保存路径，loaded_ims对应所有标注了方框和目标名字的图片数组
 
 
end = time.time()
 
print("SUMMARY")
print("----------------------------------------------------------")
print("{:25s}: {}".format("Task", "Time Taken (in seconds)"))
print()
print("{:25s}: {:2.3f}".format("Reading addresses", load_batch - read_dir))# 读取所有图片路径的时间
print("{:25s}: {:2.3f}".format("Loading batch", start_det_loop - load_batch))# 读入所有图片，并将图片按照batch size分成不同batch的时间
# 从开始检测到到去掉低分，NMS操作得到output的时间.  
print("{:25s}: {:2.3f}".format("Detection (" + str(len(imlist)) +  " images)", output_recast - start_det_loop))
#这里output映射回原图的时间
print("{:25s}: {:2.3f}".format("Output Processing", class_load - output_recast))
print("{:25s}: {:2.3f}".format("Drawing Boxes", end - draw))# 画框和文字的时间
print("{:25s}: {:2.3f}".format("Average time_per_img", (end - load_batch)/len(imlist)))# 从开始载入图片到所有结果处理完成，平均每张图片所消耗时间
print("----------------------------------------------------------")
 
torch.cuda.empty_cache()

```

### 检测测试代码

```python
python detect.py --images dog-cycle-car.png --det det
```



## video.py

 ```python

from __future__ import division
import time
import torch 
import torch.nn as nn
from torch.autograd import Variable
import numpy as np
import cv2 
from util import *
import argparse
import os 
import os.path as osp
from darknet import Darknet
import pickle as pkl
import pandas as pd
import random
 
def arg_parse():
    """
    视频检测模块的参数转换
    
    """
    #创建一个ArgumentParser对象，格式: 参数名, 目标参数(dest是字典的key),帮助信息,默认值,类型
    parser = argparse.ArgumentParser(description='YOLO v3 检测模型')
    parser.add_argument("--bs", dest = "bs", help = "Batch size，默认为 1", default = 1)
    parser.add_argument("--confidence", dest = "confidence", help = "目标检测结果置信度阈值", default = 0.5)
    parser.add_argument("--nms_thresh", dest = "nms_thresh", help = "NMS非极大值抑制阈值", default = 0.4)
    parser.add_argument("--cfg", dest = 'cfgfile', help = 
                        "配置文件",
                        default = "cfg/yolov3.cfg", type = str)
    parser.add_argument("--weights", dest = 'weightsfile', help = 
                        "模型权重",
                        default = "yolov3.weights", type = str)
    parser.add_argument("--reso", dest = 'reso', help = 
                        "网络输入分辨率. 分辨率越高,则准确率越高; 反之亦然",
                        default = "416", type = str)
    parser.add_argument("--video", dest = "videofile", help = "待检测视频目录", default = "video.avi", type = str)
    
    return parser.parse_args()
    
args = arg_parse()# args是一个namespace类型的变量，即argparse.Namespace, 可以像easydict一样使用,就像一个字典，key来索引变量的值   
# Namespace(bs=1, cfgfile='cfg/yolov3.cfg', confidence=0.5,det='det', images='imgs', nms_thresh=0.4, reso='416', weightsfile='yolov3.weights')
batch_size = int(args.bs)
confidence = float(args.confidence)
nms_thesh = float(args.nms_thresh)
start = 0
CUDA = torch.cuda.is_available()# GPU环境是否可用
 
 
 
num_classes = 80# coco 数据集有80类
classes = load_classes("data/coco.names")#将类别文件载入到我们的程序中，coco.names文件中保存的是所有类别的名字，load_classes()返回一个列表classes，每个元素是一个类别的名字
 
 
 
#初始化网络并载入权重
print("载入神经网络....")
model = Darknet(args.cfgfile)# Darknet类中初始化时得到了网络结构和网络的参数信息，保存在net_info，module_list中
model.load_weights(args.weightsfile)# 将权重文件载入，并复制给对应的网络结构model中
print("模型加载成功.")
# 网络输入数据大小
model.net_info["height"] = args.reso# model类中net_info是一个字典。’’height’’是图片的宽高，因为图片缩放到416x416，所以宽高一样大
inp_dim = int(model.net_info["height"])#inp_dim是网络输入图片尺寸（如416*416）
assert inp_dim % 32 == 0 # 如果设定的输入图片的尺寸不是32的位数或者不大于32，抛出异常
assert inp_dim > 32
 
# 如果GPU可用, 模型切换到cuda中运行
if CUDA:
    model.cuda()
 
 
#变成测试模式，这主要是对dropout和batch normalization的操作在训练和测试的时候是不一样的
model.eval()
 
 
#要在视频或网络摄像头上运行这个检测器，代码基本可以保持不变，只是我们不会在 batch 上迭代，而是在视频的帧上迭代。
# 将方框和文字写在图片上,x为输出的预测，results为帧数
def write(x, results):
    c1 = tuple(x[1:3].int())# c1为方框左上角坐标x1,y1
    c2 = tuple(x[3:5].int())# c2为方框右下角坐标x2,y2
    img = results
    cls = int(x[-1])
    color = random.choice(colors)#随机选择一个颜色，用于后面画方框的颜色
    label = "{0}".format(classes[cls])#label为这个框所含目标类别名字的字符串
    cv2.rectangle(img, c1, c2,color, 1)# 在图片上画出(x1,y1,x2,y2)矩形，即我们检测到的目标方框
    t_size = cv2.getTextSize(label, cv2.FONT_HERSHEY_PLAIN, 1 , 1)[0]# 得到一个包含目标名字字符的方框的宽高
    c2 = c1[0] + t_size[0] + 3, c1[1] + t_size[1] + 4# 得到包含目标名字的方框右下角坐标c2，这里在x,y方向上分别加了3、4个像素
    cv2.rectangle(img, c1, c2,color, -1)# 在图片上画一个实心方框，我们将在方框内放置目标类别名字
    cv2.putText(img, label, (c1[0], c1[1] + t_size[1] + 4), cv2.FONT_HERSHEY_PLAIN, 1, [225,255,255], 1);# 在图片上写文字，(c1[0], c1[1] + t_size[1] + 4)为字符串的左下角坐标
    return img
 
 
#Detection phase
 
videofile = args.videofile #or path to the video file. 
 
cap = cv2.VideoCapture(videofile) #用 OpenCV 打开视频
#读取摄像头,0为摄像头索引，当有多个摄像头时，从0开始编号
#cap = cv2.VideoCapture(0)  #for webcam(相机)
 
# 当没有打开视频时抛出错误
assert cap.isOpened(), 'Cannot capture source'
# frames用于统计图片的帧数
frames = 0  
start = time.time()
 
fourcc = cv2.VideoWriter_fourcc('M','J','P','G') 
fps = 24 
savedPath = './det/savevideo.avi' # 保存的地址和视频名
ret, frame = cap.read() 
videoWriter = cv2.VideoWriter(savedPath, fourcc, fps,(frame.shape[1], frame.shape[0])) # 最后为视频图片的形状,保存文件名、编码器、帧率、视频宽高
 
while cap.isOpened():# ret指示是否读入了一张图片，为true时读入了一帧图片
    '''
    先返回一个布尔值，如果视频读取正确，则为 True，如果错误，则为 False，也可用来判断是否到视频末尾
    再返回一个值，为每一帧的图像，该值是一个三维矩阵
    '''
    ret, frame = cap.read()
    
    if ret:
        # 将图片按照比例缩放缩放，将空白部分用(128,128,128)填充，得到为416x416的图片。并且将HxWxC转换为CxHxW   
        img = prep_image(frame, inp_dim)
        #cv2.imshow("a", frame)
        # 得到图片的W,H,是一个二元素tuple.因为我们不必再处理 batch，而是一次只处理一张图像，所以很多地方的代码都进行了简化。
        #因为一次只处理一帧，故使用一个元组im_dim替代 im_dim_list 的张量。
        im_dim = frame.shape[1], frame.shape[0]
#先将im_dim变成长度为2的一维行tensor，再在1维度(列这个维度)上复制一次，变成1x4的二维行tensor[W,H,W,H]，展开成1x4主要是在后面计算x1,y1,x2,y2各自对应的缩放系数时好对应上。  
        im_dim = torch.FloatTensor(im_dim).repeat(1,2)#repeat()可能会改变tensor的维度。它对tensor中对应repeat参数对应的维度上进行重复给定的次数，如果tensor的维度小于repeat()参数给定的维度，tensor的维度将变成和repeat()一致。这里repeat(1,2)，表示在第一维度上重复一次，第二维上重复两次，repeat(1,2)有2个元素，表示它给定的维度有2个,所以将长度为2的一维行tensor变成了维度为1x4的二维tensor   
                
        if CUDA:
            im_dim = im_dim.cuda()
            img = img.cuda()
        # 只进行前向计算，不计算梯度
        with torch.no_grad():
#得到每个预测方框在输入网络图片(416x416)坐标系中的坐标和宽高以及目标得分以及各个类别得分(x,y,w,h,s,s_cls1,s_cls2...)
#并且将tensor的维度转换成(batch_size, grid_size*grid_size*num_anchors, 5+类别数量)
            output = model(Variable(img, volatile = True), CUDA)
        #将方框属性转换成(ind,x1,y1,x2,y2,s,s_cls,index_cls)，去掉低分，NMS等操作，得到在输入网络坐标系中的最终预测结果
        output = write_results(output, confidence, num_classes, nms_conf = nms_thesh)
 
        # output的正常输出类型为float32,如果没有检测到目标时output元素为0，此时为int型，将会用continue进行下一次检测
        if type(output) == int:
        #每次迭代，我们都会跟踪名为frames的变量中帧的数量。然后我们用这个数字除以自第一帧以来过去的时间，得到视频的帧率。
            frames += 1
            print("FPS of the video is {:5.4f}".format( frames / (time.time() - start)))
        #我们不再使用cv2.imwrite将检测结果图像写入磁盘，而是使用cv2.imshow展示画有边界框的帧。
            cv2.imshow("frame", frame)
            key = cv2.waitKey(1)
        #如果用户按Q按钮，就会让代码中断循环，并且视频终止。
            if key & 0xFF == ord('q'):
                break
            continue
        
#im_dim一行对应一个方框所在图片尺寸。在detect.py中一次测试多张图片，所以对应的im_dim_list是找到每个方框对应的图片的尺寸。
# 而这里每次只有一张图片，每个方框所在图片的尺寸一样，只需将图片的尺寸的行数重复方框的数量次数即可                
        im_dim = im_dim.repeat(output.size(0), 1)
        # 得到每个方框所在图片缩放系数
        #scaling_factor = torch.min(416/im_dim,1)[0].view(-1,1)#这是源代码，下面是我修改的代码
        scaling_factor = torch.min(int(args.reso)/im_dim,1)[0].view(-1,1)
        # 将方框的坐标(x1,y1,x2,y2)转换为相对于填充后的图片中包含原始图片区域（如416*312区域）的计算方式。
        output[:,[1,3]] -= (inp_dim - scaling_factor*im_dim[:,0].view(-1,1))/2
        output[:,[2,4]] -= (inp_dim - scaling_factor*im_dim[:,1].view(-1,1))/2
        # 将坐标映射回原始图片
        output[:,1:5] /= scaling_factor
        #将超过了原始图片范围的方框坐标限定在图片范围之内
        for i in range(output.shape[0]):
            output[i, [1,3]] = torch.clamp(output[i, [1,3]], 0.0, im_dim[i,0])
            output[i, [2,4]] = torch.clamp(output[i, [2,4]], 0.0, im_dim[i,1])
    
        
        #coco.names文件中保存的是所有类别的名字，load_classes()返回一个列表classes，每个元素是一个类别的名字
        classes = load_classes('data/coco.names')
        #读入包含100个颜色的文件pallete，里面是100个三元组序列
        colors = pkl.load(open("pallete", "rb"))
        #将每个方框的属性写在图片上
        list(map(lambda x: write(x, frame), output))
        
        cv2.imshow("frame", frame)
        
        videoWriter.write(frame)           # 每次循环，写入该帧
        key = cv2.waitKey(1)
        # 如果有按键输入则返回按键值编码，输入q返回113
        if key & 0xFF == ord('q'):
            break
        #统计已经处理过的帧数
        frames += 1
        print(time.time() - start)
        print("FPS of the video is {:5.2f}".format( frames / (time.time() - start)))
    else:
        videoWriter.release()              # 结束循环的时候释放
        break     
 

 ```



# Opencv的一些用法

## 1、读入并显示图片

cv2中所有的图片数据的形式都是np.array来表示的

```python
import numpy as np 
import cv2
img =cv2.imread(r'1.png',cv2.IMREAD_COLOR)
'''
第二个参数表明如何读取图片
cv2.IMREAD_COLOR  读取一张彩色图片，默认参数
cv2.IMREAD_GRAYSCALE  以灰度图读入图像
cv2.UNCHANGED   读入图像包括图像的alpha通道
'''
```

显示图片

```python
#创建一个窗口，参数：窗口名字，
# cv2.WINDOW_AUTOSIZE 窗口大小根据图片大小，默认
# cv2.WINDOW_NORMAL 窗口大小可以改变
cv2.nameWindow('image',cv2.WINDOW_NORMAL)
cv2.imshow('image',img)
cv2.waitKey(0)  #等待键盘输入
'''
等待特定的毫秒数，等待键盘的输入，如果按下任何键，返回对应键的ASCII
如果没有返回-1
'''
cv2.destroyAllWindows()
```

保存图片

`cv2,imwrite('1.png',img)`

综合应用

```python
import numpy as np
import cv2
img = cv2.imread(r'1.png',cv2.IMREAD_COLOR)
cv2.nameWindow('image',cv2.WINDOW_NORMAL)
cv2.imshow('image',img)
k = cv2.waitKey(0)

if k == 27: #27为ESC的ASCII值
    cv2.distroyAllWindows()
elif k == ord('q'):  #获取单个字符的ASCII
    cv2.imwrite(r'2.png',img)
    cv2.distroyAllWindows()
```

## 2、视频基础操作

1、获取视频和播放视频

```python
import numpy as np
import cv2

#读取摄像头，如果向读取视频，参数或称视频的路径+文件名
cap = cv2.VideoCapture(0)
while(Ture):
    ret,frame = cap.read() ,#ret表示一个布尔量，用来表示是否读取成功
    cv2.imshow('frame',frame) #一帧覆盖上一帧，产生视频的效果
    if cv2.waitKey(1) == ord('q'): #通过改变cv2.waitKey()中的参数
        							#可以改变视频播放的速度
        break
cap.release()
cv2.destroyAllWindows()
```

有时候`cv2.VideoCapture()`不能初始化成功摄像头设备，可以使用`cap.isOpend()`来检查是否初始化成功，返回值为True则没有问题，否则就要使用cap.open()。这时可以`while(True)` 改 `while cap.isOpened()`

函数 `cap.get(propId)` 可以用来获得视频的一些参数信息。这里 
propId 可以是 0 到 18 之间的任何整数。每一个数代表视频的一个属性： 
• CV_CAP_PROP_POS_MSEC Current position of the video file in milliseconds. 
• CV_CAP_PROP_POS_FRAMES 0-based index of the frame to be decoded/captured next. 
• CV_CAP_PROP_POS_AVI_RATIO Relative position of the video file: 0 - start of the film, 1 - end of the film. 
• CV_CAP_PROP_FRAME_WIDTH Width of the frames in the video stream. 
• CV_CAP_PROP_FRAME_HEIGHT Height of the frames in the video stream. 
• CV_CAP_PROP_FPS Frame rate. 
• CV_CAP_PROP_FOURCC 4-character code of codec. 
• CV_CAP_PROP_FRAME_COUNT Number of frames in the video file. 
• CV_CAP_PROP_FORMAT Format of the Mat objects returned by retrieve() . 
• CV_CAP_PROP_MODE Backend-specific value indicating the current capture mode. 
• CV_CAP_PROP_BRIGHTNESS Brightness of the image (only for cameras). 
• CV_CAP_PROP_CONTRAST Contrast of the image (only for cameras). 
• CV_CAP_PROP_SATURATION Saturation of the image (only for cameras). 
• CV_CAP_PROP_HUE Hue of the image (only for cameras). 
• CV_CAP_PROP_GAIN Gain of the image (only for cameras). 
• CV_CAP_PROP_EXPOSURE Exposure (only for cameras). 
• CV_CAP_PROP_CONVERT_RGB Boolean flags indicating whether images should be converted to RGB. 
• CV_CAP_PROP_WHITE_BALANCE Currently unsupported 
• CV_CAP_PROP_RECTIFICATION Rectification flag for stereo cameras (note: only supported by DC1394 v 2.x backend currently) 
对应的，使用 cap.set(propId,value) 来修改视频属性，value 就是你想要设置成的新值。



2、保存视频

普通的视频格式对应的编码器不一样，这里需要提供编码器。

```python
import numpy as np
import cv2
import sys

cap = cv2.VideoCapture(r'testvideo.rmvb')
#参数为4字节的编码，网站 http://www.fourcc.org/codecs.php
fourcc = cv2.VideoWriter_fourcc(*'MJPG')
#输出文件名字，编码，播放频率，帧的大小（视频的长和宽），是否为彩色，True,False
out = cv2.VideoWriter('output.avi',fourcc,20.0,(int(cap.get(cv2.CAP_PORT_FRAME_WIDTH)),int(cap.get(cv2.CAP_PROT_FRAME_HEIGHT))))
while cap.isOpened():
    ret,frame = cap.read()
    if ret:
        out.write(frame)
        cv2.imshow('frame',frame)
        if cv2.waitKey(1) == ors('q'):
            break
	else:
        break
        
cap.release()
out.release()
cv2.destroyAllWindows()
```



## 3、python API

之前没有介绍到的api,来吧，看看

```python
import cv2
import numpy as np
#获取图像的维度
h,w = img.shape[:2]
#颜色空间的转换，转化为灰度图
gray_img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
RGB_img = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
cv2.imshow('RGB',RGB_img)
#将图片转化为矩阵
array_img = np.array(img)
print(np.asarray(image)[0][0])
print(array_img[0][0])
#图片数据的归一化
norm_img = (array_img/255.0) *2 -1.0
print(norm_img[0][0])
#创建一张图片
create_img = np.zeros((400,400,3),dtype = 'float')
#绘制直线(图片，起始点，终点，颜色)
color = (255,0,0)
cv2.line(create_img,(100,100),(200,200),color)
#绘制矩形
cv2.rectangle(create_img,(100,100),(200,200),color)
#绘制圆形（图片，圆心，半径，颜色）
cv2.circle(create_img,(100,100),100,color)
#调整图片的大小
resize_img = cv2.resize(img,(50,50))
#调整图片为指定比例 插值方法，最临近插值，双线性插值，基于局部图像的插值
resize_img = cv3.resize(img,(0,0),fx=0.5,fy=0.5,interpolation=cv2.INTER_NEAREST)

'''
仿射变换是指在向量空间中进行一次线性变换(乘以一个矩阵)并加上一个平移(加上一个向量)，变换为另一个向量空间的过程。在有限维的情况下，每个仿射变换可以由一个矩阵A和一个向量b给出，它可以写作A和一个附加的列b。一个仿射变换对应于一个矩阵和一个向量的乘法，而仿射变换的复合对应于普通的矩阵乘法，只要加入一个额外的行到矩阵的底下，这一行全部是0除了最右边是一个1，而列向量的底下要加上一个1. 

'''
#旋转图像，首先根据指定的角度获得旋转矩阵，然后仿射图像
center = (img.shape[1]//2,img.shape[0]//2)
#三个参数，原始图像的旋转中心，旋转的角度，缩放系数,计算出旋转矩阵
rotate_matrix = cv2.getRotationMatrix2D(center,90,1)
#对加载图形进行仿射变换操作
rotate_img = cv2.warpAffine(img,rotate_matrix,center)

#剪裁图像
crop_img = img[100:200,100:200]

#填充图像pad区域，上下左右填充像素数量，边界处理方法：复制最边缘元素、以常量扩充边界
pad_img = cv2.copyMakeBorder(img,10,10,10,10,cv2.BORDER_CONSTANT,value=(255,0,0))


# 平移图像 首先指定平移矩阵，然后仿射变换图像
x_shift=50
y_shift=50
trans_size = (img.shape[1]-100, img.shape[0]-100)
trans_matrix = np.float32([[1,0,x_shift],[0,1,y_shift]])
trans_img = cv2.warpAffine(img, trans_matrix, trans_size)
print("平移图像维度：",trans_img.shape)

# 翻转图像 指定图像翻转模式：1 水平翻转 0 垂直翻转 -1 水平垂直翻转
flip_up_down_img = cv2.flip(img, 1)
flip_left_right_img = cv2.flip(img, 0)
flip_hori_vert_img = cv2.flip(img, -1)
--------------------- 

```



不太懂的API

### cv2.dnn.blobFromImage()

要从神经网络中获取正确的预测，首先需要预处理数据。

预处理任务通常包括

1、平均减法  2、按某种因子缩放

dnn模块包含两个功能，可以用于预处理图像并通过预先训练的声读模型为分类做好准备。

- cv2.dnn.blobFromImage
- cv2.dnn.blobFromImages

These two functions perform

1. Mean subtraction
2. Scaling
3. And optionally channel swapping

```python
#数据载入
#blobFromImage 转换数据为四维Blob图片。
cv2.dnn.blobFromImage()
'''
第一个参数，InputArray image，表示输入的图像，可以是opencv的mat数据类型。
第二个参数，scalefactor，执行平均减法后，可以选择按比例缩放图像，1/A,这个参数很重要的，如果训练时，是归一化到0-1之间，那么这个参数就应该为0.00390625f （1/256），否则为1.0
第三个参数，size，应该与训练时的输入图像尺寸保持一致。
第四个参数，mean，这是我们的平均减法值，可以使RGB三元组，从图像的每个通道减去所提供的值。这是我们的这个主要在caffe中用到，caffe中经常会用到训练数据的均值。tf中貌似没有用到均值文件。
第五个参数，swapRB，是否交换图像第1个通道和最后一个通道的顺序。Opencv假设图像处于BGR，交换变为RGB。
第六个参数，crop，如果为true，就是裁剪图像，如果为false，就是等比例放缩图像。
--------------------- 
'''
#加载图像的核心代码

frame = imread("../123.jpg");
inputBlob = blobFromImage(frame, 1/255.F, Size(416, 416), Scalar(), true, false);
net.setInput(inputBlob, "data");
detections = net.forward()

#inputBlob形状（1,3,224,224）
```



## 实战，使用opencv写入视频







# scipy快速入门教程

SciPy是构建在numpy的基础之上的，它提供了许多的操作numpy的数组的函数。SciPy是一款方便、易于使用、专为科学和工程设计的python工具包，它包括了统计、优化、整合以及线性代数模块、傅里叶变换、信号和图像图例，常微分方差的求解等。如果专业做图像处理当然还是建议使用opencv。

```python

from scipy.misc import imread,imsave,imresize
 
if __name__ == "__main__":
    #读取图片
    img = imread("timg.jpg")
    #获取图片的数据类型
    img_type = img.dtype
    print(img_type) #uint8
    #获取图片的大小
    img_shape = img.shape
    print(img_shape) #(310, 493, 3)
    #获取图片的高
    img_height = img_shape[0]
    print(img_height) #310
    #获取图片的宽
    img_width = img_shape[1]
    print(img_width)  #493
    #获取图片的通道数
    img_channel = img_shape[2]
    #通道数为1表示黑白图片，通道数为3表示彩色图片

    #通过改变图片每一个通道的比例来改变图片的色彩
    #将图片R:G:B的比例设置为1:0.9:0.9
    img_tint = img * [1,0.9,0.9]
    #保存图片,观察图片可以发现保存后的图片会有点偏红
    imsave("timg_color.jpg",img_tint)
    #改变图片的大小，将图片的大小设置为500*500
    img_resize = imresize(img,(500,500))
    #保存图片，因为这不是等比例的缩放，可以观察保存的图片会有点变形
    imsave("timg_resize.jpg",img_resize)
    #裁剪图片
    img_incision = img[50:200,100:400]
    imsave("timg_incision.jpg",img_incision)
    #scipy中还提供了scipy.io.loadmat和scipy.io.savemat来读写MATLAB的文件
```

## 计算两个点之间的欧式距离

```python

import numpy as np
from scipy.spatial.distance import pdist,squareform,cdist
 
if __name__=="__main__":
    x1 = np.array([[1,1]])
    x2 = np.array([[4,5]])
    #通过cdist函数，计算两个点之间的距离
    distance = cdist(x1,x2,"euclidean")
    print(distance)#[[ 5.]]
    #创建一个数组，数组的每一行都是一个2维的数组，相当于三个点
    x = np.array([[1,1],[4,5],[7,9]])
    #计算每个行的一个点与本身以及另外两个点的欧式距离
    x_d = squareform(pdist(x,"euclidean"))
    #欧式距离计算公式：sqrt((x1-x2)^2+(y1-y2)^2)
    print(x_d)
    '''
    [[  0.   5.  10.]
     [  5.   0.   5.]
     [ 10.   5.   0.]]
	'''
    >>> import scipy
>>> import numpy as np
>>> a = np.array([(0,1),(2,2),(3,4)])
>>> b = np.array([(1,1),(2,2),(4,6)])

#这样就会导致错误不懂为什么
>>> c = scipy.spatial.distance.cdist(a,b)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: module 'scipy' has no attribute 'spatial'
>>> from scipy.spatial import distance as dist
>>> d = dist.cdist(a,b)
>>> print(d)
[[1.         2.23606798 6.40312424]
 [1.41421356 0.         4.47213595]
 [3.60555128 2.23606798 2.23606798]]
>>> rows = d.min(axis = 1).argsort()
>>> cols = d.argmin(axis = 1)[rows]
# 分别取出最小值的横坐标和纵坐标
>>> print(rows)
[1 0 2]
>>> print(cols)
[1 0 1]
#找出横坐标
>>> q = d.argmin(axis = 1)
>>> print(q)
[0 1 1]


```



```python
代码1：
arecord -D "plughw:1" -f S16_LE -r 16000 -d 3 /home/pi/Desktop/voice.wav

代码2：
# coding: utf-8
import sys 
import json 
import urllib2 
import base64 
import requests
reload(sys) 
sys.setdefaultencoding(“utf-8”)
def get_access_token(): 
url = “https://openapi.baidu.com/oauth/2.0/token” 
body = { 
“grant_type”:”client_credentials”, 
“client_id” :”此处填写自己的client_id”, 
“client_secret”:”此处填写自己的client_secret”, 
}
r = requests.post(url,data=body,verify=True)
respond = json.loads(r.text)
return respond["access_token"]
def yuyinshibie_api(audio_data,token): 
speech_data = base64.b64encode(audio_data).decode(“utf-8”) 
speech_length = len(audio_data) 
post_data = { 
“format” : “wav”, 
“rate” : 16000, 
“channel” : 1, 
“cuid” : “B8-27-EB-BA-24-14”, 
“token” : token, 
“speech” : speech_data, 
“len” : speech_length 
}
url = "http://vop.baidu.com/server_api"
json_data = json.dumps(post_data).encode("utf-8")
json_length = len(json_data)
#print(json_data)

req = urllib2.Request(url, data=json_data)
req.add_header("Content-Type", "application/json")
req.add_header("Content-Length", json_length)

#print("asr start request\n")
resp = urllib2.urlopen(req)
#print("asr finish request\n")
resp = resp.read()
resp_data = json.loads(resp.decode("utf-8"))
if resp_data["err_no"] == 0:
   return resp_data["result"]
else:
    print(resp_data)
    return None
def asr_main(filename,tok): 
try: 
f = open(filename, “rb”) 
audio_data = f.read() 
f.close() 
resp = yuyinshibie_api(audio_data,tok) 
return resp[0] 
except Exception,e: 
print “e:”,e 
return “识别失败”.encode(“utf-8”)

代码3：
# coding: utf-8

import requests
import json
import sys
reload(sys)
sys.setdefaultencoding("utf-8")


def Tuling(words):
    Tuling_API_KEY = "此处填写自己的Turling KEY"

    body = {"key":Tuling_API_KEY,"info":words.encode("utf-8")}

    url = "http://www.tuling123.com/openapi/api"
    r = requests.post(url,data=body,verify=True)

    if r:
        date = json.loads(r.text)
        print date["text"]
        return date["text"]
    else:
        return None


代码4：
# coding: utf-8
import sys 
import urllib2 
import json 
import os 
import yuyinshibie
reload(sys) 
sys.setdefaultencoding(“utf-8”)
def yuyinhecheng_api(tok,tex): 
cuid = “B8-27-EB-BA-24-14” 
spd = “4” 
url = “http://tsn.baidu.com/text2audio?tex=“+tex+”&lan=zh&cuid=”+cuid+”&ctp=1&tok=”+tok+”&per=3” 
#print url 
#response = requests.get(url) 
#date = response.read() 
return url
def tts_main(filename,words,tok): 
voice_date = yuyinhecheng_api(tok,words)
f = open(filename,"wb")
f.write(voice_date)
f.close()


代码5：

# coding: utf-8

import os
import time
import yuyinhecheng
import Turling
import yuyinshibie


tok = yuyinshibie.get_access_token()

switch = True
while switch:
    os.system('sudo arecord -D "plughw:1" -f S16_LE -r 16000 -d 3 /home/pi/Desktop/voice.wav')
    time.sleep(0.5)
    info = yuyinshibie.asr_main("/home/pi/Desktop/voice.wav",tok)
    if '关闭'.encode("utf-8") in info:
        while True:
            os.system('sudo arecord -D "plughw:1" -f S16_LE -r 16000 -d 10 /home/pi/Desktop/voice.wav')
            time.sleep(10)

            info = yuyinshibie.asr_main("/home/pi/Desktop/voice.wav",tok)
            if '开启'.encode("utf-8") in info:
                break

        url = "http://tsn.baidu.com/text2audio?tex=开启成功&lan=zh&cuid=B8-27-EB-BA-24-14&ctp=1&tok="+tok+"&per=3"
        os.system('mpg123 "%s"'%url)


    elif '暂停'.encode("utf-8") in info:
        url = "http://tsn.baidu.com/text2audio?tex=开始暂停&lan=zh&cuid=B8-27-EB-BA-24-14&ctp=1&tok="+tok+"&per=3"
        os.system('mpg123 "%s"'%url)
        time.sleep(10)

        url = "http://tsn.baidu.com/text2audio?tex=暂停结束&lan=zh&cuid=B8-27-EB-BA-24-14&ctp=1&tok="+tok+"&per=3"
        os.system('mpg123 "%s"'%url)
        continue


    else:
        tex = Turling.Tuling(info)
        url = yuyinhecheng.yuyinhecheng_api(tok,tex)
        os.system('mpg123 "%s"'%url)
        time.sleep(0.5)

```



# 激动人心，监控鼠标和键盘

pynput模块: 控制监控鼠标和键盘   

-------------------------------------------------------------------------------



## 1.模块函数

1.模块函数
1.mouse: 包含鼠标类的模块

1.1.class Button:      #鼠标的键值类
    # left(左键), right(右键),middle(中间建),unknown(未知键)

1.2.class Controller: #向系统发送鼠标事件的控制器
    # position:             指针当前的位置
    # move(x, y):         将鼠标移动到指定位置
    # press(button):    按下鼠标键
    # release(button): 释放鼠标键
    # scroll(x, y):         发送滚动事件
    # click(button, count=1): 在当前位置发送点击事件
    # button:              按下的鼠标键
    # count:               点击的次数

1.3.class Listener: 鼠标的监听器
Listener(no_move,on_click,on_scroll):#创建一个监听器
    no_move: #鼠标移动调用的方法(参数: x, y)
    on_click:   #鼠标点击调用的方法(参数: x, y, button, pressed)
    on_scroll: #鼠标滚轮滑动调用的方法(参数: x, y , dx, dy)







## 方法

    run():    #启动监听器
    stop():   # 停止监听器
    wait():   # 等待监听器就绪
    join():    #启动并等待线程停止

===========================================================================

## 2.keyboard: 包含键盘类的模块

2.1.class Key: 键盘的键值类
    # alt(Alt),alt_l(左Alt),alt_r(右),ctrl(Ctrl),ctrl_l(左Ctrl),ctrl_r(右Ctrl),shift(Shift), enter(回车),
    # shift_r(右Shift),space(空格),tab(Tab),caps_lock(大小写),cmd(cmd),backspace(退格),
    # esc(esc),down(下),up(上),left(左),right(右)end(End),delete(Del),home(Home),insert(Ins),
    # page_down(PageDown),page_up(PageUp),scroll_lock(ScrlLock), pause(PauseBreak)
    # ,print_screen(PrintScr.)f1=12(F1=12),menu(menu),num_lock(NumLock)
2.2.class Controller: 向系统发送键盘事件的控制器
    # press(key):        按下某个键
    # key:                   按下的键
    # release(key):     释放某个键
    # pressed(*args): 使下边的按键均同时按下此键(可以用with打开)
    # type(str):           将字符串发送
2.3.class Listener: 键盘的监听器
Listener(on_press, on_release): 创建一个监听器
    on_press:    #按下某个键时调用的方法(参数为key)
    on_release: #释放某个键时调用的方法(参数为key)




```python

1.类键盘监听实现
 
"""1.作者：tcy 写于上海叶榭。2018/8/30
   2.用途：实时监听键盘，可用来启停程序，键盘中断。
           如输入stop停止事件，输入start开始运行。
   3.平台：window7 python3.7 PyCharm模拟。
   4.技术说明：用程序和类分别包装。建议用类
               监听部分有暂停键盘监听，恢复监听，销毁监听；
               暂停后可以恢复，但销毁后不能再恢复"""
 
from pynput import keyboard
#双向队列
from collections import deque
import threading,time
 
#处理字符串类
class KeyboardStr():
    '''1.接收键盘监听取得的字符串，处理带有shift切换的键，如输入！，大写字符；
       2.要取得可打印的字符串，默认数量最多10个，用t.a.get_print_chars获取；
       3.t.a.get_print_chars获取最多100个任意字符和非打印字符（以代码命名）'''
 
    def __init__(self):
        # super(KeyboardStr, self).__init__()
        # 获取字符串变量
        self.shift_press_flag=False
        self.get_print_chars = deque()  # 获取键盘字符串以回车结束
        self.get_all_chars = deque()    # 获取键盘所有字符串，含非打印字符以回车结束
        self.__get_print_chars = deque()
        self.__get_all_chars = deque()
 
        self.__shift_up_chars = {
            '0': ')', '1': '!', '2': '@', '3': '#', '4': '$', '5': '%', '6': '^', '7': '&',
            '8': '*', '9': '(', '10': '_', '11': '+', '12': '~', '13': '{', '14': '}',
            '15': ':', '16': '"', '17': '|', '18': '<', '19': '>', '20': '?'}
        self.__shift_down_key_chars = {
            "0": "0", "1": "1", "2": "2", "3": "3", "4": "4", "5": "5", "6": "6", "7": "7",
            "8": "8", "9": "9", "10": "-", "11": "=", "12": "`", "13": "[", "14": "]",
            "15": ";", "16": "'", "17": "'\'", "18": ",", "19": ".", "20": "/"}
 
    # 处理键盘上下键 大小写问题
    def __get_combination_key_char(self,key_char:str):
        new_char=''
        is_up_down_key_char = key_char in self.__shift_down_key_chars.values()
        if key_char.__len__()==1:
            if key_char.isalpha() and self.shift_press_flag:
                new_char=key_char.upper()
            elif is_up_down_key_char and self.shift_press_flag:
                index_name = [k for k, v in self.__shift_down_key_chars.items() if v == key_char]
                new_char=self.__shift_up_chars[index_name[0]]
            else:
                new_char=key_char
            return  new_char
        else:
            return None
 
    '''获取回车确认前10个可打印键盘字符；回车后显示；'''
 
    def GetPrintChars(self, key_char:str,GetstrNumber=10):
        if  key_char.__len__()==1:
            new_char = self.__get_combination_key_char(key_char)
            self.__get_print_chars.append(new_char)
 
            while self.__get_print_chars.__len__() > GetstrNumber:
                self.__get_print_chars.popleft()
 
        if key_char=='Key.enter':
            self.get_print_chars = self.__get_print_chars.copy()
            self.__get_print_chars.clear()
            print('GetPrintCharStr===>%s\n' % self.get_print_chars)
 
    '''获取回车确认前100个所有字符，含非打印字符'''
 
    def GetAllChars(self, key_char, GetstrNumber=100):
        self.__get_all_chars.append(key_char)
        while self.__get_all_chars.__len__() > GetstrNumber:
            self.__get_all_chars.popleft()
        if key_char == 'Key.enter':
            self.get_all_chars = self.__get_all_chars.copy()
            self.__get_all_chars.clear()
            print('GetAllCharStr===>%s\n' % self.get_all_chars)
#********************************************************************************
class KeyboardClass(threading.Thread,KeyboardStr):
    '''1.用途：实时监听键盘事件，能暂停，恢复，销毁。
       2.测试：测试部分有2个，一个测试键盘监听，一个测试字符串处理。'''
    def __init__(self):
        super(KeyboardClass, self).__init__()
        KeyboardStr.__init__(self)
 
        #键盘监听变量
        self.run_flag = True
        self.pause_flag = True
        self.listener = keyboard.Listener()
 
        self.a=KeyboardStr()
 
    def __GetOneChar(self, key):
        return key.char if isinstance(key, keyboard.KeyCode) else str(key)
    
    def on_press(self,key):
        key_char = self.__GetOneChar(key)
        try:
            if key_char=='Key.shift':
                self.a.shift_press_flag=True
                # print('alphanumeric key {0} pressed'.format(key_char))
        except AttributeError:
            key_char=None
            print('special key {0} pressed'.format(key_char))
        finally:
            print('Alphanumeric key = 【{0}】 pressed...'.format(key_char))
 
 
    def on_release(self,key):
        key_char = self.__GetOneChar(key)
        if key_char == 'Key.shift':
            self.a.shift_press_flag = False
 
        self.a.GetPrintChars(key_char)
        self.a.GetAllChars(key_char)
        # print('{0} released'.format(key))
        if not self.run_flag:#key == keyboard.Key.esc:
            return False# Stop listener
 
    def keyboard_pause(self):
        self.listener.stop()
        self.pause_flag=False
 
    def keyboard_resume(self):
        self.pause_flag=True
 
    def keyboard_destroy(self):
        self.pause_flag=True
        self.run_flag=False
        self.listener.stop()
 
    def run(self):
        while self.run_flag:
            with keyboard.Listener(on_press=self.on_press,
                                    on_release=self.on_release) as self.listener:
                if self.pause_flag:
                    self.listener.join()
 
#键盘字符处理测试程序
def test_str():
    t=KeyboardClass()
    t.start()
 
    print('1.start run...................................')
    while 1:
        print('2.可打印字符串===》',t.a.get_print_chars)
        print('3.所有字符串===》',t.a.get_all_chars)
        time.sleep(2)
 
#键盘监听测试程序
def test_keyboard_listen():
    t = KeyboardClass()
    t.start()
 
    print('1.1.start run...................................',time.ctime())
    time.sleep(5)
    print('1.2.start run stop..............................', time.ctime())
 
    print('2.1.start pause..................................', time.ctime())
    t.keyboard_pause()
    time.sleep(5)
    print('2.2.end pause.....................................%s\n'% (time.ctime()))
    print('3.1.keyboard listener resume......................%s\n'% (time.ctime()))
    t.keyboard_resume()
    time.sleep(5)
    print('3.2.stop resume.stoping.............................%s\n'% (time.ctime()))
    print('4.1.start destroy...................................%s\n'% (time.ctime()))
    t.keyboard_destroy()
    time.sleep(1)
    print('4.2.end destroy......................................%s\n'%( time.ctime()))
    time.sleep(1)
    print('5.all program end.exit....')
 
# test_str()
test_keyboard_listen()
#-------------------------------------------------------------------------------------------------------
#第一步分测试显示如下：随机显示内容，视你的按下什么键
# 1.start run...................................
# 2.可打印字符串===》 deque([])
# 3.所有字符串===》 deque([])
'''没有按键盘字符'''
# Alphanumeric key = 【a】 pressed...
# Alphanumeric key = 【s】 pressed...
# Alphanumeric key = 【Key.shift】 pressed...
# as2.可打印字符串===》 deque([])
# 3.所有字符串===》 deque([])
'''按下回车后显示结果'''
# Alphanumeric key = 【Key.enter】 pressed...
# GetPrintCharStr===>deque(['a', 's'])
# GetAllCharStr===>deque(['a', 's', 'Key.shift', 'Key.enter'])
# dAlphanumeric key = 【d】 pressed...
# 2.可打印字符串===》 deque(['a', 's'])
# 3.所有字符串===》 deque(['a', 's', 'Key.shift', 'Key.enter'])
# Alphanumeric key = 【Key.enter】 pressed...
#
# GetPrintCharStr===>deque(['d'])
#
# GetAllCharStr===>deque(['d', 'Key.enter'])
#
# 2.可打印字符串===》 deque(['d'])
# 3.所有字符串===》 deque(['d', 'Key.enter'])
# Alphanumeric key = 【Key.shift】 pressed...
# Alphanumeric key = 【1】 pressed...
# Alphanumeric key = 【2】 pressed...
# Alphanumeric key = 【3】 pressed...
# 2.可打印字符串===》 deque(['d'])
# 3.所有字符串===》 deque(['d', 'Key.enter'])
# $Alphanumeric key = 【4】 pressed...
# Alphanumeric key = 【5】 pressed...
# %
# Alphanumeric key = 【Key.enter】 pressed...
# GetPrintCharStr===>deque(['!', '@', '#', '$', '%'])
#
# GetAllCharStr===>deque(['1', '2', '3', '4', '5', 'Key.shift', 'Key.enter'])
 
# GetAllCharStr===>deque(['h', 'h', 'h', 'Key.space', 'Key.shift', 'Key.shift_r', 'Key.delete', 'Key.end', 'Key.page_down', 'Key.insert', 'Key.home', 'Key.page_up', 'Key.down', 'Key.right', 'Key.up', 'Key.left', 'Key.down', '2', '0', 'Key.enter'])
#
# 2.可打印字符串===》 deque(['h', 'h', 'h', '2', '0'])
# 3.所有字符串===》 deque(['h', 'h', 'h', 'Key.space', 'Key.shift', 'Key.shift_r', 'Key.delete', 'Key.end', 'Key.page_down', 'Key.insert', 'Key.home', 'Key.page_up', 'Key.down', 'Key.right', 'Key.up', 'Key.left', 'Key.down', '2', '0', 'Key.enter'])
#************************************************************************************************
#第二部分监听测试结果：
# C:\python37\python.exe C:/Users/Administrator/.PyCharmCE2018.2/config/scratches/tmp.py
# 1.1.start run................................... Thu Aug 30 00:45:29 2018
# dAlphanumeric key = 【d】 pressed...
#  Alphanumeric key = 【Key.space】 pressed...
# fAlphanumeric key = 【f】 pressed...
#
# Alphanumeric key = 【Key.enter】 pressed...
# GetPrintCharStr===>deque(['d', 'f'])
#
# GetAllCharStr===>deque(['d', 'Key.space', 'f', 'Key.enter'])
#
# dAlphanumeric key = 【d】 pressed...
# gAlphanumeric key = 【g】 pressed...
# 1.2.start run stop.............................. Thu Aug 30 00:45:34 2018
# 2.1.start pause.................................. Thu Aug 30 00:45:34 2018
#
# fffffff2.2.end pause.....................................Thu Aug 30 00:45:39 2018
#
# 3.1.keyboard listener resume......................Thu Aug 30 00:45:39 2018
#
# Alphanumeric key = 【s】 pressed...
# sfAlphanumeric key = 【f】 pressed...
# Alphanumeric key = 【Key.enter】 pressed...
# GetPrintCharStr===>deque(['d', 'g', 's', 'f'])
#
# GetAllCharStr===>deque(['d', 'g', 's', 'f', 'Key.enter'])
#
# Alphanumeric key = 【Key.space】 pressed...
# Alphanumeric key = 【f】 pressed...
# Alphanumeric key = 【Key.enter】 pressed...
# GetPrintCharStr===>deque(['f'])
#
# GetAllCharStr===>deque(['Key.space', 'f', 'Key.enter'])
#
# 3.2.stop resume.stoping.............................Thu Aug 30 00:45:44 2018
#
# 4.1.start destroy...................................Thu Aug 30 00:45:44 2018
#
# 4.2.end destroy......................................Thu Aug 30 00:45:45 2018
# 
# 5.all program end.exit....
#
# Process finished with exit code 0

```



```python
2.函数监听
from pynput import keyboard
import threading,time
listener=keyboard.Listener()
 
run_flag=True
pause_flag=True
def on_press(key):
    key_char = key.char if isinstance(key, keyboard.KeyCode) else str(key)
    try:
        print('alphanumeric key {0} pressed'.format(
            key_char))
    except AttributeError:
        print('special key {0} pressed'.format(
            key))
 
def on_release(key):
    global  run_flag
    # print('{0} released'.format(
    #     key))
    # print('thread----------=',threading.activeCount(),threading.current_thread().name)
    if not run_flag:#key == keyboard.Key.esc:
        # Stop listener
        return False
 
def keyboard_pause(listen=listener):
    global pause_flag
    listen.stop()
    pause_flag=False
def keyboard_resume(listen=listener):
    global pause_flag
    pause_flag=True
    # listen.run()
def keyboard_stop(listen=listener):
    global run_flag,pause_flag
    pause_flag=True
    run_flag=False
def run():
    global listener,run_flag,pause_flag
    while run_flag:
        with keyboard.Listener(
                on_press=on_press,
                on_release=on_release) as listener:
            if pause_flag:
                listener.join()
    #     print('end22222222222222222222')
 
t = threading.Thread(target=run)
t.start()
 
 
print('1.start run.....---------------------11--------------------')
time.sleep(5)
print('1.end run.....---------------------12--------------------')
print('2.start pause.....-------------------21--------------------')
keyboard_pause(listen=listener)
time.sleep(5)
print('2.end pause.....-------------------22--------------------')
print('3.start run.....---------------------31-------------------')
keyboard_resume()
time.sleep(5)
print('3.end run.....---------------------32-------------------')
print('4.start stop.....----------------------41-----------------------------')
keyboard_stop()
time.sleep(1)
print('4.end stop.....----------------------------42---------------------------')
time.sleep(1)
print('5.all end.....----------------------------5---------------------------')
 
# C:\python37\python.exe C:/Users/Administrator/.PyCharmCE2018.2/config/scratches/keboardok1.py
# 1.start run.....---------------------11--------------------
 
# falphanumeric key f pressed
#  alphanumeric key Key.space pressed
# falphanumeric key f pressed
# 1.end run.....---------------------12--------------------
# 2.start pause.....-------------------21--------------------
# hhddddgghhjhjj2.end pause.....-------------------22--------------------
# 3.start run.....---------------------31-------------------
# talphanumeric key t pressed
# talphanumeric key t pressed
# talphanumeric key t pressed
#  alphanumeric key Key.space pressed
# alphanumeric key f pressed
# ffalphanumeric key f pressed
# 3.end run.....---------------------32-------------------
# 4.start stop.....----------------------41-----------------------------
#  alphanumeric key Key.space pressed
# f4.end stop.....----------------------------42---------------------------
# ff5.all end.....----------------------------5---------------------------
# 
# Process finished with exit code 0
--------------------- 

```

