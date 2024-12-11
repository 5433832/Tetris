#pragma once  //防止头文件被重复包含
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include"Mywindows.h"
#include"game.h"
#include"data.h"
#include<stdbool.h>
#include<conio.h>
//播放音乐头文件
#pragma comment(lib,"winmm.lib")//#pragma comment编译预处理指令将lib类型库文件引入
//游戏逻辑模块实现
int grade = 0;//分数
int level = 1;//等级
int one = 0, two = 0, tree = 0, four = 0;//消行数量统计
//定义处理器时间变量来设置游戏开始时间
clock_t start_time;
//BLOCK自定义结构体变量
BLOCK cur_block;//当前方块
BLOCK next_block;//下一个方块
//1.定义绘制游戏池边框函数该函数无返回值（void表示无返回值）
void windowPrint(int x, int y) {
  int i, j;
  //遍历数组将边框渲染
  for (i = 0; i < 25; i++)
  {
    for (j = 0; j < 26; j++) {
      if (windowsShape[i][j] == 1)
      {
        setColor(0xc0);
        setPos(x + j, y + i);
        printf("%2s", "");
      }
    }
  }
}


//3.打印操作说明
void printInfo(int n) {
  setColor(12);
  switch (n)
  {
  case 1:
    setPos(33, 9);
    printf("经典模式");
    setPos(32, 11);
    printf("1.方块匀速下落");
    setPos(32, 12);
    printf("2.方块可见");
    break;
  case 2:
    setPos(33, 9);
    printf("暴走模式");
    setPos(32, 11);
    printf("1.方块加速下落");
    setPos(32, 12);
    printf("2.方块可见");
    break;
  case 3:
    setPos(33, 9);
    printf("地狱模式");
    setPos(32, 11);
    printf("1.方块匀速下落");
    setPos(32, 12);
    printf("2.方块不可见");
    break;
  default:
    break;
  }
  setColor(0x0a);
  setPos(32, 15);
  printf("操作规则");
  setPos(32, 17);
  printf("1.按←或A左移");
  setPos(32, 18);
  printf("2.按→或D右移");
  setPos(32, 19);
  printf("3.按↓或S加速下移");
  setPos(32, 20);
  printf("4.按↑或W变形");
  setPos(32, 21);
  printf("5.按空格暂停");

}
//4.打印分数和等级
void printGradeLeve(int num)
{
  switch (num)
  {
  case 0:
    break;
  case 1:
    grade += 10;
    one++;
    break;
  case 2:
    grade += 40;
    two++;
    break;
  case 3:
    grade += 60;
    tree++;
    break;
  case 4:
    grade += 80;
    four++;
    break;
  default:
    break;
  }

  setColor(0x0e);
  setPos(4.5, 6);
  printf("分数：%d", grade);

  if (grade < 10)
  {
    level = 1;
  }
  else if (grade >= 10 && grade < 50)
  {
    level = 2;
  }
  else if (grade >= 50 && grade < 100)
  {
    level = 3;
  }
  else if (grade >= 100 && grade < 200)
  {
    level = 4;
  }
  else if (grade >= 200 && grade < 400)
  {
    level = 5;
  }
  else if (grade >= 400 && grade < 800)
  {
    level = 6;
  }
  else if (grade >= 800 && grade < 1600)
  {
    level = 7;
  }
  else if (grade >= 1600)
  {
    level = 8;
  }
  setPos(4.5, 7);
  switch (level)
  {
  case 1:
    printf("段位：倔强青铜");
    break;
  case 2:
    printf("段位：秩序白银");
    break;
  case 3:
    printf("段位：荣耀黄金");
    break;
  case 4:
    printf("段位：尊贵铂金");
    break;
  case 5:
    printf("段位：永恒钻石");
    break;
  case 6:
    printf("段位：至尊星耀");
    break;
  case 7:
    printf("段位：最强王者");
    break;
  case 8:
    printf("段位：传奇·荣耀王者");
    break;
  default:
    break;
  }
  setPos(4.5, 11);
  printf("相处一行 %d次", one);
  setPos(4.5, 12);
  printf("相处两行 %d次", two);
  setPos(4.5, 13);
  printf("相处三行 %d次", tree);
  setPos(4.5, 14);
  printf("相处四行 %d次", four);
  //设置时间类型的变量timep
  time_t timep;
  //tm为表示日期和时间的结构体包含（年月日时分秒等成员变量）
  //定义tm结构体类的指针p,指向struct tm结构体对象
  struct tm* p;
  //调用time函数将当前系统时间(自1970.1.1 00:00:00起的秒数)存储到timep中
  time(&timep);
  /*gmtime函数将timep变量中的时间转为UTC时间，
    存储到指针p指向的tm结构体对象中*/
  p = gmtime(&timep);

  setColor(15);
  setPos(2, 18);
  //年份+1900是因为从1900年开始计数的，例如如果tm_year的值为121其实际年份为2021
  //月份+1是因为是从0开始计数的
  printf("当前日期：%d年%d月%d日", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
  //UTC+8为中国北京时间
  setPos(2, 19);
  printf("当前时间：%d:%d:%d", 8 + p->tm_hour, p->tm_min, p->tm_sec);
  setPos(2, 22);
  printf("石家庄信息工程职业学院");
  setPos(2, 23);
  printf("    计算机应用系");
  setPos(2, 24);
  printf("21级计算机应用技术1班");

}
//5.游戏计时功能(需要传入处理器时间类型的游戏开始时间变量)
void gameTime(clock_t start_time) {
  setColor(15);
  setPos(2, 3);
  //利用(clock函数获取程序在CPU运行的时间-程序开始时间)/CLOCKS_PER_SEC（获取每秒钟CPU的时钟周期）
  //这样就可以获取程序执行了多长时间（单位：秒）
  printf("本次游戏运行时间：%d 秒", (clock() - start_time) / CLOCKS_PER_SEC);
}
//6.打印左边框
void borderLeft() {
  setColor(0x09);
  setPos(0, 0);
  printf("□ □ □ □ □ □ □ □ □ □ □ □ □ □ □\n");
  for (int i = 0; i < 24; i++)
  {
    printf("□                           □\n");
  }
  printf("□ □ □ □ □ □ □ □ □ □ □ □ □ □ □\n");
}
//7.打印方块
void printBlock(int x, int y, int shape, int status, int color) {
  int i, j;
  //遍历block数组
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      //如果遍历为1渲染颜色分配位置打印方块
      if (block[shape][status][i][j] == 1) {
        setColor(color);
        setPos(x + j, y + i);
        printf("■");
      }
    }
  }
}
//8.删除方块
void deleteBlock(int x, int y, int shape, int status) {
  int i, j;
  //遍历block数组
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      //如果遍历为1渲染颜色分配位置打印方块
      if (block[shape][status][i][j] == 1) {
        setPos(x + j, y + i);
        printf("%2s","");
      }
    }
  }
}
//9.产生游戏第一个方块
void startBlock() {
  //第一个方块：形状，形态，颜色-》全部随机，但是位置固定
  //初始化cur_block
  //设置随机数种子，产生不一样的随机数，使用时间，时间不会一直一样
  //srand()用来设置随机数种子，time（null）来获取自1970.1.1到现在的秒数
  //  之后强制转换为无符号整数（unsigned表示正整数）
  srand((unsigned)time(NULL));
  cur_block.x = 22;
  cur_block.y = 1;
  cur_block.shape = rand() % 7;//产生0-6的随机数
  cur_block.status = rand() % 4;
  cur_block.color = rand() % 0x10;
  //如果随机出来的颜色是黑色就变为白色
  if (cur_block.color == 0x00)
  {
    cur_block.color = 0x0a;
  }
  printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);

}
//10.产生下一个方块
void nextBlock() {
  //形状，形态颜色-》随机，但位置固定
  //初始化next_block
  next_block.x = 33;
  next_block.y = 2;
  deleteBlock(next_block.x, next_block.y, next_block.shape, next_block.status);

  next_block.shape = rand() % 7;
  next_block.status = rand() % 4;
  next_block.color = rand() % 0x10;
  //如果随机出来的颜色是黑色就变为白色
  if (next_block.color == 0x00)
  {
    next_block.color = 0x0a;
  }
  printBlock(next_block.x, next_block.y, next_block.shape, next_block.status, next_block.color);
}
//11.拷贝方块
void copyBlock() {
  //当前方块等于下一个方块，并产生新的下一个方块
  cur_block = next_block;
  cur_block.x = 22;
  cur_block.y = 1;
  printBlock(next_block.x, next_block.y, next_block.shape, next_block.status, next_block.color);
  nextBlock();
}
//12.方块下移操作
//返回值标记方块是否到游戏底部
int downBlock(int n) {
  //原理：删除掉现在正在显示的方块，垂直坐标+1，重新打印
  if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -1)
  {
    //如果发生了碰撞：方块落到了游戏池底部
    /*产生新的方块：下一个新的方块值-》当前正在下落的方块，重新产生下一个方块
      保存方块检测是否消行，打印游戏池，产生新的方块*/
    save();
    lineClear();
    updateGame(n);
    copyBlock();
    return -1;
  }
  else if (crash(cur_block.x, cur_block.y + 1, cur_block.shape, cur_block.status) == -2)
  {
    //游戏结束
    return -2;
  }
  else
  {
    deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
    cur_block.y += 1;
    printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
    return 0;
  }
}
//13.方块左移
void leftBlock() {
  if (crash(cur_block.x-1, cur_block.y, cur_block.shape, cur_block.status) == -1)
  {
    //如果发生碰撞，就直接返回
    return;
  }
  deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
  cur_block.x -= 1;
  printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}
//14.方块右移
void rightBlock() {
  if (crash(cur_block.x+1, cur_block.y, cur_block.shape, cur_block.status) == -1)
  {
    //如果发生碰撞，就直接返回
    return;
  }
  deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
  cur_block.x += 1;
  printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}
//15.方块变形
void changeBlock() {
  //通过数组下标+1来获得下一个形态，下标值0-3
  if (crash(cur_block.x, cur_block.y, cur_block.shape, (cur_block.status + 1) % 4) == -1)
  {
    return;
  }
  deleteBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status);
  cur_block.status = (cur_block.status + 1) % 4;
  printBlock(cur_block.x, cur_block.y, cur_block.shape, cur_block.status, cur_block.color);
}

//17.碰撞检测
int crash(int x, int y, int shape, int status) {
  //基于下一个位置的检测，参数为下一个位置或形态
  int i, j;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++) {
      if (block[shape][status][i][j] == 1)
      {
        if (windowsShape[i + y][j + x - 15] == 1) {
          if (cur_block.x == 22 && cur_block.y == 1) {
            //方块产生就发生碰撞游戏结束
            return -2;
          }
          //方块落到游戏池底部
          return -1;
        }
      }
    }
  }
  return 0;
}
//18.保存方块
void save() {
  //根据方块在界面上的坐标，将坐标对应到游戏池下标的对应位置
  //方块为1的保存到windowShpe数组
  int i, j;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++) {
      if (block[cur_block.shape][cur_block.status][i][j] == 1)
      {
        windowsShape[i + cur_block.y][j + cur_block.x - 15] = 1;
      }
    }
  }
}
//19.刷新游戏池
void updateGame(int n) {
  int i, j;
  for (i = 23; i > 0; i--)
  {
    for (j = 1; j < 15; j++) {
      switch (n)
      {
      case 1:
        if (windowsShape[i][j] == 1)
        {
          setColor(0x0e);
          setPos(15 + j, i);
          printf("■");
        }
        else
        {
          setColor(0x00);
          setPos(15 + j, i);
          printf("%2s", "");
        }
        break;
      case 2:
        if (windowsShape[i][j] == 1)
        {
          setColor(0x0e);
          setPos(15 + j, i);
          printf("%2s", "");
        }
        else
        {
          setColor(0x00);
          setPos(15 + j, i);
          printf("%2s", "");
        }
        break;
      default:
        break;
      }
    }
  }
}
//20.空格键实现游戏暂停
void pause() {
  while (true)
  {
    if (_getch() == 32) {
      break;
    }
  }
}
//21.消行检测
void lineClear() {
  //遍历windowsshape数组判断是否有满行，即行所有值相加为14
  int i, j;
  int number = 0;
  for (i = 23; i > 0; i--)
  {
    int total = 0;
    for (j = 0; j < 15; j++)
    {
      total += windowsShape[i][j];
    }
    if (total == 15)
    {
      lineDown(i);
      i += 1;
      number += 1;
    }
  }
  printGradeLeve(number);
}
//22.消行下移,传入消几行参数
void lineDown(int line) {
  //从line开始向下移动 i -= 1;
  int i, j;
  for (i = line; i > 1; i--)//i>1来保证边界不往下移
  {
    for (j = 1; j < 15; j++) {
      windowsShape[i][j] = windowsShape[i - 1][j];
    }
  }
}
//23.游戏结束动画
void printOver() {
  int i, j;
  for (i = 23; i > 0; i--)
  {
    for (j = 1; j < 15; j++) {
      setColor(0x2e);
      setPos(j + 15, i);
      printf("☢️");
      //sleep 作用是暂停当前线程的执行（单位：ms）
      Sleep(4);//稍微停顿
    }
  }
}
//24.游戏重新开始提示；按用户操作选择以下两个结果其一
void printFinish() {
  setColor(0x0f);
  setPos(20, 8);
  printf("游戏结束");
  setPos(20, 10);
  printf("按Y键重新开始");
  setPos(20, 11);
  printf("按N键结束游戏");
  //检测按键
  switch (_getch())
  {
  case 'y':
  case 'Y':
    againGame();
    break;
  case 'n':
  case 'N':
    end();
    break;
  default:
    printFinish();
    break;
  }
}
//25.重新开始游戏
void againGame() {
  //复位分数等级游戏池数据
  level = 1;
  grade = 0;
  one = 0;
  two = 0;
  tree = 0;
  four = 0;
  int i, j;
  for (i = 1; i < 24; i++)
  {
    for (j = 1; j < 15; j++) {
      windowsShape[i][j] = 0;
    }
  }
  system("cls");//系统命令：清空控制台屏幕
  //游戏重新初始化
  gameinit();
}
//26.游戏结束界面
void end() {
  system("cls");

  setPos(21, 8);
  setColor(12);
  printf("游戏  结束");

  setPos(21, 10);
  printf("分数：%d", grade);

  setPos(21, 12);
  switch (level)
  {
  case 1:
    printf("段位：倔强青铜");
    break;
  case 2:
    printf("段位：秩序白银");
    break;
  case 3:
    printf("段位：荣耀黄金");
    break;
  case 4:
    printf("段位：尊贵铂金");
    break;
  case 5:
    printf("段位：永恒钻石");
    break;
  case 6:
    printf("段位：至尊星耀");
    break;
  case 7:
    printf("段位：最强王者");
    break;
  case 8:
    printf("段位：传奇·荣耀王者");
    break;
  default:
    break;
  }

  setPos(21, 14);
  printf("消除一行 %d次", one);
  setPos(21, 16);
  printf("消除两行 %d次", two);
  setPos(21, 18);
  printf("消除三行 %d次", tree);
  setPos(21, 20);
  printf("消除四行 %d次", four);

  setPos(21, 22);
  printf("本次游戏运行时间 %d 秒", (clock() - start_time) / CLOCKS_PER_SEC);

  int i;
  setPos(24, 2);
  setColor(6);
  printf("\\\\\\|///");
  setPos(24, 3);
  printf("\\\\\\");

  setPos(22, 3);
  setColor(6);
  printf("\\\\");

  setPos(24, 3);
  setColor(15);
  printf(".-.-");

  setPos(27, 3);
  setColor(6);
  printf("////");

  setPos(23, 4);
  setColor(14);
  printf("(");

  setPos(24, 4);
  setColor(15);
  printf(".@.@");
  setPos(26, 4);
  setColor(14);
  printf(")");

  for (i = 6; i < 25; i++)
  {
    setPos(8, i);
    printf("|");
    setPos(41, i);
    printf("|");
  }

  _getch();//任意键退出游戏
  exit(0);

}
//27.打印开始图案
void printStart(int x, int y) {
  int color = rand() % 0x10;
  if (color == 0x00)
  {
    color = 0x0f;
  }
  setColor(color);
  setPos(x, y);
  printf("**********************\n");
  setPos(x, y + 1);
  printf("*                    *\n");
  setPos(x, y + 2);
  printf("*       Tetris       *\n");
  setPos(x, y + 3);
  printf("*     俄罗斯方块     *\n");
  setPos(x, y + 4);
  printf("*                    *\n");
  setPos(x, y + 5);
  printf("**********************\n");

  setPos(25, 15);
  printf("按Enter键开始游戏");
}
//28.清除开始动画
void deleteStart(int x, int y) {
  int i, j;
  for (i = y; i <= y + 5; i++)
  {
    for (j = x; j < x + 35; j++) {
      setPos(i, j);
      printf("%2s", "");
    }
  }
}
//29.动画效果-》定时(边界)
void printAnimation() {
  clock_t time1, time2;
  time1 = clock();
  int x = 5;
  printStart(x, 5);
  while (true)
  {
    time2 = clock();
    if (time2 - time1 > 200)//间隔200ms
    {
      time1 = time2;
      deleteStart(x, 5);
      printStart(++x, 5);
      if (x == 22)
      {
        deleteStart(x, 5);
        x = 5;
      }
    }
    //kbhit检查控制台窗口的按键是否被按下
    if (_kbhit())
    {


      //按下回车键开始游戏退出动画
      if (_getch() == 13)
      {
        break;
      }
      else
      {
        setPos(22, 17);
        //随机图案颜色
        int color = rand() % 0x10;
        if (color == 0x00)
        {
          color = 0x0f;
        }
        printf("输入有误 请按回车键开始游戏");
        _getch();
        system("cls");
      }
    }
  }
  system("cls");
}
//30.游戏模式选择,传入时间和模式代表数字
void gameMode(double time, int n) {
  //游戏开始时间
  clock_t startTime = clock();
  //定时器
  clock_t time1,time2;
  time1 = clock();
  while (true)
  {
    //检测是否有按键按下
    if (_kbhit())
    {
      switch (_getch())
      {
      case 'W':
      case 'w':
      case 72:
        changeBlock();
        break;
      case 'A':
      case 'a':
      case 75:
        leftBlock();
        break;
      case 'D':
      case 'd':
      case 77:
        rightBlock();
        break;
      case 'S':
      case 's':
      case 80:
        downBlock(n);
        break;
      case 32:
        pause();
        break;
      }
    }
    time2 = clock();
    //每0.65s下落一次
    if (time2-time1>time*CLOCKS_PER_SEC)
    {
      //游戏计时
      gameTime(startTime);
      if (downBlock(n) == -2) {
        break;
      }
      time1 = time2;
    }
  }

}
//31.选择游戏模式界面
void gameModeChoose() {
  system("cls");
  setPos(24, 9);
  setColor(11);
  printf("俄罗斯方块模式选择");

  setColor(12);
  setPos(16, 15);
  printf("1.普通模式");
  setPos(26, 15);
  printf("2.困难模式");
  setPos(36, 15);
  printf("3.超难模式");
  setPos(24, 22);
  setColor(3);
  printf("请输入数字选择模式：");

  setColor(14);

  int n;
  scanf_s("%d", &n);
  switch (n)
  {
  case 1:
    system("cls");

    windowPrint(15, 0);
    printInfo(n);
    borderLeft();

    printGradeLeve(0);

    startBlock();
    nextBlock();

    gameMode(0.65, 1);

    printOver();
    printFinish();

    break;
  case 2:
    system("cls");

    windowPrint(15, 0);
    printInfo(n);
    borderLeft();

    printGradeLeve(0);

    startBlock();
    nextBlock();

    gameMode(0.15, 1);

    printOver();
    printFinish();

  case 3:
    system("cls");

    windowPrint(15, 0);
    printInfo(n);
    borderLeft();

    printGradeLeve(0);

    startBlock();
    nextBlock();

    gameMode(0.15, 2);

    printOver();
    printFinish();

    break;
  default:
    setColor(12);
    setPos(21, 23);
    printf("输入错误请重新输入");
    _getch();
    system("cls");
    gameModeChoose();
    break;
  }
}

////2.游戏初始化
void gameinit() {
  //初始化句柄
  initHandle();

  //使用多媒体接口打开音乐 取一个别名为a
  mciSendString("open 俄罗斯方块.mp3 alias a",NULL,0,NULL);

  //使用多媒体接口发送play a指令播放音乐a
  mciSendString(TEXT("play a repeat"), NULL, 0, NULL);

  printAnimation();
  gameModeChoose();

  borderLeft();
}
