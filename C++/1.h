#ifndef __COMPLEX__
#define __COMPLEX__
//template<typename T>
class complex{
    public:
        complex(double r=0,double i=0):re(r),im(i){}
        double real() const {return re;}
        double imag() const {return im;} 
        void prinths(const int& a){
            std::cout<<a<<std::endl;
        }
        int func(const complex& param){
            return param.im+param.re;
        }

        complex& miku(complex* ths,const complex& r);
        complex& operator += (const complex& r);

    private:
        double re,im;
};

#endif