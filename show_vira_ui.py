import cv2
import threading
import speech_recognition as sr

exit_flag = False

def listen_for_exit():
    global exit_flag
    recognizer = sr.Recognizer()
    mic = sr.Microphone()

    with mic as source:
        recognizer.adjust_for_ambient_noise(source)

    while not exit_flag:
        with mic as source:
            try:
                audio = recognizer.listen(source, timeout=5)
                command = recognizer.recognize_google(audio).lower()
                print(f"You said: {command}")
                if "exit" in command:
                    exit_flag = True
                    break
            except sr.UnknownValueError:
                continue
            except sr.WaitTimeoutError:
                continue
            except sr.RequestError as e:
                print(f"Speech recognition error: {e}")
                break

# Show the image in full screen
img = cv2.imread(r" PASTE THE PATH OF THE IMAGE SAVE IN YOUR SYSTEM")
if img is None:
    print("Image not found!")
    exit()

cv2.namedWindow("VIRA", cv2.WINDOW_NORMAL)
cv2.setWindowProperty("VIRA", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)
cv2.imshow("VIRA", img)

# Start the voice recognition in a separate thread
listener_thread = threading.Thread(target=listen_for_exit)
listener_thread.start()

# Keep the image displayed until 'exit' is spoken
while not exit_flag:
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
listener_thread.join()
