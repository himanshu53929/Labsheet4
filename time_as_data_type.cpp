#include<iostream>
using namespace std;

//Let's create a user-defined class representing time variable
class time{
    private:
        int day, hour, minute, second;

    public:
        time(int a=0, int b=0, int c=0, int z = 0):hour(a), minute(b), second(c), day(0){}
        friend time operator+(time, time);//Okay, now lets use some concept of operator overloading
        void display12();//Function to display time in 12 hour format
        void display24();//Function to display time in 24 hour format

};

void time::display24(){
    cout<<hour<<":"<<minute<<":"<<second;
    return;
}

void time::display12(){

    if(hour>12){
        cout<<hour-12<<":"<<minute<<":"<<second<<" PM";
    }

    else{
        cout<<hour<<":"<<minute<<":"<<second<<" AM";
    }

    return;
}

time operator+(time t1, time t2);

int main(){
    //First we initialized different variables of type time
    time t1 = time(15,23,47);
    time t2 = time(6, 35, 55);
    time t3;

    t3 = t1 + t2;//Adding time variables using operator overlaoding


    //now we display the time variables in different format
    t1.display24();cout<<" + "; t2.display24(); cout<<" = "; t3.display24(); cout<<endl;
    t1.display12();cout<<" + "; t2.display12(); cout<<" = "; t3.display12(); cout<<endl;

    return 0;
}

//Now we write all the codes for the function definition

time operator+(time t1, time t2){
    int h, m, s, d = 0;

    if((t1.second + t2.second) > 60){
        t1.minute;
        s = t1.second + t2.second - 60;
    }

    else{
        s = t1.second + t2.second;
    }

    if(t1.minute + t2.minute > 60){
        t1.hour++;
        m = t1.minute + t2.minute - 60;
    }

    else{
        m = t1.minute + t2.minute;
    }

    if((t1.hour+t2.hour)>24){
        d++;
        h = t1.hour+t2.hour - 24;
    }

    else{
        h = t1.hour + t2.hour;
    }

    return(time(h, m, s, d));
}
