#include "sortedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool test_empty_list() {
  Node *head = NULL;
  add_sorted(&head, 5);
  bool result = (head != NULL && head->value == 5 && head->next == NULL);
  free_list(head);
  return result;
}

bool test_insert_beginning() {
  Node *head = NULL;
  add_sorted(&head, 10);
  add_sorted(&head, 5);
  bool result = (head != NULL && head->value == 5 && head->next != NULL &&
                 head->next->value == 10);
  free_list(head);
  return result;
}

bool test_insert_end() {
  Node *head = NULL;
  add_sorted(&head, 5);
  add_sorted(&head, 10);
  bool result = (head != NULL && head->value == 5 && head->next != NULL &&
                 head->next->value == 10);
  free_list(head);
  return result;
}

bool test_insert_middle() {
  Node *head = NULL;
  add_sorted(&head, 5);
  add_sorted(&head, 15);
  add_sorted(&head, 10);

  bool result = (head != NULL && head->value == 5 && head->next != NULL &&
                 head->next->value == 10 && head->next->next != NULL &&
                 head->next->next->value == 15);
  free_list(head);
  return result;
}

bool test_delete_beginning() {
  Node *head = NULL;
  add_sorted(&head, 5);
  add_sorted(&head, 10);
  delete_value(&head, 5);
  bool result = (head != NULL && head->value == 10 && head->next == NULL);
  free_list(head);
  return result;
}

bool test_delete_end() {
  Node *head = NULL;
  add_sorted(&head, 5);
  add_sorted(&head, 10);
  delete_value(&head, 10);
  bool result = (head != NULL && head->value == 5 && head->next == NULL);
  free_list(head);
  return result;
}

bool test_sorted_property() {
  Node *head = NULL;
  add_sorted(&head, 3);
  add_sorted(&head, 1);
  add_sorted(&head, 2);

  bool sorted = true;
  Node *cur = head;
  while (cur != NULL && cur->next != NULL) {
    if (cur->value > cur->next->value) {
      sorted = false;
      break;
    }
    cur = cur->next;
  }

  bool result = sorted && (head->value == 1 && head->next->value == 2 &&
                           head->next->next->value == 3);
  free_list(head);
  return result;
}

void run_tests() {
  printf("=== ТЕСТИРОВАНИЕ СОРТИРОВАННОГО СПИСКА ===\n\n");

  struct {
    const char *name;
    bool (*test_func)();
  } tests[] = {
      {"Добавление в пустой список", test_empty_list},
      {"Добавление в начало", test_insert_beginning},
      {"Добавление в конец", test_insert_end},
      {"Добавление в середину", test_insert_middle},
      {"Удаление из начала", test_delete_beginning},
      {"Удаление из конца", test_delete_end},
      {"Сохранение сортированности", test_sorted_property},
  };

  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    printf("Тест %d: %s... ", i + 1, tests[i].name);
    bool result = tests[i].test_func();

    if (result) {
      printf("ПРОЙДЕН\n");
      passed++;
    } else {
      printf("НЕ ПРОЙДЕН\n");
    }
  }

  printf("\nРезультат: %d/%d тестов пройдено\n", passed, total);

  if (passed == total) {
    printf("Все тесты успешно пройдены!\n");
  } else {
    printf("Некоторые тесты не пройдены!\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2 && strcmp(argv[1], "--test") == 0) {
    run_tests();
    return 0;
  }

  printf("Используйте --test для запуска тестов\n");
  return 0;
}
