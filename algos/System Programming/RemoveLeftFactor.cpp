#include <iostream>
using namespace std;

int main(){  //  Oh plz, you already know it is important.

	char x[100], part[20][20], common[20], other[100];
	//  Variables : x-> to store input, part-> to store parts found in input, common-> to store what is common in input. , other-> it will contain symbols which are not common in input.

	int partIndex=0,i=0,j=0;  //  partIndex is to know how many parts in input.

	cout<<"Enter Production : A-> ";  //  Getting input from user.
	cin.get(x,100);

	while ( x[i]!='\0' ){  //  Get char from input until end of string.

		if (x[i]=='|') i++; // If it is '|' then ignore it and go next.

		while (x[i]!='|' && x[i]!='\0'){  //  Store it in particular part until part ends.
			part[partIndex][j]=x[i];
			j++; i++;
		}

		part[partIndex][j]='\0';  
		partIndex++; j=0;  //  Now increment partIndex and reset j to add new part on next iteration.
	}

	for(i=0; part[0][i]!='\0'; i++) common[i]=part[0][i];  //  Copy fist part in common so later it will checked with all parts.
	common[i]='\0';

	for(i=1; i<partIndex; i++){  //  Check with other parts to know common in it.
		j=0;
		while(part[i][j] == common[j]) j++;
		common[j]='\0';
	}

	int l=0;
	while (common[l]!='\0') l++;  //  To know length of common parts and store it in l.

	if(l==0){  //  If it is zero means there is nothing common so there is no left factor.
		cout<<"No left factor found."<<endl<<endl;
		return 0;
	}

	for(i=j=0; i<partIndex; i++){  //  Now collect all uncommon symbols and store in other and adding '|' between them.
		for(int k=l; part[i][k]!='\0'; k++,j++) other[j]=part[i][k];
		other[j++]='|';
	}
	other[j-1]='\0';

	cout<<"\nOutput : "<<endl<<"A  -> "<<common<<"A'"<<endl<<"A' -> "<<other<<endl<<endl;  //  Printing output.

	return 0;
}

/*
 * Example : 
 *
 * Enter Production : A-> abcDE|abcF|abcSTM|abcK
 *
 * Output : 
 * A-> abcX
 * X-> DE|F|STM|K
 *
 */
