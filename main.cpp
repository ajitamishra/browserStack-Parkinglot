#include <bits/stdc++.h>
using namespace std;


class Slot
{
  public:
        int age;
        string vehicle_registration_number;
        bool booked;

  Slot()
  {
    this->booked=false;
    this->age=0;
    this->vehicle_registration_number="";
  }
};

class ParkingLot
{
  public:
        int number_of_slots;
        vector<Slot>slots;

  ParkingLot(int n)
  {
    number_of_slots=n;
    slots.resize(n);
  }

void book(int age,string vehicle_registration_number)
  {
    if(age<1)
    {
       cout<<"Invalid age of driver!";
    }
    else if(vehicle_registration_number.size()!=13)
    {
       cout<<"Invalid Vehicle registration number!";
    }
    else
    {
      int slot_number=-1;
      for(int i=0;i<this->number_of_slots;i++)
      {
        if(!this->slots[i].booked)
        {
          slot_number=i;
          break;
        }
      }
      if(slot_number==-1)
      {
         cout<<"Sorry! Parking lot is full :("<<endl;
      }
      else
      {
        this->slots[slot_number].booked=true;
        this->slots[slot_number].age=age;
        this->slots[slot_number].vehicle_registration_number=vehicle_registration_number;

        cout<<"Car with vehicle registration number \""<<vehicle_registration_number<<"\" has been parked at slot number "<<(slot_number+1)<<endl;
      }
    }
  }

void leave(int slot_no)
{
  slot_no--;
  if(!this->slots[slot_no].booked)
  {
    cout<<"Slot already vacant!"<<endl;
  }
  else
  {
    cout<<"Slot number "<<(slot_no+1)<<" vacated, the car with vehicle registration number \" "<<this->slots[slot_no].vehicle_registration_number <<"\" left the space, the driver of the car was of age "<<this->slots[slot_no].age<<endl;

    this->slots[slot_no].booked=false;
    this->slots[slot_no].age=0;
    this->slots[slot_no].vehicle_registration_number="";
    
  }
}  

void slotsNumbersForDriversOfAge(int age)
{
  vector<int>slot_numbers;

  for(int i=0;i<this->slots.size();i++)
  {
    if(this->slots[i].age==age)
    {
       slot_numbers.push_back(i+1);
    }
  }


  if(slot_numbers.size()==0)
   {
      cout<<"No cars with age "<<age<<" parked!"<<endl;
   }
   else
    {
    cout<<"Cars are parked at slot ";
     for(int i=0;i<slot_numbers.size()-1;i++)
     {
         cout<<slot_numbers[i]<<",";
     }   
      cout<<slot_numbers[slot_numbers.size()-1]<<endl;  
   }
   
}
void slotNumberForVehicleRegistrationNumber(string vrn)
  {
    int slot_number = -1;
    for (int i = 0; i < this->number_of_slots; i++)
    {
      if (this->slots[i].vehicle_registration_number == vrn)
      {
        slot_number = i + 1;
        break;
      }
    }
    
    if (slot_number == -1)
    {
       cout << "No car with vehicle registration number " << vrn << " parked!\n";
    }
    else
      cout << slot_number << endl;
  }

 
void vehicleRegistrationNumberOfAge(int age)
 {
  vector<pair<string,int>>vehicle_registration_numbers;

  for(int i=0;i<this->number_of_slots;i++)
  {
    if(this->slots[i].age==age)
    {
      vehicle_registration_numbers.push_back({this->slots[i].vehicle_registration_number,i+1});
    }
  }

  if (vehicle_registration_numbers.size() == 0)
      cout << "No cars with age " << age << " parked!\n";
       
  else
    {
      for (int i = 0; i < vehicle_registration_numbers .size(); i++)
      {
          cout  << vehicle_registration_numbers [i].first << "  " << vehicle_registration_numbers[i].second << endl;
      }
    }
  
  }
};


void help()
{
  vector<string> commands = {
      "help",
      "exit",
      "Leave (slot number)",
      "Create_parking_lot (number of slots)",
      "Park (13 char long VRN) driver_age (age in number)",
      "Slot_numbers_for_driver_of_age (age in number)",
      "Slot_number_for_car_with_number (13 char long VRN)",
      "Vehicle_registration_number_for_driver_of_age (age in number)",
  };

  cout << "\n----------------------\n";
  for (string cmd : commands)
  {
    cout << cmd << endl;
  }
  cout << endl;
  cout << "( info ) => Based on info you have to complete the command while executing.\n";
  cout << "----------------------\n\n";
}



int main() {
  string cmd;
  ParkingLot *parking_lot = NULL;

  while (cin >> cmd)
  {
    if (cmd == "help")
      help();
    else if (cmd == "exit")
    {
      cout << "Shutting down program! \n\n";
      break;
    }
    else if (cmd == "Create_parking_lot")
    {
      int n;
      cin >> n;

      if (parking_lot != NULL)
        cout << "Parking lot already created!\n";
      else if (n < 1)
        cout << "Invalid number of slots!\n";
      else
      {
        parking_lot = new ParkingLot(n);
        cout << "Created parking of " << n << " slots\n";
      }
    }
    else if (cmd == "Park")
    {
      string vrn, info_type;
      int age;
      cin >> vrn >> info_type >> age;

      if (vrn.size() != 13)
        cout << "Invalid vehicle registration number!\n";
      else if (age < 0)
        cout << "Invalid age!\n";
      else if (info_type != "driver_age")
        cout << "Invalid info type, expected 'driver_age' " << endl;
      else if (parking_lot == NULL)
        cout << "Please first create Parking lot with 'Create_parking_lot' command\n";
      else
        parking_lot->book(age, vrn);
    }
    else if (cmd == "Leave")
    {
      int slot_number;
      cin >> slot_number;

      if (parking_lot == NULL)
        cout << "Please first create Parking lot with 'Create_parking_lot' command\n";
      else if (slot_number > parking_lot->number_of_slots || slot_number < 1)
        cout << "Slot number is invalid \n";
      else
        parking_lot->leave(slot_number);
    }
    else if (cmd == "Slot_numbers_for_driver_of_age")
    {
      int age;
      cin >> age;
      if (parking_lot == NULL)
        cout << "Please first create Parking lot with 'Create_parking_lot' command\n";
      else if (age < 0)
        cout << "Invalid age!\n";
      else
        parking_lot->slotsNumbersForDriversOfAge(age);
    }
    else if (cmd == "Slot_number_for_car_with_number")
    {
      string vrn;
      cin >> vrn;
      if (parking_lot == NULL)
        cout << "Please first create Parking lot with 'Create_parking_lot' command\n";
      else if (vrn.size() != 13)
        cout << "Invalid vehicle registration number!\n";
      else
        parking_lot->slotNumberForVehicleRegistrationNumber(vrn);
    }
    else if (cmd == "Vehicle_registration_number_for_driver_of_age")
    {
      int age;
      cin >> age;
      if (parking_lot == NULL)
        cout << "Please first create Parking lot with 'Create_parking_lot' command\n";
      else if (age < 0)
        cout << "Invalid age!\n";
      else
        parking_lot->vehicleRegistrationNumberOfAge(age);
    }
    else
      cout << "Invalid command! , press 'help' for commands supported \n";
  }

  return 0;

}