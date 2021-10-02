all: horsemonger

CFLAGS_KLUDGES := -Wno-reserved-id-macro -Wno-old-style-cast -Wno-sign-conversion -Wno-extra-semi -Wno-zero-as-null-pointer-constant -Wno-documentation -Wno-documentation-deprecated-sync -Wno-shift-sign-overflow -Wno-suggest-override -Wno-suggest-destructor-override -Wno-documentation-unknown-command -Wno-shadow -Wno-non-c-typedef-for-linkage -Wno-documentation-html -Wno-reserved-id-macro -Wno-old-style-cast -Wno-padded -Wno-switch-enum -Wno-documentation-pedantic -Wno-covered-switch-default -Wno-extra-semi-stmt -Wno-switch-enum -Wno-weak-vtables

CFLAGS := -std=c++14 -g -Weverything -pedantic-errors -Wno-c++98-compat -Wno-c++98-compat-pedantic ${CFLAGS_KLUDGES}
LDFLAGS := -L /usr/local/lib -lfltk

INCLUDES := -I /usr/local/include -I .

gen/horsemonger.cxx gen/horsemonger.h: src/horsemonger.fl
	fluid -c -o gen/horsemonger.cxx -h gen/horsemonger.h src/horsemonger.fl

horsemonger: gen/horsemonger.cxx gen/horsemonger.h
	clang++ ${CFLAGS} ${INCLUDES} ${LDFLAGS} -o horsemonger gen/*.cxx src/*.cxx

clean:
	rm -f horsemonger horsemonger.cxx horsemonger.h
