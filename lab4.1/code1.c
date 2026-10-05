#include <stdio.h>

// 1. Data Section: Initialized global variable
int data_global_var = 0x12345678;

// 2. Read-Only Data Section: String literal
const char *text_string_literal = "Text_Segment_Verification";

// 3. Text Section: Function code
void check_execution() {
    printf("Executing within the text segment instruction block.\n");
}

int main() {
    printf("Addresses:\n");

    // Address of initialized global variable (.data)
    printf("Data (Global Initialized): %p\n",
           (void *)&data_global_var);

    // Address of string literal (.rodata)
    printf("Read-Only Data (String): %p\n",
           (void *)text_string_literal);

    // Address of function (.text)
    printf("Text Code (Function): %p\n",
           (void *)&check_execution);

    // Execute function from the text segment
    check_execution();

    // Point to inspect memory segments using a debugger
    printf("Ready for Text/Data segment inspection!\n");

    return 0;
}
