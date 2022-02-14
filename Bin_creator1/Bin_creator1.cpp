#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void main()
{
	int key = 1;
	char filename_1[10] = "test1.rar";
	char filename_2[10] = "test2.bin";
	int a;

	FILE* f1, * f2;

	f1 = fopen(filename_1, "rb"); // поток_1 для чтения файла_1
	f2 = fopen(filename_2, "wb"); // поток_2 для записи в файл_2

	fseek(f1, 0, SEEK_END);
	long fSize = ftell(f1); // определяем размер файла_1 в байтах
	fseek(f1, 0, SEEK_SET); // возвращаем указатель в начало

	fread(&a, sizeof(int), 1, f1); // читаем из файла_1
	fwrite(&a, sizeof(int), 1, f2); // записываем в файл_2

	for (int i = 1; i < fSize / 4 + 1; i++) // цикл перезаписи
	{
		if (i % 16 == 0)
		{
			fwrite(&key, sizeof(int), 1, f2);
		}
		fread(&a, sizeof(int), 1, f1); // читаем из файла_1
		fwrite(&a, sizeof(int), 1, f2); // записываем в файл_2
	}

	fclose(f1);
	fclose(f2);

	system("pause");
}
