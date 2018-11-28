---
layout: post
title: KMP Algorithm
date: 2018-09-29 01:56:36
categories: data-structure
description: string match algorithm
---
## Introduction to KMP
KMP算法是一种**高效的字符串匹配算法**，它的第一次被提出是在1977年由Donald E. Knuth, James H. Morris and Vaughan R. Pratt提出的。这篇博客主要介绍KMP算法的实现及其应用，至于KMP算法的正确性，本博客不涉及，这也是为了让新手能够能加容易看懂。
## Two steps to realize KMP
KMP算法一般分为两个步骤：
1. 计算next数组
2. 根据next数组进行字符串匹配

是不是看着一脸懵逼？没有关系，因为上面两个步骤没有清楚得定义next数组和字符串匹配的规则，只是从总体来说，但是实现的细节正是这篇文章的重点。

## How to get the next array
### Definition of next array
首先我们要明确next数组的执行是只依据**模式串（Pattern String）**的，与**主串（Text String)**无关。**下面假设模式串为P[n],主串为T[m],P和T的字符下标从0开始**。
下面我们来定义next数组：
`next[j]=i`表示P[0,...,j-1]有着**最大**长度为i的前缀字符串F和后缀字符串L,使得F=L。
注意：这里我专门强调了最大，比如P="aaaa",则P的相同长度的前缀和后缀相等的长度有：1，2，3，分别是"a","aa","aaa"。但是这里的next[4]=3,而不能取1或2或0;
### Prefix and Suffix
为了让这篇文章能够让小白也能看得懂，我再这里解释一下什么叫做前缀和后缀：
假设字符串为S[0,...,n]，则
S的前缀为：`{S[0,...,i]:0<=i<n}`
S的后缀为：`{S[i,n]:0<i<=n}`
### Deduce the formula
ok,我们已经定义好了next数组的含义，我们接下来就开始寻找计算next数组的方法。
假设我们已经知道当前的next[j]=i，那么我们下一步肯定是考虑移动i或者j：
1. 若next[j]==next[i+1]，那么next[j+1]=i+1,即此时i++,j++；
2. 若next[j]!=next[i+1],那么P[0,...,i+1]!=P[j-i-1...,j],那么我们就应该`i=next[i]`( 这里看不懂没有关系，因为这个涉及到KMP的算法，即计算next数组本身也是一个字符匹配的问题，可以先记住这个步骤 )

### Initial the next
我们可以设定next[0]=-1，这样做的好处是：-1可以作为一个标记，当i=-1时，说明模式串P不可以再向右滑动了，此时j++。
`i=0,j=1`
i=0表示长度最小为0，j=1表示P[0,...j-1]，要使`j-1>=0`,则j>=1，所以j赋予初值1。

### Code

```c++
void calculateNext(string& P, int *Next) {
	int i = -1;
	int j = 0;
	int length = P.length();
	Next[0] = -1;
	while (j < length)
	{
		if (i == -1 || P[i] == P[j]) {
			i++;
			j++;
			Next[j] = i;
		}
		else {
			i = Next[i];
		}
	}
}
```

### Example
假设模式串P=abaabc，下面我们来计算模式串P的next数组：
1. 初始化i=-1,j=0,next[0]=-1。此时i==-1,所以i++,j++,得到i=0,j=1;所以此时next数组如下：

a|b|a|a|b|c|'\0'
---|---|---|---|---|---|---
-1|0|-|-|-|-|-

2. P[i]=P[0]='a',P[j]=P[1]='b',所以P[i]!=P[j],i=Next[i]=Next[0]=-1,然后i==-1,跳转到if语句，此时i++,j++,i=0,j=2,所以此时next数组如下：

a|b|a|a|b|c|'\0'
---|---|---|---|---|---|---
-1|0|0|-|-|-|-

3. P[i]=P[j]='a',所以i++,j++，此时i=1,j=3,next数组为

a|b|a|a|b|c|'\0'
---|---|---|---|---|---|---
-1|0|0|1|-|-|-

4. P[i]!=P[j],所以i=Next[i]=0,然后P[i]=P[j]='a'，所以i++,j++，此时i=1,j=4,Next数组为

a|b|a|a|b|c|'\0'
---|---|---|---|---|---|---
-1|0|0|1|1|-|-

5. P[i]=P[j]='b',所以i++,j++，此时i=2,j=5,next数组为

a|b|a|a|b|c|'\0'
---|---|---|---|---|---|---
-1|0|0|1|1|2|-

6.P[i]!=P[j],i=Next[i]=0,此时P[i]!=P[j],i=Next[i]=-1,所以i++,j++,i=0,j=6,Next[6]=0，此时next数组为：

a|b|a|a|b|c|'\0'
---|---|---|---|---|---|---
-1|0|0|1|1|2|0

7. 跳出循环。Next数组的计算结束。

## Sliding rule
### Rule
假设P[0,...,i-1]和T[j-q,j-1]匹配,有以下两种情况：
1. 若P[i]和T[j]相等，则P[0,...,i]和T[j-q,...,j]匹配
2. 若P[i]和T[j]不相等，则P[0,...,i]和T[j-q,...,j]不匹配，这时候就需要“将模式串向右滑动尽可能远的距离”，继续匹配。如果不能再继续向右滑动(i==-1)，则j++,i=0。

### Code
```c++
int KMP(string T, string P) {
	const int MAX_SIZE = 1000;
	int Next[MAX_SIZE];
	calculateNext(P, Next);
	int T_length = T.length();
	int P_length = P.length();
	int i = -1;
	int j = -1;
	while (i < P_length)
	{
		if (j >= T_length)
			return -1;
		if (i == -1 || T[j] == P[i]) {
			i++; j++;
		}
		else {
			i = Next[i];
		}
	}
	return j - P_length;
}
```
### Example
假设T=acabaabaabcacaabc,P=abaabcac,根据上面介绍的计算Next数组的方法，容易计算next数组的值为：

i|0|1|2|3|4|5|6|7
---|---|---|---|---|---|----|---
Pattern|a|b|a|a|b|c|a|c
next|-1|0|0|1|1|2|0|1

匹配过程如下：

![exampleOfKMP](/uploads/exampleOfKMP.jpg)

## Optimize KMP
其实在求next数组的时候还可以优化。比如说我们的模式串P=ababc,则next数组应该为：

a|b|a|b|c|\0
---|---|---|---|---|---
-1|0|0|1|2|0

但是，如果我们在i=3,即P[i]='b'的时候，如果和T[j]匹配不成功，则i=next[i]=1，此时P[i]='b'，还是和T[j]不匹配，这就是我们可以优化的地方。
所以我们可以这样操作： 
如果P[i]==P[j],则nextval[j]=nextval[i],否则nextval[j]=i;

### Code
```c++
/* P 为模式串，下标从 0 开始 */
void GetNextval(string P, int nextval[])
{
    int p_len = P.size();
    int i = -1;   // P 的下标
    int j = 0;  
    nextval[0] = -1;

    while (i < p_len - 1)
    {
        if (i == -1 || P[i] == P[j])
        {
            i++;
            j++;
          
            if (P[i] != P[j])
                nextval[j] = i;
            else
                nextval[j] = nextval[i];  // 既然相同就继续往前找真前缀
        }
        else
            i = nextval[i];
    }
}
```

## Application
### POJ 3461	Oulipo
The French author Georges Perec (1936–1982) once wrote a book, La disparition, without the letter 'e'. He was a member of the Oulipo group. A quote from the book:

Tout avait Pair normal, mais tout s’affirmait faux. Tout avait Fair normal, d’abord, puis surgissait l’inhumain, l’affolant. Il aurait voulu savoir où s’articulait l’association qui l’unissait au roman : stir son tapis, assaillant à tout instant son imagination, l’intuition d’un tabou, la vision d’un mal obscur, d’un quoi vacant, d’un non-dit : la vision, l’avision d’un oubli commandant tout, où s’abolissait la raison : tout avait l’air normal mais…

Perec would probably have scored high (or rather, low) in the following contest. People are asked to write a perhaps even meaningful text on some subject with as few occurrences of a given “word” as possible. Our task is to provide the jury with a program that counts these occurrences, in order to obtain a ranking of the competitors. These competitors often write very long texts with nonsense meaning; a sequence of 500,000 consecutive 'T's is not unusual. And they never use spaces.

So we want to quickly find out how often a word, i.e., a given string, occurs in a text. More formally: given the alphabet {'A', 'B', 'C', …, 'Z'} and two finite strings over that alphabet, a word W and a text T, count the number of occurrences of W in T. All the consecutive characters of W must exactly match consecutive characters of T. Occurrences may overlap.

**Input**
The first line of the input file contains a single number: the number of test cases to follow. Each test case has the following format:

One line with the word W, a string over {'A', 'B', 'C', …, 'Z'}, with 1 ≤ |W| ≤ 10,000 (here |W| denotes the length of the string W).
One line with the text T, a string over {'A', 'B', 'C', …, 'Z'}, with |W| ≤ |T| ≤ 1,000,000.

**Output**
For every test case in the input file, the output should contain a single number, on a single line: the number of occurrences of the word W in the text T.

**Sample Input**
3
BAPC
BAPC
AZA
AZAZAZA
VERDI
AVERDXIVYERDIAN
**Sample Output**
1
3
0

**分析：**
题目的意思就是让我们在文本串T中寻找有多少个模式串P。根据KMP算法，我们可以在匹配成功之后把模式串向右滑动，然后重新匹配。比如T=abcabcabc,P=abc,则在第一次匹配(i=3,j=3)完之后让模式串向右滑动：`i=next[i]`，此时i=-1,j=3.(i是指向模式串的索引，j是指向T的索引)。

**Accepted code**
```c++
#include<iostream>
#include<string>
using namespace std;

const int MAX_SIZE = 1000005;
int Next[MAX_SIZE];

void calculateNext(string& P, int *Next) {
	int i = -1;
	int j = 0;
	int length = P.length();
	Next[0] = -1;
	while (j < length)
	{
		if (i == -1 || P[i] == P[j]) {
			i++;
			j++;
			Next[j] = i;
		}
		else {
			i = Next[i];
		}
	}
}

int KMP_Count(string &T,string &P)
{
	calculateNext(P, Next);

	int T_length = T.length();
	int P_length = P.length();
	int i = -1;
	int j = -1;
	int res = 0;
	while (j < T_length&&i<P_length) {
		int k = i;
		if (i == -1 || T[j] == P[i]) {
			i++; j++;
		}
		else {
			i = Next[i];
		}
		if (i == P_length) {
			res++;
			i = Next[i];
		}
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string T, P;
		cin >> P >> T;
		cout << KMP_Count(T, P) << endl;
	}
}
```

### POJ 2752	Seek the Name, Seek the Fame
The little cat is so famous, that many couples tramp over hill and dale to Byteland, and asked the little cat to give names to their newly-born babies. They seek the name, and at the same time seek the fame. In order to escape from such boring job, the innovative little cat works out an easy but fantastic algorithm: 

Step1. Connect the father's name and the mother's name, to a new string S. 
Step2. Find a proper prefix-suffix string of S (which is not only the prefix, but also the suffix of S). 

Example: Father='ala', Mother='la', we have S = 'ala'+'la' = 'alala'. Potential prefix-suffix strings of S are {'a', 'ala', 'alala'}. Given the string S, could you help the little cat to write a program to calculate the length of possible prefix-suffix strings of S? (He might thank you by giving your baby a name:) 

**Input**
The input contains a number of test cases. Each test case occupies a single line that contains the string S described above. 

Restrictions: Only lowercase letters may appear in the input. 1 <= Length of S <= 400000. 

**Output**
For each test case, output a single line with integer numbers in increasing order, denoting the possible length of the new baby's name.

**Sample Input**
ababcababababcabab
aaaaa

**Sample Output**
2 4 9 18
1 2 3 4 5

**分析**
题目的意思是求一个字符串P的所有前缀字符串和后缀字符串相等的长度。我们可以在P中使用KMP算法求得next数组，得到最大长度的满足题目条件前缀字符串S1，然后在字符串S1中继续寻找满足题目条件的前缀字符串S2......，一直递归下去，直到找不到满足题目条件的字符串。然后逆序输出答案即可（递归或者栈）。下面这个图有利于理解：
![example](https://pic1.xuehuaimg.com/proxy/csdn/http://dl.iteye.com/upload/picture/pic/106268/654c396e-75c4-34c7-be81-780284370688.jpg)

**Accepted code**
```java
import java.util.Scanner;

public class Main {
	final static int MAX_SIZE=4000005;
	static int Next[]=new int [MAX_SIZE];
	static boolean first=true;
	
	static void getNext(String P) {
		int i=-1;
		int j=0;
		Next[0]=-1;
		int P_length=P.length();
		while(j<P_length) {
			if(i==-1||P.charAt(i)==P.charAt(j)) {
				i++;
				j++;
				Next[j]=i;
			}else {
				i=Next[i];
			}
		}
	}
	
	static void printRes(int i) {
		if(i<=0) {
			return ;
		}else {	
			printRes(Next[i]);
			if(first) {
				first=false;
			}else {
				System.out.print(" ");
			}
			System.out.print(i);
		}
	}
	
	public static void main(String[] args) {
		String S;
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			first=true;
			S=in.nextLine();
			getNext(S);
			printRes(S.length());
			System.out.println();
		}
		in.close();
	}

}
```
### POJ 2406	Power Strings
Given two strings a and b we define `a*b` to be their concatenation. For example, if `a = "abc"` and `b = "def"` then `a*b = "abcdef"`. If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: a^0 = "" (the empty string) and a^(n+1) = a*(a^n).

**Input**
Each test case is a line of input representing s, a string of printable characters. The length of s will be at least 1 and will not exceed 1 million characters. A line containing a period follows the last test case.

**Output**
For each s you should print the largest n such that s = a^n for some string a.

**Sample Input**
abcd
aaaa
ababab
.
**Sample Output**
1
4
3

**Hint**
This problem has huge input, use scanf instead of cin to avoid time limit exceed.

**分析**
这个题目的意思就是给出一个字符串S，让我们求这个字符串有多少个**最小循环节**。
这里给出方法，但是不证明：
如果`S.length%(S.length-next[S.length])==0`,那么答案就是`S.length/(S.length-next[S.length])`,否则就是1

**Accepted code**
```java
import java.util.Scanner;

public class Main {
	final static int MAX_SIZE=1000005;
	static int []next=new int[MAX_SIZE];
	static void calculateNext(String P) {
		int i=-1;
		int j=0;
		int P_length=P.length();
		next[0]=-1;
		while(j<P_length) {
			if(i==-1||P.charAt(i)==P.charAt(j)) {
				i++;
				j++;
				next[j]=i;
			}else {
				i=next[i];
			}
		}
	}
	public static void main(String []args) {
		String P;
		Scanner in = new Scanner(System.in);
		while(in.hasNext()) {
			P=in.nextLine();
			if(P.equals(".")) {
				break;
			}
			calculateNext(P);
			int P_length=P.length();
			int res;
			if(P_length%(P_length-next[P_length])==0) {
				res=P_length/(P_length-next[P_length]);
			}else {
				res=1;
			}
			System.out.println(res);
		}
		in.close();
	}
}
```