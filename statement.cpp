#include "statement.hpp"

#include <array>
#include <cctype>
#include <cstddef>

// Anonymous Namespace to enforce internal linkage
namespace {
    struct Statements {
        std::string_view keyword;
        minidb::StatementType type;
    };
}


namespace minidb {

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
