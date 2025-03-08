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
int main() {  // Función principal del programa
    vector<int> ventas(7); // Declara un vector de enteros con 7 posiciones para almacenar las ventas de cada día de la semana
    ofstream archivo("ventas.txt");    // Crea y abre un archivo de salida llamado "ventas.txt"

    if (!archivo) {  // Verifica si el archivo no se pudo abrir correctamente
        cerr << "Error al abrir el archivo." << endl;  // Muestra un mensaje de error en la salida de error estándar
        return 1;  // Termina el programa con un código de error
    }

    // Registro de ventas
    for (int i = 0; i < 7; ++i) {  // Bucle que se ejecuta 7 veces, una por cada día de la semana
        string dia = switchDias(i + 1); // Llama a la función switchDias para obtener el nombre del día correspondiente

        cout << "Ingrese las ventas del dia " << dia << ": "; // Solicita al usuario que ingrese las ventas del día
        while (!(cin >> ventas[i])) {  // Verifica si la entrada es válida (si no es un número, vuelve a solicitarla)
            cout << "Entrada invalida. Ingrese un numero: "; // Muestra un mensaje de error
            cin.clear();  // Limpia el estado de error del flujo de entrada
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta la entrada incorrecta para evitar un bucle infinito
        }
        archivo << ventas[i] << endl; // Escribe la venta del día en el archivo "ventas.txt"
    }
    archivo.close();  // Cierra el archivo después de guardar las ventas

    // Cálculos
    int totalVentas = 0, maxVentas = ventas[0]; // Declara e inicializa variables para el total de ventas y el máximo de ventas
    string diaMax;  // Declara una variable para almacenar el nombre del día con más ventas
    int DiaSinVentas = 0;  // Variable para contar los días sin ventas

    for (int i = 0; i < 7; ++i) {  // Recorre el vector de ventas
        totalVentas += ventas[i]; // Suma las ventas del día al total

        if (ventas[i] > maxVentas) {  // Si la venta del día es mayor que el máximo registrado
            maxVentas = ventas[i];  // Actualiza el valor de la venta máxima
            diaMax = switchDias(i + 1);  // Almacena el nombre del día con más ventas
        }
        if (ventas[i] == 0) {  // Si el día no tuvo ventas
            DiaSinVentas += 1;  // Incrementa el contador de días sin ventas
        }
    }

    // Resultados
    cout << "Total de ventas en la semana: " << totalVentas << endl;  // Muestra el total de ventas de la semana
    cout << "Dia con mayores ventas: Dia " << diaMax << " con " << maxVentas << " ventas." << endl;  // Muestra el día con más ventas

    if (DiaSinVentas > 0) {  // Si hubo días sin ventas
        cout << "Hubo " << DiaSinVentas << " sin ventas." << endl;  // Muestra la cantidad de días sin ventas
    }
    else {  // Si no hubo días sin ventas
        cout << "Todos los dias tuvieron ventas." << endl;  // Muestra un mensaje indicando que todos los días registraron ventas
    }

    return 0;  // Finaliza el programa correctamente
}
