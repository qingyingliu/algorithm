---
layout: post
title: Collections and Generics
date: 2018-11-10 18:33:49
categories: Java
---
# Collection

在我们编程的时候，我们难免会遇到处理一些集合的问题，在我们的Java中，Collection API就是为了处理集合类问题的API。
Collections API方便了Java程序猿去使用一些高效的数据类型和算法，比如list,tree，hashtable等等，减少了代码量，同时也是易于拓展，简单使用。

<!--more-->

首先我们先看一下Collections的结构
![Collection结构](/uploads/CollectionAPI.png)
其中Set接口和List接口继承了Collection接口，然后Set和List接口分别衍生出子类。值得注意的是，我们不可以直接使用接口，而应该是使用它的子类。所以，接下来我准备分别讲解ArrayList, LinkedList, HashSet 和 TreeSet，并区分他们的不同和使用情况。

## Collection方法

- `int size()`

    返回collection中元素的个数。如果collectoin元素的个数大于`Integer.MAX_VALUE`，则返回`Integer.MAX_VALUE`

- `boolean isEmpty()`

    如果collection含有元素则返回true，否则返回false

- `boolean contains(Object o)`

    如果collection包含特定的元素o则返回true，否则返回false

- `iterator<E> interator()`

    返回一个在collection上的迭代器。

- `boolean add(E e)`

    添加一个元素e。如果collection不允许有多个内容相同的元素且已经存在了元素e，则返回false。
    即，如果调用add函数，导致了collection发生了变化，则返回true，否则返回false。

- `boolean remove(E e)`

    删除一个元素e。如果调用remove函数，导致了collection发生了变化，则返回true，否则返回false。

- `boolean containsAll(Collection<?> c)`

    如果当前集合包含了集合c中的所有元素，则返回true，否则返回false。

- `boolean addAll(Collection<? extends E> c)`

    并集操作。如果操作成功返回true。

- `boolean removeAll(Collection<?> c)`

    差集操作。如果操作成功返回true。

- `boolean retainAll(Collection<?> c)`

    交集操作。如果操作成功返回true。

## ArrayList

原型：

``` java
public class ArrayList<E>
extends AbstractList<E>
implements List<E>, RandomAccess, Cloneable, Serializable
```

特点：

- 它是一种可变容量大小(Resizable)的数组

- 它是非同步化的(unsynchronized)，除了这一点，其它的都和vector一样。

- 相比Collection添加的方法：
  - `public E get(int i)`: 返回第i个元素的实例。
  - `public E set(int i, E var2)`：将第i个元素设置为var2

例如：

```java
package collection;

import java.util.ArrayList;

public class ArrayListExample {

	public static void main(String[] args) {
	
		//定义一个ArrayList
		ArrayList<Integer> a = new ArrayList<Integer>();
		
		//添加元素
		for(int i=0;i<10;i++) {
			a.add(i);
		}
		
		//通过set(i)来修改第i个元素的值
		a.set(2, 100);
		
		//通过get(i)来获取第i个元素
		for(int i=0;i<a.size();i++) {
			System.out.println(a.get(i));
		}
	}

}
```

## LinkedList

原型： 

```java
public class LinkedList<E>
extends AbstractSequentialList<E>
implements List<E>, Deque<E>, Cloneable, Serializable
```

特点：

- 和ArrayList一样，它也是非同步化的(unsynchronized)

- 因为它的实现是双向链表的方式，所以更加适合于插入和删除的操作。

- 函数：
  - 它和ArrayList一样也有get和set方法。
  - addFirst(E e), push(E e)
  - addLast(E e)
  - getFirst(), peek(), peekFirst()
  - getLast(), peekLast()

## HashSet

原型： 

```java
public class HashSet<E>
extends AbstractSet<E>
implements Set<E>, Cloneable, Serializable
```

特点：

- 它也是非同步化的(unsynchronized)
- 它不保证元素的顺序性
- 注意元素的相同是根据equals函数来判断的，所以如果是自己定义的类，需要重写equals和hashCode方法，因为默认的equals是根据地址比较的。

```java
package collection;

import java.util.HashSet;

class MyClass{
	int v;
	MyClass(){
	
	}
	MyClass(int var){
		this.v=var;
	}
}

public class HashSetExample {

	public static void main(String[] args) {
		HashSet<MyClass> hashSet = new HashSet<MyClass>();
		
		for(int i=0;i<10;i++) {
			hashSet.add(new MyClass(i));
		}
		
		hashSet.add(new MyClass(5));
		//输出是11，因为没有重写equals方法和hashCode方法且new的两个MyClass(5)的地址不同
		System.out.println(hashSet.size());
	}
}
```

加入equals方法和hashCode方法后
```java
package collection;

import java.util.HashSet;

class MyClass{
	int v;
	MyClass(int var){
		this.v=var;
	}
	public boolean equals(Object obj) {
		MyClass obj1 = (MyClass)obj;
		return this.v==obj1.v;
	}
	
	public int hashCode() {
		return this.v;
	}
}
public class HashSetExample {

	public static void main(String[] args) {

		HashSet<MyClass> hashSet = new HashSet<MyClass>();
		
		//添加数据
		for(int i=0;i<10;i++) {
			hashSet.add(new MyClass(i));
		}
	
		hashSet.add(new MyClass(5));
	    //输出是10
		System.out.println(hashSet.size());
	}
}
```

## TreeSet

  TreeSet的方法和HashSet的方法类似，但是内部实现不同。TreeSet的内部实现是红黑树。所以查询，插入，删除都是O(log(n))的时间复杂度。
同样值得注意的是，如果使用的泛型参数是自定义类型，则需要重写equals和hashCode方法。
  由于TreeSet还涉及到排序的问题，所以如果是自定义的类，还需要继承Comparable接口，重写CompareTo函数。

# Map

map和collection不同，它是以key-value的形式的数据类型。
接口和实现类如下：
![map](/uploads/mapExample.png)
其中HashMap和TreeMap和HashSet、TreeSet的实现方法一样。

还需值得强调的是，自定义的类需要重写：equals,hashCode方法。
如果是含有排序的功能，还需implements Comparable。

# Collection遍历的方法

## for-each方法

![for-each](/uploads/for-each.png)

## iterator方法

![iterator](/uploads/iteratorExample.png)

## Stream的遍历方法

Stream遍历的方法是Java 8的新特性，具体用法可以参考这篇文章[Java 8th 新特性：流式数据处理](https://my.oschina.net/wangzhenchao/blog/754726)

# Map遍历的方法

map遍历的方法可以转化成Collection遍历的方法。
其中map的键对集合为entrySet()，键的集合为keySet(),值的集合为values()。
然后再根据Collection遍历的方法可以对entrySet()，entrySet()，values()集合进行遍历。