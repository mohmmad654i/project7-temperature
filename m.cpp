#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    float Mean = 0, x = 0, Median = 0;
    string choice, operation;
    int maxCount = 0;

    cout << "========================================" << endl;
    cout << "   STATISTICAL CALCULATOR PRO v1.0" << endl;
    cout << "========================================" << endl;
    cout << "Choose Mode ([all] for full report / [one] for specific task): ";
    cin >> choice;

    if (choice == "all")
    {
        cout << "\nEnter number of elements (n): ";
        cin >> n;
        float samplespace[n];
        cout << "Enter " << n << " values: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << " [" << i + 1 << "]: ";
            cin >> samplespace[i];
            x += samplespace[i];
        }

        Mean = x / n;

        sort(samplespace, samplespace + n);

        if (n % 2 != 0)
            Median = samplespace[n / 2];
        else
            Median = (samplespace[(n / 2) - 1] + samplespace[n / 2]) / 2;

        float Mode = samplespace[0];
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (samplespace[j] == samplespace[i]) count++;
            }
            if (count > maxCount)
            {
                maxCount = count;
                Mode = samplespace[i];
            }
        }

        float sum_sq = 0;
        for (int i = 0; i < n; i++)
        {
            sum_sq += pow(samplespace[i] - Mean, 2);
        }
        float s2 = (n > 1) ? (sum_sq / (n - 1)) : 0;

        cout << "\n--- Statistical Summary ---" << endl;
        cout << fixed << setprecision(2);
        cout << " >> Mean (Average): " << Mean << endl;
        cout << " >> Median (Middle): " << Median << endl;
        cout << " >> Mode (Most Common): " << Mode << " (Freq: " << maxCount << ")" << endl;
        cout << " >> Variance (S2): " << s2 << endl;
        cout << "---------------------------" << endl;
    }
    else if (choice == "one")
    {
        cout << "\nAvailable: [Mean] [Median] [Mode] [S2]" << endl;
        cout << "Enter operation: ";
        cin >> operation;
        
        cout << "Enter number of elements (n): ";
        cin >> n;
        float samplespace[n];
        
        for (int i = 0; i < n; i++) 
        {
            cout << " [" << i + 1 << "]: ";
            cin >> samplespace[i];
        }

        if (operation == "Mean" || operation == "mean")
        {
            for (int i = 0; i < n; i++) x += samplespace[i];
            cout << "\nRESULT >> Mean = " << x / n << endl;
        }
        else if (operation == "Median" || operation == "median")
        {
            sort(samplespace, samplespace + n);
            if (n % 2 != 0) Median = samplespace[n / 2];
            else Median = (samplespace[(n / 2) - 1] + samplespace[n / 2]) / 2;
            cout << "\nRESULT >> Median = " << Median << endl;
        }
        else if (operation == "Mode" || operation == "mode")
        {
            float Mode = samplespace[0];
            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = 0; j < n; j++)
                {
                    if (samplespace[j] == samplespace[i]) count++;
                }
                if (count > maxCount)
                {
                    maxCount = count;
                    Mode = samplespace[i];
                }
            }
            cout << "\nRESULT >> Mode = " << Mode << endl;
        }
        else if (operation == "S2" || operation == "s2")
        {
            for (int i = 0; i < n; i++) x += samplespace[i];
            Mean = x / n;
            float sum_sq = 0;
            for (int i = 0; i < n; i++) sum_sq += pow(samplespace[i] - Mean, 2);
            cout << "\nRESULT >> Variance (S2) = " << sum_sq / (n - 1) << endl;
        }
    }

    cout << "\nOperation Complete." << endl;
    system("pause");
    return 0;
}