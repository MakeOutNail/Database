#include <iostream>
#include <string>

int main() {

     do{
         std::string input{};

         std::cout << "minidb> ";

         // Flushing the buffer
         std::cout << std::flush;

         if (!std::getline(std::cin, input)) {
             // EOF - End of File (CTRL + D)
             break;
         }

         if (input == ".exit") {
             break; // Proper local variable cleanup
         }


         std::cout << "Unrecognized command: " << input << "\n";


    } while (true);


    return 0;
}
