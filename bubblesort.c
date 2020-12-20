#include<stdio.h>
int strlength(const char in_p[]);
void print_string(const char instring[]);
void bubblesort(char bubstring[]);
void to_lowercase(char instring[]);

/**
 * @fn	int main(void)
 * @brief	Main entry-point for this application
 * @author	MIN
 * @date	2020/10/31
 * @returns	Exit-code for the process - 0 for success, else an error code.
 */
int main(void)
{
    char mystring[] = "C Programming in TCD School of Mathematics";
    printf("Original string: %s\n", mystring);

    bubblesort(mystring);
    printf("\nAfter bubblesort of original string:\n");
    /* Print string, grouping characters together on a line 	*/
    print_string(mystring);

    to_lowercase(mystring);
    bubblesort(mystring);
    printf("\nAfter folding case and bubblesorting again:\n");
    print_string(mystring);

    return 0;
}

/**
 * @fn	int strlength(const char in_p[])
 * @brief	Q1 Part A calculate the length of a string
 * @author	MIN
 * @date	2020/10/31
 * @param 	in_p   input a string	
 * @returns	An int.
 */
int strlength(const char in_p[])
{
    int len = -1;               //The initialization length is -1
    while (len++, *in_p++);     //Every time the pointer moves back, it checks to see if it reaches the end, while len increases by 1
    return len;                 //Returns the length of the string
}

/**
 * @fn	void print_string(const char instring[])
 * @brief	Q1 Part B Print the string on one line per letter, only letters, or on one line if adjacent letters are the same
 * @author	MIN
 * @date	2020/10/31
 * @param 	instring	input a string
 */
void print_string(const char instring[])
{
    const char* str = instring;   //Used to store the previous letter
    while (*instring)       //Checks if the pointer reaches the end of the string
    {
        //If the current character is alphabetic, print
        if (*instring >= 'a' && *instring <= 'z' ||
            *instring >= 'A' && *instring <= 'Z')
        {
            //If the previous character is different from this character and the previous record is a letter, wrap the line
            if (*str != *instring &&
                (*str >= 'a' && *str <= 'z' ||
                    *str >= 'A' && *str <= 'Z')
                )
                printf("\n");
            printf("%c", *instring);
            //Record current character
            str = instring;
        }
        //The pointer moves back one bit
        instring++;
    }
    printf("\n");
}

/**
 * @fn	void bubblesort(char bubstring[])
 * @brief	Q1 Part C Bubble sort sort strings, a little bit of a simple optimization
 * @author	MIN
 * @date	2020/10/31
 * @param 	bubstring	input a string
 */
void bubblesort(char bubstring[])
{
    //Record string length
    int len = strlength(bubstring);
    for (int i = 0; i < len - 1; i++)
    {
        //Records whether an exchange operation was performed
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++)
        {
            //If the preceding character is larger than the following character, switch positions
            if (bubstring[j] > bubstring[j + 1])
            {
                bubstring[j] ^= bubstring[j + 1];
                bubstring[j + 1] ^= bubstring[j];
                bubstring[j] ^= bubstring[j + 1];
                //Flag as 1
                flag = 1;
            }
        }
        //If flag is 0, it means that the characters after this are all arranged in an orderly manner and out of the loop
        if (!flag)
            break;
    }
}

/**
 * @fn	void to_lowercase(char instring[])
 * @brief	Q1 Part D Convert all uppercase letters to lowercase letters
 * @author	MIN
 * @date	2020/10/31
 * @param 	instring	The instring
 */
void to_lowercase(char instring[])
{
    do
    {
        //If the current character is uppercase
        if (*instring >= 'A' && *instring <= 'Z')
        {
            //Transfer as lowercase
            *instring += 'a' - 'A';
        }
    } while (*instring++);//Determines whether the end of the string has been reached and the pointer moves back
}