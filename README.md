# browserStack-Parkinglot


### compile
Run command on shell

 `g++ main.cpp`

### Run

`./a.out < input_file_name.txt > output_file_name.txt`


## Class

Slot 
   - age (int)
   - vehicle registration number (string)
   - booked (boolean)

Parking lot
  - slots(int)
  - list of slots 

## Commands Supported 

1. Create_parking_lot (number of slots)
2. Park (13 char long VRN) driver_age (age in number)
3. Slot_numbers_for_driver_of_age (age in number)
4. Slot_number_for_car_with_number (13 char long VRN)
5. Leave (slot number)
6. Vehicle_registration_number_for_driver_of_age (age in number)

( info ) => Based on info you have to complete the command while executing.



## Assumptions
- create parking lot first before executing any other commands.
- vehicle_registration_no are unique as provided by government.
- slots and vehicle are limited to 10^8.
- vrn = vehicle_registration_number and it is assumed to be 13 digit long .


## functions

### book (age, vehicle_registration_no)

To park a vehicle 
- if the lot is full then alert message thrown  `Sorry! Parking lot is full :(`
- else print the vehicle number with the available nearest slot that is alloted to vehicle

### leave (slot_number)

To vacate the slot

- if slots already vacant then alert message thrown`Slot already vacant!`
- if invalid slot is asked for `Slot number is invalid `
- else print the vehicle number with the vacated slot that was alloted to vehicle.

### slotsNumbersForDriversOfAge  (int age)

- if no slots available for given age then throw alert message `No cars with age _ parked!`
- else output comma separated slot numbers for particular age.

### slotNumberForVehicleRegistrationNumber  (string vrn)
 vrn - vehicle_registration_no

 output slot number for given vrn
 - if no vehicle with given vrn parked then throw alert message `No car with vehicle registration number PB-01-HH-1235 parked!`
 - else print the slot number simply




 ###  vehicleRegistrationNumberOfAge(int age)

 output vehicle registration number for given age

 - if no vrn available for given age then throw alert message `No cars with age 32 parked!`
 - else print vehicle_registration_no and corresponding slot number



 ### help

 type help in command prompt to see the list of commands available

 ### exit

type exit to stop execution


