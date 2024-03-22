# include <iostream>
# include <math.h>
# include <iomanip>
# include <fstream>
# include <sstream>

double riscale(double x)
{
    double y = (2+1)*(x-1)/(5-1) -1;
    return y;
}
int main()
{
    std::string nameFile1 ="results.csv";
    std::ofstream ofstr(nameFile1);

    std::string nameFile2 = "data.csv";
    std::ifstream ifstr(nameFile2);

    if(ifstr.fail())
    {
        std::cerr << "File not found" << std::endl;
        return 1;
    }
    double value;
    double sum = 0.0;
    double mean = 0.0;
    double valTrasformed;
    int count = 1;
    while (ifstr >> value)
    {
        valTrasformed = riscale(value);
        sum = sum + valTrasformed;
        mean = sum / count;
        ofstr << count << " " << mean << "\n";

        count++;
    }
    return 0;
}
