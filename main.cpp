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
            voter_list.push_back(line);
        }

        //identity voter id
        void identify_voter_id(std::string& voter_line){
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
        void print_voter_choices(std::string& voter_line){
            size_t line_length = voter_line.length();
            for(int i = 0; i < line_length; i++){
                char l = voter_line[i];
                if(std::isalpha(l)){
                    std::cout << l;
                    if(l >= 'A' && l <= 'C'){
                        mayor_choice(l);
                    } else if(l >= 'D' && l <= 'E'){
                        proposition_17_result(l);
                    } else if(l >= 'F' && l <= 'G'){
                        measure_1_result(l);
                    } else if(l >= 'H' && l <= 'I'){
                        measure_2_result(l);
                    }    
                }
            }
        }

        

        void mayor_choice(char& line){
            if(line == 'A'){
                vote_mayor_choice = "Pincher";
            } else if(line == 'B'){
                vote_mayor_choice = "Dover";
            } else if(line == 'C'){
                vote_mayor_choice = "Perman";
            }else{
                vote_mayor_choice = "Error no mayor found"; 
            }
        }

        void proposition_17_result(char& line){
            if (line == 'D'){
                yes_no_prop_17 = "YES";
            } else if (line == 'E'){
                yes_no_prop_17 = "NO";
            } else {
                yes_no_prop_17 = "ERROR prop 17 failed to find letter";
            }
        }
        void measure_1_result(char& line){
            if (line == 'F'){
                yes_no_measure_1 = "YES";
            } else if (line == 'G'){
                yes_no_measure_1 = "NO";
            } else {
                yes_no_measure_1 = "ERROR prop 17 failed to find letter";
            }
        }
        void measure_2_result(char& line){
            if (line == 'H'){
                yes_no_measure_2 = "YES";
            } else if (line == 'I'){
                yes_no_measure_2 = "NO";
            } else {
                yes_no_measure_2 = "ERROR prop 17 failed to find letter";
            }
        }

         //check voter info
        void check_voter_info(const int& n){
            std::string line = voter_list[n];
            std::cout << "Voter ";
            identify_voter_id(line);
            std::cout << " voted: ";
            print_voter_choices(line);
            print_voter_picks();
        }
        
        void print_voter_picks(){
            std::cout << " (" << vote_mayor_choice << ", " << yes_no_prop_17 << " on PROP 17 " << ", " << yes_no_measure_1  << " on MEASURE 1" << ", " << yes_no_measure_2 << " on MEASURE 2)" << std::endl;
        }

        //count choices
        void count_choices(char& letter){
            switch(letter){
                //mayors
                case 'A':
                case 'a':
                    penny++;
                    break;
                case 'B':
                case 'b':
                    skip++;
                    break;
                case 'C':
                case 'c':
                    sue++;
                    break;

                //proposition 17
                //yes
                case 'D':
                case 'd':
                    proposition_17_yes++;
                    break;
                //no
                case 'E':
                case 'e':
                    proposition_17_no++;
                    break;
                
                //Measure 1
                //yes
                case 'F':
                case 'f':
                    measure_1_yes++;
                    break;
                //no
                case 'G':
                case 'g':
                    measure_1_no++;
                    break;

                //Measure 2
                //yes
                case 'H':
                case 'h':
                    measure_2_yes++;
                    break;
                //no
                case 'I':
                case 'i':
                    measure_2_no++;
                    break;
                
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


        double int_to_percentage(int& candidate, double& total){
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
        
        void pick_voter(){
            int user_input{0};
            std::cout << "Enter a number: ";
            std::cin >> user_input;
            check_voter_info(user_input);
        }
        

    private:

        //variables
        //vector
        std::vector<std::string> voter_list;
        
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

        //string variables
        std::string vote_mayor_choice;
        std::string yes_no_prop_17;
        std::string yes_no_measure_1;
        std::string yes_no_measure_2;
};


int main(){
    //debug
    std::string typo_test = "votts_small.txt";
    std::string main_file = "votes_small.txt";
    std::string large_file = "votes_large.txt";
    voter test;
    test.process_file_results(large_file);
    // test.debug_display_result();
    
    //calculate total votes
    test.mayor_total_vote();
    test.proposition_17_total_vote();
    test.measure_1_total_vote();
    test.measure_2_total_vote();

    //display results
    test.display_result();
    std::cout << std::endl;
    test.pick_voter();
    
    return 0;
}