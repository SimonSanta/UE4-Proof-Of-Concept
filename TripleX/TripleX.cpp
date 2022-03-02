#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Introductory message to the terminal
    std::cout << "Your are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
 
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print CodeSum and CodeProduct to the terminal
    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "+ The codes add-up to: "<< CodeSum << "\n";
    std::cout << "+ The codes multiply to: "<< CodeProduct << "\n";

    // Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Good job agent! ***\n";
        std::cout << "*** Level " << Difficulty << " is completed, you have succesfully extrated a file! Move to next step!\n\n";
        return true;
    }
    else
    {
        std::cout << "\n*** Wrong code agent! Try again! ***\n\n";
        return false;
    }
}

int main()
{   
    srand(time(NULL)); // Create new random sequence based on the current time of day

    int LevelDifficulty = 1 ;
    int const MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty) // Loop until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty); 
        std::cin.clear(); // Clears any error
        std::cin.ignore(); // Discards any error

        if(bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "Great job agent! You have extracted all the files! Get out of here without getting caught!";
    return 0;
}