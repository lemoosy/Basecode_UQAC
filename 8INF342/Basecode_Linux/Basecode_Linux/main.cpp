#include "Historic.h"
#include "Settings.h"

int main(void)
{
    /*int messageCount = 0;
    string message;

    int parametersCount = 3;
    string* parameters = new string[parametersCount];

    while (1)
    {
        cout << "Breton & Lemoosy >> "; getline(cin, message);
        
        messageCount++;
        
        Message_ToCommands(message, 3, parameters);
        
        Historic_Add(HISTORIC_PATH_EXPORT, message, messageCount);
        
        if (parameters[0] == "stop")
        {
			break;
		}
        
        Commands_ToLinux(3, parameters);
    }

    if (parameters)
    {
        delete parameters;
    }*/

    Historic_Load(HISTORIC_PATH_IMPORT);

    return EXIT_SUCCESS;
}
