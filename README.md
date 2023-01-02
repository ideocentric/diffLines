# diffLines
Uses OpenCV to compute frame differences which then triggers line particles from brightness and the color of the pixels.

This uses a simple frame differencing from ofxOpenCv library which is required.  The threshold is currently set inline of what level will trigger a particle to be generated.

The particles are line segments that are set to a random trajectory but are pulled downwards by a fixed force.

