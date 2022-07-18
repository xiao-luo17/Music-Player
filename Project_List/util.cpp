#include "util.h"
#include<graphics.h>
char* wday[] = { (char*)"Sun", (char*)"Mon", (char*)"Tue", (char*)"Wed", (char*)"Thu", (char*)"Fri", (char*)"Sat" };

using namespace std;
//通过MCI接口API指令操作音乐文件
// 成功: return 0
// 失败: return !=0
// returnString: 返回错误字符串信息
//
int mciSendStringUtil(const char* url, char* returnString)
{
	if (url == NULL)
	{
		if (0 != mciSendString(url, NULL, 0, NULL))
		{
			return -1;
		}
		else {
			return 0;
		}
	}
	else
	{
		if (0 != mciSendString(url, returnString, 1024, NULL)) 
		{
			return -2;
		}
		else {
			return 0;
		}
	}
}

//打开设备: 默认MP3
// 通过MCI接口API指令操作音乐文件
// 其中mciSendString指令被封装于mciSendStringUtil中
// 通过open字符串拼接传参并赋予别名"MyMusic"
// 后续相同操作只需指明别名
// 成功: return 0
// 失败: return !=0
//
int openMusic(const char* url)
{
	if (url != NULL) 
	{
		char cmd[500] = "";
		strcpy_s(cmd, "open \"");
		strcat_s(cmd, url);
		strcat_s(cmd, "\"");
		strcat_s(cmd, " alias MyMusic");
		if (mciSendStringUtil(cmd, NULL) == 0)
		{
			return 0;
		}
	}
}

//以下函数中将包含MyMusic别名
// 通过别名对mciSendString接口传参
// 即包含了open命令:
// 定义open设备操作为MyMusic
//

//设备开始播放音乐
int playMusic()
{
	char cmd[500] = "play MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//设备暂停播放音乐
int pauseMusic()
{
	char cmd[500] = "pause MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//设备继续播放音乐
int resumeMusic() 
{
	char cmd[500] = "resume MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//设备停止播放音乐
int stopMusic()
{
	char cmd[500] = "stop MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//设备重复播放音乐
int playMusicRepeat()
{
	char cmd[1000] = "play MyMusic repeat";
	return mciSendStringUtil(cmd, NULL);
}

//设备关闭
// 设备关闭接口，而非音乐停止接口
int closeMusic()
{
	char cmd[1000] = "close MyMusic";
	return mciSendStringUtil(cmd, NULL);
}

//返回当前播放位置
int getMusicPosition()
{
	char szTimeBuffer[1024];
	mciSendStringUtil("status MyMusic position", szTimeBuffer);
	return atoi(szTimeBuffer);
}

//返回播放音乐的总长度
int getMusicLength()
{
	char szTimeBuffer[1024];
	mciSendStringUtil("status MyMusic length", szTimeBuffer);
	return atoi(szTimeBuffer);
}

//设置指定播放位置
// 通过外部传参position实现
// 执行"seek 别名 to 位置"指令
// 使音乐到达指定位置:
// 参数说明: 
// //任意位置: position
// //定位音乐开头位置: start
// //定位音乐最后位置: end
//
int gotoPosition(int position)
{
	char cmd[1000] = "";
	sprintf(cmd, "seek MyMusic to %d", position);
	return mciSendStringUtil(cmd, NULL);
}

int getMusicSpeed()
{
	char szSpeedBuffer[1024];
	mciSendStringUtil("status MyMusic speed", szSpeedBuffer);
	return atoi(szSpeedBuffer);
}

void setMusicSpeed(int speed)
{
	char cmd[1000] = "";
	sprintf(cmd, "set MyMusic speed %d", speed);
	mciSendStringUtil(cmd, NULL);
}

void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg)
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();

	// 结构体的第三个成员表示额外的透明度，0 表示全透明，255 表示不透明。
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	// 使用 Windows GDI 函数实现半透明位图
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void change() //实现无边框窗口
{
	HWND hnd = GetHWnd();//获取窗口句柄
	SetWindowText(hnd, "玉玉云音乐播放器");
}

void upTo10s()
{
	int time = getMusicPosition() + 10000;
	if (time > getMusicLength())
	{
		time = getMusicLength();
	}
	gotoPosition(time);
	playMusic();
}

void downTo10s()
{
	int time = getMusicPosition() - 10000;
	if (time < 0)
	{
		time = 0;
	}
	gotoPosition(time);
	playMusic();
}

void addVolume() 
{
	char vo[20];
	char res[260];
	char file1[100] = "setaudio MyMusic volume to "; // to后面一定要有空格，不然会报错
	
	mciSendString("status MyMusic volume", res, 260, NULL);
	int volume = 0;
	volume = atoi(res); // 转化语句
	volume += 200;
	if (volume >= 1000)
		volume = 1000;
	itoa(volume, vo, 10); //转化语句
	strcat(file1, vo); // 将vo接在file1后面
	mciSendString(file1, 0, 0, 0); // 设定成功
}

void lowVolume() 
{
	char vo[20];
	char res[260];
	char file1[100] = "setaudio MyMusic volume to "; // to后面一定要有空格，不然会报错
	mciSendString("status MyMusic volume", res, 260, NULL);
	int volume = 0;
	volume = atoi(res); // 转化语句
	volume -= 200;
	if (volume <= 0)
		volume = 0;
	itoa(volume, vo, 10); //转化语句
	strcat(file1, vo); // 将vo接在file1后面
	mciSendString(file1, 0, 0,0); // 设定成功
}

int w_log(char a[100])
{
	FILE* fpWrite = fopen("D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\log.txt", "a");
	if (fpWrite == NULL)
	{
		return 0;
	}
	time_t timep;
	struct tm* p;
	time(&timep);
	p = gmtime(&timep);
	fprintf(fpWrite, "%d.%d.%d ", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);
	fprintf(fpWrite, "%s %d:%d:%d -- %s\n", wday[p->tm_wday], p->tm_hour - 4, p->tm_min, p->tm_sec, a);
	fclose(fpWrite);
}
//集成绝大多数MCI的API指令封装为简单的接口
// mci集成工具集: util.cpp
//