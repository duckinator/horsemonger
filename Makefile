all: horsemonger

gen/horsemonger.cxx gen/horsemonger.h: src/horsemonger.fl
	fluid -c -o gen/horsemonger.cxx -h gen/horsemonger.h src/horsemonger.fl

horsemonger: gen/horsemonger.cxx gen/horsemonger.h
	clang++ -g -o horsemonger -L /usr/local/lib -lfltk -I /usr/local/include -I . gen/*.cxx src/*.cxx

clean:
	rm -f horsemonger horsemonger.cxx horsemonger.h
