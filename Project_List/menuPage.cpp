#include "menuPage.h"
#include "util.h"
#include "playerWindow.h"
#include "listmenu.h"

void menu()
{
    int logostatus = 0;
    initgraph(640, 480, 0);
    //背景图片
    IMAGE img1;
    loadimage(&img1, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\mainmenu.png");
    putimage(0, 0, &img1);    

    IMAGE choice;
    loadimage(&choice, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\menuchoice.png"); 

    while (1) {
        //鼠标操作
        if (MouseHit()) {
            MOUSEMSG msg = GetMouseMsg();

            //显示灰色块块
            if (msg.x >= 369 && msg.x <= 583 && msg.y >= 69 && msg.y <= 160 && logostatus == 0) {
                transparentimage(NULL, 369, 69, &choice);
                logostatus = 1;

            }
            else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 195 && msg.y <= 264 && logostatus == 0)
            {
                transparentimage(NULL, 369, 195, &choice);
                logostatus = 1;
            }
            else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 321 && msg.y <= 390 && logostatus == 0)
            {
                transparentimage(NULL, 369, 321, &choice);
                logostatus = 1;
            }
            else
            {
                putimage(0, 0, &img1);
                logostatus = 0;
            }

            switch (msg.uMsg)
            {
            case WM_LBUTTONDOWN:

                if (msg.x >= 369 && msg.x <= 583 && msg.y >= 69 && msg.y <= 160) {
                    closegraph();
                    createWindow();

                }
                else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 195 && msg.y <= 264)
                {
                    closegraph();
                    listmenu();
                }
                else if (msg.x >= 369 && msg.x <= 583 && msg.y >= 321 && msg.y <= 390)
                {
                    closegraph();
                    copyright();
                }
                break;
            default:
                break;
            }
        }
    }
}

void copyright() {
    initgraph(720,960, 0);
    setbkmode(TRANSPARENT);

    //背景图片
    IMAGE im;
    loadimage(&im, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\copyright.png");
    putimage(0, 0, &im);

    //返回按钮
    IMAGE back;
    loadimage(&back, "D:\\visual studio project\\yuyucloudmusic v2.4\\Project_List\\picture\\back.png", 30, 30);
    transparentimage(NULL, 15, 12, &back);

    while (1)//要用个循环来不断监测鼠标事件
    {
        if (MouseHit())
        {
            MOUSEMSG msg = GetMouseMsg();
            switch (msg.uMsg)
            {
            case WM_LBUTTONDOWN:
                if (msg.x >= 15 && msg.x <= 45 && msg.y <= 42 && msg.y >= 12)//返回
                {
                    closegraph();
                    menu();

                }//点击返回
                if (msg.x >= 114 && msg.x <= 584 && msg.y >= 805 && msg.y <= 853) {
                    WinExec("C:\\Program Files\\Internet Explorer\\IExplore.exe https://github.com/xiao-luo17", 1);
                }
            }
        }
    }
}