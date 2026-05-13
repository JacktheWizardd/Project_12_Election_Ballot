#include <iostream>
#include <fstream>
#include <sstream>

class voter{
    public:

        //check file is readbale
        bool read_from_file(const std::string& filename){
            std::ifstream file(filename);
            //check if is open
            if(!file.is_open()){
                std::cout << "Error file is not open";
            }
            return file.good();
        } 

        //check file's line readability
        

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
    voter test;
    test.read_from_file("votes_small.txt");

    return 0;
}