#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Linkedstack.h"

#define URL_SIZE 200

void removeEnter(char str[])
{
    int len;

    len = (int)strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main()
{
    LinkedStack* browser;
    int menu;
    char url[URL_SIZE];
    char* outUrl;
    char* nowUrl;

    browser = createLinkedStack();

    if (browser == NULL) {
        printf("스택 생성에 실패했습니다.\n");
        return 1;
    }

    while (1) {
        printf("입력 ");

        if (scanf("%d", &menu) != 1) {
            while (getchar() != '\n');
            continue;
        }

        getchar();

        if (menu == 1) {
            printf("URL 입력:\n");

            fgets(url, URL_SIZE, stdin);
            removeEnter(url);

            if (pushLinkedStack(browser, url)) {
                printf("현재 창: %s\n", peakLinkedStack(browser));
            }
        }
        else if (menu == 2) {
            outUrl = popLinkedStack(browser);

            if (outUrl == NULL) {
                printf("브라우저가 종료되었습니다.\n");
                destoryLinkedStack(browser);
                break;
            }

            printf("이탈: %s\n", outUrl);
            free(outUrl);

            nowUrl = peakLinkedStack(browser);

            if (nowUrl == NULL) {
                printf("브라우저가 종료되었습니다.\n");
                destoryLinkedStack(browser);
                break;
            }
            else {
                printf("현재 창: %s\n", nowUrl);
            }
        }
        else if (menu == 3) {
            nowUrl = peakLinkedStack(browser);

            if (nowUrl != NULL) {
                printf("현재 창: %s\n", nowUrl);
            }
        }
    }

    return 0;
}