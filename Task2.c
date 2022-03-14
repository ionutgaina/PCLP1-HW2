#include "utils.h"

void swap(char * str1, char * str2) {
  char * temp = (char * ) malloc((strlen(str1) + 1) * sizeof(char));
    snprintf(temp, "%s", str1);
    snprintf(str1, "%s", str2);
    snprintf(str2, "%s", temp);
    free(temp);
}

void caesar(int k, char text[MAX_TEXT]) {
  for (int i = 0; i < strlen(text); i++) {
    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] -= (k % ('z' - 'a' + 1));
      if (text[i] < 'a') {
        text[i] += ('z' - 'a' + 1);
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] -= (k % ('Z' - 'A' + 1));
      if (text[i] < 'A') {
        text[i] += ('Z' - 'A' + 1);
      }
    }
    if (text[i] >= '0' && text[i] <= '9') {
      text[i] -= (k % ('9' - '0' + 1));
      if (text[i] < '0') {
        text[i] += ('9' - '0' + 1);
      }
    }
  }
}

void vigenere(char key[MAX_KEY], char text[MAX_TEXT]) {
  for (int i = 0; i < strlen(text); i++) {
    int c = i % strlen(key);
    int k = key[c] - 'A';

    if (text[i] >= 'a' && text[i] <= 'z') {
      text[i] -= (k % ('z' - 'a' + 1));
      if (text[i] < 'a') {
        text[i] += ('z' - 'a' + 1);
      }
    }
    if (text[i] >= 'A' && text[i] <= 'Z') {
      text[i] -= (k % ('Z' - 'A' + 1));
      if (text[i] < 'A') {
        text[i] += ('Z' - 'A' + 1);
      }
    }
    if (text[i] >= '0' && text[i] <= '9') {
      text[i] -= (k % ('9' - '0' + 1));
      if (text[i] < '0') {
        text[i] += ('9' - '0' + 1);
      }
    }
  }
}

void addition(int key, char s1[], char s2[]) {
  caesar(key, s1);
  caesar(key, s2);

  int i = strlen(s1), j = strlen(s2);
  if (j > i) {
    swap(s1, s2);
    i = strlen(s1);
    j = strlen(s2);
  }
  i--;
  j--;
  int nr1 = 0, nr2 = 0, add = 0;
  while (i != -1) {
    s1[i] += add;
    add = 0;
    if (j != -1) {
      if (s1[i] + s2[j] - '0' > '9') {
        s1[i] += s2[j] - '0' - 10;
        add = 1;
      } else {
        s1[i] += s2[j] - '0';
      }
      j--;
    } else {
      if (s1[i] > '9') {
        s1[i] -= 10;
        add = 1;
      }
    }
    i--;
  }
  while (s1[0] == '0' && add == 0) {
    snprintf(s1, "%s", s1 + 1);
  }
  if (add)
    printf("1");
}
void SolveTask2() {
  char text[MAX_TEXT] = "", key[MAX_KEY] = "";
  char cifru[MAX_CIFRU] = "", text2[MAX_TEXT];

  scanf("%s", cifru);
  scanf("%s", key);
  scanf("%s", text);

  if (!strcmp(cifru, "caesar")) {
    int k = atoi(key);
    caesar(k, text);
  } else if (!strcmp(cifru, "vigenere")) {
    vigenere(key, text);
  } else if (!strcmp(cifru, "addition")) {
    scanf("%s", text2);
    int k = atoi(key);
    addition(k, text, text2);
  }
  printf("%s\n", text);
}
