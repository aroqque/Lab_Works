#include "foo.h"


table* create_list_by_hand()
{
	table* ptr, * head, * previous;

	head = previous = ptr = new table;
	int N = 0;

	cout << "������� ��� ����������, ����� ��� ��������, ������������� � ����� � ������\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;

	char c = 'y';

	while (N < 20 && c == 'y')
	{
		ptr = new table;

		if (head == nullptr)
			head = ptr; // ���� ��� ��������� � ������, �� ������ ������� ���������� ������
		else
			previous->next = ptr; // ���������� ��������� �� �������

		previous = ptr; // ���������� ���������� �������

		cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;

		cout << "��������� ���?(y/other key)\n";
		c = _getch();
		++N;
	}
	previous->next = nullptr; //����� ������
	return head;
}

table* create_list_random() {
	table* ptr, * head, * previous;

	head = previous = ptr = new table;

	int N;
	cout << "������� ���-��: ";
	cin >> N;
	string symbol[3] = { "12","17","12a" };
	string names[3] = { "��", "�-�", "�" };
	string sign[3] = { "27.55","13.6","57.3" };
	string kilom[3] = { "75","57","117" };


	strcpy_s(ptr->name, names[rand() % 3].c_str());
	strcpy_s(ptr->cnt, sign[rand() % 3].c_str());
	strcpy_s(ptr->type, symbol[rand() % 3].c_str());
	strcpy_s(ptr->sq, kilom[rand() % 3].c_str());
	--N;

	for (int i = 0; i < N; i++)
	{
		ptr = new table; // �������� ������ ��� ��������� �������
		if (head == nullptr)
			head = ptr; // ���� ��� ��������� � ������, �� ������ ������� ���������� ������
		else
			previous->next = ptr; // ���������� ��������� �� �������

		previous = ptr; // ���������� ��������� ���������� �������


		strcpy_s(ptr->name, names[rand() % 3].c_str());
		strcpy_s(ptr->cnt, sign[rand() % 3].c_str());
		strcpy_s(ptr->type, symbol[rand() % 3].c_str());
		strcpy_s(ptr->sq, kilom[rand() % 3].c_str());
	}
	previous->next = nullptr;
	return head;
}


void print_list(table* head) {
	table* ptr = head;
	while (ptr != nullptr)
	{
		printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	cout << "\n";
}
table* search_by_name(table* head, char* name) {
	table* ptr = head;
	while (ptr)
	{
		if (strcmp(ptr->name, name) == 0)
			printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}
table* search_by_type(table* head, char* type) {
	table* ptr = head;
	while (ptr)
	{
		if (strcmp(ptr->type, type) ==0)
			printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}
table* search_by_cnt(table* head, char* count) {
	table* ptr = head;
	while (ptr) {
		if (strcmp(ptr->cnt, count) == 0)
			printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}
table* search_by_sq(table* head, char* sq) {
	table* ptr = head;
	while (ptr) {
		if (strcmp(ptr->sq, sq) == 0)
			printf("\n[ %-10s   %-10s   %-13s   %-12s ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}

void add_to_begin(table** head) {
	table* ptr = new table;
	cout << "\n������� ��� ���������� � ���������:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	ptr->next = *head; // ������ ������� ���������� ������
	*head = ptr; // ������ ������� ���������� ������
}
void add_to_end(table* head) {
	table* ptr = head;
	table* previous = nullptr;

	while (ptr)
	{
		previous = ptr;
		ptr = ptr->next;
	}
	ptr = new table;
	cout << "\n������� ��� ���������� � ���������:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	previous->next = ptr; // ���������� ��������� �� �������
	ptr->next = nullptr; // ����� ������
}

void add_after_element(table* head)
{
	table* ptr = head;
	table* previous = head;
	char name[12];
	cout << "\n������� ��� ����������: ";
	cin >> name;
	while (ptr)
	{
		if (strcmp(previous->name, name) == 0)
		{
			ptr = new table;
			ptr->next = previous->next; // ���������� ��������� �� �������
			previous->next = ptr; // ���������� ���������� �������
			cout << "\n������� ��� ���������� � ���������:\n";
			cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
			break;
		}

		previous = ptr; // ���������� ���������� �������
		ptr = ptr->next; // ������� ���������� ���������

	}
}

void delete_first(table** head) {
	table* ptr = *head;
	*head = ptr->next;
	delete ptr;
}
void delete_last(table** head) {
	table* ptr = *head;
	table* previous = nullptr;
	while (ptr->next) {
		previous = ptr;
		ptr = ptr->next;
	}
	if (previous == nullptr) {
		delete_first(head);
		return;
	}
	previous->next = nullptr;
	delete ptr;
}
void delete_element(table** head) {
	table* ptr = *head;
	table* previous = nullptr;
	char name[11];
	cout << "\n������� ��� ����������: ";
	cin >> name;
	if (strcmp(ptr->name, name) == 0) {
		delete_first(head);
		system("cls");
		return;
	}
	while (ptr) {
		if (strcmp(ptr->name, name) == 0) {
			previous->next = ptr->next;
			delete ptr;
			system("cls");
			return;
		}
		else {
			previous = ptr;
			ptr = ptr->next;
		}
	}
}

void sort(table* head) {
	table* left = head;
	table* right = head->next;
	while (left->next) { // ���� �� ����� �� ����� ������
		while (right) {
			if ((strcmp(left->name, right->name) > 0)) { // ���� ����� ������ ������� �� ��������
				swap(left->name, right->name);
				swap(left->type, right->type);
				swap(left->cnt, right->cnt);
				swap(left->sq, right->sq);
			}
			right = right->next; // ��������� � ���������� ��������
		}
		left = left->next; // ��������� � ���������� ��������
		right = left->next; // ��������� � ���������� ��������
	}
}

void input_in_file(table* head) {
	table* ptr = head;

	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "wt");

	while (ptr)
	{
		fprintf(f, "\n %-10s   %-10s   %-13s   %-12s", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	fclose(f);
}

table* read_from_file() {
	table* ptr, * head, * previous;
	ptr = head = previous = new table;
	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "rt");

	fscanf(f, " %s %s %s %s", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
	while (!feof(f)) {
		ptr = new table;
		fscanf(f, " %s %s %s %s", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
		previous->next = ptr;
		previous = ptr;
	}
	ptr->next = nullptr;
	cout << "���������" << endl;
	fclose(f);
	return head;

}
