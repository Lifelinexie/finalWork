#include "head.h"
#include "back.h"
int help()
{

	printf("��������Ϸ˵��:\n\n");
	printf("����������Ϸ��Ҫ��Ϊ˫�˵���ͨ��\n\n");
	printf("��ͨ��:ʤ�߿��Ի��һ������,�ﵽһ��������������\n");
	printf("��λ��:ҵ��һ�Σ�ҵ�����...��߾Ŷ�.\n\n");
	color(4);
	printf("����ע��:��������������壬����޷�Ӧ����������Ե��ɫ�����Ҽ����\n");
	printf("ѡ������->ѡ��->����ѡ��->ѡ�в���ģʽ��ȡ�����ٱ༭ģʽ.\n");
	printf("����ʱ����������ˣ����������г���.\n\n");
	color(16);
	printf("����ע��ע��:\n");
	printf("�����û���ʱ��Ҫ�������ģ���Ϊ���ļ�����ʱfopen������txt������utf-8\n"\
			"�Ķ�c����ascII��ȡ,�ᵼ�������������\n\n");
	printf("��������ļ���ʧ�ܣ��������Ȩ�޲������������ĵ��Է���û��d��\n");
	printf("��Ϸ���������ݵľ���·��Ϊ:d:\JSGame\data��鿴�Ƿ���ڸ��ļ���\n");
	printf("�������û��������ļ��ģ������봴���û���ʱ���������.\n\n");
	printf("���������forѭ���������벻ͨ����������ı������汾������c99��׼��֮��\n\n");
	printf("����δע����û���ѡ��ע�ᣬ�����Ѿ�ע����û���ѡ���¼\n");
	printf("��������Ϸ���������κ�BUG����Ϸ��������ϵ���������ң�ʮ�ָ�л��.\n\n");
	printf("��B/b���س���ʼ����\n");
	
	if(back())
	{
		return 1;
	}
}