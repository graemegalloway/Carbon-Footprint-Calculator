
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int electricity;
    int form_of_gas;
    double natural_gas_used;
    int km_traveled_by_car;
    int km_traveled_by_bus;
    int form_of_travel_tripone;
    int km_traveled_by_bus_tripone;
    int km_traveled_by_train_tripone;
    int km_traveled_by_aeroplane_tripone;
    int form_of_travel_triptwo;
    int km_traveled_by_bus_triptwo;
    int km_traveled_by_train_triptwo;
    int km_traveled_by_aeroplane_triptwo;
    int form_of_travel_tripthree;
    int km_traveled_by_bus_tripthree;
    int km_traveled_by_train_tripthree;
    int km_traveled_by_aeroplane_tripthree;

    //flags to skip the rest of trips if 'None' is selected
    bool skip_trip_two = false;
    bool skip_trip_three = false;

    printf("Welcome to the \"CIS*1500 Carbon Footprint Calculator\". This will calculate your annual CO2 emissions.\n\n");

    printf("\nEnter your total electricity consumption in kWh for the past year: ");
    scanf("%d", &electricity);
    if (electricity < 0 ){   
        printf("\nInvalid Choice. The program will now exit.\n");
        return 1; //exit program on invalid input
    }

        printf("\nWhat form of gas does your house require?\n1) Natural Gas in kWh\n2) Natural Gas in Cubic Meters\n3) LPG in Litres\n4) None\nEnter choice (1-4): ");
        scanf("%d", &form_of_gas);
    if (form_of_gas < 0 ){
        printf("\nInvalid Choice. The program will now exit.\n");
        return 1; 
    }

    switch (form_of_gas) {       //depending on what form of gas the user uses, prompt them to enter the corresponding amount
        case 1:
            printf("\nEnter the total kWh of Natural Gas used in the past year: ");
            scanf("%lf", &natural_gas_used);
            break;
        case 2:
            printf("\nEnter the total cubic metres of Natural Gas used in the past year: ");
            scanf("%lf", &natural_gas_used);
            break;
        case 3:
            printf("\nEnter the total litres of LPG used in the past year: ");
            scanf("%lf", &natural_gas_used);
            break;
        case 4:
            printf("You have completed the gas section.\n");
            break;
        default:
            printf("\nInvalid Choice. The program will now exit.\n");
            return 1;
    }


    printf("\nEnter the total km you traveled by car/taxi in the past year: ");
    scanf("%d", &km_traveled_by_car);
    if (km_traveled_by_car < 0 ){
        printf("\nInvalid Choice. The program will now exit.\n");
        return 1;
    }

    printf("\nApproximately how many km do you travel by bus per week? ");
    scanf("%d", &km_traveled_by_bus);
    if (km_traveled_by_bus < 0 ){
        printf("\nInvalid Choice. The program will now exit.\n");
        return 1;
    }

    printf("\nThe following section will ask you about your travel in the past year.");
    printf("\nYou will be able to enter up to 3 trips.");


    //this section recieves and stores user input details from trip one
    printf("\n\nWhat form of travel did you use for trip 1 in the past year?\n1) Bus\n2) Train\n3) Aeroplane\n4) None\nEnter choice (1-4): ");
    scanf("%d", &form_of_travel_tripone);
    if (form_of_travel_tripone < 1 || form_of_travel_tripone > 4 ){   
        printf("\nInvalid choice. The program will now exit.\n");
    }

    switch (form_of_travel_tripone) {
        case 1: // Bus
            printf("\nEnter the total km you traveled by bus in the trip: ");
            scanf("%d", &km_traveled_by_bus_tripone);
            break;

        case 2: // Train
            printf("\nEnter the total km you traveled by train in the trip: ");
            scanf("%d", &km_traveled_by_train_tripone);
            break;

        case 3: // Aeroplane
            printf("\nEnter the total km you traveled by aeroplane in the trip: ");
            scanf("%d", &km_traveled_by_aeroplane_tripone);
            break;

        case 4: // None
            printf("\nYou have completed the travel section.\n");
            skip_trip_two = true; // if the user did not take a trip, these are set to skip the prompts for trip two and three
            skip_trip_three = true; // 
            break;

        default:
            printf("\nInvalid choice. The program will now exit.\n");
            return 1; 
    }

    // if trip two does not need to be skipped, the code will continue into prompting user about trip two details
    if (!skip_trip_two) {
        printf("\nWhat form of travel did you use for trip 2 in the past year?\n1) Bus\n2) Train\n3) Aeroplane\n4) None\nEnter choice (1-4): ");
        scanf("%d", &form_of_travel_triptwo);
        if (form_of_travel_triptwo < 1 || form_of_travel_triptwo > 4 ){
            printf("\nInvalid choice. The program will now exit.\n");
        }

        switch (form_of_travel_triptwo) {  //depending on what form of travel the user took on trip twp, prompt them to enter the corresponding km
            case 1: // Bus
                printf("\nEnter the total km you traveled by bus in the trip: ");
                scanf("%d", &km_traveled_by_bus_triptwo);
                break;

            case 2: // Train
                printf("\nEnter the total km you traveled by train in the trip: ");
                scanf("%d", &km_traveled_by_train_triptwo);
                break;

            case 3: // Aeroplane
                printf("\nEnter the total km you traveled by aeroplane in the trip: ");
                scanf("%d", &km_traveled_by_aeroplane_triptwo);
                break;

            case 4: // None
                printf("\nYou have completed the travel section.\n");
                skip_trip_three = true; // if the user did not take a trip for trip number two, the prompts for trip three will be skipped
                break;

            default:
                printf("\nInvalid choice. The program will now exit.\n");
                return 1; 
        }
    }

    // if trip three does not need to be skipped, the code will continue into prompting the user about trip three details
    if (!skip_trip_three) {
        printf("\nWhat form of travel did you use for trip 3 in the past year?\n1) Bus\n2) Train\n3) Aeroplane\n4) None\nEnter choice (1-4): ");
        scanf("%d", &form_of_travel_tripthree);
        if (form_of_travel_tripthree < 1 || form_of_travel_tripthree > 4 ){
            printf("\nInvalid choice. The program will now exit.\n");
        }

        switch (form_of_travel_tripthree) {  //depending on what form of travel the user took on trip three, prompt them to enter the corresponding km
            case 1: // Bus
                printf("\nEnter the total km you traveled by bus in the trip: ");
                scanf("%d", &km_traveled_by_bus_tripthree);
                break;

            case 2: // Train
                printf("\nEnter the total km you traveled by train in the trip: ");
                scanf("%d", &km_traveled_by_train_tripthree);
                break;

            case 3: // Aeroplane
                printf("\nEnter the total km you traveled by aeroplane in the trip: ");
                scanf("%d", &km_traveled_by_aeroplane_tripthree);
                break;

            case 4: // None
                printf("\nYou have completed the travel section.\n");
                break;

            default:
                printf("\nInvalid choice. The program will now exit.\n");
                return 1; 
        }
    }

    printf("\nEnter your total income in dollars for the past year: "); 
    int total_income;
    scanf("%d", &total_income);

    printf("\nHow much efford do you put into reducing your carbon footprint?\n1) None\n2) Little\n3) Moderate\n4) High\n5) Very High\nEnter choice (1-5): "); 
    int effort;
    scanf("%d", &effort);

    // these are creating new varaibles, taking into consideration the carbon factors, to be printed in the table
    double electricityCO2 = electricity * 0.028; 
    double carCO2 = km_traveled_by_car * 0.17;
    double busCO2 = (km_traveled_by_bus * 52) * 0.97;

    printf("\n=== Personal Annual CO2 Emissions ===\n"); //this is the beginning of the table
    printf("----------------------------\n");
    printf("|%-15s|%10s|\n", "Totals", "CO2");
    printf("|--------------------------|\n");
    printf("|%-15s|%10s|\n", "Utilities", "");  
    printf("|%-15s|%10.2f|\n", "Electricity", electricityCO2);  

    // these are creating new varaibles, taking into consideration the carbon factors, to be printed in the table
    double natural_gas_used_cubic_metres_CO2 = natural_gas_used * 1.77;
    double natural_gas_used_kWh_CO2 = natural_gas_used * 0.19;
    double natural_gas_used_LPG_CO2 = natural_gas_used * 1.51;

    double gas_CO2;   //based on the user's choice of the form of gas used, this assigns a value the variable 'gas_CO2'
    switch (form_of_gas) {
        case 1: // Natural Gas in kWh
            gas_CO2 = natural_gas_used_kWh_CO2;
            break;
        case 2: // Natural Gas in Cubic Meters
            gas_CO2 = natural_gas_used_cubic_metres_CO2;
            break;
        case 3: // LPG in Litres
            gas_CO2 = natural_gas_used_LPG_CO2;
            break;
        case 4: // None
            gas_CO2 = 0.0;
            break;
        default:
            printf("\nInvalid Choice. The program will now exit.\n");
            return 1;
    }

    printf("|%-15s|%10.2f|\n", "Gas", gas_CO2);
    printf("|--------------------------|\n");
    printf("|%-15s|%10s|\n", "Communting", ""); 
    printf("|%-15s|%10.2f|\n", "Car", carCO2);
    printf("|%-15s|%10.2f|\n", "Bus", busCO2);

   
   
    // these are creating new varaibles, taking into consideration the carbon factors, to be printed in the table
    double bus_CO2_factor = 0.97;
    double aeroplane_CO2_factor = 0.246;
    double train_CO2_factor = 0.1;

    //these are creating new varaibles based on the distance traveled in a trip and the corresponding carbon factor
    double bus_trip_one_emissions = km_traveled_by_bus_tripone * bus_CO2_factor;
    double bus_trip_two_emissions = km_traveled_by_bus_triptwo * bus_CO2_factor;
    double bus_trip_three_emissions = km_traveled_by_bus_tripthree * bus_CO2_factor;
    double aeroplane_trip_one_emissions = km_traveled_by_aeroplane_tripone * aeroplane_CO2_factor;
    double aeroplane_trip_two_emissions = km_traveled_by_aeroplane_triptwo * aeroplane_CO2_factor;
    double aeroplane_trip_three_emissions = km_traveled_by_aeroplane_tripthree * aeroplane_CO2_factor;
    double train_trip_one_emissions = km_traveled_by_train_tripone * train_CO2_factor;
    double train_trip_two_emissions = km_traveled_by_train_triptwo * train_CO2_factor;
    double train_trip_three_emissions = km_traveled_by_train_tripthree * train_CO2_factor;


    printf("|--------------------------|\n");
    printf("|%-15s|%10s|\n", "Trips", ""); 

    //this prints the CO2 emissions for trip one
    if (form_of_travel_tripone == 1) { // Bus
        printf("|%-15s|%10.2f|\n", "Bus", bus_trip_one_emissions);
    } else if (form_of_travel_tripone == 2) { // Train
        printf("|%-15s|%10.2f|\n", "Train", train_trip_one_emissions);
    } else if (form_of_travel_tripone == 3) { // Aeroplane
        printf("|%-15s|%10.2f|\n", "Aeroplane", aeroplane_trip_one_emissions);
    }

    //this prints the CO2 emissions for trip two
    if (!skip_trip_two) {
        if (form_of_travel_triptwo == 1) { // Bus
            printf("|%-15s|%10.2f|\n", "Bus", bus_trip_two_emissions);
        } else if (form_of_travel_triptwo == 2) { // Train
            printf("|%-15s|%10.2f|\n", "Train", train_trip_two_emissions);
        } else if (form_of_travel_triptwo == 3) { // Aeroplane
            printf("|%-15s|%10.2f|\n", "Aeroplane", aeroplane_trip_two_emissions);
        }
    }

    //this prints the CO2 emissions for trip three
    if (!skip_trip_three) {
        if (form_of_travel_tripthree == 1) { // Bus
            printf("|%-15s|%10.2f|\n", "Bus", bus_trip_three_emissions);
        } else if (form_of_travel_tripthree == 2) { // Train
            printf("|%-15s|%10.2f|\n", "Train", train_trip_three_emissions);
        } else if (form_of_travel_tripthree == 3) { // Aeroplane
            printf("|%-15s|%10.2f|\n", "Aeroplane", aeroplane_trip_three_emissions);
        }
    }


    double total_trip_emissions = 0.0; //this line initializes the varible to 0.0, making sure it has a starting value before running calcuations. if not, there will be a warning

    //this adds the emissions from trip one to the total emissions, if trip one was taken
    if (form_of_travel_tripone == 1) { // Bus
        total_trip_emissions += bus_trip_one_emissions;
    } else if (form_of_travel_tripone == 2) { // Train
        total_trip_emissions += train_trip_one_emissions;
    } else if (form_of_travel_tripone == 3) { // Aeroplane
        total_trip_emissions += aeroplane_trip_one_emissions;
    }

    //this adds the emissions from trip two to the total emissions, if trip two was taken
    if (!skip_trip_two) {
        if (form_of_travel_triptwo == 1) { // Bus
            total_trip_emissions += bus_trip_two_emissions;
        } else if (form_of_travel_triptwo == 2) { // Train
            total_trip_emissions += train_trip_two_emissions;
        } else if (form_of_travel_triptwo == 3) { // Aeroplane
            total_trip_emissions += aeroplane_trip_two_emissions;
        }
    }

    //this adds the emissions from trip three to the total emissions, if trip three was taken
    if (!skip_trip_three) {
        if (form_of_travel_tripthree == 1) { // Bus
            total_trip_emissions += bus_trip_three_emissions;
        } else if (form_of_travel_tripthree == 2) { // Train
            total_trip_emissions += train_trip_three_emissions;
        } else if (form_of_travel_tripthree == 3) { // Aeroplane
            total_trip_emissions += aeroplane_trip_three_emissions;
        }
    }


    printf("|%-15s|%10.2f|\n", "Trips Total", total_trip_emissions);
    printf("|--------------------------|\n");

    //these calcuate the CO2 emissions based on income 
    double income_CO2 = (total_income / 5000.0) * 1000.0; 
    double adjusted_income_CO2; 

    //based on the users effort level, this adjusts the income-related CO2 emissions
    switch (effort) {
        case 1: // None
            adjusted_income_CO2 = income_CO2;
            break;
        case 2: // Little
            adjusted_income_CO2 = income_CO2 / 1.25;
            break;
        case 3: // Moderate
            adjusted_income_CO2 = income_CO2 / 1.5;
            break;
        case 4: // High
            adjusted_income_CO2 = income_CO2 / 1.75;
            break;
        case 5: // Very High
            adjusted_income_CO2 = income_CO2 / 2.0;
            break;
        default:
            printf("\nInvalid choice. The program will now exit.\n");
            adjusted_income_CO2 = income_CO2; 
    }


    printf("|%-15s|%10.2f|\n", "Income", adjusted_income_CO2);
    printf("|--------------------------|\n");

    //this creates a variable for the total emissions in kg
    double total_emissions = electricityCO2 + gas_CO2 + busCO2 + carCO2 + total_trip_emissions + adjusted_income_CO2;

    //this takes the total emissions variable and transfers it to tonnes
    double total_emissions_tonnes = total_emissions / 1000;

    printf("|%-15s|%10.2f|\n", "Total (KG)", total_emissions); 
    printf("|%-15s|%10.2f|\n", "Total (Tonnes)", total_emissions_tonnes); 
    printf("|--------------------------|\n");

    printf("\nIn 2020, Canada was the second largest GHG emitting country per capita.\nCanadians on average produce 17.8 tonnes of CO2 per person.");
    printf("\nYour total CO2 emmisions are %.2lf tonnes of CO2.", total_emissions_tonnes);
    double emissions_compared_canadian = (total_emissions_tonnes / 17.8) * 100; //this creates a new variable that converts the total emissions tonnes to emissions compared to the average Canadian
    printf("\nYou are emitting %.2lf%% of the average Canadian.", emissions_compared_canadian);
    double trees_required = round(total_emissions_tonnes * 38); //this creates a new variable that converts the total emissions tonnes to the number of trees required
    printf("\n\nAccording to 8billiontrees.com, 1 ton of CO2 is offset by planting 31-46 trees.\n\nLet's assume 38 trees per ton.\n\nTo offset your emissions, you would need to plant %.0lf trees.\n", trees_required);
    printf("\nThank you for using the CIS*1500 Carbon Calculator.\n");

    return 0;
}


