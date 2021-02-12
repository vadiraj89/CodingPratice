#include <bits/stdc++.h>

using namespace std;

class UserDetails{
    public:
    string name;
    string sex;
    int age;
    string usertype;
    
    
     UserDetails(string name,string sex,int age,string usertype){
        this->name=name;
        this->sex = sex;
        this->age = age;
        this->usertype = usertype;
    }
    UserDetails() = default;
    
    
    
};
UserDetails * getUser(vector<UserDetails  *> users,string name){
        for(auto i:users){
            if(i->name==name){
                return i;
            }
        }
        
        return users[0];
    }
class VechileDetails{
    public:
    string vehicletype;
    UserDetails * driverdetails;
    string vehiclenumber;
    string status;
    VechileDetails() = default;
     VechileDetails(UserDetails * driverdetails,string vehicletype,string vehiclenumber){
        this->vehicletype = vehicletype;
        this->driverdetails = driverdetails;
        this->vehiclenumber = vehiclenumber;
        this->status = "Available";
    }
    
};
VechileDetails  * getVehicle(vector<VechileDetails *> vehicles,string vehiclenum){
        for(auto i:vehicles){
            if(i->vehiclenumber==vehiclenum)
              return i;
        }
        
        return vehicles[0];
}

class Ride{
    public:
    UserDetails * rider;
    VechileDetails * vehicle;
    string source;
    string destination;
    string status;
    int avaiable_seats;
    
     Ride(UserDetails *rider,VechileDetails * vehicle,string source,string destination,int avaiable_seats){
        this->rider = rider;
        this->vehicle = vehicle;
        this->source = source;
        this->destination = destination;
        this->avaiable_seats = avaiable_seats;
        this->status = "offered";
    }
};

class Searchstatergy{
    public:
  virtual vector<Ride *> findRides(vector<Ride *> rides,int seatrequired) {};
} ;
class prefferedVehiclebasedstatergy :public Searchstatergy{
    public :
    string vehicle_type;
    prefferedVehiclebasedstatergy(string vehicletype){
        this->vehicle_type = vehicletype;
    }
    vector<Ride *> output_rides;
    
    vector<Ride *> findRides(vector<Ride *> rides,int seatrequired){
        for(auto i:rides){
            if(i->vehicle->vehicletype==vehicle_type && i->avaiable_seats>=seatrequired && i->status=="offered")
              output_rides.push_back(i);
        }
        
        return output_rides;
    }
};
class DriverDemo {
    public:
    vector<UserDetails *> users;
    vector<VechileDetails *> vehicles;
    unordered_map<UserDetails *,vector<Ride *>> offered_rides;
    map<pair<string,string>,vector<Ride *>> offered_rides_based_on_destination;
    unordered_map<UserDetails *,vector<Ride *>> taken_rides;
    
    void adduser(string name,string sex,int age,string usertype){
        UserDetails * user = new UserDetails(name,sex,age,usertype);
        users.push_back(user);
    }
    void addvehicle(string name,string vehicletype,string vehiclenum){
        UserDetails * driverdetails = getUser(users,name);
        VechileDetails * vehicle =new VechileDetails(driverdetails,vehicletype,vehiclenum);
        vehicles.push_back(vehicle);
    }
    
    void Offer_ride(string name,string source,string destination,int seats_avaibale,string vehicle_num){
        UserDetails * rider = getUser(users,name);
        VechileDetails * veh = getVehicle(vehicles,vehicle_num);
        if(veh->status=="Available"){
            Ride * offeredride = new Ride(rider,veh,source,destination,seats_avaibale);
            offered_rides[rider].push_back(offeredride);
            offered_rides_based_on_destination[make_pair(source,destination)].push_back(offeredride);
            veh->status = "offered";
        }
        else{
            cout<<"Cant offer already locked";
        }
        
    }
    
    bool select_ride(string name,string source,string destination,Searchstatergy * startergy,int seatrequired){
        UserDetails * rider = getUser(users,name);
        //vector<Ride> available_ride = offered_rides_based_on_destination.find(make_pair(source,destination));
        if(offered_rides_based_on_destination.find(make_pair(source,destination))==offered_rides_based_on_destination.end()){
            return false;
        }
        else{
            vector<Ride *> serachstartergybased = startergy->findRides(offered_rides_based_on_destination[make_pair(source,destination)],seatrequired);
            if(serachstartergybased.size()>0){
              serachstartergybased[0]->avaiable_seats--;
              taken_rides[rider].push_back(serachstartergybased[0]);
                return true;
            }
            else return false;
        }
    }
    
    void endride(string user,string vehiclenum){
        UserDetails * rider = getUser(users,user);
        
        for(auto i:offered_rides[rider]){
            if(i->vehicle->vehiclenumber==vehiclenum){
                i->vehicle->status = "Available";
                i->status = "end";
            }
        }
        for(auto i:taken_rides[rider]){
            if(i->vehicle->vehiclenumber==vehiclenum){
                i->vehicle->status = "Available";
                i->status = "end";
            }
        }
        
        
    }
    
    
     
    
    
};


int main()
{
    DriverDemo * driverclass = new DriverDemo();
    driverclass->adduser("vadi","Male",23,"Rider");
    driverclass->adduser("vasu","Male",23,"Driver");
    driverclass->adduser("sakku","FeMale",23,"Rider");
    driverclass->addvehicle("vasu","Baleno","KA-05-1228");
    driverclass->Offer_ride("vadi","A1","B1",2,"KA-05-1228");
    driverclass->Offer_ride("sakku","A1","B1",2,"KA-05-1228");
    bool aut =driverclass->select_ride("sakku","A1","B1",new prefferedVehiclebasedstatergy("Baleno"),1);
    for(auto i:driverclass->users){
        cout<<i->name<<" "<<i->usertype<<"\n";
        
    }
    for(auto i:driverclass->vehicles){
        cout<<i->vehiclenumber<<" "<<i->driverdetails->name<<"\n";
        
    }
    for(auto i:driverclass->offered_rides){
        for(auto j:i.second){
            cout<<j->source<<" ";
            cout<<j->destination<<" ";
            cout<<j->rider->name<<" ";
            cout<<j->vehicle->status<<"\n";
        }
    }
    //  for(auto i:driverclass->offered_rides_based_on_destination){
    //     for(auto j:i.second){
    //         cout<<j->source<<" ";
    //         cout<<j->destination<<" ";
    //         cout<<j->rider->name<<" ";
    //         cout<<j->vehicle->status<<"\n";
    //     }
    // }
    //  for(auto i:driverclass->offered_rides_based_on_destination){
    //     for(auto j:i.second){
    //         cout<<j->source<<" ";
    //         cout<<j->destination<<" ";
    //         cout<<j->rider->name<<" ";
    //         cout<<j->vehicle->status<<"\n";
    //     }
    // }
    
     for(auto i:driverclass->taken_rides){
        for(auto j:i.second){
            cout<<j->source<<" ";
            cout<<j->destination<<" ";
            cout<<i.first->name<<" ";
            cout<<j->vehicle->status<<"\n";
        }
    }
    driverclass->endride("sakku","KA-05-1228");
    cout<<"End ride";
    
    for(auto i:driverclass->vehicles){
        cout<<i->vehiclenumber<<" "<<i->status<<"\n";
    }
    driverclass->Offer_ride("sakku","A1","B1",2,"KA-05-1228");
    bool aut1 =driverclass->select_ride("sakku","A1","B1",new prefferedVehiclebasedstatergy("Baleno"),1);
    cout<<"taken rides\n";
      for(auto i:driverclass->taken_rides){
        for(auto j:i.second){
            cout<<j->source<<" ";
            cout<<j->destination<<" ";
            cout<<i.first->name<<"\n";
            
        }
    }
    return 0;
}
