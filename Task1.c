#include "utils.h"

#define ONEHUNDRED 100

void revstr(char * str1) {
  int len = 0, temp = 0;
  len = strlen(str1);

  for (int i = 0; i < len / 2; i++) {
    temp = str1[i];
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
  }
}

int palindrom(char seq[]) {
  char aux[MAX] = "";
  snprintf(aux, "%s", seq);
  revstr(aux);

  if (strcmp(seq, aux) == 0)
    return 1;
  else
    return 0;
}

int prime(int num) {
  int p = 0;
  for (int i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
      p++;
    }
  }
  if (p == 0) {
    return 1;
  } else {
    return 0;
  }
}

void SolveTask1() {
  char str[MAX] = "", * p = NULL;
  int N = 0, M = 0, max = 0, pos = 0, num = 0, c = 0, S = 0;
  int64_t n = 0, k = 0;
  int matrix[MAX][MAX], dir[MAX] = {
    0
  };

  scanf("%d", & N);
  scanf("%d\n", & M);

  memset(matrix, 0, sizeof(matrix));
  memset(dir, 0, sizeof(dir));

  fgets(str, MAX, stdin);
  str[strcspn(str, "\n")] = 0;

  p = strtok(str, " ");

  c = 0;
  while (p != NULL) {
    max = 0;
    if (p[0] == 'a') {
      for (int i = 0; i < DIRECTIONS; i++) {
        num = (int)(p[i + 1] - '0');
        if (num > max) {
          dir[c] = i;
          max = num;
        }
      }
      c++;
    } else if (p[0] == 'b') {
      num = atoi(p + 1) % ONEHUNDRED;
      if (palindrom(p + 1) == 1 && prime(num) == 1) {
        dir[c] = LEFT;
      }
      if (palindrom(p + 1) == 1 && prime(num) == 0) {
        dir[c] = RIGHT;
      }
      if (palindrom(p + 1) == 0 && prime(num) == 1) {
        dir[c] = UP;
      }
      if (palindrom(p + 1) == 0 && prime(num) == 0) {
        dir[c] = DOWN;
      }
      c++;
    } else if (p[0] == 'c') {
      n = (int)(p[1] - '0');
      k = (int)(p[2] - '0');

      S = 0;
      for (int i = 0; i < k; i++) {
        S += (int) p[3 + ((i * k) % n)];
      }

      if (S % 4 == 0) {
        dir[c] = LEFT;
      }
      if (S % 4 == 1) {
        dir[c] = UP;
      }
      if (S % 4 == 2) {
        dir[c] = RIGHT;
      }
      if (S % 4 == 3) {
        dir[c] = DOWN;
      }
      c++;
    }
    p = strtok(NULL, " ");
  }

  int i = 0, j = 0;
  matrix[0][0] = 1;
  for (int k = 0; k < c; k++) {
    if (dir[k] == RIGHT) {
      j++;
      matrix[i][j] = k + 2;
    }
    if (dir[k] == UP) {
      i--;
      matrix[i][j] = k + 2;
    }
    if (dir[k] == LEFT) {
      j--;
      matrix[i][j] = k + 2;
    }
    if (dir[k] == DOWN) {
      i++;
      matrix[i][j] = k + 2;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
