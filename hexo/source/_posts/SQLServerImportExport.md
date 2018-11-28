---
layout: post
title: SQL Server import/export to Excel
date: 2018-10-11 00:30:38
categories: data-base
description: 用SQL Server把数据导入和导出Excel。
---
本篇博客介绍的是用SQL Server把数据导入和导出Excel。
## SQL Server导入EXCEL数据
1. 右键点击数据库名，选择Tasks
![step1](/uploads/SQLServerImport1.jpg)
2. 选择Import Data
![step2](/uploads/SQLServerImport2.jpg)
3. 点击next
![step3](/uploads/SQLServerImport3.jpg)
4. 选择数据源，Microsoft Excel，然后选择Excel的路径，点击next
![step4](/uploads/SQLServerImport4.jpg)
5.选择目的数据库，这里就选择SQL Server Native Client 11.0就好了，然后选择我们要导入的数据库，我这里就选择Lewin数据库了。
![step5](/uploads/SQLServerImport5.jpg)
6. 选择copy data
![step6](/uploads/SQLServerImport6.jpg)
7. 选择数据源的table
![step7](/uploads/SQLServerImport7.jpg)
8. run
![step8](/uploads/SQLServerImport8.jpg)
9. 点击finish
![step9](/uploads/SQLServerImport9.jpg)
10. 导入成功
![step10](/uploads/SQLServerImport10.jpg)

## SQL Server导出数据
只要在上面的第四、第五步改一下数据源和目的数据库就可以，其他操作同上。