#include <iostream>
#include <math.h>
#include <random>
int main(int argc, char const *argv[]){
    std::uniform_real_distribution<double> un(0, 1);
    std::default_random_engine re;
    int n = (int) pow(10, 7);
    int acertos = 0;
    for(int i = 0; i < n; i++){
        double x = un(re);
        double y = un(re);
        if(x * x + y * y <= 1.0)
            acertos++;
    }
    std::cout << 4.0 * (double)acertos / (double)n << std::endl;
    return 0;
}
