---
layout: post
title: JSP basic syntax
date: 2018-10-19 14:24:26
categories: Java Web
---

## Part 1: 使用myEclipse建立第一个JSP页面
1. 打开myEclipse，建立web项目,建立好了之后，在项目的WebRoot下有一个index.jsp，可以先将其删除。
2. 新建JSP页面，在WebRoot文件夹中右击，在弹出的菜单中选中New|JSP，新建JSP页面,然后再编辑JSP页面即可。
<!-- more -->
![](/uploads/JSP1.1.jpg)

注意：你新建的JSP网页打开之后可能会中文乱码，那是因为page指令上的初始编码为：`ISO-8859-1`

## Part 2: 几种注释
1. HTML注释：`<!---注释内容-->`,这是HTML的注释方式，在客户端可以接收到HTML注释的内容。
2. JSP注释语法： `<%--注释内容--%>`，在JSP注释里面的内容不会被编译，更不会执行，所以这部分的内容不会被发送到客户端。
3. JAVA注释：`//注释内容`表示单行注释，`/*注释内容*/`表示多行注释。
例如：
![](/uploads/JSP1.2.png)
发送到客户端的源代码为：
![](/uploads/JSP1.3.png)

所以，HTML注释会发送到客户端，而JAVA和JSP注释则不会发送到客户端。

## Part 3: JSP表达式
表达式基本语法定义如下：
`<%=变量/返回值/表达式%>`
**JSP表达式的作用是将其里面的内容所运算的结果输出到客户端。**
如：`<%=msg%>`是JSP表达式，意思是将msg内容输出到客户端。等价于`<%out.print(msg);%>`
例如：
![](/uploads/JSP1.4.png)
运行效果：
![](/uploads/JSP1.5.png)

## Part 4: JSP程序段
在Part 3中，介绍了JSP表达式。但是JSP表达式只能单行出现。如果需要在JSP程序中既要输出数据，也要定义变量等一系列复杂的逻辑操作，表达式是不能够满足要求的，这之后就需要JSP程序段。实际上，**JSP程序段就是插入到JSP程序的JAVA代码段，在网页的任何地方都可以插入JSP程序段。**JSP的用法如下：
`<% Java代码 %>`
JSP中可以嵌入HTML，也可以放入JSP程序段和JSP表达式。他们可以灵活地配合使用。
例如：
```
<%@ page language="java" import="java.util.*" pageEncoding="UTF8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<title>mixPage</title>
</head>
<body>
	<%
		for(int i=1;i<=10;i++){
	%>
	<%=i%>欢迎来到本系统<br>
	<% 
		}
	%>
</body>
</html>
```
运行效果为:
![](/uploads/JSP1.6.png)

## Part 5: JSP声明
**在JSP程序段中**，变量必须要先定义，后使用，但是在JSP声明中，JSP的声明可以在网页的任何地方定义变量，因为JSP声明中定义的变量是网页级别的，会优先执行。在实际的应用中，方法，页面全局变量甚至类的声明都可以放在JSP声明部分。
JSP声明的使用方法如下:
`<%! 代码 %>`
注意点：
- JSP声明和JSP程序段不同，可以在网页的任何地方定义变量。但是JSP程序段却只能先定义变量后使用。
- JSP声明中只能定义变量，不能做其他控制逻辑操作。
- 每条声明后面需要加分号

例如：
![](/uploads/JSP1.7.png)
在JSP声明中定义了str变量之后，可以在声明前使用，也可以在声明后使用str变量。
但是如果在JSP声明中使用了控制逻辑操作，MyEclipse就会报错（上图第十六行)

## Part 6: JSP指令
JSP包含三个指令：page、include、taglib
a. 导入包
`<%@ import ="包名.类名"%>`
当导入多个包时，可以写多条类似于上面的语句，也可以用一个import，然后每个导入的包用逗号分开。
`<%@ import="包名.类名1,包名.类名2">`
例如，我们要得到当前时间的时候，需要导入Date类。
![](/uploads/JSP1.8.png)
运行结果为:
![](/uploads/JSP1.9.png)

b. 设定字符集。pageEncoding属性可以设置页面的字符集。常见的编码方式有gb2812,GBK,utf8等等。
`<%@ page pageEncoding="编码类型">`
之前的例子都是用utf8编码的。

c. 设定错误页面。
一般情况下，我们可以将异常现象在一个统一的网页中显示。因此此处就要用到errorPage和isErrorPage属性。
errorPage指令的作用是制定一个网页，当JSP出现没有被捕获的异常时，就跳转到那个指定页面。通常情况下，跳转到的页面需要设定isErrorPage来指明处理其他页面的错误信息。
例如：
![](/uploads/JSP1.10.png)
![](/uploads/JSP1.11.png)
运行结果:
![](/uploads/JSP1.12.png)
d. include指令。include指令可以在JSP程序中插入多个外部文件，这些文件可以JSP,HTML,JAVA,甚至是文本。编译时，include指令就会把相应的文件包含进入主文件。
语法格式如下：
`<%@ include file="文件名">`

例如：
![](/uploads/JSP1.15.png)
![](/uploads/JSP1.14.png)

运行效果：
![](/uploads/JSP1.13.png)