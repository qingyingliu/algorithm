---
layout: post
title: open z-buffer algorithm(开启深度测试)
date: 2018-10-21 01:46:24
categories: 计算机图形学
---
只要三个步骤就能够开启OpenGL的深度测试：

1. modifying the initialization of the display mode to the following: **(in main function)**
`glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);`
2. enable the algorithm by the function call:**(in main or init function)**
`glEnable(GL_DEPTH_TEST);`
3. modify the clear procedure:**(in display function)**
`glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);`