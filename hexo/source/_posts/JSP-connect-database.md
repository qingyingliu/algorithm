---
layout: post
title: JSP connect database
date: 2018-11-10 11:24:58
categories: Java Web
---
#### JDBC简介
在Java技术中，访问数据库的技术叫做JDBC，它提供了一系列的API，让Java语言编写的代码连接数据库，对数据库进行添加、删除、修改和查询。
JDBC相关的API存在java.sql包中。主要包括以下类或者接口：
- java.sql.Connection: 负责数据库的连接
- java.sql.Statement, 负责执行SQL语句
- java.sql.ResultSet, 负责存放查询结果

<!--more-->

由于JSP不知道具体连接的是哪一种数据库，而各种数据库产品，由于厂商不一样，连接的方式也不一样。所以这里给出了解决方案：
JDBC提供了“驱动程序”的概念，即对于不同的数据库，使用不同的驱动即可。

#### JDBC操作
1. 指定驱动(以SQL Server数据库为例)
`Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");`

2. 获取连接：
```java
Connection conn=DriverManager.getConnection(
	"url=?;databaseName=?;user=?;password=?");
```

3. 使用statement接口运行SQL语句
```java
Statement stat=conn.createStatement();
//执行SQL语句
stat.execute(sql);
//SQL查询
stat.executeQuery(sql);
```

4. 执行SQL语句
5. 关闭数据库
```java
stat.close();
conn.close();
```

#### SQL查询
这里之所以需要单独讲解SQL查询，是因为它和其他SQL操作不同。
首先它返回的是一个查询的结果ResultSet
```java
ResultSet rs = stat.executeQuery(sql)
```
这个时候结果就已经放在了rs变量中了。
其次我们可以把rs理解成一个指针，通过rs.next()来移动指针。
rs初始指向第一行的前一行，所以如果要访问第一行，需要先执行rs.next()，然后再通过rs.getString()来获取第一行的值。
如果有多行，可以通过while循环来获取
```java
while(rs.next()){
	String stuno = rs.getString("STUNO");
	String stuname=rs.getString("STUNAME");
	out.println(stuno+" "+stuname+"<br>");
}
```
注意： getString()也可以来获取第i列的值:`getString(i)`

#### 使用PreparedStatement
PreparedStatement是Statement的子接口，功能和Statement类似，只是使用?来代替了需要插入的参数。
```java
String sql="INSERT INTO STUDENT VALUES(STUNO,STUNAME,STUSEX) VALUES(?,?,?)";
PrepareStatement ps = conn.prepareStatement(sql);
ps.setString(1,studno);
ps.setString(2,stuname);
ps.setString(3.stusex);
```

#### 事务
在银行转账时，要对数据库进行两个操作，即一个账户的前减少，将另一个账户的钱增多。但是由于操作的先后顺序，如果在两个操作之间发生故障，则会导致数据不一致，因为我们需要一个事务，**是在两条语句都被执行成功后，数据才真正的被放入数据库，否则操作回滚(rollback)**

```java
try{
	//设置不要自动提交
	conn.setAutuCommit(false);
	stat.execute(sql1);
	stat.execute(sql2);
	//提交以上操作
	conn.commit();
}catch(Exception e){
	conn.rollback();
}finally{
	conn.close();
}
```