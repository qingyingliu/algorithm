---
layout: post
title: Form development
date: 2018-10-26 20:03:20
categories: Java Web
description: 表单开发
---
表单时用户和服务器之间进行信息交互的重要手段，是一种由用户输入并提交给服务器的一个图形界面。
#### 一、 表单提交给服务器。
使用action属性来确定提交的页面。
例如
``` html
<form action="page.jsp">
	请你输入账号:<input name="account" type="text"><br>
	请你输入密码：<input name="password" type="password"><br>
	<input type="submit" value="登陆">
</form>
```
表示表单输入的内容提交给page.jsp去运行。

#### 二、 在服务器中获取接受表单的数据
获取提交过来的值，使用**request对象**。通过**name属性**来获得提交过来的值。分为以下两种类型获取数据元素：
##### 获取单一元素数据
由于获取的元素只是一个元素，所以只需要一个变量来储存即可。
```java
  String res=request.getParameter(name);
```
**注意**： 获取的数据必须是String类型。如果是其他元素的类型，需要用类型转换来转换。
比如获取上面的表单的account和password：
```java
  //因为账号输入的input的name属性为"account"，所以传入的参数为"account"
  String account=request.getParameter("account");
  String password=request.getParameter("password");
```

##### 获取捆绑表单元素的数据
捆绑表单元素指的是**多个同名元素的值传给服务器端的时，是一个捆绑的数组**。这种情况的表单元素有复选框、多选列表框、同名表单等等。
获取数据的方法如下：
```java
  String []str=request.getParameterValues(name)
```

比如在`choose.html`中定义一个选择爱好的表单，然后把表单发送给`result.jsp`
```html
 <form action="result.jsp" method="post">
    <input type="checkbox" name="hobby" value="sing">唱歌
    <input type="checkbox" name="hobby" value="dance">跳舞
    <input type="checkbox" name="hobby" value="ball">打球
    <input type="checkbox" name="hobby" value="game">打游戏
    <input type="submit"  value="Submit">
    </form>
```

![](/uploads/form_1.jpg)
提交表单之后，我们使用`String []str=request.getParameterValues(name)`的方法来获取表单的值
```java
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<%
	try{
	String []str=request.getParameterValues("hobby");
		for(int i=0;i<str.length;i++){
			out.print(str[i]+"<br>");
		}
	}catch(Exception e){
		out.print("no hobby");
	}
%>
```
选择唱歌和跳舞后的运行结果：
![](/uploads/form1_result.png)

#### 三、 隐藏表单技术
这种方法可以实现值的传递，而且无法看到传递的信息。
实现的方法：
1. 将input的type改为"hidden"
2. 将form的method改为"post"

**注意**： 对于秘密性要求很严格的数据（如密码），不推荐使用表单的方法传值。

#### 四、 中文乱码问题
1. 首先需要将JSP页面设置为`UTF-8`的字符集
`<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>`
2. 需要将request的内容设置为`UTF-8`的字符集
`request.setCharacterEncoding("utf8");`
3. 需要将response的内容设置为`UTF-8`
`response.setContentType("text/html;charset=utf8");`

通过学习后面的知识后，我们可以使用Servlet的Filter来对多个页面进行设置字符集，这样就不用分别在每一个页面都添加上面三行代码了。