# Math Quiz Game 🧮

A console-based mathematical quiz game built in C++ that challenges users with arithmetic problems of varying difficulty levels. This project demonstrates the implementation of **functional programming principles** within C++ to create a modular, maintainable, and well-structured application.

## 🎯 Features

- **Multiple Difficulty Levels**: Easy (1-10), Medium (10-50), Hard (50-100), and Mixed
- **Various Operations**: Addition, Subtraction, Multiplication, Division, and Mixed operations
- **Customizable Quiz Length**: 1-10 questions per session
- **Real-time Feedback**: Immediate answer validation with visual feedback
- **Score Tracking**: Comprehensive results display with pass/fail determination
- **Visual Feedback**: Color-coded responses (green for correct, red for incorrect)
- **Replay Functionality**: Option to play multiple rounds

## 🔧 Technical Implementation

### Functional Programming Approach

This project heavily utilizes **functional programming principles** in C++:

#### 1. **Pure Functions**
The code is structured around pure functions that produce consistent outputs for given inputs without side effects:

```cpp
// Pure mathematical calculation
int SimpleCalculator(int Number1, int Number2, enOperationsType OpType)

// Pure random number generation
int RandomNumber(int From, int To)

// Pure string conversion functions
string GetOpTypeSymbol(enOperationsType OperationsType)
string GetQuestionLevelText(enQuestionsLevel QuestionLevel)
```

#### 2. **Function Composition**
Complex operations are built by composing simpler functions:

```cpp
// Question generation combines multiple pure functions
stQuestion GenerateQuestion(enQuestionsLevel QuestionLevel, enOperationsType OpType)
{
    // Composes RandomNumber() and SimpleCalculator()
    Question.Number1 = RandomNumber(1, 10);
    Question.Number2 = RandomNumber(1, 10);
    Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
}
```

#### 3. **Immutable Data Structures**
Uses structs to encapsulate data with clear separation between data and behavior:

```cpp
struct stQuestion {
    int Number1, Number2;
    enQuestionsLevel Questionlevel;
    enOperationsType OperationType;
    int CorrectAnswer;
    int PlayerAnswer;
    bool AnswerResult;
};
```

#### 4. **Higher-Order Functions Pattern**
Functions that operate on other functions and data transformations:

```cpp
// Processes each question through a functional pipeline
void AskAndCorrectQuestionListAnswer(stQuize& Quize)
{
    for (short QuestionNumber = 0; QuestionNumber < Quize.NumberOfQuestions; QuestionNumber++)
    {
        PrintTheQuestion(Quize, QuestionNumber);           // Display function
        Quize.QuestionsList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();  // Input function
        CorrectTheQuestionAnswer(Quize, QuestionNumber);   // Validation function
    }
}
```

#### 5. **Enumeration-Based Type Safety**
Uses enumerations for type-safe functional programming:

```cpp
enum enQuestionsLevel { Easy = 1, Med, Hard, Mix };
enum enOperationsType { Add = 1, Sub, Mul, Div, MixOp };
```

## 🏗️ Project Structure

### Core Components

1. **Data Types**
   - `stQuestion`: Encapsulates individual question data
   - `stQuize`: Contains quiz configuration and results
   - Enumerations for type-safe operations

2. **Functional Modules**
   - **Input Functions**: `ReadHowManyQuestions()`, `ReadQuestionsLevel()`, `ReadOpType()`
   - **Generation Functions**: `GenerateQuestion()`, `GenerateQuizeQuestions()`
   - **Utility Functions**: `RandomNumber()`, `SimpleCalculator()`, `GetOpTypeSymbol()`
   - **Display Functions**: `PrintTheQuestion()`, `PrintQuizeResults()`
   - **Validation Functions**: `CorrectTheQuestionAnswer()`

3. **Game Flow Control**
   - `PlayMathGame()`: Main game orchestration
   - `StartGame()`: Session management with replay functionality

## 🎮 How to Use

### Compilation
```bash
g++ -o math_quiz math_quiz.cpp
```

### Running the Game
```bash
./math_quiz
```

### Game Flow
1. **Setup Phase**:
   - Choose number of questions (1-10)
   - Select difficulty level (Easy/Medium/Hard/Mix)
   - Choose operation type (Add/Sub/Mul/Div/Mix)

2. **Quiz Phase**:
   - Answer each question as it appears
   - Receive immediate feedback
   - Visual color coding for correct/incorrect answers

3. **Results Phase**:
   - View comprehensive results summary
   - See pass/fail status (pass requires ≥50% correct)
   - Option to play again

## 🎯 Functional Programming Benefits Demonstrated

1. **Modularity**: Each function has a single, well-defined purpose
2. **Reusability**: Functions like `RandomNumber()` and `SimpleCalculator()` are used throughout
3. **Testability**: Pure functions are easy to unit test
4. **Maintainability**: Clear separation of concerns makes code easy to modify
5. **Readability**: Function names clearly describe their purpose
6. **Type Safety**: Enumerations prevent invalid state combinations

## 🔄 Program Flow

```
Start → Setup Quiz Parameters → Generate Questions → 
Ask Questions → Validate Answers → Display Results → 
Play Again? → End/Restart
```

## 🎨 Visual Features

- **Color Coding**: 
  - Green background for correct answers
  - Red background for incorrect answers (with audio beep)
- **Clear Formatting**: Well-structured question display with visual separators
- **Progress Tracking**: Question counter shows current position

## 🛠️ Requirements

- **C++ Compiler**: Supporting C++11 or later
- **Operating System**: Windows (for `system()` color commands)
- **Standard Libraries**: `<iostream>`, `<cmath>`, `<string>`, `<cstdlib>`, `<ctime>`

## 🚀 Future Enhancements

- Cross-platform color support
- Question timing functionality
- Score history tracking
- Different mathematical operations (powers, roots)
- GUI implementation
- Network multiplayer support

## 📝 Code Quality Features

- **Consistent Naming**: Hungarian notation for variables
- **Clear Structure**: Logical function organization
- **Error Handling**: Input validation for user entries
- **Resource Management**: Proper memory usage with stack allocation
- **Documentation**: Self-documenting function and variable names

---

This project showcases how functional programming principles can be effectively applied in C++ to create clean, maintainable, and well-structured code while building an engaging educational application.
