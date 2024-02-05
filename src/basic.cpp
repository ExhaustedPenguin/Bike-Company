#include "./nthu_bike.h"
// #include "./Linked_List.h"
#include "./graph.h"
#include "./user.h"

#include "./vectors.cpp"
#include "./bike.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

void mergeSortU(vectors<User> &array, int begin, int end);
void mergeUser(vectors<User> &array, int left, int mid, int right);
void mergeSortB(vectors<Bike> &array, int begin, int end);
void mergeBike(vectors<Bike> &array, int left, int mid, int right);

void mergeSortU(vectors<User> &array, int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSortU(array, begin, mid);
    mergeSortU(array, mid + 1, end);
    mergeUser(array, begin, mid, end);
}

void mergeUser(vectors<User> &array, int left, int mid, int right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new User[subArrayOne],
         *rightArray = new User[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array.arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array.arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne].startT < rightArray[indexOfSubArrayTwo].startT)
        {
            array.arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else if (rightArray[indexOfSubArrayTwo].startT < leftArray[indexOfSubArrayOne].startT)
        {
            array.arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        else
        {
            if (leftArray[indexOfSubArrayOne].userID < rightArray[indexOfSubArrayTwo].userID)
            {
                array.arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array.arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array.arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array.arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSortB(vectors<Bike> &array, int begin, int end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSortB(array, begin, mid);
    mergeSortB(array, mid + 1, end);
    mergeBike(array, begin, mid, end);
}

void mergeBike(vectors<Bike> &array, int left, int mid, int right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new Bike[subArrayOne],
         *rightArray = new Bike[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array.arr[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array.arr[mid + 1 + j];

    auto indexOfSubArrayOne = 0,   // Initial index of first sub-array
        indexOfSubArrayTwo = 0;    // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne].station < rightArray[indexOfSubArrayTwo].station)
        {
            array.arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else if (rightArray[indexOfSubArrayTwo].station < leftArray[indexOfSubArrayOne].station)
        {
            array.arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        else
        {
            if (leftArray[indexOfSubArrayOne].bikeID < rightArray[indexOfSubArrayTwo].bikeID)
            {
                array.arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else
            {
                array.arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array.arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array.arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void basic(string selectedCase)
{
    // insert your code here
    int userTot = 0;
    int stationMax = 0;

    string line;
    string path = "./testcases/" + selectedCase;

    // INPUT1 : input data from map.txt
    ifstream srcmap(path + "/map.txt");
    Graph *MainGraph = new Graph();
    int big = 0;
    int s1, s2, dis;
    if (srcmap.is_open())
    {
        string a, b, c;
        while (getline(srcmap, line))
        {
            stringstream ss(line);
            ss >> a;
            ss >> b;
            ss >> c;

            s1 = stoi(a.substr(1));
            s2 = stoi(b.substr(1));
            dis = stoi(c);

            MainGraph->dist[s1][s2] = dis;
            MainGraph->dist[s2][s1] = dis;

            if (big < s2 && s1 < s2)
            {
                big = s2;
            }
            else if (big < s1 && s2 < s1)
            {
                big = s1;
            }
        }
        MainGraph->n = big + 1;
        MainGraph->CalculateShort();
        srcmap.close();
    }
    else
    {
        cout << "not open" << endl;
    }

    // INPUT2 : input data from bike.txt
    int bikT, bikID, staton, renalC;
    float renalP;

    vectors<Bike> avaiBike[51];

    ifstream srcbike(path + "/bike.txt");
    if (srcbike.is_open())
    {
        string a, b, c, d, e;
        while (getline(srcbike, line))
        {
            stringstream ss(line);
            ss >> a;
            ss >> b;
            ss >> c;
            ss >> d;
            ss >> e;

            bikT = stoi(a.substr(1));
            bikID = stoi(b);
            staton = stoi(c.substr(1));
            renalP = stod(d);
            renalC = stoi(e);

            if (stationMax < staton)
            {
                stationMax = staton;
            }

            // cout<<staton<<" "<<bikT<<" "<<bikID<<" "<<renalP<<" "<<renalC<<endl;
            Bike temp(staton, bikT, bikID, renalP, renalC);
            temp.station = staton;
            temp.bikeT = bikT;
            temp.rentalP = renalP;
            temp.rentalC = renalC;
            avaiBike[bikT].insertHead(Bike(staton, bikT, bikID, renalP, renalC));
            avaiBike[bikT].arr[avaiBike[bikT].curr - 1].station = staton;
            avaiBike[bikT].arr[avaiBike[bikT].curr - 1].bikeT = bikT;
            avaiBike[bikT].arr[avaiBike[bikT].curr - 1].bikeID = bikID;
            avaiBike[bikT].arr[avaiBike[bikT].curr - 1].rentalP = renalP;
            avaiBike[bikT].arr[avaiBike[bikT].curr - 1].rentalC = renalC;
            // cout<< avaiBike[bikT].arr[avaiBike[bikT].curr-1].station<< " "<<avaiBike[bikT].arr[avaiBike[bikT].curr-1].bikeT<< " "<<avaiBike[bikT].arr[avaiBike[bikT].curr-1].bikeID<<" "<<endl<< avaiBike[bikT].arr[avaiBike[bikT].curr-1].rentalP<<" "<<avaiBike[bikT].arr[avaiBike[bikT].curr-1].rentalC<<endl;
        }
        srcbike.close();
    }
    else
    {
        cout << "not open" << endl;
    }
    /*
    for(int i=0; i<50; i++){
        for(int j=0; j<51; j++){
            if(avaiBike[i][j]!=NULL){
                cout<<i<<" "<<j<<" ";
                avaiBike[i][j]->printList();
            }

        }
    }
    */

    // INPUT3 : input data from user.txt
    ifstream srcuser(path + "/user.txt");
    vectors<User> userArr;
    int usr, strtT, enddT, strtP, enddP;

    int accbke[51] = {-1};
    if (srcuser.is_open())
    {
        string a, b, c, d, e, f;
        while (getline(srcuser, line))
        {
            stringstream ss(line);
            ss >> a;
            ss >> b;
            ss >> c;
            ss >> d;
            ss >> e;
            ss >> f;

            string tempp[51];
            stringstream temp(b);
            int i = 0;
            usr = stoi(a.substr(1));
            while (getline(temp, tempp[i], ','))
            {
                i++;
            }
            int accbken = i;
            i--;
            while (i + 1)
            {
                accbke[i] = stoi(tempp[i].substr(1));
                i--;
            }

            strtT = stoi(c);
            enddT = stoi(d);
            strtP = stoi(e.substr(1));
            enddP = stoi(f.substr(1));
            userArr.insertHead(User(usr, &accbke[0], strtT, enddT, strtP, enddP, accbken));

            userArr.arr[avaiBike[bikT].curr - 1].userID = usr;
            for (int i = 0; i < accbken; i++)
            {
                userArr.arr[userArr.curr - 1].accBike[i] = accbke[i];
            }
            userArr.arr[userArr.curr - 1].startT = strtT;
            userArr.arr[userArr.curr - 1].endT = enddT;
            userArr.arr[userArr.curr - 1].startP = strtP;
            userArr.arr[userArr.curr - 1].endP = enddP;
            userArr.arr[userArr.curr - 1].accBiken = accbken;
            // cout<<userArr.arr[userArr.curr-1].startT<<" "<<userArr.arr[userArr.curr-1].endT<<" "<<userArr.arr[userArr.curr-1].startP<<" "<<userArr.arr[userArr.curr-1].startP<<" "<<userArr.arr[userArr.curr-1].endP<<" "<<userArr.arr[userArr.curr-1].accBiken<<endl;
            // cout<<userArr.arr[userArr.curr-1].accBike[0]<<" "<<userArr.arr[userArr.curr-1].accBike[1]<<endl;
            // userArr.printAccBike();
            // cout<<endl;
            userTot++;
        }
        srcuser.close();
    }
    else
    {
        cout << "not open" << endl;
    }

    // INPUT4 : input data from bike_info.txt
    ifstream srcbinfo(path + "/bike_info.txt");
    string a, b;
    float discount;
    int rentLim;
    if (srcbinfo.is_open())
    {
        for (int i = 0; i < 2; i++)
        {
            getline(srcbinfo, line);
            stringstream ss(line);
            if (i == 0)
            {
                ss >> a;
            }
            else
            {
                ss >> b;
            }
        }
        discount = stof(a);
        rentLim = stoi(b);
        srcbinfo.close();
    }
    else
    {
        cout << "not open" << endl;
    }

    // starting to calculate data
    mergeSortU(userArr, 0, userArr.curr - 1);

    for (int i = 0; i < userArr.curr; i++)
    {
        cout << userArr.arr[i].startT << " " << userArr.arr[i].userID << endl;
    }

    vectors<User> out_User;
    vectors<Bike> out_Bike;

    for (int i = 0; i < userArr.curr; i++)
    {
        int tripTime = MainGraph->shortest[userArr.arr[i].startP][userArr.arr[i].endP];
        int rentalPnow = -1;
        int bikeTnow;
        int bikePos;
        int bikeIDnow = 999999999999;
        int revenue;

        if (tripTime < (userArr.arr[i].endT - userArr.arr[i].startT))
        {
            for (int j = 0; j < userArr.arr[i].accBiken; j++)
            {
                int accBikeT = userArr.arr[i].accBike[j];
                for (int k = 0; k < avaiBike[accBikeT].curr; k++)
                {
                    if (avaiBike[accBikeT].arr[k].station == userArr.arr[i].startP && avaiBike[accBikeT].arr[k].rentalC < rentLim && avaiBike[accBikeT].arr[k].rentalP > 0 && avaiBike[accBikeT].arr[k].prevArrive <= userArr.arr[i].startT)
                    {
                        if (userArr.arr[i].accept)
                        {
                            if (avaiBike[accBikeT].arr[k].rentalP > rentalPnow)
                            {
                                rentalPnow = avaiBike[accBikeT].arr[k].rentalP;
                                bikeIDnow = avaiBike[accBikeT].arr[k].bikeID;
                                bikeTnow = accBikeT;
                                bikePos = k;
                                userArr.arr[i].accept = 1;
                            }
                            else if (avaiBike[accBikeT].arr[k].rentalP == rentalPnow)
                            {
                                if (avaiBike[accBikeT].arr[k].bikeID < bikeIDnow)
                                {
                                    rentalPnow = avaiBike[accBikeT].arr[k].rentalP;
                                    bikeIDnow = avaiBike[accBikeT].arr[k].bikeID;
                                    bikeTnow = accBikeT;
                                    bikePos = k;
                                    userArr.arr[i].accept = 1;
                                }
                            }
                        }
                        else
                        {
                            rentalPnow = avaiBike[accBikeT].arr[k].rentalP;
                            bikeIDnow = avaiBike[accBikeT].arr[k].bikeID;
                            bikeTnow = accBikeT;
                            bikePos = k;
                            userArr.arr[i].accept = 1;
                        }
                    }
                }
            }
            revenue = rentalPnow * tripTime;
        }
        // cout<<avaiBike[bikeTnow].arr[bikePos].station<<" "<<avaiBike[bikeTnow].arr[bikePos].rentalP<<" "<<avaiBike[bikeTnow].arr[bikePos].rentalC<<" "<<avaiBike[bikeTnow].arr[bikePos].prevArrive<<endl;

        if (userArr.arr[i].accept)
        {
            cout << avaiBike[bikeTnow].arr[bikePos].station << " " << avaiBike[bikeTnow].arr[bikePos].rentalP << " " << avaiBike[bikeTnow].arr[bikePos].rentalC << " " << avaiBike[bikeTnow].arr[bikePos].prevArrive << endl;
            avaiBike[bikeTnow].arr[bikePos].station = userArr.arr[i].endP;
            avaiBike[bikeTnow].arr[bikePos].rentalP -= discount;
            avaiBike[bikeTnow].arr[bikePos].rentalC++;
            avaiBike[bikeTnow].arr[bikePos].prevArrive = userArr.arr[i].startT + tripTime;

            out_User.insertHead(User());
            out_User.arr[out_User.curr - 1].revenue = revenue;
            out_User.arr[out_User.curr - 1].userID = userArr.arr[i].userID;
            out_User.arr[out_User.curr - 1].accept = 1;
            out_User.arr[out_User.curr - 1].bikeIDacc = bikeIDnow;
            out_User.arr[out_User.curr - 1].startT = userArr.arr[i].startT;
            out_User.arr[out_User.curr - 1].arriveT = userArr.arr[i].startT + tripTime;
        }
        else
        {
            out_User.insertHead(User());
        }
    }

    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < avaiBike[i].curr; j++)
        {
            out_Bike.insertHead(Bike());
            // cout<<avaiBike[i].arr[j].station<<" "<<avaiBike[i].arr[j].bikeT<<" "<<avaiBike[i].arr[j].bikeID<<" "<<avaiBike[i].arr[j].rentalP<<" "<<avaiBike[i].arr[j].rentalC<<endl;
            out_Bike.arr[out_Bike.curr - 1].station = avaiBike[i].arr[j].station;
            out_Bike.arr[out_Bike.curr - 1].bikeT = avaiBike[i].arr[j].bikeT;
            out_Bike.arr[out_Bike.curr - 1].bikeID = avaiBike[i].arr[j].bikeID;
            out_Bike.arr[out_Bike.curr - 1].rentalP = avaiBike[i].arr[j].rentalP;
            out_Bike.arr[out_Bike.curr - 1].rentalC = avaiBike[i].arr[j].rentalC;
        }
    }

    // mergeSortB(out_Bike, 0, out_Bike.curr-1);

    ofstream rsltStation("result/" + selectedCase + "/station_status.txt");
    ofstream rsltUser("result/" + selectedCase + "/user_result.txt");
    ofstream rsltLog("result/" + selectedCase + "/transfer_log.txt");

    for (int i = 0; i < out_Bike.curr; i++)
    {
        rsltStation << "S" << out_Bike.arr[i].station << " " << out_Bike.arr[i].bikeID << " B" << out_Bike.arr[i].bikeT << " " << out_Bike.arr[i].rentalP << " " << out_Bike.arr[i].rentalC << "\n";
    }

    for (int i = 0; i < out_User.curr - 1; i++)
    {
        rsltUser << "U" << out_User.arr[i].userID << " " << out_User.arr[i].accept << " " << out_User.arr[i].bikeIDacc << " " << out_User.arr[i].startT << " " << out_User.arr[i].arriveT << " " << out_User.arr[i].revenue << "\n";
    }

    for (int i = 0; i < out_User.curr - 1; i++)
    {
        if (out_User.arr[i].accept)
            rsltLog << out_User.arr[i].bikeIDacc << " S" << out_User.arr[i].startP << " S" << out_User.arr[i].endP << " " << out_User.arr[i].startT << " " << out_User.arr[i].endT << " U" << out_User.arr[i].userID << "\n";
    }

    rsltStation.close();
    rsltLog.close();
    rsltUser.close();

    // LATERRRRR
}
