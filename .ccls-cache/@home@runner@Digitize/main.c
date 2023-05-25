#include <stdio.h>

/* function to get a user input sentence */
char* sentenceUserInput() {

   // get, store, and print user input sentence
  static char sentenceInput[100];

  printf("Type in a sentence: \n");
  fgets(sentenceInput, sizeof(sentenceInput), stdin);
  printf("%s", sentenceInput);

  return sentenceInput;
}

int main(void) {
  sentenceUserInput();
  return 0;
}