#include "../include/note_module.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int compare_by_name(const void *a, const void *b) {
    const NOTE1 *note_a = (const NOTE1 *)a;
    const NOTE1 *note_b = (const NOTE1 *)b;
    return strcmp(note_a->Name, note_b->Name);
}

void input_notes(NOTE1 *block, int count) {
    printf("Введите информацию о %d людях:\n", count);
    for (int i = 0; i < count; i++) {
        printf("\n--- Запись %d ---\n", i + 1);
        
        printf("Введите фамилию и инициалы: ");
        fgets(block[i].Name, sizeof(block[i].Name), stdin);
        size_t len = strlen(block[i].Name);
        if (len > 0 && block[i].Name[len-1] == '\n') {
            block[i].Name[len-1] = '\0';
        }
        
        printf("Введите номер телефона: ");
        fgets(block[i].TELE, sizeof(block[i].TELE), stdin);
        len = strlen(block[i].TELE);
        if (len > 0 && block[i].TELE[len-1] == '\n') {
            block[i].TELE[len-1] = '\0';
        }
        
        printf("Введите дату рождения (год месяц число): ");
        scanf("%d %d %d", &block[i].DATE.year, &block[i].DATE.month, &block[i].DATE.day);
        getchar();
    }
}

void sort_notes(NOTE1 *block, int count) {
    qsort(block, count, sizeof(NOTE1), compare_by_name);
}

void print_all_notes(NOTE1 *block, int count, const char *title) {
    printf("\n%s\n", title);
    for (int i = 0; i < count; i++) {
        printf("%s | %s | %04d.%02d.%02d\n",
               block[i].Name,
               block[i].TELE,
               block[i].DATE.year,
               block[i].DATE.month,
               block[i].DATE.day);
    }
}

void search_and_print_by_month(NOTE1 *block, int count, int month) {
    int found = 0;
    printf("\nЛюди, родившиеся в месяце %d:\n", month);
    for (int i = 0; i < count; i++) {
        if (block[i].DATE.month == month) {
            printf("%s | %s | %04d.%02d.%02d\n",
                   block[i].Name,
                   block[i].TELE,
                   block[i].DATE.year,
                   block[i].DATE.month,
                   block[i].DATE.day);
            found = 1;
        }
    }
    if (!found) {
        printf("Нет людей с днем рождения в месяце %d\n", month);
    }
}
