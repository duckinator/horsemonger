all: horsemonger

gen/horsemonger.cxx gen/horsemonger.h: src/horsemonger.fl
	fluid -c -o gen/horsemonger.cxx -h gen/horsemonger.h src/horsemonger.fl

horsemonger: gen/horsemonger.cxx gen/horsemonger.h src/main.cxx
	clang++ -o horsemonger -L /usr/local/lib -lfltk -I /usr/local/include $@

clean:
	rm -f horsemonger horsemonger.cxx horsemonger.h
