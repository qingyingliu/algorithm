---
layout: post
title: mysql远程连接
date: 2018-11-16 11:41:25
categories: data-base
---
最近在尝试将实验室的电脑当做自己的服务器，发现不能够远程实验室的mysql。于是在查阅了一番资料之后，写此博客来记录解决办法。

#### 检查3306端口是否开启
`netstat -an|grep 3306`
一般来说这个端口都是打开的。但是服务器的就不一定了，服务器的解决方法请看最下面的注意点。
![port](/uploads/portCheck.png)

<!--more-->

#### 打开mysql配置文件
将bind-address = 127.0.0.1注销​，即把它这一句给注释掉。

`sudo vim /etc/mysql/mysql.conf.d/mysqld.cnf`

![bind-add](/uploads/bind-add.jpg)

#### 修改mysql用户的host
先查看mysql用户的host

```
use mysql;
select user,host from user;
```
然后将用户的host由本地改成%

`update user set host = '%' where user = 'root'`

然后更新权限
`flush privileges;`

![](/uploads/host-add.png)

#### 重启服务器
```
sudo service mysql restart
sudo service mysql start
```

#### 连接成功
![success](/uploads/mysqlConnectSuccess.png)

#### 注意点
注意： 如果远程的是阿里云的服务器（我的就是），我们必须在服务器的控制端去关闭防火墙。在防火墙的选项中添加规则。
![](/uploads/example3.png)