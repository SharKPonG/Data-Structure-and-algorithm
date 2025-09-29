#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    int count = 1, c = 0;

    printf("Enter Sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // ลบ newline ที่ fgets อ่านมา
    sentence[strcspn(sentence, "\n")] = '\0';

    while (sentence[c] != '\0') {
        if (sentence[c] == ' ') {
            count++;
        }
        c++;
    }
    // นับแค่จำนวนคำเช่น Pingpong = 1 / p i n g = 4
    printf("number of words = %d\n", count);
    return 0;
}
