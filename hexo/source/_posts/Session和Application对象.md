---
layout: post
title: Session和Application对象
date: 2018-11-10 14:05:42
categories: Java Web
---
#### session
在我们的实际开发中，难免会遇到需要登陆的功能，但是我们需要思考如何去保持在多个页面下的用户的登录状态。在Java Web中，Session是一个很好的解决方案，它的特点就是**跨页面保持**。
1. 在sesion中添加对象： `session.setAttribute(String name,Object obj)`
2. 获取session对象: `Object session.getAttribute(String name)`
3. 移除session的内容: `session.removeAttribute(String name)`
4. 移除session的全部内容: `session.invalidate()`
<!--more-->
比如当用户登陆成功的时候，我们就储存它的用户名(用户名唯一):
```java
session.setAttribute("user", name);
```
当用户注销的时候，我们移除session中的user
```java
session.removeAttribute("user");
```
注意：
- 如果获取session的内容的时候是返回Object类，所以可能需要强制转换
- 如果两次调用setAttribute且name相同，则后面放进去的内容会覆盖以前放进去的内容
- 如果调用getAttribute的name不存在，则返回null。通过这个特性，我们可以判断是否是null来判断用户是否登陆。

#### application
对于一个Web容器而言，所有的用户都共同使用一个application对象，服务器启动后，就会自动创建application对象，这个对象会一直保存，直到服务器关闭。
1. 将内容放入application。
``` java 
void application.setAttribute(String name,Object obj);
```
2. 读取application中的内容。
```java
Object application.getAttribute(String name);
```
3. 将内容从application中移除。
```java
void application.removeAttribute(String name);
```

比如，我们可以统计访问网页的次数。
```html
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>

<!DOCTYPE HTML>
<html>
  <head>
    <title>count visitor</title>

  </head>
  
  <body>
   <%
   	Integer count = (Integer)application.getAttribute("count");
   	if(count==null){
   		count = new Integer(0);
   	}
   	count++;
   	application.setAttribute("count", count);
   %>
   
   你是第<%=count %>个访问者。
  </body>
</html>
```
效果：
![](/uploads/applicationExample.png)
当然，application的应用还有很多，比如列出在线人数等等。
