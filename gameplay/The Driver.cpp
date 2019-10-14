#include "iGraphics.h"
#include"Header.h"
#include"myRacer.h"
#include"myPolice.h"
#include"myLoadPicture.h"
#include"myVariables.h"
#include"Blink.h"
#include"Score.h"

//For Showing Back Button; called from iDraw method;return type void
void backButton()
{
	iShowImage(0, 730, 100, 60, back);
}

//For showing Menu Button; called from iDraw and homeButtonPress method;return type void

void MainMenu()
{
	iShowImage(0, 0, 1522, 792, menu);
	
}


//Inside New Game button,Options will be shown here;called from iDraw;return type void
void NewGameInside()
{
	
	iShowImage(0, 0, 1522, 792, play);

}


//Loading condition part by part rectangle increasing codes are here;called from iDraw;return type void
void LoadingPage()
{
	
	loadshow++;
	
}
//After pressing home button the environment will be reset again;;called from iDraw;return type void
void RepeatOnHomeButtonPress()
{
	PlaySound("Sounds/RaceCareScreamBy.wav", NULL, SND_LOOP | SND_ASYNC);
	MainMenu();
	isNamePlateActive = true;
	NewGame = 0;

	mainCar1.carY = 800;
	mainCar2.carY = 796;
	policeCar1.carY = 800;
	policeCar2.carY = 796;
	
	mainCar1.carX = rand() % (roadWidth-mainCar1.carWidth) + roadX;
	mainCar2.carX = rand() % (roadWidth - mainCar2.carWidth) + roadX;
	policeCar1.carX = rand() % roadWidth + roadX;
	policeCar2.carX = rand() % roadWidth + roadX;

	MoveCar = 1;
	MenuControl = 0;
	MenuRank = 0;
	MenuAbout = 0;
	playScoreHome = 0;
	MenuBack = 0;
	PlayPolice = 0;
	PlayRacer = 0;
	GameoverScore = 0;
	MainScore = 0;
	CarDamage = 0;
	gameOverQuitShow = 0;
	second = 0;
	bulletFire = 0;
	level = 1;
	increaseTime = 0;
	secondIncreaseFast = 0;
	mainCarSpeed1 = 5, mainCarSpeed2 = 4;
	MainMenuValue = 0;
}

/*append scores into a file for the COP part;called from iDraw;return type void*/


void appendHighScore(char userName[], int points)
{
	FILE *fp = fopen("Score_COP.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s\n", userName);
		fprintf(fp, "%d\n", points);
	}

	fclose(fp);
	activeAppending=false;
}

/*append scores into a file for the racer part;called from iDraw:return type void*/
void appendHighScore2(char userName[], int points)
{
	FILE *fp = fopen("Score_Racer.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s\n", userName);
		fprintf(fp, "%d\n", points);
	}

	fclose(fp);
	activeAppending = false;
}

/*sorting all the scores saved into the file in descending order;called from highScoreShow method which is from iDraw;return type void*/
void sortingHighScore()
{
	int temp;
	char t[100];

	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
				strcpy(t, totalName[j]);
				strcpy(totalName[j], totalName[j + 1]);
				strcpy(totalName[j + 1], t);
			}
		}
	}
}

/*showing the top five scores from file of COP part and call the sortingHighScore method;called from iDraw;return type void*/
void highScoreShow()
{
	sortingHighScore();
	
	for (int k = 0, y = 330; k < 5; k++, y -= 44)
	{
		char str[100];

		if (numberArray[k]>0)
		{
			_itoa(numberArray[k], str, 10);
			iSetColor(255, 255, 255);
			//score
			iText(1070, y, str, GLUT_BITMAP_HELVETICA_18);
			//name
			iText(297, y, totalName[k], GLUT_BITMAP_HELVETICA_18);
		}
	}
}

/*showing the top five scores from file of Racer part and call the sortingHighScore method;called from iDraw;return type void*/
void highScoreShow2()
{
	sortingHighScore();

	for (int k = 0, y = 621; k < 5; k++, y -= 45)
	{
		char str[100];

		if (numberArray[k]>0)
		{
			_itoa(numberArray[k], str, 10);
			iSetColor(255, 255, 255);

			iText(1070, y, str, GLUT_BITMAP_HELVETICA_18);

			iText(297, y, totalName[k], GLUT_BITMAP_HELVETICA_18);
		}
	}
}

/*shows the name of the gamer from keyboard;called from iDraw;return type void*/
void userName()
{
	if (flag == 0)
	{
		iSetColor(0, 0, 0);
		iRectangle(828, 627, 306, 38);
		iText(832, 640, nameOfUser);
	}
	if (flag == 1)
	{
		iSetColor(136,0, 21);
		iRectangle(828, 627, 306, 38);		
		iText(832, 640, nameOfUser, GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 0, 0);
	}
}

/*read the highest all scores from the COP file;called from iMain and iDraw method;return type void*/
void readHighScore()
{
	FILE *fp = fopen("Score_COP.txt", "r");
	char str[100];
	arrayIndex = 0, stringIndex = 0;

	if (fp != NULL)
	{
		while (fgets(str, 30, fp) != NULL)
		{
			
			strcpy(totalName[stringIndex++], str);
			fgets(str, 15, fp);
			numberArray[arrayIndex++] = atoi(str);	


		}
	}

	fclose(fp);
}



/*read the highest all scores from the COP file;called from iMain and iDraw method;return type void*/
void readHighScore2()
{
	FILE *fp = fopen("Score_Racer.txt", "r");
	char str[100];
	arrayIndex = 0, stringIndex = 0;

	if (fp != NULL)
	{
		while (fgets(str, 40, fp) != NULL)
		{

			strcpy(totalName[stringIndex++], str);
			fgets(str, 20, fp);
			numberArray[arrayIndex++] = atoi(str);



		}
	}

	fclose(fp);
}


//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

void iDraw()
{

	iClear();
	iPauseTimer(0);
	iPauseTimer(b);
	iPauseTimer(l);
	iPauseTimer(p);

	

	//:::::::::::::::::::::::::::::::::::::::::::::Cover picture & loading parts are here(blink.h)::::::::::::::::::::::::::::::::::::::::://
	iShowImage(0, 0, 1522, 792, Cover[0]);


	if (loadshow == 1)
	{
		NewGameBlink_Value = 0;
		Controls_Blink_Value = 0;
		Rank_Blink_Value = 0;
		About_Blink_Value = 0;
		Quit_Blink_Value = 0;

		iShowImage(0, 0, 1522, 792, Cover[1]);
		loadingRectangle();
		iFilledRectangle(470, 100, 50, 39);
	}
	
	else if (loadshow == 2)
	{
		NewGameBlink_Value = 0;
		Controls_Blink_Value = 0;
		Rank_Blink_Value = 0;
		About_Blink_Value = 0;
		Quit_Blink_Value = 0;

		iShowImage(0, 0, 1522, 792, Cover[2]);
		loadingRectangle();
		
		iFilledRectangle(470, 100, 300, 39);
		
	}
	else if (loadshow == 3)
	{
		NewGameBlink_Value = 0;
		Controls_Blink_Value = 0;
		Rank_Blink_Value = 0;
		About_Blink_Value = 0;
		Quit_Blink_Value = 0;

		iShowImage(0, 0, 1522, 792, Cover[3]);
		loadingRectangle();

		
		iFilledRectangle(470, 100, 400, 39);

	}
	else if (loadshow == 4)
	{
		NewGameBlink_Value = 0;
		Controls_Blink_Value = 0;
		Rank_Blink_Value = 0;
		About_Blink_Value = 0;
		Quit_Blink_Value = 0;

		iShowImage(0, 0, 1522, 792, Cover[4]);

		loadingRectangle();
		
		iFilledRectangle(470, 100, 600, 39);

	}

	if (loadshow == 5)
	{
		MainMenu();
		
		iPauseTimer(t);
	}

	
	//::::::::::::::::::::::::::::::::::::::::Here all the menu info can be seen:::::::::::::::::::::::::::::::::::::::::://

	if (NewGame == 1)
	{
		iClear();
		NewGameInside();
		backButton();
		
		introSound = false;
		
		
		
		
		
	}

	if (MenuControl == 1)
	{
		iClear();
		iShowImage(0, 0, 1522, 792, controls);
		backButton();	
		

	}
	if (MenuRank == 1)
	{
		iClear();
		
		iShowImage(0, 0, 1522, 792, rank);

		readHighScore();
		highScoreShow();
		
		readHighScore2();
		highScoreShow2();

		backButton();
	}
	else if (MenuAbout == 1)
	{
		iClear();
		iShowImage(0, 0, 1522, 792, about);
		backButton();
	}
	else if (MenuBack == 1)
	{
		iClear();
		iShowImage(0, 0, 1522, 792, menu);

	}

	//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Showing Fire on collision::::::::::::::::::::::::::::::::::::::::::::::::::::::://

	if (ShowFire == 1)
	{
		iShowImage(policeCarX - 20, policeCarY + 60, 120, 130, fire);
		
	}

	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::NewGame playing part & bullet logic::::::::::::::::::::::::::::::::::::::::::::::://

	if (PlayPolice == 1 && PlayRacer==0)
	{
		iResumeTimer(0);
		

	    Police();
		iResumeTimer(b);
		iResumeTimer(l);
		iResumeTimer(p);

		if (bulletFire == 1)
		{
			iShowImage(bulletX, bulletY, bulletWidth, bulletHeight, bullet);
			bulletY += 5;	
		}
		iShowImage(14, 712, 1512, 100, showMyScore);

		if (playScoreHome == 1)
		{
			RepeatOnHomeButtonPress();
			playScoreHome = 0;
		}
		

		//:::::::::::::::::::::::::::::::::::::::::::::::GameOver Page Showing codes are here:::::::::::::::::::::::::::::::::::::::::://
		if (GameoverScore == 1 && MainScore==0)
		{

			iPauseTimer(p);
			iPauseTimer(b);
			iPauseTimer(l);
			ShowFire = 0;
			MoveCar = 0;
			playScoreHome = 0;
			iShowImage(0, 0, 1522, 792, gameOver);
			
			if (HomeOnPlay == 1)
			{
				RepeatOnHomeButtonPress();
			}
			else
			{
				playScoreHome = 0;
			}
			

			score_show();
			userName();
			if (activeAppending == true)
			{
				appendHighScore(nameOfUser, second);
			}
			

			if (gameOverQuitShow == 1)
			{
				GameOverquit_Rectangle();
				
			}
			
		}
		
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Main Score while playng the game::::::::::::::::::::::::::::::::::://
		 if (GameoverScore == 0 && MainScore == 1)
		{
			score();
			
		}
		
	   
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Racer part Here::::::::::::::::::::::::::::::::::::::::::::::::::::://
	else if (PlayRacer == 1 && PlayPolice==0)
	{
		
		iResumeTimer(0);

		Racer();

		iResumeTimer(b);
		iResumeTimer(l);
		iResumeTimer(p);

		iShowImage(14, 712, 1512, 100, showMyScore);

		if (playScoreHome == 1)
		{
			RepeatOnHomeButtonPress();
			playScoreHome = 0;
		}

		if (HomeOnPlay == 1)
		{
			RepeatOnHomeButtonPress();
		}
		//:::::::::::::::::::::::::::::::::::::::::::::::GameOver Page Showing codes are here:::::::::::::::::::::::::::::::::::::::::://
		if (GameoverScore == 1 && MainScore == 0)
		{

			PlaySound(0, 0, 0);
			
			
			iPauseTimer(p);
			iPauseTimer(b);
			iPauseTimer(l);

			ShowFire = 0;
			MoveCar = 0;
			iShowImage(0, 0, 1522, 792, gameOver);
			
			score_show();
			userName();

			if (activeAppending == true)
			{
				appendHighScore2(nameOfUser, second);
			}

			if (gameOverQuitShow == 1)
			{
				GameOverquit_Rectangle();

			}

		}

		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Main Score while playng the game::::::::::::::::::::::::::::::::::://
		if (GameoverScore == 0 && MainScore == 1)
		{
			score();

		}
		
	}

	//:::::::::::::::::::::::::::::::::::::::::::::::All the Menu Button Blinking Codes here:::::::::::::::::::::::::::::::::::::::::::::::://

	if (NewGameBlink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		NewGameRectangle();
	}
	if (Controls_Blink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		ControlRectangle();
	}
	if (Rank_Blink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		RankRectangle();
	}
	if (About_Blink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		AboutRectangle();
	}
	if (Quit_Blink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		QuitRectangle();
	}
	



	//:::::::::::::::::::::::::::::::::::::::::::::::::Back Button blink where it is used:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://

	if (Back_Blink_Value == 1 && NewGame == 1 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		Back_button_Blink();
	}

	if (Back_Blink_Value == 1 && NewGame == 0 && MenuControl == 1 && MenuRank == 0 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		Back_button_Blink();
	}

	if (Back_Blink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 1 && MenuAbout == 0 && PlayPolice == 0 && PlayRacer == 0)
	{
		Back_button_Blink();
	}

	if (Back_Blink_Value == 1 && NewGame == 0 && MenuControl == 0 && MenuRank == 0 && MenuAbout == 1 && PlayPolice == 0 && PlayRacer == 0)
	{
		Back_button_Blink();
	}


	//::::::::::::::::::::::::::::::::::::::::::::::::GameOver Home Button Blink codes here::::::::::::::::::::::::::::::::::::::::::::::://
	
	if (HomeShowValue == 1)
	{
		HomeButtonRectangle();
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::MainMenu after pressing Home Button in the game over page:::::::::::::::::::::::::::::::::::::::::::::::::://
	if (MainMenuValue == 1)
	{
		
		RepeatOnHomeButtonPress();
		
	}
	

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{
	
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{
	

	if (mx >= 32 && mx <= 110 && my >= 748 && my <= 758 && PlayRacer == 1 && PlayPolice == 0 && GameoverScore == 0)
	{
		playScoreHome = 1;
		PlaySound(0, 0, 0);
	}
	else if (mx >= 32 && mx <= 110 && my >= 748 && my <= 758 && PlayRacer == 0 && PlayPolice == 1 && GameoverScore == 0)
	{
		playScoreHome = 1;
		PlaySound(0, 0, 0);
	}
	else
	{
		playScoreHome = 0;
	}


	
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::Blink NewGame Button::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	if (mx >= 72 && mx <= 307 && my >= 669 && my <= 736)
	{

		BlinkNewGame();
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::Blink Control Button::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	else if (mx >= 72 && mx <= 307 && my >= 575 && my <= 642)
	{

		BlinkControl();
	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::Blink Rank Button::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	else if (mx >= 72 && mx <= 307 && my >= 479 && my <= 544)
	{
		BlinkRank();

	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::Blink About Button::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	else if (mx >= 72 && mx <= 307 && my >= 382 && my <= 449)
	{
		BlinkAbout();

	}
	//:::::::::::::::::::::::::::::::::::::::::::::::::::::Quit Button blink::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	else if (mx >= 1282 && mx <= 1508 && my >= 20 && my <= 81)
	{
		BlinkQuit();
	}
	//::::::::::::::::::::::::::::::::::::::::::::::::::::Back Button Blink::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	else if (mx >= 13 && mx <= 90 && my >= 737 && my <= 777)
	{
		BlinkBack();
	}
	else
	{

		NewGameBlink_Value = 0;
		Controls_Blink_Value = 0;
		Rank_Blink_Value = 0;
		About_Blink_Value = 0;
		Quit_Blink_Value = 0;
		Back_Blink_Value = 0;
		
		iSetColor(255, 255, 255);
	}

	//::::::::::::::::::::::::::::::::::::::::::::Inside GameOver page Option Blink:::::::::::::::::::::::::::::::::::::::::::::::::::::::://
	if (mx >= 1392 && mx <= 1505 && my >= 720 && my <= 771 && GameoverScore == 1)
	{
		gameOverQuitShow = 1;
	}
	else if (mx >= 15 && mx <= 130 && my >= 727 && my <= 775 && GameoverScore==1)
	{
	    
		HomeShowValue = 1;
	    
	}
	else
	{
		gameOverQuitShow = 0;
		HomeShowValue = 0;
	}


	if (mx >= 32 && mx <= 110 && my >= 748 && my <= 758 && PlayPolice == 1)
	{
		BlinkQuit();
	}
}

void iMouse(int button, int state, int mx, int my)
{
	
	

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
		
		//printf("\n%d \t %d\n", mx, my);
		if (isNamePlateActive == true)
		{
			if (mx >= 828 && mx <= 1134 && my >= 629 && my <= 667)
			{
				flag = 1;
			}
		}
		
		
				//::::::::::::::::::::::::::::::::::::::::::::::::NewGame Button Activation:::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		menux = mx;
		menuy = my;

		if (menux >= 73 && menux <= 303 && menuy >= 673 && menuy <= 733 && MenuControl != 1 && MenuAbout != 1 && MenuRank != 1)
		        {

			        PlaySound(0, 0, 0);
			        PlaySound("Sounds/carstart.wav", NULL,SND_ASYNC);
				    NewGame = 1;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;
					
		        }	
		        //:::::::::::::::::::::::::::::::::::::::::::::::::::::::Control Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 80 && mx <= 300 && my >= 580 && my <= 640 && MenuRank != 1 && MenuAbout != 1 && NewGame != 1)
				{
					PlaySound(0, 0, 0);
					PlaySound("Sounds/RACECAR.wav", NULL, SND_ASYNC);
					NewGame = 0;
					MenuControl = 1;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 0;


				}
				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Rank Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 73 && mx <= 303 && my >= 483 && my <= 541 && MenuControl != 1 && MenuAbout != 1 && NewGame!=1)
				{
					PlaySound(0, 0, 0);
					PlaySound("Sounds/OldCarEnginee02olds.wav", NULL, SND_ASYNC);
					NewGame = 0;
					MenuControl = 0;
					MenuRank = 1;
					MenuAbout = 0;
					MenuBack = 0;
					

				}
				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Back Button Activation:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 13 && mx <= 90 && my >= 737 && my <= 777)
				{
					PlaySound(0, 0, 0);
					PlaySound("Sounds/RaceCareScreamBy.wav", NULL, SND_LOOP | SND_ASYNC);
					NewGame = 0;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 0;
					MenuBack = 1;

				}
				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::about Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 73 && mx <= 303 && my >= 387 && my <= 449 && MenuControl != 1 && MenuRank != 1 && NewGame != 1)
				{
					PlaySound(0, 0, 0);
					PlaySound("Sounds/The driver intro.wav", NULL, SND_ASYNC);
					NewGame = 0;
					MenuControl = 0;
					MenuRank = 0;
					MenuAbout = 1;
					MenuBack = 0;

				}


				//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Exit when gameover page appears & power icon clicked::::::::::::::::::::::::::::::::::::://
				else if (mx >= 1392 && mx <= 1505 && my >= 720 && my <= 771 && GameoverScore == 1)
				{
					exit(0);
				}
				
				

				//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Exit Button Activation::::::::::::::::::::::::::::::::::::::::::::::::::::::://
				else if (mx >= 1282 && mx <= 1508 && my >= 20 && my <= 81 && MenuControl != 1 && MenuRank != 1 && NewGame != 1 && MenuAbout!=1)
				{

					exit(0);
				}
				//::::::::::::::::::::::::::::::::For Home Button on Gameover page:::::::::::::::::::::::::::::::::::::::://
				if (mx >= 15 && mx <= 130 && my >= 727 && my <= 775 && GameoverScore == 1)
				{
					MainMenuValue = 1;
				}

				if (mx >= 32 && mx <= 110 && my >= 748 && my <= 758 && PlayRacer==1)
				{
					playScoreHome = 1;
				}


				
			}
	
	
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == '\r')
	{
		flag = 0;
		activeAppending = true;
		isNamePlateActive = false;
	}
	if (flag == 1)
	{
		if (key == 8)
		{
			if (length > 0)
			{
				nameOfUser[--length] = ' ';
			}

		}
		else
		{
			nameOfUser[length] = key;
			length++;
		}
		
	
		
	}

	if (key == 'r' || key=='R')
	{
		
		if (NewGame ==1 && PlayPolice!=1)
		{
			if (Sound==true)
			{
				PlaySound("Sounds/racerSound.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			PlayRacer = 1;	
			MainScore = 1;
			GameoverScore = 0;

			
			
		}
		
	}
	if (key == 's')
	{
		if (NewGame == 1 && PlayPolice != 1)
		{
			for (int i = 0; i < 14; i++)
			{
				roadDiv[i] -= roadSpeed+10;
			}
			for (int i = 0; i < 12; i++)
			{
				buildingY[i] -= roadSpeed+10;
			}
			for (int i = 0; i < 20; i++)
			{
				treeY[i] -= roadSpeed+10;
			}
			for (int i = 0; i < 8; i++)
			{
				rockY[i] -= roadSpeed+10;
			}
			policeCar1.carY -= mainCarSpeed1 + 10;
			policeCar2.carY -= mainCarSpeed2 + 10;
			second += 2;

		}
			
	}
	 if (key == 'c'|| key=='C')
	{
		if (NewGame == 1 && PlayRacer!=1)
		{
			PlaySound("Sounds/policeSound.wav", NULL, SND_LOOP | SND_ASYNC);
			PlayPolice = 1;
			//PauseValue = 1;
			MainScore = 1;
			GameoverScore = 0;
			
			
			
		}
	}

	if (key == 32)
	{
		bulletFire = 1;
		bulletX = policeCarX+25;
		bulletY = policeCarY+policeCarHeight;		
	}
	
	if (key == 'w')
	{
		iResumeTimer(0);
		
	}
	
	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	
	if (key == GLUT_KEY_RIGHT)
	{
		if (MoveCar == 1)
		{
			policeCarX += 5;
			mainCarX += 5;
		}
		
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (MoveCar == 1)
		{
			policeCarX -= 5;
			mainCarX -= 5;
		}

	}
	
	if (key == GLUT_KEY_HOME)
	{
		playScoreHome = 1;
	}
	
}


int main()
{
	srand((unsigned)time(NULL));
	
	b = iSetTimer(10, mainCarsChange);	
	p = iSetTimer(600+secondIncreaseFast, score_change);
	l = iSetTimer(1000, SurvivalTime);
	t=iSetTimer(100, LoadingPage);
	
	PlaySound("Sounds/OpenPipeSymphony.wav", NULL, SND_ASYNC);
	
	//PlaySound("Sounds/RaceCareScreamBy.wav", NULL, SND_LOOP | SND_ASYNC);
	
	
	iInitialize(width, height, "The Driver");
	
	loadPicture();
	readHighScore();
	readHighScore2();
	
		
	iStart();

	return 0;
}