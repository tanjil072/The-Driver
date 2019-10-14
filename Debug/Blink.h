#ifndef Blink_H_INCLUDED
#define Blink_H_INCLUDED
#include"myVariables.h"


//Creating Rectangle in every button

//creates the rectangles for blinking of New Game option;called from blinkGame method which is from iDraw;return type void;
void NewGameRectangle()
{
	
	iRectangle(76, 672, 229, 61);
	iRectangle(76, 671, 230, 61);
	iRectangle(76, 670, 231, 61);
	iRectangle(76, 669, 231, 61);


	iRectangle(76, 672, 229, 61);
	iRectangle(75, 671, 230, 61);
	iRectangle(74, 670, 231, 61);
	iRectangle(73, 669, 231, 61);


}

//creates the rectangles for blinking of Controls option;called from blinkGame method which is from iDraw;return type void;
void ControlRectangle()
{
	iRectangle(76, 577, 229, 66);
	iRectangle(76, 576, 230, 66);
	iRectangle(76, 575, 231, 66);
	iRectangle(76, 574, 231, 66);


	iRectangle(76, 574, 229, 66);
	iRectangle(75, 576, 230, 66);
	iRectangle(74, 575, 231, 66);
	iRectangle(73, 574, 231, 66);


}

//creates the rectangles for blinking of Top Rank option;called from blinkGame method which is from iDraw;return type void;
void RankRectangle()
{
	iRectangle(77, 482, 229, 64);
	iRectangle(77, 481, 230, 64);
	iRectangle(77, 480, 231, 64);
	iRectangle(77, 479, 231, 64);

	iRectangle(77, 482, 229, 64);
	iRectangle(76, 481, 230, 64);
	iRectangle(75, 480, 231, 64);
	iRectangle(74, 479, 231, 64);

}

//creates the rectangles for blinking of About option;called from blinkGame method which is from iDraw;return type void;
void AboutRectangle()
{
	iRectangle(77, 384, 229, 64);
	iRectangle(77, 383, 230, 64);
	iRectangle(77, 382, 231, 64);
	iRectangle(77, 381, 231, 64);

	iRectangle(77, 384, 229, 64);
	iRectangle(76, 383, 230, 64);
	iRectangle(75, 382, 231, 64);
	iRectangle(74, 381, 231, 64);
}

//creates the rectangles for blinking of Quit option;called from blinkGame method which is from iDraw;return type void;
void QuitRectangle()
{
	iRectangle(1282, 20, 226, 60);
	iRectangle(1282, 19, 226, 60);
	iRectangle(1282, 18, 226, 60);
	iRectangle(1282, 17, 226, 60);

	iRectangle(1282, 20, 226, 60);
	iRectangle(1281, 20, 226, 60);
	iRectangle(1280, 20, 226, 60);
	iRectangle(1279, 20, 226, 60);


}

//creates the rectangles for blinking of Back Button option;called from blinkGame method which is from iDraw;return type void;
void Back_button_Blink()
{
	iRectangle(13, 737, 77, 40);
	iRectangle(13, 736, 77, 40);
	iRectangle(13, 735, 77, 40);
	iRectangle(13, 734, 77, 40);

	iRectangle(13, 737, 77, 40);
	iRectangle(13, 737, 77, 40);
	iRectangle(13, 737, 77, 40);
	iRectangle(13, 737, 77, 40);

	iRectangle(13, 737, 77, 40);
	iRectangle(12, 737, 77, 40);
	iRectangle(11, 737, 77, 40);
	iRectangle(10, 737, 77, 40);


}

//creates the rectangles for blinking of Quit button of the game over page;called from blinkGame method which is from iDraw;return type void;
void GameOverquit_Rectangle()
{
	iSetColor(74, 0, 0);
	iRectangle(1392, 720, 113, 51);
	iRectangle(1392, 719, 113, 51);
	iRectangle(1392, 718, 113, 51);
	iRectangle(1392, 717, 113, 51);

	iRectangle(1392, 720, 113, 51);
	iRectangle(1391, 720, 113, 51);
	iRectangle(1390, 720, 113, 51);
	iRectangle(1389, 720, 113, 51);
}

//creates the rectangles for blinking of Home button of the game over page;called from blinkGame method which is from iDraw;return type void;
void HomeButtonRectangle()
{
	iSetColor(74, 0, 0);
	iRectangle(15, 727, 115, 48);
	iRectangle(15, 726, 115, 48);
	iRectangle(15, 725, 115, 48);
	iRectangle(15, 724, 115, 48);

	iRectangle(15, 727, 115, 48);
	iRectangle(14, 727, 115, 48);
	iRectangle(13, 727, 115, 48);
	iRectangle(12, 727, 115, 48);

}



/*controls the blinking of new game;called from iPassineMouse;return type void*/
void BlinkNewGame()
{
	About_Blink_Value = 0;
	Rank_Blink_Value = 0;
	Controls_Blink_Value = 0;
	Quit_Blink_Value = 0;
	Back_Blink_Value = 0;
	NewGameBlink_Value = 1;

	iSetColor(74, 0, 0);

	NewGameRectangle();
}

/*controls the blinking of control;called from iPassineMouse;return type void*/
void BlinkControl()
{
	About_Blink_Value = 0;
	Rank_Blink_Value = 0;
	NewGameBlink_Value = 0;
	Quit_Blink_Value = 0;
	Back_Blink_Value = 0;
	Controls_Blink_Value = 1;
	iSetColor(74, 0, 0);

	ControlRectangle();
}

/*controls the blinking of rank;called from iPassineMouse;return type void*/
void BlinkRank()
{
	NewGameBlink_Value = 0;
	Controls_Blink_Value = 0;
	About_Blink_Value = 0;
	Quit_Blink_Value = 0;
	Back_Blink_Value = 0;
	Rank_Blink_Value = 1;
	iSetColor(74, 0, 0);
	RankRectangle();
}

/*controls the blinking of about;called from iPassineMouse;return type void*/
void BlinkAbout()
{
	NewGameBlink_Value = 0;
	Controls_Blink_Value = 0;
	Rank_Blink_Value = 0;
	Quit_Blink_Value = 0;
	Back_Blink_Value = 0;
	About_Blink_Value = 1;

	iSetColor(74, 0, 0);
	AboutRectangle();
}

/*controls the blinking of quit;called from iPassineMouse;return type void*/
void BlinkQuit()
{
	NewGameBlink_Value = 0;
	Controls_Blink_Value = 0;
	Rank_Blink_Value = 0;
	About_Blink_Value = 0;
	Back_Blink_Value = 0;
	Quit_Blink_Value = 1;
	iSetColor(74, 0, 0);
	QuitRectangle();
}

/*controls the blinking of back button;called from iPassineMouse;return type void*/
void BlinkBack()
{
	NewGameBlink_Value = 0;
	Controls_Blink_Value = 0;
	Rank_Blink_Value = 0;
	About_Blink_Value = 0;
	Quit_Blink_Value = 0;
	Back_Blink_Value = 1;
	iSetColor(74, 0, 0);
	Back_button_Blink();
}

void BlinkPlayHomeRectangle()
{
	iSetColor(74, 0, 0);
	iRectangle(32, 748, 78, 10);
	iRectangle(32, 747, 78, 10);
	iRectangle(32, 746, 78, 10);
	iRectangle(32, 745, 78, 10);

	iRectangle(32, 748, 78, 10);
	iRectangle(31, 747, 78, 10);
	iRectangle(30, 746, 78, 10);
	iRectangle(29, 745, 78, 10);
}



/*draws therectangles of the loading rectangles of the opening page;called from iDraw;return type void*/

void loadingRectangle()
{
	iSetColor(63, 72, 204);
	iRectangle(469, 98, 602, 43);
	iRectangle(468, 97, 603, 44);
	iRectangle(470, 99, 603, 41);
	iRectangle(469, 100, 603, 42);
	
	iSetColor(0, 162, 232);
}


#endif // Blink_H_INCLUDED