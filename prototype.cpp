#include <iostream>
#include <fstream>

std::vector<int> voter_ids;
std::vector<std::string> voter_choices;
int count{0};

int save_value_int(char value){
    int x = value - '0';
    //debug
    // std::cout << typeid(x).name() << std::endl;
    return x;
}
std::string save_value_str(char value){
    std::string j(1, value);
    // std::cout << typeid(j).name() << std::endl;
    // std::cout << j << std::endl;
    return j;
}


void read_from_file(const std::string& x){
    std::ifstream file(x);
    std::string line;

    int num[4];
    std::string words[9];

    //get each line
    while(getline(file, line)){
        //debug output line
        std::cout << line << std::endl;
        int string_legnth = line.length();
        // std::cout << string_legnth << std::endl;

        for(int i = 0; i < string_legnth; i++){
            //if line contains digit
            if(isdigit(line[i])){
                //debug 
                // std::cout << line[i] << std::endl;

                num[i] = save_value_int(line[i]);

            } else if(isalpha(line[i])){
                //if line contains alpha
                // std::cout << line[i] << std::endl;

                words[i] = save_value_str(line[i]);
            } else if(isspace(line[i])){
                //if line contains white space -- pass
                continue;
            }
            
            //after finish save it
            if(i == (string_legnth - 1)){
                int combined_num{0};
                std::string combined_letter;

                for(int j = 0; j < 4; j++){
                    combined_num = (combined_num * 10) + num[j];
                    
                }
                for(int p = 5; p < 9; p++){
                    combined_letter = combined_letter + words[p];
                }
                
                voter_ids.push_back(combined_num);
                voter_choices.push_back(combined_letter);
                count++;
            }
        }
    }
}


int main(){
    int dummyplace{0};
    read_from_file("votes_small.txt");
    std::cout << std::endl;
    std::cout << "debug" << std::endl;
    std::cout << count << std::endl;
    std::cout << voter_ids[0] << std::endl;
    std::cout << voter_ids[1] << std::endl;
    std::cout << voter_ids[2] << std::endl;
    std::cout << voter_choices[0] << std::endl;
    std::cout << voter_choices[1] << std::endl;
    std::cout << voter_choices[2] << std::endl;

    //variables
    //mayors
    int penny{0};
    int skip{0};
    int sue{0};
    //Proposition 17
    int Proposition_yes{0};
    int Proposition_no{0};
    //Measure 1
    int Measure_1_yes{0};
    int Measure_1_no{0};
    //Measure 2
    int Measure_2_yes{0};
    int Measure_2_no{0};
    
    while(dummyplace < count){
        std::cout << "debug" << std::endl;
        for(int i = 0; i < 4; i++){
            if(voter_choices[dummyplace][i] == 'A'){
                penny++;
            }
        } 
        dummyplace++;
    }
    //debug 
    std::cout << penny << std::endl;

    //total price
    const int total{100};
    double percentage = (static_cast<double>(penny) / total) * 100;
    std::cout << percentage << "%" << std::endl;

    //debug display voter info
    int user_input{0};
    std::cout << "Enter a number: ";
    std::cin >> user_input;
    std::cout << "Voter ID: " << voter_ids[user_input] << ". Voter Choices: " << voter_choices[user_input];

    //debug choics
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
                if(voter_choices[i][j] == 'A'){
                std::cout << "penny" << std::endl;
            } else if(voter_choices[i][j] == 'B'){
                std::cout << "Skip" << std::endl;
            } else if(voter_choices[i][j] == 'C'){
                std::cout << "Sue" << std::endl;
            } else if(voter_choices[i][j] == 'D'){
                std::cout << "Yes" << std::endl;
            } else if(voter_choices[i][j] == 'E'){
                std::cout << "No" << std::endl;
            } else if(voter_choices[i][j] == 'F'){
                std::cout << "Yes" << std::endl;
            } else if(voter_choices[i][j] == 'G'){
                std::cout << "No" << std::endl;
            } else if(voter_choices[i][j] == 'H'){
                std::cout << "Yes" << std::endl;
            } else if(voter_choices[i][j] == 'I'){
                std::cout << "No" << std::endl;
            } 
        }
    }
    
    
    return 0;
}