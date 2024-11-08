#include <stdio.h>
#include "sort.h"
#include "students.h"
#include "helpers.h"

char enterclass[50];

struct students studenti[] = {
    {13, "Artem", "Stanko", "px-23"},
    {5, "Pavel", "Durov", "px-22"},
    {2, "Aetem", "Stanok", "px-23"},
    {40, "Name", "Surname", "px-24"},
    {52, "Timur", "FamilijuNeznaju", "px-24"}
};

void save_to_file(struct students studenti[], int n) {
    FILE *fp = fopen("bd.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %s %s\n", studenti[i].age, studenti[i].name, studenti[i].sname, studenti[i].class);
    }
    
    fclose(fp);
}

int load_from_file(struct students studenti[]) {
    FILE *fp = fopen("bd.txt", "r");
    if (fp == NULL) {
        printf("File not found. Starting with an empty list.\n");
        return 0;
    }

    int i = 0;
    while (fscanf(fp, "%d %s %s %s", &studenti[i].age, studenti[i].name, studenti[i].sname, studenti[i].class) == 4) {
        i++;
    }
    
    fclose(fp);
    return i;
}

int compare_names(const char* name1, const char* name2) {
    int i = 0;

    while (name1[i] != '\0' && name2[i] != '\0') {
        if (name1[i] < name2[i]) {
            return -1;
        } else if (name1[i] > name2[i]) {
            return 1;
        }
        i++;
    }

    if (name1[i] == '\0' && name2[i] != '\0') {
        return -1;
    } else if (name1[i] != '\0' && name2[i] == '\0') {
        return 1;
    }

    return 0;
}

void strcopy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void out_clasic(int n){
    for (int i = 0; i < n; i++) {
    printf("- - - - - - - - \n");
    printf("Name: %s\nSurname: %s\nAge: %d\nClass: %s\n", 
    studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].class);   
    }
}

void out_class(int n){
    for (int i = 0; i < n; i++) {
        if(compare_names(studenti[i].class, enterclass) == 0){
            printf("- - - - - - - - \n");
            printf("Name: %s\nSurname: %s\nAge: %d\nClass: %s\n", 
            studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].class);   
        }
    }
}

void change(int n){
    int num;
    for (int i = 0; i < n; i++) {
        if(compare_names(studenti[i].class, enterclass) != 0){
            printf("-%d-%d-%d-%d-%d-%d-%d-%d\n",i,i,i,i,i,i,i,i);
            printf("Name: %s\nSurname: %s\nAge: %d\nClass: %s\n", 
            studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].class);   
        }
    }
    printf("Enter num:\n");
    scanf("%d", &num);
    int age;
    char name[50];
    char sname[50];
    char class[50];
    printf("\nName:\n");
    scanf("%s", name);
    printf("Suame:\n");
    scanf("%s", sname);
    printf("Class:\n");
    scanf("%s", class);
    printf("Age:\n");
    scanf("%d", &age);
    studenti[num].age = age;
    strcopy(studenti[num].name, name);
    strcopy(studenti[num].sname, sname);
    strcopy(studenti[num].class, class);
    
    printf("OK!\n");
    
}

void delite(int* n){
    int num;
    
    for (int i = 0; i < *n; i++) {
        if(compare_names(studenti[i].class, enterclass) != 0){
            printf("-%d-%d-%d-%d-%d-%d-%d-%d\n", i, i, i, i, i, i, i, i);
            printf("Name: %s\nSurname: %s\nAge: %d\nClass: %s\n", 
            studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].class);   
        }
    }
    
    printf("Enter num:\n");
    scanf("%d", &num);

    if (num >= 0 && num < *n) {
        for (int i = num; i < *n - 1; i++) {
            studenti[i] = studenti[i + 1];
        }
        (*n)--;
    } else {
        printf("Invalid!\n");
    }
}

void create_new(int* n){
    int age;
    char name[50];
    char sname[50];
    char class[50];
    printf("\nName:\n");
    scanf("%s", name);
    printf("Suame:\n");
    scanf("%s", sname);
    printf("Class:\n");
    scanf("%s", class);
    printf("Age:\n");
    scanf("%d", &age);
    studenti[*n].age = age;
    strcopy(studenti[*n].name, name);
    strcopy(studenti[*n].sname, sname);
    strcopy(studenti[*n].class, class);
    (*n)++;
    
    printf("OK!\n");
}

int main() {
    int n = load_from_file(studenti);  // Load data from file at the start

    for (;;) {
        int num;
        printf("\n\nSort Name:    1\nSort Sname:   2\nSort Age:     3\nSort Class:   4\nCreate New:   5\nChange:       6\nDelite:       7\nEXIT:         8\n");
        scanf("%d", &num);

        if (num == 1) {
            sort_by_name(studenti, n, 0);
        } else if (num == 2) {
            sort_by_sname(studenti, n, 0);
        } else if (num == 3) {
            sort_by_age(studenti, n, 0);
        } else if (num == 4) {
            sort_class(studenti, n);
        } else if (num == 5) {
            create_new(&n);
            save_to_file(studenti, n);
        } else if (num == 6) {
            change(n);
            save_to_file(studenti, n);
        } else if (num == 7){
            delite(&n);
            save_to_file(studenti, n);
        } else if (num == 8) {
            save_to_file(studenti, n);
            return 0;
        }
    }

    return 0;
}