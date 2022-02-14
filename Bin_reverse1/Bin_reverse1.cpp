#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void main()
{
	char key[5] = "1234";
	char filename_1[10] = "test2.bin";
	char filename_2[10] = "test1.rar";
	int a;
	int count = 0;
	bool isChecked = false;

	FILE* f1, * f2;

	f1 = fopen(filename_1, "rb"); // поток_1 для чтения файла_1
	f2 = fopen(filename_2, "wb"); // поток_2 для записи в файл_2

	fseek(f1, 0, SEEK_END);
	long fSize = ftell(f1); // определяем размер файла_1 в байтах
	fseek(f1, 0, SEEK_SET); // возвращаем указатель в начало

	fread(&a, sizeof(int), 1, f1); // читаем из файла_1
	fwrite(&a, sizeof(int), 1, f2); // записываем в файл_2

	for (int i = 1; i < fSize / 4; i++) // цикл перезаписи
	{
		fread(&a, sizeof(int), 1, f1); // читаем из файла_1
		if ((i-count) % 16 == 0  && isChecked == false)
		{
			count++;
			isChecked = true;
			continue;
		}
		fwrite(&a, sizeof(int), 1, f2); // записываем в файл_2
		isChecked = false;
	}

	fclose(f1);
	fclose(f2);

	system("pause");
}
