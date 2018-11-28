---
layout: post
title: python语法特点
date: 2018-11-23 00:11:51
categories: Python
---
这篇文章主要介绍python的一些语法特点和习惯，包括注释，

### 注释
注释的作用就是对代码的解释和说明，让他人了解代码实现的功能，从而帮助程序猿更好地阅读代码。注释的内容python将不会执行，因此也可以用于临时不想执行的代码。

#### 单行注释
在python中，使用`#`作为单行注释的符号。从符号`#`开始直到换行为止，`#`所有的内容都作为注释的内容，并被编译器忽略。

<!--more-->
语法如下：
`#注释内容`

单行注释可以被放在要注释的前一行，也可以放在要注释代码的右侧。
例如：
```python
#这是一种风格的单行注释
print('one type of annotation')

print('another type of annotation') #另外一种注释风格
```
#### 多行注释
在python中，并没有一个单独的多行注释标记，而是将包含在一对三引号(`'''注释内容'''`)或者(`"""注释内容"""`)之间。
语法如下：
```python
'''
注释内容1
注释内容2
'''
```
或者
```python
"""
注释内容1
注释内容2
"""
```
#### 中文编码声明注释
在python中，还提供了一种特殊的中文字符编码声明注释，该注释的出现是为了支持有些python(python2.x)中文不支持中文的问题。
语法如下：
```python
# _*_ coding: 编码_*_
```
或者
```python
# coding = 编码
```

### 代码缩进
python不像其他的程序设计语言(如C，Java)采用大括号`{}`分隔代码块，**而是采用缩进和冒号区分代码之间的层次。**
注意： 通常情况下1个tab键等价于4个空格，建议使用4个空格来表示一个缩进而不是使用tab。
例如：
```python
# 缩进示例

bmi = float(input())
#判断身材是否合理
if bmi < 18.5:
    print('体重过轻')
elif bmi >= 18.5 and bmi <24.9:
    print("正常范围")
else:
    print("overweight")

```
python对代码的缩进要求非常严格，同一个级别的代码块的缩进量必须相同，否则将会抛出SyntaxError的异常。

### 代码规范

1. 每个import语句只导入一个模块，尽量避免一次导入多个模块。
  比如，推荐写法为：
```python
import os
import sys
```
  而不推荐
```
import os,sys
```

2. 不要在每行尾加分号，也不要用分号将两条命令放在同一行。
3.  建议每行不超过80个字符，如果超过，建议使用小括号`()`将多行内容隐式的连接起来，而不推荐使用反斜杠`\`进行连接。
  比如，推荐的写法为：
```python
s=('aaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaa')
```
  而不推荐
```python
s='aaaaaaaaaaaaaaaaaaaaaaa\
aaaaaaaaaaaaaaaaaaa'
```
4. 使用必要的空行可以增加代码的可读性。一般在顶级定义（如函数或者类的定义）之间空两行，而方法定义之间空一行。另外，在用于分割某些功能的位置也可以空一行
5. 运算符，函数参数之间两侧建议使用空格分割。

### 命名规范
1. 模块名尽量短小，并且全部使用小写字母，可以使用下划线分割多个字母。
2. 包名尽量短小，并且全部使用小写字母，不推荐使用下划线。比如不建议使用`com_mingrisoft`而建议使用`com.mingrisoft`
3. 类名采用首字母大写的形式。比如`BookBorrow`
4. 函数，类的属性和方法的命名规则同模块类似，也是全部使用小写字母，使用下划线分割多个字母。
5. 常量命名时全部使用大写字母，可以使用下划线。
6. 使用单下划线`_`开头的模块变量或者函数是受保护的。
7. 使用双下划线`__`开头的实例变量或方法是类私有的。

### 保留字
保留字是python中一些已经被赋予特定意义的单词。开发程序时，不可以把这些保留字作为变量，类，函数，模块和其他对象的名称来使用。
python保留字可以如下查询：
```python
import keyboard
print(keyboard.kwlist)
```
输出的结果为
```
['False', 'None', 'True', 'and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 'else', 'except',
'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 'lambda', 'nonlocal', 'not', 'or', 'pass', 'raise',
'return', 'try', 'while', 'with', 'yield']
```
### 标识符
标识符可以简单地理解为一个名字，比如每个人都有自己的名字，它主要用来表示变量，函数，模块和其他对象的名称。
python语言标识符的命名规则如下：
- 由字母、数字和下划线组成，且第一个字母不能使数字
- 不能使python的保留字
  
例如下面是合法的标识符
```
UESERID
name1
_id
```
下面是非法的标识符
```
4word
try
$money
```

### 变量
在Python中，不需要先声明变量名和它的类型，可以直接赋值即可创建各种类型的变量。
这里有几点需要注意的
- Python是一种动态类型的语言，也就是说，变量的类型是可以变化的。我们可以通过type内置函数查看变量类型
- 虽然变量的类型可以变化，而且地址也会变化。（其实就是重新生成了一个新的变量）

例如：
```python
# string类型的变量
test = 'string'
print(type(test))
print(id(test))

# test的类型变成int
test = 1
print(type(test))
print(id(test))
```
输出的结果为
```
<class 'str'>
55757024
<class 'int'>
1355211376
```
  
### 基本数据类型
#### 数字类型
数字类型包括整数，浮点数和复数。注意这里的浮点数只有一种：`float`。
更加强大的是，Python的数字的位数的任意的，当超过计算机自身的计算功能时，会自动专用高精度计算。
比如：
```python
int_number = 10
float_number = 1e100
complex_numer = 55+2j

print(int_number)
print(float_number)
print(complex_numer)
```
输出结果：
```
10
1e+100
(55+2j)
```
其中1e100表示10的100次方。

#### 字符串类型
字符串其实就是一串字符。我们可以用一对引号(`'字符串内容'`)或者(`"字符串内容"`)表示单行字符串。
如果我们需要表示多行字符串，我们可以用一对三引号来表示(`'''字符串内容'''`)或者(`"""字符串内容"""`)
例如
```python
str1 = 'test1'
str2 = "test2"
str3 = '''test
3'''
str4 = """test
4
"""
print('编译成功，字符串定义没有问题')
```

#### 布尔类型
布尔类型主要用来判断真假，真为1，假为0
比如：
```python
flag = True
if not flag:
    print('假')
else:
    print('真')
```

### 运算符
运算符可以通过变量之间的运算得到一个新的结果，返回给变量。其中加减乘除和求余数就不多介绍了。这里主要介绍功能比较强大的整除和求幂。
整除：`//`，比如:`8//3=2`，得到的是一个商的整数部分。而`8/3`得到的浮点数除法的结果。
```python
print(8//3)
print(8/3)
```
运行结果
```
2
2.6666666666666665
```
幂：`**`，比如`2**4`，即2的四次方，结果为16

### 基本输入输出
在Python中，使用内置函数input()可以接受用户的键盘输入。input的用法如下：
`variable = input('提示文字')`
这里值得注意的是，input返回的类型是字符串类型，如果我们需要读入其他类型的数据，比如数字，我们需要使用类型转换函数，比如int()。
例如：
```python
variable = float(input('请输入一个数字\n'))
print(str(variable)+'的平方为'+str(variable**2))
```
默认情况下，我们可以使用print函数将一行字符串输出。注意，默认情况下print输出完之后会换行。
如果我们想一次性输出多个内容，则需要把这些变量用逗号分隔。
例如：
```python
str1 = 'str1'
str2 = 'str2'

print(str1)
print(str1,str2)
```
输出结果为：
```
str1
str1 str2
```
如果不想变量之间输出空格，则可以使用字符串的`+`把它们连接起来输出：print(str1+str2)
