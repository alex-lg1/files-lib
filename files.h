#include <fstream>
#include <iostream>
#include <string>

class files {

public:
    static void cfile(const char* crfile) {
        std::ofstream cl(crfile);
        if (!cl) {
            std::cout << "error creating file\n";
        }
    }
    static void wfile(const char* filename, const char* text) {
        std::ofstream ol(filename, std::ios::app);
        if (!ol) {
            std::cout << "error write to file\n";
        }
        ol << text;
    }

    static void wnfile(const char* filename, const char* text) {
        std::ofstream ol(filename, std::ios::app);
        if (!ol) {
            std::cout << "error write to file\n";
        }
        ol << text << "\n";
    }


    static std::string rfile(const char* filename) {
        std::ifstream il(filename);
        if (!il) {
            std::cout << "error read file\n";
        }
        std::string content((std::istreambuf_iterator<char>(il)),std::istreambuf_iterator<char>());
        return content;
    }

	void clearfile(const char* filename) {
    	std::ofstream fl(filename, std::ios::trunc);
    	if (!fl) {
    	    std::cout << "error clear file\n";
    	}
	}

    void list(const char* filename) {
        std::ifstream fin(filename);
        if (!fin) {
            std::cout << "empty file\n";
            return;
        }
    std::cout << "list:\n";
    std::string line;
    int count = 1;
    while (std::getline(fin, line)) {
        std::cout << count << ". " << line << std::endl;
        count++;
    }
    fin.close();
    }

};
files files;

