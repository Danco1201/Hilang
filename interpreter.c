#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEMORY_SIZE 30000

typedef struct {
    char name[50];
    void (*func)(int*, int*);
} function;

void move_left(int* pointer) {
    (*pointer)--;
}

void move_right(int* pointer) {
    (*pointer)++;
}

void increment_memory(int* memory, int pointer) {
    memory[pointer]++;
}

void decrement_memory(int* memory, int pointer) {
    memory[pointer]--;
}

void repl(int* memory, int pointer) {
    printf("%c", memory[pointer]);
}

void input(int* memory, int pointer) {
    char c = getchar();
    memory[pointer] = c;
}

void reset_memory(int* memory, int pointer) {
    memory[pointer] = 0;
}

void jump_to_start(int* pointer) {
    *pointer = 0;
}

int condition(int* memory, int pointer) {
    return memory[pointer] != 0; 
}

void interpret(const char* code) {
    int memory[MEMORY_SIZE] = {0};
    int pointer = 0;

    const char* delimiter = ",";
    char* code_copy = strdup(code);
    char* instruction = strtok(code_copy, delimiter);

    while (instruction != NULL) {
        while (*instruction == ' ') instruction++;  // Ignorar espacios al inicio

        if (strcmp(instruction, "bye") == 0) {
            break;
        } else if (strstr(instruction, "[salve") != NULL) {
            char loop_body[200];
            if (sscanf(instruction, "[salve %199[^]]", loop_body) == 1) {
                char* inner_instruction;
                do {
                    char* body_copy = strdup(loop_body);
                    inner_instruction = strtok(body_copy, delimiter);
                    while (inner_instruction != NULL) {
                        while (*inner_instruction == ' ') inner_instruction++; // Ignorar espacios

                        if (strcmp(inner_instruction, "hi") == 0) {
                            move_left(&pointer);
                        } else if (strcmp(inner_instruction, "hello") == 0) {
                            move_right(&pointer);
                        } else if (strcmp(inner_instruction, "hola") == 0) {
                            increment_memory(memory, pointer);
                        } else if (strcmp(inner_instruction, "hallo") == 0) {
                            decrement_memory(memory, pointer);
                        } else if (strcmp(inner_instruction, "bonjour") == 0) {
                            repl(memory, pointer);
                        } else if (strcmp(inner_instruction, "ciao") == 0) {
                            input(memory, pointer);
                        } else if (strcmp(inner_instruction, "privet") == 0) {
                            reset_memory(memory, pointer);
                        } else if (strcmp(inner_instruction, "ola") == 0) {
                            jump_to_start(&pointer);
                        } else {
                            printf("unknown command in loop: %s\n", inner_instruction);
                        }

                        inner_instruction = strtok(NULL, delimiter);
                    }
                    free(body_copy);
                } while (condition(memory, pointer));
            }
        } else {
            if (strcmp(instruction, "hi") == 0) {
                move_left(&pointer);
            } else if (strcmp(instruction, "hello") == 0) {
                move_right(&pointer);
            } else if (strcmp(instruction, "hola") == 0) {
                increment_memory(memory, pointer);
            } else if (strcmp(instruction, "hallo") == 0) {
                decrement_memory(memory, pointer);
            } else if (strcmp(instruction, "bonjour") == 0) {
                repl(memory, pointer);
            } else if (strcmp(instruction, "ciao") == 0) {
                input(memory, pointer);
            } else if (strcmp(instruction, "privet") == 0) {
                reset_memory(memory, pointer);
            } else if (strcmp(instruction, "ola") == 0) {
                jump_to_start(&pointer);
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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Uso: %s <archivo.hi> o <instrucciones>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        fileread(argv[1]);
    } else {
        interpret(argv[1]);
    }

    return 0;
}
