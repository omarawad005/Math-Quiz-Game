# 🧮 Math Quiz Game

<p align="center">
  <strong>A simple and interactive Math Quiz console game built with C++</strong>
</p>

<p align="center">
  🎯 Random Questions &nbsp; | &nbsp; 🧠 Difficulty Levels &nbsp; | &nbsp; ➕ Multiple Operations
</p>

---

## 📌 About The Project

**Math Quiz Game** is a console-based game developed using **C++**.

The game generates random mathematical questions based on the selected **difficulty level** and **operation type**.

The player answers each question, and the game checks the answer while keeping track of the correct and incorrect responses.

At the end of the game, a final result is displayed showing the player's overall performance.

---

## ✨ Features

* 🎯 Randomly generated questions
* 🧠 Easy, Medium, Hard, and Mix levels
* ➕ Addition
* ➖ Subtraction
* ✖️ Multiplication
* ➗ Division
* 🔀 Mixed operations
* ✅ Correct answer detection
* ❌ Wrong answer detection
* 📊 Score tracking
* 🏆 Pass / Fail / Draw result
* 🎨 Console screen colors
* 🔄 Play Again option

---

## 🛠️ Technologies

<p align="center">

<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white">

<img src="https://img.shields.io/badge/Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white">

<img src="https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white">

<img src="https://img.shields.io/badge/GitHub-181717?style=for-the-badge&logo=github&logoColor=white">

</p>

---

## 🎮 How The Game Works

The game starts by asking the player to enter the number of questions.

Then the player selects the **operation type** and **difficulty level**.

For each question:

```text
Generate Random Numbers
          ↓
   Select Operation
          ↓
    Display Question
          ↓
   Enter User Answer
          ↓
     Check Answer
          ↓
    Update The Score
```

After all questions are completed, the game displays the final results.

---

## 🧠 Difficulty Levels

|  Level | Number Range |
| :----: | :----------: |
|  Easy  |    1 - 10    |
| Medium |    10 - 50   |
|  Hard  |   50 - 100   |
|   Mix  |    1 - 100   |

---

## ➕ Operation Types

| Option |    Operation   |
| :----: | :------------: |
|    1   |    Addition    |
|    2   |   Subtraction  |
|    3   | Multiplication |
|    4   |    Division    |
|    5   |       Mix      |

---

## 🏆 Game Result

The game compares the number of correct and incorrect answers.

| Correct Answers | Incorrect Answers |  Result  |
| :-------------: | :---------------: | :------: |
|       More      |        Less       | **Pass** |
|       Less      |        More       | **Fail** |
|      Equal      |       Equal       | **Draw** |

---

## 📂 Project Structure

```text
Math-Quiz-Game/
│
├── 📄 Math_Game.sln
│
├── 📁 Project_2_solve/
│   ├── 📄 Project_2_solve.cpp
│   ├── 📄 Project_2_solve.vcxproj
│   └── 📄 Project_2_solve.vcxproj.filters
│
├── 📄 .gitignore
└── 📄 README.md
```

---

## ▶️ How To Run

### 1. Clone the repository

```bash
git clone https://github.com/omarawad005/Math-Quiz-Game.git
```

### 2. Open the project

Open:

```text
Math_Game.sln
```

using **Visual Studio**.

### 3. Build & Run

Build the solution and run the application.

---

## 🖥️ Example

```text
Enter Number of Question : 3

Enter Operation You need [1]:Add, [2]:Sub, [3]:Mult, [4]:Div, [5]:Mix ? 5

Enter Level of Game [1]:Easy, [2]:Meduim, [3]:Hard, [4]:Mix ? 1


Question [1 / 3] :

7
3   +
--------
10

Right Answer :-)
```

---

## 📚 What I Practiced

This project helped me practice:

* `struct`
* `enum`
* Functions
* References
* Loops
* `switch`
* Conditional Statements
* Random Number Generation
* Input Validation
* Mathematical Operations
* Game Logic
* Passing Structures to Functions
* Returning Structures from Functions
* Git & GitHub

---

## 🚀 Future Improvements

* Improve division handling
* Add a timer for each question
* Add more mathematical operations
* Add more detailed statistics
* Improve the console interface
* Add a graphical user interface

---

## 👨‍💻 Author

### Omar Awad

<p align="center">

<a href="https://github.com/omarawad005"> <img src="https://img.shields.io/badge/GitHub-omarawad005-181717?style=for-the-badge&logo=github"> </a>

</p>

<p align="center"> ⭐ If you found this project useful, feel free to star the repository! </p>
