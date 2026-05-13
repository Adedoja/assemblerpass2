#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct symbol_linked_list {
        char name[7];
        int address;
        int sourceline;
        struct symbol_linked_list *next;
};

typedef struct symbol_linked_list SYMBOL;
typedef SYMBOL *SYMTAB;
extern unsigned char EBCDIC_to_ASCII[256];
SYMTAB InsertSymbol( SYMTAB table, char name[7], int addr, int srcline );
void PrintSymbols( SYMTAB table );
extern void Destroy( SYMTAB table );
int SymbolExists( SYMTAB table, char name[7]);
int checkForFormat(char *opcode);
int checkForOperand(SYMTAB MysymbolTable, char *operand);
int offsetbit(int addr);
int stringwithacomma(char *operand);
void convertToUpper(char *word);
long Convert(const char *operand,int base , int lineNumber, const char*opcode);
int Tokenizer(char *line,char *label,char *opcode,char *operand);
void converttoO(char *opcode, char *operand, char *objectCode);
int pass1(FILE *fp, FILE *file,SYMTAB *MySymbolTable );
int pass2(FILE *file, FILE *object, SYMTAB MySymbolTable, int proglength);
char *getOpcodeValue(char *OPTAB);
void trimTrailing(char *s);
int isDirective(const char *opcode);
void appendObject(char *textRec, int *textLength, int *textStart,FILE *objectc, int currentAddr,const char *obj, int objLength);
#endif
