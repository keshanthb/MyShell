#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Inspect the archive file with hexdump -C csc209L4Archive.csc209 | more

Each file follows the same structure
- A header containing "csc209.Archive"
- One integer specifying the number of files
- One long for each file specifying the file size
- One string, max strlen is 64, specifying the archived file name
- The file contents in the order in which the files are listed.
*/


void unarchive(int argc, char**argv) {
  // open file in rb mode (csc209L4Archive.csc209)
  FILE * f = fopen("csc209L4Archive.csc209", "rb");

  // skip past the header "CSC209.Archive"

  // determine how many files there are
  int num_files = 0;
  printf("%d, files in the archive\n", num_files); 

  // determine the file sizes for each file in the archive  
  long sizes[num_files];
 
  // determine the file names 
  char tmp[65*num_files];
  
  for (int i = 0; i < num_files; i++) {
    printf("File %i is called %s and has size %lu\n", i, tmp, sizes[i]);
  }
 

  // Exract the contents and write them to new files. 
  for (int i = 0; i < num_files; i++) {
    char name[70] = {'c','s','c'};
    FILE * out = fopen(strcat(name, &tmp[i*65]), "wr");
    printf("now extracting %s to %s with %lu size\n", &tmp[i*65], name, sizes[i]);
    
    // TODO

    fclose(out);
  }
    
}

int main(int argc, char ** argv) {
    unarchive(argc, argv);
    return EXIT_SUCCESS;


}
