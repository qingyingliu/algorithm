---
layout: post
title: static factory methods
date: 2018-10-27 00:35:13
categories: Java
---
这一篇博客介绍的是**Effective Java**中的**static factory method**来代替构造器，我将会介绍什么是静态工厂方法以及它和构造函数相比有什么优势。在介绍的过程中，相信读者也会领悟到static factory method的好处。
<!-- more -->

## 什么是static factory method
首先，我们先了解什么是static factory method。在**Effective Java**中，它是这样介绍的:
*A class can provide a public static factory method, which is simply a static method that returns an instance of the class.*
也就是说，通过static factory method, 我们可以得到一个类的实例，这不就是我们的构造函数的功能吗？这也是为什么我在上文说用静态工厂来代替构造函数。
下面先看一个static factory method的例子：
```java
    Fragment fragment = MyFragment.newIntance();
    // or 
    Calendar calendar = Calendar.getInstance();
    // or 
    Integer number = Integer.valueOf("3");
```

## static factory method的优点
### 他们有名字
有名字有什么好处？当然有好处，好处就是让用户能够一看就知道相应的参数是什么，因为如果构造函数很多的话，用户肯定是记不住相应的参数的意义的，这就需要去查找相关的文档。下面看一个例子：
如果使用构造函数
```java
    class Vehicle{
		int speed,weight,seat-number;
		Vehicle(int speed){
			this.speed=speed;
		}
		/*
		这段代码不能这样写，因为构造函数是通过参数的数据类型来区分的，
		如果这样写就和第一个构造函数一样了，会出错
		Vehicle(int weight){
			this.weight=weight;
		}
		*/
		Vehicle(int weight,int seat-number){
			this.weight=weight;
			this.seat-number=seat-number;
		}
	}
```
如果使用static factory method来构造：
```java
	class Vehicle{
		public static Vehicle getVehicleWithSpeed(int speed){
			Vehicle vehicle=new Vehicle();
			vehicle.speed=speed;
			return vehicle;
		}
		public static Vehicle getVehicleWithWeight(int weight){
			Vehicle vehicle=new Vehicle();
			vehicle.weight=weight;
			return vehicle;
		}
		public static Vehicle getVehicleWithWeightAndSeatnum(int weight,int seat-number){
			Vehicle vehicle=getVehicleWithWeight(weight);
			vehicle.seat-number=seat-number;
			return vehicle;
		}
	}
```
### 不必每次都创建新的实例
下面这个例子就很好地解释了这个技巧（其实自己在这一点上理解地不够深，所以先知道有这么一个技巧，以后再更新）
```java
    public static Boolean valueOf(boolean b){
		return b?Boolean.TRUE:Boolean.FALSE;
	}
```
### 可以返回当前对象类型和所有子类类型
这个特点和多态的特性很是类似，这就使得在返回类型上有很大的灵活性。比如
```java
	class Person{
		public static getInstance(){
			return new Person();
		}
	}
```
### 可以减少对外暴露的属性
比如有这样的一个类
```java
class Player{
	public static final int TYPE_RUNNER=1;
	public static final int TYPE_SWIMMER=2;
	public static final int TYPE_RACER=3;
	protected int type;
	public static Player(int type){
		this.type=type;
	}
}
```
当调用的时候，期望的调用方法如下:
```java
    Player player1 = new Player(Player.TYPE_RUNNER);
    Player player2 = new Player(Player.TYPE_SWEIMMER);
```
但是，提供者无法控制调用者的行为，所以就很可能会出现这种情况：
```java
    Player player3 = new Player(0);
    Player player4 = new Player(-1);
    Player player5 = new Player(10086);
```
提供者期望的构造函数传入的值是事先定义好的几个常量之一，但如果不是，就很容易导致程序错误。
这个时候使用static factory method的方法就显得特别好：
```java
// Player : Version 2
class Player {
    public static final int TYPE_RUNNER = 1;
    public static final int TYPE_SWIMMER = 2;
    public static final int TYPE_RACER = 3;
    int type;

    private Player(int type) {
        this.type = type;
    }

    public static Player newRunner() {
        return new Player(TYPE_RUNNER);
    }
    public static Player newSwimmer() {
        return new Player(TYPE_SWIMMER);
    }
    public static Player newRacer() {
        return new Player(TYPE_RACER);
    }
}
```

## 总结
简而言之，静态工厂方法和公有构造器都各有用处，我们需要理解它们各自的长处。静态工 厂通常更加合适，因此切忌第一反应就是提供公有的构造器，而不先考虑静态工厂。

## Reference
1. **Effective Java**
2. [关于 Java 的静态工厂方法，看这一篇就够了！](https://www.diycode.cc/topics/1027)
