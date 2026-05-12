#include <iostream>
#include <fstream>

class voter{
    public:
        void read_from_file(const std::string& f){
            std::ifstream file(f);
            std::string line;

            //get each line
            while(getline(file, line)){

            }
        }

        void check_voter_choices(std::string& x){
            switch(x){
                case A:
                case a:
                    
            }
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

int user_input(int& x){
    using namespace std;
    int x;
    cout << "Enter an integer:" << endl;
    cin >> x;
    return x;
}



int main(){
    return 0;
}