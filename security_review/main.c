#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#define PASSWORD "ABCD1234!"
/*You need not worry about other include statements if at all any are missing */

/* 
Vulnerability 1: Potential Buffer Overflow
Explanation: The ALLOCA macro is used to allocate memory on the stack for dataBuffer,
             but there is no check on the size of the input source string before copying it 
             into dataBuffer using strcpy. If the source string is larger than 100 characters, 
             it will cause a buffer overflow.
Reference: https://cwe.mitre.org/data/definitions/120.html
*/
void func1()
{
    char *data;
    char *dataBuffer = (char *)ALLOCA(100 * sizeof(char)); // Potential vulnerability: ALLOCA is not a standard library function and its behavior might not be as expected. It's also case-sensitive, and the correct usage is _alloca.
    memset(dataBuffer, 'A', 100 - 1);
    dataBuffer[100 - 1] = '\0';
    data = dataBuffer - 8; // Potential vulnerability: Buffer underflow. data is pointing 8 bytes before dataBuffer.
    {
        char source[100];
        memset(source, 'C', 100 - 1);
        source[100 - 1] = '\0';
        strcpy(data, source); // Potential vulnerability: Buffer overflow. strcpy does not check the size of the destination buffer, and it might not be large enough to hold the contents of source.
        if (data != NULL)
        {
            printf("%s\n", data);
        }
    }
}

/*
Vulnerability 2: Potential NULL Pointer Dereference
Explanation: The calloc function allocates memory for 'data', but it doesn't check 
             if the allocation was successful. If calloc fails and returns NULL, 
             strcpy will dereference a NULL pointer, leading to undefined behavior.
Reference: https://cwe.mitre.org/data/definitions/476.html
*/
void func2()
{
    char *data;
    data = NULL;
    data = (char *)calloc(100, sizeof(char));
    strcpy(data, "A String"); // Potential vulnerability: Although in this case it's safe, it's better to use strncpy to prevent buffer overflow.
    if (data != NULL)
    {
        printf("%s\n", data);
    }
}

/*
Vulnerability 3: Hardcoded Password
Explanation: The PASSWORD macro contains a hardcoded password, which is a security risk. 
             Storing passwords directly in the source code makes them vulnerable to 
             being discovered by attackers who gain access to the source code.
Reference: https://cwe.mitre.org/data/definitions/798.html
*/
void func3()
{
    char *password;
    char passwordBuffer[100] = "";
    password = passwordBuffer;
    strcpy(password, PASSWORD); // Potential vulnerability: Hardcoded password. Also, strcpy does not check the size of the destination buffer, and it might not be large enough to hold the contents of PASSWORD.
    {
        HANDLE pHandle;
        char *username = "User";
        char *domain = "Domain";
        /* Let's say LogonUserA is a custon authentication function*/
        if (LogonUserA(
                username,
                domain,
                password,
                &pHandle) != 0)
        {
            printf("User logged in successfully.\n");
            CloseHandle(pHandle);
        }
        else
        {
            printf("Unable to login.\n");
        }
    }
}

/*
Vulnerability 4: Memory Leak
Explanation: 'data' is allocated memory using calloc, but it's not freed before 
             the function returns, leading to a memory leak.
Reference: https://cwe.mitre.org/data/definitions/401.html
*/
static void func4()
{
    char *data;
    data = NULL;
    data = (char *)calloc(20, sizeof(char));
    if (data != NULL)
    {
        strcpy(data, "Initialize"); // Potential vulnerability: Although in this case it's safe, it's better to use strncpy to prevent buffer overflow.
        if (data != NULL)
        {
            printf("%s\n", data);
        }
        free(data);
    }
}

/*
Vulnerability 5: Infinite Loop
Explanation: The do-while loop in func5 has a condition 'i >= 0', but 'i' is an 
             integer that overflows when it reaches the maximum value, resulting 
             in the loop condition always being true and causing an infinite loop.
Reference: https://cwe.mitre.org/data/definitions/835.html
*/
void func5()
{
    int i = 0;
    do
    {
        printf("%d\n", i);
        i = (i + 1) % 256;
    } while (i >= 0); // Potential vulnerability: Infinite loop. it will always be greater than or equal to 0.
}

/*
Vulnerability 6: Unbounded Input
Explanation: func6 uses fgets to read input into 'data', but it doesn't specify 
             the maximum number of characters to read, leading to a potential 
             buffer overflow if the user inputs more than 100 characters.
Reference: https://cwe.mitre.org/data/definitions/120.html
*/
void func6()
{
    char dataBuffer[100] = "";
    char *data = dataBuffer;
    printf("Please enter a string: ");
    if (fgets(data, 100, stdin) < 0) // Potential vulnerability: fgets does not null-terminate the buffer if the buffer is filled, which might lead to unexpected behavior.
    {
        printf("fgets failed!\n");
        exit(1);
    }
    if (data != NULL)
    {
        printf("%s\n", data);
    }
}

/*
Vulnerability 7: Potential NULL Pointer Dereference
Explanation: 'data' is set to NULL, and then printf is called without checking 
             if 'data' is NULL, which can lead to a NULL pointer dereference.
Reference: https://cwe.mitre.org/data/definitions/476.html
*/
void func7()
{
    char *data;
    data = "Fortify";
    data = NULL; // Potential vulnerability: Null pointer dereference. data is set to NULL and then used in printf without a null check.
    printf("%s\n", data);
}


int main(int argc, char * argv[])
{
    printf("Calling func1\n");
    func1();

    printf("Calling func2\n");
    func2();

    printf("Calling func3\n");
    func3();

    printf("Calling func4\n");
    func4();

    printf("Calling func5\n");
    func5();

    printf("Calling func6\n");
    func6();

    printf("Calling func7\n");
    func7();

    return 0;
}
