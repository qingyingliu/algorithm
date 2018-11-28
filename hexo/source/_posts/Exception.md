---
layout: post
title: Exception
date: 2018-11-05 17:55:13
categories: Java
---
异常时程序中的一些错误，但是不是所有的错误都是异常。
### try-catch语句捕捉异常
```java
try{   
	// critical code block   
	// code that might throw exceptions 
	} catch( MyException1 e1 ){
		// code to execute if a MyException1 is thrown 
	} catch( MyException2 e2 ){ 
		// code to execute if a MyException1 is thrown 
	} catch ( Exception e3 ){ 
		// code to execute if any other exception is thrown 
	}finally{
		code that will always be executed
	}
	
}
```
<!--more-->
注意：
- 如果在一个函数中的异常没有处理，那么它就会抛出给它的调用者
- 如果异常回到了主函数而且没有被处理，那么程序就会终止了

### Exception类型
![](/uploads/exceptionCategories.jpg)

### 自定义异常
throws： throws是方法可能抛出异常的声明。(用在声明方法时，表示该方法可能要抛出异常)
throw: throw表示动作，表示抛出异常。
**在Java中要想创建自定义异常，需要继承Throwable或者他的子类Exception。**

例如自定义一个DangerException
```java
public class DangerException extends Exception{

	private static final long serialVersionUID = 1L;

	public DangerException(Goods obj) {
		System.out.println(obj.toShow());
	}

}
```

检查是否需要抛出异常
```java
void checkBag(Goods goods) throws DangerException{
	if(goods.isDanger) {
		throw new DangerException(goods);
	}
}
```

捕捉异常
```java
try {
	machine.checkBag(goods[i]);
}catch(DangerException e) {
	System.out.println("处理危险物品中...");
}
```
