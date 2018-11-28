---
title: stack application
categories: data-structure
date: 2018/10/01 10:00:00 
---
## Train Problem I HDU - 1022

As the new term comes, the Ignatius Train Station is very busy nowadays. A lot of student want to get back to school by train(because the trains in the Ignatius Train Station is the fastest all over the world ^v^). But here comes a problem, there is only one railway where all the trains stop. So all the trains come in from one side and get out from the other side. For this problem, if train A gets into the railway first, and then train B gets into the railway before train A leaves, train A can't leave until train B leaves. The pictures below figure out the problem. Now the problem for you is, there are at most 9 trains in the station, all the trains has an ID(numbered from 1 to n), the trains get into the railway in an order O1, your task is  to determine whether the trains can get out in an order O2.   
<!--more-->

**Input**

The input contains several test cases. Each test case consists of an integer, the number of trains, and two strings, the order of the trains come in:O1, and the order of the trains leave:O2. The input is terminated by the end of file. More details in  the Sample Input. 

**Output**
The output contains a string "No." if you can't exchange O2 to O1, or you should output a line contains "Yes.", and then output your way in exchanging the order(you should output "in" for a train getting into the railway, and "out" for a train getting out  of the railway). Print a line contains "FINISH" after each test case. More details in the Sample Output. 
  
**Sample Input**

>3 123 321
>3 123 312

**Sample Output**

>Yes.
>in
>in
>in
>out
>out
>out
>FINISH
>No.
>FINISH

**思路**

假设输入的两个字符串分别为s1,s2。

这题有两种思路：

思路一：

通过遍历所有的可能出栈序列，然后再查找是否有s2。遍历的方法是：
每次入栈的时候都可以选择pop出当前的所有栈。时间复杂度很大，很麻烦。

思路二：

设变量index指向s2的第一个元素，每次栈压入一个元素的时候，都判断s2[index]是否和栈顶匹配。
如果匹配，则stack pop，index++。

当遍历完了s1的所有元素，如果stack为空，且index==n，则说明s2是s1的出栈序列，否则不是。
至于"in"和"out"的输出，用队列queue储存。

**accepted code:**

```c++
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main()
{
	int n;
	string s1, s2;
	while (cin >> n >> s1 >> s2)
	{
		stack<char> train;
		queue<string> res;
		int index = 0;

		for (int k = 0; k < n; k++)
		{
			train.push(s1[k]);
			res.push("in");
			while (!train.empty()&&train.top() == s2[index]) {
				index++;
				train.pop();
				res.push("out");
			}
		}

		if (train.empty() && index == n) {
			cout << "Yes." << endl;
			while (!res.empty())
			{
				cout << res.front() << endl;
				res.pop();
			}
		}
		else {
			cout << "No." << endl;
		}
		cout << "FINISH" << endl;
	}
}
```

## 迷宫问题

**题目描述**

给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]


**输入**

第一行输入t，表示有t个迷宫

第二行输入n，表示第一个迷宫有n行n列

第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过

输入n行

以此类推输入下一个迷宫

**输出**

逐个输出迷宫的路径

如果迷宫不存在路径，则输出no path并回车

如果迷宫存在路径，将路径中每个方格的x和y坐标输出，从起点到终点，每输出四个方格就换行，最终以单词END结尾，具体格式参考示范数据

**样例输入**

>2
>8
>0 0 0 1 1 1 1 1
>1 0 0 0 1 0 0 1
>1 0 0 0 1 0 0 0
>1 1 0 0 0 0 0 1
>0 0 1 1 0 1 1 0
>0 0 0 0 0 0 1 1
>1 1 1 1 1 0 0 1
>0 0 0 0 1 0 0 0
>7
>0 0 0 1 1 1 1
>1 0 0 1 0 0 1
>1 0 0 1 0 0 0
>1 1 0 0 0 0 1
>0 0 1 1 0 1 0
>1 0 0 0 0 1 0
>0 0 0 0 1 1 0

**样例输出**

>[0,0]--[0,1]--[0,2]--[1,2]--
>[1,3]--[2,3]--[3,3]--[3,4]--
>[4,4]--[5,4]--[5,5]--[6,5]--
>[6,6]--[7,6]--[7,7]--END
>no path

**思路**

这题可以用深度优先搜索和宽度优先搜索，由于这里主要讲的是栈的应用，所以这里讲深度优先搜索。

首先，我们分析一下样例的输出，如果我们从[0,0]这个位置开始搜索，我们要去判断是否有这样的路径，

这就需要依靠是否到达[n-1,n-1],如果可以，就输出路径的话，这时候会先输出[n-1,n-1]。

所以，我们可以从[n-1,n-1]开始搜索，如果到达[0,0]，就可以开始输出路径了。

那么怎样搜索呢?

对于每个格子，我们都可以走上下左右四个方向，但是由于不走重复路径，我们不走退路，即和当前方向相同的路径不走。
当走到[0,0]，终止递归，开始返回，输出路径。

定义方向：

```c++
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
```

搜索代码(递归)：

```c++
bool dfs(int x, int y, int dir) {
	if (visited[x][y])
		return false;
	if (x == 0 && y == 0 && maze[x][y] == 0)
	{
		cout << "[0,0]--";
		return true;
	}
	if (!isValid(x, y, n))
		return false;

	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if ((i + dir) % 2 == 0 && i != dir) {
			continue;
		}
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (dfs(next_x, next_y, i)) {
			if (++cnt % 4 == 0)
				cout << endl;
			cout << "[" << x << "," << y << "]--";
			return  true;
		}
	}
	return false;
}
```

将递归转化成stack形式：

每一次递归的参数的保存：

```c++
 
struct Parameter
{
    int self, father;//self is the address of current function;father is the address of function calling this function
    int x, y, dir,subdir;
    Parameter() {}
    Parameter(int s, int f, int xx, int yy, int d) {
        self = s;
        father = f;
        x = xx;
        y = yy;
        dir = d;
        subdir = 0;
    }
};
```

终止条件：

```c++
if (top.x == 0 && top.y == 0&&maze[top.x][top.y]==0) {
    cout << "[0,0]--";
    res[top.father] = true;
    s.pop();
}
```

当前的点遍历完了所有的情况,返回结果并输出路径，出栈：

```c++
else if (top.subdir >= 3) {
	res[top.father] = res[top.father] || res[top.self];
    if (res[top.self]) {
    cout << "[" << top.x << "," << top.y << "]--";
		if ((++counter) % 4 == 0) {
			cout << endl;
		}
	}
    s.pop();
}
```

递归调用，入栈：

```c++
    else {
        Parameter peek=s.top();
        peek.subdir++;
        s.pop();
        top = peek;
        s.push(peek);
        if (top.subdir - 1 + top.dir % 2 == 0 && top.subdir - 1 != top.dir)
            continue;
        if (!isValid(top.x + dx[top.subdir - 1], top.y + dy[top.subdir-1]))
            continue;
        if (visited[top.x + dx[top.subdir - 1]][top.y + dy[top.subdir - 1]])
            continue;
             
        int self;
        do {
            self = rand() % maxSize;
        } while (used[self]);
        used[self] = true;
        visited[top.x][top.y] = true;
        s.push(Parameter(self, top.self, top.x + dx[top.subdir - 1], top.y + dy[top.subdir-1], top.subdir));
       
    }
```

**accepted code**

```c++
#include<bits/stdc++.h>
#include<stack>
 
using namespace std;
 
const int maxSize = 100000;
const int maxn = 100;
int n;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
bool res[maxSize];
bool used[maxSize];
bool visited[maxn][maxn];
int maze[maxn][maxn];
 
struct Parameter
{
    int self, father;//self is the address of current function;father is the address of function calling this function
    int x, y, dir,subdir;
    Parameter() {}
    Parameter(int s, int f, int xx, int yy, int d) {
        self = s;
        father = f;
        x = xx;
        y = yy;
        dir = d;
        subdir = 0;
    }
};
 
bool isValid(const int &x, const int &y) {
    return x >= 0 && y >= 0 && x < n&&y < n&&maze[x][y] == 0;
}
bool dfs() {
    memset(res, false, sizeof(res));
    memset(visited, false, sizeof(visited));
    memset(used, false, sizeof(used));
    int counter = 1;
 
    int x = n - 1, y = n - 1, dir = 0;
    stack<Parameter> s;
    used[0] = true;
    if (maze[x][y])
        return false;
    else {
        s.push(Parameter(0, 0, x, y, dir));
    }
    used[0] = true;
    //visited[n - 1][n - 1] = true;
 
    while (!s.empty()) {
        Parameter top = s.top();
 
        if (top.x == 0 && top.y == 0&&maze[top.x][top.y]==0) {
            cout << "[0,0]--";
            res[top.father] = true;
            s.pop();
        }
        else if (top.subdir >= 3) {
            res[top.father] = res[top.father] || res[top.self];
            if (res[top.self]) {
                cout << "[" << top.x << "," << top.y << "]--";
                if ((++counter) % 4 == 0) {
                    cout << endl;
                }
            }
            s.pop();
            //visited[top.x][top.y] = true;
        }
        else {
            Parameter peek=s.top();
            peek.subdir++;
            s.pop();
            top = peek;
            s.push(peek);
            if (top.subdir - 1 + top.dir % 2 == 0 && top.subdir - 1 != top.dir)
                continue;
            if (!isValid(top.x + dx[top.subdir - 1], top.y + dy[top.subdir-1]))
                continue;
            if (visited[top.x + dx[top.subdir - 1]][top.y + dy[top.subdir - 1]])
                continue;
             
            int self;
            do {
                self = rand() % maxSize;
            } while (used[self]);
            used[self] = true;
            visited[top.x][top.y] = true;
            s.push(Parameter(self, top.self, top.x + dx[top.subdir - 1], top.y + dy[top.subdir-1], top.subdir));
            //cout << top.x << " " << top.y << endl;
        }
 
    }
    return res[0];
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> maze[i][j];
            }
        }
        if (dfs()) {
            cout << "END" << endl;
        }
        else {
            cout << "no path" << endl;
        }
    }
}
```

## 表达式计算

**题目描述**

计算一个表达式的运算结果

**输入**

第一个输入t，表示有t个实例

第二行起，每行输入一个表达式，每个表达式末尾带#表示结束

输入t行

**输出**

每行输出一个表达式的计算结果，计算结果用浮点数（含4位小数）的格式表示

**样例输入**

>2
>1+2*3-4/5#
>(66+(((11+22)*2-33)/3+6)*2)-45.6789#

**样例输出**

>6.2000
>54.3211

**思路**

首先，我们分析一下合理的表达式的所有符号有：

`+`,`-`,`*`,`/`,`(`,`)`,`#`

当遇到`#`就结束。遇到`+` or `-`，将运算符压入栈(因为优先级最低，最后才算)

遇到`*` or `/`，如果当前栈顶的运算符小于当前运算符，则进行运算，否则，将运算符入栈。

遇到`(`则入栈，是`)`pop的终止标志;遇到`)`，则开始进行运算，直到遇到`(`。(优先级最高，先算)

**accepted code**

```c++
#include<bits/stdc++.h>
#include<string>
#include<stack>
using namespace std;

double stringToDouble(string x)
{
    stringstream xx(x);
    double res;
    xx>>res;
    return res;
}
int min(int a,int b,int c,int d,int e,int f)
{
    const int inf=0x3f3f3f3f;
    if(a==-1)
        a=inf;
    if(c==-1)
        c=inf;
    if(b==-1)
        b=inf;
    if(d==-1)
        d=inf;
    if(e==-1)
        e=inf;
    if(f==-1)
        f=inf;
    return min(a,min(b,min(c,min(d,min(e,f)))));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string exp;
        cin>>exp;
        stack<double> operand;
        stack<char> opcode;
        while(!opcode.empty()){
            opcode.pop();
        }
        for(int i=0; i<exp.size(); i++)
        {

            if(exp[i]>'0'&&exp[i]<'9')
            {
                operand.push(stringToDouble(exp.substr(i)));
                i=min(exp.find('+',i),exp.find('-',i),exp.find('*',i),exp.find('/',i),exp.find('#',i),exp.find(')',i))-1;
            }
            else
            {
                if(exp[i]=='+'||exp[i]=='-')
                {
                    while((!opcode.empty())&&(opcode.top()=='*'||opcode.top()=='/'))
                    {
                        double a=operand.top();
                        operand.pop();
                        double b=operand.top();
                        operand.pop();
                        char op=opcode.top();
                        opcode.pop();
                        if(op=='*')
                        {
                            operand.push(a*b);
                        }
                        else
                        {
                            operand.push(b/a);
                        }
                    }
                    opcode.push(exp[i]);
                }
                else if(exp[i]=='#')
                {
                    break;
                }
                else if(exp[i]=='*'||exp[i]=='/')
                {
                    opcode.push(exp[i]);
                }
                else if(exp[i]==')')
                {
                    while(opcode.top()!='(')
                    {

                        double a=operand.top();
                        operand.pop();
                        double b=operand.top();
                        operand.pop();
                        char op=opcode.top();
                        opcode.pop();
                        if(op=='+')
                        {
                            operand.push(a+b);
                        }
                        else if(op=='-')
                        {
                            operand.push(b-a);
                        }
                        else if(op=='*')
                        {
                            operand.push(a*b);
                        }
                        else
                        {
                            operand.push(b/a);
                        }

                    }
                    opcode.pop();
                }else{
                    opcode.push(exp[i]);
                }
            }
        }

        while(operand.size()!=1)
        {
            double a=operand.top();
            operand.pop();
            double b=operand.top();
            operand.pop();
            char op=opcode.top();
            opcode.pop();
            if(op=='+')
            {
                operand.push(a+b);
            }
            else if(op=='-')
            {
                operand.push(b-a);
            }
            else if(op=='*')
            {
                operand.push(a*b);
            }
            else
            {
                operand.push(b/a);
            }
        }
        cout<<fixed<<setprecision(4)<<operand.top()<<endl;
    }
}
```
