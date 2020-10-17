%{
int COMMENT=0;
%}


identifier [a-zA-Z][a-zA-Z0-9]*


%%


#.* {printf("\n%s is a preprocessor directive.",yytext);}


auto |
break |
case |
char |
const |
continue |
default |
do |
double |
else |
enum |
extern |
float |
for |
goto |
if |
int |
long |
register |
return |
short |
signed |
sizeof |
static |
struct |
switch |
typedef |
union |
unsigned |
void |
volatile |
while {if(!COMMENT) printf("\n    %s is a KEYWORD",yytext);}


"/*" {COMMENT=1;} {printf("    COMMENT IGNORED",yytext);}
"*/" {COMMENT=0;}
"\n" {if(!COMMENT) printf("\n");}


{identifier}\( {if(!COMMENT) printf("\n\nFUNCTION \n%s",yytext);}


\{  {if(!COMMENT)	printf("\nBLOCK BEGINS");}
\}  {if(!COMMENT)	printf("\nBLOCK ENDS ");}


{identifier}(\[[0-9]*\])? {if(!COMMENT) printf("\n    %s IDENTIFIER",yytext);}


\".*\" {if(!COMMENT) printf("\n    %s is a STRING",yytext);}


[0-9]+ {if(!COMMENT) printf("\n    %s is a NUMBER ",yytext);}


\)(\:)? {if(!COMMENT) printf("\n"); ECHO; printf("\n");}


\( ECHO;


, {if(!COMMENT) printf("\n    %s is a SEPARATOR",yytext);}

= |
\+= |
\-= |
\*= |
\/= |
\%= {if(!COMMENT)printf("\n    %s is an ASSIGNMENT OPERATOR",yytext);}

\<= |
\>= |
\< |
== |
!= |
\> {if(!COMMENT) printf("\n    %s is a RELATIONAL OPERATOR",yytext);}

\+ |
\- |
\* |
\/ |
\% {if(!COMMENT) printf("\n    %s is an ARITHMETIC OPERATOR",yytext);}

! {if(!COMMENT) printf("\n    %s is a LOGICAL OPERATOR",yytext);}

-- {if(!COMMENT) printf("\n    %s is a DECREMENT OPERATOR",yytext);}
\+\+ {if(!COMMENT) printf("\n    %s is an INCREMENT OPERATOR",yytext);}

; {if(!COMMENT) printf("\n    %s is STATEMENT TERMINATOR",yytext);}

"." {if(!COMMENT) printf("\n    %s is SPECIAL OPERATOR",yytext);}


%%

int main(int argc, char **argv){
	char fileName[100];
	printf("Enter file name : ");
	scanf(" %[^\n]s", fileName);

	FILE *file;
	file = fopen(fileName,"r");
	
	if(!file){
		printf("could not open the file");
		exit(0);
	}

	yyin = file;
	yylex();
	
	printf("\n");

	return 0;
}

int yywrap() {
	return 1;
}


