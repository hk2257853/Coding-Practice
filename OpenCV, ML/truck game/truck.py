# pip install opencv-python
# pip install cvzone
# pip install pyautogui
# pip install numpy
# pip install mediapipe
# pip install cvzone

from cvzone.HandTrackingModule import HandDetector
import cv2
import numpy as np
import pyautogui

detector = HandDetector(detectionCon=0.8, maxHands=1)

video = cv2.VideoCapture(0)

def drawTriangle(img,pt1,pt2,pt3,color,border):
    triangle_cnt = np.array( [pt1, pt2, pt3] )
    cv2.drawContours(img, [triangle_cnt], 0, color, border)

currentDirection = "straight"

while True:

    # read the video capture
    success, img = video.read()
    img = cv2.flip(img,1)
    
    # perform hand detection
    hands, img = detector.findHands(img)
    # if there is a hand in the imag
    if hands:
        # get the first hand
        hand = hands[0]
        # get the landmarks of the hand
        lmLists = hand["lmList"]

        # get the coordinates of the thumb and fingers
        thumbCoord = lmLists[4]
        indexThird = lmLists[6]
        indexFourth = lmLists[5]

        # left triangle
        leftTriangle = ((indexThird[0]-30, indexThird[1]-160),(indexThird[0]-30, indexThird[1]-10), (indexThird[0]-150, indexThird[1]-90))
        # right triangle
        rightTriangle = ((indexFourth[0]-30, indexFourth[1]-160), (indexFourth[0]-30, indexFourth[1]-10), (indexFourth[0]+90, indexFourth[1]-90))

        # draw the rectangle and triangles
        cv2.rectangle(img, (thumbCoord[0]-20, thumbCoord[1]-20), (thumbCoord[0]+20, thumbCoord[1]+20), (50, 50, 255), 2)
        drawTriangle(img, leftTriangle[0], leftTriangle[1], leftTriangle[2], (0,255,0), 2) # hollow triangle
        drawTriangle(img, rightTriangle[0], rightTriangle[1], rightTriangle[2], (0,255,0), 2) # hollow triangle (last argument is positive)
        copiedImg = img.copy() 

        # check if the thumb is in the left or right triangle
        if thumbCoord[0] < leftTriangle[0][0]:
            drawTriangle(img,leftTriangle[0], leftTriangle[1], leftTriangle[2], (0,255,0), -2) # solid triangle (last argument is negative)
            img = cv2.addWeighted(copiedImg, 0.5, img, 0.5, 0)  # mixing solid and hollow triangle 1:1 to create a semi transparent triangle for glow effect

            print('Left clicked')
            if currentDirection == 'right':
                pyautogui.keyUp('right')
            pyautogui.keyDown('left')
            currentDirection = 'left'

        elif thumbCoord[0] > rightTriangle[0][0]:
            drawTriangle(img, rightTriangle[0], rightTriangle[1], rightTriangle[2], (0,255,0),-2)
            img = cv2.addWeighted(copiedImg, 0.5, img, 0.5, 0)

            print('Right clicked')
            if currentDirection == 'left':
                pyautogui.keyUp('left')
            currentDirection = 'right'
            pyautogui.keyDown('right')

        else:
            if currentDirection == 'left':
                pyautogui.keyUp('left')
            elif currentDirection == 'right':
                pyautogui.keyUp('right')
            currentDirection = 'straight'

    # show the processed frame    
    cv2.imshow('Game', img)

    # press q to quit
    k = cv2.waitKey(1)
    if k==ord('q'):
        break

# release the video capture
video.release()
# close all the frames
cv2.destroyAllWindows()    

