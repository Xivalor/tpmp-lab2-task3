#include <stdio.h>
#include "../include/note_module.h"

#define MAX_NOTES 9

int main() {
    NOTE1 block[MAX_NOTES];
    int month;

    printf("Программа NOTE1\n");
    input_notes(block, MAX_NOTES);
    sort_notes(block, MAX_NOTES);
    print_all_notes(block, MAX_NOTES, "Отсортированный список:");
    
    printf("\nВведите месяц для поиска: ");
    scanf("%d", &month);
    
    if (month >= 1 && month <= 12) {
        search_and_print_by_month(block, MAX_NOTES, month);
    } else {
        printf("Ошибка: месяц от 1 до 12\n");
    }
    
    return 0;
}
