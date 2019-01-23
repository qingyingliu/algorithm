# -*- coding: utf-8 -*-
"""
Created on Sun Jan 20 16:22:21 2019
@author: qingyingliu
"""

'''
    this is select sort
'''
def selectSort(data,start=0,end=None,ascending=True,inplace=False):
    # don't change oringin data
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    # we first sort ascendingly
    for i in range(start,end):
        temp = i
        for j in range(i+1,end):
            if data[j] < data[temp]:
                temp = j
        data[i],data[temp] = data[temp],data[i]
        
    # if descending
    if not ascending:
        data[start:end].reverse()
    return data


'''
    this is heap sort
'''
def buildHeap(data):
    n = len(data)
    for i in range(n//2,0,-1):
        cur_loc = i
        while True:
            left_child = cur_loc*2
            right_child = cur_loc*2+1
            flag = -1
            max_child_index = left_child
            if right_child<=n and data[right_child-1] > data[left_child-1]:
                max_child_index = right_child
            if max_child_index <=n and data[cur_loc-1] < data[max_child_index - 1]:
                data[cur_loc-1],data[max_child_index-1] = data[max_child_index-1],data[cur_loc-1]
                if max_child_index == left_child:
                    flag = 0
                else:
                    flag = 1
            if flag == -1:
                break
            elif flag == 0:
                cur_loc = 2 * cur_loc
            else:
                cur_loc = 2*cur_loc + 1
    return data

def heapSort(data,start=0,end=None,ascending=True,inplace=False):
    # don't change oringin data
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    data = buildHeap(data[start:end])
    # 筛选
    for j in range(end,start,-1):
        data[j-1],data[start] = data[start],data[j-1]
        cur_loc = start+1
        while True:
            left_child = cur_loc*2
            right_child = cur_loc*2+1
            flag = -1
            max_child_index = left_child
            if right_child<j and data[right_child-1] > data[left_child-1]:
                max_child_index = right_child
            if max_child_index <j and data[cur_loc-1] < data[max_child_index - 1]:
                data[cur_loc-1],data[max_child_index-1] = data[max_child_index-1],data[cur_loc-1]
                if max_child_index == left_child:
                    flag = 0
                else:
                    flag = 1
            if flag == -1:
                break
            elif flag == 0:
                cur_loc = 2 * cur_loc
            else:
                cur_loc = 2*cur_loc + 1
    
    # if descending
    if not ascending:
        data[start:end].reverse()
    return data

def bubbleSort(data,start=0,end=None,ascending=True,inplace=False):
    # don't change oringin data
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
        
    if start > end-1:
        return []
    if start == end-1:
        return data
    
    for i in range(start,end):
        for j in range(start,end-1):
            if data[j] > data[j+1]:
                data[j],data[j+1] = data[j+1],data[j]
    # if descending
    if not ascending:
        data[start:end].reverse()
    return data


def partition(data,start,end):
    pivot_value = data[start]
    leftmark = start
    rightmark = end - 1
    while leftmark < rightmark:
        while leftmark < rightmark and data[rightmark] >= pivot_value:
            rightmark = rightmark - 1
        if leftmark < rightmark:
            data[leftmark] = data[rightmark]
            leftmark = leftmark+1
        while leftmark < rightmark and data[leftmark] <= pivot_value:
            leftmark = leftmark + 1
        if leftmark < rightmark:
            data[rightmark] = data[leftmark]
            rightmark = rightmark - 1

    data[leftmark] = pivot_value
    return leftmark

def quickSort(data,start=0,end=None,ascending=True,inplace=False):
    # don't change oringin data
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    if start >= end:
        return []
    split_point = partition(data,start,end)
    quickSort(data,start=start,end=split_point,inplace=True)
    quickSort(data,start=split_point+1,end=end,inplace=True)
    # if descending
    if not ascending:
        data[start:end].reverse()
    return data

def mergeSort(data,start=0,end=None,ascending=True,inplace=False):
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    mid = (start + end) // 2
    mergeSort(data,start=start,end=mid,inplace=True)
    mergeSort(data,start=mid,end=end,inplace=True)
    i = 0
    j = mid-start
    copy_data = data[start:end]
    for cur_loc in range(start,end):
        if i < mid-start:
            if j < end-start and copy_data[i] > copy_data[j]:
                data[cur_loc] = copy_data[j]
                j = j + 1
            else:
                data[cur_loc] = copy_data[i]
                i = i + 1
        else:
            if j < end-start:
                data[cur_loc] = copy_data[j]
                j = j + 1
            else:
                break
    # if descending
    if not ascending:
        data[start:end].reverse()
    return data

def insertSort(data,start=0,end=None,ascending=True,inplace=False,gap=1):
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    
    for i in range(start+1,end):
        cur_loc = i 
        cur_val = data[i]
        while cur_loc-gap >= start and data[cur_loc-gap] > cur_val:
            data[cur_loc] = data[cur_loc-gap]
            cur_loc = cur_loc - gap
        data[cur_loc] = cur_val
    
    if not ascending:
        data[start:end].reverse()
    return data

def shellSort(data,start=0,end=None,ascending=True,inplace=False):
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    
    mid = (start+end)//2
    while mid >= 1:
        insertSort(data,start=start,end=end,inplace=True,gap=mid)
        mid = mid//2
        
    if not ascending:
        data[start:end].reverse()
    return data

# notice: data must be positive integer
def countSort(data,start=0,end=None,ascending=True,inplace=False):
    if not inplace:
        data = data.copy()
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    
    c = []
    k = max(data[start:end])
    for i in range(k+1):
        c.append(0)
    
    for item in data[start:end]:
        c[item] = c[item] + 1
    
    for i in range(1,k+1):
        c[i] = c[i-1] + c[i]

    cp = data[::]
    for i in range(end-1,start-1,-1):
        item = cp[i]
        data[c[item]-1+start] = item
        c[item] = c[item] - 1

    if not ascending:
        data[start:end].reverse()
    return data

def radixSort(data,start=0,end=None,ascending=True,inplace=False):
    if not inplace:
        data = data.copy()
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    res = data[start:end]
    import math
    h = math.ceil(math.log10(max(data[start:end])))
    for i in range(h):
        radix = 10**i
        container = []
        for j in range(10):
            container.append([])
        # destribute
        for item in res:
            container[int(item/radix)%10].append(item)
        # merge
        res.clear()
        for j in range(10):
            res.extend(container[j])
    data[start:end] = res
    if not ascending:
        data.reverse()
    return data 

def bucketSort(data,start=0,end=None,ascending=True,inplace=False):
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data
    bucket = []
    n = len(data)//2
    for i in range(n):
        bucket.append([])
        
    max_val,min_val = max(data),min(data)
    unit = int(max_val - min_val)//n + 1
    
    for item in data[start:end]:
        loc = int(item-min_val)//unit
        bucket[loc].append(item)
        
    res = []
    for i in range(n):
        res.extend(quickSort(bucket[i]))
    data[start:end] = res
    if not ascending:
        data.reverse()
    return data

def timSort(data,start=0,end=None,ascending=True,inplace=False):
    if not inplace:
        data = data.copy()
    
    if end == None:
        end = len(data)
    
    if start > end-1:
        return []
    if start == end-1:
        return data

    

    if not ascending:
        data.reverse()
    return data
    