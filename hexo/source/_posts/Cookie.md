---
layout: post
title: Cookie
date: 2018-11-10 13:48:14
categories: Java Web
---
在页面之间传递数据的过程中，Cookie是一种常见的方法。Cookie是一个小小的文本数据，由服务端生成，发送给客户端浏览器。如果浏览器设置为启动Cookie，则会将这个小文本数据保存在某个目录下的文本文件内。一般情况下，Cookie中的值是由key-value的形式进行表达的。下面介绍Cookie的常用方法：
respond.addCookie(Cookie e),通过这种方法，将Cookie写入客户端
Cookie.setMaxAge(int second),通过这种方法，设置Cookie的存活时间，参数是秒数。
Cookie[]request.getCookies(),读取客户端传过来的Cookie，以数组的形式返回。

<!--more-->
常见的应用之一就是，对于一些安全性要求不高的网站上，可以使用它来记住账号和密码。主要分为两个步骤：
1. 添加cookie
```java
//定义cookie
Cookie userNameCookie = new Cookie("userName", name);
Cookie passwordCookie = new Cookie("password", password);

//设置cookie的有效时间
userNameCookie.setMaxAge(600);
passwordCookie.setMaxAge(600);

//写入cookie对象
response.addCookie(userNameCookie);
response.addCookie(passwordCookie);

```

2. 读取cookie
```java
//获取cookie对象
Cookie[] cookies = request.getCookies();
if (null != cookies && cookies.length > 0) {
	//遍历Cookies
	for (Cookie c : cookies) {
		if ("userName".equals(c.getName())) {
			//为了防止读取到的cookie值为乱码，
			//将cookie的值使用URLDecoder.decode(String str, String encoding)进行转码
			userName1 = URLDecoder.decode(c.getValue(), "UTF-8");
		} else if ("password".equals(c.getName())) {
			password1 = URLDecoder.decode(c.getValue(), "UTF-8");
		}
	}
}
```

效果图：
一打开登陆界面就有账号和密码，无需用户输入
![](/uploads/cookieExample.png)