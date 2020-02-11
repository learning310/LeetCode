struct Y
{
    float f;
    int i;
    Y(int a);
}; 
Y y1[] = {Y(1), Y(2), Y(3)};
Y y2[2] = {Y(1), }; //error 编译器无法执行构造函数