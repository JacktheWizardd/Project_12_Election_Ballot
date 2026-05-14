#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class voter{
    public:

        // ------ debug ------
        //check file is readbale
        bool check_file(const std::ifstream& filename){
            //check if is open
            if(!filename.is_open()){
                std::cout << "ERROR: can't read file";
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
        
        //process file 
        bool process_file_results(const std::string& filename){
            std::ifstream file(filename);
            std::string line;

            if(check_file(file)){
                if(check_file_line(file, line)){
                    read_each_line(file, line);
                    return true;
                }
            }
            std::cout << "ERROR: failed to read the file" << std::endl;
            return false;
        }

        //read each line
        void read_each_line(std::ifstream& file, std::string& line){
            while(getline(file, line)){
                save_vote(line);
                identity_voter_choices(line);
            }
            //debug vector
            // std::cout << voter[1] << std::endl;
        }
        
        //Records a voter's ID and their selection into the tracking vector
        void save_vote(std::string& line){
            voter.push_back(line);
        }

        //identity voter id
        
        //identity voter choices;
        void identity_voter_choices(std::string& voter_line){
            size_t line_length = voter_line.length();
            for(int i = 0; i < line_length; i++){
                if(std::isalpha(voter_line[i])){
                    count_choices(voter_line[i]);
                }
            }
        }

        //count choices
        void count_choices(char& letter){
            switch(letter){
                //mayors
                case 'A':
                case 'a':
                    penny++;
                case 'B':
                case 'b':
                    skip++;
                case 'C':
                case 'c':
                    sue++;

                //proposition 17
                //add the rest of the variables.
            }
            //debug 
            
        }
        
        //debug function - display variable result
        void debug_display_result(){
            std::cout << penny << std::endl;
            std::cout << skip << std::endl;
            std::cout << sue << std::endl;
        }

    private:

        //variables
        //vector
        std::vector<std::string> voter;
        
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
    //debug
    std::string typo_test = "votts_small.txt";
    std::string main_file = "votes_small.txt";
    voter test;
    test.process_file_results(main_file);
    test.debug_display_result();
    return 0;
}