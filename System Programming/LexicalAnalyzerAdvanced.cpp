/*
 * Program of lexical analyzer.
 * It is for source code written in c language.
 * I've tried to make it as good as real.
 * I know there are too many exeptions, and maybe it'll be solved later when i've free time.
 * This program is independent of os.
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

	if( !strcmp("auto"    ,buffer) || !strcmp("break"   ,buffer) || !strcmp("case"    ,buffer) || !strcmp("char"    ,buffer) ||
	    !strcmp("continue",buffer) || !strcmp("do"      ,buffer) || !strcmp("default" ,buffer) || !strcmp("const"   ,buffer) ||
	    !strcmp("double"  ,buffer) || !strcmp("else"    ,buffer) || !strcmp("enum"    ,buffer) || !strcmp("extern"  ,buffer) ||
	    !strcmp("for"     ,buffer) || !strcmp("if"      ,buffer) || !strcmp("goto"    ,buffer) || !strcmp("float"   ,buffer) ||
	    !strcmp("int"     ,buffer) || !strcmp("long"    ,buffer) || !strcmp("register",buffer) || !strcmp("return"  ,buffer) ||
	    !strcmp("signed"  ,buffer) || !strcmp("static"  ,buffer) || !strcmp("sizeof"  ,buffer) || !strcmp("short"   ,buffer) ||
	    !strcmp("struct"  ,buffer) || !strcmp("switch"  ,buffer) || !strcmp("typedef" ,buffer) || !strcmp("union"   ,buffer) ||
	    !strcmp("void"    ,buffer) || !strcmp("while"   ,buffer) || !strcmp("volatile",buffer) || !strcmp("unsigned",buffer) )
		return true;
	return false;

}


bool isSymbol ( char ch) {

	if( ch=='[' || ch==']' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==',' || ch=='~' || ch=='$' || ch=='^' ||
	    ch=='`' || ch=='.' )
		return true;
	return false;
}


void removeDuplicate(){
	sort(_keyword.begin(), _keyword.end());
	_keyword.erase( unique( _keyword.begin(), _keyword.end() ), _keyword.end() );

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


void lexicalAnalyzer( string fileName ){
	FILE *file;
	file = fopen(fileName.data(),"r");

	if ( file == NULL ){
		cerr<<"Error in opening file."<<endl;
		return;
	}

	char ch,temp,buffer[N];
	int j=0;

	while ( (ch=fgetc(file)) && ch!=EOF ){

		if ( ch==' ' )  //  To ignore free space.
			continue;

		else if ( ch=='/' ){  //  To ignore comments.
			ch = fgetc(file);
			if( ch=='/' )
				while ( ch!='\n' )
					ch = fgetc(file);
			else if ( ch=='*' )
				while ( true ){
					temp = ch;
					ch = fgetc(file);
					if ( temp=='*' && ch=='/')
						break;
				}
			else{
				fseek(file,-2,SEEK_CUR);
				ch = fgetc(file);
			}
		}

		else if ( ch=='#' ) {
			buffer[j++]=ch;
			while ( true ) {
				ch = fgetc(file);
				if ( ch=='\n' )
					if ( buffer[j-1]!='\\' )
						break;
				buffer[j++]=ch;
			}
			buffer[j]='\0';
			j=0;
			_preprocessor.push_back( buffer );
			continue;
		}

		else if ( ch=='\'' ) {
			buffer[j++] = ch;
			while ( (ch=fgetc(file)) && ch!='\'' ) {
				buffer[j++] = ch;
			}
			buffer[j++]='\'';
			buffer[j]='\0';
			if ( j<4 || (j<5 && buffer[1]=='\\'))
				_constant.push_back( buffer );
			j=0;
			continue;
		}

		else if ( isdigit(ch) ) {
			do{
				buffer[j++]=ch;
			} while ( (ch=fgetc(file)) && ( isdigit(ch) || ch=='.' ));
			buffer[j]='\0';
			j=0;
			_constant.push_back( buffer );
			fseek(file,-1,SEEK_CUR);
			continue;
		}

		else if ( isalpha(ch) || ch=='_' ){
			do{
				buffer[j++]=ch;
			} while ( (ch=fgetc(file)) && (isalnum(ch) || ch=='_'));
			buffer[j]='\0';
			j=0;
			if ( isKeyword(buffer) )
				_keyword.push_back( buffer );
			else
				_identifier.push_back( buffer );
			fseek(file,-1,SEEK_CUR);
			continue;
		}

		else if ( isSymbol(ch) ){
			_symbol.push_back(string(1,ch));
			continue;
		}

		else if ( ch=='\"' ) {
			while ( (ch=fgetc(file)) && ch!='\"')
				buffer[j++]=ch;
			buffer[j]='\0';
			j=0;
			_string.push_back( buffer );
			continue;
		}

		if ( ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch=='=' || ch=='<' || ch=='>' || ch=='!' ||
		     ch=='&' || ch=='|' || ch=='^' || ch=='~' || ch=='\?' ) {
			buffer[j++]=ch;
			ch = fgetc(file);
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
				fseek(file,-1,SEEK_CUR);
			buffer[j]='\0';
			j=0;
			_operator.push_back( buffer );
		}
	}
	removeDuplicate();
}


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
	
	cout<<endl<<"Saved Successfully."<<endl<<endl;
}


int main(){
	string fileName;
	cout<<"Enter file name. : ";
	cin>>fileName;
	lexicalAnalyzer(fileName);
	int choice=0;
	cout<<"1.Print        2.Save\n";
	cin>>choice;
	if ( choice==1 )
		print();
	else if ( choice==2 )
		save();
	else
		cerr<<"Enter valid choice.";
	return 0;
}


