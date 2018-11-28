---
layout: post
title: Chapter 2 CONDITIONAL PROBABILITIES AND BAYES THEOREM
date: 2018-11-06 10:23:39
categories: 概率论
mathjax: true
description: conditional probability, independent probability and Bayes Theorem
---
## Conditional Probability
**Definition 2.1**
Let $S$ be a sample space associated with a random experiment. The conditional probability of event $A$, given that event $B$ has occured, is defined by
$$P(A|B)=\frac{P(A \cap B) }{ P(B)}$$

The conditional probability measure $P(A|B)$satisfies all three axioms of probability measure. That is:
(CP1) $P(A|B)>0$ for all event $A$
(CP2) $P(B|B)=1$
(CP3) If $$A_1$$, $$A_2$$,$$\cdots$$,$$A_{k}$$,$$\cdots$$ are mutually events, then $$ P(\bigcup_{k=1}^{\infty}A_{k}|B)=\sum_{k=1}^{\infty}P(A_{k}|B) $$.

**Note**

***
The conditional probability $$P(A|B)$$ can be understood as follows:
Because given the event B has occured, we can shrink the sample space from $$S$$ to the event $$B$$. That is, the event B is our new sample space of the event A. Furthermore, the event A that occurs given B can be denoted by $$A \cap B$$.
![](/uploads/cap2_1.jpg)
Therefore, the probability of event A given B is $$P(A|B)=\frac{P(A \cap B)}{P(B)}$$.
***


**Example 2.1.** A drawer contains 4 black, 6 brown, and 8 olive socks. Two socks are selected at random from the drawer. (a) What is the probability that both socks are of the same color? (b) What is the probability that both socks are olive if it is known that they are of the same color? 
**Answer**: The sample space of this experiment consists of 
$$S=\{(x,y)|x,y \in Bl,Ol,Br\}$$
The cardinality of S is 
$$N(S)=\binom{18}{2}=153$$
Let $$A$$ be the event that two socks selected at random are of the same color. Then the cardinality of $$A$$ is 
$$N(A)=\binom{4}{2}+\binom{6}{2} + \binom{8}{2}=49$$

Therefore, the probability of $$A$$ is 
$$P(A)=\frac{49}{153}$$

Let $$B$$ be the event that two socks selected at random are olive. Then the cardinality of $$B$$ is given by 
$$N(B)=\binom{8}{2}=28$$
and hence 
$$P(B)=\frac{28}{153}$$
Notice $$B \subseteq B$$. Hence
$$P(B|A)=\frac{P(A \cap B)}{P(A)}=\frac{P(B)}{P(A)}=\frac{4}{7}$$

## Independent event
**Definition 2.2**
Two events $$A$$ and $$B$$ of a sampe space $$S$$ are called indenpendent if and only if
$$P(A \cap B) = P(A) P(B)$$

**Example 2.2.** The following diagram shows two events A and B in the sample space S. Are the events A and B independent?
![](/uploads/example2_2.jpg)

**Answer**:
From the graph above, we get
$$N(A)=4$$ 
$$N(B)=5$$ 
$$N(S)=10$$ 
$$N(A \cap B)=2$$
hence 
$$P(A)=\frac{4}{10}$$ 
$$N(B)=\frac{5}{10}$$  
$$N(A \cap B)=\frac{2}{10}$$
then we check
$$P(A \cap B) = \frac{2}{10} = P(A)P(B)$$
 Hence A and B are independent. 
 
**Theorem 2.1.**
 Let $$A,B \subseteq S$$. If A and B are independent and $$P(B) > 0$$, then
 $$P(A|B)=P(A)$$
 
 **Proof**:
 Because $$A$$ and $$B$$ are mutually independent, we get $$P(A \cap B) = P(A) P(B)$$
 Therefore,
 $$P(A|B)=\frac{P(A \cap B)}{B}
 =\frac{P(A) P(B)}{P(B)}=P(A)$$
 
**Theorem 2.2**
 If $$A$$ and $$B$$ are independent events. Then $$A^c$$ and $$B$$ are independent. Similarly $$A$$ and $$B^c$$ are independent .
 
**Theorem 2.3**
Two possible mutually exclusive events are always dependent.

**Proof**
If the event $$A$$ and the event $$B$$ are mutually exclusive, then $$A \cap B = \varnothing$$.
As we known before, two events are dependent if and only if $$P(A \cap B)=P(A)P(B)$$.
That is, $$0=P(\varnothing )= P(A \cap B) =P(A)P(B)$$
Hence, $$P(A)=0$$ or $$P(B)=0$$. However, this is contradict to the fact that $$A$$ and $$B$$ are possible events. 

**Theorem 2.4**
Two possible independent events are not mutually exclusive.

## Bayes Theorem
The Bayes Theorem solve the issue whose outcome depends on what happens in various intermediate stages.
**Partition**
Let S be a set and let $$p=\{A_{i}\}_{i=1}^{m}$$ be a collection of subsets of $$S$$. The collection $p$ is called a partition if 
(a) $$S=\bigcup_{i=1}^{m}$$
(b) $$A_{i} \cap A_{j} = \varnothing$$  for  $$i \neq j$$
 ![](/uploads/partition.jpg)
 
 **Theorem 2.5**
 If the events $$\{B_{i}\}_{i=1}^{m}$$ constitute a partition of the sample space $$S$$ and $$P(B_{i}) \neq 0\ for\ i = 1,2,3,\cdots ,m$$, then for any events in $$S$$
 $$P(A)=\sum_{i=1}^{m}{P(B_{i})P(A|B_{i})}$$
 **Proof**
 $$\sum_{i=1}^{m}P(A)=P(B_{i})P(A|B_{i})\\
 =\sum_{i=1}^{m}P(B_{i}) \frac{P(A \cap B_{i})}{B_{i}}\\
 =\sum_{i=1}^{m}P(A \cap B_{i}) \\
 =P(A \cap (\bigcup_{i=1}^m B_{i})) \\
 =P(A \cap S) = P(A)
 $$
 
 Using Theorem 2.5 and conditional probability theorem, we can deduce the following theorem.
 
 **Theorem 2.6**
 If the events $$\{B_{i}\}_{i=1}^{m}$$ constitute a partition of the sample space $$S$$ and $$P(B_{i}) \neq 0$$ for i = 1,2,3...,m, then for any event A in $$S$$ such that $$P(A) \neq 0$$
 $$
 P(B_{k}|A)=\frac{P(A \cap B_{k})}{\sum_{i=1}^{m}P(B_{i}) P(A|B_{i})}
 $$
 
 This Theorem is called Bayes Theorem. The probability $$P(B_{k})$$ is called **prior probability**. The probability $$P(B_{k}|A)$$ is called **posterior probability**.
 
 **Example 2.3**
Two boxes containing marbles are placed on a table. The boxes are labeled $$B_1$$ and $$B_2$$. Box $$B_1$$ contains 7 green marbles and 4 white marbles. Box $$B_2$$ contains 3 green marbles and 10 yellow marbles. The boxes are arranged so that the probability of selecting box $$B_1$$ is $${\frac{1}{3}}$$ and the probability of selecting box $$B_2$$ is $${\frac{2}{3}}$$. Kathy is blindfolded and asked to select a marble. She will win a color TV if she selects a green marble. (a) What is the probability that Kathy will win the TV (that is, she will select a green marble)? (b) If Kathy wins the color TV, what is the probability that the green marble was selected from the ﬁrst box?

**Answer**
(a)  Let $$A$$ be the event of drawing a green marble. Then
$$P(A) = P(A \cap B_{1}) + P(A \cap B_{2}) = P(A|B_{1})P(B_{1}) + P(A|B_{2})P(B_{2})
\\ = (\frac{7}{11}) \cdot (\frac{1}{3}) \cdot (\frac{3}{13})  \cdot (\frac{2}{3}) \cdot = \frac{157}{429}$$

(b) $$P(B_{1}|A) = \frac{P(B_{1} \cap A)}{P(A)} = \frac{P(A|B_{1}) \cdot P(B_{1})}{P(A)} = \frac{\frac{7}{11} \cdot \frac{1}{3}}{\frac{157}{429}} = \frac{91}{157}$$
![](/uploads/bayesExample.jpg)