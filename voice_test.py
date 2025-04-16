# voice_input.py
import speech_recognition as sr

def get_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        audio = recognizer.listen(source)

    try:
        command = recognizer.recognize_google(audio)
        print("You said:", command)
        return command.lower()
    except:
        return ""

command = get_command()

with open("command.txt", "w") as f:
    f.write(command)
