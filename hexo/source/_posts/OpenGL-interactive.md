---
layout: post
title: OpenGL interactive
date: 2018-11-11 20:26:08
categories: 计算机图形学
---
这一篇文章讲的是：在OpenGL中检查窗口系统能够识别的各种事件，并且为应用程序需要处理的时间编写回调函数，以此来控制应用程序来对这些事件做出响应。

<!--more-->

# 鼠标交互

鼠标的交互事件有三种：

- **移动事件(move event)**: 如果鼠标在某个按键被按下时移动，那么就发生了移动事件。
- **被动移动事件(passive move event)**： 如果鼠标在移动时没有被按下，这个时间叫做被动移动事件。
- **鼠标事件（mouse event)**: 当鼠标的一个按键被按下或者释放，就发生了鼠标事件。

#### 鼠标回调函数

`glutMouseFunc(mouse)`描述的是鼠标事件，其中mouse的函数格式为`void mouse(int button, int state, int x, int y)`
其中

- button的值可能是GLUT_LEFT_BUTTON,GLUT_MIDDLE_BUTTON,GLUT_RIGHT_BUTTON表示哪个按钮导致了事件发生
- state表示相应按钮的状态：GL_UP, GL_DOWN
- x, y表示在**窗口**中的位置

#### 鼠标移动回调函数

`void glutMotionFunc(void (*func)(int x, int y));`描述的是移动事件。

#### 被动移动回调函数

`void glutPassiveMotionFunc(void (*func)(int x, int y));`描述的是鼠标被动事件。

值得注意的是，窗口坐标的原点为左上角，而右下角的坐标为(w-1,h-1)。

# 键盘交互

#### 普通按键事件

`void glutKeyboardFunc(void (*func)(unsigned char key,int x, int y));`来注册按下一个普通键所产生的事件的回调函数。

#### 特殊按键事件

`void glutSpecialFunc(void (*func)(int key, int x, int y))`来注册按下一个特殊事件所产生的回调函数。

# 显示回调函数

`glutDisplayFunc(display)`注册要执行的显示回调函数display。
许多事件都会导致调用显示回调函数，这会导致遍历一次事件循环的过程中多次执行显示回调函数
可以用下列方法避免这个问题
`glutPostRedisplay();`这条语句设置一个标志
当事件循环结束时，GLUT会检查是否设置了上述标志，如果设置了标志，那么就会执行显示回调函数

# 双缓存

1. 在主函数中申请双缓存： `glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH)`
2. 在显示回调函数的末尾添加: `glutSwapBuffers()`

注意： 系统默认使用单缓存

# 菜单

1. 为每一个菜单注册一个回调函数: `int glutCreateMenu(void (*func)(int value));`
2. 定义对应菜单中每一个选项的功能: `void glutAddMenuEntry(char *name, int value);`
3. 和鼠标的某个特定按键关联起来: `void glutAttachMenu(int button);`

例如：
创建菜单：

```c++
void createMenu(){
    //注册菜单回调函数
    glutCreateMenu(demo_menu);
    //分别为菜单的每一个选项定义功能
    glutAddMenuEntry("quit",1);
    glutAddMEnuEntry("start rotation",2);
    //和特定的按键关联起来
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
```

其中菜单回调函数为：

```c++
void demo_menu(int id){
    switch(id){
        case 1:
            exit(0);
            break;
        case 2:
            rotate();
            break;
    }
    glutPostRedisplay();
}
```

当然，如果我们需要将rotate有关的操作放在一个子菜单的话，我们可以安装如下操作：

```c++
void createMenu() {
	//注册子菜单
	int sub_menu = glutCreateMenu(demo_menu);
	//添加到子菜单
	glutAddMenuEntry("start rotation", 2);
	glutAddMenuEntry("stop rotation", 3);
	//注册主菜单回调函数
	glutCreateMenu(demo_menu);
	//分别为菜单的每一个选项定义功能
	glutAddMenuEntry("quit", 1);
	//添加子菜单
	glutAddSubMenu("rotation control", sub_menu);
	//和特定的按键关联起来
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
```