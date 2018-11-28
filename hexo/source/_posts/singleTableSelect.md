---
layout: post
title: 单表查询
date: 2018-10-17 08:59:28
categories: data-base
---
SELECT 语句的基本语法
```
SELECT 目标列名序列    //需要哪些列
	FROM 数据源		//出自哪些表
	WHERE 检索条件表达式     //根据什么条件
	GROUP BY 组提取条件     //根据什么分组
	HAVING 组提取条件      //组内的数据满足什么条件
	ORDER BY 排序依据列	  //根据什么排序
```
<!-- more -->

### 去重
用DISTINCT关键字去掉重复行，它的位置在SELECT之后。
例如，我们查询Student中的所有不重复学生：
`SELECT DISTINCT * FROM student`

### 空值的查询
注意：空值的查询不能使用`= NULL`，而是要用`IS NULL`.
比如，查询所有缺少成绩的学生：
`SELECT * FROM STUDENT WHERE Sscore IS NULL`

### 排序
对查询结果进行排序，以方便用户观察或进一步处理。排序是使用ORDER BY子句，在ORDER BY后面加上依据的排序列，而且并且指明升序还是降序。默认是升序。升序：ASC，降序：DESC。
例如：
查询Student中的所有学生，按照学号升序排序：
`SELECT DISTINCT * FROM Student ORDER BY Sid ASC;`

### LIKE通配符
语法格式如下：
`[NOT] LIKE <匹配串> [ESCAPE 换码字符]`
通配符：
- `%`代表任意长度（可以为0）的字符串。例如a%b可以以a开头以b结尾的字符串，acb，addgb，ab都满足该匹配串。
- `_`代表单个字符。例如a_b可以表示a开头，b结尾的长度为3的任意字符串，acb，afb都满足该字符串。
例如：
- 查询所有姓李的学生：
`select distinct * from student where Sname LIKE '李%'`
- 查询姓"欧阳"且全名为三个汉字的学生的姓名：`select Sname from Student where Sname Like '欧阳_'`
- 如果用户要查询的字符串本身就含有通配符%或者_，这时候就要使用`ESCAPE 转义字符`短语对通配符进行转义了。
比如查询DB_Design课程的课程学号：
`select Cid from Course where Cname LIKE 'DB\_Design' ESCAPE '\';`

### 聚集函数
SQL中有一些用于统计的函数，例如求最大值、最小值、平均值等。这些函数是**针对某一列**进行统计，所以叫列函数，也称为聚合函数或者聚集函数。常见的聚集函数如下：
- 求某一列的最大值 MAX();
- 求某一列的最小值 MIN();
- 求某一列的和 SUM();
- 求某一列的平均值 AVG();
- 求某一列值的个数 COUNT();
例如：
- 查询雇员表Emple中员工的最低工资，并且列名用“最低工资”表示。
  `SELECT MIN(Salary) AS '最低工资' FROM Emple`
- 查询雇员表Emple中的所有员工的总元素，并用列名“员工总数”表示。
  `SELECT SUM(*) AS '员工总人数' FROM Emple`
  
### 分组查询
分组查询，即先分组再查询，先使用GROUP BY关键字对表中的数据进行分组，然后在每一个组内部再进行相应的查询。
例如：
- 分别统计雇员表Emple中各部门员工的工资总额，并且列名分别用“部门编号“及“各部门工资总额”表示。
  `SELECT Dno AS '部门编号', SUM(Salary) AS '各部门工资总额' FROM Emple GROUP BY Dno`
