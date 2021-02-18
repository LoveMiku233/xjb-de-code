#ifndef _HTEST_H
#define _HTEST_H
#define COLOR(msg,code) "\033[0;1;#codem" msg "\033[0m"
#define RED(msg) COLOR(msg,31)
#define GREEN(msg) COLOR(msg,32)
#define YELLOW(msg) COLOR(msg,33)
#define BLUE(msg) COLOR(msg,34)

#define EXPECT(a,comp,b){ \
    if(!((a) comp (b))){\
    print("error\n");\
    }\
}\

#define ex_xy(a,b) EXPECT(a,<,b)
#define ex_dey(a,b) EXPECT(a,=,b)
#define ex_day(a,b) EXPECT(a,>,b)




#endif