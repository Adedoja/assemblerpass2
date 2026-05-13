#ifndef OPCODE_H
#define OPCODE_H

struct opcode {
        char mnemonic[10];
        int Format;

};
struct opcodeTable {
        char mnemonic[10];
        char code[3];
};


extern struct opcode directive[];
extern int DirectiveLength;
long Convert(const char *operand,int base, int lineNumber, const char*opcode);
int checkForFormat(char *opcode);
void convertToUpper(char *word);

#endif
