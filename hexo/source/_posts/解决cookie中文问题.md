---
layout: post
title: 解决在Java Web中的cookie不支持中文的问题
date: 2018-11-18 16:43:02
categories: Java Web
---
今天在写一个登陆界面的时候，需要使用记住密码的功能，把网页部署到服务器后，发现在使用中文账号进行登陆时候进行记住密码的时候会出错。在查阅了一些资料之后，找到了解决方法。

1. 把保存到cookie的值的编码改成utf-8。
```java
//进行转编码
String userName1=URLEncoder.encode(userName,"UTF-8");
String password1=URLEncoder.encode(password,"UTF-8");
```

<!--more-->

2. 然后把cookie保存。
```java
//定义cookie
Cookie userNameCookie = new Cookie("userName", userName1);
Cookie passwordCookie = new Cookie("password", password1);

//设置cookie的有效时间
userNameCookie.setMaxAge(600);
passwordCookie.setMaxAge(600);

//写入cookie对象
response.addCookie(userNameCookie);
response.addCookie(passwordCookie);
```

3. 在取出cookie的时候，遍历每一个cookie。
   注意： 取出的cookie的时候需要进行解码。
```java
//获取cookie对象
Cookie[] cookies = request.getCookies();
if (null != cookies && cookies.length > 0) {
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