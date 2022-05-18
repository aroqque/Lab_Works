#include "foo.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[] = "file.txt";
	table* head = nullptr;
	while (1) {
		int a;
		cout << "1. Создать список по ручному вводу\n2. Создать список по случайному вводу\n3. Вывести список\n4. Поиск по названию\n5. Добавить в список\n6. Удаление\n7. Сортировка\n8. Запись в файл\n9. Создание нового списка из файла\n10.Выход\n";
		cin >> a;
		switch (a) {
		case 1:
			head = create_list_by_hand();
			system("cls");
			break;

		case 2:
			head = create_list_by_random();
			system("cls");
			break;

		case 3:
			if (head == NULL) {
				printf("%s\n", "Список пуст");
				system("pause");
				system("cls");
				break;
			}
			print_list(head);
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << "Выбор по критерию\n 1 - Вид транспорта\n 2 - Номер маршрута\n 3 - Протяженность\n 4 - Время в дороге\n > ";
			int b;
			cin >> b;
			switch (b) {
			case 1:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				cout << "Введите вид транспорта: ";
				char name[20];
				cin >> name;
				search_by_name(head, name);
				cout << "\n";
				system("pause");
				system("cls");
				break;

			case 2:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				cout << "Введите номер маршрута: ";
				char type[20];
				cin >> type;
				search_by_type(head, type);
				cout << "\n";
				system("pause");
				system("cls");
				break;

			case 3:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				cout << "Введите протяженность маршрута: ";
				char cnt[20];
				cin >> cnt;
				search_by_cnt(head, cnt);
				cout << "\n";
				system("pause");
				system("cls");
				break;

			case 4:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				cout << "Введите время в дороге: ";
				char sq[20];
				cin >> sq;
				search_by_sq(head, sq);
				cout << "\n";
				system("pause");
				system("cls");
				break;
			}
			break;
		case 5:
			system("cls");
			cout << " 1 - Добавить в начало\n 2 - Добавить в конец\n 3 - Добавить после заданного элемента\n > ";
			int c;
			cin >> c;
			switch (c) {

			case 1:
				add_to_begin(&head);
				system("pause");
				system("cls");
				break;
			case 2:
				add_to_end(head);
				system("pause");
				system("cls");
				break;
			case 3:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				add_after_element(head);
				system("pause");
				system("cls");
				break;
			}
			break;
		case 6:
			system("cls");
			cout << " 1 - Удалить первый элемент\n 2 - Удалить последний элемент\n 3 - Удалить заданный элемент\n > ";
			int d;
			cin >> d;
			switch (d) {
			case 1:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				delete_first(&head);
				system("pause");
				system("cls");
				break;
			case 2:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				delete_last(&head);
				system("pause");
				system("cls");
				break;
			case 3:
				if (head == NULL) {
					printf("%s\n", "Список пуст");
					system("pause");
					system("cls");
					break;
				}
				delete_such_element(&head);
				system("pause");
				system("cls");
				break;
			}
			break;
		case 7:
			if (head == NULL) {
				printf("%s\n", "Список пуст");
				system("pause");
				system("cls");
				break;
			}
			sort(head);
			system("pause");
			system("cls");
			break;
		case 8:
			if (head == NULL) {
				printf("%s\n", "Список пуст");
				system("pause");
				system("cls");
				break;
			}
			input_in_file(head);
			system("pause");
			system("cls");
			break;

		case 9:

			head = read_from_file();

			system("pause");
			system("cls");
			break;

		case 10:
			exit(0);

		}
	}
}
