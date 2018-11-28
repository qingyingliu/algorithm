---
title:      breif Markdown
author:     Lewin671
categories: Markdown
date: 2018/10/01 00:00:00
---
## markdown教程

如今在很多的博客平台都使用markdown语法来写博客，比如CSDN，GitHub等等。
所以我觉得非常有必要学习一下markdown的语法。故我随手写下了此教程。


主要内容如下：


1. [标题](#1标题)
2. [段落](#2段落)
3. [引用](#3引用)
4. [强调](#4强调)
5. [列表](#5列表)
6. [代码引用](#6代码引用)
7. [链接](#7链接)
8. [图片](#8图片)
9. [table](#9table)

<!--more-->
### 标题


一般使用`#`来表示标题，类似于html中的`<h>`标签,`#`的个数代表标题的级数。
级数越大，标题越小。
注意：在GitHub中，使用`#`之后，需要加一个空格和标题分隔开来。
比如:


`code:`


```
# 一级标题
## 二级标题
### 三级标题
```



### 段落


段落的前后要有空行，所谓的空行是指没有文字内容。若想在段内强制换行的方式是使用两个以上空格加上回车（引用中换行省略回车）。





### 引用


在段落的每一行或者只在第一行使用`>`,可以嵌套使用。</span>
比如:


`code:`


```
>第一个引用
>>嵌套引用
```
`效果:`
>第一个引用
>>嵌套引用

注意：如果想要引用多行，在GitHub中，就必须用多一个`>`来分割每一行。


比如：


```
>first line
>
>second line
>
>third line
```

`效果:`


>first line
>
>second line
>
>third line


### 4.强调


使用`*`或者`_`来强调内容。
1个`*`或者`_`表示斜体，2个表示加粗。
比如：


`code:`


```
*Italic* _Italic_
**Bold** **Bold**
```

`效果：`


*Italic* _Italic_


**Bold** **Bold**




### 列表


分为有序和无序列表。无序列表使用`*`,`-`标记，有序列表的标记方法是将上述符号换成数字，并辅以`.`。
比如：


`code:`


```
- George Washington
- John Adams
- Thomas Jefferson
```


`效果:`


- George Washington
- John Adams
- Thomas Jefferson


`code:`


```
1. first
2. second
3. third
```


`效果:`

1. first
2. second
3. third

当然，我们还可以通过控制缩进(2个空格)来控制嵌套



`code:`


```
- 1
- 2
- 3
  - 3.1
  - 3.2
  - 3.3
```


`效果:`


- 1
- 2
- 3
  - 3.1
  - 3.2
  - 3.3





### 代码引用


单行使用单个反引号括起来，多行代码使用三个反引号括起来


### 链接


格式：`[这是链接内容](http://www.yaosansi.com/这是链接地址 "这里是链接说明")`


链接可以由两种形式生成：**行内式**和**参考式**

**行内式：**


比如：


`code:`


```
[Lewin671的GitHub](https://github.com/Lewin671)
```


`效果：`


[Lewin671的GitHub](https://github.com/Lewin671/myblog/blob/master/%E5%85%B6%E4%BB%96%E6%8A%80%E5%B7%A7/markdown%E4%BD%BF%E7%94%A8%E6%95%99%E7%A8%8B.md#%E4%B8%80%E7%BA%A7%E6%A0%87%E9%A2%98)


**参考式：**


`code:`


```
[web1][1]
[web2][2]
[1]:https://www.baidu.com "baidu"
[2]:https://github.com/Lewin671/myblog/blob/master/%E5%85%B6%E4%BB%96%E6%8A%80%E5%B7%A7/markdown%E4%BD%BF%E7%94%A8%E6%95%99%E7%A8%8B.md#%E4%B8%80%E7%BA%A7%E6%A0%87%E9%A2%98 "Lewin671"
```

`效果:`


[web1][1]


[web2][2]


[1]:https://www.baidu.com "baidu"


[2]:https://github.com/Lewin671/myblog/blob/master/%E5%85%B6%E4%BB%96%E6%8A%80%E5%B7%A7/markdown%E4%BD%BF%E7%94%A8%E6%95%99%E7%A8%8B.md#%E4%B8%80%E7%BA%A7%E6%A0%87%E9%A2%98 "Lewin671"



### 图片


Format: `![Alt Text](url)`


比如：


`code:`


```
![this is the pic of baidu](http://www.baidu.com/img/baidu_sylogo1.gif "baidu")
```

`效果:`


![this is the pic of baidu](http://www.baidu.com/img/baidu_sylogo1.gif "baidu")





### table


通过组合`-`和`|`符号来制作表格。
比如：


`code:`


```
First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column

```


`效果:`


First Header | Second Header
------------ | -------------
Content from cell 1 | Content from cell 2
Content in the first column | Content in the second column
