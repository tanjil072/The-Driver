#ifndef Score_H_INCLUDED
#define Score_H_INCLUDED

#include"myPolice.h"
#include"myLoadPicture.h"
#include"myVariables.h"

/*changing the score ;called from iMain;a parameter of iSetTimer;return type void;*/
void score_change()
{
	second++;
	if (second % 50 == 0)
	{
		level++;
		mainCarSpeed1 += 1;
		mainCarSpeed2 += 1;
		secondIncreaseFast = 2;        //after increasing level score will increase fast
	}
	
	
} 

/*how much times the car stayed onthe track is calculated in this method;called from iMain;a parameter of iSetTimer*/
void SurvivalTime()
{
	increaseTime++;
}

void score()
{
	char score[10000];
	char Damaged[1000];
	char SurvivalTime[1000];
	char lvl[1000];
	

	iSetColor(136, 0, 21);
	_itoa_s(second, score, 10);
	_itoa_s(CarDamage, Damaged, 10);
	_itoa_s(increaseTime, SurvivalTime, 10);
	_itoa_s(level, lvl, 10);
	
	iText(150, 758, lvl, GLUT_BITMAP_TIMES_ROMAN_24);
	iCircle(155, 765, 15, 100);
	iText(900, 755, score, GLUT_BITMAP_TIMES_ROMAN_24);


	iText(465, 758, Damaged, GLUT_BITMAP_TIMES_ROMAN_24);

	iText(1266, 757, SurvivalTime, GLUT_BITMAP_TIMES_ROMAN_24);


	//iText(1393, 643, ":", GLUT_BITMAP_TIMES_ROMAN_24);
	//iText(1420, 643, lvl, GLUT_BITMAP_TIMES_ROMAN_24);
}

/*shows the score on the score bar;called from iDraw;return type void*/
void score_show()
{
	char score[1000];
	char Damaged[1000];
	char SurvivalTime[1000];

	_itoa_s(second, score, 10);
	_itoa_s(CarDamage, Damaged, 10);
	_itoa_s(increaseTime, SurvivalTime, 10);
	iSetColor(136, 0, 21);
	iText(813, 242, score, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(1310, 244, Damaged, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(361, 244, SurvivalTime, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(450, 244, "sec", GLUT_BITMAP_TIMES_ROMAN_24);
}
#endif // Score_H_INCLUDED