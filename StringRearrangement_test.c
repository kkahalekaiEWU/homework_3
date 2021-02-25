#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char *s[], int count);
void printArray(char *s[], int count);
void swapStrings(char** a, char** b);
int main(){

        int i;
        char buff[BUFSIZ];

        int count;
       // 's' is a pointer to a char pointer, initially 's' is allocated storage for one char pointer
        char** s= malloc(sizeof(char*));
        
        printf("Here is the list of unsorted names: \n\n");

        // Keep on reading unlimited number of names until EOF (Ctrl + D) is reached
        for (count = 0; fgets(buff, sizeof(buff), stdin); count++){
            //Step 1: allocate sufficient storage for s[count] to store the content in buff plus one byte for '\0'
            s[count] =  malloc(strlen(buff)+1);
            // Step 2: Copy into the allocated memory
            strcpy(s[count], buff);
            //Step 3: resize the array of pointers pointed to by 's' to increase its size for the next pointer
            s = realloc(s, sizeof (char*)*(count+2));
            }



       // EOF reached. Now count the number of strings read

        printf("\nCount is %d\n\n", count);

       // Now sort string using sortString function
       // Step 4: implement sortString function for the above-mentioned function declaration
       sortString(s, count);

       // Step 5: print the list of sorted names.
       printArray(s, count);
       // Step 6:free the allocated memory.
       free(s);

        return 0;
}

void sortString(char *s[], int count){

    if(s == NULL || count == 0){
        return;
    }

    for (int i = 0; i < count; i++){
        for (int j =  i+1; j < count; j++){
            if(strcmp(&*s[i], &*s[j]) > 0) {
                swapStrings(&s[i], &s[j]);
            }
        }
    }

}
void swapStrings(char** a, char** b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(char *s[], int count){
    printf("Here is the list of sorted names: \n");
    for(int i = 0; i < count; i++){
        printf("%s", s[i]);
    }
}


