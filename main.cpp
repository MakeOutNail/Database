#include <iostream>
#include <string>
#include <array>
#include <string_view>
#include <cctype>
#include <cstddef>

// Anonymous Namespace to enforce internal linkage
namespace {

    enum class StatementType {
        insert,
        select,
        unrecognized
    };


    struct Statements {
        std::string_view keyword;
        StatementType type;
    };


    StatementType check_valid_statement(std::string_view aStatement) {

        std::array statements{
            Statements{"insert",StatementType::insert},
            Statements{"select",StatementType::select},};

        for (std::size_t i{0};i<statements.size();i++){

            if (aStatement.starts_with(statements[i].keyword)) {

                // static cast to turn this signed character into a unsigned character
                // (positive only) before it is processed as a integer
                if (aStatement.length()==statements[i].keyword.length()
                    || (aStatement.length()>statements[i].keyword.length()
                    && std::isspace(static_cast<unsigned char>(aStatement[statements[i].keyword.length()]))!=0)) {

                    return statements[i].type;
                }
            }
        }

        return StatementType::unrecognized;
    }


}


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



         switch (check_valid_statement(input)) {
             case StatementType::insert:
                 std::cout << "Recognized insert Statement: " << input << std::endl; break;
             case StatementType::select:
                 std::cout << "Recognized select Statement: " << input << std::endl; break;
             case StatementType::unrecognized:
                 std::cout << "Unrecognized statement: " << input << std::endl; break;
         }



    } while (true);


    return 0;
}
