/* 
 * It is a short program of lexical analyzer.
 * It contains very few things just for learning.
 * It may cannot work in turbo c++, to make it work you need to add conio header and add getch() in main function.
 */

// Including header files.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// function to check if a stored word in buffer is keyword or not.
int isKeyword ( char buffer[] ) {

	int flag=0,i; // flag for is buffer contain keyword or not, and i for loop
	char keyword[32][10] = {"auto","break","case","char","continue","do","default","const","double","else","enum","extern","for","if","goto",
	                        "float","int","long","register","return","signed","static","sizeof","short","struct","switch","typedef","union",
	                        "void","while","volatile","unsigned"};  // list of keywords.
	for(i=0 ; i<32 ; i++){  // loop for checking buffer with keywords.
		if ( strcmp(keyword[i],buffer)==0 ){  // codition if it match with keyword.
			flag=1;
			break;
		}
	}
	return flag; // return flag.
}

// main function.
void main(){
	char buffer[20],ch,operator[] = "+-*/%="; // buffer to store words temporarily, ch for storing char from file, operator array.
	int i,j=0; // i for loop and j for storing char in buffer.
	FILE *fp; // creating file pointer.
	printf("Enter file name : ");  
	scanf(" %s",buffer);  //  Get file name from user and store in buffer.
	fp = fopen(buffer,"r"); // opening file in read mode.
	if (fp==NULL){ // if file is null exit.
		printf("Fail to open file.\n");
		exit(1);
	}
	while ( (ch=fgetc(fp)) != EOF ) {  // loop till it reach EOF(End Of File).
		if ( isalnum(ch) ) // function to check if char is num or alphabet and store it in buffer and increment j.
			buffer[j++]=ch; 
		else if ( j!=0 ) { // if ch is not num or alphabet then complete buffer and check for keyword and identifier.
			buffer[j]='\0'; // ending buffer.
			
			j=0; // reset j.
			if ( isKeyword(buffer) )  // if it is keyword, print it.
				printf("%s is keyword.\n",buffer);
			else // else it is identifier and print it.
				printf("%s is identifier.\n",buffer);
		}
		
		for (i=0 ; i<6; i++){ // check if ch is operator then print it.
			if (ch==operator[i]){
				printf("%c is operator.\n",ch);
				break;
			}
		}
	}
	fclose(fp);
}
