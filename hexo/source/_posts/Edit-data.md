---
layout: post
title: SQL Server edit data
date: 2018-10-11 15:13:47
categories: data-base
description: 编辑数据包括插入、删除、更新数据。
---
SQL编辑数据包括插入、删除、更新数据。
<!-- more -->
## Insert语句的基本语法
`INSERT	INTO 表名 （列名列表） VALUES (值列表)`

例如，我们向STUDENT表添加计算机系学生李志，学号2017150000，性别男，年龄20。
`INSERT INTO STUDENT VALUES('2017150000','李志','男',20,'计算机系')`；
我们也可以这样写:
`INSERT INTO STUDENT(Sdep,Sname,Sno,Sage) VALUES('计算机系','李志','2017150000',20)`

## Update语句的基本语法
```
UPDATE 表名 SET
	列名1=表达式1，
	列名2=表达式2，
	...
	列名n=表达式n
	WHERE 更新条件
```

例如，我们把所有的学生的年龄加一岁。
`UPDATE STUDENT SET Sage=Sage+1`
我们把信息系改成信管系：
`UPDATE STUDENT SET Sdep='信管系' WHERE Sdep='信息系'`

## 删除记录语句DELETE
`DELETE FROM 表名 WHERE 删除条件`

例如，删除计算机系20岁以上的学生：
`DELETE FROM STUDENT WHERE Sdep='计算机系' AND Sage>20`

删除性别为空的学生：
`DELETE FROM STUDENT WHERE Ssex IS NULL`