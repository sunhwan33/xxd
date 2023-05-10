#include <stdio.h>
#include <ctype.h>
#include <string.h>

void text_to_bin(const char*  textfile, const char*  binaryfile){
    //TODO
    FILE* input = fopen(textfile, "r");
    if (input == NULL) {
        perror("Unable to open the text file.\n");
        return;
    }
    FILE* tmpoutput; 
    char ch;
    tmpoutput = tmpfile();
     if (tmpoutput == NULL) {
        perror("Unable to create a temporary binary file.\n");
        fclose(input);
        return;
    }
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch, tmpoutput);
    }
    // Rewind the temporary binary file
    rewind(tmpoutput);

    FILE *output = fopen(binaryfile, "wb");
    if (output == NULL) {
        perror("Unable to create the binary file.\n");
        fclose(input);
        fclose(tmpoutput);
        return;
    }
    while ((ch = fgetc(tmpoutput)) != EOF) {
        fputc(ch, output);
    }

    fclose(input);
    fclose(tmpoutput);
    fclose(output);


}
void bin_to_text(const char* binaryfile, const char* textfile){
    //TODO
    FILE* input = fopen(binaryfile, "rb");
    FILE* output = fopen(textfile, "w");
    if (input == NULL || output == NULL) {
        perror("Unable to open the file");
        return;
    }
    int count = 0;
    int offset=0;
    char asciiSymbols[17];
   unsigned char byte;
    while (fread(&byte, sizeof(byte), 1, input) == 1) {
        
        if (count % 8 == 0) {
            fprintf(output, "%08X: ", offset);
        }
        fprintf(output, "%02X%02X  ", byte, byte);//fprintf(output, "%04X ", byte); // 바이너리 값을 16진수 형식의 텍스트로 출력
        
       
        asciiSymbols[count % 16] = (isprint(byte) ? byte : '.');

        count++;
        offset++;
        // Print a new line after every 16 bytes
        if (count % 8 == 0) {
            
            asciiSymbols[16] = '\0'; // Null-terminate the array
            fprintf(output, "%s\n", asciiSymbols);
        
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    
    const char* textFile;
    const char* binaryFile;
    if (strcmp(argv[1], "-r") == 0){
        textFile = argv[2];
        if (strcmp(argv[3], "-o") == 0)
            binaryFile = argv[4]; // 커맨드 라인에서 받은 바이너리 파일 경로
        else 
            binaryFile = argv[3];
        text_to_bin(textFile, binaryFile);
    }
    else{
        binaryFile = argv[1]; // 커맨드 라인에서 받은 바이너리 파일 경로
        textFile = argv[2];
        bin_to_text(binaryFile, textFile);
    }

    
    return 0 ;
}

/*
i'm watching these videos right now, they might help maybe you can watch them too
1) Reading from binary files https://youtu.be/dDjfaA9Q3n8
2) Writing to binary files https://youtu.be/P-fWNCF7Wx8
3) Converting Word into Binary https://youtu.be/HcpnXo40L54
4) Read and Write a file in binary https://youtu.be/ogscYkB_8Ak
*/
