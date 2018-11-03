Assignment #2: Build a foot touchpad
Your job is to build a foot touchpad that displays a circle on the screen whenever a user touches the floor with his feet. You will work with your Kinect and tripod setup. You will probably want to use the concept of double thresholding proposed by Andy Wilson (Using a Depth Camera as a Touch Sensor).


Preparation
Make sure to have a Kinect camera and tripod from us
Make sure your Kinect development environment set up
Need help? In addition to the lecture slides, use OpenCV Documentation and feel free to ask/email us TAs.

Start in class, finish at home
Mount the Kinect onto the tripod using the mount you cut during the last assignment.
Download and unpack the skeleton code for the assignment.
Problems running it? It works just like the environment test program. If the wrong program starts (or the debug button is disabled), you should right click on assignment01 in the solution explorer and choose Set as startup project (Als Startprojekt festlegen).
Fill in the blanks: We left a couple of blank spots for you to fill out. You should check:
main.cpp
touchRecognizer.hpp
touchRecognizer.cpp
touchVisualizer.cpp
Insert your code so that the application draws a circle marker wherever either of the user's feet is in contact with the ground.
Try to make your algorithm as generic as possible (i. e. it should work if you mount your Kinect at different heights).
Two hints for free: OpenCV uses BGR colors (instead of RGB); the values in the depth image are in millimeters
Bonus: Connect the points of contact to implement a drawing app. You could use the additional files we provided to do this:
drawVisualizer.hpp
drawVisualizer.cpp

Deliverable
Record a 10 seconds video showing you tapping on the ground with circle markers appearing every time your feet touch the ground and upload it to YouTube or Vimeo.
Copy the assignment page to your group namespace and embed your video.
