#include<iostream>
#include "iGraphics.h"
#include "bitmap_loader.h"
#include"variables.h"
#include "menu.h"
#include "heroMovement.h"
#include "villian1.h"
#include"villian2.h"
#include "villian3.h"
#include "scores.h"
//__________________________________________________________scoring part_________________________________________________________________
bool play_ground = false;
char str1[40];
bool take_name = false;
int len = 0;
bool high_score_page = false;
void showChar()
{
	iSetColor(255, 255, 255);
	iText(680, 800, "Enter your name", GLUT_BITMAP_TIMES_ROMAN_24);
	iRectangle(660, 730, 220, 30);
	iText(670, 740, str1, GLUT_BITMAP_HELVETICA_18);

}
typedef struct Player Player;

struct Player{
	char name[30];
	int score = 0;
	Player()
	{
		;
	}
	Player(char *_name, int _score)
	{
		strcpy(name, _name);
		score = _score;
	}
};
typedef struct sorting
{
	char ch[30];
	int sc;
} sorts;

void sort_stru(sorting o1[], int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (o1[i].sc < o1[j].sc)
			{
				sorting temp = o1[i];
				o1[i] = o1[j];
				o1[j] = temp;
			}
		}
	}
}
Player o1;
void high_page_sorting(){
	FILE *fp = fopen("high_score.txt", "a");
	fprintf(fp, "%s %d\n", o1.name, o1.score);
	fclose(fp);
}
void showing_score_page(){
	int z;
	FILE *fp = fopen("high_score.txt", "r");
	char chs[30];
	int cnt = 0;
	while (fscanf(fp, "%s%d", &chs, &z) != EOF)
	{
		cnt++;
	}
	sorts o2[100];
	fclose(fp);
	fp = fopen("high_score.txt", "r");
	for (int i = 0; i < cnt; i++)
	{
		fscanf(fp, "%s%d", &chs, &z);
		strcpy(o2[i].ch, chs);
		o2[i].sc = z;
	}
	fclose(fp);
	fp = fopen("high_score.txt", "r");
	sort_stru(o2, cnt);
	int x = cnt;
	if (cnt>7){
		x = 7;
	}
	for (int i = 0; i <x; i++)
	{
		char name[2][30];
		fprintf(fp, "%s %d\n", o2[i].ch, o2[i].sc);
		sprintf(name[0], "%s", o2[i].ch);
		sprintf(name[1], "%d", o2[i].sc);
		iSetColor(0, 0, 0);
		iText(700, 550 - 50 * i, name[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900, 550 - 50 * i, name[1], GLUT_BITMAP_TIMES_ROMAN_24);
	}
	fclose(fp);
}
char point[1000];
void takeinput(unsigned char key){
	
	if (key == '\r'){
		strcpy(o1.name, str1);
		o1.score =score ;
		high_page_sorting();
		exit(0);
	}
	else if (key == '\b'){
		if (len <= 0){
			len = 0;
		}
		else
			len--;
		str1[len] = '\0';
	}
	else{
		str1[len] = key;
		len++;
		if (len > 15){
			len = 15;
		}str1[len] = '\0';
	}
}

//__________________________________________________________scoring part END_____________________________________________________________
struct renderBackground{
	int x, y;
} background[8];
renderBackground background2[8];
renderBackground background3[8];
void bgShow(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background[i].x, background[i].y, backGround1[i]);
}
void bgShow2(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background2[i].x, background2[i].y, backGround2[i]);
}
void bgShow3(){
	for (int i = 0; i < 8; i++)
		iShowBMP(background3[i].x, background3[i].y, backGround3[i]);
}

bool showing_scoring = false;
int cnt_scor = 0;

void levelChange(){
	if (heroCoordinateX >= screenWidth - 150 && level == 1){

		level = 2;
	}
	else if (heroCoordinateX +150 >= screenWidth && level_2_coll >= 3 && level_count_f==0 && level == 2){
		//roundPass = true;
		level_2_coll = 0;
		level = 3;
		//gameState = 100;
		cout << level_count_f << endl;
	
	}
	/*else if (heroCoordinateX >= screenWidth - 150 && heroCoordinateY <= 100 && level == 3 && roundPass){
		//level = 99;
		gameState = 6;
	}
	*/
}

void iDraw()
{
	iClear();
	if (cnt_scor >= 10){

	}
	if (gameState == -1){
		menuShow();
	}
	else if (gameState == 0 && frameShowed)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(frames[frameIndex]));
	}
	else if (gameState == 0 && frameShowed1)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(frames1[frameIndex1]));
	}
	else if (gameState == 0 && level==1){
		if (!pause){
				levelChange();
				bgShow();
				lifeBar();
				
				villian1Movement();
				villian12Movement();
				scorecounter();
				if (jump){
					Jump();
				}
				else{
					Character();
				}
			}
		else {
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[5]));
		}
}
	else if (gameState == 0 && level == 2)
{
		if (!pause){
			levelChange();
			bgShow2();
			lifeBar2();
			villian21Movement();
			villian22Movement();
			scorecounter();
			if (jump){
				Jump();
			}
			else{
				Character();
			}
		}
		else {
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[5]));
		}
	}
	else if (gameState == 0 && level == 3)
	{
		if (level_count_f >= 3 && (heroCoordinateX + 150 >= screenWidth)){
			gameState = 6;
		}
		if (!pause){
			bgShow3();
			lifeBar3();
			
			bossMovement();
			scorecounter();
			if (jump){
				Jump();
			}
			else{
				Character();
			}
		}
		else {
			iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[5]));
		}
	}
	else if (gameState == 1)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[2]));
		
	}
	else if (gameState == 2)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[3]));
		showing_score_page();
	}
	else if (gameState == 3)
	{
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[4]));
	}
	else if (gameState == 4)
	{
		exit(0);
	}
	else if (gameState == 5){
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[6]));
	}
	else if (gameState == 6){
		iShowImage(0, 0, screenWidth, screenHeigth, iLoadImage(pages[7]));
		
	}
	if (showing_scoring){
		showChar();
	}
	
}

void changeBackground()
{
	if (level == 1){
		if (standPosition == false){
			for (int i = 0; i < 8; i++)
			{
				background[i].x -= backGroundSpeed;
				if (background[i].x < 0)
					background[i].x = screenWidth - 200;
			}
		}
	}
	else if (level == 2){
	if (standPosition == false){
	for (int i = 0; i < 8; i++)
	{
	background2[i].x -= backGroundSpeed;
	if (background2[i].x < 0)
	background2[i].x = screenWidth - 200;
	}
	}
	}
	else if (level == 3){
		if (standPosition == false){
			for (int i = 0; i < 8; i++)
			{
				background3[i].x -= backGroundSpeed;
				if (background3[i].x < 0)
					background3[i].x = screenWidth - 200;
			}
		}
	}


} 

void iPassiveMouse(int x, int y){;}
void iMouseMove(int mx, int my){}

void iMouse(int button, int state, int mx, int my){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		for (int i = 0; i < 5; i++){
			if (mx >= buttonCordinate[i].x && mx <= buttonCordinate[i].x + 434 && my >= buttonCordinate[i].y && my <= buttonCordinate[i].y + 104)
			{
				gameState = i;
				if (gameState == 0){
					frameShowed = true;
				}
			}
		}
	}


}
void iKeyboard(unsigned char key){
	if (showing_scoring){
		takeinput(key);
	}
	if (key =='\t' )
	{
		if (level!=1 ||level!=2 || level!=3){
			gameState = -1;
		}
	}
	else if (key == ' '){
		if (!jump){
			jump = true;
			jumpUp = true;
		}
	}
	else if (key == 'd' || key == 'D'){
		standPosition = false;
		reverseStand = false;
		
		heroCoordinateX += 20;
		if (heroCoordinateX >= screenWidth){
			heroCoordinateX = 0;
		}
		heroIndex++;
		if (heroIndex >= 6)
			heroIndex = 0;
		if (heroCoordinateX >= screenWidth-120)
			heroCoordinateX = 0;
	}
	else if (key == 'a' || key == 'A'){
		standPosition = false;
		heroCoordinateX -= 10;
		reverseStand = true;
		
		if (heroCoordinateX <= 20){
			heroCoordinateX = 10;
		}
		heroReverseIndex++;
		if (heroReverseIndex >= 6)
		{
			heroReverseIndex = 0;
		}
	}
	else if (key == 's' || key == 'S'){
		standPosition = false;
		heroCoordinateY -= 15;
		
		if (heroCoordinateY <=0){
			heroCoordinateY = 0;
		}
		heroIndex++;
		if (heroIndex >= 6)
		{
			heroIndex = 0;
		}
	}
	else if (key == 'w' || key == 'W'){
		standPosition = false;
		reverseStand = false;
		
		heroCoordinateY += 15;
		if (heroCoordinateY >= 110){
			heroCoordinateY = 110;
		}
		heroIndex++;
		if (heroIndex >= 6)
			heroIndex = 0;
		if (heroCoordinateX >= screenWidth - 150)
			heroCoordinateX = screenWidth - 150;
	}
	else if (key == 'e' || key == 'E'){
		heroFire = true;
		if (!firing){
			firing = true;
				shurikenX = heroCoordinateX;
				if (jumpUp) shurikenY = heroCoordinateY + heroCoordinateJump + 100;
				else 
					shurikenY = heroCoordinateY + 100;
		}
	}
	else if (key == 'p' || key == 'P'){
		if (!pause){
			pause = true;
		}
		else
		{
			pause = false;
		}
	}
	else if (key == 'm' || key == 'M'){
		
		if (musicOn)
		{
			musicOn = false;
			PlaySound(0,0,0);
		}
		else
		{
			musicOn = true;
			PlaySound("music\\mus1.wav", NULL, SND_LOOP | SND_ASYNC);
		}

	

	}
}
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_F2){

		if (frameShowed){
			frameIndex++;
			if (frameIndex ==15){
			level = 1;
			frameIndex = 0;
			frameShowed = false;
			
		}
		}
		
	}
	
}

void setbackground()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background[i].x = sum;
		background[i].y = 0;
		sum += 200;
	}
}
void setbackground2()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background2[i].x = sum;
		background2[i].y = 0;
		sum += 200;
	}
}
void setbackground3()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		background3[i].x = sum;
		background3[i].y = 0;
		sum += 200;
	}
}

void changeings__(){
	if (gameState == 5 || gameState == 6)
		cnt_scor++;
	if (cnt_scor >= 15){
		showing_scoring = true;
	}
}
int main()
{   
	setbackground();
	setbackground2();
	setbackground3();
	setVillianVariables1();
	setVillianVariables12();
	setVillianVariables21();
	setVillianVariables22();
	//setVillianVariables31();
	setBossVariables();



	iSetTimer(200, changeings__);
	iSetTimer(400, changeBackground);
	iSetTimer(20, fire_shuriken);
	iSetTimer(100, villian1Show);
//	iSetTimer(100, villian1Show1);
//	iSetTimer(100, villian21Show);
	iSetTimer(100, villian22Show);
	iSetTimer(100, gameScore);
	//iSetTimer(100, villian31Show);
	iSetTimer(100, bossShow);
	iSetTimer(20, fireCharacter);
	iSetTimer(20, jumpchange);


	showButton();


	if (musicOn)
	{
		PlaySound("music\\mus1.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	iInitialize(screenWidth, screenHeigth, projectName);




	iStart(); 

	return 0;
}

