default:
	$(CXX) -D USE_FUNDOSHI_STRING alloc_memory.cpp -o fundoshi_alloc_memory
	$(CXX) alloc_memory.cpp -o std_string_alloc_memory

clean:
	rm -f fundoshi_alloc_memory std_string_alloc_memory

get_fundoshi_hpp:
	wget https://github.com/maraigue/fundoshi.hpp/raw/master/fundoshi.hpp

