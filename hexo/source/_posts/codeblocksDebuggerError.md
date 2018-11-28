---
layout: post
title: codeblocks17.02不能调试的解决办法
date: 2018-10-10 23:58:10
categories: configer
---
前段时间codeblocks新出了一个版本17.02，于是我也去更新了。结果发现不能调试，出现了一下的错误信息：

```
Active debugger config: GDB/CDB debugger:Default
Building to ensure sources are up-to-date
Selecting target: 
Debug
ERROR: You need to specify a debugger program in the debuggers's settings.
(For MinGW compilers, it's 'gdb.exe' (without the quotes))
(For MSVC compilers, it's 'cdb.exe' (without the quotes))
```

结果发现没有配置好debugger，只要为debugger设置gdb的路径即可。

解决方法：
1. 在codeblocks打开Setting->Debuger->GDB/CDB debuger->default->Executable path:
2. 在Executable path填gdb.exe路径，gdb的默认路径是：C:\Program Files (x86)\CodeBlocks\MinGW\bin\gdb32.exe