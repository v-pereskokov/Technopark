#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

typedef enum { false, true } bool;

const int MAX_SIZE = 256;

typedef enum Priority
{
  low, /*!< Низкий приоритет(для '+' и '-')*/
  medium, /*!< Средний приоритет(для '*' и '/')*/
  high, /*!< Высокий приоритет(для '^')*/
  error = -1 /*!< В случае иных операторов(или символов)*/
} Priority;

// Стэк для double
struct StackD
{
  double _value; /*!< Значение */
  struct StackD *_next; /*!< Указатель на следующий элемент*/
};

void pushD(struct StackD **stack, const double value)
{
  struct StackD *tmp = (struct StackD *) malloc(sizeof(struct StackD));
  tmp->_value = value;
  tmp->_next = *stack;
  *stack = tmp;
}

void popD(struct StackD **stack)
{
  struct StackD *tmp;
  tmp = *stack;
  *stack = (*stack)->_next;
  if (tmp)
    free(tmp);
}

struct StackD* popDN(struct StackD **stack) {
  struct StackD *tmp;
  if ((*stack) != NULL) {
    tmp = *stack;
    *stack = (*stack)->_next;
    return tmp;
  }
  return NULL;
}

double topD(struct StackD **stack)
{
  return (*stack)->_value;
}

size_t getSizeD(const struct StackD *stack) {
  size_t size = 0;
  while (stack) {
    ++size;
    stack = stack->_next;
  }
  return size;
}

// Стэк для char
struct StackC
{
  char _value; /*!< Значение */
  struct StackC *_next; /*!< Указатель на следующий элемент*/
};

void pushC(struct StackC **stack, const char value)
{
  struct StackC *tmp = (struct StackC *) malloc(sizeof(struct StackC));
  tmp->_value = value;
  tmp->_next = *stack;
  *stack = tmp;
}

void popC(struct StackC **stack)
{
  struct StackC *tmp;
  tmp = *stack;
  *stack = (*stack)->_next;
  if (tmp)
    free(tmp);
}

struct StackC* popCN(struct StackC **stack) {
  struct StackC *tmp;
  if ((*stack) != NULL) {
    tmp = *stack;
    *stack = (*stack)->_next;
    return tmp;
  }
  return NULL;
}

char topC(struct StackC **stack)
{
  return (*stack)->_value;
}

size_t getSizeC(const struct StackC *stack) {
  size_t size = 0;
  while (stack) {
    ++size;
    stack = stack->_next;
  }
  return size;
}

void memoryClean(struct StackC *chars, struct StackD *doubles)
{
  struct StackC *tmpC = NULL;
  while (chars) {
    tmpC = popCN(&chars);
    if (tmpC)
      free(tmpC);
  }
  struct StackD *tmpD = NULL;
  while (doubles) {
    tmpD = popDN(&doubles);
    if (tmpD)
      free(tmpD);
  }
}

bool isOperator(char operators)
{
  return
  operators == '+' || operators == '-' ||
  operators == '*' || operators == '/' ||
  operators == '^' ? true : false;
}

Priority priority(char operators)
{
  return
  operators == '+' || operators == '-' ? low :
  operators == '*' || operators == '/' ? medium :
  operators == '^' ? high : error;
}

char action(char operators, struct StackD **values)
{
  double rhs = topD(values);
  popD(values);
  double lhs = topD(values);
  popD(values);
  switch (operators) {
    case '+':
      pushD(values, lhs + rhs);
      break;
    case '-':
      pushD(values, lhs - rhs);
      break;
    case '*':
      pushD(values, lhs * rhs);
      break;
    case '/':
      if (rhs == 0)
        return 'e';
      pushD(values, lhs / rhs);
      break;
    case '^':
      pushD(values, pow(lhs, rhs));
      break;
  }
  return 'g';
}

char *calculaton(const char *target)
{
  struct StackD *values = NULL; // Стек значений
  struct StackC *operators = NULL; // Стек операторов
  size_t sizeValues = 0; // Размер стека значений
  size_t sizeOperators = 0; // Размер стека операторов
  size_t isOpen = 0; // Число открывающих скобок
  size_t length = strlen(target); // Длина поданной строки
  for (size_t i = 0; i < length; ++i) {
    if (target[i] == '(') { // Если нашли открывающую скобку
      pushC(&operators, target[i]); // Заносим в стек
      ++sizeOperators;  // Увеличиваем счетчик операторов
      ++isOpen; // Скобка открыта
    } else if (target[i] == ')') { // Если нашли закрывающую скобку
      if (isOpen > 0) { // Если есть хотя бы одна открывающая
        while (topC(&operators) != '(') { // Пока не встретим открывающую скобку - выполняем операции
          if (sizeValues < 2) { // Проверяем на наличие в стеке хотя бы 2 значений
            memoryClean(operators, values);
            return "e";
          }
          char except = action(topC(&operators), &values); // Выполняем операции со значениями
          --sizeValues;
          if (except == 'e') {
            memoryClean(operators, values);
            return "e";
          }
          popC(&operators); // Удаляем из вершины использованный оператор
          --sizeOperators;
          if (sizeOperators <= 0) { // Выходим с ошибкой
            memoryClean(operators, values);
            return "e";
          }
        }
        --isOpen;
        popC(&operators); // Удаляем из вершины скобку '('
        --sizeOperators;
      } else { // Выходим с ошибкой
        memoryClean(operators, values);
        return "e";
      }
    } else if (isOperator(target[i]) == true) { // Если символ - оператор
      while (sizeOperators > 0 && priority(topC(&operators)) >= priority(target[i])) { // Проверяем приоритет и если операторы уже есть
        if (sizeOperators >= sizeValues) {
          memoryClean(operators, values);
          return "e";
        }
        char except = action(topC(&operators), &values); // Находим значение, если приоритет операции ниже i
        --sizeValues;
        if (except == 'e') {
          memoryClean(operators, values);
          return "e";
        }
        popC(&operators);
        --sizeOperators;
      }
      pushC(&operators, target[i]); // В ином случае просто добавляем еще один оператор
      ++sizeOperators;
    } else if (isdigit(target[i])) { // Если встретили число
      char operand[MAX_SIZE]; // Массив для числа
      size_t sizeOperand = 0;
      bool isDot = false; // Есть ли точка или запятая
      while (i < length && (isdigit(target[i]) || (isDot == false && (target[i] == '.' || target[i] == ',')))) {
        if (isDot == false && target[i] == ',') { // Если встретили запятую, в массив добавляем точку
          operand[sizeOperand] = '.';
          ++sizeOperand;
          continue;
        }
        operand[sizeOperand] = target[i];
        ++sizeOperand;
        ++i;
      }
      ++sizeValues;
      --i;
      pushD(&values, atof(operand)); // Добавляем в стек число
    } else if (target[i] == ' ') // Если встретили пробел - идем дальше
      continue;
    else {
      memoryClean(operators, values);
      return "e";
    }
  }
  if (isOpen > 0 || sizeOperators >= sizeValues) { // Если открывающие скобки все еще остались - неверная скобочная последовательность => выходим
    memoryClean(operators, values);
    return "e";
  }
  while (sizeOperators > 0) { // Если операторы еще остались - считаем оставшиеся значения
    char except = action(topC(&operators), &values);
    --sizeValues;
    if (except == 'e') {
      memoryClean(operators, values);
      return "e";
    }
    popC(&operators);
    --sizeOperators;
  }
  printf("%.2f", topD(&values));
  printf("\n");
  memoryClean(operators, values);
  return "e";
}

int main()
{
  char *string = (char *) malloc(MAX_SIZE * sizeof(char));
  gets(string);
  char *result = calculaton(string);
  if (result[0] == 'e') {
    printf("[error]\n");
    return 0;
  }
  if (result)
    free(result);
  if (string)
    free(string);
  return 0;
}
