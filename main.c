#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

/* Structure for dictionary entry */
typedef struct Node {
    char word[MAX_WORD_LENGTH];
    int length;
    char firstFour[5];
    struct Node* next;
} Node;

Node dictionary[MAX_WORDS];  // Global memory for dictionary
int dictionarySize = 0;  // Current size of the dictionary

/* function to get a user input sentence */
char* sentenceUserInput() {

   // get, store, and print user input sentence
  static char sentenceInput[100];

  printf("Type in a sentence: \n");
  fgets(sentenceInput, sizeof(sentenceInput), stdin);
  // printf("%s", sentenceInput);

  return sentenceInput;
}

/* Function to add a word to the dictionary */
void addToDictionary(char* word) {
    if (dictionarySize >= MAX_WORDS) {
        printf("Dictionary is full. Cannot add more words.\n");
        return;
    }

    // Create a new node
    Node* newNode = &dictionary[dictionarySize];

    // Copy the word
    strncpy(newNode->word, word, MAX_WORD_LENGTH);
    newNode->word[MAX_WORD_LENGTH - 1] = '\0'; // Ensure null-terminated string
  
    // Store word length
    newNode->length = strlen(word);

    // Store the first four letters of the word
    strncpy(newNode->firstFour, word, 4);
    newNode->firstFour[4] = '\0'; // Ensure null-terminated string

    newNode->next = NULL; // Set next pointer to NULL

    // Link the new node to the previous node
    if (dictionarySize > 0) {
        dictionary[dictionarySize - 1].next = newNode;
    }

    dictionarySize++; // Increase the size of the dictionary
}

/* Function to create and return a linked list dictionary */
Node* createDictionary(char* sentence) {
    int sentenceLength = strlen(sentence);
    int wordStart = 0;
    int i;

    for (i = 0; i <= sentenceLength; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            // Found a word boundary, extract the word
            char word[MAX_WORD_LENGTH];
            int wordLength = i - wordStart;
            strncpy(word, &sentence[wordStart], wordLength);
            word[wordLength] = '\0';

            addToDictionary(word); // Add the word to the dictionary

            wordStart = i + 1; // Update the word start index
        }
    }
  
    return &dictionary[0]; // Return the head of the linked list dictionary
}

/* Function to alphabetize a linked list */
void alphabetizeDictionary() {
    if (dictionary == NULL || dictionary->next == NULL) {
        return; // No need to sort an empty or single-node list
    }

    int swapped;
    Node* current;
    Node* last = NULL;

    do {
        swapped = 0;
        current = dictionary;

        while (current->next != last) {
            if (strcmp(current->word, current->next->word) > 0) {
                // Swap nodes
                char temp[MAX_WORD_LENGTH];
                strcpy(temp, current->word);
                strcpy(current->word, current->next->word);
                strcpy(current->next->word, temp);
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

/* Function to print the linked list dictionary */
void printDictionary(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("Word: %s, Word length: %d, First four letters: %s\n", current->word, current->length, current->firstFour);
        current = current->next;
    }
}

int main(void) {
  
  char* sentence = sentenceUserInput();

  Node* dictionary = createDictionary(sentence);

  printf("Linked List Dictionary:\n");
  printDictionary(dictionary);

  // Alphabetize the dictionary
  alphabetizeDictionary();

  // Print alphabetized dictionary
  printf("\nAlphabetized Dictionary:\n");
  printDictionary(dictionary);
  
  return 0;
}