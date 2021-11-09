#include <stdio.h>
#include <string.h>
#define BUF_SIZE 128

void trim(char *string) {
    int s = strlen(string);
    if (string[s - 1] == '\n') {
        string[s - 1] = 0;
    }
}

// defining simple addiditon operator
int add(int a, int b) {
    return a + b;
}

// defining simple multiplication operator
int mult(int a, int b) {
    return a * b;
}
//v return value of output function pointer
int (*choose_op(char *c))(int, int) {
//    ^fn name  ^input    ^input type(s) (like decleration) of function  
//                         pointed to by this function's output 
    if (!strcmp(c, "add")) {
        return add; // Function would return (*add)(int, int), the pointer to 
    } else if (!strcmp(c, "mult")) {
        return mult;
    } else {
        return NULL;
    }
}

int main() {
    char operator[BUF_SIZE] = { 0 };
    int a = 0, b = 0;

    printf("Enter the operator: ");
    fgets(operator, BUF_SIZE, stdin);
    trim(operator);

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int (*op)(int, int) = choose_op(operator);

    if (op == NULL) {
        printf("Invalid operator\n");
        return 1;
    }

    int op_result = op(a, b);

    printf("op(%d, %d) = %d\n", a, b, op_result);

    return 0;
}