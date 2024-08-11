#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

enum enOperationName
{
	eFirstLetterOfEachWord = 1,
	eLowerAllString,
	eUpperAllString,
	eInvertAllStringCase,
	eUpperFirstLetterOfEachWord,
	eLowerFirstLetterOfEachWord,
	eCountTypeOfDigitInString,
	eCountLetterFrequancyInString,
	ePrintEachWordInString,
	eCountLetter,
	eIsVowel,
	eCountWords,
	eTrimLeft,
	eTrimRight,
	eTrim,
	eReverceWordsInString,
	eReplaceWordInString,
	ePunctuationsRemoved,
	eConvertNumberToText
};

struct stOperationInfo
{
	string Text;
	enOperationName OperationName;
	string result;
};

void ShowMainMenuOptions()
{
	cout << "===============================\n";
	cout << " Choose one choice to perform\n";
	cout << "===============================\n";
	cout << " [01] First Letter Of Each Word.\n";
	cout << " [02] Lower All String.\n";
	cout << " [03] Upper All String.\n";
	cout << " [04] Invert All String Case.\n";
	cout << " [05] Upper First Letter Of Each Word.\n";
	cout << " [06] Lower First Letter Of Each Word.\n";
	cout << " [07] Count Type Of Digit In String.\n";
	cout << " [08] Count Letter Frequancy In String.\n";
	cout << " [09] Words In String.\n";
	cout << " [10] Count Letter.\n";
	cout << " [11] Is Vowel.\n";
	cout << " [12] Count Words.\n";
	cout << " [13] Trim Left.\n";
	cout << " [14] Trim Right.\n";
	cout << " [15] Trim.\n";
	cout << " [16] Reverce Words In String.\n";
	cout << " [17] Replace Word In String.\n";
	cout << " [18] Punctuations Removed.\n";
	cout << " [19] Convert Number To Text.\n";
	cout << "===============================\n";
}

string ReadInput()
{
	cout << "===============================\n";
	cout << "\tEnter a Text : \n";
	cout << "===============================\n";
	cin.ignore();
	string Input;
	getline(cin, Input);
	return Input;
}

enOperationName GetUserChoice()
{
	short Choice = 0;
	cout << "Choose one choice to perform [1 : 19] .";
	cin >> Choice;

	while (cin.fail() || Choice < 1 || Choice > 19)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input, Please enter a valid one!\n";
		cin >> Choice;
	}
	return (enOperationName)Choice;
}

string FirstLetterOfEachWord(string str)
{
	bool IsFirstLetter = true;
	string result = "";

	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && IsFirstLetter)
		{
			result += str[i];
			result += ' ';
		}
		IsFirstLetter = (str[i] == ' ' ? true : false);
	}
	return result;
}

string LowerFirstLetterOfEachWord(string str)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && IsFirstLetter && isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
		IsFirstLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}

string UpperFirstLetterOfEachWord(string str)
{
	bool IsFirstLetter = true;

	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && IsFirstLetter && islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
		IsFirstLetter = (str[i] == ' ' ? true : false);
	}
	return str;
}

char InvertCharacterCase(char Character)
{
	return isupper(Character) ? tolower(Character) : toupper(Character);
}

string InvertAllStringCase(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = InvertCharacterCase(str[i]);
	}
	return str;
}

enum enWhatToCount { All, CapitalLetters, SmallLetters, PunctualSymbols, Spaces };

short CountTypeOfDigitInString(string str, enWhatToCount WhatToCount)
{
	short Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (WhatToCount == enWhatToCount::All) {
			Counter++;
		}
		else if (WhatToCount == enWhatToCount::CapitalLetters && isupper(str[i]))
		{
			Counter++;
		}
		else if (WhatToCount == enWhatToCount::SmallLetters && islower(str[i]))
		{
			Counter++;
		}
		else if (WhatToCount == enWhatToCount::PunctualSymbols && ispunct(str[i]))
		{
			Counter++;
		}
		else if (WhatToCount == enWhatToCount::Spaces && str[i] == ' ')
		{
			Counter++;
		}
	}
	return Counter;
}

enWhatToCount WhatToCount()
{
	short Choice = 0;
	cout << "Choose one choice to perform [All  (1) : CapitalLetters  (2) : SmallLetters  (3) : PunctualSymbols  (4) : Spaces  (5)] .";
	cin >> Choice;

	while (cin.fail() || Choice < 1 || Choice > 5)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nInvalid input, Please enter a valid one!\n";
		cin >> Choice;
	}
	return (enWhatToCount)Choice;
}

string CountTypeOfDigitInStringScreen(string str)
{
	return to_string(CountTypeOfDigitInString(str, WhatToCount()));
}

string LoweAllString(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}

string UpperAllString(string str)
{
	for (short i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

char ReadCharacter()
{
	char C;
	cout << "Enter a Character : ";
	cin >> C;
	while (!isalpha(C))
	{
		cout << "\nInvalid Input, Please enter a valid character!";
		cin >> C;
	}
	return C;
}

short CountLetterFrequancyInString(string str, char Character)
{
	short Counter = 0;
	for (short i = 0; i < str.length(); i++)
	{
		if (str[i] == Character)
		{
			Counter++;
		}
	}
	return Counter;
}

string CountLetterFrequancyInStringScreen(string str)
{
	return to_string(CountLetterFrequancyInString(str, ReadCharacter()));
}

string EachWordInString(string str)
{
	string result = "";
	string sWord;
	short pos = 0;
	string Dilimter = " ";

	while ((pos = str.find(Dilimter)) != string::npos)
	{
		sWord = str.substr(0, pos);
		if (sWord != "")
		{
			result += sWord + ' ';
		}
		str.erase(0, pos + Dilimter.length());
	}
	if (str != "")
	{
		result += str;
	}
	return result;
}

string CountLetter(string S1, char Letter, bool MatchCase = true)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
		}
	}
	return to_string(Counter);
}

bool IsMatchCase()
{
	char answer = 'y';
	cout << "\nDo you want to count all letter cases Y/N? ";
	cin >> answer;

	while (!(toupper(answer) == 'Y' || toupper(answer) == 'N'))
	{
		cout << "\nInvalid Input, Please enter a valid choice Y/N? ";
		cin >> answer;
	}
	return (toupper(answer) == 'Y');
}

string CountLetterScreen(string str)
{
	char C = ReadCharacter();
	return CountLetter(str, C, IsMatchCase());
}

bool IsVowel(char Letter)
{
	Letter = tolower(Letter);
	return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o'

		|| Letter == 'u');
}

bool IsVowelScreen()
{
	char Letter = ReadCharacter();
	return IsVowel(Letter);
}

string CountWords(string S1)
{
	short Counter = 0;
	string sWord;
	short pos = 0;
	string Dilimter = " ";

	while ((pos = S1.find(Dilimter)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			Counter++;
		}
		S1.erase(0, pos + Dilimter.length());
	}
	if (S1 != "")
	{
		Counter++;
	}
	return to_string(Counter);
}

string TrimLeft(string str)
{
	while (str[0] == ' ')
	{
		str.erase(0, 1);
	}
	return str;
}

string TrimRight(string str)
{
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.length() - 1, 1);
	}
	return str;
}

string Trim(string str)
{
	str = TrimLeft(str);
	str = TrimRight(str);
	return str;
}

string ReverceWordsInString(string S1)
{
	string sWord;
	short pos = 0;
	string Dilimter = " ";
	vector<string> vWords;

	while ((pos = S1.find(Dilimter)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			vWords.push_back(sWord);
		}
		S1.erase(0, pos + Dilimter.length());
	}
	if (S1 != "")
	{
		vWords.push_back(S1);
	}
	string result = "";
	for (short i = vWords.size() - 1; i >= 0; i--)
	{
		result += vWords[i] + " ";
	}
	return result;
}

string ReplaceWordInString(string str, string StrToReplace, string StrReplaceBy)
{
	short pos = str.find(StrToReplace);
	while (pos != string::npos)
	{
		str.replace(pos, StrToReplace.length(), StrReplaceBy);
		pos = str.find(StrToReplace);
	}
	return str;
}

string ReplaceWordInStringScreen(string str)
{
	string StrToReplace = "";
	string StrReplaceBy = "";
	cout << "\nPlease enter a word to replace: ";
	cin >> StrToReplace;
	cout << "\nPlease enter a word to replace by: ";
	cin >> StrReplaceBy;

	return ReplaceWordInString(str, StrToReplace, StrReplaceBy);
}

string RemovePunctuations(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (ispunct(S1[i]))
		{
			S1.erase(i--, 1);
		}
	}
	return S1;
}

string RemovePunctuationsScreen(string str)
{
	return RemovePunctuations(str);
}

string ReadNumber()
{
	cout << "\nPlease enter a number: ";
	string Number = "";
	cin >> Number;
	return Number;
}

string ConvertNumberToText(int Number)
{

	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string Arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
						 "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
		return Arr[Number];
	}

	if (Number >= 20 && Number <= 99)
	{
		string Arr[] = { "","","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
		return Arr[Number / 10] + " " + ConvertNumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 199)
	{
		return "One Hundred " + ConvertNumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{
		return ConvertNumberToText(Number / 100) + " Hundred " + ConvertNumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + ConvertNumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{
		return   ConvertNumberToText(Number / 1000) + "Thousands " + ConvertNumberToText(Number % 1000);
	}

	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + ConvertNumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999)
	{
		return ConvertNumberToText(Number / 1000000) + " Millions " + ConvertNumberToText(Number % 1000000);
	}

	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + ConvertNumberToText(Number % 1000000000);
	}

	else
	{
		return  ConvertNumberToText(Number / 1000000000) + " Billions " + ConvertNumberToText(Number % 1000000000);
	}
}

string ConvertNumberToTextScreen()
{
	return ConvertNumberToText(stoi(ReadNumber()));
}

string ChooseOperationToPerform(stOperationInfo & OperationInfo)
{
	switch (OperationInfo.OperationName)
	{
	case eFirstLetterOfEachWord:
		return FirstLetterOfEachWord(OperationInfo.Text);
	case eLowerAllString:
		return LoweAllString(OperationInfo.Text);
	case eUpperAllString:
		return UpperAllString(OperationInfo.Text);
	case eInvertAllStringCase:
		return InvertAllStringCase(OperationInfo.Text);
	case eUpperFirstLetterOfEachWord:
		return UpperFirstLetterOfEachWord(OperationInfo.Text);
	case eLowerFirstLetterOfEachWord:
		return LowerFirstLetterOfEachWord(OperationInfo.Text);
	case eCountTypeOfDigitInString:
		return CountTypeOfDigitInStringScreen(OperationInfo.Text);
	case eCountLetterFrequancyInString:
		return CountLetterFrequancyInStringScreen(OperationInfo.Text);
	case ePrintEachWordInString:
		return EachWordInString(OperationInfo.Text);
	case eCountLetter:
		return CountLetterScreen(OperationInfo.Text);
	case eIsVowel:
		return IsVowelScreen() ? "True" : "False";
	case eCountWords:
		return CountWords(OperationInfo.Text);
	case eTrimLeft:
		return TrimLeft(OperationInfo.Text);
	case eTrimRight:
		return TrimRight(OperationInfo.Text);
	case eTrim:
		return Trim(OperationInfo.Text);
	case eReverceWordsInString:
		return ReverceWordsInString(OperationInfo.Text);
	case eReplaceWordInString:
		return ReplaceWordInStringScreen(OperationInfo.Text);
	case ePunctuationsRemoved:
		return RemovePunctuationsScreen(OperationInfo.Text);
	case eConvertNumberToText:
		return ConvertNumberToTextScreen();
	}
	return "";
}

void Start()
{
	ShowMainMenuOptions();
	stOperationInfo OperationInfo;
	OperationInfo.Text = ReadInput();
	OperationInfo.OperationName = GetUserChoice();
	OperationInfo.result = ChooseOperationToPerform(OperationInfo);
	cout << "\nResult: " << OperationInfo.result << endl;
}

int main()
{
	Start();
	system("pause>0");
	return 0;

}
