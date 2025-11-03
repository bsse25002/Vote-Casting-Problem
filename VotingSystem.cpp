#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int ch, IMS_num, IAS_num, Alumni_num, IMSVotes, IASVotes, AlumniVotes;
    vector<string> IMS, IAS, Alumni;
    vector<int> IMS_Votes, IAS_Votes, Alumni_Votes;

    while(true){
        cout << "\t\t\t*****MENU*****\n\t0) Close Program \n\t1)Prepare Voting System\n\t2)Cast Votes\n\t3)Result" << endl;
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
            for(int i = 0;i < IMS_num;i++) {
                string name;
                cin >> name;
                IMS.push_back(name);
                IMS_Votes.push_back(0);
                
                if(i != IMS_num-1) {
                    cout << "Next Candidate!" << endl;
                }
            }

            cout << "ii) IAS Society: " << endl;
            for(int i = 0;i < IAS_num;i++) {
                string name;
                cin >> name;
                IAS.push_back(name);
                IAS_Votes.push_back(0);
                
                if(i != IAS_num-1) {
                    cout << "Next Candidate!" << endl;
                }
            }

            cout << "ii) Alumni Society: " << endl;
            for(int i = 0;i < IAS_num;i++) {
                string name;
                cin >> name;
                Alumni.push_back(name);
                Alumni_Votes.push_back(0);
                
                if(i != Alumni_num-1) {
                    cout << "Next Candidate!" << endl;
                }
            }
        } else if(ch == 2) {
            cout << "\t\t***** Instructions for Vote Casting *****\n\tEnter the desired Index to which candidate you want to vote!" << endl;
            int vote;

            cout << "i) IMS Society: " << endl;
            for(int i = 0;i < IMS_num;i++) {
                cout << i << ") " << IMS[i] << endl;
            }
            cout << endl;

            cin >> vote;            
            if(vote < 0 || vote >= IMS_num) {
                cout << "Invalid Vote!(Out of Range)" << endl;
            } else {
                for(int i = 0;i < IMS_num;i++) {
                    if(vote == i) {
                        IMS_Votes[i]++;
                        IMSVotes++;
                    }
                }
            }

            cout << "ii) IAS Society: " << endl;
            for(int i = 0;i < IAS_num;i++) {
                cout << i << ") " << IAS[i] << endl;
            }
            cout << endl;

            cin >> vote;            
            if(vote < 0 || vote >= IAS_num) {
                cout << "Invalid Vote!(Out of Range)" << endl;
            } else {
                for(int i = 0;i < IAS_num;i++) {
                    if(vote == i) {
                        IAS_Votes[i]++;
                        IASVotes++;
                    }
                }
            }

            cout << "iii) Alumni Society: " << endl;
            for(int i = 0;i < Alumni_num;i++) {
                cout << i << ") " << Alumni[i] << endl;
            }
            cout << endl;

            cin >> vote;            
            if(vote < 0 || vote >= Alumni_num) {
                cout << "Invalid Vote!(Out of Range)" << endl;
            } else {
                for(int i = 0;i < Alumni_num;i++) {
                    if(vote == i) {
                        Alumni_Votes[i]++;
                        AlumniVotes++;
                    }
                }
            }
        } else if(ch == 3) {
            cout << "\t\t*****RESULT*****\n\ti) Result for IMS Society" << endl;
            cout << "Name\tGained Votes\tTotal Votes\tPercentage" << endl;
            for(int i = 0;i < IMS_num;i++) {
                cout << i << ") " << IMS[i] << ": \t" << IMS_Votes[i] << "\t" << IMSVotes << "\t" << float((IMS_Votes[i]*100)/IMSVotes) << endl;
            }

            cout << "\t\t****FINAL IMS RESULT****" << endl;
            int highestEl = IMS_Votes[0], max = 0;
            for(int i = 1;i < IMS_num;i++) {
                if(IMS_Votes[i] > highestEl) {
                    highestEl = IMS_Votes[i];
                    max = i;
                }
            }
            cout << "WINNER: " << IMS[max] << endl;

            cout << "\ti) Result for IAS Society" << endl;
            cout << "Name\tGained Votes\tTotal Votes\tPercentage" << endl;
            for(int i = 0;i < IAS_num;i++) {
                cout << i << ") " << IAS[i] << ": \t" << IAS_Votes[i] << "\t" << IASVotes << "\t" << float((IAS_Votes[i]*100)/IASVotes) << endl;
            }

            cout << "\t\t****FINAL IAS RESULT****" << endl;
            int highestEl = IAS_Votes[0], max = 0;
            for(int i = 1;i < IAS_num;i++) {
                if(IAS_Votes[i] > highestEl) {
                    highestEl = IAS_Votes[i];
                    max = i;
                }
            }
            cout << "WINNER: " << IAS[max] << endl;

            cout << "\ti) Result for Alumni Society" << endl;
            cout << "Name\tGained Votes\tTotal Votes\tPercentage" << endl;
            for(int i = 0;i < Alumni_num;i++) {
                cout << i << ") " << Alumni[i] << ": \t" << Alumni_Votes[i] << "\t" << AlumniVotes << "\t" << float((Alumni_Votes[i]*100)/AlumniVotes) << endl;
            }

            cout << "\t\t****FINAL Alumni RESULT****" << endl;
            int highestEl = Alumni_Votes[0], max = 0;
            for(int i = 1;i < Alumni_num;i++) {
                if(Alumni_Votes[i] > highestEl) {
                    highestEl = Alumni_Votes[i];
                    max = i;
                }
            }
            cout << "WINNER: " << Alumni[max] << endl;

            break;
        } else {
            cout << "Invalid Choice Try Again!" << endl;
        }
    }

    return 0;
}