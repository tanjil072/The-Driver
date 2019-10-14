#ifndef myVariables_H_INCLUDED
#define myVariables_H_INCLUDED

int NewGame, MenuControl, MenuAbout, MenuRank, MenuBack;
int menux;
int menuy;

int PlayPolice = 0;
int PlayRacer = 0;


int gameOverQuitShow = 0;
int MainMenuValue = 0;
int MoveCar = 1;
int loadshow = 0;
int HomeShowValue = 0;

char totalName[100][100];
int numberArray[100];
int arrayIndex = 0, stringIndex = 0;
bool activeAppending = false;
bool isNamePlateActive = true;
int flag = 0;
int length = 0;
char nameOfUser[100];


int increaseTime = 0;
int level = 1;
int secondIncreaseFast = 0;
int showMyScore;
int HomeOnPlay = 0;
int playScoreHome = 0;

int NewGameBlink_Value = 0,
	Controls_Blink_Value = 0, 
	Rank_Blink_Value = 0,
	About_Blink_Value = 0,
	Quit_Blink_Value = 0,
	Back_Blink_Value = 0, 
	Gameover_Quit_Blink_Value = 0;


int Score = 80;
int second = 0;
int p, t, b, l;
int gameOver;
int fire;
int GameoverScore = 0, MainScore = 0;
int ShowFire = 0;
int CarDamage = 0;
int bulletFire = 0;
int bulletX, bulletY;
int bulletHeight = 35, bulletWidth = 10;
bool Sound = true;

int backSound = 1;
int loopSound = 0;


int Cover[20];
char* CoverPic[] = { "Loading pages/cover.png", "Loading pages/cover2.png", "Loading pages/cover3.png", "Loading pages/cover4.png", "Loading pages/cover5.png" };
int bullet;




int buildingX[] = { 100, 300, 100, 100, 320, 220, 1200, 1300, 1050, 1300, 1100, 1250 };
int buildingY[] = { 20, 90, 200, 400, 450, 620, 20, 300, 400, 600, 200, 450 };
int building[12];
char* buildingPic[] = { "buildings/Building 10.png", "Buildings/Building 1.png", "buildings/Building 2.png", "buildings/Building 3.png", "buildings/Building 10.png", "buildings/Building 1.png",
"buildings/Building 4.png", "buildings/Building 5.png", "buildings/Building 6.png", "buildings/Building 3.png", "buildings/Building 5.png", "buildings/Building 9.png" };
int buildingHeight = 150;

int tree[20];
int treeX[] = { 0, 0, 90, 100, 350, 60, 80, 230, 0, 200, 1400, 1050, 1400, 1250, 1180, 1260, 1190, 1400, 1150, 1050 };
int treeY[] = { 0, 200, 200, 200, 250, 300, 450, 450, 600, 620, 50, 100, 200, 200, 370, 400, 530, 560, 650, 650 };
char* treePic[] = { "buildings/Tree.png", "buildings/Tree.png", "buildings/Tree3.png", "buildings/Tree3.png", "buildings/Tree7.png", "buildings/Tree3.png", "buildings/Tree3.png",
"buildings/Tree4.png", "buildings/Tree1.png", "buildings/Tree3.png", "buildings/Tree2.png", "buildings/Tree3.png", "buildings/Tree2.png", "buildings/Tree7.png",
"buildings/Tree7.png", "buildings/Tree3.png", "buildings/Tree3.png", "buildings/Tree5.png", "buildings/Tree2.png", "buildings/Tree2.png" };
int treeHeight[] = { 150, 150, 150, 150, 220, 150, 150, 150, 150, 150, 150, 200, 150, 200, 170, 150, 150, 200, 150, 150 };
int treeWidth = 100;

int rock[8];
char* rockPic[] = { "buildings/rock3.png", "buildings/rock4.png", "buildings/rock4.png", "buildings/rock2.png", "buildings/rock2.png", "buildings/rock4.png", "buildings/rock2.png",
"buildings/rock4.png" };
int rockX[] = { 50, 270, 1100, 1250, 1120, 1150, 1300, 1100 };
int rockY[] = { 150, 400, 40, 400, 620, 170, 150, 350 };
int rockHeight[] = { 40, 50, 60, 40, 40, 50, 40, 50 };
int rockWidth[] = { 60, 70, 90, 60, 60, 70, 60, 70 };

int mainCarPic;
int mainCarX = 600, mainCarY = 0, mainCarHeight = 120, mainCarWidth = 62;
int mainCarsPic1, mainCarsPic2;

int home;
int menu, play, about, controls, rank, back;
int mainBackground;
int police1, police2, police3;

int width = 1522, height = 792;

int mainCarSpeed1 = 5, mainCarSpeed2 = 4;

int roadWidth = 500, roadHeight = 792;
int roadX = 521, roadY = 0;

int policeCarPic;
int policeCarPic1, policeCarPic2;

int policeCarX = 600, policeCarY = 0, policeCarWidth = 62, policeCarHeight = 120;

int roadSpeed = 3;
int roadDiv[] = { 0, 120, 240, 360, 480, 600, 720, 0, 120, 240, 360, 480, 600, 720 };
int roadDivHeight = 80;



bool introSound = true,backgroundSound=false;


#endif // myVariables_H_INCLUDED