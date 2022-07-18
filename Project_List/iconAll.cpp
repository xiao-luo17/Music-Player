//#include <graphics.h>		// 图形库
//#include<easyx.h>
//#include <conio.h>
//#include<stdio.h>
//#include <ctime>
//#include<Windows.h>
//#include<stdlib.h>
//#include<mmsystem.h>//包含多媒体文件接口
//#pragma comment(lib,"WINMM.LIB")//加载静态库
//IMAGE fengmian;
//extern music* head;
//extern int musiclength;//音乐长度
//int progress_length = 90;//进度条长度
//char zhuanji[100];
//char currentname[100] = "0";//全局变量，当前的歌名；
//int status = 0;//歌曲播放状态
//
//
////消除MOUSEHIT的警告
//#define _CRT_SECURE_NO_DEPRECATE
//#pragma warning(disable:4996)
//
////使png图片透明
//void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
//{
//	HDC dstDC = GetImageHDC(dstimg);
//	HDC srcDC = GetImageHDC(srcimg);
//	int w = srcimg->getwidth();
//	int h = srcimg->getheight();
//
//	// 结构体的第三个成员表示额外的透明度，0 表示全透明，255 表示不透明。
//	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
//	// 使用 Windows GDI 函数实现半透明位图
//	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
//}
//
//
//
//void windows(int n) {
//
//
//	HWND hwnd = initgraph(640, 480, EW_SHOWCONSOLE);//创建窗口
//
//
//	//设置背景色
//	setbkcolor(WHITE);
//	cleardevice();
//
//	change();
//
//
//
//	//设置背景图片
//	IMAGE image;
//	loadimage(&image, "./picture/background.png");
//	putimage(0, 0, &image);
//
//
//	//暂停按钮
//	IMAGE pause;
//	IMAGE play2;
//	loadimage(&play2, "./picture/play2.png", 36, 36);
//	loadimage(&pause, "./picture/play.png", 36, 36);
//	transparentimage(NULL, 302, 400, &pause);
//
//
//	//网易云按钮
//	IMAGE comment;
//	loadimage(&comment, "./picture/comment.png", 27, 27);
//	transparentimage(NULL, 480, 405, &comment);
//
//	//返回按钮
//	IMAGE back;
//	loadimage(&back, "./picture/back.png", 30, 30);
//	transparentimage(NULL, 15, 12, &back);
//
//	//下一曲图标
//	IMAGE next;
//	loadimage(&next, "./picture/next.png", 36, 36);
//	IMAGE next2;
//	loadimage(&next2, "./picture/next2.png", 36, 36);
//	transparentimage(NULL, 380, 400, &next);
//
//	//上一曲图标
//	IMAGE last;
//	loadimage(&last, "./picture/last.png", 36, 36);
//	IMAGE last2;
//	loadimage(&last2, "./picture/last2.png", 36, 36);
//	transparentimage(NULL, 222, 400, &last);
//
//	//循环图标
//	IMAGE circle;
//	loadimage(&circle, "./picture/circle.png", 36, 36);
//	IMAGE circle2;
//	loadimage(&circle2, "./picture/circle2.png", 36, 36);
//	transparentimage(NULL, 130, 400, &circle);
//
//
//
//	setbkmode(TRANSPARENT);//设置文字输出时背景为透明
//
//	//进度条
//	fillroundrect(90, 355, 550, 350, 10, 10);
//
//	play_and_pause(playmusicbynumber(n, head));//默认播放
//
//	status = 1;
//	int width = 620 / 2 - textwidth(zhuanji) / 2;
//	int height = 100 / 2 - textheight(zhuanji) / 2;
//	drawtext(30, width, height, zhuanji);
//
//
//
//
//
//	printf("%d", musiclength);
//	int t = 0;
//	t = musiclength / 100 / 460;
//	long int t1 = 0;
//	//鼠标信息
//	while (1)//要用个循环来不断监测鼠标事件
//	{
//
//		if (progress_length < 550 && t1 % 200000000 == 0 && status == 1)
//		{
//			setfillcolor(0xAAAAAA);
//
//			fillroundrect(90, 355, progress_length, 350, 10, 10);
//			progress_length = progress_length + t;
//
//
//		}
//		t1 = t1 + 1;
//
//		if (MouseHit())
//		{
//
//
//			MOUSEMSG msg = GetMouseMsg();
//
//
//
//			switch (msg.uMsg)
//			{
//			case WM_LBUTTONDOWN:
//				if (msg.x >= 302 && msg.x <= 338 && msg.y <= 436 && msg.y >= 400)//播放按钮
//				{
//
//					transparentimage(NULL, 302, 400, &play2);//灰色的按钮
//					Sleep(100);
//					transparentimage(NULL, 302, 400, &pause);
//
//					play_and_pause(currentname);
//
//				}//点击播放键
//
//
//
//				if (msg.x >= 380 && msg.x <= 416 && msg.y <= 436 && msg.y >= 400)//下一首
//				{
//					transparentimage(NULL, 380, 400, &next2);//灰色的按钮
//					Sleep(100);
//					transparentimage(NULL, 380, 400, &next);
//					fundmantual();//重置界面
//
//					nextmusic(head, currentname);
//
//					//刷新进度条
//					setfillcolor(WHITE);
//					fillroundrect(90, 355, 550, 350, 10, 10);
//					progress_length = 90;//进度条长度
//					int width = 620 / 2 - textwidth(zhuanji) / 2;
//					int height = 100 / 2 - textheight(zhuanji) / 2;
//					drawtext(30, width, height, zhuanji);
//				}//点击下一首
//
//
//
//				if (msg.x >= 222 && msg.x <= 258 && msg.y <= 436 && msg.y >= 400)//上一首
//				{
//					transparentimage(NULL, 222, 400, &last2);//灰色的按钮
//					Sleep(100);
//					transparentimage(NULL, 222, 400, &last);
//					fundmantual();
//					lastmusic(head, currentname);
//					//进度条
//					setfillcolor(WHITE);
//					fillroundrect(90, 355, 550, 350, 10, 10);
//					progress_length = 90;//进度条长度
//
//
//					int width = 620 / 2 - textwidth(zhuanji) / 2;
//					int height = 100 / 2 - textheight(zhuanji) / 2;
//					drawtext(30, width, height, zhuanji);
//
//				}//点击上一首
//
//
//				if (msg.x >= 130 && msg.x <= 166 && msg.y <= 436 && msg.y >= 400)//上一首
//				{
//					transparentimage(NULL, 130, 400, &circle2);//灰色的按钮
//					Sleep(100);
//					transparentimage(NULL, 130, 400, &circle);
//
//					repeatmusic(currentname);
//					setfillcolor(WHITE);
//					fillroundrect(90, 355, 550, 350, 10, 10);
//					progress_length = 90;//进度条长度
//					int width = 600 / 2 - textwidth(zhuanji) / 2;
//					int height = 100 / 2 - textheight(zhuanji) / 2;
//					drawtext(30, width, height, zhuanji);
//
//				}//点击循环
//
//
//
//				if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//返回
//				{
//					closemusic(currentname);
//					closegraph();
//					menu();
//
//				}//点击返回
//
//				if (msg.x >= 480 && msg.x <= 507 && msg.y <= 432 && msg.y >= 405)//上一首
//				{
//					WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://music.163.com/#/song?id=1388961676", 1); //跳到网易云热评
//
//
//				}//点网易云
//
//
//
//
//
//				printf("坐标(%d,%d)\n", msg.x, msg.y);
//				break;
//			case WM_RBUTTONDOWN:
//				outtextxy(400, 400, "鼠标右键按下");
//				printf("坐标(%d,%d)\n", msg.x, msg.y);
//				break;
//			}
//
//
//
//		}
//
//
//
//
//
//	}
//
//
//
//
//	getchar();
//	//关闭窗口
//	closegraph();
//
//}
//
//void change() //实现无边框窗口
//{
//	HWND hnd = GetHWnd();//获取窗口句柄
///*
//long style = GetWindowLong(hnd, GWL_STYLE);
//	style &= ~WS_CAPTION;
//	SetWindowLong(hnd, GWL_STYLE, style);
//*/
//	SetWindowText(hnd, "Hello Music");
//
//}
//
//void show_progress() {
//	int t = 0;
//	t = musiclength / 100 / 460;
//	if (progress_length < 550)
//	{
//		setfillcolor(0xAAAAAA);
//		Sleep(1000);//延时0.1秒
//		fillroundrect(90, 355, progress_length, 350, 10, 10);
//		progress_length = progress_length + t;
//	}
//}
//
//void drawtext(int size, int x, int y, char text[100]) {
//	settextcolor(WHITE);
//	setbkmode(TRANSPARENT);//设置文字输出时背景为透明
//
//	settextstyle(size, 0, "微软雅黑");
//	outtextxy(x, y, text);
//}
//
//char* attainlength(int time) {
//	int fen = 0;
//	int miao = 0;
//	miao = (int)time / 1000;
//	fen = (int)miao / 60;
//	miao = (int)miao - fen * 60;
//	char f[100];//分
//	char m[100];//秒
//	char tatol[100];//总的
//	itoa(miao, m, 10);
//	itoa(fen, f, 10);
//	strcpy(tatol, f);
//	strcat(tatol, " : ");
//	if (miao < 10)
//	{
//		strcat(tatol, "0");
//	}
//	strcat(tatol, m);
//	return tatol;
//}
//
//void fundmantual() {
//	//设置背景色
//	setbkcolor(WHITE);
//	cleardevice();
//
//
//
//
//	//设置背景图片
//	IMAGE image;
//	loadimage(&image, "./picture/background.png");
//	putimage(0, 0, &image);
//
//
//
//
//	//暂停按钮
//	IMAGE pause;
//	loadimage(&pause, "./picture/play.png", 36, 36);
//	transparentimage(NULL, 302, 400, &pause);
//
//	//下一曲图标
//	IMAGE next;
//	loadimage(&next, "./picture/next.png", 36, 36);
//	transparentimage(NULL, 380, 400, &next);
//
//	//上一曲图标
//	IMAGE last;
//	loadimage(&last, "./picture/last.png", 36, 36);
//	transparentimage(NULL, 222, 400, &last);
//
//
//	IMAGE fengmian;
//	loadimage(&fengmian, "./cards/BREATHE.png", 200, 200);
//	transparentimage(NULL, 222, 100, &fengmian);
//
//	drawpicture();
//
//	//返回按钮
//	IMAGE back;
//	loadimage(&back, "./picture/back.png", 30, 30);
//	transparentimage(NULL, 15, 12, &back);
//
//
//	//网易云按钮
//	IMAGE comment;
//	loadimage(&comment, "./picture/comment.png", 27, 27);
//	transparentimage(NULL, 480, 405, &comment);
//
//
//	//循环图标
//	IMAGE circle;
//	loadimage(&circle, "./picture/circle.png", 36, 36);
//	transparentimage(NULL, 130, 400, &circle);
//
//
//	setbkmode(TRANSPARENT);//设置文字输出时背景为透明
//
//	//进度条
//	fillroundrect(90, 355, 550, 350, 10, 10);
//}
//
//
//
//void getzhuanjiname() {
//
//
//	int lenth = strlen(currentname);//数组长度
//
//	for (int i = 0; i <= lenth; i++) {
//		if (currentname[i] == '.') {
//			lenth = i;
//			break;
//		}
//	}
//	memset(zhuanji, 0, strlen(zhuanji));//刷新专辑名字
//	strncpy(zhuanji, currentname, lenth);
//	char str1[100];
//	sprintf(str1, "./cards/%s.png", zhuanji);
//	loadimage(&fengmian, str1, 200, 200);//加载图片
//
//}
