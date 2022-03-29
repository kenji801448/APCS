import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class P1 {

    //for input
    private static Scanner scanner;

    //number of students
    private int n;

    //container for passed students
    private List<Integer> pass;

    //container for failed students
    private List<Integer> fail;

    //print list with space as delimiter
    private void printList(List<Integer> list) {

        for (int i = 0; i < list.size(); i++) {
            if (i != 0) {
                System.out.print(" ");
            }
            System.out.print(list.get(i));
        }
    }

    //constructor
    P1 () {
        //initial a Scanner object using keyboard as input
        scanner = new Scanner(System.in);

        //get an integer from keyboard
        n = scanner.nextInt();

        //initial two integer list to store grades
        pass = new ArrayList<Integer>(n);
        fail = new ArrayList<Integer>(n);

        //get the list ready
        for (int i = 0; i < n; i++) {
            int temp = scanner.nextInt();
            if (temp < 60) {
                fail.add(temp);
            } else {
                pass.add(temp);
            }
        }

        //sort two list as natural ordering
        pass.sort(null);
        fail.sort(null);

        //print all grades
        printList(fail);
        System.out.print(" ");
        printList(pass);
        System.out.println();

        //no students are failed if fail is empty
        if (fail.isEmpty()) {
            System.out.println("best case");
        } else {
            //print out the largest grade of fail
            System.out.println(fail.get(fail.size()-1));
        }

        //no students are passed if pass is empty
        if (pass.isEmpty()) {
            System.out.println("worst case");
        } else {
            //print out the smallest grade of pass
            System.out.println(pass.get(0));
        }
    }

    //main function
    public static void main(String... arg) {
        //new a object to trigger constructor
        new P1();
    }
}
