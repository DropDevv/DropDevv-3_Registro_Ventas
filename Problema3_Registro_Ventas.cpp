#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// switch para retornar nombre de los dias
string switchDias(int dia)
{
    switch (dia)
    {
    case 1:
        return "Lunes";
        break;
    case 2:
        return "Martes";
        break;
    case 3:
        return "Miercoles";
        break;
    case 4:
        return "Jueves";
        break;
    case 5:
        return "Viernes";
        break;
    case 6:
        return "Sabado";
        break;
    case 7:
        return "Domingo";
        break;
    default:
        return"Error en dia";
        break;
    }
};

int main() {
    vector<int> ventas(7);
    ofstream archivo("ventas.txt");

    if (!archivo) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Registro de ventas
    for (int i = 0; i < 7; ++i) {
        string dia = switchDias(i + 1);

        cout << "Ingrese las ventas del dia " << dia << ": ";
        while (!(cin >> ventas[i])) {
            cout << "Entrada invalida. Ingrese un numero: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        archivo << ventas[i] << endl;
    }
    archivo.close();

    // Cálculos
    int totalVentas = 0, maxVentas = ventas[0];
    string diaMax;
    int DiaSinVentas = 0;

    for (int i = 0; i < 7; ++i) {
        totalVentas += ventas[i];
        if (ventas[i] > maxVentas) {
            maxVentas = ventas[i];
            diaMax = switchDias(i + 1);
        }
        if (ventas[i] == 0) {
            DiaSinVentas += 1;
        }
    }

    // Resultados
    cout << "Total de ventas en la semana: " << totalVentas << endl;
    cout << "Dia con mayores ventas: Dia " << diaMax << " con " << maxVentas << " ventas." << endl;
    if (DiaSinVentas > 0) {
        cout << "Hubo " << DiaSinVentas << " sin ventas." << endl;
    }
    else {
        cout << "Todos los dias tuvieron ventas." << endl;
    }

    return 0;
}
