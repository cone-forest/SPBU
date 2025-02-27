#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string_view>

enum State : uint32_t {
  A, B, C, D, E, F, G, H, I,
};

int get_matching(std::string_view tape, int &pos) {
  if (pos == tape.size()) {
    return -1;
  }

  State state = State::A;
  int beg = pos;

  while (state != State::C) {
    if (pos == tape.size()) {
      return -1;
    }
    if (tape[pos] != '%' &&
        tape[pos] != '+' &&
        tape[pos] != 'x' &&
        tape[pos] != '?'
        ) {
      pos++;
      return -1;
    }

    switch (state) {
      case A:
        switch (tape[pos]) {
          case '%':
            state = State::B;
            break;
        }
        break;
      case B:
        switch (tape[pos]) {
          case '%':
            state = State::C;
            break;
          default:
            state = State::D;
            break;
        }
        break;
      case C:
        break;
      case D:
        switch (tape[pos]) {
          case 'x':
            state = State::F;
            break;
          default:
            state = State::E;
            break;
        }
        break;
      case E:
        switch (tape[pos]) {
          case 'x':
            state = State::F;
            break;
        }
        break;
      case F:
        state = State::G;
        break;
      case G:
        switch (tape[pos]) {
          case '%':
            state = State::C;
            break;
          default:
            state = State::H;
            break;
        }
        break;
      case H:
        switch (tape[pos]) {
          case '%':
            state = State::C;
            break;
          case 'x':
            state = State::F;
            break;
          default:
            state = State::I;
            break;
        }
        break;
      case I:
        switch (tape[pos]) {
          case '%':
            state = State::C;
            break;
          case 'x':
            state = State::F;
            break;
        }
        break;
    }

    pos++;
  }

  return beg;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    return 47;
  }

  auto tape = argv[1];
  int pos = 0;
  int beg = get_matching(tape, pos);

  if (beg == -1) {
    printf("No matching shit");
    return 1;
  }

  while (pos != strlen(tape)) {
    if (beg >= 0) {
      printf("%d ", beg);
      for (int i = beg; i < pos; i++) {
        printf("%c", tape[i]);
      }
      printf("\n");
    }

    beg = get_matching(tape, pos);
  }
  if (beg >= 0) {
    printf("%d ", beg);
    for (int i = beg; i < pos; i++) {
      printf("%c", tape[i]);
    }
    printf("\n");
  }
}
