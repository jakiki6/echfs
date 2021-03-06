#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESERVED_BLOCKS         16

char boot_sector[] = {
  0xeb, 0x22, 0x90, 0x90, 0x5f, 0x45, 0x43, 0x48, 0x5f, 0x46, 0x53, 0x5f,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0e, 0x1f, 0x0e, 0x07, 0xbe, 0x40, 0x7c, 0xb4, 0x0e, 0xb9, 0x01, 0x00,
  0xbb, 0x0e, 0x00, 0xac, 0x84, 0xc0, 0x74, 0x04, 0xcd, 0x10, 0xeb, 0xf7,
  0xfa, 0xf4, 0xeb, 0xfc, 0x4e, 0x6f, 0x74, 0x20, 0x61, 0x20, 0x62, 0x6f,
  0x6f, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x56, 0x42, 0x52, 0x2e, 0x20,
  0x54, 0x68, 0x69, 0x73, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x65, 0x63,
  0x68, 0x69, 0x64, 0x6e, 0x61, 0x46, 0x53, 0x20, 0x70, 0x61, 0x72, 0x74,
  0x69, 0x74, 0x69, 0x6f, 0x6e, 0x21, 0x0a, 0x0d, 0x00, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x55, 0xaa
};

static FILE * image;

static inline void wr_qword(uint64_t loc, uint64_t x) {
    fseek(image, (long)loc, SEEK_SET);
    fwrite(&x, 8, 1, image);
    return;
}

int main(int argc, char **argv) {
    if (argc < 4) {
          fprintf(stderr, "%s: usage: %s <image> <bytes per block> <reserved blocks factor>\n", argv[0], argv[0]);
          return 1;
    }
    image = fopen(argv[1], "rb");
    if (image == NULL) {
         fprintf(stderr, "%s: error: no valid image specified.\n", argv[0]);
    }

    fseek(image, 0L, SEEK_END);
    uint64_t imgsize = (uint64_t)ftell(image);
    rewind(image);
    fclose(image);
    image = fopen(argv[1], "r+");

    fprintf(stderr, "%s: info: formatting %lu bytes...\n", argv[0], imgsize);

    uint64_t bytesperblock = atoi(argv[2]);

    if ((bytesperblock <= 0) || (bytesperblock % 512)) {
        fprintf(stderr, "%s: error: block size MUST be a multiple of 512.\n", argv[0]);
        fclose(image);
        return 1;
    }

    if (imgsize % bytesperblock) {
        fprintf(stderr, "%s: error: image is not block-aligned.\n", argv[0]);
        fclose(image);
        return 1;
    }

    uint64_t reserved_factor = atoi(argv[3]);

    if ((reserved_factor <= 0) || (reserved_factor >= 100)) {
        fprintf(stderr, "%s: error: reserved blocks factor must be between 1%% and 99%%\n", argv[0]);
        fclose(image);
        return 1;
    }

    uint64_t blocks = imgsize / bytesperblock;

    fseek(image, 0, SEEK_SET);
    fwrite(&boot_sector, 512, 1, image);

    fseek(image, 4, SEEK_SET);
    fputs("_ECH_FS_", image);
    wr_qword(12, blocks);	// blocks
    wr_qword(20, blocks / (100 / reserved_factor)); 	//reserved blocks
    wr_qword(28, bytesperblock);	// block size
    // mark reserved blocks
    uint64_t loc = RESERVED_BLOCKS * bytesperblock;

    uint64_t fatsize = (blocks * sizeof(uint64_t)) / bytesperblock;
    uint64_t dirsize = blocks / (100 / reserved_factor);

    for (uint64_t i = 0; i < (RESERVED_BLOCKS + fatsize + dirsize); i++) {
        wr_qword(loc, 0xfffffffffffffff0);
        loc += sizeof(uint64_t);
    }
    fflush(image);
    fclose(image);
    return 0;
}
