---
title: binary search tree
date: 2018-11-27 16:14:24
categories: data structure
---

### 二叉搜索树的概念
在《算法导论》中是这样定义的：
> 二叉搜索树，对任何结点x，其左子树的关键字最大不超过x.key，其右子树的关键字最小不低于x.key。

注： 上面的`关键字`表示的是结点的数据域，下同。

在二叉搜索树中，不同的二叉搜索树可以表示同一数值的集和，所以我们后面还会讨论如何构建更好的二叉树（不是这一篇文章)。比如下面的两颗二叉搜索树就表示了相同的集合。
![binarytree1](/uploads/bst1.png)
下面我们直接进入主题，如何构建二叉搜索树，如何对二叉搜索树进行操作，包括插入、删除和查找。

### 二叉搜索树的操作

#### 查询

在二叉搜索树中，最简单的就是查询一个（可以比较的）元素是不是属于二叉搜索树的，因为根据二叉搜索树的定义可以知道，对于一个需要查找的元素element，如果element大于当前结点，那么它肯定是只可能存在于右子树；同理，如果element小于当前结点，那么它肯定只可能存在于右子树，如果element的关键字等于当前结点的关键字，那么当前结点就是我们需要查找的结点。

```python
def search(x,element):
    if x == null:
        return null
    if x > element:
        return search(x.left,element)
    elif x < element:
        return search(x.right,element)
    else:
        return x
```

当然，我们除了查找特定值之外，我们还可以查找最到最小值。根据二叉搜索树的定义，最小值肯定是在最左边，最大值肯定是最右边。通过O(h)的时间复杂度可以找到。
```python
# x是当前结点
def find-min(x):
    if x.left != null:
        return find-min(x.left)
    else:
        return x
```

```python
def find-max(x):
    if x.right != null:
        return find-max(x.right)
    else:
        return x
```

除此之外，我们还可以查找x的后继，这在删除一个结点的时候会用到。
注： 一个结点x的后继是大于x.key的最小关键字的结点。
下面根据x结点是否有右结点来进行讨论：
- 如果x存在右结点（或者右子树），那么后继肯定存在右子树
- 如果x不存在右结点，则后继y只可能存在于x的最底层祖先（根结点），且y的左孩子也是x的一个祖先
```python
def find-successor(x):
    # 如果存在右子树，则返回右子树的一个最小值
    if(x.right!=null):
        return find-min(x.right)

    y = x.father
    while(y!=null and x==y.right):
        x= y
        y = y.father
    return y
```


#### 插入
插入是一个动态更新二叉搜索树的过程，而我们需要去做的就是去更新结点的位置和相关属性(left,right,father)。
首先我们需要找到插入的位置，这个时候我们需要使用类似于查找的方法找到插入的位置，然后再更新插入之后的相关属性即可。

```python
def insert(element):
    # 从根开始找
    x = root
    y = null
    while(x!=null):
        y =x
        if x.key > element:
            x = x.left
        else:
            x = x.right
    # 此时的x就是我们要插入的结点的位置
    
    #插入之后还需要更新结点的信息
    x.father = y
    if(x.key>y.key):
        y.right = x
    else:
        y.left = x
```

#### 删除
从一颗二叉搜索树中删除一个结点x可以分为三种基本情况：
- 如果x没有孩子结点，那么只是将他简单地删除即可，并修改它的父结点
- 如果x只有一个孩子结点，那么将这个孩子提上来，代替x，并修改x的父结点
- 如果x有两个孩子结点，此时后继肯定存在于右子树，这个时候需要把右子树提上来即可。
```python
def delete(element):
    #先找到元素的位置,x
    x = find(element)
    
    #第一种情况，没有左右孩子
    if x.left == null and x.right ==null:
        update(x.father,x)
        del x
        
    #第三种情况，有两个孩子结点
    if x.left != null and x.right != null:
        successor = find-min(x.right)
        # 如果x是左孩子
        if x.father.left == x:
            x.father.left = successor
            successor.left = x.left
            successor.right = x.right
            del x
    
        #如果x是右孩子，类似与左孩子

    #第二种情况，只有一个孩子结点
    #如果是左孩子：
    if x.left != null and x.right == null:
        x.father.child = x.left
        x.left.father = x.father
    #如果是右孩子，类似于左孩子，这里不再写出
```
