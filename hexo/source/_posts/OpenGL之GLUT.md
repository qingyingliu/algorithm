---
title: OpenGL之GLUT库
categories: 计算机图形学
date: 2018/10/01 10:00:00
---
# GLUT - The OpenGL Utility Toolkit
glut是**基本的窗口界面**，是独立于gl和glu的，如果不喜欢用glut可以用MFC和Win32窗口等代替，但是glut是**跨平台**的，这就保证了我们编出的程序是跨平台的，如果用MFC或者Win32只能在windows操作系统上使用。选择OpenGL的一个很大原因就是因为它的跨平台性，所以我们可以尽量的使用glut库。

# 回调函数
回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
<!--more-->
# GLUT Function

## 初始化

`void glutInit(int *argc,char **argv);`这个函数用来初始化GLUT库。对于main函数的形式是：`int main(int argc,char *argv[])`，这个函数从`main`函数获取其两个参数。

`void glutInitWindowSize(int width,int height);`
`void glutInitWindowPosition(int x,int y)`;
这两个函数分别设置窗口的大小和位置(相对于left,up)。以像素为单位。

`void glutInitDisplayMode(unsigned int mode)`设置图形显示模式。参数`mode`的可选值为：
- `GLUT_RGBA`: 当未指明`GLUT_RGBA`或者`GLUT_INDEX`时，是默认的使用模式。表面欲建立RGBA模式的窗口。
- `GLUT_INDEX`: 指明颜色索引模式。
- `GLUT_SINGLE`:只使用单缓存。
- `GLUT_DOUBLE`:使用双缓存。以避免把计算机作图的过程都表现出来，或者为了平滑地实现动画。
- `GLUT_ACCUM`: 让窗口使用累加的缓存。
- `GLUT_ALPHA`: 让颜色缓冲区使用alpha组件。
- `GLUT_DEPTH`: 使用深度缓存
- `GLUT_STENCIL`: 使用模板缓存。
- `GLUT_MULTISAMPLE`: 让窗口支持多例程。
- `GLUT_STEREO`: 使窗口支持立体。
- `GLUT_LUMINACE`: luminance是亮度的意思。但是大多数OpenGL不被支持。


## 事件处理(event processing)

`void glutMainLoop(void);`：让glut程序进入事件循环。在一个glut程序中最多只能调用一次，一旦调用，会知道程序结束才返回

## 窗口管理(Window Management)

`int glutCreateWindow(char *name);`：产生一个顶层窗口。name作为窗口的名字，也就是窗口标题栏显示的内容。**返回值是生成窗口的标记符**，可用`glutGetWindow()`加以引用.

`int glutCreateSubWindow(int win,int x,int y,int width,int height)`:创建一个子窗口，win是父窗口的标记符。x,y是相对父窗口的位移，以像素表示。width,height是子窗口的宽和高。

`void glutSetWindow(int win)` :设置标识符为win的窗口为当前窗口

`int glutGetWindow(void)`: 返回当前窗口的标识符.

`void glutDestroyWindow(int win)`: 销毁以win标记的窗口。

`void glutPostRedisplay(void)`: 将当前窗口打上标记，标记其需要再次显示。

`void glutSwapBuffers(void)`:**当窗口模式为双缓存时**，此函数的功能就是把后台缓存的内容交换到前台显示。当然，只有单缓存时，使用它的功能跟用glFlush()一样。

而使用双缓存是为了把完整图画一次性显示在窗口上，或者是为了实现动画。

`void glutPosition(int x,int y);`:改变当前窗口的位置：当前窗口是顶层窗口时，x,y是相对于屏幕的的位移；当前窗口若是子窗口时，x,y是相对其父窗口原点的位移.

`void glutReshapeWindow(int width,int height)`：改变当前窗口的大小

`void glutFullscreen(void);`:让当前窗口全屏显示。当前窗口是顶层窗口时才有效。

`void glutPopWindow(void);`, `void glutPushWindow(void);`:对顶层窗口和子窗口均有效。改变当前窗口在栈中相对于其它窗口的次序。

`void glutIconifyWindow(void);`,`void glutShowWindow(void);`,`void glutHideWindow(void);`:这三个函数作用是改变当前窗口的显示状态。注意：glutIconifyWindow让当前窗口成为一个图标，也即是最小化。

`void glutSetWindowTitle(char* name);`,`void glutSetIconTitle(char* name);`：设置当前窗口（必须是顶层窗口）的标题和图标化时的标题。

`void glutSetCursor(int cursor);`:设置当前窗口的光标样式。
cursor的可选值有：

- GLUT_CURSOR_RIGHT_ARROW指向右边的光标
- GLUT_CURSOR_LEFT_ARROW指向左边的光标
- GLUT_CURSOR_INFO成为手状。
- GLUT_CURSOR_DESTROY呈叉状
- GLUT_CURSOR_HELP呈现问号的形状

## 菜单管理

`int glutCreateMenu(void(*func)(int value));`:当点击菜单时,调用**回调函数func**，value为传递给回调函数的数值,它由所选择的菜单条目对应的整数值所决定。这个函数创建一个新的弹出式菜单,并返回一个唯一的标识次菜单的整型标识符,并将新建的弹出菜单与func函数关联在一起,这样,当选择此菜单中的一个菜单条目时,调用回调函数func.

`void glutSetMenu(int menu);`:设置当前菜单;

`int glutGetMenu(void);`:获取当前菜单的标识符

`void glutDestroyMenu(int menu);`:删除指定的菜单

`void glutAddMenuEntry(char* name, int value);`:添加一个菜单条目

`void glutAddSubMenu(char* name, int menu);`:在当前菜单的底部增加一个子菜单的触发条目

`void glutChangeToMenuEntry(int entry, char* name, int value);`:更改当前菜单中指定菜单项

`void glutChangeToSubMenu(int entry, char* name, int menu);`:将指定的当前菜单中菜单项变为子菜单触发条目

`void glutRemoveMenuItem(int entry);`:删除指定的菜单项

`void glutAttachMenu(int button);`:把当前窗口的一个鼠标按键与当前菜单关联起来

`void glutDetachMenu(int button)`:解除鼠标按键与弹出式菜单的关联关系。

## 注册回调

`void glutDisplayFunc(void (*func)(void));`：为当前窗口设置回调函数

`void glutOverlayDisplayFunc(void(*func)(void))`注册当前窗口的重叠层的显示回调函数

`void glutReshapFunc(void(*Func)(intt width,int height))`:指定当前窗口的大小改变时的调用的函数

`void glutKeyboardFunc(void(*func(unsign char key,int x,int y)))`:注册当前窗口的键盘回调函数


`void glutMouseFunc(void(*func)(int button,int state,int x,int y))`:注册指定当前的鼠标回调函数。
button为鼠标的按键：为以下定义的常量：
- GLUT_LEFT_BUTTON:鼠标左键
- GLUT_MIDDLE_BUTTON:鼠标中键
- GLUT_RIGHT_BUTTON:鼠标右键
state为鼠标的按键动作，为以下定义的常量
- GLET_UP: 鼠标释放
- GLET_DOWN: 鼠标按下

`void glutMotionFunc(void(*func)(int x,int y))`:设置移动回调函数

`void glutPassiveMotionFunc(void(*func)(int x,int y))`:设置当前鼠标移动函数

**注意**：当鼠标在窗口中按下并移动时调用glutMotionFunc注册的回调函数，当鼠标在窗口中移动时调用glutPassiveMotionFunc注册的回调函数

`void glutVisibilityFunc(void (*func) (int state) );`:设置当前窗口的可视回调函数。这个函数设置当前窗口的可视回调函数,当窗口的可视性改变时,该窗口的可视回调函数被调用.**只要窗口中的任何一个像素是可见的,或者他的任意一个子窗口中任意一个像素是可见的,GLUT则认为窗口是可见的.**
state表示窗口的可视性，为以下常量：
- GLUT_NOT_VISIBLE:窗口完全不可见
- GLUT_VISIBLE:窗口可见或部分可见

`void glutEntryFunc(void (*func) (int state));`:设置鼠标的进出窗口的回调函数
Func为注册的鼠标进出的回调函数
state为鼠标的进出回调函数，为以下常量之一：
- GLUT_LEFT:鼠标离开窗口
- GLUT_RIGHT:鼠标进入窗口
当窗口取得焦点或者失去焦点时调用这个函数，当鼠标进入窗口区域并点击时，state为GLUT_RIGHT，当鼠标离开窗口区域点击其他窗口时，state为GLUT_LEFT

`void glutSpecialFunc(void(*func)(int key,int x,int y))`：设置当前窗口的特定键的回调函数
key为按下的特定键，为以下定义的常量：

key常量|描述
-----|------
GLUT_KEY_F1|F1功能键
GLUT_KEY_F2|F2功能键
GLUT_KEY_F3|F3功能键
GLUT_KEY_F4|F4功能键
GLUT_KEY_F5|F5功能键
GLUT_KEY_F6|F6功能键
GLUT_KEY_F7|F7功能键
GLUT_KEY_F8|F8功能键
GLUT_KEY_F9|F9功能键
GLUT_KEY_F10|F10功能键
GLUT_KEY_F11|F11功能键
GLUT_KEY_F12|F12功能键
GLUT_KEY_LEFT|←键
GLUT_KEY_RIGHT|→键
GLUT_KEY_UP|↑键
GLUT_KEY_DONW|↓键
GLUT_KEY_PAGE_UP|PageUp键
GLUT_KEY_PAGE_DOWN|PageDown键
GLUT_KEY_Home|Home键
GLUT_KEY_END|End键
GLUT_KEY_INSERT|Insert键

`void glutMenuStatusFunc(void(*func)(int status,int x,int y))`:设置菜单状态回调函数
status是当前是否使用菜单，为以下定义的常量：
- GLUT_MENU_IN_USE:菜单正在使用
- GLUT_MENU_NOT_IN_USE:菜单未被使用

`void glutIdleFunc(void (*func) (void));`：设置空闲回调函数

`void glutTimerFunc(unsigned int msecs, void (*Func)(int value), int value);`
- msecs是等待的时间
- Func是注册的函数
- value是指定的一个数值,用来传递到回调函数Func中
这个函数注册了一个回调函数,当指定的毫秒数到达后,这个函数就调用注册的函数,value参数用来向这个注册的函数中传递参数。




