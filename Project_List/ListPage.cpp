#include "ListPage.h"
#include "FileToList.h"
#include <wtypes.h>
#include "playerWindow.h"
mediaNode* list = createList();
void add() {
	
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME file = { 0 };

	file.hwndOwner = NULL;
	file.lStructSize = sizeof(file);
	file.lpstrFilter = "mp3文件(*.mp3)\0*.mp3\0";//要选择的文件后缀
	file.lpstrFile = szBuffer;//存放文件的缓冲区
	file.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	file.nFilterIndex = 0;
	file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT
	BOOL bSel = GetOpenFileName(&file);
	Media* music = createMedia(file.lpstrFile);
	if (music != NULL) {
		headInsert(list, *music);
	}
}

int getNumOfNode()
{
	int num = 0;
	mediaNode* pMove = list->next;
	while (pMove != NULL) {
		num++;
		pMove = pMove->next;
	}
	return num;
}

//传入编号和主函数和链表返回歌曲名字
char* getName(int num) {
	
	char name[200];
	mediaNode* pMove = list->next;
	if (pMove == NULL)
	{
		return (char*)"等待播放列表暂时还没有歌曲噢";
	}
	while (pMove != NULL) {
		if (num == pMove->num) {
			strcpy_s(name, sizeof(name), pMove->media.name);
			break;
		}
		pMove = pMove->next;
	}
	return name;
}

char* getPath(int num) {
	char path[200];
	mediaNode* pMove = list->next;
	while (pMove != NULL) {
		if (num == pMove->num) {
			strcpy_s(path, sizeof(path), pMove->media.path);
			break;
		}
		pMove = pMove->next;
	}
	return path;
}

void printList()
{
	mediaNode* pMove = list->next;
	int i=0;
	while (pMove != NULL)
	{
		printtext(320,60+i, pMove->media.name);
		pMove = pMove->next;
		i += 60;
	}
}


void del() 
{
	deleteNode(list);
}

