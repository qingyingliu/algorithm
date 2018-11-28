---
layout: post
title: Chapter 1 PROBABILITY OF EVENTS
date: 2018-10-30 09:22:46
categories: 概率论
mathjax: true
description: Introduce some basic concepts of probability and its measure.
---
##1.1 Counting Techniques
  For an event $A$ of a discrete sample space $S$, the probability of $A$ can be computed by using the formula
   $$P(A)=\frac{N(A)}{N(S)}$$
   where $N(A)$ denotes the number of elements of $A$ and $N(S)$ denotes the number of elements in the sample space $S$.
   Therefore, counting is important. There are three basic counting techeniques. They are multiplication rule, permutation and combination.
   
#### 1.1.1 Multiplication Rule 
  If $$E1$$ is an experiment with $$n_1$$ outcomes and $$E2$$ is an experiment with $$n_2$$ possible outcomes, then the experiment which consist of performing $E1$ first and then $$E2$$ consists of $$n_{1}n_{2}$$ possible outcomes.

**Example 1.1** Find the possible number of outcomes in a sequence of two tosses of a fair coin.
**Answer**: The number of possible outcomes is 2$$\cdot$$2=4. 

**Example 1.2**.  How many different license plates are possible if Kentucky uses three letters followed by three digits. 
**Answer**: 
$$(26)^{3}(10)^{3}\\
=(17576)(1000)\\
=17,576,000.  \\
$$

#### 1.1.2 Permutation
  In general, if $r$ positions are to filled from $n$ objects, then the total number of possible ways they can be filled are given 
  $$
  n(n-1)(n-2) \cdots (n-r+1)\\
  =\frac{n!}{(n-r)!}\\
  =_{n}P_{r}
  $$
  Thus, $$_{n}P_{r}$$ represents the number of ways $r$ positions can be filled from $n$ objects.
  
**Definition 1.1**
Each of the $$_{n}P_{r}$$ arrangements is call a permutation of $n$ objects taken $r$ at a time.
Notice: Order is important!

**Example 1.3** How many permutations are there of all three of letters a, b, and c?
**Answer**:  $$_{3}P_{3}=\frac{n!}{(n-r)!}=\frac{3!}{0!}=6$$

**Example 1.4** Four names are drawn from the 24 members of a club for the oces of President, Vice-President, Treasurer, and Secretary. In how many different ways can this be done?
**Answer**:
$$_{24}P_{4}=\frac{24!}{(24-4)!}=(24)(23)(22)(21)=255,024
$$

#### 1.1.3 Combination
  Let $$c$$ denote the number of subsets of size $r$ that can be selected from $n$ different objects. The $r$ objects in each set can be ordered in $$_{r}P_{r}$$ ways.
    Thus we have 
  $$_{n}P_{r}=c \cdot _{r}P_{r}$$
From this point, we get
  $$c=\frac{_{n}P_{r}}{_{r}P_{r}}=\frac{n!}{(n-r)!r!}$$
  The number c is denoted by $$\binom{n}{r}$$. Thus, the above can be written as
  $$\binom{n}{r}=\frac{n!}{(n-r)! \cdot r!}$$
  
**Definition 1.2** Each of the $$\binom{n}{r}$$ unordered subsets is called a combination of $n$ objects taken $r$ at a time.

**Example 1.5** How many committees of two chemists and one physicist can be formed from 4 chemists and 3 physicists?
**Answer**: 
 $$\binom{4}{2} \cdot \binom{3}{1} \ \ \ (multiplication\ rule) =(6) \cdot (3) =18$$ 
 
#### 1.1.4 Binomial Theorem
$$(x+y)^{n} = \sum_{k=0}^{n} \binom{n}{k} x^{n-k} y^{k}$$
Above expression is called Binamial Theorem. The coefficient $$\binom{n}{k}$$ is called the binomial coefficient.

**Theorem 1.1** Let $$n \in N$$ and $$r=0,1,2,\cdots,n$$
Then
 $$\binom{n}{r}=\binom{n}{n-r}$$
**Proof**: By direct verification, we get
  $$\binom{n}{n-r}=\frac{n!}{(n-(n-r))! \cdot (n-r)!}=\frac{n!}{(n-r)! \cdot r!}=\binom{n}{r}$$
  
**Theorem 1.2** For any positive integer $n$ and $$r=1,2,3,\cdot,n$$, we have
  $$\binom{n-1}{r}=\binom{n}{r-1}+\binom{n-1}{r-1}$$
**Proof**: 
$$(1+y)^{n}=(1+y)(1+y)^{n-1}=(1+y)^{n-1}+y \cdot (y-1)^{n-1}$$
$$\sum_{r=0}^{n} \binom{n}{r} y^r= \sum_{r=0}^{n-1} \binom{n-1}{r} y^r + \sum_{r=0}^{n-1} \binom{n-1}{r} y^{r+1}$$
By equating the coefficients of $$y^r$$, we obtain
$$\binom{n}{r}=\binom{n}{n-r}$$
and the proof is complete.

**Theorem 1.3** Let m and n be positive integers. Then
$$\sum_{r=0}^{k} \binom{m}{r} \binom{n}{k-r} = \binom{n+m}{k}$$

**Example 1.6** Show that
  $$\sum_{r=0}^{n} \binom{n}{r}^{2} = \binom{2n}{n}$$
**Answer**:
$$ \sum_{r=0}^{n} \binom{n}{r}^{2} \\
= \sum_{r=0}^{n} \binom{n}{r} \cdot \binom{n}{n-r}	\\
=\binom{n+n}{r+n-r}	
=\binom{2n}{n}  
$$
## 1.2 Probability Measure
A **random experiment** is an experiment whose outcomes cannot be predictedwith certainty. However, in most cases the collection of every possibleoutcome of a random experiment can be listed.

**Definition 1.3** . A **sample space** of a random experiment is the collection of all possible outcomes.

**Example 1.7** What is the sample space for an experiment in which the state of Kentucky picks a three digit integer at random for its daily lottery?
**Answer**: $$S={0,1,2,\cdots ,999}$$

**Definition 1.4.** Each element of the sample space is called a **sample point**.

**Definition 1.5.** If the sample space consists of a countable number of sample points, then the sample space is said to be a **countable sample space**.

**Definition 1.6.** If a sample space contains an uncountable number of sample points, then it is called a **continuous sample space**.

**Definition 1.7.** A subset A of the sample space S is said to be an event if it belongs to a collection F of subsets of S satisfying the following three rules:
(a) S $$\in$$ F; (b) if A$$\in$$ F then $$A^{c} \in$$ F; and (c) if $$A_{j}\in F$$ for j \>=1, then $$\bigcup_{j=1}^{\infty}=F$$. The collection F is called an **event space.**

**Definition 1.8** Let $S$ be the sample space of a random experiment. A **probability measure** P: $F$ -> [0,1] is a set function which assigns real number to the various events of S satisfying
1. $P(A)>0$ for all event A $\in$ F
2. P(S)=1
3. $$P(\bigcup_{k=1}^{\infty}A_{k})=\sum_{k=1}^{\infty}P(A_k)$$ if $A_1$,$A_2$,$A_3$,$\cdots$,$A_k$ are mutually disjoint events of S.

**Theorem 1.5** If $\varnothing$ is an empty set, then 
$$P(\varnothing )=0$$

**Proof**:
Obviously, $$\varnothing=\bigcup_{k=1}^{\infty} \varnothing $$ and $$\bigcap _{k=1}^{\infty} = \varnothing$$, so according to **Definition 1.8**'s third property, we have
$$P(\varnothing )=P(\bigcup_{k=1}^{\infty} \varnothing)=\sum_{k}^{\infty}P(\varnothing )$$
Therefore, $$P(\varnothing )$$ must be 0 and the proof is complete.

**Theorem 1.6** Let$${A_{1},A_{2},\cdots ,A_{n}}$$ be a finite collection of $n$ events such that $$A_{i} \cap  E_{j} = \varnothing $$ for $$i \neq j$$. Then 
$$P(\bigcup_{i=1}^{n}A_{i})=\sum_{i=1}^{n}P(A_{i})$$

**Theorem 1.7** If $A$ is an event of a discrete sample space $S$, then the probability of A is equal to the sum of the probabilities of its elementary events.

**Proof**: Any set $A$ in $S$ can be written as the union of its singleton sets. Let $$\{O_{i}\}_{i=1}^{\infty}$$ be the collection of all the singleton sets of $A$. Then 
$$A=\bigcup_{i=0}^{\infty}O_{i}$$
So,
$$P(A)=P(\bigcup_{i=1}^{\infty}O_{i})=\sum_{i=1}^{\infty}P(O_{i})$$

**Example 1.8**  If a fair coin is tossed twice, what is the probability of getting at least one head? 
**Answer**: 
Obviously, we can list all the possible outcomes as follows:
$$S={HH,HT,TH,TT}$$
The events of getting at least one head is $$A={HH,HT,TH}$$. According to theorem 1.7, we obtain
$$P(A)=P(HH)+P(HT)+P(TH)=\frac{3}{4}$$

**Corollary 1.1** If S is a finite sample space with $n$ sample elements and $A$ is an event in $S$ with $m$ elements and **the probability of each elements equals mutually**, then the probablity of $A$ is given by
$$P(A)=\frac{m}{n}$$

**Proof**: By previous theorem, we get 
$$P(A)=\sum_{i=1}^{m}P(O_{i})=\sum_{i=1}^{m}\frac{1}{n}=\frac{m}{n}$$

## 1.3. Some Properties of Probability Measure
**Theorem 1.8**. If $A$ be any event of the sample space $S$, then
$$P(A^{c})=1-P(A)$$
**Proof**:
$$S=A \cup A^{c}\ and\ A \cap A^{c} = \varnothing$$
Therefore,
$$1=P(S)=P(A \cup A_{c})=P(A)+P(A^{c})$$
That is 
$$P(A^{c})=1-P(A)$$

**Theorem 1.9** If $$A \subseteq B \subseteq S$$, then 
$$P(A)<=P(B)$$
**Proof**:
Note that $$B=A \cup (B-A)$$ and $$A \cap (B-A) = \varnothing$$
Therefore,
$$P(B)=P(A \cup (B-A))=P(A) + P(B-A)$$
That is 
$$P(B)-P(A)=P(B-A)>=0$$
So,
$$P(B)>=P(A)$$

**Theorem 1.10** If $A$ and $B$ are any two events, then
$$P(A \cup B)=P(A)+P(B)-P(A \cap B)$$
**Proof**
It easy to see that
$$A \cup B = A \cup (A^{c} \cap B)$$
and 

$$A^{c} \cap B = \varnothing$$
Hence, we get
$$P(A \cup B) = P(A) + P(A^{c} \cap B)=P(A) + P(B - (A\cap B))=P(A)+P(B)-P(A\cap B)$$

**Theorem 1.11** If $$A_{1}$$ and $$A_{2}$$ are two events such that $$A_{1} \subseteq A_{2}$$, then
$$P(A_{2} -A_{1})=P(A_{2})-P(A_{1})$$

**Proof**: The event $A_{2}$ can be written as 
$$A_{2}=A_{1} \cup (A_{2} - A_{1})$$
and $$A_{1} \cap (A_{2} - A_{1}) = \varnothing$$
Therefore
$$P(A_{2})=P(A_{1})+P(A_{2}-P_{1})$$
So
$$P(A_{2} -A_{1})=P(A_{2})-P(A_{1})$$