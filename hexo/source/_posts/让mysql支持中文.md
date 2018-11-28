---
layout: post
title: 让mysql支持中文
date: 2018-11-18 16:43:02
categories: Java Web
---
#### 在`/etc/mysql/ mysql.cnf`后添加下面的代码:
```
[client]
default-character-set=utf8

[mysqld]
character_set_server=utf8
```
<!--more-->
#### 修改编码格式
- 修改数据库的编码格式:
```
alter database <数据库名> character set 'utf8';
```
- 修改表格的字符编码：
```
alter table <表名> character set 'utf8';
```
- 修改列的字符编码
```
ALTER TABLE tbl_name CHANGE c_name c_name CHARACTER SET character_name [COLLATE ...];
```
#### 查看编码格式

- 查看数据库编码：
```
SHOW CREATE DATABASE db_name;
```
- 查看表编码：
```
SHOW CREATE TABLE tbl_name;
```
- 查看字段编码：
```
SHOW FULL COLUMNS FROM tbl_name;
```