#include <iostream>
#include <time.h>
#include <windows.h>
#include <queue>

using namespace std;

struct pri_queue
{
	int num;
	int priority;
	pri_queue* next = nullptr;
};

void insert(pri_queue*& main, pri_queue* new_el) {
	pri_queue* tmp = main;
	pri_queue* left = main;

	while (tmp != nullptr && new_el->priority < tmp->priority)
	{
		left = tmp;
		tmp = tmp->next;
	}

	if (tmp != left) {
		left->next = new_el;
	}
	else main = new_el;
	new_el->next = tmp;

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int count;
	cout << "Введите число элементов: ";
	cin >> count;

	if (count <= 1) count = 2;

	pri_queue* head = nullptr;

	while (count) {

		pri_queue* tmp = new pri_queue;
		cout << "\nВведите данные: ";
		cin >> tmp->num;
		cout << "Введите приоритет: ";
		cin >> tmp->priority;
		insert(head, tmp);
		count--;
	}

	pri_queue* tmp = head;

	while (tmp != nullptr) {
		cout << tmp->num << endl;
		tmp = tmp->next;
	}
	return 0;
}