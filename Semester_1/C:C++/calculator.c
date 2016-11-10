#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef enum { false = 0, true } bool;

typedef struct stackD {
  double *_data;
  size_t _size;
  int _head;
} stackD;

stackD* createStackD(const size_t size) {
  if (size > 1) {
    stackD *out = NULL;
    out = (stackD *) malloc(sizeof(stackD));
    if (out == NULL) {
      return NULL;
    }
    out->_data = (double *) malloc(size * sizeof(double));
    if (out->_data == NULL) {
      if (out) {
        free(out);
      }
      return NULL;
    }
    out->_size = size;
    out->_head = -1;
    return out;
  }
  return NULL;
}

void growStackD(stackD **stack) {
  size_t newSize = (*stack)->_size << 1;
  double *newData = (double *) malloc(newSize * sizeof(double));
  if (newData != NULL) {
    for (size_t i = 0; i < (*stack)->_size; ++i) {
      newData[i] = (*stack)->_data[i];
    }
    if ((*stack)->_data) {
      free((*stack)->_data);
    }
    (*stack)->_data = newData;
  } else {
    printf("[error]\n");
  }
}

void pushStackD(stackD **stack, const double value) {
  size_t size = (*stack)->_size;
  if ((*stack)->_head + 1 >= size) {
    growStackD(stack);
  }
  (*stack)->_data[++((*stack)->_head)] = value;
}

double popStackD(stackD **stack) {
  double out = (*stack)->_data[(*stack)->_head];
  --((*stack)->_head);
  return out;
}

double topStackD(stackD **stack) {
  int head = (*stack)->_head;
  if (head >= 0) {
    return (*stack)->_data[head];
  }
  return 0;
}

bool isEmptyStackD(stackD **stack) {
  return (*stack)->_head < 0;
}

size_t sizeStackD(stackD **stack) {
  return (*stack)->_head + 1;
}

void freeStackD(stackD **stack) {
  if ((*stack)->_data) {
    free((*stack)->_data);
  }
  if (*stack) {
    free(*stack);
  }
  *stack = NULL;
}

typedef struct stackC {
  char *_data;
  size_t _size;
  int _head;
} stackC;

stackC* createStackC(const size_t size) {
  if (size > 1) {
    stackC *out = NULL;
    out = (stackC *) malloc(sizeof(stackC));
    if (out == NULL) {
      return NULL;
    }
    out->_data = (char *) malloc(size * sizeof(char));
    if (out->_data == NULL) {
      if (out) {
        free(out);
      }
      return NULL;
    }
    out->_size = size;
    out->_head = -1;
    return out;
  }
  return NULL;
}

void growStackC(stackC **stack) {
  size_t newSize = (*stack)->_size << 1;
  char *newData = (char *) malloc(newSize * sizeof(char));
  if (newData != NULL) {
    for (size_t i = 0; i < (*stack)->_size; ++i) {
      newData[i] = (*stack)->_data[i];
    }
    if ((*stack)->_data) {
      free((*stack)->_data);
    }
    (*stack)->_data = newData;
  } else {
    printf("[error]\n");
  }
}

void pushStackC(stackC **stack, const char value) {
  size_t size = (*stack)->_size;
  if ((*stack)->_head + 1 >= size) {
    growStackC(stack);
  }
  (*stack)->_data[++((*stack)->_head)] = value;
}

char popStackC(stackC **stack) {
  char out = (*stack)->_data[(*stack)->_head];
  --((*stack)->_head);
  return out;
}

char topStackC(stackC **stack) {
  int head = (*stack)->_head;
  if (head >= 0) {
    return (*stack)->_data[head];
  }
  return 0;
}

bool isEmptyStackC(stackC **stack) {
  return (*stack)->_head < 0;
}

size_t sizeStackC(stackC **stack) {
  return (*stack)->_head + 1;
}

void freeStackC(stackC **stack) {
  if ((*stack)->_data) {
    free((*stack)->_data);
  }
  if (*stack) {
    free(*stack);
  }
  *stack = NULL;
}

#define MAX_LENGHT 128

typedef char* string_t;
typedef char operator_t;
typedef double value_t;
typedef bool* check_t;
typedef enum { null = 0, space, operator, digit, bracket, other } states;
typedef enum { error = -1, low, high } priorities;

bool isOperator(const char operator) {
  return
  operator == '+' || operator == '-' ||
  operator == '*' || operator == '/'
  ? true : false;
}

bool isDigit(const char digit) {
  return (digit >= '0') && (digit <= '9');
}

bool isOpen(const char symbol) {
  return symbol == '(';
}

bool isClosed(const char symbol) {
  return symbol == ')';
}

bool isBracket(const char symbol) {
  return isOpen(symbol) || isClosed(symbol);
}

states checkState(const string_t target, const size_t index) {
  char symbol = target[index];
  if (isspace(symbol)) {
    return space;
  } else if (isOperator(symbol)) {
    return operator;
  } else if (isDigit(symbol)) {
    return digit;
  } else if (isBracket(symbol)) {
    return bracket;
  }
  return other;
}

priorities checkPriority(const char operator) {
  return
  operator == '+' || operator == '-' ? low :
  operator == '*' || operator == '/' ? high : error;
}

value_t calculate(const value_t lhs, const operator_t operator, const value_t rhs, check_t check) {
  switch (operator) {
    case '+':
      return lhs + rhs;
    case '-':
      return lhs - rhs;
    case '*':
      return lhs * rhs;
    case '/':
      if (rhs == 0) {
        *check = false;
        return -1.;
      }
      return lhs / rhs;
    default:
      *check = false;
      return -1;
  }
}

bool isUnaryOperator(const states last) {
  return last == null || last == bracket;
}

void handleOperator(const string_t target, const size_t index, stackD **values, stackC **operators, int *bracketCount, const states last, size_t *unary, check_t check) {
  if (last == operator) {
    *check = false;
    return;
  }
  char currentOperator = target[index];
  bool isEmptyStackOperators = isEmptyStackC(operators);
  if (!isEmptyStackOperators) {
    char lastOperator = topStackC(operators);
    if (isOpen(lastOperator) && isUnaryOperator(last)) {
      if (currentOperator == '+') {
        printf("topop: %c\n", lastOperator);
      }
      ++(*unary);
    } else {
      while (checkPriority(currentOperator) <= checkPriority(lastOperator)) {
        if (currentOperator == '+') {
          printf("topop1: %c\n", lastOperator);
        }
        double rhs = popStackD(values);
        double lhs = popStackD(values);
        double result = calculate(lhs, lastOperator, rhs, check);
        if (!(*check)) {
          return;
        }
        pushStackD(values, result);
        popStackC(operators);
        lastOperator = topStackC(operators);
      }
    }
  } else if (isUnaryOperator(last)){
    ++(*unary);
  }
  char lastOperator = topStackC(operators);
  if (*unary == 0 || (*unary > 0 && *bracketCount > *unary)) {
    pushStackC(operators, currentOperator);
  }
}

void handleDigits(const string_t target, size_t *index, const size_t lenght, stackD **values, stackC **operators, int *bracketCount, const states last, size_t *unary, check_t check) {
  bool isDot = false;
  char bufferDigit[255];
  for (size_t iBuffer = 0; *index < lenght; ++(*index), ++iBuffer) {
    char digit = target[*index];
    if (isDigit(digit) || (!isDot && (target[*index] == '.' || target[*index] == '.'))) {
      bufferDigit[iBuffer] = digit;
      if (target[*index] == '.' || target[*index] == '.') {
        isDot = true;
      }
    } else if (isOperator(target[*index]) || isBracket(target[*index]) || isspace(target[*index])) {
      break;
    } else {
      *check = false;
      return;
    }
  }
  --(*index);
  double addDigit = atof(bufferDigit);
  char lastOperator = topStackC(operators);
  if (*unary > 0 && *bracketCount == *unary) {
    addDigit = -addDigit;
    --(*unary);
  }
  pushStackD(values, addDigit);
}

void handleBracket(const string_t target, const size_t index, stackD **values, stackC **operators, int *bracketCount, const states last, size_t *unary, check_t check) {
  char bracket = target[index];
  if (isOpen(bracket)) {
    pushStackC(operators, bracket);
    ++(*bracketCount);
  } else if (isClosed(bracket)) {
    --(*bracketCount);
    if (*bracketCount < 0) {
      *check = false;
      return;
    }
    char lastOperator = topStackC(operators);
    while (sizeStackD(values) > 1 && !isOpen(lastOperator)) {
      double rhs = popStackD(values);
      double lhs = popStackD(values);
      double result = calculate(lhs, lastOperator, rhs, check);
      if (!(*check)) {
        return;
      }
      pushStackD(values, result);
      popStackC(operators);
      lastOperator = topStackC(operators);
    }
    popStackC(operators);
  }
}

string_t calculator(const string_t target) {
  size_t lenght = strlen(target);
  if (lenght >= 1) {
    stackD *values = createStackD(4);
    stackC *operators = createStackC(4);
    bool check = true;
    size_t unary = 0;
    int bracketCount = 0;
    states last = null;
    for (size_t i = 0; i < lenght; ++i) {
      states state = checkState(target, i);
      switch (state) {
        case space:
        case null:
          printf("sp\n");
          continue;
        case operator:
          printf("op\n");
          handleOperator(target, i, &values, &operators, &bracketCount, last, &unary, &check);
          printf("operat: %c\n", topStackC(&operators));
          printf("un: %zu\n\n", unary);
          if (!check) {
            freeStackD(&values);
            freeStackC(&operators);
            return "e";
          }
          last = state;
          break;
        case digit:
          printf("dg\n");
          handleDigits(target, &i, lenght, &values, &operators, &bracketCount, last, &unary, &check);
          printf("digit: %f\n", topStackD(&values));
           printf("un: %zu\n\n", unary);
          if (!check) {
            freeStackD(&values);
            freeStackC(&operators);
            return "e";
          }
          last = state;
          break;
        case bracket:
          printf("br\n");
          handleBracket(target, i, &values, &operators, &bracketCount, last, &unary, &check);
          printf("operat: %c\n", topStackC(&operators));
          printf("un: %zu\n\n", unary);
          if (!check) {
            freeStackD(&values);
            freeStackC(&operators);
            return "e";
          }
          last = state;
          break;
        case other:
          printf("ot\n");
          freeStackD(&values);
          freeStackC(&operators);
          return "e";
      }
    }
    while (!isEmptyStackC(&operators)) {
      char lastOperator = popStackC(&operators);
      double rhs = popStackD(&values);
      double lhs = popStackD(&values);
      double result = calculate(lhs, lastOperator, rhs, &check);
      if (!check) {
        freeStackD(&values);
        freeStackC(&operators);
        return "e";
      }
      pushStackD(&values, result);
    }
    char *resultCalculate = (char *) malloc(255 * sizeof(char));
    sprintf(resultCalculate, "%f", topStackD(&values));
    freeStackD(&values);
    freeStackC(&operators);
    return resultCalculate;
  } else {
    return "e";
  }
}

int main() {
  char target[MAX_LENGHT];
  gets(target);
  string_t result = calculator(target);
  if (result[0] == 'e') {
    printf("[error]\n");
    return 0;
  }
  printf("%.2f\n", atof(result));
  return 0;
}
