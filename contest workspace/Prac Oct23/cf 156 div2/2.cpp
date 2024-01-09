#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>

int main()
{
    int t;
    std::cin >> t;
    while (t)
    {
        t--;
        int px, py, ax, ay, bx, by;
        std::cin >> px >> py >> ax >> ay >> bx >> by;
        // o is 0, 0
        double distao, distap, distbo, distbp;
        // euclidean distance from p to a
        distao = sqrt(pow(0 - ax, 2) + pow(0 - ay, 2));
        distap = sqrt(pow(px - ax, 2) + pow(py - ay, 2));
        double case1 = std::max(distao, distap);
        double case1min = std::min(distao, distap);

        // for b
        distbo = sqrt(pow(0 - bx, 2) + pow(0 - by, 2));
        distbp = sqrt(pow(px - bx, 2) + pow(py - by, 2));
        double case2 = std::max(distbo, distbp);
        double case2min = std::min(distbo, distbp);

        double possibans1 = std::min(case1, case2);

        // using a, b both
        double cur2ans = std::max(case1min, case2min);

        double distab = sqrt(pow(ax - bx, 2) + pow(ay - by, 2));        

        // if(cur2ans < distab)
        // {
        //     cur2ans = distab / 2;
        // }

        // Set the precision to the desired number of decimal places
        std::cout << std::fixed << std::setprecision(10) << std::min(possibans1, cur2ans) << std::endl;

        // changing float to double gave me correct ans for TC1
    }
    return 0;
}
