#include <iostream>
#include <string>
#include <list>
#include <boost/shared_ptr.hpp>
#include <cstdlib>
#include "fundoshi.hpp"
#include <sys/types.h>
#include <unistd.h>

#ifdef USE_FUNDOSHI_STRING
typedef fundoshi::string substring_type;
#else
typedef std::string substring_type;
#endif

int main(void){
	std::string tmp;
	
	// メモリを確保して作業する
	//std::string buf(200, '-');
	//std::string buf(400, '-');
	std::string buf("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	size_t num_substrings = (buf.length() * (buf.length() + 1)) / 2;
	substring_type * substrings = new substring_type[num_substrings];
	
	size_t i, len;
	size_t count = 0;
	
	for(i = 0; i < buf.length(); ++i){
		for(len = 1; len <= buf.length() - i; ++len){
			substrings[count] = substring_type(buf, i, len);
			++count;
		}
	}
	
	for(i = 0; i < num_substrings; ++i){
		std::cout << substrings[i] << std::endl;
	}
	
	// メモリが確保された状態で一旦休止
	std::cout << "original string length: " << buf.length() << std::endl;
	std::cout << "pid: " << getpid() << std::endl;
	std::cout << "[Memory have been allocated] Press ENTER to continue" << std::endl;
	std::getline(std::cin, tmp);
	
	// メモリ解放
	delete[] substrings;
	
	// メモリが解放された状態で一旦休止
	std::cout << "[Memory have been released] Press ENTER to exit" << std::endl;
	std::getline(std::cin, tmp);
}

