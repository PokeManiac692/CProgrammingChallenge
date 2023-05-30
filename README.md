# Digitize Programming Challenge:
*A simple program in `C` demonstrating the following concepts:*

* **user input**,
* **static data structure creation and usage**,
* **output to console**

#### TL;DR
In this program, the user inputs a sentence which is broken down into a **linked-list dictionary**, storing the `word` itself, the character `length`, and the four letter `abbreviation`. Using a variation of the **Bubble-Sort Algorithm**, the dictionary is alphabetically sorted. Users can search for words in the dictionary using a **linear search** function that supports **case sensitive** and **case insensitive** searches (Time Complexity - `O(n)`). Users can also add new entries or delete the entire linked-list dictionary.

## Running This Program and What to Expect

1. Upon hitting `Run`, the user will be directed to the following Start Menu:
```
██████  ██  ██████  ██ ████████ ██ ███████ ███████ 
██   ██ ██ ██       ██    ██    ██    ███  ██      
██   ██ ██ ██   ███ ██    ██    ██   ███   █████   
██   ██ ██ ██    ██ ██    ██    ██  ███    ██      
██████  ██  ██████  ██    ██    ██ ███████ ███████ 

JAbuan Programming Challenge Submission
---------------------------------------------------
1. Start Program
2. End Program
Enter numerical choice: 
```
2. The user will input `1` or `2` on their keyboard and press `ENTER`.
    * Inputting `1` will start the program
    * Inputting `2` will clear the screen and end the program
3. Starting the program prompts the user to type in a sentence
```
Type in a sentence: 
Hello world, this was created for the digitize programmers challenge
```
4. After typing in a sentence, the input is broken down into a **linked-list dictionary**, storing the `word`, its character `length`, and a four letter `abbreviation`. The user is then presented with an Options menu.
```
   ____        _   _                  
  / __ \      | | (_)                 
 | |  | |_ __ | |_ _  ___  _ __  ___  
 | |  | | '_ \| __| |/ _ \| '_ \/ __| 
 | |__| | |_) | |_| | (_) | | | \__ \ 
  \____/| .__/ \__|_|\___/|_| |_|___/ 
        | |                           
        |_|                           

---------------------------------------------------
1. Print Alphabetized List
2. Look Up a Word
3. Add an Entry
4. Initialize the Current Linked List
5. Exit Program

Enter numerical choice: 
```
5. Inputting a number from `1` - `5` will take the user through the program's functions.
    * Inputting `1` will print out the **alphabetized linked-list dictionary** providing the `word`, `length`, and `abbreviation` for each of the words in the user-input sentence. The user must hit `ENTER` to continue.
```
      
Alphabetized Dictionary:
---------------------------------------------------
Word: Hello,        Length: 5,      Abbreviation: Hell
Word: challenge,        Length: 9,      Abbreviation: chal
Word: created,      Length: 7,      Abbreviation: crea
Word: digitize,     Length: 8,      Abbreviation: digi
Word: for,      Length: 3,      Abbreviation: for
Word: programmers,      Length: 11,     Abbreviation: prog
Word: the,      Length: 3,      Abbreviation: the
Word: this,     Length: 4,      Abbreviation: this
Word: was,      Length: 3,      Abbreviation: was
Word: world,,       Length: 6,      Abbreviation: worl
---------------------------------------------------

Press ENTER key to Continue
```
  * Using option `2` allows the user to **search** for a word in the dictionary. This search has the option of using **case-sensitivity**. The `word` and its linked information is displayed.

```
Enter a word to search: Hello
Do you want to search with case sensitivity? (y/n): y
Word found: Hell
Word: Hello,        Length: 5,      Abbreviation: Hell


Press ENTER key to Continue
```
_**Search `Hello` with Case Sensitivity:** Word `Hello` exists in the dictionary and is returned with its length and abbreviation._

```
Enter a word to search: hello
Do you want to search with case sensitivity? (y/n): y
Word not found.
```
_**Search `hello` with Case Sensitivity:** Word `hello` does not exist in the dictionary and an error message is returned._

```
Enter a word to search: hello
Do you want to search with case sensitivity? (y/n): n
Word found: Hell
Word: Hello,        Length: 5,      Abbreviation: Hell


Press ENTER key to Continue
```
_**Search `hello` WITHOUT Case Sensitivity:** Word `Hello` exists in the dictionary and the original capitalized word is returned._

```
Enter a word to search: water
Do you want to search with case sensitivity? (y/n): y
Word not found.
Do you want to add 'water' to the dictionary? (y/n): y
'water' has been added to the dictionary.


Press ENTER key to Continue
```
_**Search `water`:** Word `water` does not exist in the dictionary and an error message returned. User is given the option to add the word to the dictionary._

```
Alphabetized Dictionary:
---------------------------------------------------
Word: Hello,        Length: 5,      Abbreviation: Hell
Word: challenge,        Length: 9,      Abbreviation: chal
Word: created,      Length: 7,      Abbreviation: crea
Word: digitize,     Length: 8,      Abbreviation: digi
Word: for,      Length: 3,      Abbreviation: for
Word: programmers,      Length: 11,     Abbreviation: prog
Word: the,      Length: 3,      Abbreviation: the
Word: this,     Length: 4,      Abbreviation: this
Word: was,      Length: 3,      Abbreviation: was
Word: water,        Length: 5,      Abbreviation: wate
Word: world,,       Length: 6,      Abbreviation: worl
---------------------------------------------------

```
_**Resulting print shows that the Word `water` now exists in the dictionary and is automatically alphabetized._

  * Choosing option `3` allows the user to add a new word to the dictionary.
```
Enter a new word to add: embedded
'embedded' has been added to the dictionary.


Press ENTER key to Continue
```
```
Alphabetized Dictionary:
---------------------------------------------------
Word: Hello,        Length: 5,      Abbreviation: Hell
Word: challenge,        Length: 9,      Abbreviation: chal
Word: created,      Length: 7,      Abbreviation: crea
Word: digitize,     Length: 8,      Abbreviation: digi
Word: embedded,     Length: 8,      Abbreviation: embe
Word: for,      Length: 3,      Abbreviation: for
Word: programmers,      Length: 11,     Abbreviation: prog
Word: the,      Length: 3,      Abbreviation: the
Word: this,     Length: 4,      Abbreviation: this
Word: was,      Length: 3,      Abbreviation: was
Word: water,        Length: 5,      Abbreviation: wate
Word: world,,       Length: 6,      Abbreviation: worl
---------------------------------------------------
```
_Resulting print shows that `embedded` was added to the dictionary and alphabetized as well._

* Option `4` deletes the dictionary contents and outputs a confirmation message.
```
Dictionary Deleted.


Press ENTER key to Continue
```
```
Alphabetized Dictionary:
---------------------------------------------------
Word: ,     Length: 0,      Abbreviation: 
---------------------------------------------------
```
_Printing the dictionary shows no results now._

  * Choosing Option `5` returns to the `Main Menu`.
```
Exiting to main menu...


Press ENTER key to Continue
```

### Project Notes
* What was easy?
  * The challenge itself was pretty straightforward. Breaking down the problem conceptually into smaller, bite-size problems made tackling each requirement easier.
* What was challenging?
  * Working without dynamic memory allocation made this more challenging in that it was more tedious to complete. I had to review a few `C` concepts as well such as proper **syntax**,**linked-list dictionaries**, and taking user input and **flushing out** `\n` characters.
* What could be improved?
  * This program can be further improved by adding more string validations to make it more bulletproof as a program. Removing duplicates from the dictionary could also be another avenue for improvement. I think the main changes for optimization would be the `deleteDictionary()` function as in its current state, it does not allow for further changes to the dictionary after deletion.


### Programming Log
| Date | Start Time | Stop Time | Task Description |
| ----------- | ----------- | ----------- | ----------- |
| 5/25 | 2:20 PM | 2:25 PM | Started Repl<br>Connected to Github<br>Started README.md |
| 5/25 | 4:30 PM | 5:00 PM | Review Program Specifications<br>Create sentence input function |
| 5/26 | 12:00 PM | 1:30 PM | Created linked list dictionary<br>Dictionary Structure:<br>`word`->`word length`->`first 4 letters` |
| 5/26 | 8:00 PM | 8:30 PM | Created `alphabetizeDictionary()` |
| 5/26 | 9:50 PM | 10:20 PM | Fixed errors according to specifications<br>Created `userSearch()` |
| 5/26 | 10:20 PM | 10:35 PM | Created `deleteDictionary()` |
| 5/26 | 10:35 PM | 11:00 PM | Optimized code<br>Created `addNewDict()` |
| 5/26 | 11:00 PM | 11:15 PM | Added case sensitive search option |
| 5/30 | 1:25 PM | 3:00 PM | Created menus<br>Added ASCII art for fun 😅 |
| 5/30 | 4:00 PM | 5:30 PM | Added I/O examples to `README`<br>Optimized code and added some comments<br>Removed printf() tests in program |