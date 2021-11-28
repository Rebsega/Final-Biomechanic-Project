import cv2
import pyaudio
import wave
import threading
import time
import subprocess
import os

class VideoRecorder():  
    def __init__(self):
        self.open = True
        self.device_index = 0
        self.fps = 6 #delimita os fps            
        self.fourcc = "MJPG"       
        self.frameSize = (640,480) 
        self.video_filename = "temp_video_Teste_8.avi"
        self.video_cap = cv2.VideoCapture(self.device_index)
        self.video_writer = cv2.VideoWriter_fourcc(*self.fourcc)
        self.video_out = cv2.VideoWriter(self.video_filename, self.video_writer, self.fps, self.frameSize)
        self.frame_counts = 1
        self.start_time = time.time()


#Começa a gravar 
    def record(self):

        counter = 1
        timer_start = time.time()
        timer_current = 0

        while(self.open==True):
            ret, video_frame = self.video_cap.read()
            if (ret==True):
                self.video_out.write(video_frame)
                self.frame_counts += 1
                counter += 1
                timer_current = time.time() - timer_start
                time.sleep(0.16)
                gray = cv2.cvtColor(video_frame, cv2.COLOR_BGR2GRAY)
                #Essa linha dá mto problema, cuidado
                cv2.imshow('video_frame', gray)
                cv2.waitKey(1)
            else:
                break
    def stop(self):

        if self.open==True:

            self.open=False
            self.video_out.release()
            self.video_cap.release()
            cv2.destroyAllWindows()

        else: 
            pass
        #Disclaimer: Pass e continue são iguais, mas continue só pode ser usado em loops

    #Starta a gravação de vídeo por método threading       
    def start(self):
        video_thread = threading.Thread(target=self.record)
        video_thread.start()

#Grava áudio
class AudioRecorder():

    #Wav e PyAudio, definições iniciais em __init__
    def __init__(self):
        self.open = True
        self.rate = 44100
        self.frames_per_buffer = 1024
        self.channels = 2
        self.format = pyaudio.Paint16
        self.audio_filename = "temp_audio.wav"
        self.audio = pyaudio.PyAudio()
        self.stream = self.audio.open(format=pyaudio.Paint16,channels=2,rate=44100,input=True,frames_per_buffer = 1024)
        self.audio_frames = []
    #Starta a gravação de áudio por método threading    
    def start(self):
        audio_thread = threading.Thread(target=self.record)
        audio_thread.start()
    #Grava áudio
    def record(self):
        self.stream.start_stream()
        while(self.open == True):
            data = self.stream.read(self.frames_per_buffer) 
            self.audio_frames.append(data)
            if self.open==False:
                break
    #Func para parar a gravação  
    def stop(self):
        if self.open==True:
            self.open = False
            self.stream.stop_stream()
            self.stream.close()
            self.audio.terminate()

            waveFile = wave.open(self.audio_filename, 'wb')
            waveFile.setnchannels(self.channels)
            waveFile.setsampwidth(self.audio.get_sample_size(self.format))
            waveFile.setframerate(self.rate)
            waveFile.writeframes(b''.join(self.audio_frames))
            waveFile.close()
        pass
    
def start_video_recording(filename):
    global video_thread
    video_thread = VideoRecorder()
    video_thread.start()
    return filename


def start_audio_recording(filename):
    global audio_thread
    audio_thread = AudioRecorder()
    audio_thread.start()
    return filename

def stop_recording(filename):

    audio_thread.stop() 
    frame_counts = video_thread.frame_counts
    elapsed_time = time.time() - video_thread.start_time
    recorded_fps = frame_counts / elapsed_time
    video_thread.stop() 
    #Pausa de segurança
    while threading.active_count() > 1:
        time.sleep(1)

def start_recording(filename):
    global video_thread #definição de variáveis globais para as threadings de video e audio
    global audio_thread
    video_thread = VideoRecorder()
    audio_thread = AudioRecorder()
    audio_thread.start()
    video_thread.start()
    return filename

    
#Junta vídeo e som
    if abs(recorded_fps - 6) >= 0.01: #Re-tradução caso taxa de fps saia do requerido
        print ("Re-encoding")
        cmd = "ffmpeg -r " + str(recorded_fps) + " -i temp_video.avi -pix_fmt yuv420p -r 6 temp_video2.avi"
        subprocess.call(cmd, Shell=True)
        print ("Mixing")
        cmd = "ffmpeg -ac 2 -channel_layout stereo -i temp_audio.wav -i temp_video2.avi -pix_fmt yuv420p " + filename + ".avi"
        subprocess.call(cmd, Shell=True)
    else:
        print ("Normal recording\nMuxing")
        cmd = "ffmpeg -ac 2 -channel_layout stereo -i temp_audio.wav -i temp_video.avi -pix_fmt yuv420p " + filename + ".avi"
        subprocess.call(cmd, Shell=True)
        print ("Cheguei aqui")

#Processamento dos arquivos finais
def file(filename):

    local_path = os.getcwd()
    if os.path.exists(str(local_path) + "/temp_audio.wav"):
        os.remove(str(local_path) + "/temp_audio.wav")
    if os.path.exists(str(local_path) + "/temp_video.avi"):
        os.remove(str(local_path) + "/temp_video.avi")
    if os.path.exists(str(local_path) + "/temp_video2.avi"):
        os.remove(str(local_path) + "/temp_video2.avi")
    if os.path.exists(str(local_path) + "/" + filename + ".avi"):
        os.remove(str(local_path) + "/" + filename + ".avi")
        
if __name__ == '__main__':
    filename = "teste_vid"
    start_recording(filename)
    time.sleep(2)
    stop_recording(filename)
    file(filename)