#include <iostream>
#include <ctime>

using namespace std;

bool CheckSameDigits(int num) {
    int arrNum[4];
    
    arrNum[0] = num / 1000;
    arrNum[1] = num / 100 % 10;
    arrNum[2] = num / 10 % 10;
    arrNum[3] = num % 10;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (i != j and arrNum[i] == arrNum[j])
            {
                return true;
            }
        }
    }

    return false;
}

bool CheckNum(int num) {
    if (num > 9876 or num < 1234)
    {
        cout << "Enter a four-digit number from 1234 to 9876" << endl;
        return false;
    }

    if (CheckSameDigits(num))
    {
        cout << "Enter a number without duplicate digits" << endl;
        return false;
    }

    return true;
}

int CountCows(int inputNum, int hiddenNum) {
    int arrInputNum[4];
    
    arrInputNum[0] = inputNum / 1000;
    arrInputNum[1] = inputNum / 100 % 10;
    arrInputNum[2] = inputNum / 10 % 10;
    arrInputNum[3] = inputNum % 10;

    int arrHiddenNum[4];

    arrHiddenNum[0] = hiddenNum / 1000;
    arrHiddenNum[1] = hiddenNum / 100 % 10;
    arrHiddenNum[2] = hiddenNum / 10 % 10;
    arrHiddenNum[3] = hiddenNum % 10;

    int cows = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arrInputNum[i] == arrHiddenNum[j])
            {
                cows++;
            }
        }
    }

    return cows;
}

int CountBulls(int inputNum, int hiddenNum) {
    int arrInputNum[4];
    
    arrInputNum[0] = inputNum / 1000;
    arrInputNum[1] = inputNum / 100 % 10;
    arrInputNum[2] = inputNum / 10 % 10;
    arrInputNum[3] = inputNum % 10;

    int arrHiddenNum[4];

    arrHiddenNum[0] = hiddenNum / 1000;
    arrHiddenNum[1] = hiddenNum / 100 % 10;
    arrHiddenNum[2] = hiddenNum / 10 % 10;
    arrHiddenNum[3] = hiddenNum % 10;

    int bulls = 0;

    for (int i = 0; i < 4; i++)
    {
        if (arrInputNum[i] == arrHiddenNum[i])
        {
            bulls++;
        }
    }

    return bulls;
}

int Output(int hiddenNum) {
    int inputNum;
    cin >> inputNum;
    
    if (!CheckNum(inputNum))
    {
        Output(hiddenNum);
        return 0;
    }
    
    int cows = CountCows(inputNum, hiddenNum);
    int bulls = CountBulls(inputNum, hiddenNum);

    if (bulls == 4)
    {
        return bulls;
    }

    cout << "Cows: " << cows << endl;
    cout << "Bulls: " << bulls << endl;
    cout << "HiddenNum: " << hiddenNum << endl;

    return bulls;
}

int main() {
    srand(time(NULL));

    int inputNum, hiddenNum;
    hiddenNum = rand() % 8643 + 1234;

    while (CheckSameDigits(hiddenNum))
    {
        hiddenNum = rand() % 8643 + 1234;
    }

    cout << "HiddenNum: " << hiddenNum << endl;
    int bulls = CountBulls(inputNum, hiddenNum);

    while (bulls != 4)
    {
        bulls = Output(hiddenNum);
    }
    
    cout << "Congratulations!" << endl;

    return 0;
}