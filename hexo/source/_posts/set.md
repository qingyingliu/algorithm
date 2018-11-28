---
layout: post
title: 集合的基本概念和运算
date: 2018-10-29 18:55:31
categories: 离散数学
mathjax: true
---
### 集合的基本概念
1. **集合**： 集合是不能精确定义的数学概念。一般认为，**集合**是一些可确定的、可分辨的事物构成的整体。用大写字母表示。
2. **元素**： 集合中的事物。
3. **子集**： 设A、B为集合，如果B中的每一个元素都是A中的元素，则称B为A的子集合，简称**子集**。
<!--MORE-->
4. **包含**： 如果B是A的子集，则称A包含B，或者称B包含于A，符号化为：
	$A\subseteq B \Leftrightarrow \forall x(x\in B \rightarrow x\in A)$
5. **相等**: 设A、B为集合，如果$A\subseteq B$且$B \subseteq A$,则称A与B相等，记作A=B。符号化表示为：
	$A=B\Leftrightarrow A\subseteq B \wedge B \subseteq A$ 
6. **真子集：** A,B为集合，如果$A \subseteq B$且$A\neq B$，则称A是B的真子集。
7. **空集**: 不含任何元素的集合是空集。表示为：$\varnothing$
	**定理**： 空集是一切集合的子集。
	证明： 任给集合A，由子集定义有：
	$\varnothing \subseteq A \Leftrightarrow \forall x (x \in \varnothing \rightarrow x \in A)$
	由于在右边的命题中，$x\in \varnothing$为假，即蕴含式前键为假，所以整个命题为真。
	
	**推论**: 空集是唯一的。
	证明： 假设空集不唯一，有$\varnothing_1 , \varnothing_2$,则根据上面的定理，有：
	$\varnothing_1 \subseteq \varnothing_2$
	$\varnothing_2 \subseteq \varnothing_1$
	根据集合相等的定义有：
	$\varnothing_1 = \varnothing_2$
8. **幂集**： 设A为集合，把**A的全体子集**构成的集合称作A的幂集。用$P(A)$表示。所以符号化为：
	$P(A)=${$x|x \subseteq A$}
	性质： 若A是n元集，则P（A）有$2^n$个元素。
	证明：
	假设x为A的子集，则：
	当x的元素为空时： 有1种情况
	当x的元素为1时： 有n种情况
	当x的元素为2时， 有$C_n^2$种情况。
	$\cdots$
	当x的元素为m时，有$C_n^m$种情况。
	所以一共有：$C_n^0+C_n^1+...C_n^n=(1+1)^n=2^n$
	证毕！
	
	比如A={a,b,c}，则P（A)={$\varnothing$,{a},{b},{c},{a,b},{a,c},{b,c},{a,b,c}}，P（A)一共有8个元素。
9. 全集： 在一个具体问题中，如果涉及到的问题的集合都是某个集合的子集，那么称这个集合为全集，记为$E或者U$。

### 集合的基本运算
1. 并： $A\cup B$={$x|x\in A \vee x \in B$}
2. 交： $A \cap B$={$x|x \in A \wedge x \in B$},当两个集合的交集为空集时，则这两个集合是**不交**的。
推广：
   对于n个集合的并集和交集，有：
   $\bigcup_{i=1}^{n}A_i=A_1 \cup A_2 \cup \cdots \cup A_n $
   
   $\bigcap_{i=1}^{n}A_i=A_1 \cap A_2 \cap \cdots \cap A_n $
3. 相对补集： $A-B$={$x|x\in A \wedge x \notin B$}
   如下图所示：
   ![](/uploads/set_complementary.jpg)

4. 绝对补集： 设E为全集，则称**A对E的相对补集**为A的绝对差集，记作$\tilde{A}$。
   即： $\tilde{A}$=$E-A$={$x|x \in E \wedge x \notin A$}={$x|x \notin A$}
5. 对称差： 对称差的意义就是集合A,B的非公共部分的并集：
$A \bigoplus B = (A \cup B) - (A \cap B)$
等价于：
$A \bigoplus B = (A - B) \cup (B - A)$
如下图所示： 
![](/uploads/set_bigOPlus.png)

### 集合的算律
1. 幂等律： 
	$A \cup A = A$
	$A \cap A = A$
2. 结合律：
	$(A \cup B ) \cup C=A \cup ( B \cup C)$ 
	$(A \cap B ) \cap C=A \cap ( B \cap C)$ 
3. 交换律：
	$A \cup B = B \cup A$
	$A \cap B = B \cap A$
4. 分配律：
	$(A \cup B ) \cap C=(A \cap C) \cup (B \cap C)$ 
	$(A \cap B ) \cup C=(A \cup C) \cap ( B \cup C)$ 
5. 同一律：
	$A \cup \varnothing = A$
	$A \cap E = A$
6. 零律：
	$A \cup E = E$
	$A \cap \varnothing = \varnothing$
7. 排中律：
	$A \cup \widetilde{A} = E$
8. 矛盾律：
	$A \cap \widetilde{A} = \varnothing$
9. 吸收律：
	$A \cup (A \cap B) = A$
	$A \cap (A \cup B) = A$
10. 德摩根定律：
	$A-(B \cup C) = (A - B) \cap (A -C)$
	$A-(B \cap C) = (A -B) \cup (A -C)$
	$\widetilde{B ∩ C} = \widetilde{B} \cup \widetilde{C}$
	$\widetilde{B \cup C} = \widetilde{B} \cap \widetilde{C}$
11. 双重否定律：
	$\widetilde{\widetilde{A}}=A$
	
以上恒等式的证明主要用到命题演算的等值式。
**证明的基本思想是：**
欲证P=Q，即证$P \subseteq Q \wedge Q \subseteq P$
即证 $ \forall x \rightarrow (x \in P \rightarrow x \in Q \wedge x \in Q \rightarrow x \in P)$
即： $x \in P \Leftrightarrow x \in Q$

### 集合包含的证明
1. **命题演算证法**： 
$\forall x(x \in X \Rightarrow \cdots \Rightarrow x \in Y)$

	例如： 证明$A \subseteq B \Leftrightarrow P(A) \subseteq P(B)$:
	证明： $\forall x,x \in P(A) \Rightarrow x \subseteq A \Rightarrow x \subseteq B \Rightarrow x \in P(B)$
	$x\in A \Rightarrow$ {x} $\subseteq P(A) \Rightarrow ${x} $\in P(B) \Rightarrow ${x}$\subseteq B \Rightarrow x \in B$

2. **包含传递证明法**： 
	找到集合T满足$X \subseteq T \wedge T \subseteq Y$,从而得到$X \subseteq Y$

	例如： 证明$A-B \subseteq A \cup B$
	证明： $A-B \subseteq A \subseteq A \cup B$
	
3. **利用包含的等价条件证明$X \subseteq Y$**: 
	$A \subseteq B \Leftrightarrow A \cup B = B \Leftrightarrow A \cap B = A \Leftrightarrow A-B=\varnothing$
	例如： 证明$A \subseteq C \wedge B \subseteq C \Rightarrow A \cup B \subseteq C$
	证明： $A \subseteq C \Rightarrow A \cup C = C$
	$B \subseteq C \Rightarrow B \cup C = C$
	所以，$(A \cup B) \cap C \Rightarrow (A \cap C) \cup (B \cap C) \Rightarrow A \cup B$,
	所以命题成立
	
4. **反证法**：
	欲证$$X \subseteq Y$$, 假设命题不成立，必存在x使得$$x \in X$$且$$x \notin Y$$.然后推出矛盾。
	例如：
	证明 $$A \subseteq C \wedge B \subseteq C \Rightarrow A \cup B \subseteq C$$ 
	证： 假设$$A \cup B \subseteq C$$不成立，
	则$$\exists x(x \in A \cup B \wedge x \notin C)$$
	即存在x使得$$x \in A$$或$$x \in B$$,且$$x \notin C$$
	若$$x \in A $$ 且 $$x \notin C$$, 则和$$A \subseteq C$$相矛盾
	若$$x \in B $$ 且 $$x \notin C$$, 则和$$B \subseteq C$$相矛盾
	所以不存在x使得$$x \in A$$或$$x \in B$$,且$$x \notin C$$
  所以假设错误。即$$A \subseteq C \wedge B \subseteq C \Rightarrow A \cup B \subseteq C$$
	
5. **利用已知包含式并交运算**
	$$X \subseteq Y \Rightarrow X \cap Z \subseteq Y \cap Z$$
	$$ X \subseteq Y \Rightarrow X \cup Z \subseteq Y \cup Z$$

	例如：
	证明 $$A \cap C \subseteq B \cap C \wedge A - C \subseteq B - C \Rightarrow A \subseteq B$$
	证： 根据题意，有 $$A \cap C \subseteq B \cap C$$, $$A-C \subseteq B - C$$
	将上式两边求并，所以 $$(A \cap C ) \cup (A-C ) \subseteq (B \cap C) \cup (B - C)$$
	所以$$(A \cap C ) \cup (A \cap \widetilde{C} ) \subseteq (B \cap C) \cup (B \cap \widetilde{C})$$
	所以$$A \cap (C \cup \widetilde{C}) \subseteq B \cap (C \cup \widetilde{C})$$
	所以$$A \subseteq B$$
	
**注意**： 
$$X \subseteq Y \Rightarrow X \cap Z \subseteq Y \cap Z$$
$$ X \subseteq Y \Rightarrow X \cup Z \subseteq Y \cup Z$$
的顺序不可逆。也就是说，$$X \cap Z \subseteq Y \cap Z \nRightarrow X \subseteq Y$$, $$X \cup Z \subseteq Y \cup Z \nRightarrow X \subseteq Y$$

### 集合中元素的计数
1. 集合$A=\{1,2,\cdots,n\}$, 它含有$n$个元素，可以说这个集合的基数是$n$，记作
 $$card A = n$$

2. 包含排斥原理：
   设$S$为又穷集合，$$P_{1},P_{2},P_{3},\cdots,P_{m}$$是m条性质。$$S$$中的任何一个元素x对性质$$P_i$$具有或者不具有，两种情况必居其一。令$$A_i$$表示$$S$$中具有性质$$P_{i}$$元素构成的集合，那么包含排斥定理可以叙述为：
   S中不包含$$P_{1},P_{2},P_{3},\cdots,P_{m}$$的元素个数为：
   $$\begin{aligned}
	   &|\bar{A_{1}} \cap \bar{A_{2}} \cap \cdots \cap \bar{A_{m}}| \\
	   =&|S| - \sum_{i=1}^{m}|A_{i}| + \sum_{1<=i<=j<=m}|A_{i} \cap A_{j}| + \cdots + (-1)^{m}|A_{1} \cap A_{2} \cap \cdots \cap A_{m}|
   \end{aligned}$$

3. 例如： 给出一个数N，求1至N中，有多少个数不是2 3 5 7的倍数。 例如N = 10，只有1不是2 3 5 7的倍数。
   解： 设全集为$$S$$, 数组a[4]={2,3,5,7}则
   性质$$P_{i}(x)$$为: a[i]是x的倍数，其中$$x \in S$$
   集合A为满足性质$$P_{i}$$的元素集合。根据包含排斥原理：
   $$\begin{aligned}
	&|\bar{A_{i}} \cap \bar{A_{2}} \cap \bar{A_{3}} \cap \bar{A_{4}}| \\
	=&|S| - \sum_{i=1}^{4}|A_{i}| + \sum_{1<=i<=j<=4}|A_{i} \cap A_{j}| + \cdots + (-1)^{4}|A_{1} \cap A_{2} \cap \cdots \cap A_{4}|\\
	=&N - (N/2 + N/3 + N/5 +N /7) + (N/6 + N/10 + N/14 + N/15 + N/21 + N/35) \\
	-& (N/30 + N/42 + N/70 + N/105) + (N/210)
   \end{aligned}
   $$