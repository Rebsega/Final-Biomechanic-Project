#Code for the Last project of the Biomechanic subject
#Authors:
#Clara Alves Coelho
#Renan Barbieri Segamarchi
#####################################################
#This code is made for receiving a video, chosen by the authors or the user, then this one will have some options such as:
#Cut the video in a specific part then generate images of this piece
#Show the number of frames
#Generate an video of images

import sys
import numpy as np
import cv2

def main():
    captura = cv.VideoCapture(sys.argv[1])
    captura.open()
    while(captura.isOpened()):
        ret,frame = cap.read()
        cv.imshow('frame')
        if cv.waitKey(1) & 0xFF == ord('q'):
            break
    cap.release()
    cv.destroyAllWindows()

if __name__ == '__main__':
    main()