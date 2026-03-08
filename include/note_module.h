#ifndef NOTE_MODULE_H
#define NOTE_MODULE_H

typedef struct {
    char Name[50];
    char TELE[20];
    struct {
        int year;
        int month;
        int day;
    } DATE;
} NOTE1;

void input_notes(NOTE1 *block, int count);
void sort_notes(NOTE1 *block, int count);
void search_and_print_by_month(NOTE1 *block, int count, int month);
void print_all_notes(NOTE1 *block, int count, const char *title);

#endif
