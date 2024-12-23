#include <stdio.h>

int main() {
    char buffer[10]; // This is a fixed size character buffer array if the user enter more characters than the buffer size it will cause buffer overflow and cause security issue in the program and change in adjacent memory.

    printf("Enter a string: "); // Prompt for getting user input
    scanf("%s", buffer); // saves the user input in character buffer array, in this scanf it will not check the length that user is entering, it will directly write the input until it see space or new line, if it see any of these it will add a null \0 to buffer array,so if the user input more data then the buffer size that is 0-8+Null over or above the data cause buffer overflow, here scanf is vulnerable
    printf("You entered : %s\n", buffer); // This will print the string saved in the buffer array

    return 0;
    //Program Exexution
    /*╭─ 💁 n.sivashankar2002 at 💻 essentials in 📁 ~/gcc3
      ╰λ ./Buffer-Assignment
      Enter a string: Mani
      You entered: Mani   //Here i first entered 4 characters Mani the program is normal here, it will not overflow the buffer because the entered data is less than the buffer size and it will not overwrite adjacent memory also.

    //Program Execution
    /*╭─ 💁 n.sivashankar2002 at 💻 essentials in 📁 ~/gcc3
      ╰λ ./Buffer-Assignment
       Enter a string: ManikandanNagaraj //Here i entered 17 characters ManikandanNagaraj it will overflow the buffer because scanf deosn't encoundered /0 null or new line characters so it will write the overflowed data in the adjacent memory.
       You entered: ManikandanNagaraj // The  program will print the overflowed data in the adjacent memory and it overflows the stack, base pointer and return address also then the program will give error and terminate.
       *** stack smashing detected ***: terminated // It is a error  message that is given by the program when it encounters buffer overflow.
       Aborted (core dumped) // It store  the output has core dump in the memory and it will terminate the program.
       */
}

// Breif explain with alter code:
    /*char buffer[10]; // This is a fixed size character buffer array if the user enter more characters than the buffer size it will cause buffer overflow and cause security issue in the program and change in adjacent memory.
        char b[10]; // This is also  a  fixed size character buffer array here i used this because to show how char buffer[10] overflow affects this array.

        printf("Enter a string: "); // Prompt for getting user input
        scanf("%s", buffer); // saves the user input in character buffer array, in this scanf it will not check the length that user is entering, it will directly write the input until it see space or new line, if it see any of these it will add a null \0 to buffer array,so if the user input more data then the buffer size that is 0-8+Null over or above the data cause buffer overflow, here scanf is vulnerable
        printf("You entered : %s\n", buffer); // This will print the string saved in the buffer array
        printf("Inside b array: %s\n", b); // This will print the string saved in the buffer array
        printf("Buffer (After b array): %s\n", buffer); // This printf is to show what will be there in buffer array after it overflowed b array

        return 0;
        //Program Exexution
        /*╭─ 💁 n.sivashankar2002 at 💻 essentials in 📁 ~/gcc3
          ╰λ ./Buffer-Assignment
          Enter a string: Mani
          You entered: Mani   //Here i first entered 4 characters Mani the program is normal here, it will not overflow the buffer because the entered data is less than the buffer size and it will not overwrite array b also.
          Inside b array:   // There is no characters in b array because no data is assigned to it, it printed as it is.
          Buffer (After b array): Mani */  // Here also normal because the entered data is less than the buffer size.
        //Program Execution
        /*╭─ 💁 n.sivashankar2002 at 💻 essentials in 📁 ~/gcc3
          ╰λ ./Buffer-Assignment
          Enter a string: ManikandanNagaraj //Here i entered 17 characters ManikandanNagaraj the program is overflowed the buffer because the entered data is more than the buffer size and it will overwrite array b also.
          You entered: ManikandanNagaraj // Here buffer doesn't encoundered /0 null or new line characters so it will write the overflowed data in the adjacent memory b.
          Inside b array: Nagaraj    // The overflowed characters in array b 
          Buffer (After b array): ManikandanNagaraj */ // Here the overflowed data is still in the buffer array because it encountered null character after Nagaraj it stays in buffer array the buffer and b will be corruupted or collapsed.*/