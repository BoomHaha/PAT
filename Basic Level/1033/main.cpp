/*
1.ע���ַ�ѭ������ķ���  char c; while((c=getchar())!='\n')
                                �� while ((c=cin.get())!='\n')
2.��������˼�룺��������ĸ��ascii��Ϊ�±�������ʾ
*/
#include <cstdio>
#include <cctype>
#include <memory.h>
int main()
{
	bool list[128];
	memset(list,true,sizeof(list));
	char input;
	short bad_key;
	while ((bad_key=getchar())!='\n') {
		list[bad_key]=0;
		list[tolower(bad_key)]=0;
	}
	if (list['+']==0)
		for (short i='A';i<='Z';i++) list[i]=0;
	while ((input=getchar())!='\n') {
		if (list[input]) printf("%c",input);
	}
	printf("\n");
	return 0;
}
