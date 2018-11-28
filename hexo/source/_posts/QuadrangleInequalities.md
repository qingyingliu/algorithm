---
layout: post
title: Efficient Dynamic Programming Using Quadrangle Inequalities
date: 2018-10-11 23:20:27
categories: Algorithm
mathjax: true
---
## Introduction
Dynamic Programming is a general tenique to speeds up the program, which avoids repeatting to solve the same subprogram. However, can we improve our dynamic programming? Sure. This post is to introduce how to optimize the Interval Dynamic Programming by using **Quadangle Inequalities**. Additionally, Interval Dynamic Programming just like this:
```
c(i,j)=0;
c(i,j)=w(i,j)+min(c(i,k-1)+c(k,j)),i<=k<=j     (1)
```
<!-- more -->
## Quadangle Inequalities
**Definition**: for $i<=i'<=j<=j'$, if the inequality satisfies :
$w(i,j)+w(i',j')<=w(i,j')+w(i',j)$, we call this kind of inequality as **Quadrangle Inequality(QI)**.
This property allows the dynamic programming to be speeded up because the following proof.

**Theorem**: If $w$ satifies QI and furthermore is monotone on the lattice of intervals, i.e.,
$w(i,j)<w(i',j')$  for  $i<i'<j<j'$
then the function c defined by (1) can be computed by O(n^2).

