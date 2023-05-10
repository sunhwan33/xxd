#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {
    //FILE * fp = fopen(argv[1], "r");
    //fseek(fp, 0, SEEK_END) ;
    FILE * in;
    //fopen_s(&in, argv[1], "rb");
    fopen_s(&in, "a.out", "rb");
    if (in == NULL) return 3;

    char buffer[1024];
    fread_s(buffer, sizeof(buffer), sizeof(buffer), 1, in);

    return 0 ;
}

/*
i'm watching these videos right now, they might help maybe you can watch them too
1) Reading from binary files https://youtu.be/dDjfaA9Q3n8
2) Writing to binary files https://youtu.be/P-fWNCF7Wx8
3) Converting Word into Binary https://youtu.be/HcpnXo40L54
4) Read and Write a file in binary https://youtu.be/ogscYkB_8Ak
*/
