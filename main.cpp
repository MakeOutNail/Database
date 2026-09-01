#include <iostream>
#include <string>
#include "statement.hpp"


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

         if (input==".exit") {
             break; // Proper local variable cleanup
         }
         else if (input.starts_with('.')){
             std::cout<< "Unrecognized command: " << input << std::endl;
         }
         else {
             switch (minidb::check_valid_statement(input)) {
                 case minidb::StatementType::insert:
                     std::cout << "Recognized insert Statement: " << input << std::endl; break;
                 case minidb::StatementType::select:
                     std::cout << "Recognized select Statement: " << input << std::endl; break;
                 case minidb::StatementType::unrecognized:
                     std::cout << "Unrecognized statement: " << input << std::endl; break;
             }
         }

    } while (true);


    return 0; // Successful
}
