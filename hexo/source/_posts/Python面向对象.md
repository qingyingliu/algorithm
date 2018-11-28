---
title: '''Python面向对象'''
date: 2018-11-29 00:21:00
categories: Python
---

### 定义类

在Python中，类的定义使用class关键字来实现，语法如下：

```python
class ClassName:
    "类的帮助信息"  # 类文档的字符串
    statement   # 类体
```

### 创建类的实例

创建类的实例的语法如下：

`variable = ClassName(parameterlist)`

其中variable是实例对象，parameterlist是参数列表。当创建一个类时，会自动调用__init__()方法。`__init__`()方法，除了self参数外，还可以自定义一些参数，参数间使用都好分割。比如：

```python
class Geese:
    "大雁类"

    def __init__(self):
        print("我是大雁类")

wildGeese = Geese()
```

输出结果为：

`我是大雁类`

注意： `__init__`方法的第一个参数必须时self。

### 创建类的成员并访问

#### 创建类的实例方法并访问
实例的第一个方法必须是self，语法格式如下：

```python
    def functionName(self,parameterlist):
    block
```

实例方法完成后，通过类的实例方法和点操作符进行访问。语法格式如下：

`instanceName.fucntionName(parameterlist)`

值得注意的是，在创建实例方法时，也可以和创建函数一样为参数设置默认值，但是被设置了默认值的参数必须位于所有参数的最后（即最右侧）。

#### 创建数据成员并访问

根据属性，可以分为两种类型：类属性和实例属性。

- 类属性类似于C++或者Java的静态变量，该类的所有实例都可以访问，是大家共享的，可以通过实例或者类名来访问。
- 而实例属性则值能通过实例访问。

比如：

```python
class Geese:

    # neck和wing是类属性
    neck = "脖子比较长"
    wing = "振翅频率高"

    def __init__(self,name):
        self.name = name    #实例属性
```

### 访问属性
在Python中也是需要区分private、protected和public数据的，这是通过变量的名称来确定的。

- 首尾双下划线表示定义特殊的方法，**一般是系统定义的名字**。
- 以单下划线开头的表示保护类型(protected)类型成员，值能允许类本身和子类进行访问
- 双下划线表示私有成员(private)类型成员的数据，只允许定义该方法的类本身进行访问，而不能通过类的实例进行访问。
  
比如：
```python
class Swan:
    "天鹅类"

    _neck_swan = '天鹅的脖子很长'
    def __init__(self):
        print("__init__() ",_neck_swan)
    
swan = Swan
print('直接访问: ',swan._neck_swan)
```

可以发现，上面的运行程序没有错误，说明保护属性可以通过实例名访问。

### 属性
这里介绍的属性指的是特殊的属性，通过`@property`(装饰器)的声明。可以把一个方法转换成一个属性。例如：

```python
class Circle:
    del __init(self,r):
        this.r = r
    
    @property
    def area(self):
        return self.r*self.r*3.14;

circle = Circle(1)
print(circle.area)
```

可以看出，通过装饰器的声明，我们可以不用加括号地访问它的值。但是。通过@property转换过的值不能重新赋值，否则会出错。

``` python
# 不能这样子
circle.area = 3.14
```

通过属性不仅可以将属性设置为只读，而且还可以为属性设置拦截器，即让属性允许修改，但是需要满足一定的约束。例如：

```python
class TVshow:
    list_film = ['战狼二','红海行动','西游记女儿国','熊出没']
    def __init__(self,show):
        self.__show = show

    @property
    def show(self):
        return self.__show

    @show.setter
    def show(self,value):
        if value in TVshow.list_film:
            self.__show = '您选择了《' + value + "》,稍后将播放"
        else:
            self.__show = '你选择的电影不存在'

tvshow = TVshow('战狼二')
print('正在播放: ',tvshow.show)
# 不能修改，因为红海行动不在列表中
tvshow.show = '红海行动'
print(tvshow.show)
```

### 继承
