#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
    int n; 
    scanf("%d", &n);

    char letter[5000][15];
    char target[205];

    for (int i = 0; i < n; i++){
        scanf("%s", letter[i]);
    }
    scanf("%s", target);
    int L = strlen(target);

    int DP[205] = {0};
    DP[0] = 1;

    for (int i = 1; i <= L; i++){
        for (int j = 1; j <= 10 && j <= i; j++){
            char sub[15];
            strncpy(sub, target + i - j, j);
            sub[j] = '\0';

            int found = 0;
            for (int k = 0; k < n; k++){
                if (strcmp(sub, letter[k]) == 0){
                    found = 1;
                    break;
                }
            }

            if (DP[i - j] && found){
                DP[i] = 1;
                break;
            }
        }
    }

    if (DP[L]){
        printf("POSSIBLE\n");
    } else { printf("IMPOSSIBLE\n");}
    return 0;
}
