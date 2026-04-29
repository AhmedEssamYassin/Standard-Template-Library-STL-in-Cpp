#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

/*
C-Style Strings and C++ String Class

C-Style Strings:
----------------
- Character arrays with a null terminator '\0'
- Require fixed size at compile-time
- Modifiable character-by-character but cannot be reassigned
- Can be manipulated with string.h functions (strcpy, strcat, strlen, etc.)

C++ String Class:
-----------------
- Dynamic size, no need for fixed allocation
- Supports powerful built-in functions for manipulation
- Can be reassigned and modified easily

Data member constants:
-----------------
static const size_t npos = -1;

Maximum value for size_t
npos is a static member constant value with the greatest possible value for an element of type size_t.

This value, when used as the value for a len (or sub_len) parameter in string's member functions, means "until the end
of the string".

As a return value, it is usually used to indicate NO matches.

This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest
possible representable value for this type.

Methods and Features:
---------------------
C-Style String Functions:
- strlen(S): Returns the length (excluding null terminator) - O(N)
- strcpy(dest, src): Copies src into dest (must have enough space) - O(N)
- strcat(dest, src): Appends src to dest (must have enough space) - O(N)
- strcmp(S1, S2): Lexicographically compares two strings - O(N)
- strtok(S, delimiters): Splits string into tokens - O(N)
- memset(ptr, char, n): Fills memory block with given char - O(N)

- size()/length(): Returns the number of characters - O(1)
- empty(): Checks if the string is empty - O(1)
- clear(): Deletes the entire string - O(1)
- append(str): Appends another string - O(N)
- push_back(char): Appends a single character - O(1)
- pop_back(): Removes the last character - O(1)
- front(): Returns the first character - O(1)
- back(): Returns the last character - O(1)
- at(idx): Returns the character at idx with bounds checking - O(1)
- begin(): Returns an iterator to the first character - O(1)
- end(): Returns an iterator past the last character - O(1)
- rbegin(): Returns a reverse iterator to the last character - O(1)
- rend(): Returns a reverse iterator before the first character - O(1)

- insert(): Multiple variations for inserting substrings or characters - O(N)
 - insert(pos, str): Inserts entire string at position pos
 - insert(pos, str, subpos, sublen): Inserts substring from str at position pos
 - insert(pos, n, char): Inserts character char repeated n times at pos
 - insert(pos, const char*, N): Inserts the first N characters of a C-string
 - insert(pos, const char*): Inserts a C-string at position pos
 - insert(iterator, char): Inserts character at the specified iterator position
 - insert(iterator, n, char): Inserts n copies of a character before iterator
 - insert(iterator, first, last): Inserts range of characters before iterator

- replace(): Multiple variations for replacing substrings - O(N)
 - replace(pos, len, str): Replaces the substring of length len starting from pos with str
 - replace(pos, len, str, subpos, sublen): Replaces the substring of length len starting from pos with substring of
length sublen starting from subpos of str
 - replace(pos, len, const char*): Replaces the substring of length len starting from pos with the string literal
 - replace(pos, len, const char*, N): Replaces the substring of length len starting from pos with the first N characters
of the string literal
 - replace(pos, len, N, char): Replaces the substring of length len starting from pos with N copies of the character
 - replace(first, last, str): Replaces the range [first, last) with the string str
 - replace(first, last, const char*): Replaces the range [first, last) with the string literal
 - replace(first, last, const char*, N): Replaces the range [first, last) with the first N characters of the string
literal
 - replace(first, last, N, char): Replaces the range [first, last) with N copies of the character
 - replace(first1, last1, first2, last2): Replaces the range [first1, last1) with the range [first2, last2)

- substr(pos, len): Extracts substring of length len - O(N)
 - substr(pos): construct a substring starting from pos to the end of the string

- erase(): Multiple variations for erasing characters - O(N)
 - erase(pos, len): Removes substring from pos
 - erase(pos): Removes substring from pos to end of string
 - erase(iterator): Removes single character at iterator
 - erase(first, last): Removes range of characters

- swap(str): Swaps string values - O(1)

- find(): Multiple variations for finding substrings - O(N)
 - find(str, pos = 0): Finds first occurrence of str from pos
 - find(const char*, pos = 0): Finds first occurrence of C-string from pos
 - find(char, pos = 0): Finds first occurrence of a character from pos
 - find(const char*, pos, N): Finds first occurrence of first N characters of C-string from pos

- rfind(): Multiple variations for finding last occurrences - O(N)
 - rfind(str, pos = npos): Finds last occurrence of str before pos
 - rfind(const char*, pos = npos): Finds last occurrence of C-string before pos
 - rfind(char, pos = npos): Finds last occurrence of a character before pos
 - rfind(const char*, pos, N): Finds last occurrence of first N characters of C-string before pos

 pos:
        Position of the first character in the string to be considered in the search.
        If this is greater than the string length, the function never finds matches.
        Note: The first character is denoted by a value of 0 (NOT 1): A value of 0 means that the entire string is
searched.

        If the searched arg is NOT found, it returns string::npos which is -1

- find_first_of(): Finds first occurrence of any character from given set - O(N)
- find_last_of(): Finds last occurrence of any character from given set - O(N)
- find_first_not_of(): Finds first character not in given set - O(N)
- find_last_not_of(): Finds last character not in given set - O(N)
- getline(): Reads an entire line, handling spaces properly

Concatenation and comparison can be easily done using the overloaded operators =, > and <

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    /* ------+--------------+ C-Style strings ------+--------------+ */

    /* Declaration: */
    /* We can declare a c-style string EXACTLY in the same way we declare an array of characters! */
    char arr[256]; /* Size MUST be known at compile-time */

    /* Initialization: */
    char name[6] = {'A', 'h', 'm', 'e', 'd', '\0'};
    /* To hold the NULL character at the end of the array, the size of the character array containing the string is one
     * more than the number of characters in the actual word */

	/* Outputting C-Style strings: */
    /* We can simply output the name of the array using cout! */
    cout << name << "\n";
    
	/*
    You can also assign a string literal (it's type is const char *) to a character array
    You do NOT need to actually place the null character at the end of a string literal.
    The C++ compiler automatically places the '\0' at the end of the string when it initializes the character array
    */

	char password[] = "AEY0144436102#";
    cout << "Password: " << password << "\n";
    
    /*
    - One important point to note is that strings follow ALL the same rules as arrays.
     This means you can initialize the string upon creation, but you can NOT assign values to it using the assignment
    operator after that!
    - However, you can still modify single elements (also same as arrays)
    */
    /* password = "1234"; Yields an error */
    password[2] = 'E'; /* It works fine, and now it's "AEE0144436102#" */

    /*
    Why did we declare the C-Style string arr to be 255 characters long?
    The answer is that we don’t know how many characters the user is going to enter, so we are using this array of 255
    characters as a buffer. A buffer is memory set aside temporarily to hold data. If the user were to enter more
    characters than our array could hold, we would get a buffer overflow. A buffer overflow occurs when the program
    tries to store more data in a buffer than the buffer can hold. Buffer overflow results in other memory being
    overwritten, which usually causes a program crash, but can cause any number of other issues
    ---------------
    We use
    cin.getline(char * arr, size_t n) and cin.getline(char * arr, size_t n, char C) to handle this problem:
    arr: A character array in which data is stored
    n: Maximum number of character to extract
    C: delimiter character
    cin extracts characters from input stream until either:
    - Fills the whole size (n) of the character buffer
    - Hits the delimiter
    */
    cin.getline(arr, 25, '\\'); /* Extracts characters of the input stream until it fills 25 characters or hits the '\\' character */

    /* ------+--------------+ C-Style strings VS char pointers ------+--------------+ */
    char str[] = "c-Style string";
    /*
    - str[i] is modifiable
    - str is NOT modifiable, i.e., str CANNOT point to any other character other than the first character of this string
    literal However, we STILL can perform other pointer arithmetic on this pointer as long as they does NOT modify it
     i.e., *(str + i) is allowed but *(str++), str-- or *(++str) are NOT allowed
    - str is char* const, i.e., it CANNOT point to any other string (str = "Other" is NOT allowed)
    - sizeof(str) evaluates to the length of that string (because each character is one byte)
    */
    str[0] = 'C';               /* It works fine, now it's "C-Style string" */
    cout << *(str + 2) << "\n"; /* Same as str[2] */
    /* cout << *(str++); // Yields an error */
    /* cout << *(++str); // Yields an error */
    /* str++; // Yields an error */
    /* str = "1234";// Yields an error */

    const char *ch_ptr = "character pointer";
    /*
    - ch_ptr[i] is NOT modifiable, because ch_ptr now holds the address of the const char* "character pointer" which is
    stored in a "read-only" data segment
    - The pointer ch_ptr is NOT const, i.e., it can point to any other string literal
    - sizeof(ch_ptr) evaluates to the 4 or 8 bytes (depending on the architecture) because it's just a pointer
    */
    /* ch_ptr[0] = 'C'; // Yields a segmentation fault */
    ch_ptr++;                      /* Works fine */
    cout << *(--ch_ptr) << "\n";   /* Works fine */
    cout << *(ch_ptr + 2) << "\n"; /* Same as ch_ptr[2] */

    /* ------+--------------+ C-Style strings functions ------+--------------+ */

    /*
    strcpy(S1, S2):
    To avoid overflows, the size of the destination string shall be long enough to contain the source string (including
    the terminating null character), and should NOT overlap in memory with the source.
    --------------
    strcat(S1, S2)
    To avoid overflows, the size of the destination string shall be long enough to contain the source string (including
    the terminating null character), and should NOT overlap in memory with the source.
    --------------
    strlen(S):
    It returns the length of the string NOT the size of the buffer and NOT including the null terminating character.
    ---------------
    strcmp(S1, S2):
    Compares the two strings lexicographically (the same way used to sort words alphabetically in dictionaries),
    meaning that it starts comparison character by character, starting from the first character.
    If first character in both strings is equal, then this function will check the second character, if this is also
    equal then it will check the third and so on. This process continues until either:
    - A mismatch between the two strings is encountered
    - A character in either string is NULL. (A string ends)
    When S1 and S2 are NOT the same, the value returned by strcmp() function is the difference between the ASCII values
    of the first unmatched characters in S1 and S2
    ---------------------------------
    memset(char *ptr, char, size_t n)
    Fills a block of memory
    - Sets the first num bytes of the block of memory pointed to by ptr to the specified val (val is interpreted as an
    unsigned char)
    - returns ptr
    ----------------------------------------
    strtok(char *str, const char *delimiters)
    Splits string into tokens.
    - A sequence of calls to this function split str into tokens,
     which are sequences of contiguous characters separated by any of the characters that are part of delimiters literal
    - On the first call, the function expects a C string as argument for str, whose first character is used as the
    starting location to scan for tokens.
    - In subsequent calls, the function expects a null pointer and uses the position right after the end of the last
    token as the new starting location for scanning.

    - To determine the beginning and the end of a token,
     the function first scans from the starting location for the first character NOT contained in delimiters (which
    becomes the beginning of the token). And then scans starting from this beginning of the token for the first
    character contained in delimiters, which becomes the end of the token.
    - The scan also stops if the terminating null character is found.

    - This end of the token is automatically replaced by a null-character, and the beginning of the token is returned by
    the function.
    - Once the terminating null character of str is found in a call to strtok, all subsequent calls to this function
    (with a null pointer as the first argument) return a null pointer.

    Return value:
    If a token is found, a pointer to the beginning of the token. Otherwise, a null pointer.
    A null pointer is always returned when the end of the string (i.e., a null character) is reached in the string being
    scanned.

    */
    {
        /*
        WARNING: When using strcat, always ensure the destination buffer is large enough!
        If we had declared `char S1[] = "A character Array";`, S1 would only be 18 bytes long.
        Calling `strcat(S1, S2)` would write 38 characters into an 18-byte buffer,
        causing a stack buffer overflow (Undefined Behavior).
        To fix this, we explicitly give S1 a large capacity: `char S1[64]`.
        */
        char S1[64] = "A character Array";
        char S2[] = " is a C-style string";
        strcat(S1, S2);

        /*
        strcpy(S1, S2) would be fine here since S1 (64 bytes) > S2 (21 bytes).
        strcpy(S2, S1) would overflow because S2 (21 bytes) < S1 (38 chars after strcat).
        Always ensure the destination buffer can hold the source string + '\0'.
        */
        char S3[64];
        strcpy(S3, S1);

        cout << "Length of S1: " << strlen(S1) << "\n";

        cout << "strcmp(S1, S2): " << strcmp(S1, S2) << "\n";

        char line[] = "This is A sentence, or a Line, just to show how strtok() works! Amazing ha? I know:)";
        char *token = strtok(line, " ,!?"); /* First call */
        cout << "Tokenizing the string based on ' ', '!' and '?'\n";
        int cnt = 1;
        while (token)
        {
            cout << "Token " << cnt++ << ": " << token << "\n";
            token = strtok(nullptr, " ,!?"); /* Subsequent calls */
        }

        memset(S1, 'X', strlen(S1)); /* Fills ALL S1 with X's */
    }
    cout << "---------------------------------------------------------------------------------" << "\n";

    /* ------+--------------+ Class strings ------+--------------+ */
    /* Declaration: */
    string T;

    /* Initialization and constructors */
    string S = "A class string";
    {
        string S2("Full string");

        string S3("Full string", 3); /* "Ful" */

        string S4(S2, 2); /* A string starting from index 2 to the end --> "ll string" */

        string S5(S2, 2, 6); /* A string of length 6 starting from index 2 --> "ll str" */

        string S6(5, 'X'); /* A string of 5 X's --> "XXXXX" */

        string S7({'X', 'Y', 'Z'}); /* "XYZ" */
    }
    /* Unlike C-style strings, we can re-assign the class string to any value at any time after initialization */
    S = "Another class string"; /* Works fine! */

    /*
    You do NOT need to actually place the null character at the end of a string literal.
    The C++ compiler automatically places the '\0' at the end of the string when it initializes the class string.

    sizeof(std::string) vs the string's actual content:
    ----------------------------------------------------
    sizeof(S) does NOT return the length of the text stored in S.
    It returns the size of the std::string OBJECT itself, which internally contains:
     - A pointer to the dynamically allocated character buffer
     - A size_t for the current length
     - A size_t for the current capacity
    On a typical 64-bit system, sizeof(std::string) is 24 or 32 bytes,
    regardless of how many characters the string actually holds.
    To get the text length, use S.size() or S.length().
    */
    cout << sizeof(S) << "\n";

    getline(cin, T); /* reads a line (string with spaces) as an input */
    cout << T << "\n";

    T = ""; /* Assigns T to an empty string */

    getline(cin, T, '!'); /* reads a line (string with spaces) as an input until the delimiter '!' */
    cout << T << "\n";

    /* ------+--------------+ Class strings functions ------+--------------+ */

    string Word = "An example sentence!";

    cout << S + " Ahmed" + " " + "Essam" << "\n"; /* we can add several strings using the operator + */

    S += "New string";
    if (!S.empty())
        cout << "string is not empty, it is: " << S << "\n";
    S = ""; /* deletes the whole string */
    S += "Another new string";
    cout << S << "\n";
    {
        string str1 = "to be question";
        string str2 = "the ";
        string str3 = "or not to be";
        string::iterator it;

        /* used in the same order as described above: */
        str1.insert(6, str2); /* to be (the )question */
        cout << str1 << '\n';

        str1.insert(6, str3, 3, 4); /* to be (not )the question */
        cout << str1 << '\n';

        str1.insert(10, "that is cool", 8); /* to be not (that is )the question */
        cout << str1 << '\n';

        str1.insert(10, "to be "); /* to be not (to be )that is the question */
        cout << str1 << '\n';

        str1.insert(15, 1, ':'); /* to be not to be(:) that is the question */
        cout << str1 << '\n';

        it = str1.insert(str1.begin() + 5, ','); /* to be(,) not to be: that is the question */
        cout << str1 << '\n';

        str1.insert(str1.end(), 3, '.'); /* to be, not to be: that is the question(...) */
        cout << str1 << '\n';

        str1.insert(it + 2, str3.begin(), str3.begin() + 3); /* to be, (or )not to be: that is the question(...) */
        cout << str1 << '\n';
    }
    cout << "---------------------------------------------------------------------------------" << "\n";
    {
        string base = "this is a test string.";
        string str2 = "n example";
        string str3 = "sample phrase";
        string str4 = "useful.";

        /* Using positions: */
        string str = base;       /* "this is a test string." */
        str.replace(9, 5, str2); /* "this is an example string." (1) */
        cout << str << '\n';

        str.replace(19, 6, str3, 7, 6); /* "this is an example phrase." (2) */
        cout << str << '\n';

        str.replace(8, 10, "just a"); /* "this is just a phrase." (3) */
        cout << str << '\n';

        str.replace(8, 6, "a shorty", 7); /* "this is a short phrase." (4) */
        cout << str << '\n';

        str.replace(22, 1, 3, '!'); /* "this is a short phrase!!!" (5) */
        cout << str << '\n';

        /* Using iterators: */
        str.replace(str.begin(), str.end() - 3, str3); /* "sample phrase!!!" (1) */
        cout << str << '\n';

        str.replace(str.begin(), str.begin() + 6, "replace"); /* "replace phrase!!!" (3) */
        cout << str << '\n';

        str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7); /* "replace is cool!!!" (4) */
        cout << str << '\n';

        str.replace(str.begin() + 12, str.end() - 4, 4, 'o'); /* "replace is cooool!!!" (5) */
        cout << str << '\n';

        str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end()); /* "replace is useful." (6) */
        cout << str << '\n';
    }
    cout << "---------------------------------------------------------------------------------" << "\n";
    {
        string str("The sixth sick sheik's sixth sheep's sick.");
        string key("sixth");

        size_t found = str.rfind(key);
        if (found != string::npos)
            str.replace(found, key.length(), "seventh");

        cout << str << '\n';
    }
    /* Erase Examples */
    cout << "---------------------------------------------------------------------------------" << "\n";
    string erase_str = "Hello, World!";
    erase_str.erase(5, 2); /* Removes ", " */
    cout << "After erase(5, 2): " << erase_str << "\n";

    erase_str.erase(5); /* Removes everything after index 5 */
    cout << "After erase(5): " << erase_str << "\n";

    erase_str = "Hello, World!";
    erase_str.erase(erase_str.begin() + 7); /* Removes 'W' */
    cout << "After erase(begin()+7): " << erase_str << "\n";

    erase_str.erase(erase_str.begin() + 2, erase_str.begin() + 5);
    cout << "After erase range: " << erase_str << "\n";

    /* Swap Example */
    cout << "---------------------------------------------------------------------------------" << "\n";
    string swap1 = "First", swap2 = "Second";
    swap1.swap(swap2);
    cout << "After swap: swap1 = " << swap1 << ", swap2 = " << swap2 << "\n";

    /* Find Examples */
    cout << "---------------------------------------------------------------------------------" << "\n";
    string find_str = "This is a simple example.";
    cout << "Find 'simple': " << find_str.find("simple") << "\n";
    cout << "Find 'is' after index 3: " << find_str.find("is", 3) << "\n";
    cout << "Find first occurrence of 's': " << find_str.find('s') << "\n";
    cout << "Find first 3 characters of 'example': " << find_str.find("example", 0, 3) << "\n";

    /* Reverse Find Examples */
    cout << "---------------------------------------------------------------------------------" << "\n";
    cout << "Reverse Find 'simple': " << find_str.rfind("simple") << "\n";
    cout << "Reverse Find 'is' before index 10: " << find_str.rfind("is", 10) << "\n";
    cout << "Reverse Find 's': " << find_str.rfind('s') << "\n";
    cout << "Reverse Find first 3 characters of 'example': " << find_str.rfind("example", find_str.size(), 3) << "\n";

    return 0;
}