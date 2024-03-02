#include <iostream>
#include <random>
#include <limits>

int randomNumberGenerator()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 30);
    return distribution(generator);
}

int main()
{
    int rounds, randomNumber, winCount = 0;
    std::cout << "You get three guesses every round with hints (numbers 1-30)\n";
    std::cout << "How many rounds do you want to play: ";
    std::cin >> rounds;
    for (int i = 0; i < rounds; i++)
    {
        randomNumber = randomNumberGenerator();
        bool won = false;

        for (int guessNum = 0; guessNum < 3; guessNum++)
        {
            int guess;
            std::cout << "Enter your guess " << guessNum + 1 << ": ";
            std::cin >> guess;

            if (guess == randomNumber)
            {
                winCount++;
                won = true;
                std::cout << "You guessed correctly!\n";
                break; // Exit the guess loop if correct
            }
            else
            {
                int difference = std::abs(randomNumber - guess);
                if (difference < 3)
                {
                    std::cout << "You're within 3 of the answer\n";
                }
                else if (difference < 5)
                {
                    std::cout << "You're within 5 of the answer\n";
                }
                else
                {
                    std::cout << "You're further than 5 numbers away\n";
                }
            }
        }
        if (!won)
        {
            std::cout << "You're out of guesses! The number was " << randomNumber << "\n";
        }
    }
    std::cout << "You won " << winCount << "times\n";
    return 0;
}
