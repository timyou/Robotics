/*============================================================
A键被按下  小车前进     B键被按下小车左转   C键被按下小车右转  D键被按下 小车后退    C D键同时被按下小车停止
=============================================================*/
/******************************定义头文件*************************/
#include <AT89X52.h>
#define uchar unsigned char
#define uint unsigned int
/*****************************IO口定义****************************/
sbit EN1 = P1^4;			//右轮调速
sbit EN2 = P1^5;			//左轮调速

sbit IN1 = P1^2;			 /*电机正反转逻辑控制端*/
sbit IN2 = P1^3;
sbit IN3 = P1^6;
sbit IN4 = P1^7;

sbit Key_B = P0^7;			 //B键信号端	  对应D0
sbit Key_D = P0^6;			//D键信号端		  对应D1
sbit Key_A = P0^5;			//A键信号端		  对应D2
sbit Key_C = P0^4;			//C键信号端		  对应D3

/**************************子函数定义****************************/
void forward()			   //前进函数
{
     IN1=0;		//左电机
	 IN2=1;
	 IN3=1;		//右电机
	 IN4=0;
	 EN1=1;
	 EN2=1;	
}

void back()					//后退函数
{
     IN1=1;		//左电机
	 IN2=0;
	 IN3=0;		//右电机
	 IN4=1;
	 EN1=1;
	 EN2=1;
}

void left()				   //左转函数
{
     IN1=0;		//左电机
	 IN2=0;
	 IN3=1;		//右电机
	 IN4=0;
	 EN1=1;
	 EN2=1;
}

void right()			   //右转函数
{
     IN1=0;		//左电机
	 IN2=1;
	 IN3=0;		//右电机
	 IN4=0;
	 EN1=1;
	 EN2=1;
}
void stop()					//停止函数
{
     IN1=0;		//左电机
	 IN2=0;
	 IN3=0;		//右电机
	 IN4=0;
	 EN1=1;
	 EN2=1;
}
/***************************主函数*****************************/
void main()
{
	while(1)			  //while循环
	{
		if(Key_B==0&&Key_D==0&&Key_A==1&&Key_C==0)	//A键被按下
		{
			forward();						//小车前进?
		}
		else if(Key_B==1&&Key_D==0&&Key_A==0&&Key_C==0)	//B键被按下
		{
			right();						//小车右转
		}
		else if(Key_B==0&&Key_D==0&&Key_A==0&&Key_C==1)	//C键被按下
		{
			left();						//小车左转
		}
		else if(Key_B==0&&Key_D==1&&Key_A==0&&Key_C==0)	//D键被按下
		{
			back();					//小车后退	
		}
		else if(Key_B==0&&Key_D==1&&Key_A==0&&Key_C==1)	//CD键同时被按下
		{
			stop();					//小车停止	
		}
		else
		{
//			stop();
		}
	}	 

}
