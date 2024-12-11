#include "Mywindows.h"
//引入布尔类型头文件否则true和false会为未定义标识符
#include<stdbool.h>

/*系统调用模块实现*/

//定义句柄变量
HANDLE handle;
//1.初始化句柄
void initHandle() {
  //通过调用GetStdHandle函数，并将STD_OUTPUT_HANDLE作为参数传递，可以获取到标准输出流的句柄。
  //这个句柄可以用于执行各种控制台相关的操作，比如改变文本颜色、隐藏光标等。
  handle = GetStdHandle(STD_OUTPUT_HANDLE);
  //调用隐藏光标方法
  hideCursor();
}

//2.设置颜色;需要进行传参
void setColor(int color) {
  //将获取到的句柄设置文本颜色
  SetConsoleTextAttribute(handle, color);
}

//3.设置光标（文本输出）位置
void setPos(int x, int y) {
  //定义结构体变量来保存输出位置
  COORD coord = { x * 2,y };
  //通过以下函数将获取的句柄设置位置
  SetConsoleCursorPosition(handle, coord);
}

//4.隐藏光标
void hideCursor() {
  //通过以下函数获取光标信息并赋值给info
  CONSOLE_CURSOR_INFO info;
  //设置光标是否可见
  info.bVisible = false;
  //设置光标宽度（1-100）这里属于百分比形式
  info.dwSize = 1;
  //通过设置光标信息函数将以上两个属性应用给info
  SetConsoleCursorInfo(handle,&info);
}
