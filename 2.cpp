// '+' - добавить элемент
// '-' - удалить элемент
// 'f' - найти элемент
// '+' , 'print' - вывести очередь на экран

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <malloc.h>
#include <string.h>

struct node
{
	char inf[256];  // полезная информация
	struct node* next;  // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL;  // указатели на первый и последний элементы списка

/* Функция просмотра всей очереди */
int review(struct node** head) {
	struct node* gg = *head;
	if (gg == NULL) {
		printf("Очередь пуста!\n");
		return 0;
	}
	printf("\n");
	while (gg) {
		printf("%s\n", gg->inf);
		gg = gg->next;
	}
	printf("\n");
	return 0;
}

/* Функция создания элемента очереди */
struct node* get_struct()
{
	struct node* p = NULL;
	p = (node*)malloc(sizeof(struct node));

	char s[256];
	printf("Введите название объекта: ");  // вводим данные
	scanf("%s", &s);
	if (*s == 0) {
		printf("Запись не была произведена!\n");
		return 0;
	}

	if (strcmp("print", s) == 0) {
		review(&head);
		return 0;
	}

	if (p != NULL) {
		strcpy(p->inf, s);  // устанавливаем данные в выделенном узле и возвращаем их
		p->next = NULL;
		return p;
	}
	else {
		printf("\nHeap Overflow");
		exit(1);
	}
}

/* Функция добавления элемента в очередь (в конец) */
void spstore()
{
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL)  // если списка нет, то устанавливаем голову списка
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL)  // если список уже есть, то вставляем в конец
	{
		last->next = p;
		last = p;
	}
	return;
}

/* Функция поиска элемента очереди */
struct node* find()
{
	struct node* struc = head;
	if (head == NULL)
	{
		printf("Очередь пуста!\n");
		return 0;
	}

	char name[20];
	printf("Введите название элемента для поиска: ");
	scanf("%s", &name);

	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			printf("Элемент найден)\n");
			return 0;
		}
		struc = struc->next;
	}
	printf("Элемент не найден(\n");
	return 0;
}

/* Функция удаления элемента очереди (первого) */
void end() {
	if (head == NULL)
	{
		printf("Очередь пуста!\n");
		exit(1);
	}

	struct node* tmp = head;  // принять к сведению данные верхнего узла
	printf("Верхний удаляемый элемент: %s\n", head->inf);
	head = head->next;  // обновляем верхний указатель, чтобы он указывал на следующий узел

	if (head == NULL) {  // если список стал пустым
		last = NULL;
	}
	free(tmp);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true) {
		int i = _getch();
		switch (i) {
		case '+':
			spstore();
			break;
		case '-':
			end();
			break;
		case 'f':
			find();
			break;
		default:
			break;
		}
	}
	return 0;
}