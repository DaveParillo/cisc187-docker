#include <cstring>
#include <iostream>
 
// define a function signature that will
// transform one char to another
using transform = char (*)(const char c);


static void usage(const char* name) {
    std::cerr << "Encrypt or decrypt a single line of text read from standard input\n"
        << "Usage: " << name << " [-h]\n";
}

static void help (const char* name) {
    usage(name);
    std::cerr << "Options:\n"
        << "  -h   Show this text\n"
        << "\nRunning with no input from standard in enters 'interactive mode'.\n"
        << "Text can be entered one per line.\n"
        << "The program runs until 'CTRL+C' is entered or EOF is reached.\n\n"
        << "Running on plain text creates cipher text\n"
        << "Running on cipher text creates plain text\n\n";
    exit(0);
}

char rot13(const char c) {
    if (!std::isalpha(c)) return c;

    // in order to rotate upper or lower case
    // need to know where the alphabet 'starts'
    char const start = std::islower(c) ? 'a' : 'A';
    return (c - start + 13) % 26 + start;
}

void render_text(char* message, transform handler) {
    if (!message) return;
    do {
        std::cout << handler(*message);
    } while (*message++);
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    // giving us an option to swap in different encryption function
    transform handler = rot13;

    for (int i=1; i < argc; ++i) {
        if (!std::strcmp(argv[i], "-h")) {
            help(*argv);
        } else {
            usage(*argv);
            exit(-1);
        }
    }

    constexpr auto max_line_length = 200u;
    char message[max_line_length];
    while (std::cin.getline(message, max_line_length)) {
        render_text(message, handler);
    }
}
