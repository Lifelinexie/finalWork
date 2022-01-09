#include "data.h"
#ifndef PROGRAMVIEW_H 
#define PROGRAMVIEW_H 
//程序开始界面，包含关于，帮助，注册，登录模块 ,包含处理函数 
//返回programViewHandle的返回值到主函数中，1表示显示程序开始界面，0表示退出程序 
int programView(USER *user);
//自定义函数修改颜色 
void color(short x);
/*
　  0=黑色                8=灰色　　
  　1=蓝色                9=淡蓝色           　　                        
　　2=绿色                10=淡绿色              　　
　　3=湖蓝色              11=淡浅绿色     　
　　4=红色                12=淡红色       　　
　　5=紫色                13=淡紫色             　　
　　6=黄色                14=淡黄色             　　
　　7=白色                15=亮白色
大于15或者小于0都变成白色 
*/   
#endif 
