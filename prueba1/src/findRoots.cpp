#include <iostream>
#include <cmath>

using namespace std;
// Método para calcular las raíces de un polinomio de la forma ax^3 + bx^2 + cx + d
// con el método de Cardano.
int cardano(int a, int b, int c, int d){
    double p = (3 * a * c - b * b) / (3 * a * a);
    double q = (2 * b * b * b - 9 * a * b * c + 27 * a * a * d) / (27 * a * a * a);
    double delta = q * q + 4 * p * p * p / 27;

    if (delta > 0) {
        double u = cbrt((-q + sqrt(delta)) / 2);
        double v = cbrt((-q - sqrt(delta)) / 2);
        double x1 = u + v - b / (3 * a);
        double x2 = -(u + v) / 2 - b / (3 * a);
        double x3 = -(u + v) / 2 - b / (3 * a);
        cout << "{" << x1 << ", " << x2 << ", " << x3 << "}" << endl;
    } else if (delta == 0) {
        double u = cbrt(-q / 2);
        double x1 = 2 * u - b / (3 * a);
        cout << "{" << x1 << "}" << endl;
    } else {
        double rho = sqrt(-p * p * p);
        double theta = acos(-q / (2 * rho));
        double x1 = 2 * cbrt(rho) * cos(theta / 3) - b / (3 * a);
        double x2 = 2 * cbrt(rho) * cos((theta + 2 * M_PI) / 3) - b / (3 * a);
        double x3 = 2 * cbrt(rho) * cos((theta - 2 * M_PI) / 3) - b / (3 * a);
        cout << "{" << x1 << ", " << x2 << ", " << x3 << "}" <<endl;
    }

    return 0;
}

int main(int argc, char* argv[]){
    if (argc < 5){
        cout << "Uso: findRoots a b c d" << endl;
        return 1;
    }

    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double d = atof(argv[4]);

    return cardano(a,b,c,d);
}