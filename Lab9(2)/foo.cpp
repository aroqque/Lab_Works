#include "foo.h"

extern struct table* head, * tail;

void create_list_by_hand()
{
	table* ptr, * previous;

	previous = nullptr;
	do {
		ptr = new table;
		cout << "Введите вид транспорта, номер его маршрута, протяженность и время в дороге\n";
		cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;

		ptr->prev = previous;
		if (previous != nullptr)
			previous->next = ptr;
		else
			head = ptr;
		previous = ptr;
		puts(" Чтобы выйти - 'esc'");
	} while (_getch() != 27);

	tail = ptr;
	tail->next = nullptr;
}
void create_list_by_random() {
	table* ptr, * previous;

	head = previous = ptr = new table;
	previous = nullptr;

	int N;
	cout << "Введите кол-во: ";
	cin >> N;
	string symbol[3] = { "12","17","12a" };
	string names[3] = { "Тр", "Т-с", "А" };
	string sign[3] = { "27.55","13.6","57.3" };
	string kilom[3] = { "75","57","117" };

	for (int i = 0; i < N; i++)
	{
		ptr = new table;

		strcpy_s(ptr->name, names[rand() % 3].c_str());
		strcpy_s(ptr->cnt, sign[rand() % 3].c_str());
		strcpy_s(ptr->type, symbol[rand() % 3].c_str());
		strcpy_s(ptr->sq, kilom[rand() % 3].c_str());

		ptr->prev = previous;
		if (previous != nullptr)
			previous->next = ptr;
		else
			head = ptr;
		previous = ptr;
	}
	tail = ptr;
	tail->next = nullptr;

}
void print_list_begin(table* head) {
	table* ptr = head;
	while (ptr != nullptr)
	{
		printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	cout << "\n";
}
void print_list_end(table* tail) {
	table* ptr = tail;
	while (ptr != nullptr)
	{
		printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->prev;
	}
	cout << "\n";
}
void search_by_name(table* p, char* name) {
	table* ptr = p;
	if (ptr == head)
	{
		while (ptr)
		{
			if (strcmp(ptr->name, name) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (strcmp(ptr->name, name) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void search_by_type(table* p, char* type) {
	table* ptr = p;
	if (ptr == head)
	{
		while (ptr)
		{
			if (strcmp(ptr->type, type) ==0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (strcmp(ptr->type, type) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void search_by_cnt(table* p, char* count) {
	table* ptr = p;
	if (ptr == head) {
		while (ptr)
		{
			if (strcmp(ptr->cnt, count) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (strcmp(ptr->cnt, count) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void search_by_sq(table* p, char* sq) {
	table* ptr = p;
	if (ptr == head)
	{
		while (ptr)
		{
			if (strcmp(ptr->sq, sq) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr) {
			if (strcmp(ptr->sq, sq) == 0)
				printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void add_to_begin() {
	table* ptr = new table;
	cout << "\nВведите вид транспорта и остальное:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	ptr->prev = nullptr; // предыдущий указывает на nullptr
	ptr->next = head;// первый элемент становится вторым
	head->prev = ptr; // предыдущий указывает на íîâűé óçĺë
	head = ptr; // первый элемент становится первым



}
void add_to_end() {
	table* ptr = head;
	table* previous = nullptr;

	while (ptr)
	{
		previous = ptr;
		ptr = ptr->next;
	}
	ptr = new table;
	cout << "\nВведите вид транспорта и остальное:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	previous->next = ptr; // предыдущий указывает на текущий
	ptr->prev = previous; // текущий указывает на предыдущий
	ptr->next = nullptr; // конец списка
	tail = ptr;
}
void add_after_element()
{
	table* ptr = head;
	table* previous = head;
	char name[12];
	cout << "\nВведите вид транспорта: ";
	cin >> name;
	while (ptr)
	{
		if (strcmp(previous->name, name) == 0)
		{
			ptr = new table;
			ptr->next = previous->next; // предыдущий указывает на текущий
			previous->next->prev = ptr; // текущий указывает на предыдущий
			ptr->prev = previous; // предыдущий указывает на íîâűé óçĺë
			previous->next = ptr; // предыдущий становится текущим
			cout << "\nВведите вид транспорта и остальное:\n";
			cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
			break;
		}

		previous = ptr; // предыдущий становится текущим
		ptr = ptr->next; // текущий становится следующим

	}
}
void delete_first() {
	table* ptr = head;
	head = ptr->next;
	head->prev = NULL;
	free(ptr);
	ptr = head;
}
void delete_last() {
	table* ptr = head;
	table* previous = nullptr;
	while (ptr->next) {
		previous = ptr;
		ptr = ptr->next;
	}
	if (previous == nullptr) {
		delete_first();
		return;
	}
	previous->next = nullptr;
	tail = previous;
	free(ptr);

}
void delete_such_element() {
	table* ptr = head;
	table* previous = nullptr;
	char name[11];
	cout << "\nВведите вид транспорта: ";
	cin >> name;
	if (strcmp(ptr->name, name) == 0) {
		delete_first();
		system("cls");
		return;
	}
	while (ptr) {
		if (strcmp(ptr->name, name) == 0) {
			if (ptr->next == nullptr) {
				previous->next = nullptr;
				tail = previous;
				free(ptr);
				system("cls");
				return;
			}
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			free(ptr);
			system("cls");
			return;
		}
		else {
			previous = ptr;
			ptr = ptr->next;
		}
	}
}
void sort() {
	table* left = head;
	table* right = head->next;
	while (left->next) { // пока не дошли до конца списка
		while (right) {
			if ((strcmp(left->name, right->name) > 0)) { // если левый больше правого по алфавиту
				swap(left->name, right->name);
				swap(left->type, right->type);
				swap(left->cnt, right->cnt);
				swap(left->sq, right->sq);
			}
			right = right->next; // переходим к следующему элементу
		}
		left = left->next; // переходим к следующему элементу
		right = left->next; // переходим к следующему элементу
	}
}
void input_in_file() {
	table* ptr = head;

	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "wt");

	while (ptr)
	{
		fprintf(f, "\n %-10s   %-10s  %-13s   %-12s", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	fclose(f);
}
void read_from_file() {
	table* ptr, * previous;
	ptr = head = previous = new table;
	head->prev = nullptr;
	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "rt");

	fscanf(f, " %s %s %s %s", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
	while (!feof(f)) {
		ptr = new table;
		fscanf(f, " %s %s %s %s", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
		previous->next = ptr;
		ptr->prev = previous;
		previous = ptr;
	}
	ptr->next = nullptr;
	tail = ptr;
	cout << "Выполнено" << endl;
	fclose(f);

}