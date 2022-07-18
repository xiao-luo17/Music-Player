#pragma once
#include "all.h"

// 代表三种不同的播放模式
enum PLAY_STATUS
{
	STATUS_PLAY_SEQUENCE = 0,
	STATUS_PLAY_REPEAT,
	STATUS_PLAY_RANDOM,
};

// 代表当前音乐的播放状态
enum STATUS
{
	STATUS_PLAY = 0,
	STATUS_PAUSE,
	STATUS_STOPPED,
};

//通过MCI接口API指令操作音乐文件
// 成功: return 0
// 失败: return !=0
// returnString: 返回错误字符串信息
//
int mciSendStringUtil(const char* url, char* returnString);

//打开设备: 默认MP3
// 通过MCI接口API指令操作音乐文件
// 其中mciSendString指令被封装于mciSendStringUtil中
// 通过open字符串拼接传参并赋予别名"MyMusic"
// 后续相同操作只需指明别名
// 成功: return 0
// 失败: return !=0
//
int openMusic(const char* url);

//以下函数中将包含MyMusic别名
// 通过别名对mciSendString接口传参
// 即包含了open命令:
// 定义open设备操作为MyMusic
//

//设备开始播放音乐
int playMusic();

//设备暂停播放音乐
int pauseMusic();

//设备继续播放音乐
int resumeMusic();

//设备停止播放音乐
int stopMusic();

//设备重复播放音乐
int playMusicRepeat();

//设备关闭
// 设备关闭接口，而非音乐停止接口
//
int closeMusic();

//返回当前播放位置
int getMusicPosition();

//返回播放音乐的总长度
int getMusicLength();

//设置指定播放位置
// 通过外部传参position实现
// 执行"seek 别名 to 位置"指令
// 使音乐到达指定位置:
// 参数说明: 
// //任意位置: position
// //定位音乐开头位置: start
// //定位音乐最后位置: end
//
int gotoPosition(int position);

int getMusicSpeed();

void setMusicSpeed(int speed);

void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg);

void change();

void addVolume();

void lowVolume();

int w_log(char a[100]);

//集成绝大多数MCI的API指令封装为简单的接口
// mci集成工具集: util.cpp
//