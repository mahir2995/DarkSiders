#ifndef VARIABLES_INCLUDED
#define VARIABLES_INCLUDED
#include<iostream>

#define screenWidth 1600
#define screenHeigth 900
#define projectName "Darksiders"
#define JUMPLIMIT 100 
#define numbersOfVillian 40
#define numbersOfVillian2 40
#define numbersOfVillian3 40
#define bossnumber 40
#define mainVillian 1
#define backGroundSpeed 200



struct villian{
	int villianX;
	int villianY;
	int villian_index;
	bool villian_show;
};



char buttons[5][40] = { "images\\Button\\startButton.bmp", "images\\Button\\mechanismButton.bmp", "images\\Button\\scoreButton.bmp", "images\\Button\\creditsButton.bmp", "images\\Button\\quitButton.bmp" };

char pages[8][30] = { "images\\Page\\menuPage.jpg", "images\\Page\\start.jpg", "images\\Page\\mechanism.jpg", "images\\Page\\score.jpg", "images\\Page\\credits.jpg", "images\\Page\\pause.jpg", "images\\Page\\gameOver.jpg" , "images\\Page\\end.jpg" };

char frames[15][40] = { "images\\frames\\frame.jpg", "images\\frames\\frame1.jpg", "images\\frames\\frame2.jpg", "images\\frames\\frame3.jpg", "images\\frames\\frame4.jpg", "images\\frames\\frame5.jpg", "images\\frames\\frame6.jpg", "images\\frames\\frame7.jpg", "images\\frames\\frame8.jpg", "images\\frames\\frame9.jpg", "images\\frames\\frame10.jpg", "images\\frames\\frame11.jpg", "images\\frames\\frame12.jpg", "images\\frames\\frame13.jpg", "images\\frames\\frame14.jpg" };
char frames1[1][40] = { "image\\levels\\level1.jpg" };

char b[3][50] = { "images\\background\\level_1_background.jpg", "images\\background\\level_2_background.jpg", "images\\background\\level_3_background.jpg" };
char backGround1[8][50] = { "images\\background\\bg001.bmp", "images\\background\\bg002.bmp", "images\\background\\bg003.bmp",
"images\\background\\bg004.bmp","images\\background\\bg005.bmp","images\\background\\bg006.bmp","images\\background\\bg007.bmp","images\\background\\bg008.bmp" };

char backGround2[8][50] = { "images\\background\\bg011.bmp", "images\\background\\bg012.bmp", "images\\background\\bg013.bmp", "images\\background\\bg014.bmp", 
"images\\background\\bg015.bmp", "images\\background\\bg016.bmp", "images\\background\\bg017.bmp", "images\\background\\bg018.bmp" };

char backGround3[8][50] = { "images\\background\\bg021.bmp", "images\\background\\bg022.bmp", "images\\background\\bg023.bmp", "images\\background\\bg024.bmp", 
"images\\background\\bg025.bmp", "images\\background\\bg026.bmp", "images\\background\\bg027.bmp", "images\\background\\bg028.bmp" };



char lifebar[6][50] = { "images\\lifebar\\lifebar1.bmp", "images\\lifebar\\lifebar2.bmp", "images\\lifebar\\lifebar3.bmp", "images\\lifebar\\lifebar4.bmp", 
"images\\lifebar\\lifebar5.bmp", "images\\lifebar\\lifebar6.bmp"};

char levels[3][50] = { "images\\levels\\level1.jpg","images\\levels\\level2.jpg","images\\levels\\level3.jpg" };
char gameOver[50] = { "images\\background\\gameOver.jpg" };


char herowalk[6][50] = { "images\\character\\walk1.bmp","images\\character\\walk2.bmp","images\\character\\walk3.bmp","images\\character\\walk4.bmp",
"images\\character\\walk5.bmp","images\\character\\walk6.bmp"};

char herorevwalk[6][50] = { "images\\character\\revwalk1.bmp", "images\\character\\revwalk2.bmp", "images\\character\\revwalk3.bmp", 
"images\\character\\revwalk4.bmp", "images\\character\\revwalk5.bmp", "images\\character\\revwalk6.bmp"};

char herojump[2][50] = { "images\\character\\jump1.bmp","images\\character\\jump2.bmp" };

char herorevjump[2][50] = { "images\\character\\revjump1.bmp", "images\\character\\revjump2.bmp" };
char heroidle[2][50] = { "images\\character\\idle.bmp", "images\\character\\idle.bmp" };

char heroattack[4][50] = { "images\\character\\idle.bmp", "images\\character\\idle.bmp", "images\\character\\idle.bmp","images\\character\\idle.bmp" };


char f[2][50] = { "images\\character\\f1.bmp", "images\\character\\f2.bmp"};


char rounds[3][50] = { "images\\levels\\level1.jpg", "images\\levels\\level2.jpg", "images\\levels\\level3.jpg" };

//------------------------ villian level 1------------------------//

char level_1_villianattack[5][50] = { "images\\character\\l1vAttack1.bmp", "images\\character\\l1vAttack2.bmp", "images\\character\\l1vAttack3.bmp", "images\\character\\l1vAttack4.bmp", "images\\character\\l1vAttack5.bmp" };
//----------------villian level 2--------------------//
char level_2_villianattack[5][50] = { "images\\character\\l2vAttack1.bmp", "images\\character\\l2vAttack2.bmp", "images\\character\\l2vAttack3.bmp", "images\\character\\l2vAttack4.bmp", "images\\character\\l2vAttack5.bmp" };

//-------------------villian level 3---------------//

char level_3_villianattack[6][50] = { "images\\character\\l3vAttack1.bmp", "images\\character\\l3vAttack2.bmp", "images\\character\\l3vAttack3.bmp", "images\\character\\l3vAttack4.bmp", "images\\character\\l3vAttack5.bmp", "images\\character\\l3vAttack6.bmp"};



int change = 0;

int shurikenIndex = 0;
bool shurikenShow = false;

int rnd = 0;
bool roundPass = false;
int gameState = -1;
int frameIndex = 0;
int frameIndex1 = 0;
bool musicOn = true;
bool enenmyshow = false;
bool frameShowed=false;
bool frameShowed1 = false;
int heroCoordinateX = 15;
int heroCoordinateY = 80;
int heroIndex = 0;
int heroReverseIndex = 0;
bool reverseStand = false;
bool standPosition = true;
int standCounter = 0;
int life = 0;
int life1 = 0;
int life2 = 0;
bool jump = false;
bool jumpUp = false;
int level;
int levelcount = 0;
int heroCoordinateJump = 0;
bool levelShow = false;
int attacked = 0;
int villian1set = 0;
int villian12set = 0;
int shurikenX = 0;
int shurikenY = 0;
bool firing = false;
bool front = false;
bool heroVisible = true;
int kill = 0;
bool heroFire = false;
int fireIndex = 0;
int bgIndex = 0;
bool pause = false;
int vl11 = 0;
int vl12 = 0;
int vl21 = 0;
int vl22 = 0;
int vl31 = 0;
int vlboss = 0;
int killScore = 0;




void lifeBar(){
	iShowBMP2(0, screenHeigth - 80, lifebar[life], 0);
}

void lifeBar2(){
	iShowBMP2(0, screenHeigth - 80, lifebar[life1], 0);
}

void lifeBar3(){
	iShowBMP2(0, screenHeigth - 80, lifebar[life2], 0);
}


void round_one(){
	iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(levels[0]));


}
void round_two(){
	iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(levels[1]));


}

void round_three(){
	iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(levels[2]));


}



#endif