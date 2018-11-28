---
layout: post
title: 数据定义语言DDL的使用
date: 2018-10-10 10:31:26
categories: data-base
description: sql的基本数据类型和创建表、修改表、删除表的语句
---
这篇博客主要介绍sql的基本数据类型和创建表、修改表、删除表的语句。
<!-- more -->
## 数据类型
1. 数值型： INT,BIGINT,DECIMAL,FLOAT
2. 字符串型: CHAR,NCHAR,VARCHAR,NVARCHAR
3. 日期时间类型： DATETIME
4. 货币类型： MONEY

## 创建表语句
```
ALTER TABLER<表名>
(<列名><数据类型>[<列级完整性约束条件>]
[,<列名><数据类型>[<列级完整性约束条件>])]...
[<表级完整性约束条件>];
```

例如，创建一个学生关系Student可以这样写：
```
CREATE TABLE Student (
	Sno CHAR(9) PRIMARY KEY, /*列级完整性约束条件，Sno是主码*/
	Sname char(20) UNIQUE,   /*列级完整性约束条件，Sname是唯一的*/
	Ssex char(2),
	Sage SMALLINT,
	Sdep char(20)
);
```

创建一个Course关系可以这样写
```
CREATE TABLE Course (
	Cno char(4) PRIMARY KEY,
	Cname char(40) NOT NULL, /*列级完整性约束条件，Cname不能取空值*/
	Cpno Char(4), /*Cpno是指先修课程*/
	Ccredit smallint,
	FOREIGN KEY (Cpno) REFERENCES Course (Cno) /*表级完整性约束条件，Cpo是外码，被参照的表示Course，被参照列是Cno*/
)
```

## 修改表语句
```
ALTER TABLE <表名>
[ADD <新列名><数据类型>[完整性约束]]
[DROP COLUMN <列名>]
[ALTER COLUMN <列名><数据类型>]
[ADD CONSTRAINT<完整性约束名>];
[DROP CONSTRAINT<完整性约束名>];
```
**注意：ADD不用加column关键字，drop和alter都需要加column关键字**
例如，在学生关系中添加一个“入学时间列”，其数据类型为日期型：
```
ALTER TABLE Student
	ADD S_entrance DATE;
```

将学生关系中的Sage由字符型的数据类型改成SMALLINT：
```
ALTER TABLE Student
	ALTER COLUMN Sage SMALLINT
```
## 删除表语句
```
DROP TABLE <表名>
```
注意，如果当前要删除的表名被其他表引用，那么则需要先删除这个引用。
SQL Server似乎不支持`DROP TABLE <表名> CASCADE>`，这点注意一下。