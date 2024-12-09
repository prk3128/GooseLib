#ifndef GOOSEFILTERLIB_H
#define GOOSEFILTERLIB_H

#include <Eigen/Eigen>
#include <Eigen/Dense>

class MovingAverage
{
    private:
        int filter_size;
        double initial_value;
        double* input_history;
        int input_index;
        double output;
        
    public:
        MovingAverage(int filter_size_=1, double initial_value_=0)
        {  
            // Create Input History Memory
            if(filter_size_<0) {this->filter_size=1;}
            this->input_history = new double[filter_size_];

            // Initialize Input History Memory
            this->initial_value = initial_value_;
            for(int i=0; i<this->filter_size; i++) {input_history(i)=this->initial_value;}
            
            // Set Input History Memory index
            this->input_index = 0;
        };
            
        ~MovingAverage(){ delete input_history; };

        void HistoryUpdate(double* input_data);
        void GetOutput(double* output_filtered);
        void GetFiltered();
}

#endif