import java.util.Scanner;

public class Bus {

    char[] totalseats = new char[17];
    int[] stops = new int[5];
    int user, metroseats, startpoint, endpoint;

    public void kms(int s) {
        for (int j = 1; j <= 5; j++) {
            stops[j - 1] = 5 * j;
        }
        for (int i = 0; i < 17; i++) {
            totalseats[i] = 'O';
        }
    }

    public void selectBus() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("|| 1->APSRTC  || 2-> PRIVATE Bus ||");
        System.out.print("Enter your bus : ");
        user = scanner.nextInt();

        switch (user) {
            case 1:
                System.out.print("Enter number of seats : ");
                metroseats = scanner.nextInt();
                int[] seatarr = new int[metroseats];
                journey();
                kms(metroseats);
                printTicket(stops, metroseats);
                reservedSeats();
                break;
        }
    }

    public void journey() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Starting Point: ");
        System.out.println("1.Gannavaram || 2.Eluru || 3.Tadepalligudem || 4.Rajamundry || 5.Anakapalle");
        startpoint = scanner.nextInt();
        System.out.println("Enter Destination Point: ");
        System.out.println("1.Gannavaram || 2.Eluru || 3.Tadepalligudem || 4.Rajamundry || 5.Anakapalle");
        endpoint = scanner.nextInt();
    }

    public void printTicket(int[] arr, int seats) {
        System.out.print("Startpoint - ");
        points(startpoint);
        System.out.print("Destination - ");
        points(endpoint);
        System.out.println("No. of passengers: " + metroseats);
        System.out.println("Total Ticket Price: " +(((stops[endpoint - 1] - stops[startpoint - 1])*45) * metroseats));
    }

    public void points(int a) {
        String stop;
        switch (a) {
            case 1:
                stop = "Gannavaram";
                System.out.println(stop);
                break;
            case 2:
                stop = "Eluru";
                System.out.println(stop);
                break;
            case 3:
                stop = "Tadepalligudem";
                System.out.println(stop);
                break;
            case 4:
                stop = "Rajamundry";
                System.out.println(stop);
                break;
            case 5:
                stop = "Anakapalle";
                System.out.println(stop);
                break;
        }
    }

    public void reservedSeats() {
        Scanner scanner = new Scanner(System.in);
        int[] seatarr = new int[metroseats];
        busStructure();
        for (int i = 0; i < metroseats; i++) {
            System.out.print("Choose your seat: ");
            seatarr[i] = scanner.nextInt();
            while ((totalseats[seatarr[i] - 1] == 'R') || (seatarr[i] > 16)) {
                System.out.println("Invalid seat or that seat is already booked. Try again.");
                seatarr[i] = scanner.nextInt();
            }
            totalseats[seatarr[i] - 1] = 'R';
        }
        busStructure();
        System.out.println("Total Ticket Price: " +(((stops[endpoint - 1] - stops[startpoint - 1])*45) * metroseats));
    }

    public void busStructure() {
        System.out.println("|| s1(" + totalseats[0] + ")   s2(" + totalseats[1] + ")                      s3( " + totalseats[2] + ")   s4(" + totalseats[3] + ")    ||");
        System.out.println("|| s5(" + totalseats[4] + ")   s6(" + totalseats[5] + ")                      s7( " + totalseats[6] + ")   s8(" + totalseats[7] + ")    ||");
        System.out.println("|| s9(" + totalseats[8] + ")   s10(" + totalseats[9] + ")                     s11( " + totalseats[10] + ") s12(" + totalseats[11] + ")    ||");
        System.out.println("|| s13(" + totalseats[12] + ")   s14(" + totalseats[13] + ")                  s15( " + totalseats[14] + ") s16(" + totalseats[15] + ")      ||");
    }

    public static void main(String[] args) {
        Bus busSystem = new Bus();
        busSystem.selectBus();
    }
}
