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
			printf("�����������ʱ�䣬��λΪ���룬ͬʱɾ���������ĸ\n");
			scanf("%d", &pause_time);
		}
		if (GetAsyncKeyState(VK_W))
		{
			printf("�����ѿ�ʼ����ǰ��������%d\n", pause_time);
			while (1)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(pause_time);
				if (GetAsyncKeyState(VK_E))
				{
					printf("�����ѽ���\n");
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
	printf("�����������\nĬ�ϵ�����Ϊ50ms\nW:��ʼ\nE:ֹͣ\nR:���õ�����\nQ:�˳�\nT:����\n");
}