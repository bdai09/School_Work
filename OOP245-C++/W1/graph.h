/***********************************************************************
// OOP244 Workshop 1: Compiling modular source code

Name:Bo Dai
Student number:132954173
Email:bdai9@myseneca.ca
Date: May17, 2018

/////////////////////////////////////////////////////////////////
***********************************************************************/

#define MAX_NO_OF_SAMPLES 20

int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples);
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);