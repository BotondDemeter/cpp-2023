//
// Created by Boti on 10/2/2023.
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H



class Point{
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    void print() const;
    int x;
    int y;
};



#endif //CPP_2022_POINT_H
