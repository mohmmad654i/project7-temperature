#include <iostream>


using namespace std;

int main()
{
    float maxcauot = 0;
    float temperature[7];
    float mini = 0;
    float Averagetemperature = 0;
    const float Alert = 40;
    float x;
    for (int i = 0; i < 7; i++)
    {
        cout << "Please enter day" << " " << i + 1 << " " << "temperature : ";
        cin >> temperature[i];
    }
    maxcauot = temperature[0];
    for (int i = 1; i < 7; i++)
    {
        if (temperature[i] > maxcauot)
        {
            maxcauot = temperature[i];
        }
    }
    cout << "Maximum temperature: " << maxcauot << endl;

    mini = temperature[0];
    for (int i = 1; i < 7; i++)
    {
        if (temperature[i] < mini)
        {
            mini = temperature[i];
        }
    }
    cout << "Lowest temperature : " << mini << endl;

    for (int i = 0; i < 7; i++)
    {

        Averagetemperature = Averagetemperature + temperature[i];
    }

    cout << "Averagetemperature :" << ((Averagetemperature) / 7) << endl;

    for (int i = 1; i < 7; i++)
    {
        if (temperature[i] > Alert)
        {

            x = temperature[i];
        }
    }

    cout << "Beware of this high temperature:" << x << endl;

    system("pause");
    return 0;
}
