//游戏逻辑模块
#pragma once
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
//定义方块结构体名为BLOCK
typedef struct {
  //方块坐标
  int x;
  int y;
  //方块形状
  int shape;
  //方块状态
  int status;
  //方块颜色
  int color;
}BLOCK;
//1.定义绘制游戏池边框函数该函数无返回值（void表示无返回值）
void windowPrint(int x, int y);
//2.游戏初始化
void gameinit();
//3.打印操作说明
void printInfo(int n);
//4.打印分数和等级
void printGradeLeve(int num);
//5.游戏计时功能(需要传入处理器时间类型的游戏开始时间变量)
void gameTime(clock_t start_time);
//6.打印左边框
void borderLeft();
//7.打印方块
void printBlock(int x,int y,int shape,int status,int color);
//8.删除方块
void deleteBlock(int x,int y,int shape, int status);
//9.产生游戏第一个方块
void startBlock();
//10.产生下一个方块
void nextBlock();
//11.拷贝方块
void copyBlock();
//12.方块下移操作
//返回值标记方块是否到游戏底部
int downBlock(int n);
//13.方块左移
void leftBlock();
//14.方块右移
void rightBlock();
//15.方块变形
void changeBlock();
//16.方块直接落地,传入底部参数
void bottomBlock(int n);
//17.碰撞检测
int crash(int x,int y,int shape,int status);
//18.保存方块
void save();
//19.刷新游戏池
void updateGame(int n);
//20.空格键实现游戏暂停
void pause();
//21.消行检测
void lineClear();
//22.消行下移,传入消几行参数
void lineDown(int line);
//23.游戏结束动画
void printOver();
//24.游戏重新开始提示；按用户操作选择以下两个结果其一
void printFinish();
//25.重新开始游戏
void againGame();
//26.游戏结束界面
void end();
//27.打印开始图案
void printStart(int x,int y);
//28.清除开始动画
void deleteStart(int x,int y);
//29.动画效果-》定时(边界)
void printAnimation();
//30.游戏模式选择,传入时间和模式代表数字
void gameMode(float time,int n);
//31.选择游戏模式界面
void gameModeChoose();



