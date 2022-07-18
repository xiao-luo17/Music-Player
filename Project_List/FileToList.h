
#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <io.h>

typedef struct Media {
	char name[200]; //歌曲名字
	char path[500]; //绝对路径
	char short_path[500]; //短路径
	int length;     //时长
};

typedef struct mediaNode {
	Media media;
	int num;        //编号
	struct mediaNode* pre;
	struct mediaNode* next;
};

mediaNode* createList();

mediaNode* createNode(Media music);

void headInsert(mediaNode* headNode, Media music);

Media* createMedia(const char* path);

int deleteNode(mediaNode* headNode);
