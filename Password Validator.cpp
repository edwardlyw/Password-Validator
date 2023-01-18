#include <iostream>
#include <ctype.h>

using namespace std;

int const passwordMaxLength = 15;
int const minChar = 10;

void checkPassword(char password_in[passwordMaxLength], bool & upper, bool & lower, bool & punct, bool & digit)
{	
	for(int count = 0; count < passwordMaxLength; count++)
	{
		if(isupper(password_in[count]))
		{
			upper = true;
		}
		
		if(islower(password_in[count]))
		{
			lower = true;
		}
		
		if(ispunct(password_in[count]))
		{
			punct = true;
		}
		
		if(isdigit(password_in[count]))
		{
			digit = true;
		}
	}
}

int main()
{
	
	char password[passwordMaxLength] = {' '};
	
	cout << "A strong password must be at least " << minChar << " characters long, with maximum of " << passwordMaxLength 
		 << " characters and must have a combination of the following:" << endl;
	cout << "Uppercase letters" << endl;
	cout << "Lowercase letters" << endl;
	cout << "Symbols" << endl;
	cout << "Numbers" << endl;
	cout << "Please enter a password: ";
	cin >> password;
	
	int characterNum = 0;
	bool hasUpper = false;
	bool hasLower = false;
	bool hasPunct = false;
	bool hasDigit = false;
	
	checkPassword(password, hasUpper, hasLower, hasPunct, hasDigit);
	characterNum = strlen(password);
	
	if(characterNum > minChar && characterNum < passwordMaxLength && hasUpper == true && hasLower == true && hasPunct == true && 
		hasDigit == true)
	{
		cout << "Password is valid" << endl;
	}
	
	else if(characterNum < minChar)
	{
		cout << "Password is too short" << endl;
	}
	
	else
	{
		cout << "Password is invalid and is missing the following:" << endl;
		
		if(hasUpper == false && hasLower == true)
		{
			cout << "Uppercase Letters" << endl;
		}
		
		if(hasLower == false && hasUpper == true)
		{
			cout << "Lowercase Letters" << endl;
		}
		
		if(hasLower == false && hasUpper == false)
		{
			cout << "Letters" << endl;
		}
		
		if(hasPunct == false)
		{
			cout << "Symbols/Punctuations" << endl;
		}
		
		if(hasDigit == false)
		{
			cout << "Numbers" << endl;
		}
	}
	
	return EXIT_SUCCESS;
	
}
