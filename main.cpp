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
                identify_voter_choices(line);
            }
            //debug vector
            // std::cout << voter[1] << std::endl;
        }
        
        //Records a voter's ID and their selection into the tracking vector
        void save_vote(std::string& line){
            voter.push_back(line);
        }

        //identity voter id
        void identif_voter_id(std::string& voter_line){
            size_t line_length = voter_line.length();
            for(int i = 0; i < line_length; i++){
                if(std::isdigit(voter_line[i])){
                    std::cout << voter_line[i];
                }
            }
        }

        //identity voter choices;
        void identify_voter_choices(std::string& voter_line){
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
                //yes
                case 'D':
                case 'd':
                    proposition_17_yes++;
                //no
                case 'E':
                case 'e':
                    proposition_17_no++;
                
                //Measure 1
                //yes
                case 'F':
                case 'f':
                    measure_1_yes++;
                //no
                case 'G':
                case 'g':
                    measure_1_no++;

                //Measure 2
                //yes
                case 'H':
                case 'h':
                    measure_2_yes++;
                //no
                case 'I':
                case 'i':
                    measure_2_no++;
                
            }        
        }
        
        //display result
        void display_result(){
            using namespace std;

            cout << "=== Vote Totals ===" << endl;
            cout << "Mayor:" << endl;
            cout << "   A. Pincher, Penny.  :" << int_to_percentage(penny, mayor_total_count) << "%" << endl;
            cout << "   B. Dover, Skip.     :" << int_to_percentage(skip, mayor_total_count) << "%" << endl;
            cout << "   C. Perman, Sue.     :" << int_to_percentage(sue, mayor_total_count) << "%" << endl;
            std::cout << std::endl;

            cout << "Proposition 17:" << endl;
            cout << "   D. Yes              :" << int_to_percentage(proposition_17_yes, proposition_17_total_count) << "%" << endl;
            cout << "   E. No               :" << int_to_percentage(proposition_17_no, proposition_17_total_count) << "%" << endl;
            std::cout << std::endl;
            
            cout << "Measure 1:" << endl;
            cout << "   F. Yes              :" << int_to_percentage(measure_1_yes, measure_1_total_count) << "%" << endl;
            cout << "   G. No               :" << int_to_percentage(measure_1_no, measure_1_total_count) << "%" << endl;
            std::cout << std::endl;

            cout << "Measure 2:" << endl;
            cout << "   H. Yes              :" << int_to_percentage(measure_2_yes, measure_2_total_count) << "%" << endl;
            cout << "   I. Yes              :" << int_to_percentage(measure_2_no, measure_2_total_count) << "%" << endl;
        }

        //check voter info
        

        int int_to_percentage(int& candidate, double& total){
            return (candidate / total) * 100;
        }

        //total votes
        int mayor_total_vote(){
            mayor_total_count = penny + skip + sue;
            return mayor_total_count;
        }
        int proposition_17_total_vote(){
            proposition_17_total_count = proposition_17_yes + proposition_17_no;
            return proposition_17_total_count;
        }
        int measure_1_total_vote(){
            measure_1_total_count = measure_1_yes + measure_1_no;
            return measure_1_total_count;
        }
        int measure_2_total_vote(){
            measure_2_total_count = measure_2_yes + measure_2_no;
            return measure_2_total_count;
        }

        //debug function - display variable result
        void debug_display_result(){
            std::cout << penny << std::endl;
            std::cout << skip << std::endl;
            std::cout << sue << std::endl;

            std::cout << "proposition 17" << std::endl;
            std:: cout <<proposition_17_yes << std::endl;
            std:: cout <<proposition_17_no << std::endl;
            std::cout << "" << std::endl;

            std::cout << "Measure 1" << std::endl;
            std:: cout <<measure_1_yes << std::endl;
            std:: cout <<measure_1_no << std::endl;

            std::cout << "" << std::endl;
            std::cout << "Measure 2" << std::endl;
            std:: cout <<measure_2_yes << std::endl;
            std:: cout <<measure_2_no << std::endl;
        }

    private:

        //variables
        //vector
        std::vector<std::string> voter;
        
        // -- Mayors --
        int penny{0};              //Letter A
        int skip{0};               //Letter B
        int sue{0};                //Letter C
        double mayor_total_count{0};

        // -- Proposition 17 --
        int proposition_17_yes{0}; //letter D
        int proposition_17_no{0};  //letter E
        double proposition_17_total_count{0};

        // -- Measure 1 --
        int measure_1_yes{0};      //letter F
        int measure_1_no{0};       //letter G
        double measure_1_total_count{0};

        // -- Measure 2 --
        int measure_2_yes{0};      //letter H
        int measure_2_no{0};       //letter I
        double measure_2_total_count{0};   
};


int main(){
    //debug
    std::string typo_test = "votts_small.txt";
    std::string main_file = "votes_small.txt";
    voter test;
    test.process_file_results(main_file);
    // test.debug_display_result();
    
    //calculate total votes
    test.mayor_total_vote();
    test.proposition_17_total_vote();
    test.measure_1_total_vote();
    test.measure_2_total_vote();

    //display results
    test.display_result();
    return 0;
}