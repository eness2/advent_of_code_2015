#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int light[1000][1000] = {0};
void turnOn(int directions[], int lights[][1000])
{
    for (int i = directions[0]; i <= directions[2]; i++)
    {
        for (int j = directions[1]; j <= directions[3]; j++)
        {
            // lights[i][j] = 1;
            lights[i][j] += 1;
        }
    }
}
void turnOff(int directions[], int lights[][1000])
{
    for (int i = directions[0]; i <= directions[2]; i++)
    {
        for (int j = directions[1]; j <= directions[3]; j++)
        {
            if (!(lights[i][j] == 0))
                lights[i][j] -= 1;
        }
    }
}
void toggle(int directions[], int lights[][1000])
{
    for (int i = directions[0]; i <= directions[2]; i++)
    {
        for (int j = directions[1]; j <= directions[3]; j++)
        {
            /* if (lights[i][j] == 1)
                 lights[i][j] = 0;
             else
                 lights[i][j] = 1;
             */
            lights[i][j] += 2;
        }
    }
}
int main()
{

    fstream input("input.txt");
    int instructions[4], counter = 0;
    if (input.is_open())
    {
        string line;

        while (getline(input, line))
        {
            int j = 0;
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ',')
                    line[i] = ' ';
            }
            stringstream ss;
            string temp;
            ss << line;
            for (int i = 0; i < 2; i++)
            {
                ss >> temp;
                if (temp == "on")
                {
                    for (int k = 1; k < 6; k++)
                    {
                        ss >> temp;
                        if (k == 1 || k == 2 || k == 4 || k == 5)
                        {
                            stringstream(temp) >> instructions[j++];
                        }
                    }
                    turnOn(instructions, light);
                    break;
                }
                else if (temp == "off")
                {
                    for (int k = 1; k < 6; k++)
                    {
                        ss >> temp;
                        if (k == 1 || k == 2 || k == 4 || k == 5)
                        {
                            stringstream(temp) >> instructions[j++];
                        }
                    }
                    turnOff(instructions, light);
                    break;
                }
                else if (temp == "toggle")
                {
                    for (int k = 0; k < 5; k++)
                    {
                        ss >> temp;
                        if (k == 0 || k == 1 || k == 3 || k == 4)
                        {
                            stringstream(temp) >> instructions[j++];
                        }
                    }
                    toggle(instructions, light);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            /* if (light[i][j] == 1)
                counter++;
            */
            counter += light[i][j];
        }
    }
    cout << counter << endl;

    system("pause");
    return 0;
}