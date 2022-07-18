#include "playerWindow.h"
#include "playerPage.h"
#include "menuPage.h"

char nowName[100];

// 播放模式全局枚举
enum PLAY_STATUS play_mode = STATUS_PLAY_SEQUENCE;
char play_status[1000];
// 播放状态全局枚举
enum STATUS status = STATUS_STOPPED;
char status_now[1000];
int num = 0;
int progress_length = 90;//进度条长度
double t = 0;
double t1 = 0;
double c = 0;

void createWindow()
{
	initgraph(720, 960,0);
	char a[1000] = "";
	strcpy(a, getPath(num));

	openMusic(a);
	
	setbkcolor(WHITE);

	change();

	//设置背景图片
	IMAGE image;
	loadimage(&image, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\background.png");
	putimage(0, 0, &image);
	transparentimage(NULL,0, 0, &image);

	//暂停按钮
	IMAGE pause;
	IMAGE play2;
	IMAGE play;
	loadimage(&play2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play2.png", 81, 81);
	loadimage(&pause, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play.png", 81, 81);
	transparentimage(NULL, 334, 652, &pause);

	//上一曲图标
	IMAGE last;
	loadimage(&last, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last.png", 50, 50);
	IMAGE last2;
	loadimage(&last2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last2.png", 50, 50);
	transparentimage(NULL, 194, 666, &last);

	//下一曲图标
	IMAGE next;
	loadimage(&next, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next.png", 50, 50);
	IMAGE next2;
	loadimage(&next2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next2.png", 50, 50);
	transparentimage(NULL, 498, 671, &next);

	//改模式图标
	IMAGE change;
	loadimage(&change, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change.png",30,30);
	IMAGE change2;
	loadimage(&change2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change2.png",30,30);
	transparentimage(NULL, 92, 678, &change);

	//快进图标
	IMAGE up;
	loadimage(&up, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up.png", 36, 36);
	IMAGE up2;
	loadimage(&up2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up2.png", 36, 36);
	transparentimage(NULL, 618, 748, &up);

	//快退图标
	IMAGE down;
	loadimage(&down, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down.png", 36, 36);
	IMAGE down2;
	loadimage(&down2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down2.png", 36, 36);
	transparentimage(NULL, 94, 748, &down);

	//音量加图标
	IMAGE add1;
	loadimage(&add1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add.png", 40, 40);
	IMAGE add2;
	loadimage(&add2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add2.png", 40, 40);
	transparentimage(NULL, 170, 870, &add1);

	//音量减少图标
	IMAGE add1_lr;
	loadimage(&add1_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut.png", 40, 40);
	IMAGE add2_lr;
	loadimage(&add2_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut2.png", 40, 40);
	transparentimage(NULL, 230, 870, &add1_lr);

	IMAGE back;
	loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	IMAGE circle;
	loadimage(&circle, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\BREATHE.png", 340, 340);
	transparentimage(NULL, 110, 40, &circle);

	IMAGE issue;
	loadimage(&issue, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\issue.png", 36, 36);
	transparentimage(NULL, 608, 675, &issue);

	setbkmode(TRANSPARENT);//设置文字输出时背景为透明

	while (1)//要用个循环来不断监测鼠标事件
	{
		strcpy(nowName, getName(num));
		printtext(242, 755, nowName);
		printtext(91, 598, play_status);	

		//进度条
		t = getMusicLength();
		t1 = getMusicPosition();
		if (t != 0)
			c = t1 / t;
		progress_length = c * 523 + 90;
		fillroundrect(90, 830, progress_length, 825, 10, 10);

		if (MouseHit())
		{
			MOUSEMSG msg = GetMouseMsg();
			switch (msg.uMsg)
			{

			case WM_LBUTTONDOWN:
				if (msg.x >= 334 && msg.x <= 412 && msg.y <= 732 && msg.y >= 652)//播放按钮
				{	
					w_log((char*)"start/stop success");
					printtext(2222, 755, getName(num));
					printtext(91, 598, play_status);
					strcpy(a, (const char*)getPath(num));//传歌曲路径
					openMusic(a);
					if (status == STATUS_STOPPED)
					{

						transparentimage(NULL, 334, 652, &play2);//灰色的按钮
						Sleep(100);
						transparentimage(NULL, 334, 652, &pause);
						playMusic();
						status = STATUS_PLAY;
						strcpy(status_now, "正在播放中");
					}
					else if (status == STATUS_PLAY)
					{
						transparentimage(NULL, 334, 652, &play2);//灰色的按钮
						Sleep(100);
						transparentimage(NULL, 334, 652, &pause);
						pauseMusic();
						status = STATUS_PAUSE;
						strcpy(status_now, "暂停中");
					}
					else if (status == STATUS_PAUSE)
					{
						transparentimage(NULL, 334, 652, &play2);//灰色的按钮
						Sleep(100);
						transparentimage(NULL, 334, 652, &pause);
						resumeMusic();
						status = STATUS_PLAY;
						strcpy(status_now, "正在播放中");
					}

				}//点击播放键

				if (msg.x >= 202 && msg.x <= 236 && msg.y <= 709 && msg.y >= 676)//上一首
				{
					w_log((char*)"up next success");
					transparentimage(NULL, 194, 666, &last2);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 194, 666, &last);
					if (num > 1)
					{
						num -= 1;
					}
					//处理逻辑
					fillroundrect(96, 830, 613, 825, 10, 10);

					closeMusic();
					fundmantual();
	
					printtext(91, 598, play_status);
					strcpy(a, (const char*)getPath(num));//传歌曲路径

					openMusic(a);
					playMusic();
				}

				if (msg.x >= 506 && msg.x <= 542 && msg.y <= 711 && msg.y >= 676)//下一首
				{
					w_log((char*)"down next success");
					transparentimage(NULL, 498, 671, &next2);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 498, 671, &next);
					if (num < getNumOfNode())
					{
						num += 1;
					}
					fillroundrect(96, 830, 613, 825, 10, 10);
					closeMusic();
					fundmantual();

					printtext(91, 598, play_status);
					strcpy(a, (const char*)getPath(num));//传歌曲路径

					openMusic(a);
					playMusic();
				}

				if (msg.x >= 618 && msg.x <= 654 && msg.y <= 784 && msg.y >= 748)//快进
				{
					w_log((char*)"quick up success");
					transparentimage(NULL, 618, 748, &up2);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 618, 748, &up);
					//处理逻辑
					upTo10s();
				}

				if (msg.x >= 94 && msg.x <= 130 && msg.y <= 784 && msg.y >= 748)//快退
				{
					w_log((char*)"quick back success");
					transparentimage(NULL, 94, 748, &down2);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 94, 748, &down);
					//处理逻辑
					downTo10s();
					fundmantual();
				}

				//三种播放模式
				if (msg.x >= 92 && msg.x <= 122 && msg.y <= 708 && msg.y >= 678)
				{
					transparentimage(NULL, 92, 678, &change2);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 92, 678, &change);
					if (play_mode == STATUS_PLAY_SEQUENCE)
					{
						w_log((char*)"now play_mode random");
						play_mode = STATUS_PLAY_RANDOM;
						strcpy(play_status, "当前播放状态:  随机播放");
						fundmantual();
					}
					else if (play_mode == STATUS_PLAY_RANDOM)
					{
						w_log((char*)"now play_mode repeat");
						play_mode = STATUS_PLAY_REPEAT;
						strcpy(play_status, "当前播放状态:  单曲循环");
						fundmantual();
					}
					else if (play_mode == STATUS_PLAY_REPEAT)
					{
						w_log((char*)"now play_mode sequence");
						play_mode = STATUS_PLAY_SEQUENCE;
						strcpy(play_status, "当前播放状态:  列表播放");
						fundmantual();
					}
				}

				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//返回
				{
					closegraph();
					menu();

				}//点击返回

				if (msg.x >= 170 && msg.x <= 210 && msg.y <= 910 && msg.y >= 870)//加音量
				{
					w_log((char*)"addVolume");
					transparentimage(NULL, 170, 870, &add2);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 170, 870, &add1);
					addVolume();
				}

				if (msg.x >= 230 && msg.x <= 270 && msg.y <= 910 && msg.y >= 870)//减音量
				{
					w_log((char*)"lowVolume");
					transparentimage(NULL, 230, 870, &add2_lr);//灰色的按钮
					Sleep(100);
					transparentimage(NULL, 230, 870, &add1_lr);
					lowVolume();
				}

				if (msg.x >= 608 && msg.x <= 644 && msg.y <= 711 && msg.y >= 675)//网易云热评
				{

				/*	transparentimage(NULL, 608, 675, &issue);*/
					//处理逻辑
					WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://www.musicbooks.cn/", 1);
				}

				break;
			}
		}

		if (getMusicLength() == getMusicPosition() && play_mode == STATUS_PLAY_SEQUENCE && num > 0)//列表播放状态的逻辑
		{
			if (num > 1)
			{
				num -= 1;
			}
			//处理逻辑
			fillroundrect(96, 830, 613, 825, 10, 10);
			closeMusic();
			fundmantual();
			printtext(91, 598, play_status);
			strcpy(a, (const char*)getPath(num));//传歌曲路径
			openMusic(a);
			playMusic();
		}
		if (getMusicLength() == getMusicPosition() && play_mode == STATUS_PLAY_REPEAT && num > 0)
		{
			fillroundrect(96, 830, 613, 825, 10, 10);
			closeMusic();
			fundmantual();
			printtext(91, 598, play_status);
			strcpy(a, (const char*)getPath(num));//传歌曲路径
			openMusic(a);
			playMusic();
		}
		if (getMusicLength() == getMusicPosition() && play_mode == STATUS_PLAY_RANDOM && num > 0)
		{
			if (num > 0)
			{
				num = rand() % (getNumOfNode()) + 1;
			}
			
			fillroundrect(96, 830, 613, 825, 10, 10);
			closeMusic();
			fundmantual();
			printtext(91, 598, play_status);
			strcpy(a, (const char*)getPath(num));//传歌曲路径
			openMusic(a);
			playMusic();
		}
	}
}

void fundmantual()
{
	initgraph(720, 960, 0);
	char a[1000] = "";
	strcpy(a, getPath(num));

	openMusic(a);
	setbkcolor(WHITE);

	change();

	//设置背景图片
	IMAGE image;
	loadimage(&image, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\background.png");
	putimage(0, 0, &image);
	transparentimage(NULL, 0, 0, &image);

	//暂停按钮
	IMAGE pause;
	IMAGE play2;
	IMAGE play;
	loadimage(&play2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play2.png", 81, 81);
	loadimage(&pause, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\play.png", 81, 81);
	transparentimage(NULL, 334, 652, &pause);

	//上一曲图标
	IMAGE last;
	loadimage(&last, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last.png", 50, 50);
	IMAGE last2;
	loadimage(&last2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\last2.png", 50, 50);
	transparentimage(NULL, 194, 666, &last);

	//下一曲图标
	IMAGE next;
	loadimage(&next, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next.png", 50, 50);
	IMAGE next2;
	loadimage(&next2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\next2.png", 50, 50);
	transparentimage(NULL, 498, 671, &next);

	//改模式图标
	IMAGE change;
	loadimage(&change, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change.png", 30, 30);
	IMAGE change2;
	loadimage(&change2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\change2.png",30, 30);
	transparentimage(NULL, 92, 678, &change);

	//快进图标
	IMAGE up;
	loadimage(&up, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up.png", 36, 36);
	IMAGE up2;
	loadimage(&up2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\up2.png", 36, 36);
	transparentimage(NULL, 618, 748, &up);

	//快退图标
	IMAGE down;
	loadimage(&down, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down.png", 36, 36);
	IMAGE down2;
	loadimage(&down2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\down2.png", 36, 36);
	transparentimage(NULL, 94, 748, &down);

	IMAGE back;
	loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
	transparentimage(NULL, 15, 12, &back);

	IMAGE circle;
	loadimage(&circle, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\BREATHE.png", 340, 340);
	transparentimage(NULL, 110, 40, &circle);

	//音量加图标
	IMAGE add1;
	loadimage(&add1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add.png", 40, 40);
	IMAGE add2;
	loadimage(&add2, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\add2.png", 40, 40);
	transparentimage(NULL, 170, 870, &add1);

	//音量减少图标
	IMAGE add1_lr;
	loadimage(&add1_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut.png", 40, 40);
	IMAGE add2_lr;
	loadimage(&add2_lr, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\cut2.png", 40, 40);
	transparentimage(NULL, 230, 870, &add1_lr);

	IMAGE issue;
	loadimage(&issue, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\issue.png", 36, 36);
	transparentimage(NULL, 608, 675, &issue);

}

char* attainlength(int time) {
	int fen = 0;
	int miao = 0;
	miao = (int)time / 1000;
	fen = (int)miao / 60;
	miao = (int)miao - fen * 60;
	char f[100];//分
	char m[100];//秒
	char tatol[100];//总的
	itoa(miao, m, 10);
	itoa(fen, f, 10);
	strcpy(tatol, f);
	strcat(tatol, " : ");
	if (miao < 10)
	{
		strcat(tatol, "0");
	}
	strcat(tatol, m);
	return tatol;
}

void printtext(int x, int y,char text[100])
{
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);//设置文字输出时背景为透明
	outtextxy(x, y, text);
}

int getnum()
{
	return num;
}

void setnum(int n)
{
	num = n;
}