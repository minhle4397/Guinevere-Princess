#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);
int Read_FILE(string file_input, int info_knight[], int road_to_Koopa[], string item[]);
void event_Processor(int *info_knight, int road_to_Koopa[], string item[],int num_road, int & rescue);
void readFile_merlin_pack(int& a, int& b, string filename);
int** readMatrixFromFile(string filename, int& n, int& m);
void find_max2_3(int arr[], int size, int& max2_3x, int& max2_3i);
int find_first_occurrence(int arr[], int n, int x);
void find_pos_first_min_max(int arr[], int n, int& maxi2, int& mini2);
void checkMountainShape(int arr[], int n, int &mtx, int &mti);
void find_pos_final_min_max(int arr[], int n, int& a, int& b);
int* extract_digits(int n, int& size);
int count_digits(int n);
int* read_data_from_file_MushGhost(string filename, int& n);
int fibonacci_near(int n);
int absoluteValue(int num);
bool isPrime(int n);
int findNearestPrime(int n);
int sumOfNLargestOddDigits(int n);
int levelO(int event_no);
int damge(double baseDam, int levelBoss);

#endif // __KNIGHT_H__
