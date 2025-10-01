#include "AttributeTranslator.hpp"

/////////////////////////////////////////////////////////////////////////////////////Метки//////////////////
int label_jump_int = 0;
vector<string> lable_; // Храним метку в которую переходит jump
vector<string> lable_jump_; // Храним метку после jump 
string generateLabel() {
    //vector lable; 
    //vector lable_jump;
    int size_vector = 0;
    while (size_vector < lable_jump_.size())
    {
        if ("L" + to_string(label_jump_int) == lable_jump_[size_vector])
        {
            label_jump_int++;
            size_vector = 0;
        }
        else
        {
            size_vector++;
        }

    }
    lable_.push_back("L" + to_string(label_jump_int));
    lable_jump_.push_back("L" + to_string(label_jump_int));

    return "L" + to_string(label_jump_int);
}
//ЗАнесение метки в ветор меток 
int Find_Lable(string lable2_) // -1 warning / 1 - good
{
    for (int size_vector = 0; (size_vector < lable_.size()); size_vector++)
    {
        if (lable2_ == lable_[size_vector])
            return -1;
    }
    string copy_lable2_ = lable2_;
    copy_lable2_.pop_back();
    lable_.push_back(copy_lable2_);
    return 1;
}
int Find_Lable_jump(string lable2_)
{
    for (int size_vector = 0; (size_vector < lable_jump_.size()); size_vector++)
    {
        if (lable2_ == lable_[size_vector])
            return -1;
    }
    lable_jump_.push_back(lable2_);
    return 1;
}
string Find_pars_lables(vector<string> labl_, vector<string> Labl_jm)
{
    if (labl_.size() != Labl_jm.size())
        return "size";
    for (int size_Labl_jm = 0; size_Labl_jm < Labl_jm.size(); size_Labl_jm++)
    {
        for (int size_labl_ = 0; size_labl_ < labl_.size(); size_labl_++)
        {
            if (Labl_jm[size_Labl_jm] == labl_[size_Labl_jm])
                continue;
        }
        if (Labl_jm[size_Labl_jm] != labl_[size_Labl_jm])
            return Labl_jm[size_Labl_jm];
    }
    return "good";
}