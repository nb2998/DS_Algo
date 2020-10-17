/*
 * Program of lexical analyzer.
 * It is for source code written in c language.
 * I've tried to make it as good as real.
 * I know there are too many exeptions, and maybe it'll be solved later when i've free time.
 * This program is os independent.
 * In linux for me it works perfectly.
 */

// Including header files.
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define N 256

using namespace std;

vector <string> _keyword, _identifier, _constant, _string, _symbol, _operator, _preprocessor;

// function to check if a stored word in buffer is keyword or not.
bool isKeyword ( char buffer[] ) {

	//  Comparing buffer with keywords, if any of it matches then return true else it will return false.
	if( !strcmp("auto"    ,buffer) || !strcmp("break"   ,buffer) || !strcmp("case"    ,buffer) || !strcmp("char"    ,buffer) ||
	    !strcmp("continue",buffer) || !strcmp("do"      ,buffer) || !strcmp("default" ,buffer) || !strcmp("const"   ,buffer) ||
	    !strcmp("double"  ,buffer) || !strcmp("else"    ,buffer) || !strcmp("enum"    ,buffer) || !strcmp("extern"  ,buffer) ||
	    !strcmp("for"     ,buffer) || !strcmp("if"      ,buffer) || !strcmp("goto"    ,buffer) || !strcmp("float"   ,buffer) ||
	    !strcmp("int"     ,buffer) || !strcmp("long"    ,buffer) || !strcmp("register",buffer) || !strcmp("return"  ,buffer) ||
	    !strcmp("signed"  ,buffer) || !strcmp("static"  ,buffer) || !strcmp("sizeof"  ,buffer) || !strcmp("short"   ,buffer) ||
	    !strcmp("struct"  ,buffer) || !strcmp("switch"  ,buffer) || !strcmp("typedef" ,buffer) || !strcmp("union"   ,buffer) ||
	    !strcmp("void"    ,buffer) || !strcmp("while"   ,buffer) || !strcmp("volatile",buffer) || !strcmp("unsigned",buffer) )
		return true;
	return false;  //  It will be executed if condition is not satisfied.

}

//  Function to check if the character is a special symbol or not.
bool isSymbol ( char ch) {

	//  Same as isKeyword function it will check it and return true or false for it.
	if( ch=='[' || ch==']' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==',' || ch=='~' || ch=='$' || ch=='^' ||
	    ch=='`' || ch=='.' )
		return true;
	return false;
}


//  It important to remove duplicates from the list, because if any of variable multiple times used in program then
//  it's senseless to show same variable multiple times.
void removeDuplicate(){
	sort(_keyword.begin(), _keyword.end());  //  First it will sort the vector cause it will make work easier to remove duplicates.
	_keyword.erase( unique( _keyword.begin(), _keyword.end() ), _keyword.end() );  //  It will remove duplicates from vector.

	//  Same way removing duplicate values from all other tokens.
	sort(_identifier.begin(), _identifier.end());
	_identifier.erase( unique( _identifier.begin(), _identifier.end() ), _identifier.end() );

	sort(_constant.begin(), _constant.end());
	_constant.erase( unique( _constant.begin(), _constant.end() ), _constant.end() );

	sort(_string.begin(), _string.end());
	_string.erase( unique( _string.begin(), _string.end() ), _string.end() );

	sort(_symbol.begin(), _symbol.end());
	_symbol.erase( unique( _symbol.begin(), _symbol.end() ), _symbol.end() );

	sort(_operator.begin(), _operator.end());
	_operator.erase( unique( _operator.begin(), _operator.end() ), _operator.end() );

	sort(_preprocessor.begin(), _preprocessor.end());
	_preprocessor.erase( unique( _preprocessor.begin(),_preprocessor.end() ), _preprocessor.end() );
}


//  Main lexical analyzer function which will do main work.
void lexicalAnalyzer( string fileName ){  //  It takes string argument which is for name of file.
	fstream file;  //  created fstream object.
	file.open(fileName.data(),ios::in);  //  opening file as input.

	if ( file.fail() ){  //  Check if file loaded successfully or not.
		cerr<<"Error in opening file."<<endl;
		return;
	}

	char ch,temp,buffer[N];  //  Variables used to store values.
	int j=0;  //  Int variable to point top of buffer.

	while ( file.get(ch) && !file.eof() ){  //  Loop to read a char from file until end of file comes.

		if ( ch==' ' )  //  To ignore free space.
			continue;

		else if ( ch=='/' ){  //  To ignore comments.
			file.get(ch);
			if( ch=='/' )  //  If it is single line comment then skip until '\n' comes in it.
				while ( ch!='\n' )
					file.get(ch);
			else if ( ch=='*' )  //  If it's multiple line comment then skip until '*' and '/' comes in sequence.
				while ( true ){
					temp = ch;
					file.get(ch);
					if ( temp=='*' && ch=='/')
						break;
				}
			else{  //  If it's not comment then it is operator so seek pointer 2 step in reverse and again get that value in ch.
				file.seekg(-2,ios::cur);
				file.get(ch);
			}
		}
		
		//  To know preprocessors.
		else if ( ch=='#' ) {  //  If fist char is # then it is preprocessor.
			buffer[j++]=ch;
			while ( true ) {  //  Save it in buffer until '\n' comes and previous variable doesn't need to be '\' cause it represent preprocessor is still continue.
				file.get(ch);
				if ( ch=='\n' )
					if ( buffer[j-1]!='\\' )
						break;
				buffer[j++]=ch;
			}
			buffer[j]='\0';  //  Now add '\0' at end of buffer to represent end of char in it.
			j=0;  //  Reset j to zero.
			_preprocessor.push_back( buffer );  //  Add preprocessor in vector to store.
			continue;
		}

		//  If it is char constant then get it and store in constants.
		else if ( ch=='\'' ) { 
			buffer[j++] = ch;
			while ( file.get(ch) && ch!='\'' ) {
				buffer[j++] = ch;
			}
			buffer[j++]='\'';
			buffer[j]='\0';
			if ( j<4 || (j<5 && buffer[1]=='\\'))
				_constant.push_back( buffer );
			j=0;
			continue;
		}

		//  If it is numerical constant then get it and store in constants.
		else if ( isdigit(ch) ) {
			do{
				buffer[j++]=ch;
			} while ( file.get(ch) && ( isdigit(ch) || ch=='.' ));
			buffer[j]='\0';
			j=0;
			_constant.push_back( buffer );
			file.seekg(-1,ios::cur);
			continue;
		}

		//  To check if char starts with underscore or alphabet to consider it as keyword or identifier.
		else if ( isalpha(ch) || ch=='_' ){
			do{
				buffer[j++]=ch;
			} while ( file.get(ch) && (isalnum(ch) || ch=='_'));  //  Save the char in buffer until it satisfies condition.
			buffer[j]='\0';
			j=0;
			if ( isKeyword(buffer) )  //  Check if it is keyword or not and save it in it's vector respectively.
				_keyword.push_back( buffer );
			else
				_identifier.push_back( buffer );
			file.seekg(-1,ios::cur);
			continue;
		}

		//  Check if it is a symbol or not and store.
		else if ( isSymbol(ch) ){
			_symbol.push_back(string(1,ch));
			continue;
		}

		//  If it is string then store in string.
		else if ( ch=='\"' ) {
			while ( file.get(ch) && ch!='\"')
				buffer[j++]=ch;
			buffer[j]='\0';
			j=0;
			_string.push_back( buffer );
			continue;
		}

		//  Check if it is operator or not.
		if ( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=' || ch=='<' || ch=='>' || ch=='!' ||
		     ch=='&' || ch=='|' || ch=='^' || ch=='~' || ch=='\?' ) {
			buffer[j++]=ch;
			file.get(ch);
			if ( buffer[0]=='?' )
				buffer[j++]=':';
			else if ( buffer[0]!='~' && buffer[0]!='\?' && ch=='=' )
				buffer[j++]=ch;
			else if ( buffer[0]=='&' && ch=='&' )
				buffer[j++]=ch;
			else if ( buffer[0]=='|' && ch=='|' )
				buffer[j++]=ch;
			else if ( buffer[0]=='<' && ch=='<' )
				buffer[j++]=ch;
			else if ( buffer[0]=='>' && ch=='>' )
				buffer[j++]=ch;
			else
				file.seekg(-1,ios::cur);
			buffer[j]='\0';
			j=0;
			_operator.push_back( buffer );
		}
	}
	file.close();
	removeDuplicate();
}

//  Function to print all tokens.
void print(){
	cout<<endl<<"Preprocessors.\n--------------\n"<<endl;
	for (int i=0; i<_preprocessor.size(); i++)
		cout<<_preprocessor[i]<<endl;

	cout<<endl<<endl<<"Keyword.\n--------\n"<<endl;
	for (int i=0; i<_keyword.size(); i++)
		cout<<_keyword[i]<<endl;

	cout<<endl<<endl<<"Identifiers.\n------------\n"<<endl;
	for (int i=0; i<_identifier.size(); i++)
		cout<<_identifier[i]<<endl;

	cout<<endl<<endl<<"Constants.\n----------\n"<<endl;
	for (int i=0; i<_constant.size(); i++)
		cout<<_constant[i]<<endl;

	cout<<endl<<endl<<"Symbol.\n-------\n"<<endl;
	for (int i=0; i<_symbol.size(); i++)
		cout<<_symbol[i]<<endl;

	cout<<endl<<endl<<"Operator.\n---------\n"<<endl;
	for (int i=0; i<_operator.size(); i++)
		cout<<_operator[i]<<endl;

	cout<<endl<<endl<<"String.\n-------\n"<<endl;
	for (int i=0; i<_string.size(); i++)
		cout<<_string[i]<<endl;
}

//  Function to save it in file.
void save(){
	fstream fpreprocessor,fkeyword,fidentifier,fconstant,fsymbol,foperator,fstring;
	fpreprocessor.open("preprocessor.txt",ios::out);
	fkeyword.open("keyword.txt",ios::out);
	fidentifier.open("identifier.txt",ios::out);
	fconstant.open("constant.txt",ios::out);
	fsymbol.open("symbol.txt",ios::out);
	foperator.open("operator.txt",ios::out);
	fstring.open("string.txt",ios::out);
	
	for (int i=0; i<_preprocessor.size(); i++)
		fpreprocessor<<_preprocessor[i]<<endl;

	for (int i=0; i<_keyword.size()     ; i++)
		fkeyword<<_keyword[i]<<endl;

	for (int i=0; i<_identifier.size()  ; i++)
		fidentifier<<_identifier[i]<<endl;

	for (int i=0; i<_constant.size()    ; i++)
		fconstant<<_constant[i]<<endl;

	for (int i=0; i<_symbol.size()      ; i++)
		fsymbol<<_symbol[i]<<endl;

	for (int i=0; i<_operator.size()    ; i++)
		foperator<<_operator[i]<<endl;

	for (int i=0; i<_string.size()      ; i++)
		fstring<<_string[i]<<endl;
		
	fpreprocessor.close();
	fkeyword.close();
	fidentifier.close();
	fconstant.close();
	fsymbol.close();
	foperator.close();
	fstring.close();
}

//  Function to save everything in same file.
void saveInOne(){
	fstream file;
	file.open("Tokens.txt",ios::out);
	
	file<<endl<<"Preprocessors.\n--------------\n"<<endl;
	for (int i=0; i<_preprocessor.size(); i++)
		file<<_preprocessor[i]<<endl;

	file<<endl<<endl<<"Keyword.\n--------\n"<<endl;
	for (int i=0; i<_keyword.size(); i++)
		file<<_keyword[i]<<endl;

	file<<endl<<endl<<"Identifiers.\n------------\n"<<endl;
	for (int i=0; i<_identifier.size(); i++)
		file<<_identifier[i]<<endl;

	file<<endl<<endl<<"Constants.\n----------\n"<<endl;
	for (int i=0; i<_constant.size(); i++)
		file<<_constant[i]<<endl;

	file<<endl<<endl<<"Symbol.\n-------\n"<<endl;
	for (int i=0; i<_symbol.size(); i++)
		file<<_symbol[i]<<endl;

	file<<endl<<endl<<"Operator.\n---------\n"<<endl;
	for (int i=0; i<_operator.size(); i++)
		file<<_operator[i]<<endl;

	file<<endl<<endl<<"String.\n-------\n"<<endl;
	for (int i=0; i<_string.size(); i++)
		file<<_string[i]<<endl;
}

int main(){
	string fileName;
	cout<<"Enter file name. : ";
	cin>>fileName;
	lexicalAnalyzer(fileName);
	int choice=0;
	cout<<"1.Print        2.Save\n-> ";
	cin>>choice;
	if ( choice==1 )
		print();
	else if ( choice==2 )
		cout<<"1.One file only      2.Multiple files\n-> ";
		cin>>choice;
		if(choice==1) saveInOne();
		else if(choice==2) save();
	else
		cerr<<"Enter valid choice.";
	return 0;
}


