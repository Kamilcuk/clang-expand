#ifndef CLANG_EXPAND_SEARCH_HPP
#define CLANG_EXPAND_SEARCH_HPP

// Project includes
#include "clang-expand/common/data.hpp"
#include "clang-expand/common/structures.hpp"

// Standard includes
#include <string>
#include <variant>
#include <vector>

namespace clang {
namespace tooling {
class CompilationDatabase;
}
}

namespace ClangExpand {
class Query;

class Search {
 public:
  using CompilationDatabase = clang::tooling::CompilationDatabase;
  using SourceVector = std::vector<std::string>;
  using Result = DefinitionData;
  using ResultOrError = std::variant<int, Result>;

  Search(const std::string& file, unsigned line, unsigned column);

  ResultOrError
  run(CompilationDatabase& compilationDatabase, const SourceVector& sources);

 private:
  int _symbolSearch(CompilationDatabase& compilationDatabase, Query& query);
  int _definitionSearch(CompilationDatabase& compilationDatabase,
                        const SourceVector& sources,
                        Query& query);

  EasyLocation _location;
};
}  // namespace ClangExpand

#endif  // CLANG_EXPAND_SEARCH_HPP
