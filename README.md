# Matrix Row Sum Finder

## Description

This C program addresses the problem of identifying a row (or rows) in a square matrix of any size N x N, where the absolute sum of its elements is either the maximum or minimum in the matrix.

## Features

- **User Input Options:**
  - Manual input of matrix values.
  - Random generation of matrix values.

- **Display Options:**

  - Ability to display the generated matrix.

- **Output Information:**

  - Minimum and maximum values in the matrix.
  - Identification of the row(s) with the maximum and minimum absolute sum of elements.

- **Execution Time Measurement:**
  - Elapsed time calculation using the `clock()` function.

## How to Use

1. Run the program and enter the size of the square matrix (N x N).
2. Choose whether to input matrix values manually or generate random values.
3. If generating random values, choose whether to display the matrix.
4. View the minimum and maximum values in the matrix.
5. Identify the row(s) with the maximum and minimum absolute sum of elements.

## Implementation Details

- **Dynamic Memory Allocation:** Utilizes dynamic memory allocation for a 2D array.
- **User Input Validation:** Ensures proper validation for matrix size and menu choices.
- **Random Number Generation:** Generates random values for matrix elements within a specified range.
- **Elapsed Time Calculation:** Measures the elapsed time using the `clock()` function.
- **Readable Code Structure:** Organized code with functions for specific tasks.

## Sample Output

Lukas Lechovic 07
Zadanie 5:
Rieste problem, ktory v stvorcovej matici zadaneho lubovolneho rozmeru N x N najde riadok (riadky cislujte vo vystupe), ktoreho absolutna hodnota suctu jeho prvkov je maximum alebo minimum v danej matici.

Zadajte velkost stvorcovej matice: 3

(1) Prvky si zadate sami
(2) Prvky si nechate nahodne vygenerovat
Zadajte 1 alebo 2: 2

Chcete vypisat maticu ?
(1) Ano
(2) Nie
Zadajte 1 alebo 2: 1

(1) 25.73 83.45 -2.12
(2) 42.18 -6.78 71.43
(3) -4.21 63.11 19.86

Najmensia hodnota v matici je -6.78
Najvacsia hodnota v matici je 83.45

    SUCET               MIN               MAX

(1) 106.06 > -6.78 > 83.45
(2) 106.83 > -6.78 > 83.45
(3) 77.76 > -6.78 > 83.45

(The elapsed time is 0.000001 seconds)

Chcete program spustit znova?
(1) Ano
(2) Nie
Zadajte iba 1 alebo 2: 2

Dovidenia...
