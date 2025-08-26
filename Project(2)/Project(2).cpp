#include <iostream>
#include <cmath> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med, Hard, Mix };
enum enOperationsType { Add = 1, Sub, Mul, Div, MixOp };

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionsLevel Questionlevel;
	enOperationsType OperationType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuize
{
	stQuestion QuestionsList[100];
	short NumberOfQuestions;
	enOperationsType OpType;
	enQuestionsLevel QuestionsLevel;
	short NumberOfWrongAnswer = 0;
	short NumberOfRightAnswer = 0;
	bool IsPass = false;
};

string GetOpTypeSymbol(enOperationsType OperationsType)
{
	switch (OperationsType)
	{
	case enOperationsType::Add:
		return "+";
		break;
	case enOperationsType::Sub:
		return "-";
		break;
	case enOperationsType::Mul:
		return "*";
		break;
	case enOperationsType::Div:
		return "/";
		break;
	default:
		return "Mix";
		break;
	}
}

string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy","Mid","Hard","Mix" };

	return arrQuestionLevelText[QuestionLevel - 1];
}

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;

	return randNum;
}

void SetColorScreen(bool Right)
{
	if (Right)
	{
		system("color 2f");
	}
	else
	{
		system("color 4f");
		cout << "\a";
	}
}

int ReadHowManyQuestions()
{
	int NumberOfQuestions;
	do
	{
		cout << "How Many Questions do you to want answer ? ";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions>10);

	return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionLevel;

	do
	{
		cout << "Enter Questions Level [1] Easy, [2] Med, [3]Hard, [4] Mix ? ";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel>4);

	return (enQuestionsLevel)QuestionLevel;
}

enOperationsType ReadOpType()
{
	short OpType;

	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul,[4] Div, [5] Mix ? ";
		cin >> OpType;

	} while (OpType < 1 || OpType>5);

	return (enOperationsType)OpType;
}

int SimpleCalculator(int Number1, int Number2, enOperationsType OpType)
{
	switch (OpType)
	{
	case enOperationsType::Add:
		return Number1 + Number2;
		break;
	case enOperationsType::Sub:
		return Number1 - Number2;
		break;
	case enOperationsType::Mul:
		return Number1 * Number2;
		break;
	case enOperationsType::Div:
		return Number1 / Number2;
		break;
	default:
		return Number1 + Number2;
	}
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationsType OpType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionsLevel::Mix)
	{
		QuestionLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}

	if (OpType == enOperationsType::MixOp)
	{
		OpType = (enOperationsType)RandomNumber(1, 4);
	}

	Question.OperationType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionsLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.Questionlevel = QuestionLevel;

		return Question;
		break;
	case enQuestionsLevel::Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.Questionlevel = QuestionLevel;

		return Question;
		break;
	case enQuestionsLevel::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);
		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		Question.Questionlevel = QuestionLevel;

		return Question;
		break;
	}

	return Question;
}

void GenerateQuizeQuestions(stQuize& Quize)
{
	for (short Question = 0; Question < Quize.NumberOfQuestions; Question++)
	{
		Quize.QuestionsList[Question] = GenerateQuestion(Quize.QuestionsLevel, Quize.OpType);
	}
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;

	return Answer;
}

void PrintTheQuestion(stQuize& Quize, short QuestionNumber)
{
	cout << "\n";
	cout << "Question[" << QuestionNumber + 1 << "/" << Quize.NumberOfQuestions << "]\n\n";
	cout << Quize.QuestionsList[QuestionNumber].Number1 << endl;
	cout << Quize.QuestionsList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSymbol(Quize.QuestionsList[QuestionNumber].OperationType);
	cout << "\n_________" << endl;

}

void CorrectTheQuestionAnswer(stQuize& Quize, short QuestionNumber)
{
	if (Quize.QuestionsList[QuestionNumber].PlayerAnswer != Quize.QuestionsList[QuestionNumber].CorrectAnswer)
	{
		Quize.QuestionsList[QuestionNumber].AnswerResult = false;
		Quize.NumberOfWrongAnswer++;

		cout << "Wrong Answer :-( \n";
		cout << "The Right Answer is: ";
		cout << Quize.QuestionsList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quize.QuestionsList[QuestionNumber].AnswerResult = true;
		Quize.NumberOfRightAnswer++;
		cout << "Right Answer :-) \n";
	}
	cout << endl;

	SetColorScreen(Quize.QuestionsList[QuestionNumber].AnswerResult);
}

void AskAndCorrectQuestionListAnswer(stQuize& Quize)
{
	for (short QuestionNumber = 0; QuestionNumber < Quize.NumberOfQuestions; QuestionNumber++)
	{
		PrintTheQuestion(Quize, QuestionNumber);
		Quize.QuestionsList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quize, QuestionNumber);
	}

	Quize.IsPass = (Quize.NumberOfRightAnswer >= Quize.NumberOfWrongAnswer);
}

string GetFinalResult(bool IsPass)
{
	if (IsPass)
	{
		return "PASS :-)";
	}

	return "FAIL :-(";
}

void PrintQuizeResults(stQuize Quize)
{
	cout << "\n";
	cout << "______________________________\n\n";

	cout << " Final Results Is " << GetFinalResult(Quize.IsPass);
	cout << "\n______________________________\n\n";
	cout << "Number of questions: " << Quize.NumberOfQuestions << endl;
	cout << "Questions Level : " <<
		GetQuestionLevelText(Quize.QuestionsLevel) << endl;
	cout << "OpType : " <<
		GetOpTypeSymbol(Quize.OpType) << endl;
	cout << "Number of Right Answers: " <<
		Quize.NumberOfRightAnswer << endl;
	cout << "Number of Wrong Answers: " <<
		Quize.NumberOfWrongAnswer << endl;
	cout << "______________________________\n";
}

void PlayMathGame()
{
	stQuize Quize;

	Quize.NumberOfQuestions = ReadHowManyQuestions();
	Quize.QuestionsLevel = ReadQuestionsLevel();
	Quize.OpType = ReadOpType();

	GenerateQuizeQuestions(Quize);
	AskAndCorrectQuestionListAnswer(Quize);
	PrintQuizeResults(Quize);
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

void StartGame()
{
	char playAgain = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "Do you want to play again? Y/N? ";
		cin >> playAgain;

	} while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	return 0;
}