#include <stdio.h>
#include <stdlib.h>


char amino_acids[] = "ACGTTTGCACGGGGTCAACG";

void generate_protein(char *sequence, int length) {
    int amino_len = strlen(amino_acids);
    for (int i = 0; i < length; i++) {
        sequence[i] = amino_acids[rand() % amino_len];
    }
    sequence[length] = '\0';
}


void set_watermark(char *sequence, char *watermark, int position) {
    int watermark_len = strlen(watermark);


    if (position + watermark_len <= strlen(sequence)) {
        strncpy(&sequence[position], watermark, watermark_len);
    } else {
        printf("Watermark position is out of bounds!\n");
    }
}

int detect_watermark(char *sequence, char *watermark) {
    return strstr(sequence, watermark) != NULL;
}


int main() {
    srand(time(NULL));

    int length = 10;
    char sequence[50];
    char watermark[] = "ATTCG";

    generate_protein(sequence, length);
    printf("Original Protein: %s\n", sequence);


