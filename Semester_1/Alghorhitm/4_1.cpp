#include <cstdio>
#include <cassert>

using u_int = unsigned int;

class Queue {
 public:
  explicit Queue(int size);
  ~Queue();
  void push(int element);
  int pop();
  bool isEmpty() const;
 private:
  int *_buffer;
  int _size;
  int _head;
  int _tail;
};

Queue::Queue(int size)
: _size(size), _head(0), _tail(0), _buffer(new int[size]) {}

Queue::~Queue() {
  delete [] _buffer;
}

void Queue::push(int element) {
  assert((_head - _tail + _size) % _size != 1);
  _buffer[_tail++] = element;
  if (_tail == _size)
    _tail = 0;
}

int Queue::pop() {
  if (_head != _tail) {
    int result = _buffer[_head++];
    if (_head == _size)
      _head = 0;
    return result;
  }
  return -1;
}

int main() {
  u_int n;
  scanf("%d", &n);
  if (n > 0 && n <= 1000000) {
    Queue q(n);
    int cmd;
    int element;
    bool flag = true;
    for (std::size_t i = 1; i <= n; ++i) {
      scanf("%d %d", &cmd, &element);
      switch (cmd) {
        case 2:
          if (element != q.pop())
            flag = false;
          break;
        case 3:
          q.push(element);
          break;
        default:
          break;
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
