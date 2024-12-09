#include "GooseFilterLib.h"

void MovingAverage::HistoryUpdate(double* input_data)
{
    // Input History Update
    if(input_index >= this->filter_size) input_index = 0;
    input_history[input_index] = *input_data;
    input_index++;

    // Filtered Output Update
    this->output = 0;
    for(int i=0; i<this->filter_size; i++) {this->output += input_history;}
    this->output = this->output/this->filter_size ;
}

void MovingAverage::GetOutput(double* output_filtered)
{
    *output_filtered = this->output;
}

void MovingAverage::GetFiltered(double* input_data, double* output_filtered)
{
    this->HistoryUpdate(&input_data);
    *output_filtered = this->output;
}
