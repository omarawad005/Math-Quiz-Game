

#include <iostream>
using namespace std;

enum enOperationType { Add = 1, Sub = 2, Mult = 3, Div = 4, MiX = 5 };
enum enGameLevel { Easy = 1, Meduim = 2, Hard = 3, Mix = 4 };
enum enPassOrFail { Pass = 1, Fail = 2, Draw = 3 };

struct stGameInfo
{
	int NumOfQuestoin;
	int Number1;
	int Number2;
	int UserAnswer;
	int RightAnswer;
	bool IsRightAnswer;// enum is goog
	char OpTypeSymbol;
	enOperationType OperationType;
	enGameLevel GameLevel;

};

struct stFinalRestul
{
	int NumOfQuestoin;
	short RightAnswerCount = 0;
	short WrongAnswerCount = 0;
	string LevelName = "";
	string OperationName = "";
	enPassOrFail PassOrFail;
	
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int HowManyQuestion()
{
	int Num;
	do
	{
		cout << "Enter Number of Question : ";
		cin >> Num;

	} while (Num <= 0);
	return Num;
}

enOperationType GetOperationType()
{
	int Num;
	do
	{
		cout << "Enter Operation You need [1]:Add, [2]:Sub, [3]:Mult, [4]:Div, [5]:Mix ? ";
		cin >> Num;

	} while (Num < 1 || Num > 5);

	return (enOperationType)Num;
}

enGameLevel GetGameLevel()
{
	int Num;
	do
	{
		cout << "Enter Level of Game [1]:Easy, [2]:Meduim, [3]:Hard, [4]:Mix ? ";
		cin >> Num;

	} while (Num < 1 || Num > 4);

	return (enGameLevel)Num;
}

char GetRandomOperation()
{
	char Operation[] = { '+', '-', '*', '/' };
	return Operation[RandomNumber(0, 3)];
}

char GetOperationSymbol(enOperationType OpType)
{ 
	switch (OpType)
	{
		case enOperationType::Add:
			return '+';
		case enOperationType::Sub:
			return '-';
		case enOperationType::Mult:
			return '*';
		case enOperationType::Div:
			return '/';
		case enOperationType::MiX:
			return GetRandomOperation();
		default :
			return '?';


	}
}

int GenerateNumberForLevel(enGameLevel Level)
{
	switch (Level)
	{
	case enGameLevel::Easy:
		return RandomNumber(1, 10);
	case enGameLevel::Meduim:
		return RandomNumber(10, 50);
	case enGameLevel::Hard:
		return RandomNumber(50, 100);
	case enGameLevel::Mix:
		return RandomNumber(1, 100);
	default:
		return RandomNumber(1, 100);
	}

}

int GetRightAnswer(char Operation,int Num1, int Num2)
{
	switch (Operation)
	{
		case '+':
			return Num1 + Num2;
		
		case '-':
			return Num1 - Num2;
		
		case '*':
			return Num1 * Num2;
		
		case '/':
			return Num1 / Num2;
		default:
			return Num1 + Num2;
	}

}

bool CheckAnswer(int UserAnswer, int RightAnswer)
{
	return UserAnswer == RightAnswer;
}

void DisPlayQuestion(stGameInfo &GameInfo)
{
	cout << "\n";
	cout << GameInfo.Number1 << endl;
	cout << GameInfo.Number2;
	cout << "   " << GameInfo.OpTypeSymbol << endl;
	cout << "--------\n";
	cin >> GameInfo.UserAnswer;
}

void ChangeScreenColor(bool IsRightAnswer)
{
	if (IsRightAnswer)
		system("color 2f");
	else
		system("color 4f");
}

void PrintResult(stGameInfo GameInfo)
{
	cout << "\n";
	if (GameInfo.IsRightAnswer)
	{
		ChangeScreenColor(GameInfo.IsRightAnswer);
		cout << "Right Answer :-) \n";
	}
	else
	{
		ChangeScreenColor(GameInfo.IsRightAnswer);
		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer is : " << GameInfo.RightAnswer;
	}
}

enPassOrFail PassOrFail(int NumberOfRightAnswer, int NumberOfWrongAnswer)
{
	if (NumberOfRightAnswer == NumberOfWrongAnswer)
		return enPassOrFail::Draw;
	else if (NumberOfRightAnswer > NumberOfWrongAnswer)
		return enPassOrFail::Pass;
	else
		return enPassOrFail::Fail;
	
	
}

string LevelName(enGameLevel GameLevel)
{
	string Level[] = { "Easy", "Meduim", "Hard", "Mix" };
	return Level[GameLevel - 1];
}

string OperationName(enOperationType OpType)
{
	string Level[] = { "Add", "Sub", "Mult", "Div", "Mix" };
	return Level[OpType - 1];
}

stFinalRestul GenerateQuestion(stGameInfo &GameInfo)
{
	stFinalRestul FinalResult;
	short  NumOfRightAnswer = 0, NumOfWrongAnswer = 0;
	for (int i = 1; i <= GameInfo.NumOfQuestoin; i++)
	{
		cout << "\nQuestion [" << i << " / " << GameInfo.NumOfQuestoin << "] : \n";
		GameInfo.Number1 = GenerateNumberForLevel(GameInfo.GameLevel);
		GameInfo.Number2 = GenerateNumberForLevel(GameInfo.GameLevel);
		GameInfo.OpTypeSymbol = GetOperationSymbol(GameInfo.OperationType);

		DisPlayQuestion(GameInfo);

		GameInfo.RightAnswer = GetRightAnswer(GameInfo.OpTypeSymbol, GameInfo.Number1, GameInfo.Number2);
		GameInfo.IsRightAnswer = CheckAnswer(GameInfo.UserAnswer, GameInfo.RightAnswer);
		if (GameInfo.IsRightAnswer)
			NumOfRightAnswer++;
		else
			NumOfWrongAnswer++;
		PrintResult(GameInfo);

	}

	FinalResult.NumOfQuestoin = GameInfo.NumOfQuestoin;
	FinalResult.RightAnswerCount = NumOfRightAnswer;
	FinalResult.WrongAnswerCount = NumOfWrongAnswer;
	FinalResult.PassOrFail = PassOrFail(NumOfRightAnswer, NumOfWrongAnswer);
	FinalResult.LevelName = LevelName(GameInfo.GameLevel);
	FinalResult.OperationName = OperationName(GameInfo.OperationType);

	return FinalResult;
	

}

stFinalRestul GameBeginning(int NumOfQuestion)
{
	stGameInfo GameInfo;

	GameInfo.NumOfQuestoin = NumOfQuestion;
	GameInfo.OperationType = GetOperationType();
	GameInfo.GameLevel = GetGameLevel();

	return GenerateQuestion(GameInfo);
}

void ShowPassOrFail(enPassOrFail PassOrFail)
{
	if (PassOrFail == enPassOrFail::Pass)
	{
		cout << "\n------------------------------------\n";
		cout << "\tFinal Result Is Paas :-) \n";
		cout << "------------------------------------\n";
	}
	else if (PassOrFail == enPassOrFail::Fail)
	{
		cout << "\n------------------------------------\n";
		cout << "\tFinal Result Is Fail :-( \n";
		cout << "------------------------------------\n";
	}
	else
	{
		cout << "\n------------------------------------\n";
		cout << "\tFinal Result Is Draw :-| \n";
		cout << "------------------------------------\n";
	}

}

void ShowFinalResult(stFinalRestul FinalResult)
{
	cout << "\n\n";
	ShowPassOrFail(FinalResult.PassOrFail);
	cout << "\n=================================\n";
	cout << "Number of Questions  : " << FinalResult.NumOfQuestoin << endl;
	cout << "Level of Game        : " << FinalResult.LevelName << endl;
	cout << "Operation Type       : " << FinalResult.OperationName << endl;
	cout << "Correct Answers      : " << FinalResult.RightAnswerCount << endl;
	cout << "Incorrect Answers    : " << FinalResult.WrongAnswerCount << endl;
	cout << "=================================\n";

}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void StartGame()
{
	char PlayAgain = 'y';
	do
	{
		ResetScreen();

		int Num = HowManyQuestion();

		stFinalRestul Result = GameBeginning(Num);

		ShowFinalResult(Result);

		cout << "\nDo you want to play again? (y/n): ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}



int main()
{
	srand((unsigned)time(NULL));

	StartGame();


	return 0;
}