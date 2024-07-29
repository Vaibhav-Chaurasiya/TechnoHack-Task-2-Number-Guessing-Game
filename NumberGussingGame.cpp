#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;
    bool guessedCorrectly = false;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    while (!guessedCorrectly) {
        // Get the user's guess
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Check if the input is valid
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(INT_MAX, '\n'); // Discard invalid input
            std::cout << "Please enter a valid number." << std::endl;
            continue;
        }

        attempts++;

        // Check the guess
        if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            guessedCorrectly = true;
            std::cout << "Congratulations! You've guessed the number " << secretNumber << " in " << attempts << " attempts." << std::endl;
        }
    }

    return 0;
}
