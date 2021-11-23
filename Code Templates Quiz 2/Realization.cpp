class Resizable{
protected:
    virtual void enlarge()=0;
    virtual void shirnk()=0;
};

class Calculable{
protected:
    virtual double area()=0;
};

class Shape: public Resizable, public Calculable{
    // class information goes in here
    void enlarge();
    void shirnk();
    double area();
};