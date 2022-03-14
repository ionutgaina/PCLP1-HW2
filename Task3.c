#include "utils.h"

void SolveTask3() {
  char text[MAX_TEXT], grame_2_net[MAX_TEXT][MAX_WORD];
  char grame_2_brut[MAX_TEXT][MAX_WORD];
  char * p;
  int c = 0;
  while (fgets(text, MAX_TEXT, stdin)) {
    text[strcspn(text, "\n")] = 0;
    p = strtok(text, ",.!; ");
    while (p != NULL) {
      snprintf(grame_2_brut[c], MAX_WORD, "%s", p);
      if (c >= 1) {
        strncat(grame_2_brut[c - 1], " ", 1);
        strncat(grame_2_brut[c - 1], grame_2_brut[c], strlen(grame_2_brut[c]));
      }
      c++;
      p = strtok(NULL, ",.!; ");
    }
  }
    c--;
  int i = 0, j = 0, c_gram = 0, c_grams = 0, nr_grams[MAX];

  for (i = 0; i < c; i++) {
    c_gram = 1;
    for (j = i + 1; j < c; j++) {
      if (strcmp(grame_2_brut[i], grame_2_brut[j]) == 0) {
        c_gram++;
      }
    }

    int ok = 1;

    for (j = 0; j <= c_grams; j++) {
      if (strcmp(grame_2_brut[i], grame_2_net[j]) == 0) {
        ok = 0;
        break;
      }
    }
    if (ok == 1) {
      snprintf(grame_2_net[c_grams], MAX_WORD, "%s", grame_2_brut[i]);
      nr_grams[c_grams] = c_gram;
      c_grams++;
    }
  }

  printf("%d\n", c_grams);
  for (i = 0; i < c_grams; i++) {
    printf("%s %d\n", grame_2_net[i], nr_grams[i]);
  }
}
