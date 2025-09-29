#include <stdio.h>

struct student{
    char name[50];
    int age;
};

int main() {
    struct student s[5];

    printf("Enter Student Information\n");
    for(int i = 0; i < 5; i++){
        printf("Student %d\n", i+1);

        printf("Enter name: ");
        scanf("%49s", s[i].name);

        printf("Enter age: ");
        scanf("%d", &s[i].age);
    }

    printf("\nStudent Records:\n");
    for(int i = 0; i < 5; i++){
        printf("Name: %s, Age: %d\n", s[i].name, s[i].age);
    }

    return 0;
}
