#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>
#include <algorithm>

using namespace std;

string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    system("cls");

  
      system("start python show_vira_ui.py"); //This will display the image of VIRA input by python 

    string greet = "Hello Human, this is VIRA, Your Voice Interactive Response Assistant. How can I help you?";
    string greetCmd = "espeak -ven+f3 -s120 \"" + greet + "\"";// Turned it's voice into a female plus reduced the speed of speaking since it was fast
    system(greetCmd.c_str());
    //Song database map

    map<string, string> songs = {
        {"faded", "https://www.youtube.com/watch?v=SlPhMPnQ58k"},
        {"shape of you", "https://www.youtube.com/watch?v=JGwWNGJdvx8"},
        {"perfect", "https://www.youtube.com/watch?v=2Vv-BfVoq4g"},
        {"unstoppable", "https://www.youtube.com/watch?v=UceaB4D0jpo"},
        {"despacito", "https://www.youtube.com/watch?v=kJQP7kiw5Fk"},
        {"see you again", "https://www.youtube.com/watch?v=RgKAFK5djSk"},
        {"memories", "https://www.youtube.com/watch?v=CuklIb9d3fI"},
        {"uptown funk", "https://www.youtube.com/watch?v=OPf0YbXqDm0"},
        {"love the way you lie", "https://www.youtube.com/watch?v=uelHwf8o7_U"},
        {"raataan lambiyan", "https://www.youtube.com/watch?v=gvyUuxdRdR4"},
        {"param sundari", "https://www.youtube.com/watch?v=QkZxoko_HC0"},
        {"nadiyon paar", "https://www.youtube.com/watch?v=K0eDlFX9GMc"},
        {"kusu kusu", "https://www.youtube.com/watch?v=PeQWPRxn5wE"},
        {"zaroori tha", "https://www.youtube.com/watch?v=JYa6Miqh8Ls"},
        {"lahore", "https://www.youtube.com/watch?v=dZ9pD9e0IUI"},
        {"zaalima", "https://www.youtube.com/watch?v=hhdSyBHuI88"},
        {"kabira", "https://www.youtube.com/watch?v=jHNNMj5bNQw"},
        {"tera ban jaunga", "https://www.youtube.com/watch?v=VOLKJJvfAbg"},
        {"ghungroo", "https://www.youtube.com/watch?v=prwUFBsDRLk"}
    };

    while (true) {
        system("python voice_test.py");// This will take voice input which has been given in python 
        Sleep(1000);

        ifstream file("command.txt");
        string command;
        getline(file, command);
        file.close();

        command = toLower(command);
        cout << "Command: " << command << endl;

        if (command == "exit" || command == "quit") {
            system("espeak -ven+f3 -s120 \"Hope i assisted you right Goodbye. Call me anytime i'm right there for you Human.\"");
            break;
        } else if (command.find("play") == 0) {
            string songName = command.substr(5);
            if (songs.count(songName)) {
                string phrase = "Playing " + songName + " on YouTube";
                string commandSpeak = "espeak -ven+f3 -s120 \"" + phrase + "\"";
                system(commandSpeak.c_str());
                system(("start \"\" \"" + songs[songName] + "\"").c_str());
            } else {
                system("espeak -ven+f3 -s120 \"Sorry, I couldn't find that song.\"");
            }
        } else if (command == "open google") {
            system("espeak -ven+f3 -s120 \"Opening Google\""); system("start https://www.google.com");
        } else if (command == "open youtube") {
            system("espeak -ven+f3 -s120 \"Opening YouTube\""); system("start https://www.youtube.com");
        } else if (command == "open facebook") {
            system("espeak -ven+f3 -s120 \"Opening Facebook\""); system("start https://www.facebook.com");
        } else if (command == "open linkedin") {
            system("espeak -ven+f3 -s120 \"Opening LinkedIn\""); system("start https://www.linkedin.com");
        } else if (command == "how are you" || command == "what's up") {
            system("espeak -ven+f3 -s120 \"I am great, how about you dear?\"");
        } else {
            system("espeak -ven+f3 -s120 \"Sorry Human, I did not understand that command\"");
        }
    }

    return 0;
}
