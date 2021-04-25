/**
 * @headerfile operations.h
 */
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "stack.h"
#include "logic.h"

/**
 * \brief Array com todas as operações implementadas
 */
#define OPERATION_MAP {{" ", SemArgumentos}, \
                {";", DecrementaSP}, \
                {"_", Underscore},\
                {"\\", Swap},\
                {"@", SwapThree},\
                {"$", DollarSign},\
                {"l", ReadLine},            \
                {"?", ifThenElse},           \
                {" ", UmArgumento},          \
                {"!", notLG},\
                {"(", decre},\
                {")", incre},\
                {"~", notBW},\
                {"c", DataToCHAR},\
                {"i", DataToLONG},\
                {"f", DataToDOUBLE},\
                {" ", DoisArgumentos},   \
                {"e<", LesserBetweenTwo},   \
                {"e>", GreaterBetweenTwo},  \
                {"e&", andWithShortcut},     \
                {"e|", orWithShortcut},      \
                {"=", equals},               \
                {"<", lesser},               \
                {">", greater},\
                {"+", soma},\
                {"-", subtr},\
                {"*", mult},\
                {"/", divi},\
                {"%", modulo},\
                {"#", potencia},\
                {"&", and},\
                {"|", or},\
                {"^", xor},\
                {0, NULL} \
                }

/**
 * \brief Definição do tamanho máximo da line de input.
 */
#define MAX_LENGTH_INPUT 10240

/**
 * \brief Tipo de dados que funciona como apontador para uma função operação.
 */
typedef void (*Operation)();

/**
 * \brief Tipo de dados que armazena um simbolo (tipo char) e uma função operação (Operation).
 */
typedef struct {
    /** char responsável pela identificação da operação*/
    char *simbolo;
    /** Apontador para uma função*/
    Operation op;
}OperationMap;

void DoisArgumentos(Operation operation, Stack *stack);
void UmArgumento(Operation operation, Stack *stack);
void SemArgumentos(Operation operation, Stack *stack);

/** 
 * \brief Macro que assiste na declaração das Funções CreateOpAlgebrica.
 */
#define CreateOpAlgebricaProto(_name) \
void _name(Data *d1, Data *d2);

/** \brief Declaração da função soma.*/
CreateOpAlgebricaProto(soma)
/** \brief Declaração da função subtr.*/
CreateOpAlgebricaProto(subtr)
/** \brief Declaração da função mult.*/
CreateOpAlgebricaProto(mult)
/** \brief Declaração da função divi.*/
CreateOpAlgebricaProto(divi)

/** 
 * \brief Macro que assiste na declaração das Funções CreateOpIncremento.
 */
#define CreateOpIncrementoProto(_name) \
void _name(Data *d1);

/** \brief Declaração da função incre.*/
CreateOpIncrementoProto(incre)
/** \brief Declaração da função decre.*/
CreateOpIncrementoProto(decre)

/** 
 *  \brief Macro que assiste na declaração das Funções CreateOpBitwise.
 */
#define CreateOpBitwiseProto(_name) \
void _name(Data *d1, Data *d2);

/** \brief Declaração da função and.*/
CreateOpBitwiseProto(and)
/** \brief Declaração da função or.*/
CreateOpBitwiseProto(or)
/** \brief Declaração da função xor.*/
CreateOpBitwiseProto(xor)
/** \brief Declaração da função modulo.*/
CreateOpBitwiseProto(modulo)

void notBW(Data *d);
void potencia(Data *d1, Data *d2);


/*Funções sem Macros coitadinhas*/
void Underscore(Stack *stack);
void Swap(Stack *stack);
void SwapThree(Stack *stack);
void DollarSign(Stack *stack);
void ReadLine(Stack *stack);

#endif