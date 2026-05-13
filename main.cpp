#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class voter{
    public:

        //check file is readbale
        bool check_file(const std::ifstream& filename){
            //check if is open
            if(!filename.is_open()){
                std::cout << "Error can't read file";
                return false;
            }
            return true;
        } 

        //check file's line readability
        bool check_file_line(std::ifstream& filename, std::string& line){
            if(getline(filename, line)){
                return true;
            }
            std::cout << "ERROR: cant read line" << std::endl;
            return false;
        } 
        
        //get result from file
        void process_file_results(const std::string& filename){
            std::ifstream file(filename);
            std::string line;

            if(check_file(file)){
                if(check_file_line(file, line)){
                    while(getline(file, line)){
                        std::cout << line << std::endl;
                    }
                }
            }
            return;
        }

    private:
        //variables

        //vector
        std::vector<int> voter_ids;
        std::vector<std::string> voter_choices;
        
        // -- Mayors --
        int penny{0}; //Letter A
        int skip{0};  //Letter B
        int sue{0};   //Letter C

        // -- Proposition 17 --
        int proposition_17_yes{0};
        int proposition_17_no{0};

        // -- Measure 1 --
        int measure_1_yes{0};
        int measure_1_no{0};

        // -- Measure 2 --
        int measure_2_yes{0};
        int measure_2_no{0};

        // general 
        int count{0};
        const int total{100};
};


int main(){
    std::string typo_test = "votts_small.txt";
    std::string main_file = "votes_small.txt";
    voter test;
    test.process_file_results(main_file);
    return 0;
}