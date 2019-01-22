#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jan 21 20:17:58 2019

@author: qingyingliu
"""
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import time
from sort import *

size_list = [10000*x for x in range(1,101)]
sort_type = ['heapSort','quickSort','mergeSort','shellSort','countSort',
             'radixSort','bucketSort']

# recode the running time
data = []

for size in size_list:
    random_data = list(np.random.randint(1000000,size=size))
    
    line = []
    
    #heapSort
    start_time = time.time()
    heapSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    #quickSort
    start_time = time.time()
    quickSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    #mergeSort
    start_time = time.time()
    mergeSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    #shellSort
    start_time = time.time()
    shellSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    #countSort
    start_time = time.time()
    countSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    #radixSort
    start_time = time.time()
    radixSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    #bucketSort
    start_time = time.time()
    bucketSort(random_data)
    end_time = time.time()
    interval = end_time - start_time
    line.append(interval)
    
    data.append(line)
    print('size: ' + str(size) + ' finished')
    for j in range(7):
        print(sort_type[j]+": ",line[j])
        

df = pd.DataFrame(data,index=size_list,columns=sort_type)
df.index.name = 'size'
df = df*1000
df.plot(legend=True)
plt.grid(True)
plt.xlabel('data number')
plt.ylabel('time(ms)')
plt.xlim(0,1000000)
plt.show()
df.to_csv('runtime.csv')

