#include <stdio.h>
#include <stdlib.h>

// Структура узла списка
typedef struct Node {
  int value;
  struct Node *next;
} Node;

// Вставка в сортированный список
void add_sorted(Node **head, int val) {
  Node *newNode = malloc(sizeof(Node));
  if (!newNode) {
    printf("Ошибка: не удалось выделить память.\n");
    return;
  }
  newNode->value = val;
  newNode->next = NULL;

  // если список пуст или вставка в начало
  if (*head == NULL || val < (*head)->value) {
    newNode->next = *head;
    *head = newNode;
    return;
  }

  // поиск места для вставки
  Node *cur = *head;
  while (cur->next != NULL && cur->next->value < val)
    cur = cur->next;

  newNode->next = cur->next;
  cur->next = newNode;
}

// Удаление элемента из списка
void delete_value(Node **head, int val) {
  if (*head == NULL) {
    printf("Список пуст.\n");
    return;
  }

  Node *cur = *head, *prev = NULL;

  while (cur != NULL && cur->value != val) {
    prev = cur;
    cur = cur->next;
  }

  if (cur == NULL) {
    printf("Элемент %d не найден.\n", val);
    return;
  }

  if (prev == NULL) // удаляем первый элемент
    *head = cur->next;
  else
    prev->next = cur->next;

  free(cur);
  printf("Элемент %d удалён.\n", val);
}

// Печать списка
void print_list(Node *head) {
  if (!head) {
    printf("Список пуст.\n");
    return;
  }
  printf("Список: ");
  for (Node *cur = head; cur != NULL; cur = cur->next)
    printf("%d ", cur->value);
  printf("\n");
}

// Очистка списка перед выходом
void free_list(Node *head) {
  while (head) {
    Node *tmp = head;
    head = head->next;
    free(tmp);
  }
}

int main(void) {
  Node *head = NULL;
  int cmd, val;

  printf("Программа работы с сортированным списком\n");
  printf("---------------------------------------\n");

  do {
    printf("\nМеню:\n");
    printf("0 – выйти\n");
    printf("1 – добавить значение\n");
    printf("2 – удалить значение\n");
    printf("3 – распечатать список\n");
    printf("Ваш выбор: ");
    if (scanf("%d", &cmd) != 1) {
      printf("Некорректный ввод.\n");
      break;
    }

    switch (cmd) {
    case 1:
      printf("Введите число для добавления: ");
      if (scanf("%d", &val) == 1)
        add_sorted(&head, val);
      else
        printf("Ошибка ввода.\n");
      break;
    case 2:
      printf("Введите число для удаления: ");
      if (scanf("%d", &val) == 1)
        delete_value(&head, val);
      else
        printf("Ошибка ввода.\n");
      break;
    case 3:
      print_list(head);
      break;
    case 0:
      printf("Выход...\n");
      break;
    default:
      printf("Неизвестная команда.\n");
    }
  } while (cmd != 0);

  free_list(head);
  return 0;
}