
#include <fstream>
#include <sstream> 
#include <opencv2/opencv.hpp>
//#include <iostream> 
//#include <string> 


using namespace cv;
//func declarations for mininum data
int getMinSingle(Mat image, int row);
void getMinAll(Mat image, int* mins);
std::string convertMinAllRowsToString();
int writeMinStringsToFile (std::string inString,const char* fileName);


//func declarations for full data
void viewSingleRow (int row);
void writeFullDataToFile();
void writeFullDataWithDegreesToFile();

int main ()
{
 
  //writeMinStringsToFile(convertMinAllRowsToString(),"mins.txt");
  //viewSingleRow (100);
  //writeFullDataToFile();
  writeFullDataWithDegreesToFile();
 
 return 0;
}

/////////////////////////////////////// functions for full data ////////////////////////////////////

/*
Writes all the image data to file, with multiple images to represent scans at each target degree.
Sends info about what degree, as the first int of the 1st row, for each of the degree datasets.
Put in on every row to make parsing easier.
*/
void writeFullDataWithDegreesToFile()
{ Mat img = imread("backScratcherFlipped.jpg", CV_LOAD_IMAGE_GRAYSCALE );
  std::filebuf fb;
  fb.open ("fullDataWithDegrees.txt",std::ios::out);
  std::ostream os(&fb);

  //need to send the data 5 times for a simulated 0,90,180,270,360 degree scan.
  //send it 1st time alone, so it does not have a $ appended to it

  for (int row = 0; row < img.size().height; row++)
    { if (row > 0) os << ";";
      if (row == 0)   os << "0 "; //append degree info
      for (int col = 0; col < img.size().width; col++)
  	{ int pixel = img.at<uchar>(row,col);
          if (col > 0) os << " "; 
          os << pixel;
        }
    }

  //now send it 4 more times with $ appended to it
  for (int scan = 1; scan <5; scan++)
    { os << "$";

      for (int row = 0; row < img.size().height; row++)
        { if (row > 0) os << ";";
          if (row == 0) 
	    { if (scan == 1) os << "90 "; //append degree info
              if (scan == 2) os << "180 "; //append degree info
              if (scan == 3) os << "270 "; //append degree info
              if (scan == 4) os << "360 "; //append degree info
            }
          
          for (int col = 0; col < img.size().width; col++)
            { int pixel = img.at<uchar>(row,col);
              if (col > 0) os << " "; 
              os << pixel;
            }
        }
    }
    
  fb.close();

}


/*
Writes all the image data to file, with multiple images to represent scans at each target degree.
Does not send info about what degree.
*/
void writeFullDataToFile()
{ Mat img = imread("backScratcherFlipped.jpg", CV_LOAD_IMAGE_GRAYSCALE );
  std::filebuf fb;
  fb.open ("fullData.txt",std::ios::out);
  std::ostream os(&fb);

  //need to send the data 5 times for a simulated 0,90,180,270,360 degree scan.
  //send it 1st time alone, so it does not have a $ appended to it

  for (int row = 0; row < img.size().height; row++)
    { if (row > 0) os << ";";
      for (int col = 0; col < img.size().width; col++)
  	{ int pixel = img.at<uchar>(row,col);
          if (col > 0) os << " "; 
          os << pixel;
        }
    }

  //now send it 4 more times with $ appended to it
  for (int scan = 1; scan <5; scan++)
    { os << "$";

      for (int row = 0; row < img.size().height; row++)
        { if (row > 0) os << ";";
          for (int col = 0; col < img.size().width; col++)
            { int pixel = img.at<uchar>(row,col);
              if (col > 0) os << " "; 
              os << pixel;
            }
        }
    }
    
  fb.close();

}


void viewSingleRow (int row)
{
  Mat imageRaw = imread("backScratcherFlipped.jpg", CV_LOAD_IMAGE_GRAYSCALE );
  cv::Mat imageBW = imageRaw > 45;
  std::ostringstream os;
  for (int col = 0; col < imageBW.size().width; col++)
    { int pixel = imageBW.at<uchar>(row,col);
      os <<  pixel;
      os << " ";
     
    }
  std::cout << os.str();
}

//////////////////////////////////////// functions for min values //////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int getMinSingle(Mat image, int row)
{
  uchar minVal = 255;
  int minLoc = 0;
  int pixel= 0 ; 
  

  for (int col = 0; col < (image.size().width - 1); col++)
    {
      pixel = image.at<uchar>(row,col);
      if (pixel <= (minVal))
	{
          minVal = pixel;
          minLoc = col;
        }
    }
  return minVal;
}


void getMinAllRows(Mat image, int* mins)
{
  std::cout << "width: [" << image.size().width << "]" << std::endl;
  std::cout << "height: [" << image.size().height << "]" << std::endl;
  for (int row = 0; row < image.size().height; row++)
    {
      mins[row] = getMinSingle(image,row);
    }
  
}


std::string convertMinAllRowsToString()
{
   //load the image
   //had to flip the image with imageView. WTF? Once I get permanent camera, should change.
   Mat image;
   //image = imread("LinuxLogo.jpg", CV_LOAD_IMAGE_GRAYSCALE );
   image = imread("backScratcherFlipped.jpg", CV_LOAD_IMAGE_GRAYSCALE );
   //change to black and white, with values about the threshhold being white
   //cv::Mat image = imageAsRead > 25;
   std::ostringstream os;
   int mins[image.size().height -1];

   getMinAllRows(image, mins);

   for (int i = 0; i < (sizeof(mins)/sizeof(mins[0])); i++)
     {
       if (i > 0) os << " ";//put space in front if not the 1st row. Haskell will split on the space for reading ints.
       os << mins[i] ;
     }

   return os.str();
}


//takes a string, and writes it to a file via a filebuf
//now add  second/3rd arrays that would represent more angles. Use ; as a sep.
int writeMinStringsToFile (std::string inString,const char* fileName)
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
