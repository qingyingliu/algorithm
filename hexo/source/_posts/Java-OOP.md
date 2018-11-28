---
layout: post
title: Java 面向对象编程
date: 2018-10-27 13:26:37
categories: Java
---
## Object
在我们的现实生活中，对象无处不在。那对象到底是什么？我觉得，**对象是一种模拟现实世界中的实体(entity)的计算机的表示方法**。比如，我们可以抽象出Vehicle，它有height和weight属性，有run和speedup方法，这不就是模拟我们现实世界中的Vehicle吗？
对象有以下特点：
<!-- more -->
1. **Everything is an object.** Think of an object as a fancy variable; it stores data, but you can “make requests” to that object, asking it to perform operations on itself. In theory, you can take any conceptual component in the problem you’re trying to solve (dogs, buildings, services, etc.) and represent it as an object in your program.  
2. **A program is a bunch of objects telling each other what to do by sending messages.** To make a request of an object, you “send a message” to that object. More concretely, you can think of a message as a request to call a method that belongs to a particular object. 
3. **Each object has its own memory made up of other objects.** Put another way, you create a new kind of object by making a package containing existing objects. Thus, you can build complexity into a program while hiding it behind the simplicity of objects.  
4. **Every object has a type**. Using the parlance, each object is an instance of a class, in which “class” is synonymous with “type.” The most important distinguishing characteristic of a class is “What messages can you send to it?”  
5. **All objects of a particular type can receive the same messages.** This is actually a loaded statement, as you will see later. Because an object of type “circle” is also an object of type “shape,” a circle is guaranteed to accept shape messages. This means you can write code that talks to shapes and automatically handle anything that fits the description of a shape. This substitutability is one of the powerful concepts in OOP.
## Inheritance
继承是子类可以拥有父类的属性和方法一种机制。
语法:
`<modifier> class <name> extends <superclass>{  <declaration*>  } `
在子类中：
- 继承父类的数据（所有的数据都会继承，但是不一定能够访问）和方法
- 但是不继承父类的构造函数
- 可以添加子类的新特性：添加数据，添加方法和重写方法(polymorphism)
- 使用super调用**父类**（但是不能调用祖先的方法）的方法，也包括构造函数。注意，**当调用父类的构造函数的时候，必须把构造父类的构造函数放在第一句**，否则eclipse会报错：`Constructor must be the first statement in a constructor`。这是因为在构造的时候，先构造父类再构造子类。
下面看一个例子：

```java

public class Father {
	int height,age;
	Father(){}
	Father(int height,int age){
		this.height=height;
		this.age=age;
	}
}

```
```java

public class Son extends Father {
	String name;	//add data
	Son(){}
	Son(int height,int age,String name){
		super(height,age);	//call super constructor
		this.name=name;
		//Constructor must be the first statement in a constructor
		//super(height,age);
	}
	void newFunction() {
		//we can add new method that super class doesn't have
	}
}
```
前面已经说过，子类会继承所有父类的数据。但是有些数据是不可以访问的，下面这张图给出了访问权限的规则：
![](/uploads/JavaAccess.png)

## polymophism
Polymorhism: the ability to have many different forms
### override method
覆盖方法： 覆盖父类相同名字的方法。在Java中，所有的类默认继承Object类，Obeject类中有一个toString方法。我们可以override toString：
```java
public  class Employee{
	protected String name; 
	protected double salary; 
	protected Date birthDate; public Employee( … ){ // … } 
	public String toString(){ 
		return “Name: “+name+” Salary: ”+salary+” B. Date:”+birthDate;
	} 
}
```
这个时候如果我们调用Employee的toString方法，就不再是默认的Object的toString方法了。
那这个时候如果我们想要在Employee类中调用Object类的toString方法怎么办？——使用super调用父类的方法。
注意： **Overridden Methods Cannot Be Less Accessible**。比如：
```java
public  class Parent{ 
	public void foo(){}
} 
public class Child extends Parent{
	private void foo(){} //illegal 
}
```

### Heterogeneous Array
```java
 Employee emps[] = new Employee[ 100 ]; 
 emps[ 0 ] = new Employee();
 emps[ 1 ] = new Manager(); 
 emps[ 2 ] = new Employee(); 
 // … // print employees 
 for( Employee e: emps ){ 
	 System.out.println( e.toString() ); 
  } // count managers
 int counter = 0; 
 for( Employee e: emps ){ 
	 if( e instanceof Manager ){ 
		 ++counter; 
	 } 
 }
```

### 多态使得引用具有动态类型
比如：
```java
Employee e;	// static (compile time) type is: Employee
 e = new Employee(); 	//dynamic (run time) type is: Employee 
 e=new Manager();	// dynamic (run time) type is: Manager
```

注意： 父类的引用不能直接访问子类的新的方法或者数据。比如：
```java
 Employee emps[] = new Employee[ 100 ]; 
 emps[ 0 ] = new Employee();
 emps[ 1 ] = new Manager(); 
 emps[ 2 ] = new Employee(); 
 
 //Error
 //System.out.println(emps[1].department); 	
 
 //Solution
 System.out.println(((Manager) emps[1]).department);
 
 //Better solution
 if( emps[1] instanceof Manager ){ 
	 System.out.println( ((Manager) emps[1]).department );
} 
```

### instanceof 运算符
instanceof用于判断对象是否是属于指定类的实例。
注意：一个类的实例包括本身的实例,**以及所有直接或间接子类的实例**。
例如：
```java
 Employee e=new Employee();
 Manager m=new Manager();
 Employee e1=new Manager();
 
 System.out.println(e instanceof Employee);
 System.out.println(e instanceof Manager);
 
 System.out.println(m instanceof Employee);
 System.out.println(m instanceof Manager);
 
 System.out.println(e1 instanceof Employee);
 System.out.println(e1 instanceof Manager);
```
注意：instanceof只能用于对象，不能用于基础数据类型，比如int,float,double等等。比如u:
```java
int a=10;
System.out.println(a instanceof Integer);
```
会报错：`incompatible conditional oprand type int and Integer`

### overloading methods
重载也是多态的一种表现形式。重载的要求有：
- methods having the same name
- argument list must differ
比如，

```java
public void println(int i);
public void println(float f);
public void println(String s);
```

## Methods Common to All Objects
我们知道，所有的类都是直接或者间接继承Object类的。在Object中有三种通用的方法。
- The equals method 
- The  toString method 
- The clone method
这样设计的目的是为了以后的拓展。
### equals method
比如在String类中就有这个equals方法。equals一般是判断内容（逻辑上）是否相等(object logical equality)，而`==`一般是判断引用是否相同。
比如：

```java
String a="abc";
String b="abc";
System.out.println(a==b);
System.out.println(a.equals(b));
```
a和b都是"abc"的引用，所以第一个输出true,a和b的内容都是"abc"所以第二个也是输出true.
再看下面一个例子：

```java
String a="abc";
String b=new String("abc");
System.out.println(a==b);
System.out.println(a.equals(b));
```
a是"abc"的引用，b new了一个新的"abc"（可以理解成地址不同),所以第一句会输出false.
但是a和b的内容都还是"abc"，所以第二句输出true

拓展:
原来，程序在运行的时候会创建一个**字符串缓冲池**当使用 a="abc" 这样的表达是创建字符串的时候，程序首先会在这个String缓冲池中寻找相同值的对象，在第一个程序中，a先被放到了池中，所以在b被创建的时候，程序找到了具有相同值的b，b引用a所引用的对象"abc"

### toString method
作用：
- Converts an object to a String 
- Override this method to provide information about a user-defined object in readable format
一般来说，对于我们自定义类，我们需要override toString方法从而实现更友好的表达类的信息。

### clone method
clone的机制类似于equals方法，赋值一个内容相等的对象。
而`=`和clone不同，`=`赋值一个引用以供外部操作。
clone的示意图:
![](/uploads/clone.png)
`=`的示意图
![](/uploads/=.png)

## Summary
在Java的理念中，就是把所有的东西都看成对象。首先我们要知道对象和对象的理念，然后掌握面向对象的特定：继承和多态。最后还介绍了Java中所有类都是Object的子类，介绍了三种Object的一般方法。