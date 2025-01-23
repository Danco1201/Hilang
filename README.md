# Hilang
A toy esoteric language

## Índice
- [Instalación y Compilación](#instalación-y-compilación)
- [Ejemplos](#ejemplos)
- [Instrucciones](#instrucciones)
- [Licencia](#licencia)

## Instalación y Compilación
Para compilar y ejecutar Hilang, necesitas tener instalado un compilador de C. Puedes usar `gcc` para compilar el intérprete.

```sh
gcc -o hilang interpreter.c
```
Para ejecutar un archivo:

```sh
./hilang <archivo>.hi
```
Para ejecutar una instruccion:
```sh
./hilang hola, hi, hallo, bonjour, bye
```
## Ejemplos
Aquí hay algunos ejemplos de programas en Hilang:
*Hola Mundo:*
```hi
hola, hola, hola, hola,    
bonjour,                  
hello, hello,              
hola, hola, hola,        
bonjour,                  
hello, hello,              
hola, hola,                
bonjour,                  
hello, hello,              
hola,                     
bonjour,                 
hello, hello,             
hola,                      
bonjour,                   
hello, hello,             
hola, hola, hola,          
bonjour,                  
hello, hello,              
hola, hola, hola,          
bonjour,                  
hello, hello,              
hola, hola, hola,          
bonjour,                   
hello, hello,             
hola, hola,               
bonjour,                   
hello, hello,             
hola, hola, hola,          
bonjour,                  
bye                        

```
*Fibbonaci:*
```hi
hola, hola,    
hola,          
hola,            

[salve x < 10],    
    hallo,      
    bonjour,    
    hello,       
    hola,        
    hello,
bye
```    
## Instrucciones
Hilang soporta las siguientes instrucciones:

- `hi`: Mueve el puntero de memoria a la izquierda.
- `hello`: Mueve el puntero de memoria a la derecha.
- `hey`: Libera el puntero.
- `hola`: Incrementa el valor en la posición de memoria actual.
- `hallo`: Decrementa el valor en la posición de memoria actual.
- `bonjour`: Imprime el carácter correspondiente al valor en la posición de memoria actual.
- `[salve <condición>]`: Ejecuta un bucle mientras la condición sea verdadera. Actualmente, la condición es que el valor en la posición de memoria actual no sea cero.
- `bye`: Termina la ejecución del programa.
- (Proximamente) `[funcion operador operacion]`: Crea una funcion lambda con una de las operaciones aritmeticas. Ejemplo: `[x + 2 3]`

## Licencia
Este lenguaje de programacion sigue la licensia MIT. Vea el archivo LICENSE para mas informacion
