#include "sort.h"
#include "helpers.h"
#include <stdio.h>

void sort_by_name(struct students studenti[], int n, int ic) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare_names(studenti[j].name, studenti[j + 1].name) > 0) {
                struct students temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }
    if (ic == 1){
        out_class(n);
    }else{
        out_clasic(n);
    }
}

void sort_by_sname(struct students studenti[], int n, int ic) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare_names(studenti[j].sname, studenti[j + 1].sname) > 0) {
                struct students temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }
    
    if (ic == 1){
        out_class(n);
    }
    else{
        out_clasic(n);
    }
    
}

void sort_by_age(struct students studenti[], int n, int ic) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (studenti[j].age > studenti[j + 1].age) {
                struct students temp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = temp;
            }
        }
    }
    
    if (ic == 1){
        out_class(n);
    }else{
        out_clasic(n);
    }
}

void sort_class(struct students studenti[], int n) {
    int class_info = 1;
    printf("Enter class: ");
    scanf("%s", enterclass);
    printf("%s", enterclass);
    int num;
    printf("\nSort Name: 1\nSort Sname: 2\nSort Age: 3\n");
    scanf("%d", &num);

    if (num == 1) {
        sort_by_name(studenti, n, class_info);
    } else if (num == 2) {
        sort_by_sname(studenti, n, class_info);
    } else if (num == 3) {
        sort_by_age(studenti, n, class_info);
    }
}