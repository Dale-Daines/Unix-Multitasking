//Dale Daines - 16998416 - Assignment 2 - Systems Programming 1
#include <stdlib.h>
#include <stdio.h>

//Calculate the average mark from keyboard input
void averageMark() {
	int total = 0;
	int i;
	printf("Please insert 20 marks.\n");
	//Loop 20 inputs
	for ( i = 0; i < 20; i++ ) {
		int number, result;
		result = scanf("%d", &number);
		
		//If cannot read from keyboard exit child
		if ( result == EOF ) {
			printf("Keyboard not reading");
			exit(EXIT_FAILURE);
		}
		//if not proper input (e.g. text)
		else if ( result == 0 ) {
			//read until next line in text
			while (fgetc(stdin) != '\n' ) {
				;
			}
			//reduce total by 1
			i--;
		}
		else {
			total = total + number;
		}
		
	}
	int average = total/20;
	
	printf("Average mark is: %d.\n", average);
	
	exit(EXIT_SUCCESS);
	
}

//Counts words in file
void wc(char argv[]) {
	char word[255];
	int count = 0;
	//Open file for reading
	FILE *file1 = fopen(argv, "r");
	
	//If file cannot open end child
	if ( file1 == NULL ) {
		printf("Cannot open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	//Increase count per each word
    while (fscanf(file1, " %254s", word) == 1) {
        count++;
	}
	fclose(file1);
	printf("There are %d words.\n", count);
	exit(EXIT_SUCCESS);
}

//Modify words in file
void modifyFile(char argv[]) {
	char study[5] = {'s','t','u','d','y'}, execute[7] = {'e','x','e','c','u','t','e'}, start[29] = { 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 't', 'h', 'e', ' ', 'u', 'p', 'd', 'a', 't', 'e', 'd', ' ', 'v', 'e', 'r', 's', 'i', 'o', 'n', '.', ' '};
	int character, i;
	
	//Open file for reading and test for successful opening
	FILE *file2 = fopen(argv, "r");
	if ( file2 == NULL ) {
		printf("Cannot open %s\n", argv);
		exit(EXIT_FAILURE);
	}
	
	//Open file for writing and test for successful opening
	FILE *temp = fopen("fTemp.txt", "w");
	if ( temp == NULL ) {
		printf("Failed to create fTemp");
		exit(EXIT_FAILURE);
	}
	
	//Insert "this is the updated version." at the beginning of the file
	for ( i = 0; i < 29; i++ ) {
		fputc( start[i], temp );
	}
	//Until the end of the file update text
	while ( (character = fgetc(file2)) != EOF ) {
		//if next word is run replace with execute
		if ( character == 'r' ) {
			if ( (character = fgetc(file2)) != EOF && character == 'u' ) {
				if ( (character = fgetc(file2)) != EOF && character == 'n' ) {
					for ( i = 0; i < 7; i++ ) {
						fputc( execute[i], temp );
					}
					continue;
				}
				//In case word is not run output characters up to this point
				else {
					fputc( 'r', temp );
					fputc( 'u', temp );
				}
			}
			else {
				fputc( 'r', temp );
			}
		}
		
		//if next word is examine, replace with study
		if ( character == 'e' ) {
			if ( (character = fgetc(file2)) != EOF && character == 'x' ) {
				if ( (character = fgetc(file2)) != EOF && character == 'a' ) {
					if ( (character = fgetc(file2)) != EOF && character == 'm' ) {
						if ( (character = fgetc(file2)) != EOF && character == 'i' ) {
							if ( (character = fgetc(file2)) != EOF && character == 'n' ) {
								if ( (character = fgetc(file2)) != EOF && character == 'e' ) {
									for ( i = 0; i < 5; i++ ) {
										fputc( study[i], temp );
									}
									continue;
								}
								//In case word is not examine output characters up to this point
								else {
									fputc( 'e', temp );
									fputc( 'x', temp );
									fputc( 'a', temp );
									fputc( 'm', temp );
									fputc( 'i', temp );
									fputc( 'n', temp );
								}
							}
							else {
								fputc( 'e', temp );
								fputc( 'x', temp );
								fputc( 'a', temp );
								fputc( 'm', temp );
								fputc( 'i', temp );
							}
						}
						else {
							fputc( 'e', temp );
							fputc( 'x', temp );
							fputc( 'a', temp );
							fputc( 'm', temp );
						}
					}
					else {
						fputc( 'e', temp );
						fputc( 'x', temp );
						fputc( 'a', temp );
					}
				}
				else {
					fputc( 'e', temp );
					fputc( 'x', temp );
				}
			}
			else {
				fputc( 'e', temp );
			}
		}
		
		//If neither "run" or "examine" put character in then continue
		fputc( character, temp );
		
	}
	
	//Close both files
	fclose(file2);
	fclose(temp);
	
	//Delete old read file
	if ( remove(argv) != 0 ) {
		printf("Error deleting %s\n", argv);
		exit(EXIT_FAILURE);
	}
	
	//Rename write file to read file
	if (rename("fTemp.txt", argv)  != 0 ) {
		printf("Error renaming fTemp.txt");
		exit(EXIT_FAILURE);
	}
	
	exit(EXIT_SUCCESS);
}

//Wait for children and output exit status
//Code from waitdemo2.c in Tutorial 8 with slight modification
void parent() {
	int wait_rv;		/* return value from wait() */
	int child_status;
	int high_8, low_7, bit_7;
	int i;
		
	wait_rv = wait(&child_status);
	printf("done waiting for %d\n", wait_rv);

	high_8 = child_status >> 8;     /* 1111 1111 0000 0000 */
	low_7  = child_status & 0x7F;   /* 0000 0000 0111 1111 */
	bit_7  = child_status & 0x80;   /* 0000 0000 1000 0000 */
	printf("status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7);
	
	wait_rv = wait(&child_status);
	printf("done waiting for %d\n", wait_rv);

	high_8 = child_status >> 8;     /* 1111 1111 0000 0000 */
	low_7  = child_status & 0x7F;   /* 0000 0000 0111 1111 */
	bit_7  = child_status & 0x80;   /* 0000 0000 1000 0000 */
	printf("status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7);
	
	wait_rv = wait(&child_status);
	printf("done waiting for %d\n", wait_rv);

	high_8 = child_status >> 8;     /* 1111 1111 0000 0000 */
	low_7  = child_status & 0x7F;   /* 0000 0000 0111 1111 */
	bit_7  = child_status & 0x80;   /* 0000 0000 1000 0000 */
	printf("status: exit=%d, sig=%d, core=%d\n", high_8, low_7, bit_7);
	
}


int main(int argc, char* argv[]) {
	int newpid;
	//Test all arguments are present
	if ( argc < 3 ) {
		printf("Please insert two arguments: ./<RUNNAME> <file1> <file2>\n");
		return 0;
	}
	
	//Create all children and assign relevant tasks
	if ( (newpid = fork()) == -1 )
		perror("fork");
	else if ( newpid == 0 ) {
		averageMark();
	}
	else {
		if ( (newpid = fork()) == -1 )
			perror("fork");
		else if ( newpid == 0 ) {
			wc(argv[1]);
		}
		else {
			if ( (newpid = fork()) == -1 )
				perror("fork");
			else if ( newpid == 0 ) {
				modifyFile(argv[2]);
			}
			else {
				parent();
			}
		}
		
	}
	
	return 0;
}
