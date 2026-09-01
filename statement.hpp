#pragma once
#include <string_view>


namespace minidb{

    enum class StatementType {
        insert,
        select,
        unrecognized
    };

    StatementType check_valid_statement(std::string_view aStatement);

}





