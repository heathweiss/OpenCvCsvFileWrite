
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
void writeFullDataWithDegreesAndReproduce0DegreeToFile();
void writeFullDataWithDegreesToFile();
void writeFullDataWithDegreesAndReproduce0DegreeFromMultipleImagesToFile();
void scan10Degrees();

int main ()
{
 
  //writeMinStringsToFile(convertMinAllRowsToString(),"mins.txt");
  //viewSingleRow (100);
  //writeFullDataToFile();
  //writeFullDataWithDegreesToFile();
  //writeFullDataWithDegreesAndReproduce0DegreeToFile();
  //writeFullDataWithDegreesAndReproduce0DegreeFromMultipleImagesToFile();
  scan10Degrees();
 
 return 0;
}

/////////////////////////////////////// functions for full data ////////////////////////////////////
/*
Reads from multiple files.
Reproduces 0 degree as 360 degree
Reads every 10 degrees
 */
void scan10Degrees()
{ Mat img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
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

  
  //now send it 3 more times with $ appended to it
  for (int scan = 1; scan <36; scan++)
    { os << "$";
      if (scan == 1) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 2) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 3) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 4) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 5) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 6) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 7) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 8) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 9) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 10) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 11) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 12) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 13) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 14) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 15) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 16) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 17) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 18) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 19) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 20) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 21) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 22) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 23) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 24) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 25) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 26) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 27) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 28) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 29) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 30) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 31) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 32) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 33) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 34) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
      if (scan == 35) img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );

      for (int row = 0; row < img.size().height; row++)
        { if (row > 0) os << ";";
          if (row == 0) 
	    { if (scan == 1) os << "10 "; //append degree info
              if (scan == 2) os << "20 "; //append degree info
              if (scan == 3) os << "30 "; //append degree info
              if (scan == 4) os << "40 ";
              if (scan == 5) os << "50 ";
              if (scan == 6) os << "60 ";
              if (scan == 7) os << "70 ";
              if (scan == 8) os << "80 ";
              if (scan == 9) os << "90 ";
              if (scan == 10) os << "100 ";
              if (scan == 11) os << "110 ";
              if (scan == 12) os << "120 ";
              if (scan == 13) os << "130 ";
              if (scan == 14) os << "140 ";
              if (scan == 15) os << "150 ";
              if (scan == 16) os << "160 ";
              if (scan == 17) os << "170 ";
              if (scan == 18) os << "180 ";
              if (scan == 19) os << "190 ";
              if (scan == 20) os << "200 ";
              if (scan == 21) os << "210 ";
              if (scan == 22) os << "220 ";
              if (scan == 23) os << "230 ";
              if (scan == 24) os << "240 ";
              if (scan == 25) os << "250 ";
              if (scan == 26) os << "260 ";
              if (scan == 27) os << "270 ";
              if (scan == 28) os << "280 ";
              if (scan == 29) os << "290 ";
              if (scan == 30) os << "300 ";
              if (scan == 31) os << "310 ";
              if (scan == 32) os << "320 ";
              if (scan == 33) os << "330 ";
              if (scan == 34) os << "340 ";
              if (scan == 35) os << "350 ";

            }
          
          for (int col = 0; col < img.size().width; col++)
            { int pixel = img.at<uchar>(row,col);
              if (col > 0) os << " "; 
              os << pixel;
            }
        }
    }

  //resend 0 degree as 360 to close off the scan.
  //This guarantees that 360 and 0 are the same
  os << "$";
  for (int row = 0; row < img.size().height; row++)
    { if (row > 0) os << ";";
      if (row == 0)   os << "360 "; //append degree info
      for (int col = 0; col < img.size().width; col++)
  	{ int pixel = img.at<uchar>(row,col);
          if (col > 0) os << " "; 
          os << pixel;
        }
    }
  
   
  fb.close();

}

/*
Reads from multiple files.
Reproduces 0 degree as 360 degree
 */
void writeFullDataWithDegreesAndReproduce0DegreeFromMultipleImagesToFile()
{ Mat img = imread("scanImages/0.jpg", CV_LOAD_IMAGE_GRAYSCALE );
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

  img = imread("scanImages/90.jpg", CV_LOAD_IMAGE_GRAYSCALE );
  //now send it 3 more times with $ appended to it
  for (int scan = 1; scan <4; scan++)
    { os << "$";
    
      for (int row = 0; row < img.size().height; row++)
        { if (row > 0) os << ";";
          if (row == 0) 
	    { if (scan == 1) os << "90 "; //append degree info
              if (scan == 2) os << "180 "; //append degree info
              if (scan == 3) os << "270 "; //append degree info
            }
          
          for (int col = 0; col < img.size().width; col++)
            { int pixel = img.at<uchar>(row,col);
              if (col > 0) os << " "; 
              os << pixel;
            }
        }
    }

  //resend 0 degree as 360 to close off the scan.
  //This guarantees that 360 and 0 are the same
  os << "$";
  for (int row = 0; row < img.size().height; row++)
    { if (row > 0) os << ";";
      if (row == 0)   os << "360 "; //append degree info
      for (int col = 0; col < img.size().width; col++)
  	{ int pixel = img.at<uchar>(row,col);
          if (col > 0) os << " "; 
          os << pixel;
        }
    }
  
   
  fb.close();

}

/* 
Writes all the image data to file, with multiple images to represent scans at each target degree.
Sends info about what degree, as the first int of the 1st row, for each of the degree datasets.

It attaches the 0 degree onto the end as 360 degree, instead of reading it in from a file.
At this point, it does not read in from a file each time, as I am not at that point yet.
 */
void writeFullDataWithDegreesAndReproduce0DegreeToFile()
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

  //now send it 3 more times with $ appended to it
  for (int scan = 1; scan <4; scan++)
    { os << "$";
    
      for (int row = 0; row < img.size().height; row++)
        { if (row > 0) os << ";";
          if (row == 0) 
	    { if (scan == 1) os << "90 "; //append degree info
              if (scan == 2) os << "180 "; //append degree info
              if (scan == 3) os << "270 "; //append degree info
            }
          
          for (int col = 0; col < img.size().width; col++)
            { int pixel = img.at<uchar>(row,col);
              if (col > 0) os << " "; 
              os << pixel;
            }
        }
    }

  //resend 0 degree as 360 to close off the scan.
  //This guarantees that 360 and 0 are the same
  os << "$";
  for (int row = 0; row < img.size().height; row++)
    { if (row > 0) os << ";";
      if (row == 0)   os << "360 "; //append degree info
      for (int col = 0; col < img.size().width; col++)
  	{ int pixel = img.at<uchar>(row,col);
          if (col > 0) os << " "; 
          os << pixel;
        }
    }
  
   
  fb.close();

}

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

