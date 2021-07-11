all: horsemonger

horsemonger.cxx horsemonger.h:
	fluid -c -o horsemonger.cxx -h horsemonger.h horsemonger.fl

horsemonger: horsemonger.cxx horsemonger.h
	clang++ -o horsemonger -L /usr/local/lib -lfltk -I /usr/local/include horsemonger.cxx

clean:
	rm -f horsemonger horsemonger.cxx horsemonger.h
