#include <iostream>
#include <stack>
#include <string>

bool isBracket(const char bracket) {
  switch (bracket) {
    case '{':
    case '}':
    case '[':
    case ']':
    case '(':
    case ')':
      return true;
    default:
      return false;
  }
}

bool isClosed(const char lhs, const char rhs) {
  std::string cmp = "";
  cmp += lhs; cmp += rhs;
  return cmp == "()" || cmp == "[]" || cmp == "{}";
}

bool isOpen(const char bracket) {
  return bracket == '(' || bracket == '[' || bracket == '{';
}

bool otherSide_(const char lhs, const char rhs) {

  return !isOpen(lhs) && isOpen(rhs);
}

bool oneSide(const char lhs, const char rhs) {
  if (isOpen(lhs) && isOpen(rhs)) {
    return true;
  } else if (!isOpen(lhs) && !isOpen(rhs)) {
    return true;
  }
  return false;
}

char inverseBracket(const char bracket) {
  switch (bracket) {
    case '(':
      return ')';
    case ')':
      return '(';
    case '[':
      return ']';
    case ']':
      return '[';
    case '{':
      return '}';
    case '}':
      return '{';
    default:
      return ' ';
  }
}

std::string bracket(std::string *target) {
  std::stack<char> brackets;
  for (std::size_t i = 0; i < (*target).size(); ++i) {
    char bracket = (*target)[i];
    if ((bracket == '\\' && (*target)[i + 1] == 'n')) {
      ++i;
      continue;
    }
    if (isBracket(bracket)) {
      if (brackets.size() > 0) {
        char topBracket = brackets.top();
        if (isClosed(topBracket, bracket)) {
          brackets.pop();
        } else if (oneSide(topBracket, bracket) || otherSide_(topBracket, bracket)) {
          brackets.push(bracket);
        } else {
          return "IMPOSSIBLE";
        }
      } else {
        brackets.push(bracket);
      }
    } else {
      return "IMPOSSIBLE";
    }
  }
  std::string before = "";
  while (brackets.size() > 0) {
    char bracket = brackets.top();
    if (isOpen(bracket)) {
      *target += inverseBracket(bracket);
    } else {
      before += inverseBracket(bracket);
    }
    brackets.pop();
  }
  before += *target;
  return before;
}

int main() {
  std::string target;
  std::cin >> target;
  if (target.size() <= 200000) {
    std::string result = bracket(&target);
    std::cout << result << std::endl;
  }
  return 0;
}
