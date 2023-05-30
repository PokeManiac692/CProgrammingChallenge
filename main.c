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

/* Gets a user input sentence */
char* sentenceUserInput() {

   // get, store, and print user input sentence
  static char sentenceInput[100];

  printf("Type in a sentence: \n");
  fgets(sentenceInput, sizeof(sentenceInput), stdin);
  // printf("%s", sentenceInput);

  return sentenceInput;
}

/* Adds a word to the dictionary */
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

/* Creates and returns a linked list dictionary */
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

/* Alphabetizes a linked list */
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
                int tempLength;
                char tempFour[5];

                // word swap
                strcpy(temp, current->word);
                strcpy(current->word, current->next->word);       
                strcpy(current->next->word, temp);

                // length swap
                tempLength = current->length;
                current->length = current->next->length;
                current->next->length = tempLength;

                //firstFour swap
                strcpy(tempFour, current->firstFour);
                strcpy(current->firstFour, current->next->firstFour);
                strcpy(current->next->firstFour, tempFour);
              
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

/* Searches for and returns a word from dictionary or NULL */
Node* searchWord(const char* word) {
    Node* current = dictionary;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current; // Word found
        }
        current = current->next;
    }

    return NULL; // Word not found
}

/* userSearch logic - option to add search to dictionary */
void userSearch() {
  // User search
    char searchedWord[MAX_WORD_LENGTH];
    printf("\nEnter a word to search: ");
    scanf("%s", searchedWord);

    Node* foundNode = searchWord(searchedWord);
    if (foundNode != NULL) {
        printf("Word found: %s\n", foundNode->firstFour);
    } else {
        printf("Word not found.\n");

        char choice;
        printf("Do you want to add '%s' to the dictionary? (y/n): ", searchedWord);
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            addToDictionary(searchedWord);
            alphabetizeDictionary();
            printf("'%s' has been added to the dictionary.\n", searchedWord);
        }
    }
}

/* Deletes the entire linked list */
void deleteDictionary() {
    Node* current = dictionary;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = NULL;
        current = next;
    }

    // Clear the contents of the dictionary array
    memset(dictionary, 0, sizeof(Node) * 100);
}

/* Prints the linked list dictionary */
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

  userSearch();
  // Print updated dictionary
  printf("\nUpdated Dictionary:\n");
  printDictionary(dictionary);

  deleteDictionary();
  printf("\nDictionary After Delete:\n");
  printDictionary(dictionary);

  
  
  return 0;
}