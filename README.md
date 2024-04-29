Alphasense 1.0 is basically a Assitive vest for blind and Deaf people which helps them in detection of obstacles in front and backside of the person.

Components: 1) Ultrasonic Sensor *4
            2) Linear resonant Actuators(LRA's)  *4
            3) Arduino Uno
            4) Battery

Project design : This is a jacket in which there is a belt in middle below chest . 
                 The belt is elastical so can be adjusted easily according to different sizes.
                 Belt can be easily detached from the jacket 
                 Belt consist of 4 LRA's from the inner side , 2 from front and 2 from back and correponding to them their are ultrsonic sensors from outside
                 Their is a pouch for processing unit and to whom  a battery is connected

Working : So here first all the components give the signals to arduino where all the computations happens and result signals are produced to the actuators which showcase the output.
          Ultrasonic sensors fetch the distance using sound waves aand in code claculate the distance using the time which the waves require to come back to the sensors from the obstacle . 
          Then this distance is being fetched and we have given threshold to the distance or set the ranges acoording to our cse study and on that ranges set a vibrational output.
          so as per the distance the pattern of vibrations vary. this vibrations arre produced using vibrational motors ( Linear resonant actuators ) . 
          the vibrations are from that side whose ultrsonic sensor had detected the obstacle.

USP : 1) Comfortable to use 
      2) Stylish in look 
      3) Easy to wash without damaging components;
      4) easy detachable belt for changing outer jackets
      5) use of radium so people can detect the perosn at night too
