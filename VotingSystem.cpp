#include <iostream>
#include <vector>
#include <string>
using namespace std;

void arrBuilder(string society, string arr[], int arrVotes[], int num) {
    cout << "Making Candidates List for " << society << endl;

    if(num <= 0 || num >= 100) {
        cout << "Number of Candidates Out of Range!" << endl;
        return;
    }

    cout << "1. Enter the names of candidates for " << society << " Society!" << endl;

    for(int i = 0;i < num;i++) {
        string name;
        cin >> name;
        arr[i] = name;
        arrVotes[i] = 0;
        
        if(i != num-1) {
            cout << "Next Candidate!" << endl;
        }
    }
}

void arrExtender(string society, string arr[], int arrVotes[], int num, int extra) {
    cout << "Making Candidates List for " << society << endl;

    if(num + extra <= 0 || num + extra >= 100) {
        cout << "Number of Candidates Out of Range!" << endl;
        return;
    }

    cout << "1. Enter the names of candidates for " << society << " Society!" << endl;

    for(int i = num;i < num+extra;i++) {
        string name;
        cin >> name;
        arr[i] = name;
        arrVotes[i] = 0;
        
        if(i != (num+extra)-1) {
            cout << "Next Candidate!" << endl;
        }
    }
}

void voting(string society, string arr[], int arrVotes[], int num, int& totalVotes) {
    int vote;

    cout << "=> " << society << " Society:" << endl;
    for(int i = 0;i < num;i++) {
        cout << i << ") " << arr[i] << endl;
    }
    cout << endl;

    cin >> vote;            
    if(vote < 0 || vote >= num) {
        cout << "Invalid Vote!(Out of Range)" << endl;
    } else {
        for(int i = 0;i < num;i++) {
            if(vote == i) {
                arrVotes[i]++;
                totalVotes++;
            }
        }
    }
}

void Result(string society, string arr[], int arrVotes[], int num, int totalVotes) {
    cout << "Result for " << society << "Society" << endl;

    cout << "Name\tGained Votes\tTotal Votes\tPercentage" << endl;
    for(int i = 0;i < num;i++) {
        cout << i << ") " << arr[i] << ": \t" << arrVotes[i] << "\t" << totalVotes << "\t" << float((arrVotes[i]*100)/totalVotes) << endl;
    }

    cout << "\t\t****FINAL " << society << " RESULT****" << endl;
    
    int highestEl = arrVotes[0], max = 0;
    for(int i = 1;i < num;i++) {
        if(arrVotes[i] > highestEl) {
            highestEl = arrVotes[i];
            max = i;
        }
    }
    cout << "WINNER: " << arr[max] << endl;
}

int main() {
    int ch;
    string IMS[100], IAS[100], Alumni[100];
    int IMS_Votes[100], IAS_Votes[100], Alumni_Votes[100];
    int IMS_num, IAS_num, Alumni_num, IMSVotes, IASVotes, AlumniVotes;

    while(true){
        cout << "\t\t\t*****MENU*****\n\t0) Close Program\n\t1)Prepare Voting System\n\t2)Add More Candidaates\n\t3)Cast Votes\n\t4)Result" << endl;
        cin >> ch;
        
        if(ch == 0) {
            cout << "\t\tThankyou!" << endl;
            break;

        } else if(ch == 1) {
            cout << "\t\t***** Instructions for Voting System Preparation *****\n\tEnter the name and number of candidates for each society step by step!" << endl;

            cout << "1. Enter the number of candidates for each Society!\ni) IMS Society: " << endl;
            cin >> IMS_num;

            cout << "ii) IAS Society: " << endl;
            cin >> IAS_num;

            cout << "iii) Alumni Society: " << endl;
            cin >> Alumni_num;

            cout << "1. Enter the names of candidates for each Society!\ni) IMS Society: " << endl;
            arrBuilder("IMS", IMS, IMS_Votes, IMS_num);

            cout << "ii) IAS Society: " << endl;
            arrBuilder("IAS", IAS, IAS_Votes, IAS_num);

            cout << "ii) Alumni Society: " << endl;
            arrBuilder("Alumni", Alumni, Alumni_Votes, Alumni_num);

        } else if(ch == 2) {
            int chose;

            cout << "Chose which Society needs more Candidates:\n\t0) Stop Adding Candidates\n\t1) IAS Society\n\t2) IMS Society\n\t3) Alumni Society" << endl;
            cin >> chose;

            while (true) {
                if(chose == 1) {
                    int extra;

                    cout << "Enter the number of candidates to be added:" << endl;
                    cin >> extra;

                    arrExtender("IMS", IMS, IMS_Votes, IMS_num, extra);
                    IMS_num += extra;
                } else if(chose == 2) {
                    int extra;

                    cout << "Enter the number of candidates to be added:" << endl;
                    cin >> extra;

                    arrExtender("IAS", IAS, IAS_Votes, IAS_num, extra);
                    IAS_num += extra;
                } else if(chose == 3) {
                    int extra;

                    cout << "Enter the number of candidates to be added:" << endl;
                    cin >> extra;

                    arrExtender("Alumni", Alumni, Alumni_Votes, Alumni_num, extra);
                    Alumni_num += extra;
                } else if(chose == 0) {
                    cout << "More Candidates Added!" << endl;
                    break;
                } else {
                    cout << "Invalid Choice! Try Again" << endl;
                }
            }

        } else if(ch == 3) {
            cout << "\t\t***** Instructions for Vote Casting *****\n\tEnter the desired Index to which candidate you want to vote!" << endl;
            
            voting("IMS", IMS, IMS_Votes, IMS_num, IMSVotes);

            voting("IAS", IAS, IAS_Votes, IAS_num, IASVotes);

            voting("Alumni", Alumni, Alumni_Votes, Alumni_num, AlumniVotes);

        } else if(ch == 4) {
            cout << "\t\t*****RESULT*****" << endl;
            
            Result("IMS", IMS, IMS_Votes, IMS_num, IMSVotes);

            Result("IAS", IAS, IAS_Votes, IAS_num, IASVotes);

            Result("Alumni", Alumni, Alumni_Votes, Alumni_num, AlumniVotes);

            break;
        } else {
            cout << "Invalid Choice Try Again!" << endl;
        }
    }

    return 0;
}