/*
  Jeremy Abuan ©️ 2023
  Programming Challenge
*/

#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

/* Structure for dictionary entry */
/* word -> length -> abbreviation */
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

  return sentenceInput;
}

/* Adds a word to the linked-list dictionary */
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

/* Gets the last node from the linked list dictionary */
Node* getLastNode() {
    if (dictionary == NULL) {
        return NULL;  // The dictionary is empty
    }

    Node* current = dictionary;
    while (current->next != NULL) {
        current = current->next;
    }

    return current;
}

/* Creates and returns a linked list dictionary */
Node* createDictionary(char* sentence) {
    int sentenceLength = strlen(sentence);
    int wordStart = 0;
    int i;

    // Iterate through sentence to extract each word
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

    // Remove the newline character from the last word, if present
    Node* lastNode = getLastNode();
    if (lastNode != NULL) {
        int lastNodeLength = strlen(lastNode->word);
        // if new line, zero character and update length
        if (lastNode->word[lastNodeLength - 1] == '\n') {
            lastNode->word[lastNodeLength - 1] = '\0';
            lastNode->length = lastNodeLength - 1;  // update the character length
        }
    }
  
    return &dictionary[0]; // Return the head of the linked list dictionary
}

/* Alphabetizes a linked list using Bubble Sort Algorithm */
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
/* Case Sensitive Search*/
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

/* Searches for and returns a word from dictionary or NULL */
/* Case Insensitive Search */
Node* cInsensitiveSearchWord(const char* word) {
    Node* current = dictionary;

    while (current != NULL) {
        if (strcasecmp(current->word, word) == 0) {
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
  Node* foundNode;
  printf("\nEnter a word to search: ");
  scanf("%s", searchedWord);

  char insensitivity;
  printf("Do you want to search with case sensitivity? (y/n): ");
  scanf(" %c", &insensitivity);

  if (insensitivity == 'y' || insensitivity == 'Y') {
    foundNode = searchWord(searchedWord);
  } else {
    foundNode = cInsensitiveSearchWord(searchedWord);
  }
  
  if (foundNode != NULL) {
    printf("Word found: %s\n", foundNode->firstFour);
    printf("Word: %s,\t\tLength: %d,\t\tAbbreviation: %s\n", foundNode->word, foundNode->length, foundNode->firstFour);
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

/* Adds a new entry to the existing dictionary */
void addNewDictEntry(char* newEntry) {
  addToDictionary(newEntry);
  alphabetizeDictionary();
  printf("'%s' has been added to the dictionary.\n", newEntry);
}

/* Deletes the contents in the linked list dictionary*/
void deleteDictionary() {
    Node* current = dictionary;
    Node* next;

    while (current != NULL) {
        next = current->next;
        current->next = NULL;
        current->word[0] = '\0';  // Reset the word to an empty string
        current = next;
    }

    // Clear the contents of the dictionary array
    memset(dictionary, 0, sizeof(Node) * 100);
}

/* Prints the linked list dictionary */
void printDictionary(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("Word: %s,\t\tLength: %d,\t\tAbbreviation: %s\n", current->word, current->length, current->firstFour);
        current = current->next;
    }
}

/* Add a new entry to dictionary */
void addAnEntry() {
  char addNewWord[MAX_WORD_LENGTH];
  printf("\nEnter a new word to add: ");
  scanf("%s", addNewWord);
  addNewDictEntry(addNewWord);
}

/* ----- UI for Menu Start ----- */
/* ----------------------------- */

/* main menu output w/ASCII Art */
void displayMenu() {
  printf("\n ██████ ██      ██     ████████  ██████   ██████  ██      \n"); 
  printf("██      ██      ██        ██    ██    ██ ██    ██ ██      \n"); 
  printf("██      ██      ██        ██    ██    ██ ██    ██ ██      \n"); 
  printf("██      ██      ██        ██    ██    ██ ██    ██ ██      \n"); 
  printf(" ██████ ███████ ██        ██     ██████   ██████  ███████ \n"); 
  printf("\nJA Programming Challenge Submission\n");
  printf("---------------------------------------------------\n");
  printf("1. Start Program\n");
  printf("2. End Program\n");
  printf("Enter numerical choice: ");
}

/* program inner-menu w/ASCII Art */
void displayProgramMenu() {
  printf("   ____        _   _                  \n");
  printf("  / __ \\      | | (_)                 \n");
  printf(" | |  | |_ __ | |_ _  ___  _ __  ___  \n");
  printf(" | |  | | '_ \\| __| |/ _ \\| '_ \\/ __| \n");
  printf(" | |__| | |_) | |_| | (_) | | | \\__ \\ \n");
  printf("  \\____/| .__/ \\__|_|\\___/|_| |_|___/ \n");
  printf("        | |                           \n");
  printf("        |_|                           \n");
  printf("\n---------------------------------------------------\n");
  printf("1. Print Alphabetized List\n");
  printf("2. Look Up a Word\n");
  printf("3. Add an Entry\n");
  printf("4. Initialize the Current Linked List\n");
  printf("5. Exit Program\n\n");
  printf("Enter numerical choice: ");
}

/* program inner-menu logic */
void programMenu() {
  int userChoice;

  // do {show menu} until user quits
  do {
    displayProgramMenu();
    scanf("%d", &userChoice);

    // menu logic for program functions
    switch (userChoice) {
      case 1:
        /* Print Alphabetized Dictionary */
        system("clear");
        printf("\nAlphabetized Dictionary:\n");
        printf("---------------------------------------------------\n");
        printDictionary(dictionary);
        printf("---------------------------------------------------\n\n\n\n");
        // Flush the newline character from the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("Press ENTER key to Continue\n");  
        getchar();
        system("clear"); 
        break;
      case 2:
        /* Look Up a Word */
        system("clear");
        userSearch();
        // Flush the newline character from the input buffer
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\n\nPress ENTER key to Continue\n");  
        getchar();
        system("clear"); 
        break;
      case 3:
        /* Add an Entry */
        system("clear");
        addAnEntry();
        // Flush the newline character from the input buffer
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\n\nPress ENTER key to Continue\n");  
        getchar();
        system("clear"); 
        break;
      case 4:
        /* Initialize the Current Linked List [DELETE] */
        system("clear");
        deleteDictionary();
        printf("Dictionary Deleted.\n");
        // Flush the newline character from the input buffer
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\n\nPress ENTER key to Continue\n");  
        getchar();
        system("clear"); 
        break;
      case 5:
        /* End Program */
        system("clear");
        printf("Exiting to main menu...\n\n\n");
        // Flush the newline character from the input buffer
        while ((c = getchar()) != '\n' && c != EOF) {}
        printf("\n\nPress ENTER key to Continue\n");  
        getchar();
        system("clear"); 
        break;
      default:
        /* Catch Input Errors */
        system("clear"); 
        printf("Invalid choice. Please try again.\n");
    }
  } while (userChoice != 5);  // Exit Program
}

/* start option from Main Menu */
void startProgram() {
  system("clear"); // Clears console screen for readability
  
  // Flush the newline character from the input buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
  
  char* sentence = sentenceUserInput();
  
  Node* dictionary = createDictionary(sentence);
  
  alphabetizeDictionary();  // Alphabetize the dictionary

  programMenu();  // Prompt user through menu
  
}

/* main menu logic */
void menu() {
  int userChoice;

  // do {show main menu} until user exits
  do {
    displayMenu();
    scanf("%d", &userChoice);

    switch (userChoice) {
      case 1:
        startProgram();
        break;
      case 2:
        break;
      default:
        system("clear"); 
        printf("Invalid choice. Please try again.\n");
    }
  } while (userChoice != 2);
  system("clear");
}

int main(void) {
  menu(); // Show the main menu
  
  return 0;
}