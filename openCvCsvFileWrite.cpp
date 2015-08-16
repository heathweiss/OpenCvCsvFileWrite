
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

