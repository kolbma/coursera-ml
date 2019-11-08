// util.hpp
#ifndef COURSERA_UTIL_HPP
#define COURSERA_UTIL_HPP

#include <cassert>
#include <string>
#include <vector>

template <typename T>
void parse_mat(T *targetmat, const std::string source)
{
    using namespace std;
    using namespace arma;

    static_assert(is_base_of<mat, T>::value || is_base_of<fmat, T>::value, "T must extend Armadillo Mat<double> || Mat<float>");

    if (!(source.front() == '[' && source.back() == ']'))
    {
        throw new invalid_argument("can not parse Mat");
    }

    size_t cols = 0, rows = 0;
    vector<double> v;

    size_t semi_pos = 0, lsemi_pos = 0;
    do
    {
        size_t c = 0;
        size_t col_pos = semi_pos, lcol_pos = lsemi_pos;
        semi_pos = source.find(';', semi_pos + 1);
        do
        {
            const auto srclen = (semi_pos != string::npos ? semi_pos : source.length()) - 1;
            col_pos = source.substr(0, srclen).find(',', col_pos + 1);
            if (col_pos != string::npos)
            {
                v.push_back(stod(source.substr(lcol_pos + 1, col_pos - lcol_pos)));
                c++;
            }
            else if (semi_pos != string::npos)
            {
                // get single/last column
                v.push_back(stod(source.substr(lcol_pos + 1, semi_pos - lcol_pos)));
                c++;
            }
            else
            {
                // get last column in last row
                v.push_back(stod(source.substr(lcol_pos + 1, source.length() - 1)));
                c++;
            }
            lcol_pos = col_pos;
        } while (col_pos != string::npos);
        lsemi_pos = semi_pos;
        if (cols == 0)
        {
            cols = c;
        }
        else
        {
            assert(cols == c);
        }
        rows++;
    } while (semi_pos != string::npos);

    targetmat->set_size(rows, cols);

    for (size_t r = 0, i = 0; r < rows; r++)
    {
        for (size_t c = 0; c < cols; c++, i++)
        {
            (*targetmat)(r, c) = v[i];
        }
    }
}

#endif // COURSERA_UTIL_HPP
