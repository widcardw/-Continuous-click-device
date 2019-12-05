#include <stdio.h>
#include <windows.h>
#define VK_Q 0x51
#define VK_W 0x57
#define VK_E 0x45
#define VK_R 0x52
#define VK_T 0x54
void reminder();
int main()
{
	reminder();
	int pause_time = 50;
	while (1)
	{
		if (GetAsyncKeyState(VK_R))
		{
			printf("请输入点击间隔时间，单位为毫秒，同时删除多余的字母\n");
			scanf("%d", &pause_time);
		}
		if (GetAsyncKeyState(VK_W))
		{
			printf("连点已开始，当前连点间隔：%dms\n", pause_time);
			while (1)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(pause_time);
				if (GetAsyncKeyState(VK_E))
				{
					printf("连点已结束\n");
					break;
				}
			}
		}
		if (GetAsyncKeyState(VK_Q))
			break;
		if (GetAsyncKeyState(VK_T))
		{
			system("cls");
			reminder();
		}
	}
	return 0;
}
void reminder()
{
	printf("低配版连点器\nW:开始\nE:停止\nR:设置点击间隔\nQ:退出\nT:清屏\n");
}
