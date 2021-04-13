
/**
 * @file
 * Ficheiro que diz respeito ao interpretador.
 * Contém a função parse() que serve como interpretador.
 */
#include "parser.h"

/**
 * \brief Função que interpreta o input e altera a stack segundo esse input.
 *
 * @param input String com o \a input.
 * @param stack Endereço da \a stack responsável pelo armazenamento.
 */
void parse(char *input, Stack *stack){
	char *delims = " \t\n";
	for(char *token = strtok(input, delims); token != NULL; token = strtok(NULL, delims)){
		char *resto;
		/* Testar se o valor introduzido é do tipo long. */
		long vall = strtol(token, &resto, 10);

		if(strlen(resto) == 0){
			Push(CreateDataLONG(vall), stack);
		} else {
		    /* Testar se o resto contém um double decimal e somar à parte inteira. */
		    double vald = strtod(resto, &resto);
		    
            if (vall < 0) vald = vall - vald;
		    else vald += vall;

		    if (strlen(resto) ==  0) {
                    Push(CreateDataDOUBLE(vald), stack);
		    } else {
                if(strlen(token)==1) {
                    switch (token[0]) {
                        case '+': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            soma(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '-': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            subtr(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '*': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            mult(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '/': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            divi(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '(': {
                            Data x = Pop(stack);
                            decre(&x);
                            Push(x, stack);
                            break;
                        }
                        case ')': {
                            Data x = Pop(stack);
                            incre(&x);
                            Push(x, stack);
                            break;
                        }
                        case '%': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            modulo(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '#': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            potencia(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '&': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            and(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '|': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            or(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '^': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            xor(&x, &y);
                            Push(y, stack);
                            free(x.value);
                            break;
                        }
                        case '~': {
                            Data x = Pop(stack);
                            not(&x);
                            Push(x, stack);
                            break;
                        }
                        case ';': {
                            Pop(stack);
                            break;
                        }
                        case '_': {
                            Data *x = Read(0, stack);
                            Data y = DataDup(x);
                            Push(y, stack);
                            break;
                        }
                        case '\\': {
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            Push(y, stack);
                            Push(x, stack);
                            break;
                        }
                        case '@': {
                            Data z = Pop(stack);
                            Data y = Pop(stack);
                            Data x = Pop(stack);
                            Push(y, stack);
                            Push(z, stack);
                            Push(x, stack);
                            break;
                        }
                        case '$': {
                            Data indice = Pop(stack);
                            long deslocamento = *DataValLONG(&indice);
                            Data *x = Read(deslocamento, stack);
                            Data y = DataDup(x);
                            Push(y, stack);
                            free(indice.value);
                            break;
                        }
                        case 'c': {
                            Data x = Pop(stack);
                            DataToLONG(&x);
                            x.tipo = CHAR;
                            Push(x, stack);
                            break;
                        }
                        case 'l': {
                            char linha[MAX_LENGTH_INPUT];
                            assert(fgets(linha, MAX_LENGTH_INPUT, stdin) != NULL);
                            assert(linha[strlen(linha) - 1] == '\n');
                            Push(CreateDataSTRING(linha), stack);
                            break;
                        }
                        case 'i': {
                            Data x = Pop(stack);
                            DataToLONG(&x);
                            Push(x, stack);
                            break;
                        }
                        case 'f':{
                            Data x = Pop(stack);
                            DataToDOUBLE(&x);
                            Push(x, stack);
                            break;
                        }
                    }
                }
		    }
		}
	}
	PrintStack(stack);
}
