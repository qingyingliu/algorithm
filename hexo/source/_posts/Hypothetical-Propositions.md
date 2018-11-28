---
layout: post
title: Hypothetical Propositions
date: 2018-10-07 20:21:41
categories: 离散数学
description: 离散数学中容易混淆的表述
---
这篇博客主要介绍一下一些容易混淆的假设连接词。

### 1. p if q
**Example**
`I'll stay home tomorrow if I still feel sick`
`I still feel sick`是前件(antecedent)，即使它放在了语句的后面，因为它是`if`语句，所以它的标准形式应该是：`If I still feel sick, I'll stay home tomorrow`。
因此，`p if q`的标准形式应该是:`if q, then p`

### 2.p only if q
**Example**
`I'll stay home tomorrow only if I still feel sick`。这句话的直译过来是：只有当我生病的时候我明天才会在家。也就是说，如果我没有生病，那么我明天就不会呆在家里。所以，`p only if q`的等价形式为：
`if not q,then if not p`,根据假言易位，也等价于`if p,then q`。

### 3. p unless q
**Example**
`The plant will die unless you water it.`这句话的意思就是如果你不浇水，那么这株植物就死了。所以**`unless`的意思就是`if not`**。
所以`p unless q`的等价形式就是`if not q, then p`

### 4. Whenever p, q
**Example**
`Whenever I get anxious, I start eating more.`
这句话的意思是：每当我焦虑的时候，我都会吃更多的东西。也就是说，如果我焦虑，我就会去吃更多的东西。
因此，`Whenever p,q`的等价形式就是`if p, then q`

### 5. 只要p,就q
**Example**
`只要明天不下雨，我就去上学`，意思和`如果明天不下雨，我就去上学`一样。
所以，`只要p...就q`等价与`if p, then q`

### 6. 只有p,才q
**Example**
`只有你考试考到0分，妈妈才会不爱你`（有点皮了，嘿嘿),意思就是，如果你不考0分，妈妈就还是爱你的。
所以`只有p，才q`等价于`非p,则非q`，根据假言易位，也等价于`if q, then p`

### 7. 除非p,才q
**Example**
`除非考到100分，你才能玩游戏`
p:考到100分,q:玩游戏
如果p，也就是说考到了100分，你可以选择玩游戏，也可以选择不玩。
但是，如果q，也就是说如果你玩游戏的话，那你肯定就考100分了(p)。
所以`除非p，才q`等价于`if q, then p`

### 8. 除非q,否则非p
**Example**
`除非你吃饭，否则你就会饿死。`
p:没饿死 q：吃饭
等价于：如果没饿死，你肯定就是吃饭了。(p->q)
所以，`除非q，否则非p`等价于`if p, then q`