#include <fstream>
#include <sstream> 
#include <opencv2/opencv.hpp>
//#include <iostream> 
//#include <string> 

using namespace cv;


int getMinLoc(Mat image, int row)
{
  uchar minVal = 255;
  int minLoc = 0;
  int pixel= 0 ; 
  

  for (int col = 0; col < (image.size().width - 1); col++)
    {
      pixel = image.at<uchar>(row,col);
      if (pixel < minVal)
	{
          minVal = pixel;
          minLoc = col;
        }
    }
  return minVal;
}

void getMinLocations(Mat image, int* mins)
{
  std::cout << "width: [" << image.size().width << "]" << std::endl;
  std::cout << "height: [" << image.size().height << "]" << std::endl;
  for (int row = 0; row < image.size().height; row++)
    {
      mins[row] = getMinLoc(image,row);
    }
  
}

std::string stringOfMinLocations()
{
   //load the image
   //had to flip the image with imageView. WTF? Once I get permanent camera, should change.
   Mat image;
   //image = imread("LinuxLogo.jpg", CV_LOAD_IMAGE_GRAYSCALE );
   image = imread("backScratcherFlipped.jpg", CV_LOAD_IMAGE_GRAYSCALE );
   std::ostringstream os;
   int mins[image.size().height -1];

   getMinLocations(image, mins);

   for (int i = 0; i < (sizeof(mins)/sizeof(mins[0])); i++)
     {
       if (i > 0) os << " ";//put space in front if not the 1st row. Haskell will split on the space for reading ints.
       os << mins[i] ;
     }

   return os.str();
}


//takes a string, and writes it to a file via a filebuf
//now add  second/3rd arrays that would represent more angles. Use ; as a sep.
int writeMinLocationsToFile (std::string inString,const char* fileName)
{
  std::filebuf fb;
  fb.open (fileName,std::ios::out);
  std::ostream os(&fb);

  os << inString;
  for (int i = 0 ; i < 4; i++)
    {
      os << ";";
      os << inString;
    }
  
  fb.close();
  return 0;
}

//////////////////////////////////////// main //////////////////////////////////////
int main ()
{
 
 writeMinLocationsToFile(stringOfMinLocations(),"mins.txt");
 
 return 0;



}
