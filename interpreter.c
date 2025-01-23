#include <stdio.h>
#include <string.h>

#define MEMORY_SIZE 30000

void move_left(int* pointer) {
    (*pointer)--;
}

void move_right(int* pointer) {
    (*pointer)++;
}

void release_pointer() {}

void increment_memory(int* memory, int pointer) {
    memory[pointer]++;
}

void decrement_memory(int* memory, int pointer) {
    memory[pointer]--;
}

void read_and_print(int* memory, int pointer) {
    printf("%c", memory[pointer]);
}

void interpret(const char* code) {
    int memory[MEMORY_SIZE] = {0};
    int pointer = 0;

    char command[50];
    const char* delimiter = ",";

    char* code_copy = strdup(code);
    char* instruction = strtok(code_copy, delimiter);

    while (instruction != NULL) {
        while (*instruction == ' ') instruction++;  
        if (strcmp(instruction, "bye") == 0) {
            break;
        } else if (strchr(instruction, '[')) {
            // Manejo de funciones (vacío por ahora)
        } else {
            if (strcmp(instruction, "hi") == 0) {
                move_left(&pointer);
            } else if (strcmp(instruction, "hello") == 0) {
                move_right(&pointer);
            } else if (strcmp(instruction, "hey") == 0) {
                release_pointer();
            } else if (strcmp(instruction, "hola") == 0) {
                increment_memory(memory, pointer);
            } else if (strcmp(instruction, "hallo") == 0) {
                decrement_memory(memory, pointer);
            } else if (strcmp(instruction, "bonjour") == 0) {
                read_and_print(memory, pointer);
            } else {
                printf("unknown command: %s\n", instruction);
            }
        }

        instruction = strtok(NULL, delimiter);
    }

    free(code_copy);
}
void fileread(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* code = (char*)malloc(file_size + 1);
    fread(code, 1, file_size, file);
    code[file_size] = '\0';

    fclose(file);

    interpret(code);

    free(code);
}

int main() {
    const char* filename = "codigo.hi";
    fileread(filename);
    return 0;
}
