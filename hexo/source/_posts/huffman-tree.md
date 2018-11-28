---
layout: post
title: huffman tree
date: 2018-10-23 11:30:32
categories: 
- [data-structure]
- [Algorithm]
description: Huffman编码的证明、Huffman树的构造和解析Huffman编码
---
## Huffman code

### introduction

假设我们有一个文件，它只含有a,b,c,d,e,f这六种字符，如果我们用固定长度的bit来表示字符，那么我们需要3个bit来表示一个字符，但是，如果我们使用可变长度的bit来保存字符的话，通过Huffman编码我们可以压缩内存，可以节省20%到90%的内存。下面给出六种字符对应的频率(所有字符一共是10万)，还有其固定长度的bit和可变长度的bit的码字：

  |a  |b  |c  |d  |e  |f  
---|---|---|---|---|---|---
Frequency(in thousands)|45|13|12|16|9|5
fixed-length codeword|000|001|010|011|100|101
variable-length codeword|0|101|100|111|1101|1100

如果使用定长bit来表示字符，则需要的内存是：3 * 100000 = 300000 bits

如果使用不定长bit来表示字符，则需要的内存是: (45\*1+13\*3+12\*3+16\*3+9\*4+5\*4) = 224000 bits。
与定长编码相比，节省了25%的空间。实际上，我们将会看到，这是此文件的最优字符编码。  

### prefix code

首先我先介绍一下什么叫做前缀编码(prefix code)

**前缀编码**:在一个编码集合中，任何一个字符的编码都不是另外一个字符编码的前缀，这种编码叫做前缀编码。**这种前缀特性保证了每一个编码都能被译码成唯一与之对应的字符，没有二义性(unambiguous)。**


### how to construct a Huffman code?

Huffman设计了一个贪心算法来**构造最优前缀码**，被称为赫夫曼编码(Huffman code),它的正确性依赖于证明贪心选择属性(greedy choice property)和最优子结构(optimal substructure)。但是我先讲如何构造赫夫曼编码，然后再去证明。

**Huffman tree**
这棵树和Huffman code相对应，其中叶子节点放着字母和它的频率，内部节点则放着它的左右子树的和。我们可以以左子树的边为0，右子树的边代表1，从而进行编码。

这个算法使用了最小优先队列，每次都将队列里最小的两个值取出来，合并成一个新的节点，然后再把这个节点放入队列，循环，直到队列的大小等于1，说明不能合并，这时就构建好了Huffman tree.

伪代码：
```
Huffman(C):
	for i = 1 to n-1:
		allocate a new node z
		z.left=x=EXTRACT-MIN(Q)
		z.right=y=EXTRACT-MIN(Q)
		z.freq=x.freq+y.freq
		Insert(Q,z)
	return EXTRACT-MIN(Q)
```

### demonstration of greedy-choice property

首先我们先定义一个符号B，B(T)表示Huffman Tree的需要的空间。则

B(T)=sum(freq(ele) * len(ele)), 其中freq(ele)代表ele字符的频率，len(ele)表示表示该字符需要的bit.

我们假设T为最优Huffman Tree，且树的最大深度的叶子节点为y，且它出现的频率不是最小。
而频率最小的叶子节点不在最大深度，且用a表示。
此时`B(T)=freq(y) * len(y) + freq(a) * len(a) + ...` ,其中`freq(y) > freq(a)`, `len(y) > len(a)`

我们交换a,y的位置,此时得到一颗新的树T1，则`freq(a1)=freq(a)`,`freq(y1)=freq(y)`,`len(a1)=len(y)`, `len(y1)=len(a)`

```
B(T1)= freq(y1) * len(y1) + freq(a1) * len(a1) + ...
	 = freq(y) * len(a) + freq(a) * len(y) + ...
```

则
```
B(T)-B(T1)= (freq(y) * len(y) + freq(a) * len(a) + ...) - (freq(y) * len(a) + freq(a) * len(y) + ...)
		  = len(y) * (freq(y)-freq(a)) + len(a) * (freq(a) - freq(y))
		  = (len(y) - len(a)) * (freq(y) - freq(a))
```
其中`len(y)-len(a)>0`, `ferq(y)-freq(a)>0`, 所以上式等价于`B(T)-B(T1)>0`,即：
`B(T)>B(T1)`,这就和T是最优的Huffman Tree相矛盾了。所以，频率越小的字符，应该放越深的地方。
证毕！

### Proof of optimal substructure

**Lemma**: `Lemma: T′ is optimal for C′=C∖{x,y}+{z}, if T is optimal for C.`

**Proof:**
我们用反证法来证明。假设对于`C'`的最优前缀是`T''`, 而不是`T'`,则对于C，
最优前缀`T'''`=`T''`+f(x)+f(y) > `T'`+f(x)+f(y)=`T`
这和我们的假设：“对于C，T是最优前缀“相矛盾。所以`T'`是`C'`的最优前缀。




### Reference
 **Introduction to algorithm**
